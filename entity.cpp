#include "entity.h"
#include <iostream>



void Entity::draw() const
{
	switch (state)
	{
	case ATTACK:  ;
	case DEFENSE:;
	case DEAD:;

	}
	


}

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


STATE Entity::defense()
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

void Entity::printSheet() const
{
	printf("Name: %s", "\tHealth: %d\n", "\tAttack: %d\n", "\tArmor: %d\n", "\tRecovery:  \n");

}


bool Entity::isAlive()
{
	return false;
}
