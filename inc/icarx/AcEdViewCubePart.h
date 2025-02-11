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
***     Description: Declaration of AcEdViewCubePart enum
***
*****************************************************************************/
#pragma once

enum AcEdViewCubePart
{
	FACE_FRONT = 0,
	FACE_BACK,
	FACE_BOTTOM,
	FACE_TOP,
	FACE_LEFT,
	FACE_RIGHT,

	EDGE_FRONT_BOTTOM,
	EDGE_FRONT_TOP,
	EDGE_BACK_BOTTOM,
	EDGE_BACK_TOP,
	EDGE_LEFT_BOTTOM,
	EDGE_RIGHT_BOTTOM,
	EDGE_LEFT_TOP,
	EDGE_RIGHT_TOP,
	EDGE_FRONT_LEFT,
	EDGE_BACK_LEFT,
	EDGE_FRONT_RIGHT,
	EDGE_BACK_RIGHT,

	CORNER_FRONT_LEFT_BOTTOM,
	CORNER_FRONT_RIGHT_BOTTOM,
	CORNER_FRONT_LEFT_TOP,
	CORNER_FRONT_RIGHT_TOP,
	CORNER_BACK_LEFT_BOTTOM,
	CORNER_BACK_RIGHT_BOTTOM,
	CORNER_BACK_LEFT_TOP,
	CORNER_BACK_RIGHT_TOP,

	ARROW_FRONT,
	ARROW_BACK,
	ARROW_BOTTOM,
	ARROW_TOP,
	ARROW_LEFT,
	ARROW_RIGHT,

	BUTTON_ROTATE_CCW,
	BUTTON_ROTATE_CW,
	BUTTON_HOME,
	BUTTON_LOCK,
	BUTTON_MENU,

	COMPASS_EAST,
	COMPASS_WEST,
	COMPASS_SOUTH,
	COMPASS_NORTH,
	COMPASS_RING
};
