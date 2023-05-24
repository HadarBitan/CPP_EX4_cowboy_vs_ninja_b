#include <iostream>
#include "Team2.hpp"

using namespace std;
using namespace ariel;

Team2::Team2(Character *leader) : Team(leader) {}

void Team2::attack(Team *enemy) {
	if (enemy == nullptr)
		throw invalid_argument("Enemy is null");

	else if (!enemy->stillAlive() || !stillAlive())
		throw runtime_error("One of the teams is dead");

	else if (!getLeader()->isAlive())
		setLeader(closestMember());

	Character *chosenVictom = chooseVictom(enemy);

	for (Character *member : getTeamMembers())
	{
		if (!member->isAlive())
			continue;

		if (!chosenVictom->isAlive())
		{
			if (!enemy->stillAlive())
				return;

			chosenVictom = chooseVictom(enemy);
		}

		Cowboy *cowboy = dynamic_cast<Cowboy *>(member);

		if (cowboy != nullptr)
		{
			if (cowboy->hasboolets())
				cowboy->shoot(chosenVictom);

			else
				cowboy->reload();
		}

		else
		{
			Ninja *ninja = dynamic_cast<Ninja *>(member);

			if (ninja != nullptr)
			{
				if (ninja->distance(chosenVictom) <= 1)
					ninja->slash(chosenVictom);

				else
					ninja->move(chosenVictom);
			}
		}
	}
}

void Team2::print() const {
	for (Character *member : getTeamMembers())
		cout << member->print() << endl;
}