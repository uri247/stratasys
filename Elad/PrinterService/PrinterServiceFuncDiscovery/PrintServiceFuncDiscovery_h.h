

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Mon Nov 11 18:53:27 2013
 */
/* Compiler settings for PrintServiceFuncDiscovery.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __PrintServiceFuncDiscovery_h_h__
#define __PrintServiceFuncDiscovery_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __SsysPrinterSvcProxy_FWD_DEFINED__
#define __SsysPrinterSvcProxy_FWD_DEFINED__

#ifdef __cplusplus
typedef class SsysPrinterSvcProxy SsysPrinterSvcProxy;
#else
typedef struct SsysPrinterSvcProxy SsysPrinterSvcProxy;
#endif /* __cplusplus */

#endif 	/* __SsysPrinterSvcProxy_FWD_DEFINED__ */


/* header files for imported files */
#include "FunctionDiscoveryProvider.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __SsysPrinterSvcProxyLib_LIBRARY_DEFINED__
#define __SsysPrinterSvcProxyLib_LIBRARY_DEFINED__

/* library SsysPrinterSvcProxyLib */
/* [version][helpstring][uuid] */ 


EXTERN_C const IID LIBID_SsysPrinterSvcProxyLib;

EXTERN_C const CLSID CLSID_SsysPrinterSvcProxy;

#ifdef __cplusplus

class DECLSPEC_UUID("54FA0783-7B66-42b6-B22E-7454441D6C05")
SsysPrinterSvcProxy;
#endif
#endif /* __SsysPrinterSvcProxyLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


