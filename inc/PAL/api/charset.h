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

enum Charset : int
{
	kUndefinedCharset = -1,
	kAnsiCharset = 0,
	kUnicodeCharset = 1,
	kSymbolCharset = 2,
	kJapaneseCharset = 128,
	kKoreanCharset = 129,
	kChineseSimpCharset = 134,
	kChineseTradCharset = 136,
	kJohabCharset = 130,
	kHebrewCharset = 177,
	kArabicCharset = 178,
	kGreekCharset = 161,
	kTurkishCharset = 162,
	kVietnameseCharset = 163,
	kThaiCharset = 222,
	kEastEuropeCharset = 238,
	kRussianCharset = 204,
	kBalticCharset = 186,
	kDefaultCharset = kUnicodeCharset,
	kINTERNALCHARSET = 256,

	kBengaliCharset = kINTERNALCHARSET,
	kGurmukhiCharset,
	kGujaratiCharset,
	kTamilCharset,
	kTeluguCharset,
	kKannadaCharset,
	kMalayalamCharset,
	kDevanagariCharset,
	kOriyaCharset,

	kMarathiCharset = kDevanagariCharset,
	kHindiCharset = kDevanagariCharset,
	kKonkaniCharset = kDevanagariCharset,
	kSanskritCharset = kDevanagariCharset,
	kPunjabiharset = kGurmukhiCharset,
	kAssameseCharset = kUnicodeCharset,
	kFinnishCharset = kUnicodeCharset,
	kBelgianCharset = kUnicodeCharset,
	kGeorgianCharset = kUnicodeCharset,
};
