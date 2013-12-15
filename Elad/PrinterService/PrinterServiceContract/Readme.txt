Troubleshooting
==========================================
In case you change CodeGen_All.config
and the project has a PostBuild event of running WsdCodeGen on it,
you may find that you need to replace
WSDXML_NODE.TextType and WSDXML_NODE.ElementType  with
WSDXML_NODE::TextType and WSDXML_NODE::ElementType, respectively.
Changing HWID/CPID may trigger it.


// <CDATA>
=== Index ====================================================================
* Quick start guide
  + Client
  + Service
  + Compiling
* Generated files
* Generated interfaces
  + Base interfaces
  + Proxy interfaces
  + Event notify interfaces
* Generated classes
  + Proxy classes
  + Event source classes
* Generated functions
  + Proxy builder functions
  + Host builder function
  + Stub functions
* Generated structures
  + Metadata structures
  + Parameter structures




=== Quick start guide ========================================================
--- Client ---------------------------
Your client application should call one of the proxy builder functions:
* CreateCPrinterServiceTypeProxy() or CreateCPrinterServiceTypeProxyById(), to instantiate a class of type
  CPrinterServiceTypeProxy
* CreateCPrinterServiceV12TypeProxy() or CreateCPrinterServiceV12TypeProxyById(), to instantiate a class of type
  CPrinterServiceV12TypeProxy

All of these functions are defined in PrinterServiceTypeTypes.h
Once one of these classes has been successfully created, it may be used to
issue service commands to a host.



--- Service --------------------------
To build a service, implement one or more of the following
interfaces:
* IPrinterServiceType
* IPrinterServiceV12Type

Then, pass one or more of these objects into the host builder function,
These interfaces do NOT have to be implemented by the same object.
CreatePrinterServiceTypeHost() (see below).  Lastly, call Start()
on the resulting IWSDDeviceHost object.



--- Compiling -----------------------
All generated files must be compiled together into one static library,
executable, or DLL.

The generated IDL file (PrinterServiceType.idl) may be compiled into
C++ files with the MIDL tool.  The other generated files require that
PrinterServiceType.idl will be compiled into PrinterServiceType.h.




=== Generated files ==========================================================
* PrinterServiceTypeTypes.h    Forward-declarations and struct definitions
* PrinterServiceTypeTypes.cpp  Type table and operation structure definitions
* PrinterServiceType.idl       Defines the interfaces for the specified services
* PrinterServiceTypeProxy.h    Declares proxy classes and builder functions
* PrinterServiceTypeProxy.cpp  Proxy class and function implementations
* PrinterServiceTypeStub.cpp   Stub function code



=== Generated interfaces =====================================================
--- Base interfaces ------------------
* IPrinterServiceType
* IPrinterServiceV12Type

These base interfaces are generated directly by the WSDL, and are used to
implement your service.  Clients should use the extended proxy classes,
below.  No eventing operations are included in these base interfaces.

Your service objects should implement these interfaces.



--- Proxy interfaces -----------------
* IPrinterServiceTypeProxy
* IPrinterServiceV12TypeProxy

These proxy interfaces extend the base interfaces (listed above) by adding
client-only functionality such as asynchronous service calls for two-way
operations and subscribe/unsubscribe methods for eventing operations.

These interfaces should only be implemented by the generated client proxies.
Your client code should instantiate objects that expose these interfaces
using the proxy builder functions, and should call into the exposed methods.



--- Event notify interfaces ----------
* IPrinterServiceTypeEventNotify

These event notify interfaces are used by services to issue events, and are
implemented by client code to receive events.  Subscription management is
handled separately in the proxy interfaces (listed above).

Your service code should instantiate objects that expose these interfaces
using the event source builder functions (see below), and should call into
the exposed methods.

You should build a client object that implements these interfaces, and
register that object when subscribing for events.  Your object will receive
callbacks when you receive events from the service.



=== Generated classes ========================================================
--- Proxy classes --------------------
* CPrinterServiceTypeProxy
* CPrinterServiceV12TypeProxy

These proxy classes can be called from your application, and will issue
messages to a service.  To instantiate one of these classes, use a proxy
builder function (see below).



--- Event source classes -------------
* CPrinterServiceTypeEventSource

These event source classes can be called from your service, and will issue
events to subscribed clients.  To instantiate one of these classes, use a
event source builder function (see below).




=== Generated functions ======================================================
--- Proxy builder functions ----------
* CreateCPrinterServiceTypeProxy()
* CreateCPrinterServiceV12TypeProxy()

Use these functions to generate proxy classes (see above).



--- Host builder function ------------
* CreatePrinterServiceTypeHost()

Use this function to create a host and register your service(s).


--- Event source builder functions ---
* CreateCPrinterServiceTypeEventSource()
* CreateCPrinterServiceV12TypeEventSource()

Use these functions to generate event source classes (see above).



--- Stub functions -------------------
These functions receive calls from WSDAPI and dispatch them into your
service object.  You should not call these functions from your application.




=== Generated structures =====================================================
--- Metadata structures --------------
* WSD_HOST_METADATA hostMetadata
* WSD_THIS_MODEL_METADATA thisModelMetadata

Pass these structures to your host builder function (see above).



--- Parameter structures -------------
All parameter structures are defined inside PrinterServiceTypeTypes.h.

// </CDATA>

