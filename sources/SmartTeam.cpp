#include "SmartTeam.hpp"

using namespace std;
using namespace ariel;

SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

void SmartTeam::attack(Team *enemy) {
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

		YoungNinja *Yninja = dynamic_cast<YoungNinja *>(member);

		if (Yninja != nullptr)
		{
			if (Yninja->distance(chosenVictom) <= 1)
				Yninja->slash(chosenVictom);

			else
				Yninja->move(chosenVictom);
		}
	}

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

		TrainedNinja *Tninja = dynamic_cast<TrainedNinja *>(member);

		if (Tninja != nullptr)
		{
			if (Tninja->distance(chosenVictom) <= 1)
				Tninja->slash(chosenVictom);

			else
				Tninja->move(chosenVictom);
		}
	}

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

		OldNinja *Oninja = dynamic_cast<OldNinja *>(member);

		if (Oninja != nullptr)
		{
			if (Oninja->distance(chosenVictom) <= 1)
				Oninja->slash(chosenVictom);

			else
				Oninja->move(chosenVictom);
		}
	}

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
	}
}

void SmartTeam::print() const {
	Team::print();
}
