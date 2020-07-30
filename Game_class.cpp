#include"Game_class.h"
#include<cstdlib>
#include<conio.h>
#include<iostream>
#include<cmath>
#include"Input.h"
#include"Level1.h"
#include"LevelMenu.h"


spaceInvaders::spaceInvaders() {
	for (int i = 0; i < gameObjectsCountMax; i++) {
		m_arr_of_objects[i] = nullptr;
	}
}

void spaceInvaders::setupSystem() {
	srand(time(0));

	m_renderSystem.initialize();
}

void loadLevel(const unsigned char levelLoad[levelRows][levelColums + 1]) {
	for (int i = 0; i < levelRows; i++) {
		for (int j = 0; j <= levelColums; j++) {
			levelData0[i][j] = levelLoad[i][j];
		}
	}
}



void spaceInvaders::initialize(const int& level_num) {
	m_shipFireCoolDownTime = 0.0;
	m_alienAmplitudeTime = 0.0;
	if (level_num == 1) {
		loadLevel(levelData1);
	}
	else if (level_num == 2) {
		loadLevel(levelData2);
	}
	else if (level_num == 3) {
		loadLevel(levelData3);
	}
	else if (level_num == 4) {
		loadLevel(levelData4);
	}

	//Load level
	for (int r = 0; r < levelRows; r++) {
		for (int c = 0; c < levelColums; c++) {
			unsigned char cellSymbol = levelData0[r][c];
			GameObject * tank;
			GameObject* heart;
			switch (cellSymbol)
			{
				//Create Ship
			case CellSymbol_Ship:
			{
				createObject(GameObjectType_Ship,
					(c + 0.5),
					r,
					GetRenderCellSymbol(cellSymbol),
					GetRenderCellSymbolColor(cellSymbol),
					GetRenderCellSymbolBackGroundColor(cellSymbol));
				break;
			}
			case CellSymbol_Tank:
				tank = createObject(GameObjectType_Tank,
					(c + 0.5),
					r,
					GetRenderCellSymbol(cellSymbol),
					GetRenderCellSymbolColor(cellSymbol),
					GetRenderCellSymbolBackGroundColor(cellSymbol));
				//??????
				tank->setXSpeed(alienAmplitude*cos(m_alienAmplitudeTime));
				tank->setYSpeed(alienSpeed);
				break;
			
			
			case CellSymbol_Heart:
			 heart = createObject(GameObjectType_Heart,
					(c + 0.5),
					r,
					GetRenderCellSymbol(cellSymbol),
					GetRenderCellSymbolColor(cellSymbol),
					GetRenderCellSymbolBackGroundColor(cellSymbol));
				//??????
				heart->setXSpeed(alienAmplitude*cos(m_alienAmplitudeTime));
				heart->setYSpeed(alienSpeed);

				break;
			case CellSymbol_Alien:
			{
				GameObject * alien = createObject(GameObjectType_Alien,
					(c + 0.5),
					r,
					GetRenderCellSymbol(cellSymbol),
					GetRenderCellSymbolColor(cellSymbol),
					GetRenderCellSymbolBackGroundColor(cellSymbol));
				//??????
				alien->setXSpeed(alienAmplitude*cos(m_alienAmplitudeTime));
				alien->setYSpeed(alienSpeed);

				break;
			}
			}
		}
	}
}
bool spaceInvaders::frame() {
	//Calculate delta time
	clock_t clockNow = clock();
	clock_t deltaClock = clockNow - m_clockLastFrame;
	float deltaTime = float(deltaClock) / CLOCKS_PER_SEC;
	m_clockLastFrame = clockNow;

	render();
	update(deltaTime);
	//Calculate FPS
	//Increases counter of frame during the time of each tact
	framesCounter++;
	framesTimeCounter += deltaTime;
	//After passing 1 second we are replacing our previous frame 
	//for a new one and at the same time we are clean
	//our frameCounter and framesTimeCounter
	if (framesTimeCounter >= 1.0) {
		framesTimeCounter -= 1.0;
		fps = framesCounter;
		framesCounter = 0;
	}

	return m_isGameActive;
}

void spaceInvaders::render() {
	//Start frame
	m_renderSystem.clear();

	//Draw all game objects
	int objectsCount = 0;
	for (int i = 0; i < gameObjectsCountMax; i++) {
		if (m_arr_of_objects[i] != nullptr) {
			//Set to the position our object and draw it at console
			m_arr_of_objects[i]->render(&m_renderSystem);
			objectsCount++;
		}
	}

	//Draw objects count
	char objBuff[64];
	sprintf_s(objBuff, "Objs: %d", objectsCount);
	m_renderSystem.drawText(0, 0, objBuff, ConsoleColor_White, ConsoleColor_Black);

	//Draw FPS
	char FPSbuff[64];
	sprintf_s(FPSbuff, "Fps: %d", fps);
	m_renderSystem.drawText(0, 10, FPSbuff, ConsoleColor_White, ConsoleColor_Black);

	//Draw Points
	char Pointsbuff[64];
	sprintf_s(Pointsbuff, "Points: %d", counterOfPoints);
	m_renderSystem.drawText(0, 45, Pointsbuff, ConsoleColor_Red, ConsoleColor_Black);

	//Hearts
	char Heartsbuff[64];
	sprintf_s(Heartsbuff, "Hearts: %d", heartCount);
	m_renderSystem.drawText(0, 25, Heartsbuff, ConsoleColor_White, ConsoleColor_Black);
	//End frame
	m_renderSystem.flush();
}

GameObject* spaceInvaders::createObject(GameObjectType type, float x, float y, char symbol, ConsoleColor color, ConsoleColor bgcolor) {
	//Find free ptr and create object
	for (int i = 0; i < gameObjectsCountMax; i++) {
		if (m_arr_of_objects[i] == nullptr) {
			GameObject* object = new GameObject();

			object->setType(type);
			object->setX(x);
			object->setY(y);
			object->setSymbol(symbol);
			object->setColor(color);
			object->setBackgroundColor(bgcolor);
			object->setDefaultHp();
			m_arr_of_objects[i] = object;
			if (type == GameObjectType_Heart) {
				++heartCount;
			}
			return object;
		}
	}
	return nullptr;
}

void spaceInvaders::update(float dt) {
	
	//Update all game objects
	for (int i = 0; i < gameObjectsCountMax; i++) {
		GameObject* object = m_arr_of_objects[i];

		if (object != nullptr) {
			object->update(dt);

			switch (object->getType()) {
				//Hero ship
			case GameObjectType_Ship:
				//Borders
				if (object->getX() < 0) {
					object->setX(0);
				}
				else if (object->getX() > screemColums - 1) {
					object->setX(screemColums - 1);
				}

				//Move
				if (isKeyDown(VK_LEFT)) {
					object->setXSpeed(-shipSpeed);
				}
				else if (isKeyDown(VK_RIGHT)) {
					object->setXSpeed(shipSpeed);
				}
				else {
					object->setXSpeed(0.0);
				}

				//Fire
				if (isKeyDown(VK_SPACE)) {
					if (m_shipFireCoolDownTime <= 0.0) {
						m_shipFireCoolDownTime = shipFireCoolDown;

						//Create bullet
						GameObject* bullet = createObject(GameObjectType_Bullet,
							object->getX(),
							object->getY() - 1,
							GetRenderCellSymbol(CellSymbol_Bullet),
							GetRenderCellSymbolColor(CellSymbol_Bullet),
							GetRenderCellSymbolBackGroundColor(CellSymbol_Bullet));
						bullet->setYSpeed(-bulletSpeed);
					}
				}
				//Bullet
			case GameObjectType_Bullet:
				if (object->getY() < 0) {
					destroyObject(object);
				}
				else {
					for (int e = 0; e < gameObjectsCountMax; e++) {
						GameObject* anotherObject = m_arr_of_objects[e];
						if (anotherObject != nullptr) {
							if ((anotherObject->getType() == GameObjectType_Alien)||(anotherObject->getType()==GameObjectType_Tank)||(anotherObject->getType()==GameObjectType_Heart)) {
								if (anotherObject->intersects(object)) {
									if (anotherObject->getHp() <= 1) {
										
										if (anotherObject->getType() == GameObjectType_Heart) {
											--heartCount;
											
										}
										destroyObject(anotherObject);
										counterOfPoints += 10;
									}
									else if (anotherObject->getHp() > 1) {
										anotherObject->setHp(anotherObject->getHp() - 1);
									}
									destroyObject(object);
									
									break;
								}
							}
						}
					}
				}
				break;
				//Alien ship
			case GameObjectType_Alien:
			case GameObjectType_Heart:
			case GameObjectType_Tank:
			

				if (object->getY() >= screenRows)
					m_isGameActive = false;
				else
					object->setXSpeed(alienAmplitude*cos(m_alienAmplitudeTime));

				break;

			}
		}
	}

	//Ship coolDownTime
	if (m_shipFireCoolDownTime > 0.0) {
		m_shipFireCoolDownTime -= dt;
	}

	//Alien amplitude time
	m_alienAmplitudeTime += dt;

	//Victory
	if (heartCount == 0) {
		m_isGameActive = false;
		m_isGameWin = true;
	}

}

void spaceInvaders::final_result() {
	
	system("cls");
	if (m_isGameWin) {
		std::cout << "\t\t\t\t\n\n\n\n\n\n\n\n\n\n Congratulation you have winned the game.\n\t\t\t\t\t\tYour points:" << counterOfPoints << " \n\t\t\t\t\tPress Q to exit from the game";
	}
	else if (!m_isGameWin) {
		std::cout << "\t\t\t\t\n\n\n\n\n\n\n\n\n\n GAME OVER.\n\t\t\t\t\t\tYour points :"<< counterOfPoints<<" \n\t\t\t\t\tPress Q to exit from the game" ;
	}
	int exit = 0;
	while (true) {
		exit = _getch();
		if (exit == 113) {
			break;
		}
	}
}

void spaceInvaders::destroyObject(GameObject* object) {
	for (int i = 0; i < gameObjectsCountMax; i++) {
		if (m_arr_of_objects[i] == object) {
			delete m_arr_of_objects[i];
			m_arr_of_objects[i] = nullptr;
			return;
		}
	}
}

void spaceInvaders::shutdown() {
	for (int i = 0; i < gameObjectsCountMax; i++) {
		if (m_arr_of_objects[i] != nullptr) {
			delete m_arr_of_objects[i];
			m_arr_of_objects[i] = nullptr;
		}
	}
}