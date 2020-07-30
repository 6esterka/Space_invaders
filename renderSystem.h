#pragma once
////////////////////////////
//Include
#include"ConsoleColor.h"
#include<Windows.h>

////////////////////////////
//Constants
const size_t screenRows = 38;
const size_t screemColums = 63;


////////////////////////////
//Struct
struct ConsoleSymbolData {
	char symbol;
	ConsoleColor symbolColor;
	ConsoleColor backgroundColor;
};

class RenderSystem {
public:
	RenderSystem();
	// Initialize-getting descriptor of
	//console and hiding blinking cursor
	void initialize();
	//Clear-clear all symbols in backBuffer
	//and changing all zero symbols to dark screen
	void clear();
	//drawChar-writing the one symbol into the backBuffer
	void drawChar(int r, int c, char symbol, ConsoleColor symbolColor, ConsoleColor backgroundColor);
	//drawText-writing the string of symbols into the backBuffer
	void drawText(int r, int c, const char* text, ConsoleColor symbolColor, ConsoleColor backGroundColor);
	//flush-comparing backBuffer and screenBuffer items and at the same time drawing where we determined the difference
	void flush();
private:
	void setConsoleCursor(int r, int c);
	void setConsoleColor(ConsoleColor symbolColor, ConsoleColor backgroundColor);
private:
	HANDLE m_consoleHandle;
	ConsoleSymbolData m_backBuffer[screenRows][screemColums];
	ConsoleSymbolData m_screenBuffer[screenRows][screemColums];
};