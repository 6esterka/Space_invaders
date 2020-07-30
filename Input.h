#pragma once

//////////////////
//Include
#include<Windows.h>


//////////////////
//Functions
//GetAsyncKeyState check that if our button pushed or not and at the same time is it at the pressed condition or not?
//returns the value in short
bool isKeyDown(int virtualKeyCode) {
	short keyState = GetAsyncKeyState(virtualKeyCode);
	return ((keyState & 0x8000) > 0);
}
