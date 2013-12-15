@echo off
Echo error 0x80004005 will arise upon client-connecting to the server, if the wsdcodegen
Echo is not the same version here (upon creating the config file) as it is in the VC Project's build event.
Echo.
Echo versions found locally (wsdcodegen.exe):
Echo \Program Files\Windows Kits\8.1\bin\x86\        - 6.3.9600.16384 (251kb) [2013]
Echo \Program Files\Microsoft SDKs\Windows\v7.1\Bin\ - 6.1.7074.0 (369kb)     [2010]
Echo \Program Files\Microsoft SDKs\Windows\v6.1\Bin\ - 6.0.6001.17313 (221kb) [2008]
Echo.

Set SRC_WSDL_PATH=C:\sources\PrinterService\PrinterServiceContract
Set DST_CONFIG_PATH=C:\sources\PrinterService\PrinterServiceContract
Set SRC_CONFIG_APP_FULLPATH=C:\Program Files\Windows Kits\8.1\bin\x86\wsdcodegen.exe
rem Set SRC_CONFIG_APP_FULLPATH=C:\Program Files\Microsoft SDKs\Windows\v7.1\Bin\wsdcodegen.exe
rem Set SRC_CONFIG_APP_FULLPATH=C:\Program Files\Microsoft SDKs\Windows\v6.1\Bin\wsdcodegen.exe

"%SRC_CONFIG_APP_FULLPATH%" /generateconfig:all /outputfile:"%DST_CONFIG_PATH%\CodeGen_All.config" "%SRC_WSDL_PATH%\WSDPrinterService.wsdl" "%SRC_WSDL_PATH%\WSDPrinterServiceV12.wsdl"

Set SRC_CONFIG_APP_FULLPATH=
Set DST_CONFIG_PATH=
Set SRC_WSDL_PATH=

Echo.
Echo Done.
pause