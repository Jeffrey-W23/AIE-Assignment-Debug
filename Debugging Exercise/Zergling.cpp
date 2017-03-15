#include "Zergling.h"

Zergling::Zergling()
{
	health = 80;
}

Zergling::~Zergling()
{
}

int Zergling::attack()
{
	return 15;
}

void Zergling::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
		health = 0;
}