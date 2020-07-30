#pragma once

#include<ctime>
#include"renderSystem.h"
#include "gameObject.h"




////////////////////////////
//Constants
const int gameObjectsCountMax = 512;


class spaceInvaders {
private:
	bool m_isGameWin=false;
	bool m_isGameActive=true;
	clock_t m_clockLastFrame=0;
	RenderSystem m_renderSystem;
	GameObject* m_arr_of_objects[gameObjectsCountMax];
	//FPS
	//////////
	int framesCounter = 0;
	float framesTimeCounter = 0;
	int fps = 0;

	//////////
	float m_shipFireCoolDownTime=0.0;
	float m_alienAmplitudeTime=0.0;
	/////////
	//Ship counter of points
	size_t counterOfPoints=0;


	/////////
	//Counter of Hearts of alien sheap
	unsigned short heartCount = 0;
private:
	void render();
	void update(float dt);
	GameObject* createObject(GameObjectType type, float x, float y, char symbol, ConsoleColor color, ConsoleColor bgcolor);
	void destroyObject(GameObject* object);
public:
	spaceInvaders();
	//void loadLevel(const unsigned char levelLoad[levelRows][levelColums]);
	void setupSystem();
	void initialize(const int& level_num);
	bool frame();
	void final_result();
	void shutdown();

};

