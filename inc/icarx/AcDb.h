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
***     Description: Declaration of AcDb struct
***
*****************************************************************************/
#pragma once

#include "../adesk.h"
#include "../AdAChar.h"

#define ACDB_MODEL_SPACE ACRX_T("*Model_Space")
#define ACDB_PAPER_SPACE ACRX_T("*Paper_Space")
#define ACDB_NULL_HANDLE ACRX_T("\0\0\0\0\0\0\0")
#define ACDB_OPEN_BRACE_STR ACRX_T("{")
#define ACDB_OPEN_BRACE_CHAR ACRX_T('{')
#define ACDB_CLOSE_BRACE_STR ACRX_T("}")
#define ACDB_CLOSE_BRACE_CHAR ACRX_T('}')
#define ACDB_GROUP_DICTIONARY ACRX_T("ACAD_GROUP")
#define ACDB_MLINESTYLE_DICTIONARY ACRX_T("ACAD_MLINESTYLE")
#define ACDB_LAYOUT_DICTIONARY ACRX_T("ACAD_LAYOUT")
#define ACDB_PLOTSETTINGS_DICTIONARY ACRX_T("ACAD_PLOTSETTINGS")
#define ACDB_PLOTSTYLENAME_DICTIONARY ACRX_T("ACAD_PLOTSTYLENAME")
#define ACDB_MATERIAL_DICTIONARY ACRX_T("ACAD_MATERIAL")
#define ACDB_VISUALSTYLE_DICTIONARY ACRX_T("ACAD_VISUALSTYLE")
#define ACDB_COLOR_DICTIONARY ACRX_T("ACAD_COLOR")
#define ACDB_TABLESTYLE_DICTIONARY ACRX_T("ACAD_TABLESTYLE")
#define ACDB_EMBEDDED_OBJECT_STR ACRX_T("Embedded Object")
#define ACDB_LAYERSTATES_DICTIONARY ACRX_T("ACAD_LAYERSTATES")
#define ACDB_FIELD_DICTIONARY ACRX_T("ACAD_FIELD")
#define ACDB_FIELDLIST ACRX_T("ACAD_FIELDLIST")
#define ACDB_ENHANCED_BLOCK ACRX_T("ACAD_ENHANCEDBLOCK")
#define ACDB_ENHANCED_BLOCK_EVALKEY ACRX_T("ACAD_ENHANCEDBLOCKEVALKEY")
#define ACDB_ENHANCED_BLOCK_REF ACRX_T("ACAD_ENHANCEDBLOCK_REFERENCE")
#define ACDB_SECTION_MANAGER ACRX_T("ACAD_SECTION_MANAGER")
#define ACDB_DATALINK ACRX_T("ACAD_DATALINK")
#define ACDB_MLEADERSTYLE_DICTIONARY ACRX_T("ACAD_MLEADERSTYLE")
#define ACDB_ASSOCNETWORK_DICTIONARY ACRX_T("ACAD_ASSOCNETWORK")
#define ACDB_SECTIONSTYLE_DICTIONARY ACRX_T("ACAD_SECTIONVIEWSTYLE")
#define ACDB_DETAILSTYLE_DICTIONARY ACRX_T("ACAD_DETAILVIEWSTYLE")

#define ACDB_ANNOTATIONSCALES_COLLECTION acdbAnnotationScaleCollectionName()

namespace AcDb
{

enum OpenMode;

enum CoordAxis;

enum CoordSystem;

enum Intersect;

enum Visibility;

typedef int16_t DxfCode;

enum DwgDataType;

enum OsnapMask;

enum OsnapMode;

enum ShowImagesMode;

enum SaveImagesMode;

enum TextHorzMode;

enum TextVertMode;

enum LineSpacingStyle;

enum Planarity;

enum PointIndex;

enum EdgeIndex;

enum Poly2dType;

enum Poly3dType;

enum PolyMeshType;

enum Vertex2dType;

enum Vertex3dType;

enum SpaceValueType;

enum BoolOperType;

typedef uint32_t SubentType;

typedef uint32_t GeomId;

enum GeomType;

enum FilerType;

enum FilerSeekType;

enum AcDbDwgVersion;

enum MaintenanceReleaseVersion;

enum SaveType;

enum GroupOperType;

enum DeepCloneType;

enum DuplicateRecordCloning;

enum XrefStatus;

enum XrefNotificationStatus;

enum MeasurementValue;

enum UnitsValue;

enum TimeZone;

enum LineWeight;

enum EndCaps;

enum JoinStyle;

enum PlotStyleNameType;

enum IndexCreation;

enum LayerEvaluation;

enum NewLayerNotification;

enum DimArrowFlags;

enum DimblkFlags;

enum OrthographicView;

enum VpFreezeOps;

enum reservedStringEnumType;

enum SortEntsFlags;

enum DragStat;

enum GripStat;

enum DataLinkOption;

enum PathOption;

enum UpdateDirection;

enum UpdateOption;

enum DataLinkGetSourceContext;

enum CellType;

enum CellContentType;

enum CellEdgeMask;

enum CellMargin;

enum CellContentLayout;

enum CellState;

enum CellClass;

enum CellProperty;

enum GridProperty;

enum GridLineType;

enum GridLineStyle;

enum CellOption;

enum SelectType;

enum FlowDirection;

enum RotationAngle;

enum CellAlignment;

enum RowType;

enum TableStyleFlags;

enum TableBreakOption;

enum TableBreakFlowDirection;

enum TableFillOption;

enum TableCopyOption;

enum TableIteratorOption;

enum MergeCellStyleOption;

enum TableHitItem;

enum RowTypes;

enum GridLineTypes;

enum DrawOrderFlags;

enum UpdateThumbnailFlags;

enum EnhancedBlockEvalType;

enum SliceModelType;

enum CollisionType;

enum LoftParamType;

enum LoftNormalsType;

enum ShadowFlags;

enum LightingUnits;

enum FilletTrimMode;

enum ImplicitPointType;

};	// namespace AcDb
