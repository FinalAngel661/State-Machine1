#pragma once

//Enumerated Tyoe

enum STATE
{
	DEFENSE,
	ATTACK,
	DEAD

};

class Entity
{
private:
	char name[64];
	int health, maxhealth;
	int attack, maxattack;
	int defense, maxdefense;
	int critical;

	int threshold;

	STATE state;

	STATE attack(Entity &e);
	STATE defense();

	void takeDameage(int a_dmg, bool a_crit);

public:
	void init(const char a_name[]);

	void step(Entity &e);
	void printSheet() const;

	bool isAlive();

};