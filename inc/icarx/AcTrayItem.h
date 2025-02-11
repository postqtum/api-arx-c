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
***     Description: Declaration of AcTrayItem class
***
*****************************************************************************/
#pragma once

#include "AcStatusBarItem.h"
#include "AcTrayItemAnimationControl.h"

class AcRxValue;
class AcTrayItemBubbleWindowControl;

#include "IcArxPackPush.h"

class AcTrayItem : public AcStatusBarItem
{
private:
	AcTrayItemAnimationControl m_AnimationControl;
	AcTrayItemAnimationControl* m_pAnimationControl;
	AcTrayItemBubbleWindowControl m_BubbleWindowControl;
	AcTrayItemBubbleWindowControl* m_pBubbleWindowControl;

public:
	AcTrayItem();
	ACAD_PORT AcTrayItem(const CString& strId);
	virtual ~AcTrayItem();

	virtual BOOL CloseAllBubbleWindows();
	AcTrayItemAnimationControl* GetAnimationControl() const;
	virtual AcTrayItemBubbleWindowControl* GetBubbleWindowControl() const;
	HICON GetIcon() const override;
	ACAD_PORT void GoToState(const CString& state, AcRxValue* parameter = nullptr);
	BOOL PlayAnimation(AcTrayItemAnimationControl* pAnimationControl);
	BOOL SetIcon(HICON hIcon) override;
	virtual BOOL ShowBubbleWindow(AcTrayItemBubbleWindowControl* pBubbleWindowControl);
	void StopAnimation();
};

#include "IcArxPackPop.h"
