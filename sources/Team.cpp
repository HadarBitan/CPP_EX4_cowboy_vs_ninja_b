#include <iostream>
#include <limits>
#include "Team.hpp"

using namespace std;
using namespace ariel;

Team::Team(Character *leader): leader(leader) {
	if (leader->hasTeam())
		throw runtime_error("Leader already has a team");

	teamMembers.push_back(leader);
	leader->assignTeam();
}

Team::Team(const Team &other) {
	for (Character *member : other.teamMembers)
	{
		Cowboy *cowboy = dynamic_cast<Cowboy *>(member);
		Ninja *ninja = dynamic_cast<Ninja *>(member);

		if (cowboy != nullptr)
			teamMembers.push_back(new Cowboy(*cowboy));

		else if (ninja != nullptr)
			teamMembers.push_back(new Ninja(*ninja));

		else
			throw runtime_error("Unknown character type");	
	}

	leader = teamMembers.front();
}

Team::Team(Team &&other) noexcept {
	teamMembers = std::move(other.teamMembers); // Move member variables
	leader = other.leader;

	other.leader = nullptr;
}

// Copy assignment operator
Team &Team::operator=(const Team &other) {
	if (this != &other)
	{
		for (Character *member : teamMembers)
			delete member;

		teamMembers.clear();

		for (Character *member : other.teamMembers)
		{
			Cowboy *cowboy = dynamic_cast<Cowboy *>(member);
			Ninja *ninja = dynamic_cast<Ninja *>(member);

			if (cowboy != nullptr)
				teamMembers.push_back(new Cowboy(*cowboy));

			else if (ninja != nullptr)
				teamMembers.push_back(new Ninja(*ninja));

			else
				throw runtime_error("Unknown character type");	
		}

		leader = teamMembers.front();
	}
	return *this;
}

// Move assignment operator
Team &Team::operator=(Team &&other) noexcept {
	if (this != &other)
	{
		teamMembers = std::move(other.teamMembers); // Move member variables
		leader = std::move(other.leader);
	}

	return *this;
}

Team::~Team() {
	for (Character *member : teamMembers)
		delete member;

	teamMembers.clear();
}

void Team::add(Character *teamMember) {
	if (teamMembers.size() == 10 || teamMember->hasTeam())
		throw runtime_error("Team is full or the character already has a team");

	teamMembers.push_back(teamMember);
	teamMember->assignTeam();
}

void Team::attack(Team *enemy) {
	if (enemy == nullptr)
		throw invalid_argument("Enemy is null");

	else if (!enemy->stillAlive() || !stillAlive())
		throw runtime_error("One of the teams is dead");

	else if (!leader->isAlive())
		leader = closestMember();

	Character *chosenVictom = chooseVictom(enemy);

	for (Character *member : teamMembers)
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

	for (Character *member : teamMembers)
	{
		if (!member->isAlive())
			continue;

		if (!chosenVictom->isAlive())
		{
			if (!enemy->stillAlive())
				return;

			chosenVictom = chooseVictom(enemy);
		}

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

int Team::stillAlive() {
	int countAlive = 0;

	for (Character *member : teamMembers)
	{
		if (member->isAlive())
			countAlive++;
	}

	return countAlive;
}

void Team::print() const {
	for (Character *member : teamMembers)
	{
		Cowboy *cowboy = dynamic_cast<Cowboy *>(member);

		if (cowboy != nullptr)
			cout << cowboy->print() << endl;
	}

	for (Character *member : teamMembers)
	{
		Ninja *ninja = dynamic_cast<Ninja *>(member);

		if (ninja != nullptr)
			cout << ninja->print() << endl;
	}
}

Character *Team::closestMember() {
	double minDist = numeric_limits<double>::max();
	Character *choosenMem = nullptr;

	for (Character *member : teamMembers)
	{
		if (!member->isAlive())
			continue;

		double dist = member->distance(leader);

		if (dist < minDist)
		{
			minDist = dist;
			choosenMem = member;
		}
	}

	return choosenMem;
}

Character *Team::chooseVictom(Team *enemy) {
	double minDist = numeric_limits<double>::max();
	Character *choosenMem = nullptr;

	for (Character *member : enemy->teamMembers)
	{
		if (!member->isAlive())
			continue;

		double dist = member->distance(leader);

		if (dist < minDist)
		{
			minDist = dist;
			choosenMem = member;
		}
	}

	return choosenMem;
}