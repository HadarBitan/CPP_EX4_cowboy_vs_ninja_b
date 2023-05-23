#include <iostream>
#include "Team2.hpp"
#include <string>
#include <vector>
#include <climits>
#include <stdexcept>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"



namespace ariel
{       
        Team2::Team2(Character *leader):Team(leader){}

        // Copy assignment operator
        Team2& Team2::operator=(const Team2& other) 
        {
                if (this != &other) 
                {
                        Team::operator=(other);  // Call base class's copy assignment operator
                }
                return *this;
        }

        // Move assignment operator
        Team2& Team2::operator=(Team2&& other) 
        {
                if (this != &other) 
                {
                        Team::operator=(std::move(other));  // Call base class's move assignment operator
                }
                return *this;
        }

        void Team2::add(Character *teamMember)
        {
                if((this->teamMembers.size() == 10) || teamMember->hasTeam())
                {
                    throw std::runtime_error("");
                }
                this->teamMembers.push_back(teamMember);
                teamMember->assignTeam();
        }

        Team2::~Team2(){}
}
