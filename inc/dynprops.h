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
***     Description:
***
*****************************************************************************/
#pragma once

#include "icarx/OPMPerInstancePropertySources.h"
#include "icarx/OPMPerInstancePropertyExtension.h"
#include "icarx/OPMPerInstancePropertyExtensionFactory.h"
#include "icarx/OPMPropertyExtension.h"
#include "icarx/OPMPropertyExtensionFactory.h"
#include "icarx/IDynamicPropertyNotify.h"
#include "icarx/IDynamicPropertyNotify2.h"
#include "icarx/IDynamicProperty.h"
#include "icarx/IDynamicProperty2.h"
#include "icarx/IDynamicPropertyGetDispId.h"
#include "icarx/IDynamicEnumProperty.h"
#include "icarx/IDynamicDialogProperty.h"
#include "icarx/IPropertyManager.h"
#include "icarx/IPropertyManager2.h"
#include "icarx/IPropertySource.h"
#include "icarx/IFilterableProperty.h"
#include "icarx/IFilterablePropertySource.h"
#include "icarx/IFilterableMultiplePropertySource.h"
#include "icarx/IFilterableSubtypePropertySource.h"

#include "adesk.h"
#include "AdAChar.h"
#include "acdbport.h"
#include "dynprops-AcFilterablePropertyContext.h"

const int MAX_OPMSTRLEN = 256;
const int DISPID_DYNAMIC = -23;

#define S_NOTIFYCMD MAKE_HRESULT(0, 0, 0x02)

#define GET_OPM_PERINSTANCE_CREATE_PROTOCOL()     \
	OPMPerInstancePropertyExtensionFactory::cast( \
			AcDbDatabase::desc()->queryX(OPMPerInstancePropertyExtensionFactory::desc()))

#define GET_OPM_PERINSTANCE_PROPERTY_SOURCES() \
	OPMPerInstancePropertySources::cast(       \
			AcDbDatabase::desc()->queryX(OPMPerInstancePropertySources::desc()))

#define GET_OPM_PERINSTANCE_EXTENSION_PROTOCOL(pAcRxClass) \
	GET_OPM_PERINSTANCE_CREATE_PROTOCOL()->CreateOPMPerInstancePropertyExtension(pAcRxClass)

#define GET_OPMEXTENSION_CREATE_PROTOCOL() \
	OPMPropertyExtensionFactory::cast(     \
			AcDbDatabase::desc()->queryX(OPMPropertyExtensionFactory::desc()))

#define GET_OPMPROPERTY_MANAGER(pAcRxClass) \
	GET_OPMEXTENSION_CREATE_PROTOCOL()->CreateOPMObjectProtocol(pAcRxClass)->GetPropertyManager()

#define GET_OPM_COMMAND_PROPERTY_MANAGER(pCommandName) \
	GET_OPMEXTENSION_CREATE_PROTOCOL()->CreateOPMCommandProtocol(pCommandName)->GetPropertyManager()
