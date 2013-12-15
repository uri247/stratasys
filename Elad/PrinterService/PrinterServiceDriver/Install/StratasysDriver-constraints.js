/// <reference path="v4PrintDriver-Intellisense.js" />

var pskNs    = "http://schemas.microsoft.com/windows/2003/08/printing/printschemakeywords";
var psfNs    = "http://schemas.microsoft.com/windows/2003/08/printing/printschemaframework";
var psk3dNs  = "http://schemas.microsoft.com/3dmanufacturing/2013/01/pskeywords3d";
var ns0000Ns = "http://schemas.microsoft.com/3MF/2013/01";

function validatePrintTicket(printTicket, scriptContext) {
    /// <param name="printTicket" type="IPrintSchemaTicket">
    ///     Print ticket to be validated.
    /// </param>
    /// <param name="scriptContext" type="IPrinterScriptContext">
    ///     Script context object.
    /// </param>
    /// <returns type="Number" integer="true">
    ///     Integer value indicating validation status.
    ///         1 - Print ticket is valid and was not modified.
    ///         2 - Print ticket was modified to make it valid.
    ///         0 - Print ticket is invalid.
    /// </returns>

    return 1;
}

//
// Update known keywords in a XMLNode to use the 3d namespace
//
function updateNodeTo3dNamespace(xmlNode) {

    var updateKeywords = new Array();

    updateKeywords[1] = "ns0000:Job3DToolCount";
    updateKeywords[2] = "ns0000:Job3DTools";
    updateKeywords[3] = "ns0000:Extruder1";
    updateKeywords[4] = "ns0000:Extruder2";
    updateKeywords[5] = "ns0000:Extruder3";
    updateKeywords[6] = "ns0000:Extruder4";
    updateKeywords[7] = "ns0000:Extruder5";
    updateKeywords[8] = "ns0000:DisplayName";
    updateKeywords[9] = "ns0000:MaterialTypeOption";
    updateKeywords[10] = "ns0000:MaterialColor";
    updateKeywords[11] = "ns0000:FilamentDiameterOption";
    updateKeywords[12] = "ns0000:Job3DInitialTool";
    updateKeywords[13] = "ns0000:Job3DOutputArea";
    updateKeywords[14] = "ns0000:Job3DOutputAreaWidth";
    updateKeywords[15] = "ns0000:Job3DOutputAreaDepth";
    updateKeywords[16] = "ns0000:Job3DOutputAreaHeight";
    updateKeywords[17] = "ns0000:Job3DToolTemperature";
    updateKeywords[18] = "ns0000:Job3DPlatformTemperature";
    updateKeywords[19] = "ns0000:Job3DDeviceLanguage";
    updateKeywords[20] = "ns0000:3MF";
    updateKeywords[21] = "ns0000:STL";
    updateKeywords[22] = "ns0000:AMF";
    updateKeywords[23] = "ns0000:GCode";
    updateKeywords[24] = "ns0000:Bitmap";
    updateKeywords[25] = "ns0000:Job3DMaterialType";
    updateKeywords[26] = "ns0000:PLA";
    updateKeywords[27] = "ns0000:ABS";
    updateKeywords[28] = "ns0000:HDPE";
    updateKeywords[29] = "ns0000:PVA";
    updateKeywords[30] = "ns0000:Composite";
    updateKeywords[31] = "ns0000:SolidWood";
    updateKeywords[32] = "ns0000:SolidMetal";
    updateKeywords[33] = "ns0000:Powder";
    updateKeywords[34] = "ns0000:Job3DFilamentFeedRate";
    updateKeywords[35] = "ns0000:Job3DFilamentDiameter";
    updateKeywords[36] = "ns0000:ExtraThin";
    updateKeywords[37] = "ns0000:Thin";
    updateKeywords[38] = "ns0000:Medium";
    updateKeywords[39] = "ns0000:Thick";
    updateKeywords[40] = "ns0000:Job3DFilamentNozzleDiameter";
    updateKeywords[41] = "ns0000:Job3DToolTravelRate";
    updateKeywords[42] = "ns0000:Job3DQuality";
    updateKeywords[43] = "ns0000:Draft";
    updateKeywords[44] = "ns0000:Medium";
    updateKeywords[45] = "ns0000:High";
    updateKeywords[46] = "ns0000:Job3DDensity";
    updateKeywords[47] = "ns0000:Hollow";
    updateKeywords[48] = "ns0000:Low";
    updateKeywords[49] = "ns0000:Medium";
    updateKeywords[50] = "ns0000:High";
    updateKeywords[51] = "ns0000:Solid";
    updateKeywords[52] = "ns0000:InfillPercentage";
    updateKeywords[53] = "ns0000:Job3DSliceHeight";
    updateKeywords[54] = "ns0000:Job3DShellCount";
    updateKeywords[55] = "ns0000:Job3DOutputColor";
    updateKeywords[56] = "ns0000:Color";
    updateKeywords[57] = "ns0000:Monochrome";
    updateKeywords[58] = "ns0000:Job3DSupports";
    updateKeywords[59] = "ns0000:SupportsIncluded";
    updateKeywords[60] = "ns0000:SupportsExcluded";
    updateKeywords[61] = "ns0000:Job3DRaft";
    updateKeywords[62] = "ns0000:RaftIncluded";
    updateKeywords[63] = "ns0000:RaftExcluded";
    updateKeywords[64] = "ns0000:InfillPercentage";
    
    try {
        if (xmlNode.nodeType == 1 || xmlNode.nodeType == 3) // Element or String only
        {
            // features
            for (var index = 0; index < updateKeywords.length; index++) {
                if (xmlNode.nodeType == 1) {

                    // Check node name
                    var attrName = xmlNode.getAttribute("name");
                    if (attrName) {
                        if (attrName === updateKeywords[index]) {
                            xmlNode.setAttribute("name", "psk3d:" + attrName.substring(7));
                            //                            debug.innerHTML += attrName.toString() + "<br>";
                        }
                    }
                }
                else if (xmlNode.nodeType == 3) {
                    // Check node value
                    if (xmlNode === updateKeywords[index]) {
                        xmlNode = ("psk3d:" + xmlNode.substring(7));
                        //                       debug.innerHTML += xmlNode.toString() + "<br>";
                    }
                }
            }
        }
    }
    catch (e) {
        //        debug.innerHTML += (xmlNode.nodeName.toString() + ":" + e.toString() + "<br>");
    }
}

//
// Navigate DOM looking for things we need to change to the 3d namespace
//
function navigateAndUpdateDOM(xmlNode) {

    var Child;

    for (var ChildCount = 0; ChildCount < xmlNode.childNodes.length; ChildCount++) {
        Child = xmlNode.childNodes.item(ChildCount);
        updateNodeTo3dNamespace(Child);
        navigateAndUpdateDOM(Child);
    }
}

function completePrintCapabilities(printTicket, scriptContext, printCapabilities) {
    /// <param name="printTicket" type="IPrintSchemaTicket" mayBeNull="true">
    ///     If not 'null', the print ticket's settings are used to customize the print capabilities.
    /// </param>
    /// <param name="scriptContext" type="IPrinterScriptContext">
    ///     Script context object.
    /// </param>
    /// <param name="printCapabilities" type="IPrintSchemaCapabilities">
    ///     Print capabilities object to be customized.
    /// </param>

    var xmlCapabilities = printCapabilities.XmlNode;

    var Root;

    // find psf:PrintCapabilities
    for (var ChildCount = 0; ChildCount < xmlCapabilities.childNodes.length; ChildCount++) {
        Root = xmlCapabilities.childNodes.item(ChildCount);

        if (Root.nodeName == "psf:PrintCapabilities") {
            // Add new attribute xmlns:psk3d="http://schemas.microsoft.com/3dmanufacturing/2013/01/pskeywords3d""
            Root.setAttribute("xmlns:psk3d", psk3dNs.toString());
            //            debug.innerHTML +=  psk3dNs.toString() + "<br>";
        }
    }

    navigateAndUpdateDOM(Root);

}

function convertPrintTicketToDevMode(printTicket, scriptContext, devModeProperties) {
    /// <param name="printTicket" type="IPrintSchemaTicket">
    ///     Print ticket to be converted to DevMode.
    /// </param>
    /// <param name="scriptContext" type="IPrinterScriptContext">
    ///     Script context object.
    /// </param>
    /// <param name="devModeProperties" type="IPrinterScriptablePropertyBag">
    ///     The DevMode property bag.
    /// </param>
}


function convertDevModeToPrintTicket(devModeProperties, scriptContext, printTicket) {
    /// <param name="devModeProperties" type="IPrinterScriptablePropertyBag">
    ///     The DevMode property bag.
    /// </param>
    /// <param name="scriptContext" type="IPrinterScriptContext">
    ///     Script context object.
    /// </param>
    /// <param name="printTicket" type="IPrintSchemaTicket">
    ///     Print ticket to be converted from the DevMode.
    /// </param>

}

var PrintSchemaConstrainedSetting = {
    PrintSchemaConstrainedSetting_None: 0,
    PrintSchemaConstrainedSetting_PrintTicket: 1,
    PrintSchemaConstrainedSetting_Admin: 2,
    PrintSchemaConstrainedSetting_Device: 3
};

var STREAM_SEEK = {
    STREAM_SEEK_SET: 0,
    STREAM_SEEK_CUR: 1,
    STREAM_SEEK_END: 2
};

var PrintSchemaSelectionType = {
    PrintSchemaSelectionType_PickOne: 0,
    PrintSchemaSelectionType_PickMany: 1
};

