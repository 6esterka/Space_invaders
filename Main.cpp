#include<iostream>
#include"LevelMenu.h"
#include"Game_class.h"

int main() {
	int level_num = 0;
	LevelMenu levelMenu;
	levelMenu.showMenu(level_num);

	spaceInvaders game;
	game.setupSystem();
	game.initialize(level_num);
	
	while (game.frame()) {
		
	}

	game.final_result();

	game.shutdown();
}