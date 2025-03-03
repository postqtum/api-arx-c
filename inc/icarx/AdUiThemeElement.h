/***************************************************************************
***
***     Copyright (C) 2022-2023 IntelliCAD Technology Consortium. All Rights Reserved.
***
***     Use of the information contained herein, in part or in whole,
***     in/as source code and/or in/as object code, in any way by anyone
***     other than authorized employees of The IntelliCAD Technology Consortium,
***     or by anyone to whom The IntelliCAD Technology Consortium  has not
***     granted use is illegal.
***
***     Description: Declaration of AdUiThemeElement enum
***
*****************************************************************************/
#pragma once

enum AdUiThemeElement
{
	kUnknownElements = -1,

	kPaletteFontCaption,
	kPaletteFontTab,
	kPaletteFontToolTip,
	kPaletteFont,
	kWorksheetFont,
	kWorksheetFontCaption,
	kInspectorItemFont,
	kInspectorRootFont,

	kPaletteBackground,
	kPaletteCaptionBackground,
	kPaletteCaptionInactive,
	kPaletteCaptionText,
	kPaletteCaptionInactiveText,
	kPaletteTabText,
	kPaletteTabBackground,
	kPaletteBorder,
	kPaletteTabShadow,
	kPaletteTabHighlight,
	kPaletteTabTextHilite,
	kPaletteTabSelectHilite,
	kPaletteToolTip,
	kPaletteToolTipText,
	kPaletteButtonText,
	kPaletteButtonTextDisabled,
	kPaletteButtonBorder,
	kPaletteItemText,
	kPaletteScrollBackground,
	kPaletteScrollThumb,
	kPaletteScrollArrow,

	kWorksheetBackground,
	kWorksheetCaptionBackground,
	kWorksheetCaptionText,
	kWorksheet3DBtnShadow,
	kWorksheetButtonText,
	kWorksheetButtonTextDisabled,
	kWorksheetScrollBackground,
	kWorksheetScrollThumb,
	kWorksheetBorder,
	kWorksheetGripHighlight,

	kInspector,
	kInspectorTop,
	kInspectorCat,
	kInspectorItem,
	kInspectorBorder,
	kInspectorBorderItem,
	kInspectorTextTop,
	kInspectorTextCat,
	kInspectorTextItem,
	kInspectorTextLabel,
	kInspectorFGHighlight,
	kInspectorBGHighlight,
	kInspector3dShadow,
	kInspectorControl,
	kInspectorCatChevron1,
	kInspectorCatChevron2,
	kInspectorSubChevron,
	kInspectorCellHighlight,

	kPanelBackground,
	kPanelSashBackground,
	kPanelBorder,

	kControlBorder,
	kControlBackground,
	kDisabledControlBorder,
	kControlSupport,
	kControlHighlight,
	kControlActiveOuterBorder,
	kControlErrorOuterBorder,
	kControlActiveText,
	kControlText,
	kControlInactiveText,
	kControlDisabledText,

	kPaletteFrameInnerBorder,
	kPaletteFrameOuterBorder,
	kPaletteFrameBackground,
	kPaletteFrameShadow,
	kInspectorTopGradient1,
	kInspectorTopGradient2,
	kPaletteScrollBackgroundBorder,
	kPaletteScrollBackgroundGradient1,
	kPaletteScrollBackgroundGradient2,
	kPaletteScrollSliderInactive,
	kPaletteScrollSliderActiveOuterBorder,
	kPaletteScrollSliderActiveOuterGradient1,
	kPaletteScrollSliderActiveOuterGradient2,
	kPaletteScrollSliderActiveOuterGradient3,
	kPaletteScrollSliderActiveOuterGradient4,
	kPaletteScrollSliderActiveInnerGradient1,
	kPaletteScrollSliderActiveInnerGradient2,
	kInspectorClosedOuterBorder,
	kInspectorOpenOuterBorder,
	kInspectorInnerBorder,
	kPaletteColumnHeaderBackground,
	kPaletteHyperlinkText,
	kPaletteTreeOrListBackground,

	kAnchorBarBackground,
	kAnchorBarOuterBorder,
	kAnchorBarEmbossRightBottom,
	kAnchorBarEmbossLeftTop,
	kAnchorBarInnerHighlight,
	kAnchorBarGradient1,
	kAnchorBarGradient2,
	kAnchorBarActiveTitleBackground,
	kAnchorBarCaptionText,

	kGrabBarDotDark,
	kGrabBarDotLight,
	kControlBarTitleBackground,

	kAppFrameBorder,
	kAppFrameOuterBorder,
	kAppFrameOuterBorderInactive,
	kAppFrameOuterBorderMenu,
	kAppFrameOuterBorderMenuInactive,
	kAppFrameAFGradientTop,
	kAppFrameAFGradientBottom,
	kAppFrameCaptionActiveGradientTop,
	kAppFrameCaptionActiveGradientBottom,
	kAppFrameCaptionInActiveGradientTop,
	kAppFrameCaptionInActiveGradientBottom,
	kAppFrameCaptionInactiveBorder,
	kAppFrameCaptionOuterBorder,
	kAppFrameCaptionInnerBorder,
	kAppFrameQATGradientTop,
	kAppFrameQATGradientBottom,
	kAppFrameQATOuterBorder,
	kAppFrameQATInnerBorder,

	kAppFrameQATButtonsBorder,
	kAppFrameQATButtonsRolloverBorder,
	kAppFrameQATButtonsClickBorder,
	kAppFrameQATFlyoutButtonText,

	kAppFrameBigMBBGradientFillTop,
	kAppFrameBigMBBGradientFillMiddleUpper,
	kAppFrameBigMBBGradientFillMiddleLower,
	kAppFrameBigMBBGradientFillBottom,

	kAppFrameSmallMBBGradientFillTop,
	kAppFrameSmallMBBGradientFillMiddleUpper,
	kAppFrameSmallMBBGradientFillMiddleLower,
	kAppFrameSmallMBBGradientFillBottom,

	kAppFrameDocNameProductNameText,
	kAppFrameDocNameFileNameText,
	kAppFrameDocNameInactiveProductNameText,
	kAppFrameDocNameInactiveFileNameText,
	kAppFrameMenuBarMenuText,
	kAppFrameMenuBarMenuHighlightText,
	kAppFrameMenuBarMenuDeHighlightText,
	kAppFrameMenuBarRolloverBorder,
	kAppFrameMenuBarRolloverFill,
	kAppFrameMenuBarClickBorder,
	kAppFrameMenuBarClickFill,
	kAppFrameAppWindowControlButtonsRolloverGradientBorderTop,
	kAppFrameAppWindowControlButtonsRolloverGradientBorderMiddle,
	kAppFrameAppWindowControlButtonsRolloverGradientBorderBottom,
	kAppFrameAppWindowControlButtonsRolloverGradientFillTop,
	kAppFrameAppWindowControlButtonsRolloverGradientFillMiddleUpper,
	kAppFrameAppWindowControlButtonsRolloverGradientFillMiddleLower,
	kAppFrameAppWindowControlButtonsRolloverGradientFillBottom,
	kAppFrameAppWindowControlButtonsRolloverBorder,
	kAppFrameAppWindowControlButtonsRolloverSymbol,
	kAppFrameAppWindowControlButtonsClickGradientBorderTop,
	kAppFrameAppWindowControlButtonsClickGradientBorderMiddle,
	kAppFrameAppWindowControlButtonsClickGradientBorderBottom,
	kAppFrameAppWindowControlButtonsClickGradientFillTop,
	kAppFrameAppWindowControlButtonsClickGradientFillMiddleUpper,
	kAppFrameAppWindowControlButtonsClickGradientFillMiddleLower,
	kAppFrameAppWindowControlButtonsClickGradientFillBottom,
	kAppFrameAppWindowControlButtonsClickBorder,
	kAppFrameAppWindowControlButtonsClickSymbol,
	kAppFrameAppWindowControlButtonsSymbol,
	kAppFrameAppWindowControlCloseButtonsRolloverGradientFillTop,
	kAppFrameAppWindowControlCloseButtonsRolloverGradientFillBottom,
	kAppFrameAppWindowControlCloseButtonsRolloverBorder,
	kAppFrameAppWindowControlCloseButtonsRolloverSymbol,
	kAppFrameAppWindowControlCloseButtonsClickGradientFillTop,
	kAppFrameAppWindowControlCloseButtonsClickGradientFillBottom,
	kAppFrameAppWindowControlCloseButtonsClickBorder,
	kAppFrameAppWindowControlCloseButtonsClickSymbol,
	kAppFrameAppWindowControlCloseButtonsSymbol,
	kAppFrameInfoCenterToggleButtonText,
	kAppFrameZeroDocBackgroundGradientTop,
	kAppFrameZeroDocBackgroundGradientBottom,

	kStatusBarPaneUnSelectedTopGradient,
	kStatusBarPaneUnSelectedBottomGradient,
	kStatusBarPaneRolloverGradient1,
	kStatusBarPaneRolloverGradient2,
	kStatusBarPaneRolloverGradient3,
	kStatusBarPaneRolloverGradient4,
	kStatusBarPaneSelectionGradient1,
	kStatusBarPaneSelectionGradient2,
	kStatusBarPaneSelectionGradient3,
	kStatusBarPaneSelectionGradient4,
	kStatusBarPaneBorder1,
	kStatusBarPaneBorder2,
	kStatusBarBkGrdBorder,
	kStatusBarBkGrdInnerLine,
	kStatusBarBkGrdTopGradient,
	kStatusBarBkGrdBottomGradient,

	kToolbarGripDarkDot,
	kToolbarGripLightDot,
	kToolbarGripBackground,
	kToolbarBorder,
	kToolbarBackground,
	kToolbarRolloverBorder,
	kToolbarCloseButton,

	kSquareButtonBorder,
	kSquareButtonBackground,
	kSquareButtonDisabledBorder,
	kSquareButtonDisabledBackground,
	kSquareButtonHoverBorder,
	kSquareButtonHoverHighlight,
	kSquareButtonHoverBackgroundTop,
	kSquareButtonHoverBackgroundBottom,
	kSquareButtonClickBorder,
	kSquareButtonClickHighlight,
	kSquareButtonClickBackgroundTop,
	kSquareButtonClickBackgroundBottom,
	kSquareButtonToggledBorder,
	kSquareButtonToggledBackground,
	kSquareButtonToggledHoverBorder,
	kSquareButtonToggledHoverBackground,
	kSquareButtonToggledDisabledBorder,
	kSquareButtonToggledDisabledBackground,

	kComboBoxBackgroundTop,
	kComboBoxBackgroundBottom,
	kComboBoxBorder,
	kComboBoxActiveBackgroundTop,
	kComboBoxActiveBackgroundBottom,
	kComboBoxArrow,
	kComboBoxArrowShadow,
	kComboBoxHoverText,
	kComboBoxText,
	kComboBoxSelectText,
	kComboBoxDisabledText,
	kComboBoxHoverBackgroundTop,
	kComboBoxHoverBackgroundBottom,
	kComboBoxHoverBorder,
	kComboBoxSelectBackgroundTop,
	kComboBoxSelectBackgroundBottom,
	kComboBoxHoverSelectHighlight,
	kComboBoxSeparator,

	kSpinControlHighlight,
	kSpinControlBorder,
	kSpinControlArrow,
	kSpinControlClickBackgroundTop,
	kSpinControlClickBackgroundBottom,
	kSpinControlBackgroundTop,
	kSpinControlBackgroundBottom,

	kTextInputBackground,
	kTextInputBorder,
	kTextInputInnerShadow,
	kTextInputActiveBackgroundTop,
	kTextInputActiveBackgroundBottom,
	kTextInputActiveHighlight,
	kTextInputActiveText,
	kTextInputText,
	kTextInputDisabledText,
	kTextInputInactiveText,
	kTextInputActiveBorder,

	kCategoryExpander,
	kCategoryExpanderShadow,
	kGroupGrip,
	kGroupGripShadow,
	kCategoryBackground,
	kCategoryBorder,
	kCategoryActiveText,

	kListBoxBorder,
	kListBoxGrid,
	kListBoxHoverBackgroundTop,
	kListBoxHoverBackgroundBottom,
	kListBoxHoverBorder,
	kListBoxClickBackgroundTop,
	kListBoxClickBackgroundBottom,
	kListBoxClickBorder,
	kListBoxSelectBackgroundTop,
	kListBoxSelectBackgroundBottom,
	kListBoxSelectBorder,
	kListBoxSelectInactiveBackgroundTop,
	kListBoxSelectInactiveBackgroundBottom,
	kListBoxSelectHoverBackgroundTop,
	kListBoxSelectHoverBackgroundBottom,
	kListBoxSelectHoverBorder,
	kListBoxInnerShadow,
	kListBoxText,
	kListBoxDisabledText,
	kListBoxInactiveText,
	kListBoxSelectText,
	kListBoxSelectInactiveText,
	kListBoxSelectDisabledText,
	kListBoxColumnHeaderBackgroundTop,
	kListBoxColumnHeaderBackgroundBottom,
	kListBoxColumnHeaderBorder,
	kListBoxColumnHeaderText,
	kListBoxColumnHeaderArrow,
	kListBoxColumnHeaderSortCellBackgroundTop,
	kListBoxColumnHeaderSortCellBackgroundBottom,
	kListBoxGroupHeaderText,

	kTabControlBorder,
	kTabControlActiveBackground,
	kTabControlInactiveBackground,

	kTreeControlBorder,
	kTreeControlLine,
	kTreeControlSelectBackground,
	kTreeControlSelectActiveBackground,
	kTreeControlSelectInactiveBackground,
	kTreeControlText,
	kTreeControlDisabledText,
	kTreeControlInactiveText,
	kTreeControlSelectText,
	kTreeControlSelectInactiveText,
	kTreeControlSelectDisabledText,

	kCommandLineHintBackgroundColor,
	kCommandLineHintBorderColor,
	kCommandLineHintTextColor,
	kCommandLineHintSelectBackgroundColor,
	kCommandLineHintSelectBorderColor,
	kCommandLineHintSelectTextColor,
	kCommandLineHintHeaderBackgroundColor,
	kCommandLineHintHeaderTextColor,
};
