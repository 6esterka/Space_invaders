///////////////////////////////////////////////////
//Include
#include "gameObject.h"


///////////////////////////////////////////////////
//Realisation of methods and constructor of GameObject
GameObject::GameObject()
{
	m_type = GameObjectType_None;

	m_x = 0.0;
	m_y = 0.0;
	m_xSpeed = 0.0;
	m_ySpeed = 0.0;
	

	m_symbol = '?';
	m_color = ConsoleColor_White;
	m_backgroundColor = ConsoleColor_Black;
}

void GameObject::render(RenderSystem* rs) {
	int row = int(m_y);
	int column = int(m_x);

	rs->drawChar(row, column, m_symbol, m_color, m_backgroundColor);
}

void GameObject::update(float dt) {
	m_y += m_ySpeed * dt;
	m_x += m_xSpeed * dt;
}

bool GameObject::intersects(GameObject* object) {
	if ((int(m_y) == int(object->m_y)) && (int(m_x) == int(object->m_x))) {
		return true;
	}
	return false;
}

void GameObject::setDefaultHp() {
	switch (this->m_type) {
	case GameObjectType_Alien:
		m_hp = 1;
		break;
	case GameObjectType_Heart:
		m_hp = 1;
		break;
	case GameObjectType_Tank:
		m_hp = 5;
		break;
	default:
		m_hp = 0;
	}
}

