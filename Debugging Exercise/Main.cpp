// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016

// Marines are trying to "de-bug" an area (haha . . . haha)
// However something's up with this code . . . figure out what's going wrong
// When you're finished, there should be no compiler errors or warnings
// The encounter should also run and finish correctly as per the rules in the comments

// In many cases there are differences between what's in otherwise identical sections
// for Marines and Zerglings. It's good to be able to tell what the differences are
// and why they might be important.

// What's efficient and inefficient? Why?
// What uses more memory and what doesn't? Why?

#include <iostream>
#include <vector>
#include "Marine.h"
#include "Zergling.h"

using std::vector;
using std::cout;
using std::endl;

// Is there a Marine Alive?
bool marineAlive(vector<Marine*> squad)
{
	return squad.size() > 0;
}

// Is there a zergling Alive
bool zerglingAlive(vector<Zergling*> swarm)
{
	return swarm.size() > 0;
}

int main()
{
	vector<Marine*> squad;
	vector<Zergling*> swarm;

	int squadSize = 10;
	int swarmSize = 20;

	// Set up the Squad and the Swarm at their initial sizes listed above
	for (size_t i = 0; i < squadSize; i++)
	{
		Marine* m = new Marine;
		squad.push_back(m);
	}

	for (size_t i = 0; i < swarmSize; i++)
	{
		Zergling* z = new Zergling;
		swarm.push_back(z);
	}

	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!" << endl;
	
	// Attack each other until only one team is left alive
	while (marineAlive(squad) && zerglingAlive(swarm)) // If anyone is left alive to fight . . .
	{
		for (size_t i = 0; i < squad.size(); i++) // go through the squad
		{
			if (zerglingAlive(swarm))
			{
				// each marine will attack the first zergling in the swarm
				cout << "A marine fires for " << squad[i]->attack() << " damage. " << endl;

				int damage = squad[i]->attack();

				swarm[0]->takeDamage(damage);

				if (!swarm[0]->isAlive()) // if the zergling dies, it is removed from the swarm
				{
					delete swarm[0];
					swarm.erase(swarm.begin());
					cout << "The zergling target dies" << endl;
				}
			}
		}

		for (size_t i = 0; i < swarm.size(); i++) // loop through zerglings
		{
			if (marineAlive(squad))
			{
				// each zergling will attack the first marine in the swarm
				cout << "A zergling attacks for " << swarm[i]->attack() << " damage." << endl;

				int damage = swarm[i]->attack();

				squad[0]->takeDamage(damage);

				if (!squad[0]->isAlive()) // if the marine dies, it is removed from the squad
				{
					delete squad[0];
					squad.erase(squad.begin());
					cout << "The marine succumbs to his wounds." << endl;
				}
			}
		}
	}

	// Once one team is completely eliminated, the fight ends and one team wins
	cout << "The fight is over. ";
	
	if (marineAlive(squad))
	{
		cout << "The Marines win." << endl;
		system("Pause");
	} 
	else if (zerglingAlive(swarm))
	{
		cout << "The Zerg win." << endl;
		system("Pause");
	}
	else
	{
		cout << "Error!" << endl;
		system("Pause");
	}

	// delete vectors
	for (size_t i = 0; i < swarmSize; i++)
	{
		delete swarm[i];
	}

	for (size_t i = 0; i < squadSize; i++)
	{
		delete squad[i];
	}
}