#include"LevelMenu.h"
#include<iostream>
#include<conio.h>
#include<Windows.h>
void LevelMenu::Print_menu_parts(int symbol_begin, int symbol_center, int symbol_end) {
	std::cout << (char)symbol_begin;
	for (int i = 0; i < 40; ++i) {
		std::cout << (char)symbol_center;
	}
	std::cout << (char)symbol_end << "\n";
}

void LevelMenu::Move_Cursor(int& levelNum) {
	char inputCharMenu = _getch();
	inputCharMenu = tolower(inputCharMenu);
	switch (inputCharMenu) {
		//UP
	case 'w':
		if (cursor_pos > 0) {
			cursor_pos -= 2;
		}
		break;
		//DOWN
	case 's':
		if (cursor_pos < 6) {
			cursor_pos += 2;
		}
		break;
		//Enter key (Select the level)
	case 13:


		if (cursor_pos == 0) {
			++levelNum;
			level_menu = false;

		}
		else if (cursor_pos == 2) {
			levelNum += 2;
			level_menu = false;
		}
		else if (cursor_pos == 4) {
			levelNum += 3;
			level_menu = false;
		}
		else if (cursor_pos == 6) {
			levelNum += 4;
			level_menu = false;
		}

	}

}

void LevelMenu::hideCursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = 0;
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void LevelMenu::Draw_Level_Menu_Parts() {
	Print_menu_parts(First_Corner, Horizontal_Line, Second_Corner);
	Print_menu_parts(Vertical_Line, Empty_symbol, Vertical_Line);
	std::cout << (char)Vertical_Line << "             Space Invaders             " << (char)Vertical_Line << "\n";
	//Calling 3 times of function
	Print_menu_parts(Vertical_Line, Empty_symbol, Vertical_Line);
	std::cout << (char)Vertical_Line << "Created by:casper_bool,banana_juice     " << (char)Vertical_Line << "\n";
	Print_menu_parts(Vertical_Line, Empty_symbol, Vertical_Line);
	std::cout << (char)Vertical_Line << "                 Level 1                " << (char)Vertical_Line << '\n';
	if (cursor_pos == 0) {
		std::cout << (char)Vertical_Line << "                 -------                " << (char)Vertical_Line << '\n';
	}
	else {
		Print_menu_parts(Vertical_Line, Empty_symbol, Vertical_Line);
	}
	std::cout << (char)Vertical_Line << "                 Level 2                " << (char)Vertical_Line << '\n';
	if (cursor_pos == 2) {
		std::cout << (char)Vertical_Line << "                 -------                " << (char)Vertical_Line << '\n';
	}
	else {
		Print_menu_parts(Vertical_Line, Empty_symbol, Vertical_Line);
	}
	std::cout << (char)Vertical_Line << "                 Level 3                " << (char)Vertical_Line << '\n';
	if (cursor_pos == 4) {
		std::cout << (char)Vertical_Line << "                 -------                " << (char)Vertical_Line << '\n';
	}
	else {
		Print_menu_parts(Vertical_Line, Empty_symbol, Vertical_Line);
	}
	std::cout << (char)Vertical_Line << "                 Level 4                " << (char)Vertical_Line << '\n';
	if (cursor_pos == 6) {
		std::cout << (char)Vertical_Line << "                 -------                " << (char)Vertical_Line << '\n';
	}
	else {
		Print_menu_parts(Vertical_Line, Empty_symbol, Vertical_Line);
	}
	Print_menu_parts(Forth_Corner, Horizontal_Line, Third_Corner);
}

void LevelMenu::showMenu(int& levelNum) {
	hideCursor();
	Draw_Level_Menu_Parts();
	do {

		Move_Cursor(levelNum);
		system("cls");
		Draw_Level_Menu_Parts();
	} while (level_menu);
	system("cls");
}