#pragma once


////////////////////////////////////////
//Include
#include "renderSystem.h"

///////////////////////////////////////
//Enum
enum GameObjectType
{
	GameObjectType_None,
	GameObjectType_Ship,
	GameObjectType_Bullet,
	GameObjectType_Alien,
	GameObjectType_Heart,
	GameObjectType_Tank
};

///////////////////////////////////////
//Class GameObject
class GameObject
{
public:
	GameObject();

	void render(RenderSystem* rs);
	void update(float dt);

	bool intersects(GameObject* object);

	void setType(GameObjectType type) { m_type = type; }
	GameObjectType getType() { return m_type; }

	void setX(float x) { m_x = x; }
	float getX() { return m_x; }

	void setY(float y) { m_y = y; }
	float getY() { return m_y; }

	void setXSpeed(float x_Speed) { m_xSpeed = x_Speed; }
	float getXSpeed() { return m_xSpeed; }

	void setYSpeed(float y_Speed) { m_ySpeed = y_Speed; }
	float getYSpeed() { return m_ySpeed; }

	void setSymbol(char symbol) { m_symbol = symbol; }
	char getSymbol() { return m_symbol; }

	void setDefaultHp();
	unsigned short getHp() { return m_hp; }
	void setHp(unsigned short objHp) { m_hp = objHp; }

	void setColor(ConsoleColor color) { m_color = color; }
	void setBackgroundColor(ConsoleColor bgColor) { m_backgroundColor = bgColor; }
	ConsoleColor getBackgroundColor() const { return m_backgroundColor; }
private:
	GameObjectType m_type;

	float m_x;
	float m_y;
	float m_xSpeed;
	float m_ySpeed;

	char m_symbol;
	ConsoleColor m_color;
	ConsoleColor m_backgroundColor;

	unsigned short m_hp;

};