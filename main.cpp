#include <iostream>
#include "entity.h"
//
//class Menu
//{
//
//
//
//
//};
//
//class Enemy
//{
///*behavior states:
//	wander
//	pursuit*/
//
//	/*void update()
//	if no health: goto dead
//	{
//	wander:
//		do stuff;
//	pursuit:
//		do other stuff;
//	dead:
//		do nothing;
//	recover:
//		try to heal self;
//	}*/
//
//};



void Entity::init(const char a_name[])
{
	sprintf_s(name. "%s", a_name);

	health = maxhealth = rand() % 120 + 120;
	attack = maxattack = rand() % 20 + 20;
	armor = maxarmor = rand() % 60 + 60;

	critical = rand() % 3 + 2;

	threshold = rand() % health;

	state = ATTACK;

}

void Entity::step(Entity & e)
{
	switch (state)
	{
	case DEFENSE: 
		state = defense();
		break;
	case ATTACK: 
		state = attack(e); 
		break;
	case DEAD:;
	}
	


}


STATE Entity::attack(Entity & e)
{
	bool crit = rand() % critical == 0;

	int dmg = rand() % attack + attack;

	e.takeDameage(dmg, crit);

	if (health > threshold)
		return DEFENSE;
	else
		return ATTACK;

}

STATE Entity::armor()
{
	health += 5 + rand() % 30;
	attack += 5 + rand() % 5;
	armor += 5 + rand() % 5;

	if (health > threshold)
		return ATTACK;
	else if (health < 0)
		return DEAD;
	else
		return DEFENSE;


}

void Entity::takeDameage(int a_dmg, bool a_crit)
{
	int red = (a_dmg * 2) / 3;
	


}