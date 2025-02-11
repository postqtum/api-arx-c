

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0626 */
/* at Tue Jan 19 04:14:07 2038
 */
/* Compiler settings for ..\..\lib\IcArx\AcPEXCtl.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0626 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __acpexctl_h__
#define __acpexctl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if _CONTROL_FLOW_GUARD_XFG
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __IAcPeNumericEditor_FWD_DEFINED__
#define __IAcPeNumericEditor_FWD_DEFINED__
typedef interface IAcPeNumericEditor IAcPeNumericEditor;

#endif 	/* __IAcPeNumericEditor_FWD_DEFINED__ */


#ifndef __IAcPeVariantCtrl_FWD_DEFINED__
#define __IAcPeVariantCtrl_FWD_DEFINED__
typedef interface IAcPeVariantCtrl IAcPeVariantCtrl;

#endif 	/* __IAcPeVariantCtrl_FWD_DEFINED__ */


#ifndef __IAcPeColorCtrl_FWD_DEFINED__
#define __IAcPeColorCtrl_FWD_DEFINED__
typedef interface IAcPeColorCtrl IAcPeColorCtrl;

#endif 	/* __IAcPeColorCtrl_FWD_DEFINED__ */


#ifndef __IAcPeSpinCtrl_FWD_DEFINED__
#define __IAcPeSpinCtrl_FWD_DEFINED__
typedef interface IAcPeSpinCtrl IAcPeSpinCtrl;

#endif 	/* __IAcPeSpinCtrl_FWD_DEFINED__ */


#ifndef __IAcPeNoPickVariantRW_FWD_DEFINED__
#define __IAcPeNoPickVariantRW_FWD_DEFINED__
typedef interface IAcPeNoPickVariantRW IAcPeNoPickVariantRW;

#endif 	/* __IAcPeNoPickVariantRW_FWD_DEFINED__ */


#ifndef __IAcPeButtonEditCtrl_FWD_DEFINED__
#define __IAcPeButtonEditCtrl_FWD_DEFINED__
typedef interface IAcPeButtonEditCtrl IAcPeButtonEditCtrl;

#endif 	/* __IAcPeButtonEditCtrl_FWD_DEFINED__ */


#ifndef __IAcPeButtonPicture_FWD_DEFINED__
#define __IAcPeButtonPicture_FWD_DEFINED__
typedef interface IAcPeButtonPicture IAcPeButtonPicture;

#endif 	/* __IAcPeButtonPicture_FWD_DEFINED__ */


#ifndef __IAcPePick2PointsCtrl_FWD_DEFINED__
#define __IAcPePick2PointsCtrl_FWD_DEFINED__
typedef interface IAcPePick2PointsCtrl IAcPePick2PointsCtrl;

#endif 	/* __IAcPePick2PointsCtrl_FWD_DEFINED__ */


#ifndef __IAcPeCalculatorCtrl_FWD_DEFINED__
#define __IAcPeCalculatorCtrl_FWD_DEFINED__
typedef interface IAcPeCalculatorCtrl IAcPeCalculatorCtrl;

#endif 	/* __IAcPeCalculatorCtrl_FWD_DEFINED__ */


#ifndef __IAcPiPropertyEditControl_FWD_DEFINED__
#define __IAcPiPropertyEditControl_FWD_DEFINED__
typedef interface IAcPiPropertyEditControl IAcPiPropertyEditControl;

#endif 	/* __IAcPiPropertyEditControl_FWD_DEFINED__ */


#ifndef __IAcPiPropertyEditEventsSink_FWD_DEFINED__
#define __IAcPiPropertyEditEventsSink_FWD_DEFINED__
typedef interface IAcPiPropertyEditEventsSink IAcPiPropertyEditEventsSink;

#endif 	/* __IAcPiPropertyEditEventsSink_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorText_FWD_DEFINED__
#define __AcPePropertyEditorText_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorText AcPePropertyEditorText;
#else
typedef struct AcPePropertyEditorText AcPePropertyEditorText;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorText_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorLWeight_FWD_DEFINED__
#define __AcPePropertyEditorLWeight_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorLWeight AcPePropertyEditorLWeight;
#else
typedef struct AcPePropertyEditorLWeight AcPePropertyEditorLWeight;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorLWeight_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorLayer_FWD_DEFINED__
#define __AcPePropertyEditorLayer_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorLayer AcPePropertyEditorLayer;
#else
typedef struct AcPePropertyEditorLayer AcPePropertyEditorLayer;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorLayer_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorMaterial_FWD_DEFINED__
#define __AcPePropertyEditorMaterial_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorMaterial AcPePropertyEditorMaterial;
#else
typedef struct AcPePropertyEditorMaterial AcPePropertyEditorMaterial;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorMaterial_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorColor_FWD_DEFINED__
#define __AcPePropertyEditorColor_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorColor AcPePropertyEditorColor;
#else
typedef struct AcPePropertyEditorColor AcPePropertyEditorColor;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorColor_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorLType_FWD_DEFINED__
#define __AcPePropertyEditorLType_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorLType AcPePropertyEditorLType;
#else
typedef struct AcPePropertyEditorLType AcPePropertyEditorLType;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorLType_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorNumeric_FWD_DEFINED__
#define __AcPePropertyEditorNumeric_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorNumeric AcPePropertyEditorNumeric;
#else
typedef struct AcPePropertyEditorNumeric AcPePropertyEditorNumeric;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorNumeric_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorBool_FWD_DEFINED__
#define __AcPePropertyEditorBool_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorBool AcPePropertyEditorBool;
#else
typedef struct AcPePropertyEditorBool AcPePropertyEditorBool;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorBool_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorACADNumeric_FWD_DEFINED__
#define __AcPePropertyEditorACADNumeric_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorACADNumeric AcPePropertyEditorACADNumeric;
#else
typedef struct AcPePropertyEditorACADNumeric AcPePropertyEditorACADNumeric;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorACADNumeric_FWD_DEFINED__ */


#ifndef __AcPePick2PointsCtrl_FWD_DEFINED__
#define __AcPePick2PointsCtrl_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePick2PointsCtrl AcPePick2PointsCtrl;
#else
typedef struct AcPePick2PointsCtrl AcPePick2PointsCtrl;
#endif /* __cplusplus */

#endif 	/* __AcPePick2PointsCtrl_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorNumericArea_FWD_DEFINED__
#define __AcPePropertyEditorNumericArea_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorNumericArea AcPePropertyEditorNumericArea;
#else
typedef struct AcPePropertyEditorNumericArea AcPePropertyEditorNumericArea;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorNumericArea_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorEllipses_FWD_DEFINED__
#define __AcPePropertyEditorEllipses_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorEllipses AcPePropertyEditorEllipses;
#else
typedef struct AcPePropertyEditorEllipses AcPePropertyEditorEllipses;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorEllipses_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorEditButton_FWD_DEFINED__
#define __AcPePropertyEditorEditButton_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorEditButton AcPePropertyEditorEditButton;
#else
typedef struct AcPePropertyEditorEditButton AcPePropertyEditorEditButton;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorEditButton_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorEnum_FWD_DEFINED__
#define __AcPePropertyEditorEnum_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorEnum AcPePropertyEditorEnum;
#else
typedef struct AcPePropertyEditorEnum AcPePropertyEditorEnum;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorEnum_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorSpinnerEnum_FWD_DEFINED__
#define __AcPePropertyEditorSpinnerEnum_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorSpinnerEnum AcPePropertyEditorSpinnerEnum;
#else
typedef struct AcPePropertyEditorSpinnerEnum AcPePropertyEditorSpinnerEnum;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorSpinnerEnum_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorHatchEnum_FWD_DEFINED__
#define __AcPePropertyEditorHatchEnum_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorHatchEnum AcPePropertyEditorHatchEnum;
#else
typedef struct AcPePropertyEditorHatchEnum AcPePropertyEditorHatchEnum;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorHatchEnum_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorMTextDir_FWD_DEFINED__
#define __AcPePropertyEditorMTextDir_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorMTextDir AcPePropertyEditorMTextDir;
#else
typedef struct AcPePropertyEditorMTextDir AcPePropertyEditorMTextDir;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorMTextDir_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorHatchISOPenWidth_FWD_DEFINED__
#define __AcPePropertyEditorHatchISOPenWidth_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorHatchISOPenWidth AcPePropertyEditorHatchISOPenWidth;
#else
typedef struct AcPePropertyEditorHatchISOPenWidth AcPePropertyEditorHatchISOPenWidth;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorHatchISOPenWidth_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorHatchPatternName_FWD_DEFINED__
#define __AcPePropertyEditorHatchPatternName_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorHatchPatternName AcPePropertyEditorHatchPatternName;
#else
typedef struct AcPePropertyEditorHatchPatternName AcPePropertyEditorHatchPatternName;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorHatchPatternName_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorEllipsisHatchPatternType_FWD_DEFINED__
#define __AcPePropertyEditorEllipsisHatchPatternType_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorEllipsisHatchPatternType AcPePropertyEditorEllipsisHatchPatternType;
#else
typedef struct AcPePropertyEditorEllipsisHatchPatternType AcPePropertyEditorEllipsisHatchPatternType;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorEllipsisHatchPatternType_FWD_DEFINED__ */


#ifndef __AcPeDlgLaunchCtrl_FWD_DEFINED__
#define __AcPeDlgLaunchCtrl_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPeDlgLaunchCtrl AcPeDlgLaunchCtrl;
#else
typedef struct AcPeDlgLaunchCtrl AcPeDlgLaunchCtrl;
#endif /* __cplusplus */

#endif 	/* __AcPeDlgLaunchCtrl_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorVariant_FWD_DEFINED__
#define __AcPePropertyEditorVariant_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorVariant AcPePropertyEditorVariant;
#else
typedef struct AcPePropertyEditorVariant AcPePropertyEditorVariant;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorVariant_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorEllipsesHyperlinks_FWD_DEFINED__
#define __AcPePropertyEditorEllipsesHyperlinks_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorEllipsesHyperlinks AcPePropertyEditorEllipsesHyperlinks;
#else
typedef struct AcPePropertyEditorEllipsesHyperlinks AcPePropertyEditorEllipsesHyperlinks;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorEllipsesHyperlinks_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorSpin_FWD_DEFINED__
#define __AcPePropertyEditorSpin_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorSpin AcPePropertyEditorSpin;
#else
typedef struct AcPePropertyEditorSpin AcPePropertyEditorSpin;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorSpin_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorDimArrowHead_FWD_DEFINED__
#define __AcPePropertyEditorDimArrowHead_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorDimArrowHead AcPePropertyEditorDimArrowHead;
#else
typedef struct AcPePropertyEditorDimArrowHead AcPePropertyEditorDimArrowHead;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorDimArrowHead_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorGradientPattern_FWD_DEFINED__
#define __AcPePropertyEditorGradientPattern_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorGradientPattern AcPePropertyEditorGradientPattern;
#else
typedef struct AcPePropertyEditorGradientPattern AcPePropertyEditorGradientPattern;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorGradientPattern_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorPlotStyleName_FWD_DEFINED__
#define __AcPePropertyEditorPlotStyleName_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorPlotStyleName AcPePropertyEditorPlotStyleName;
#else
typedef struct AcPePropertyEditorPlotStyleName AcPePropertyEditorPlotStyleName;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorPlotStyleName_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorPlotStyleTable_FWD_DEFINED__
#define __AcPePropertyEditorPlotStyleTable_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorPlotStyleTable AcPePropertyEditorPlotStyleTable;
#else
typedef struct AcPePropertyEditorPlotStyleTable AcPePropertyEditorPlotStyleTable;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorPlotStyleTable_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorNoPickVariant_FWD_DEFINED__
#define __AcPePropertyEditorNoPickVariant_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorNoPickVariant AcPePropertyEditorNoPickVariant;
#else
typedef struct AcPePropertyEditorNoPickVariant AcPePropertyEditorNoPickVariant;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorNoPickVariant_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorRasterImageHeight_FWD_DEFINED__
#define __AcPePropertyEditorRasterImageHeight_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorRasterImageHeight AcPePropertyEditorRasterImageHeight;
#else
typedef struct AcPePropertyEditorRasterImageHeight AcPePropertyEditorRasterImageHeight;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorRasterImageHeight_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorRasterImageWidth_FWD_DEFINED__
#define __AcPePropertyEditorRasterImageWidth_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorRasterImageWidth AcPePropertyEditorRasterImageWidth;
#else
typedef struct AcPePropertyEditorRasterImageWidth AcPePropertyEditorRasterImageWidth;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorRasterImageWidth_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorTextJustify_FWD_DEFINED__
#define __AcPePropertyEditorTextJustify_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorTextJustify AcPePropertyEditorTextJustify;
#else
typedef struct AcPePropertyEditorTextJustify AcPePropertyEditorTextJustify;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorTextJustify_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorEllipseEndAngle_FWD_DEFINED__
#define __AcPePropertyEditorEllipseEndAngle_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorEllipseEndAngle AcPePropertyEditorEllipseEndAngle;
#else
typedef struct AcPePropertyEditorEllipseEndAngle AcPePropertyEditorEllipseEndAngle;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorEllipseEndAngle_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorDimStyle_FWD_DEFINED__
#define __AcPePropertyEditorDimStyle_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorDimStyle AcPePropertyEditorDimStyle;
#else
typedef struct AcPePropertyEditorDimStyle AcPePropertyEditorDimStyle;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorDimStyle_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorTextStyle_FWD_DEFINED__
#define __AcPePropertyEditorTextStyle_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorTextStyle AcPePropertyEditorTextStyle;
#else
typedef struct AcPePropertyEditorTextStyle AcPePropertyEditorTextStyle;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorTextStyle_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorMTextStyle_FWD_DEFINED__
#define __AcPePropertyEditorMTextStyle_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorMTextStyle AcPePropertyEditorMTextStyle;
#else
typedef struct AcPePropertyEditorMTextStyle AcPePropertyEditorMTextStyle;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorMTextStyle_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorCustomColor_FWD_DEFINED__
#define __AcPePropertyEditorCustomColor_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorCustomColor AcPePropertyEditorCustomColor;
#else
typedef struct AcPePropertyEditorCustomColor AcPePropertyEditorCustomColor;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorCustomColor_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorPwdText_FWD_DEFINED__
#define __AcPePropertyEditorPwdText_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorPwdText AcPePropertyEditorPwdText;
#else
typedef struct AcPePropertyEditorPwdText AcPePropertyEditorPwdText;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorPwdText_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorTextEx_FWD_DEFINED__
#define __AcPePropertyEditorTextEx_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorTextEx AcPePropertyEditorTextEx;
#else
typedef struct AcPePropertyEditorTextEx AcPePropertyEditorTextEx;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorTextEx_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorVisualStyle_FWD_DEFINED__
#define __AcPePropertyEditorVisualStyle_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorVisualStyle AcPePropertyEditorVisualStyle;
#else
typedef struct AcPePropertyEditorVisualStyle AcPePropertyEditorVisualStyle;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorVisualStyle_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorLightLampColor_FWD_DEFINED__
#define __AcPePropertyEditorLightLampColor_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorLightLampColor AcPePropertyEditorLightLampColor;
#else
typedef struct AcPePropertyEditorLightLampColor AcPePropertyEditorLightLampColor;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorLightLampColor_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorIntensityScheme_FWD_DEFINED__
#define __AcPePropertyEditorIntensityScheme_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorIntensityScheme AcPePropertyEditorIntensityScheme;
#else
typedef struct AcPePropertyEditorIntensityScheme AcPePropertyEditorIntensityScheme;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorIntensityScheme_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorLightWebPreview_FWD_DEFINED__
#define __AcPePropertyEditorLightWebPreview_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorLightWebPreview AcPePropertyEditorLightWebPreview;
#else
typedef struct AcPePropertyEditorLightWebPreview AcPePropertyEditorLightWebPreview;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorLightWebPreview_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorLightIntensity_FWD_DEFINED__
#define __AcPePropertyEditorLightIntensity_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorLightIntensity AcPePropertyEditorLightIntensity;
#else
typedef struct AcPePropertyEditorLightIntensity AcPePropertyEditorLightIntensity;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorLightIntensity_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorTableStyle_FWD_DEFINED__
#define __AcPePropertyEditorTableStyle_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorTableStyle AcPePropertyEditorTableStyle;
#else
typedef struct AcPePropertyEditorTableStyle AcPePropertyEditorTableStyle;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorTableStyle_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorAttributeValue_FWD_DEFINED__
#define __AcPePropertyEditorAttributeValue_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorAttributeValue AcPePropertyEditorAttributeValue;
#else
typedef struct AcPePropertyEditorAttributeValue AcPePropertyEditorAttributeValue;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorAttributeValue_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorPredefBlock_FWD_DEFINED__
#define __AcPePropertyEditorPredefBlock_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorPredefBlock AcPePropertyEditorPredefBlock;
#else
typedef struct AcPePropertyEditorPredefBlock AcPePropertyEditorPredefBlock;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorPredefBlock_FWD_DEFINED__ */


#ifndef __AcPePropertyEditorMLeaderStyle_FWD_DEFINED__
#define __AcPePropertyEditorMLeaderStyle_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertyEditorMLeaderStyle AcPePropertyEditorMLeaderStyle;
#else
typedef struct AcPePropertyEditorMLeaderStyle AcPePropertyEditorMLeaderStyle;
#endif /* __cplusplus */

#endif 	/* __AcPePropertyEditorMLeaderStyle_FWD_DEFINED__ */


#ifndef __AcPePropertySectionLayerCombo_FWD_DEFINED__
#define __AcPePropertySectionLayerCombo_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPePropertySectionLayerCombo AcPePropertySectionLayerCombo;
#else
typedef struct AcPePropertySectionLayerCombo AcPePropertySectionLayerCombo;
#endif /* __cplusplus */

#endif 	/* __AcPePropertySectionLayerCombo_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __ACPEXCTLLib_LIBRARY_DEFINED__
#define __ACPEXCTLLib_LIBRARY_DEFINED__

/* library ACPEXCTLLib */
/* [custom][custom][custom][custom][helpstring][version][uuid] */ 












typedef /* [uuid] */  DECLSPEC_UUID("40A74AC3-88FA-473A-9357-4A73DE86CA2B") 
enum AcPeNumericType
    {
        PE_ACAD_DISTANCE	= 0,
        PE_ACAD_ANGLE	= 1,
        PE_ACAD_NOUNITS	= 2,
        PE_ACAD_OTHER	= 3,
        PE_ACAD_ANGLEPLUS360	= 4,
        PE_ACAD_RELATIVE_ANGLE	= 5,
        PE_ACAD_RAW_ANGLE	= 6
    } 	AcPeNumericType;

typedef /* [custom][public] */ INT64 LONG_PTR;

typedef /* [custom][public] */ UINT64 UINT_PTR;


EXTERN_C const IID LIBID_ACPEXCTLLib;

#ifndef __IAcPeNumericEditor_INTERFACE_DEFINED__
#define __IAcPeNumericEditor_INTERFACE_DEFINED__

/* interface IAcPeNumericEditor */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPeNumericEditor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("43658EC4-0A4C-4A97-A90B-D904AEFDD509")
    IAcPeNumericEditor : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT __stdcall SetNumericDataType( 
            /* [in] */ AcPeNumericType dataType) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPeNumericEditorVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPeNumericEditor * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPeNumericEditor * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPeNumericEditor * This);
        
        DECLSPEC_XFGVIRT(IAcPeNumericEditor, SetNumericDataType)
        /* [helpstring] */ HRESULT ( __stdcall *SetNumericDataType )( 
            IAcPeNumericEditor * This,
            /* [in] */ AcPeNumericType dataType);
        
        END_INTERFACE
    } IAcPeNumericEditorVtbl;

    interface IAcPeNumericEditor
    {
        CONST_VTBL struct IAcPeNumericEditorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPeNumericEditor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPeNumericEditor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPeNumericEditor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPeNumericEditor_SetNumericDataType(This,dataType)	\
    ( (This)->lpVtbl -> SetNumericDataType(This,dataType) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPeNumericEditor_INTERFACE_DEFINED__ */


#ifndef __IAcPeVariantCtrl_INTERFACE_DEFINED__
#define __IAcPeVariantCtrl_INTERFACE_DEFINED__

/* interface IAcPeVariantCtrl */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPeVariantCtrl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0A8B1013-AF0C-4C23-B798-FB12DA499BCD")
    IAcPeVariantCtrl : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT __stdcall SetDwCookies( 
            /* [in] */ VARIANT cookieArray) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall SetGroupOffset( 
            /* [in] */ unsigned long dwOffset) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall SetElementCount( 
            /* [in] */ unsigned long elemCount) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPeVariantCtrlVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPeVariantCtrl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPeVariantCtrl * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPeVariantCtrl * This);
        
        DECLSPEC_XFGVIRT(IAcPeVariantCtrl, SetDwCookies)
        /* [helpstring] */ HRESULT ( __stdcall *SetDwCookies )( 
            IAcPeVariantCtrl * This,
            /* [in] */ VARIANT cookieArray);
        
        DECLSPEC_XFGVIRT(IAcPeVariantCtrl, SetGroupOffset)
        /* [helpstring] */ HRESULT ( __stdcall *SetGroupOffset )( 
            IAcPeVariantCtrl * This,
            /* [in] */ unsigned long dwOffset);
        
        DECLSPEC_XFGVIRT(IAcPeVariantCtrl, SetElementCount)
        /* [helpstring] */ HRESULT ( __stdcall *SetElementCount )( 
            IAcPeVariantCtrl * This,
            /* [in] */ unsigned long elemCount);
        
        END_INTERFACE
    } IAcPeVariantCtrlVtbl;

    interface IAcPeVariantCtrl
    {
        CONST_VTBL struct IAcPeVariantCtrlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPeVariantCtrl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPeVariantCtrl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPeVariantCtrl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPeVariantCtrl_SetDwCookies(This,cookieArray)	\
    ( (This)->lpVtbl -> SetDwCookies(This,cookieArray) ) 

#define IAcPeVariantCtrl_SetGroupOffset(This,dwOffset)	\
    ( (This)->lpVtbl -> SetGroupOffset(This,dwOffset) ) 

#define IAcPeVariantCtrl_SetElementCount(This,elemCount)	\
    ( (This)->lpVtbl -> SetElementCount(This,elemCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPeVariantCtrl_INTERFACE_DEFINED__ */


#ifndef __IAcPeColorCtrl_INTERFACE_DEFINED__
#define __IAcPeColorCtrl_INTERFACE_DEFINED__

/* interface IAcPeColorCtrl */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPeColorCtrl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F3D6F961-0583-4AB3-80A5-23D3EE1960F9")
    IAcPeColorCtrl : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT __stdcall SetNoMetaColor( 
            /* [in] */ VARIANT_BOOL bNoMetaColors) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall SetAllowNoneColor( 
            /* [in] */ VARIANT_BOOL bAllowNone) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall SetFixedForeground( 
            /* [in] */ VARIANT_BOOL bFixedForeground) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPeColorCtrlVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPeColorCtrl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPeColorCtrl * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPeColorCtrl * This);
        
        DECLSPEC_XFGVIRT(IAcPeColorCtrl, SetNoMetaColor)
        /* [helpstring] */ HRESULT ( __stdcall *SetNoMetaColor )( 
            IAcPeColorCtrl * This,
            /* [in] */ VARIANT_BOOL bNoMetaColors);
        
        DECLSPEC_XFGVIRT(IAcPeColorCtrl, SetAllowNoneColor)
        /* [helpstring] */ HRESULT ( __stdcall *SetAllowNoneColor )( 
            IAcPeColorCtrl * This,
            /* [in] */ VARIANT_BOOL bAllowNone);
        
        DECLSPEC_XFGVIRT(IAcPeColorCtrl, SetFixedForeground)
        /* [helpstring] */ HRESULT ( __stdcall *SetFixedForeground )( 
            IAcPeColorCtrl * This,
            /* [in] */ VARIANT_BOOL bFixedForeground);
        
        END_INTERFACE
    } IAcPeColorCtrlVtbl;

    interface IAcPeColorCtrl
    {
        CONST_VTBL struct IAcPeColorCtrlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPeColorCtrl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPeColorCtrl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPeColorCtrl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPeColorCtrl_SetNoMetaColor(This,bNoMetaColors)	\
    ( (This)->lpVtbl -> SetNoMetaColor(This,bNoMetaColors) ) 

#define IAcPeColorCtrl_SetAllowNoneColor(This,bAllowNone)	\
    ( (This)->lpVtbl -> SetAllowNoneColor(This,bAllowNone) ) 

#define IAcPeColorCtrl_SetFixedForeground(This,bFixedForeground)	\
    ( (This)->lpVtbl -> SetFixedForeground(This,bFixedForeground) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPeColorCtrl_INTERFACE_DEFINED__ */


#ifndef __IAcPeSpinCtrl_INTERFACE_DEFINED__
#define __IAcPeSpinCtrl_INTERFACE_DEFINED__

/* interface IAcPeSpinCtrl */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPeSpinCtrl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B9688916-D101-4F3D-8088-1E6182205F15")
    IAcPeSpinCtrl : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT __stdcall SetControls( 
            /* [in] */ VARIANT varControlsIUnkArray) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPeSpinCtrlVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPeSpinCtrl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPeSpinCtrl * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPeSpinCtrl * This);
        
        DECLSPEC_XFGVIRT(IAcPeSpinCtrl, SetControls)
        /* [helpstring] */ HRESULT ( __stdcall *SetControls )( 
            IAcPeSpinCtrl * This,
            /* [in] */ VARIANT varControlsIUnkArray);
        
        END_INTERFACE
    } IAcPeSpinCtrlVtbl;

    interface IAcPeSpinCtrl
    {
        CONST_VTBL struct IAcPeSpinCtrlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPeSpinCtrl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPeSpinCtrl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPeSpinCtrl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPeSpinCtrl_SetControls(This,varControlsIUnkArray)	\
    ( (This)->lpVtbl -> SetControls(This,varControlsIUnkArray) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPeSpinCtrl_INTERFACE_DEFINED__ */


#ifndef __IAcPeNoPickVariantRW_INTERFACE_DEFINED__
#define __IAcPeNoPickVariantRW_INTERFACE_DEFINED__

/* interface IAcPeNoPickVariantRW */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPeNoPickVariantRW;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("36D7CD15-58FF-4B22-AD30-C66006481D64")
    IAcPeNoPickVariantRW : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT __stdcall SetAlwaysRW( 
            /* [in] */ VARIANT_BOOL bIsAlwaysRW) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPeNoPickVariantRWVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPeNoPickVariantRW * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPeNoPickVariantRW * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPeNoPickVariantRW * This);
        
        DECLSPEC_XFGVIRT(IAcPeNoPickVariantRW, SetAlwaysRW)
        /* [helpstring] */ HRESULT ( __stdcall *SetAlwaysRW )( 
            IAcPeNoPickVariantRW * This,
            /* [in] */ VARIANT_BOOL bIsAlwaysRW);
        
        END_INTERFACE
    } IAcPeNoPickVariantRWVtbl;

    interface IAcPeNoPickVariantRW
    {
        CONST_VTBL struct IAcPeNoPickVariantRWVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPeNoPickVariantRW_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPeNoPickVariantRW_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPeNoPickVariantRW_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPeNoPickVariantRW_SetAlwaysRW(This,bIsAlwaysRW)	\
    ( (This)->lpVtbl -> SetAlwaysRW(This,bIsAlwaysRW) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPeNoPickVariantRW_INTERFACE_DEFINED__ */


#ifndef __IAcPeButtonEditCtrl_INTERFACE_DEFINED__
#define __IAcPeButtonEditCtrl_INTERFACE_DEFINED__

/* interface IAcPeButtonEditCtrl */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPeButtonEditCtrl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("71F90788-6855-4EF6-BB6B-9F716D0D4BE3")
    IAcPeButtonEditCtrl : public IUnknown
    {
    public:
        virtual /* [helpstring][requestedit][bindable][propput] */ HRESULT __stdcall put_DefaultPicture( 
            /* [in] */ IUnknown *pIPicture) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propget] */ HRESULT __stdcall get_DefaultPicture( 
            /* [retval][out] */ IUnknown **pIPicture) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propput] */ HRESULT __stdcall put_DisabledPicture( 
            /* [in] */ IUnknown *pIPicture) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propget] */ HRESULT __stdcall get_DisabledPicture( 
            /* [retval][out] */ IUnknown **pIPicture) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPeButtonEditCtrlVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPeButtonEditCtrl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPeButtonEditCtrl * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPeButtonEditCtrl * This);
        
        DECLSPEC_XFGVIRT(IAcPeButtonEditCtrl, put_DefaultPicture)
        /* [helpstring][requestedit][bindable][propput] */ HRESULT ( __stdcall *put_DefaultPicture )( 
            IAcPeButtonEditCtrl * This,
            /* [in] */ IUnknown *pIPicture);
        
        DECLSPEC_XFGVIRT(IAcPeButtonEditCtrl, get_DefaultPicture)
        /* [helpstring][requestedit][bindable][propget] */ HRESULT ( __stdcall *get_DefaultPicture )( 
            IAcPeButtonEditCtrl * This,
            /* [retval][out] */ IUnknown **pIPicture);
        
        DECLSPEC_XFGVIRT(IAcPeButtonEditCtrl, put_DisabledPicture)
        /* [helpstring][requestedit][bindable][propput] */ HRESULT ( __stdcall *put_DisabledPicture )( 
            IAcPeButtonEditCtrl * This,
            /* [in] */ IUnknown *pIPicture);
        
        DECLSPEC_XFGVIRT(IAcPeButtonEditCtrl, get_DisabledPicture)
        /* [helpstring][requestedit][bindable][propget] */ HRESULT ( __stdcall *get_DisabledPicture )( 
            IAcPeButtonEditCtrl * This,
            /* [retval][out] */ IUnknown **pIPicture);
        
        END_INTERFACE
    } IAcPeButtonEditCtrlVtbl;

    interface IAcPeButtonEditCtrl
    {
        CONST_VTBL struct IAcPeButtonEditCtrlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPeButtonEditCtrl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPeButtonEditCtrl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPeButtonEditCtrl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPeButtonEditCtrl_put_DefaultPicture(This,pIPicture)	\
    ( (This)->lpVtbl -> put_DefaultPicture(This,pIPicture) ) 

#define IAcPeButtonEditCtrl_get_DefaultPicture(This,pIPicture)	\
    ( (This)->lpVtbl -> get_DefaultPicture(This,pIPicture) ) 

#define IAcPeButtonEditCtrl_put_DisabledPicture(This,pIPicture)	\
    ( (This)->lpVtbl -> put_DisabledPicture(This,pIPicture) ) 

#define IAcPeButtonEditCtrl_get_DisabledPicture(This,pIPicture)	\
    ( (This)->lpVtbl -> get_DisabledPicture(This,pIPicture) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPeButtonEditCtrl_INTERFACE_DEFINED__ */


#ifndef __IAcPeButtonPicture_INTERFACE_DEFINED__
#define __IAcPeButtonPicture_INTERFACE_DEFINED__

/* interface IAcPeButtonPicture */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPeButtonPicture;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5E147B2D-6E27-467F-A29A-D228D7A735DD")
    IAcPeButtonPicture : public IUnknown
    {
    public:
        virtual /* [helpstring][requestedit][bindable][propput] */ HRESULT __stdcall put_DefaultPicture( 
            /* [in] */ IUnknown *pIPicture) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propget] */ HRESULT __stdcall get_DefaultPicture( 
            /* [retval][out] */ IUnknown **pIPicture) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propput] */ HRESULT __stdcall put_DisabledPicture( 
            /* [in] */ IUnknown *pIPicture) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propget] */ HRESULT __stdcall get_DisabledPicture( 
            /* [retval][out] */ IUnknown **pIPicture) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPeButtonPictureVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPeButtonPicture * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPeButtonPicture * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPeButtonPicture * This);
        
        DECLSPEC_XFGVIRT(IAcPeButtonPicture, put_DefaultPicture)
        /* [helpstring][requestedit][bindable][propput] */ HRESULT ( __stdcall *put_DefaultPicture )( 
            IAcPeButtonPicture * This,
            /* [in] */ IUnknown *pIPicture);
        
        DECLSPEC_XFGVIRT(IAcPeButtonPicture, get_DefaultPicture)
        /* [helpstring][requestedit][bindable][propget] */ HRESULT ( __stdcall *get_DefaultPicture )( 
            IAcPeButtonPicture * This,
            /* [retval][out] */ IUnknown **pIPicture);
        
        DECLSPEC_XFGVIRT(IAcPeButtonPicture, put_DisabledPicture)
        /* [helpstring][requestedit][bindable][propput] */ HRESULT ( __stdcall *put_DisabledPicture )( 
            IAcPeButtonPicture * This,
            /* [in] */ IUnknown *pIPicture);
        
        DECLSPEC_XFGVIRT(IAcPeButtonPicture, get_DisabledPicture)
        /* [helpstring][requestedit][bindable][propget] */ HRESULT ( __stdcall *get_DisabledPicture )( 
            IAcPeButtonPicture * This,
            /* [retval][out] */ IUnknown **pIPicture);
        
        END_INTERFACE
    } IAcPeButtonPictureVtbl;

    interface IAcPeButtonPicture
    {
        CONST_VTBL struct IAcPeButtonPictureVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPeButtonPicture_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPeButtonPicture_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPeButtonPicture_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPeButtonPicture_put_DefaultPicture(This,pIPicture)	\
    ( (This)->lpVtbl -> put_DefaultPicture(This,pIPicture) ) 

#define IAcPeButtonPicture_get_DefaultPicture(This,pIPicture)	\
    ( (This)->lpVtbl -> get_DefaultPicture(This,pIPicture) ) 

#define IAcPeButtonPicture_put_DisabledPicture(This,pIPicture)	\
    ( (This)->lpVtbl -> put_DisabledPicture(This,pIPicture) ) 

#define IAcPeButtonPicture_get_DisabledPicture(This,pIPicture)	\
    ( (This)->lpVtbl -> get_DisabledPicture(This,pIPicture) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPeButtonPicture_INTERFACE_DEFINED__ */


#ifndef __IAcPePick2PointsCtrl_INTERFACE_DEFINED__
#define __IAcPePick2PointsCtrl_INTERFACE_DEFINED__

/* interface IAcPePick2PointsCtrl */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPePick2PointsCtrl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B97B9380-8FA2-4EA8-9223-9681EE84B2BC")
    IAcPePick2PointsCtrl : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT __stdcall SetPrompts( 
            /* [in] */ BSTR prompt1,
            /* [in] */ BSTR prompt2) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPePick2PointsCtrlVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPePick2PointsCtrl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPePick2PointsCtrl * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPePick2PointsCtrl * This);
        
        DECLSPEC_XFGVIRT(IAcPePick2PointsCtrl, SetPrompts)
        /* [helpstring] */ HRESULT ( __stdcall *SetPrompts )( 
            IAcPePick2PointsCtrl * This,
            /* [in] */ BSTR prompt1,
            /* [in] */ BSTR prompt2);
        
        END_INTERFACE
    } IAcPePick2PointsCtrlVtbl;

    interface IAcPePick2PointsCtrl
    {
        CONST_VTBL struct IAcPePick2PointsCtrlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPePick2PointsCtrl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPePick2PointsCtrl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPePick2PointsCtrl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPePick2PointsCtrl_SetPrompts(This,prompt1,prompt2)	\
    ( (This)->lpVtbl -> SetPrompts(This,prompt1,prompt2) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPePick2PointsCtrl_INTERFACE_DEFINED__ */


#ifndef __IAcPeCalculatorCtrl_INTERFACE_DEFINED__
#define __IAcPeCalculatorCtrl_INTERFACE_DEFINED__

/* interface IAcPeCalculatorCtrl */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPeCalculatorCtrl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1611AC55-84A8-4DA0-90D9-30EA84394750")
    IAcPeCalculatorCtrl : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT __stdcall SetCalculatorMode( 
            /* [in] */ VARIANT_BOOL mode) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPeCalculatorCtrlVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPeCalculatorCtrl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPeCalculatorCtrl * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPeCalculatorCtrl * This);
        
        DECLSPEC_XFGVIRT(IAcPeCalculatorCtrl, SetCalculatorMode)
        /* [helpstring] */ HRESULT ( __stdcall *SetCalculatorMode )( 
            IAcPeCalculatorCtrl * This,
            /* [in] */ VARIANT_BOOL mode);
        
        END_INTERFACE
    } IAcPeCalculatorCtrlVtbl;

    interface IAcPeCalculatorCtrl
    {
        CONST_VTBL struct IAcPeCalculatorCtrlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPeCalculatorCtrl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPeCalculatorCtrl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPeCalculatorCtrl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPeCalculatorCtrl_SetCalculatorMode(This,mode)	\
    ( (This)->lpVtbl -> SetCalculatorMode(This,mode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPeCalculatorCtrl_INTERFACE_DEFINED__ */


#ifndef __IAcPiPropertyEditControl_INTERFACE_DEFINED__
#define __IAcPiPropertyEditControl_INTERFACE_DEFINED__

/* interface IAcPiPropertyEditControl */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPiPropertyEditControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2ABA2085-DE06-445B-AB8D-D8BFEC7D7BC7")
    IAcPiPropertyEditControl : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InitEditControl( 
            /* [in] */ VARIANT *pVarObjDispArray,
            /* [in] */ VARIANT *pVarDynPropArray,
            /* [in] */ VARIANT *pDispidArray,
            /* [in] */ VARIANT_BOOL bReadOnly) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( 
            /* [in] */ unsigned long dwFlags) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_KeepFocus( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propput][id] */ HRESULT STDMETHODCALLTYPE put_BackColor( 
            /* [in] */ /* external definition not present */ OLE_COLOR pclr) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propget][id] */ HRESULT STDMETHODCALLTYPE get_BackColor( 
            /* [retval][out] */ /* external definition not present */ OLE_COLOR *pclr) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propput][id] */ HRESULT STDMETHODCALLTYPE put_ForeColor( 
            /* [in] */ /* external definition not present */ OLE_COLOR pclr) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propget][id] */ HRESULT STDMETHODCALLTYPE get_ForeColor( 
            /* [retval][out] */ /* external definition not present */ OLE_COLOR *pclr) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propput][id] */ HRESULT STDMETHODCALLTYPE put_ReadOnlyBackColor( 
            /* [in] */ /* external definition not present */ OLE_COLOR pclr) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propget][id] */ HRESULT STDMETHODCALLTYPE get_ReadOnlyBackColor( 
            /* [retval][out] */ /* external definition not present */ OLE_COLOR *pclr) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propput][id] */ HRESULT STDMETHODCALLTYPE put_ReadOnlyForeColor( 
            /* [in] */ /* external definition not present */ OLE_COLOR pclr) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propget][id] */ HRESULT STDMETHODCALLTYPE get_ReadOnlyForeColor( 
            /* [retval][out] */ /* external definition not present */ OLE_COLOR *pclr) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propput][id] */ HRESULT STDMETHODCALLTYPE put_Font( 
            /* [in] */ IUnknown *pIFont) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propget][id] */ HRESULT STDMETHODCALLTYPE get_Font( 
            /* [retval][out] */ IUnknown **pIFont) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPiPropertyEditControlVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPiPropertyEditControl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPiPropertyEditControl * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPiPropertyEditControl * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcPiPropertyEditControl * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcPiPropertyEditControl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcPiPropertyEditControl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcPiPropertyEditControl * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyEditControl, InitEditControl)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitEditControl )( 
            IAcPiPropertyEditControl * This,
            /* [in] */ VARIANT *pVarObjDispArray,
            /* [in] */ VARIANT *pVarDynPropArray,
            /* [in] */ VARIANT *pDispidArray,
            /* [in] */ VARIANT_BOOL bReadOnly);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyEditControl, Refresh)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IAcPiPropertyEditControl * This,
            /* [in] */ unsigned long dwFlags);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyEditControl, get_KeepFocus)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_KeepFocus )( 
            IAcPiPropertyEditControl * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyEditControl, put_BackColor)
        /* [helpstring][requestedit][bindable][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_BackColor )( 
            IAcPiPropertyEditControl * This,
            /* [in] */ /* external definition not present */ OLE_COLOR pclr);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyEditControl, get_BackColor)
        /* [helpstring][requestedit][bindable][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_BackColor )( 
            IAcPiPropertyEditControl * This,
            /* [retval][out] */ /* external definition not present */ OLE_COLOR *pclr);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyEditControl, put_ForeColor)
        /* [helpstring][requestedit][bindable][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ForeColor )( 
            IAcPiPropertyEditControl * This,
            /* [in] */ /* external definition not present */ OLE_COLOR pclr);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyEditControl, get_ForeColor)
        /* [helpstring][requestedit][bindable][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ForeColor )( 
            IAcPiPropertyEditControl * This,
            /* [retval][out] */ /* external definition not present */ OLE_COLOR *pclr);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyEditControl, put_ReadOnlyBackColor)
        /* [helpstring][requestedit][bindable][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ReadOnlyBackColor )( 
            IAcPiPropertyEditControl * This,
            /* [in] */ /* external definition not present */ OLE_COLOR pclr);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyEditControl, get_ReadOnlyBackColor)
        /* [helpstring][requestedit][bindable][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ReadOnlyBackColor )( 
            IAcPiPropertyEditControl * This,
            /* [retval][out] */ /* external definition not present */ OLE_COLOR *pclr);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyEditControl, put_ReadOnlyForeColor)
        /* [helpstring][requestedit][bindable][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ReadOnlyForeColor )( 
            IAcPiPropertyEditControl * This,
            /* [in] */ /* external definition not present */ OLE_COLOR pclr);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyEditControl, get_ReadOnlyForeColor)
        /* [helpstring][requestedit][bindable][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ReadOnlyForeColor )( 
            IAcPiPropertyEditControl * This,
            /* [retval][out] */ /* external definition not present */ OLE_COLOR *pclr);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyEditControl, put_Font)
        /* [helpstring][requestedit][bindable][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Font )( 
            IAcPiPropertyEditControl * This,
            /* [in] */ IUnknown *pIFont);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyEditControl, get_Font)
        /* [helpstring][requestedit][bindable][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Font )( 
            IAcPiPropertyEditControl * This,
            /* [retval][out] */ IUnknown **pIFont);
        
        END_INTERFACE
    } IAcPiPropertyEditControlVtbl;

    interface IAcPiPropertyEditControl
    {
        CONST_VTBL struct IAcPiPropertyEditControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPiPropertyEditControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPiPropertyEditControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPiPropertyEditControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPiPropertyEditControl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcPiPropertyEditControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcPiPropertyEditControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcPiPropertyEditControl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcPiPropertyEditControl_InitEditControl(This,pVarObjDispArray,pVarDynPropArray,pDispidArray,bReadOnly)	\
    ( (This)->lpVtbl -> InitEditControl(This,pVarObjDispArray,pVarDynPropArray,pDispidArray,bReadOnly) ) 

#define IAcPiPropertyEditControl_Refresh(This,dwFlags)	\
    ( (This)->lpVtbl -> Refresh(This,dwFlags) ) 

#define IAcPiPropertyEditControl_get_KeepFocus(This,pVal)	\
    ( (This)->lpVtbl -> get_KeepFocus(This,pVal) ) 

#define IAcPiPropertyEditControl_put_BackColor(This,pclr)	\
    ( (This)->lpVtbl -> put_BackColor(This,pclr) ) 

#define IAcPiPropertyEditControl_get_BackColor(This,pclr)	\
    ( (This)->lpVtbl -> get_BackColor(This,pclr) ) 

#define IAcPiPropertyEditControl_put_ForeColor(This,pclr)	\
    ( (This)->lpVtbl -> put_ForeColor(This,pclr) ) 

#define IAcPiPropertyEditControl_get_ForeColor(This,pclr)	\
    ( (This)->lpVtbl -> get_ForeColor(This,pclr) ) 

#define IAcPiPropertyEditControl_put_ReadOnlyBackColor(This,pclr)	\
    ( (This)->lpVtbl -> put_ReadOnlyBackColor(This,pclr) ) 

#define IAcPiPropertyEditControl_get_ReadOnlyBackColor(This,pclr)	\
    ( (This)->lpVtbl -> get_ReadOnlyBackColor(This,pclr) ) 

#define IAcPiPropertyEditControl_put_ReadOnlyForeColor(This,pclr)	\
    ( (This)->lpVtbl -> put_ReadOnlyForeColor(This,pclr) ) 

#define IAcPiPropertyEditControl_get_ReadOnlyForeColor(This,pclr)	\
    ( (This)->lpVtbl -> get_ReadOnlyForeColor(This,pclr) ) 

#define IAcPiPropertyEditControl_put_Font(This,pIFont)	\
    ( (This)->lpVtbl -> put_Font(This,pIFont) ) 

#define IAcPiPropertyEditControl_get_Font(This,pIFont)	\
    ( (This)->lpVtbl -> get_Font(This,pIFont) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPiPropertyEditControl_INTERFACE_DEFINED__ */


#ifndef __IAcPiPropertyEditEventsSink_INTERFACE_DEFINED__
#define __IAcPiPropertyEditEventsSink_INTERFACE_DEFINED__

/* interface IAcPiPropertyEditEventsSink */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPiPropertyEditEventsSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("788D95A7-5311-48C8-8295-8C20A9282A6C")
    IAcPiPropertyEditEventsSink : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT __stdcall OnClick( void) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall OnDblClick( void) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall OnKeyDown( 
            /* [in] */ LONG_PTR pnChar,
            /* [in] */ LONG_PTR keyData) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall OnKeyUp( 
            /* [in] */ LONG_PTR pnChar,
            /* [in] */ LONG_PTR keyData) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall OnRButtonDown( 
            /* [in] */ UINT_PTR wParam,
            /* [in] */ LONG_PTR lParam) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall OnMButtonDown( 
            /* [in] */ UINT_PTR wParam,
            /* [in] */ LONG_PTR lParam) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall OnBeginPropertyUpdate( void) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall OnEndPropertyUpdate( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPiPropertyEditEventsSinkVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPiPropertyEditEventsSink * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPiPropertyEditEventsSink * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPiPropertyEditEventsSink * This);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyEditEventsSink, OnClick)
        /* [helpstring] */ HRESULT ( __stdcall *OnClick )( 
            IAcPiPropertyEditEventsSink * This);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyEditEventsSink, OnDblClick)
        /* [helpstring] */ HRESULT ( __stdcall *OnDblClick )( 
            IAcPiPropertyEditEventsSink * This);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyEditEventsSink, OnKeyDown)
        /* [helpstring] */ HRESULT ( __stdcall *OnKeyDown )( 
            IAcPiPropertyEditEventsSink * This,
            /* [in] */ LONG_PTR pnChar,
            /* [in] */ LONG_PTR keyData);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyEditEventsSink, OnKeyUp)
        /* [helpstring] */ HRESULT ( __stdcall *OnKeyUp )( 
            IAcPiPropertyEditEventsSink * This,
            /* [in] */ LONG_PTR pnChar,
            /* [in] */ LONG_PTR keyData);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyEditEventsSink, OnRButtonDown)
        /* [helpstring] */ HRESULT ( __stdcall *OnRButtonDown )( 
            IAcPiPropertyEditEventsSink * This,
            /* [in] */ UINT_PTR wParam,
            /* [in] */ LONG_PTR lParam);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyEditEventsSink, OnMButtonDown)
        /* [helpstring] */ HRESULT ( __stdcall *OnMButtonDown )( 
            IAcPiPropertyEditEventsSink * This,
            /* [in] */ UINT_PTR wParam,
            /* [in] */ LONG_PTR lParam);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyEditEventsSink, OnBeginPropertyUpdate)
        /* [helpstring] */ HRESULT ( __stdcall *OnBeginPropertyUpdate )( 
            IAcPiPropertyEditEventsSink * This);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyEditEventsSink, OnEndPropertyUpdate)
        /* [helpstring] */ HRESULT ( __stdcall *OnEndPropertyUpdate )( 
            IAcPiPropertyEditEventsSink * This);
        
        END_INTERFACE
    } IAcPiPropertyEditEventsSinkVtbl;

    interface IAcPiPropertyEditEventsSink
    {
        CONST_VTBL struct IAcPiPropertyEditEventsSinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPiPropertyEditEventsSink_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPiPropertyEditEventsSink_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPiPropertyEditEventsSink_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPiPropertyEditEventsSink_OnClick(This)	\
    ( (This)->lpVtbl -> OnClick(This) ) 

#define IAcPiPropertyEditEventsSink_OnDblClick(This)	\
    ( (This)->lpVtbl -> OnDblClick(This) ) 

#define IAcPiPropertyEditEventsSink_OnKeyDown(This,pnChar,keyData)	\
    ( (This)->lpVtbl -> OnKeyDown(This,pnChar,keyData) ) 

#define IAcPiPropertyEditEventsSink_OnKeyUp(This,pnChar,keyData)	\
    ( (This)->lpVtbl -> OnKeyUp(This,pnChar,keyData) ) 

#define IAcPiPropertyEditEventsSink_OnRButtonDown(This,wParam,lParam)	\
    ( (This)->lpVtbl -> OnRButtonDown(This,wParam,lParam) ) 

#define IAcPiPropertyEditEventsSink_OnMButtonDown(This,wParam,lParam)	\
    ( (This)->lpVtbl -> OnMButtonDown(This,wParam,lParam) ) 

#define IAcPiPropertyEditEventsSink_OnBeginPropertyUpdate(This)	\
    ( (This)->lpVtbl -> OnBeginPropertyUpdate(This) ) 

#define IAcPiPropertyEditEventsSink_OnEndPropertyUpdate(This)	\
    ( (This)->lpVtbl -> OnEndPropertyUpdate(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPiPropertyEditEventsSink_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_AcPePropertyEditorText;

#ifdef __cplusplus

class DECLSPEC_UUID("664C89FC-CF78-46F8-9372-416267128717")
AcPePropertyEditorText;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorLWeight;

#ifdef __cplusplus

class DECLSPEC_UUID("708DDD2C-6770-422B-A7DC-4513E3A665B7")
AcPePropertyEditorLWeight;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorLayer;

#ifdef __cplusplus

class DECLSPEC_UUID("580C8A82-CC98-43CB-B4AD-0E4A96C4C292")
AcPePropertyEditorLayer;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorMaterial;

#ifdef __cplusplus

class DECLSPEC_UUID("1F3D3A83-1099-42AC-8F82-21540A2A40F4")
AcPePropertyEditorMaterial;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorColor;

#ifdef __cplusplus

class DECLSPEC_UUID("09A5121B-7D20-4EAB-9643-C87A3F5B892E")
AcPePropertyEditorColor;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorLType;

#ifdef __cplusplus

class DECLSPEC_UUID("64357F0D-E1D8-49F6-BC91-8DEA40C856FC")
AcPePropertyEditorLType;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorNumeric;

#ifdef __cplusplus

class DECLSPEC_UUID("35A287CB-1CF6-4631-BDCE-050066962AB3")
AcPePropertyEditorNumeric;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorBool;

#ifdef __cplusplus

class DECLSPEC_UUID("F45303D5-E117-4B41-A765-1DC8EABABFF4")
AcPePropertyEditorBool;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorACADNumeric;

#ifdef __cplusplus

class DECLSPEC_UUID("94EF7751-68D6-4E55-B4CF-2D026898C99A")
AcPePropertyEditorACADNumeric;
#endif

EXTERN_C const CLSID CLSID_AcPePick2PointsCtrl;

#ifdef __cplusplus

class DECLSPEC_UUID("362C18AB-89B4-4867-89C9-FE7FD380BBDA")
AcPePick2PointsCtrl;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorNumericArea;

#ifdef __cplusplus

class DECLSPEC_UUID("F8498EA3-CECB-4995-BD3D-FA95503BF15E")
AcPePropertyEditorNumericArea;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorEllipses;

#ifdef __cplusplus

class DECLSPEC_UUID("9AA744FE-00A6-4308-959A-69C84E981608")
AcPePropertyEditorEllipses;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorEditButton;

#ifdef __cplusplus

class DECLSPEC_UUID("191C03A4-228B-4B77-9398-40C15ACF8D25")
AcPePropertyEditorEditButton;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorEnum;

#ifdef __cplusplus

class DECLSPEC_UUID("66305F5C-77D9-4EF5-8081-5A562E50760D")
AcPePropertyEditorEnum;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorSpinnerEnum;

#ifdef __cplusplus

class DECLSPEC_UUID("FE87BD21-27BD-4384-8130-B5145447AE8A")
AcPePropertyEditorSpinnerEnum;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorHatchEnum;

#ifdef __cplusplus

class DECLSPEC_UUID("6670388B-9772-4974-9810-17E907EE3183")
AcPePropertyEditorHatchEnum;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorMTextDir;

#ifdef __cplusplus

class DECLSPEC_UUID("2E0C2C89-63C8-4738-BCFD-45271E28841F")
AcPePropertyEditorMTextDir;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorHatchISOPenWidth;

#ifdef __cplusplus

class DECLSPEC_UUID("746C0046-F2AC-406F-9B81-345C2CB93E32")
AcPePropertyEditorHatchISOPenWidth;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorHatchPatternName;

#ifdef __cplusplus

class DECLSPEC_UUID("CDB19000-662E-45F7-AAC7-1126080C4F47")
AcPePropertyEditorHatchPatternName;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorEllipsisHatchPatternType;

#ifdef __cplusplus

class DECLSPEC_UUID("E56C65C3-17D8-4893-89E4-B6A993B1F3CF")
AcPePropertyEditorEllipsisHatchPatternType;
#endif

EXTERN_C const CLSID CLSID_AcPeDlgLaunchCtrl;

#ifdef __cplusplus

class DECLSPEC_UUID("0826A30B-FE88-4BFE-994A-AF042D91277E")
AcPeDlgLaunchCtrl;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorVariant;

#ifdef __cplusplus

class DECLSPEC_UUID("8D03D0E3-6EA4-4844-A2D0-0EA2F587E1D4")
AcPePropertyEditorVariant;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorEllipsesHyperlinks;

#ifdef __cplusplus

class DECLSPEC_UUID("A8AC12E6-B9A7-408E-94FE-2F12DB0AD24C")
AcPePropertyEditorEllipsesHyperlinks;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorSpin;

#ifdef __cplusplus

class DECLSPEC_UUID("D2EF085A-0683-482C-B6C3-682496F9DD74")
AcPePropertyEditorSpin;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorDimArrowHead;

#ifdef __cplusplus

class DECLSPEC_UUID("2345FECD-BEEA-4271-8D67-31A62164458C")
AcPePropertyEditorDimArrowHead;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorGradientPattern;

#ifdef __cplusplus

class DECLSPEC_UUID("2F42A7E4-FB52-417E-82FE-377CA9D6418F")
AcPePropertyEditorGradientPattern;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorPlotStyleName;

#ifdef __cplusplus

class DECLSPEC_UUID("68289B3C-3F26-481A-89F4-5188AF952FCB")
AcPePropertyEditorPlotStyleName;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorPlotStyleTable;

#ifdef __cplusplus

class DECLSPEC_UUID("733EBF72-2787-4868-9BE6-E7A10DB3C874")
AcPePropertyEditorPlotStyleTable;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorNoPickVariant;

#ifdef __cplusplus

class DECLSPEC_UUID("7FB870D1-BBD2-40A4-AFA5-C2B29C7618F6")
AcPePropertyEditorNoPickVariant;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorRasterImageHeight;

#ifdef __cplusplus

class DECLSPEC_UUID("FF43FB0B-EDAD-4A06-8306-C3709C4AD412")
AcPePropertyEditorRasterImageHeight;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorRasterImageWidth;

#ifdef __cplusplus

class DECLSPEC_UUID("E29CC07E-026E-49CD-A014-7D2FE60F57CA")
AcPePropertyEditorRasterImageWidth;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorTextJustify;

#ifdef __cplusplus

class DECLSPEC_UUID("EE288F39-2590-4328-A7EB-13FFF7CC2F7D")
AcPePropertyEditorTextJustify;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorEllipseEndAngle;

#ifdef __cplusplus

class DECLSPEC_UUID("3B53DE19-5A53-425F-8E02-6BF9693F3849")
AcPePropertyEditorEllipseEndAngle;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorDimStyle;

#ifdef __cplusplus

class DECLSPEC_UUID("FC44C203-C515-464A-A59C-25B5E156B727")
AcPePropertyEditorDimStyle;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorTextStyle;

#ifdef __cplusplus

class DECLSPEC_UUID("5A29371F-921C-4BA1-B824-639295F0154F")
AcPePropertyEditorTextStyle;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorMTextStyle;

#ifdef __cplusplus

class DECLSPEC_UUID("C22F277E-BC78-4295-844B-6ACCDFF27F7D")
AcPePropertyEditorMTextStyle;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorCustomColor;

#ifdef __cplusplus

class DECLSPEC_UUID("E1DFDDAA-298E-44BF-9A7B-B071725F2D69")
AcPePropertyEditorCustomColor;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorPwdText;

#ifdef __cplusplus

class DECLSPEC_UUID("383B9D8A-323A-40ED-8B41-BF4C58AF270C")
AcPePropertyEditorPwdText;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorTextEx;

#ifdef __cplusplus

class DECLSPEC_UUID("B5FB6A0A-45D1-4B49-BEE4-6DB4B98EAFB2")
AcPePropertyEditorTextEx;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorVisualStyle;

#ifdef __cplusplus

class DECLSPEC_UUID("CB3F2399-331A-4737-846E-CA09675AA9F6")
AcPePropertyEditorVisualStyle;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorLightLampColor;

#ifdef __cplusplus

class DECLSPEC_UUID("DB44FF92-201D-4CF3-9405-143C5C00232D")
AcPePropertyEditorLightLampColor;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorIntensityScheme;

#ifdef __cplusplus

class DECLSPEC_UUID("7E00BB93-58CB-4CC9-8A42-0EA452EA033A")
AcPePropertyEditorIntensityScheme;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorLightWebPreview;

#ifdef __cplusplus

class DECLSPEC_UUID("219F6580-6ED6-4723-8E1C-C0FAE234F797")
AcPePropertyEditorLightWebPreview;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorLightIntensity;

#ifdef __cplusplus

class DECLSPEC_UUID("31DA6CA9-DA12-489A-9C3A-90D5B308DF37")
AcPePropertyEditorLightIntensity;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorTableStyle;

#ifdef __cplusplus

class DECLSPEC_UUID("C83792DF-BB71-41B5-B6DD-CEA35BB551E2")
AcPePropertyEditorTableStyle;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorAttributeValue;

#ifdef __cplusplus

class DECLSPEC_UUID("02AECB30-CDD5-4A28-962B-8CBD727E4D0E")
AcPePropertyEditorAttributeValue;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorPredefBlock;

#ifdef __cplusplus

class DECLSPEC_UUID("29739A0C-3E91-443E-9D27-0103CFB0B8D4")
AcPePropertyEditorPredefBlock;
#endif

EXTERN_C const CLSID CLSID_AcPePropertyEditorMLeaderStyle;

#ifdef __cplusplus

class DECLSPEC_UUID("81FCBF40-AA32-4F7D-BE54-9942F5AC5971")
AcPePropertyEditorMLeaderStyle;
#endif

EXTERN_C const CLSID CLSID_AcPePropertySectionLayerCombo;

#ifdef __cplusplus

class DECLSPEC_UUID("C46A5AB1-BF28-4667-9846-4EE2CE9BDF0A")
AcPePropertySectionLayerCombo;
#endif
#endif /* __ACPEXCTLLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


