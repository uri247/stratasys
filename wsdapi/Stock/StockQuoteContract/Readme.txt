=== Index ====================================================================
* Quick start guide
  + Client
  + Service
  + Compiling
* Generated files
* Generated interfaces
  + Base interfaces
  + Proxy interfaces
* Generated classes
  + Proxy classes
* Generated functions
  + Proxy builder functions
  + Host builder function
  + Stub functions
* Generated structures
  + Metadata structures
  + Parameter structures




=== Quick start guide ========================================================
--- Client ---------------------------
Your client application should use one of the proxy builder functions
CreateCStockQuoteProxy() and CreateCStockQuoteProxyById(), which will instantiate
a class of type CStockQuoteProxy.  These functions are defined in StockQuoteTypes.h.

Once this class has been successfully created, it may be used to
issue service commands to a host.

Use CreateCStockQuoteProxy() when only the target type is known.
Use CreateCStockQuoteProxyById() when the service ID is known.



--- Service --------------------------
To build a host application, implement the IStockQuote service interface.
Then, pass this object into the host builder function,
CreateStockQuoteHost() (see below).  Lastly, call Start()
on the resulting IWSDDeviceHost object.



--- Compiling -----------------------
All generated files must be compiled together into one static library,
executable, or DLL.

The generated IDL file (StockQuote.idl) may be compiled into
C++ files with the MIDL tool.  The other generated files require that
StockQuote.idl will be compiled into StockQuote.h.




=== Generated files ==========================================================
* StockQuoteTypes.h    Forward-declarations and struct definitions
* StockQuoteTypes.cpp  Type table and operation structure definitions
* StockQuote.idl       Defines the interfaces for the specified services
* StockQuoteProxy.h    Declares proxy classes and builder functions
* StockQuoteProxy.cpp  Proxy class and function implementations
* StockQuoteStub.cpp   Stub function code



=== Generated interfaces =====================================================
--- Base interfaces ------------------
* IStockQuote

These base interfaces are generated directly by the WSDL, and are used to
implement your service.  Clients should use the extended proxy classes,
below.  No eventing operations are included in these base interfaces.

Your service objects should implement these interfaces.



--- Proxy interfaces -----------------
* IStockQuoteProxy

These proxy interfaces extend the base interfaces (listed above) by adding
client-only functionality such as asynchronous service calls for two-way
operations and subscribe/unsubscribe methods for eventing operations.

These interfaces should only be implemented by the generated client proxies.
Your client code should instantiate objects that expose these interfaces
using the proxy builder functions, and should call into the exposed methods.




=== Generated classes ========================================================
--- Proxy classes --------------------
* CStockQuoteProxy

These proxy classes can be called from your application, and will issue
messages to a service.  To instantiate one of these classes, use a proxy
builder function (see below).




=== Generated functions ======================================================
--- Proxy builder functions ----------
* CreateCStockQuoteProxy()

Use these functions to generate proxy classes (see above).



--- Host builder function ------------
* CreateStockQuoteHost()

Use this function to create a host and register your service(s).


--- Stub functions -------------------
These functions receive calls from WSDAPI and dispatch them into your
service object.  You should not call these functions from your application.




=== Generated structures =====================================================
--- Metadata structures --------------
* WSD_HOST_METADATA hostMetadata
* WSD_THIS_MODEL_METADATA thisModelMetadata

Pass these structures to your host builder function (see above).



--- Parameter structures -------------
All parameter structures are defined inside StockQuoteTypes.h.

