//
// Copyright (C) Microsoft Corporation. All rights reserved.
//
// File Name:
//
//    omconvertor.cpp
//
// Abstract:
//
//    Object model conversion routines. This class provides routines
//      to convert from filter pipeline objects into Xps Object Model 
//      objects.
//

#include "precomp.h"
#include "WppTrace.h"
#include "CustomWppCommands.h"
#include "Exception.h"
#include "filtertypes.h"
#include "UnknownBase.h"
#include "OMConvertor.h"

//#include "OMConvertor.tmh"

namespace MS3DPrintDriver_Render_Filter
{


//
//Routine Name:
//
//    GetStreamFromPart
//
//Routine Description:
//
//    Gets the IStream from this part.
//
//Arguments:
//
//    pPart           - An Xps Part
//
//Return Value:
//    
//    IStream_t (smart pointer)
//    The stream of the part's content
//
IStream_t
GetStreamFromPart(
    const IPartBase_t  &pPart
    )
{
    //
    // Get the IPrintReadStream for the part from the pipeline Object Model
    //
    IPrintReadStream_t   pStream;
    THROW_ON_FAILED_HRESULT(
        pPart->GetStream(&pStream)
        );

    return CreateIStreamFromIPrintReadStream(pStream);
}

//
//Routine Name:
//
//    CreateIStreamFromIPrintReadStream
//
//Routine Description:
//
//    Creates an IStream from an IPrintReadStream.
//
//Arguments:
//
//    pReadStream - A Print Pipeline IPrintReadStream
//
//Return Value:
//    
//    IStream_t (smart pointer)
//    A stream with the same content as the argument stream.
//
IStream_t
CreateIStreamFromIPrintReadStream(
    const IPrintReadStream_t   &pReadStream
    )
{
    //
    // Get the size of the stream
    //
    ULONGLONG tmpPos;
    size_t partSize;

    THROW_ON_FAILED_HRESULT(
        pReadStream->Seek(0, SEEK_END, &tmpPos)
        );

    //
    // GlobalAlloc can only allocate size_t bytes, so
    // throw if the part is larger than that
    //
    THROW_ON_FAILED_HRESULT(
        ULongLongToSizeT(tmpPos, &partSize)
        );

    THROW_ON_FAILED_HRESULT(
        pReadStream->Seek(0, SEEK_SET, &tmpPos)
        );

    //
    // Allocate an HGLOBAL for the part cache
    //
    SafeHGlobal_t pHBuf(
                    new SafeHGlobal(GMEM_FIXED, partSize)
                    );

    //
    // Read the part into the cache
    //
    {
        //
        // Lock the HGLOBAL and get the address of the buffer
        // from the RAII lock object
        //
        HGlobalLock_t lock = pHBuf->Lock();
        BYTE *pBuffer = lock->GetAddress();

        //
        // Allow the number of bytes to read to be clipped to max ULONG
        // and then spin on fEOF until the stream is exhausted
        //
        ULONG numToRead;

        if (FAILED(SizeTToULong(partSize, &numToRead)))
        {
            numToRead = MAXUINT;
        }

        BOOL fEOF;
        ULONG numRead;
        size_t pos = 0;

        //
        // Iterate until all bytes from the stream 
        // have been read into the buffer
        //
        do
        {
            THROW_ON_FAILED_HRESULT(
                pReadStream->ReadBytes(pBuffer + pos, numToRead, &numRead, &fEOF)
                );

            pos += numRead;
        } while (!fEOF && numRead);
    }

    //
    // Create an IStream from the part cache
    //
    IStream_t pIStream = pHBuf->ConvertToIStream();

    LARGE_INTEGER zero = {0};
    THROW_ON_FAILED_HRESULT(
        pIStream->Seek(zero, SEEK_SET, NULL)
        );

    return pIStream;
}

//
//Routine Name:
//
//    CreateOpcPartUriFromPart
//
//Routine Description:
//
//    Gets the Opc Uri from the Xps Part.
//
//Arguments:
//
//    pPart       - An Xps Part
//    pFactory    - Opc Factory
//
//Return Value:
//
//    IOpcPartUri_t (smart pointer)
//    The Uri of the part
//
IOpcPartUri_t
CreateOpcPartUriFromPart(
    const IPartBase_t      &pPart,
    const IOpcFactory_t    &pFactory
    )
{
    BSTR_t strPartUri;
    
    THROW_ON_FAILED_HRESULT(
        pPart->GetUri(&strPartUri)
        );
   
    IOpcPartUri_t   pPartUri;
    THROW_ON_FAILED_HRESULT(
        pFactory->CreatePartUri(strPartUri, &pPartUri)
        );
    return pPartUri;
}

} // namespace MS3DPrintDriver_Render_Filter
