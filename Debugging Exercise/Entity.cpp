#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::takeDamage(int damage)
{
}

int Entity::attack()
{
	return 0;
}

bool Entity::isAlive()
{
	if (health > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
