//
// Copyright (C) Microsoft Corporation. All rights reserved.
//	
// File Name:
//
//    WppTrace.h
//
// Abstract:
//
//    WPP tracing definitions.
//

#pragma once



#define WPP_CONTROL_GUIDS WPP_DEFINE_CONTROL_GUID(                                       \
                                MS3DPrintDriverRenderFilter,                              \
                                (f88a9089,4279,4e4b,a8b9,4453644bd54b),                  \
                                WPP_DEFINE_BIT(RENDERFILTER_TRACE_ERROR)                 \
                                WPP_DEFINE_BIT(RENDERFILTER_TRACE_WARNING)               \
                                WPP_DEFINE_BIT(RENDERFILTER_TRACE_INFO)                  \
                                WPP_DEFINE_BIT(RENDERFILTER_TRACE_VERBOSE)               \
                                )


