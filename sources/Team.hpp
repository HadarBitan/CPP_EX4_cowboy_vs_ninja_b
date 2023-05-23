#ifndef TEAM_HPP
#define TEAM_HPP

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Point.hpp"
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"

namespace ariel
{
    class Team
    {
        public:
            vector<Character*> teamMembers;
            Character * leader;
            Team(const Team& other) : teamMembers(other.teamMembers), leader(other.leader){}
            Team& operator=(const Team& other);
            Team& operator=(Team&& other);
            Team(Team&& other) : teamMembers(std::move(other.teamMembers)), leader(std::move(other.leader)){}
            Team(Character *leader);
            virtual void add(Character *teamMember);
            virtual void attack(Team *enemy);
            virtual int stillAlive();
            virtual Character *closestMember(Character *leader);
            virtual Character *chooseVictom(Character *leader);
            virtual string print();

            virtual ~Team();
    };
}

#endif