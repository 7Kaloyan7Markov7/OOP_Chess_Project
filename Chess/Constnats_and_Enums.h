#pragma once

enum class ColorType
{
	WHITE,
	BLACK,
	NOT_COLORED,
};

enum class FigureType
{
	ROOK,
	PAWN,
	BISHOP,
	QUEEM,
	KING,
	KNIGHT,
	NO_TYPE,
};

const wchar_t WHITE_KING = L'\u2654'; // ♔
const wchar_t WHITE_QUEEN = L'\u2655'; // ♕
const wchar_t WHITE_ROOK = L'\u2656'; // ♖
const wchar_t WHITE_BISHOP = L'\u2657'; // ♗
const wchar_t WHITE_KNIGHT = L'\u2658'; // ♘
const wchar_t PAWN = L'\u2659'; // ♙

const wchar_t BLACK_KING = L'\u265A'; // ♚
const wchar_t BLACK_QUEEN = L'\u265B'; // ♛
const wchar_t BLACK_ROOK = L'\u265C'; // ♜
const wchar_t BLACK_BISHOP = L'\u265D'; // ♝
const wchar_t BLACK_KNIGHT = L'\u265E'; // ♞
