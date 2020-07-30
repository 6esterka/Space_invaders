#pragma once
enum Lines {
	Horizontal_Line = 205,
	Vertical_Line = 186,
	First_Corner = 201,
	Second_Corner = 187,
	Third_Corner = 188,
	Forth_Corner = 200,
	Empty_symbol = 0
};

class LevelMenu {
private:
	bool level_menu = true;
	int cursor_pos = 0;
	void Print_menu_parts(int symbol_begin, int symbol_center, int symbol_end);
	void Move_Cursor(int& levelNum);
	void Draw_Level_Menu_Parts();
	void hideCursor();
public:
	void showMenu(int &levelNum);

};