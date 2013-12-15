QueryInterface

class CWSDSimpleThermostatProxy : public ISimpleThermostat
class CSimpleThermostatService : public ISimpleThermostat_WSD
class CSimpleThermostat_WSDProxy: public ISimpleThermostat_WSDProxy


PrinterFdProxy (the object that is created by FD for the user to control :: ) CPrinterServiceWsdProxy : IPrinterService
class CPrinterServiceService : public IPrinterServiceType
class CPrinterServiceTypeProxy: public IPrinterServiceTypeProxy

__________________________________________________
DLL equivilancy: SsysPrinterSvcProxy==SimpleThermostatProxy
client's main func:
    hr = pFunInst->QueryService(
        __uuidof(SimpleThermostatProxy),
        __uuidof(ISimpleThermostat),
        reinterpret_cast<void**>(&pSimpleThermostat)
        );
	==>
	hr = pFunInst->QueryService(
        __uuidof(SsysPrinterSvcProxy),
        __uuidof(IPrinterService),
        reinterpret_cast<void**>(&pPrinterService)
        );
		
