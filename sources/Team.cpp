#include <iostream>
#include "Team.hpp"
#include <string>
#include <vector>
#include <typeinfo>
#include <stdexcept>
#include <climits>
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"


namespace ariel
{
        Team::Team(Character* leader)
        {
                if(leader->hasTeam())
                {
                        throw std::runtime_error("");
                }
                this->leader = leader;
                if(typeid(leader) == typeid(Cowboy))
                {
                        this->teamMembers[0] = leader;
                }
                else
                {
                        this->teamMembers.push_back(leader);
                }
                leader->assignTeam();
        }

        // Copy assignment operator
        Team& Team::operator=(const Team& other) 
        {
                if (this != &other) 
                {
                        teamMembers = other.teamMembers;  // Copy member variables
                        leader = other.leader;
                }
                return *this;
        }

        // Move assignment operator
        Team& Team::operator=(Team&& other) 
        {
                if (this != &other) 
                {
                        teamMembers = std::move(other.teamMembers);  // Move member variables
                        leader = std::move(other.leader);
                }
                return *this;
        }

        void Team::add(Character *teamMember)
        {
                if(this->teamMembers.size() == 10 || teamMember->hasTeam())
                {
                    throw std::runtime_error("");
                }
                if(typeid(teamMember) == typeid(Cowboy))
                {
                        std::vector<Character*>::size_type i = 0;
                        while(typeid(this->teamMembers[i]) == typeid(Cowboy) || this->teamMembers[i] != nullptr)
                        {
                                i++;
                        }
                        this->teamMembers[i] = teamMember;
                        teamMember->assignTeam();
                }
                else
                {
                        this->teamMembers.push_back(teamMember);
                        teamMember->assignTeam();
                }
        }
       
        void Team::attack(Team *enemy)
        {
                if(enemy == nullptr)
                {
                        throw std::invalid_argument("");
                }
                if(!enemy->stillAlive() || !this->stillAlive())
                {
                        return;
                }               
                if(!this->leader->isAlive())
                {
                        Character *closestMember = this->closestMember(this->leader);
                        this->leader = closestMember;
                }
                //// Find a new leader if the current one is dead
                else{
                         Character *newLeader = nullptr;
                        double minDistance = INT_MAX;
                        for (std::vector<Character*>::size_type i=0; i<this->teamMembers.size(); i++)
                        {
                        double dist = this->teamMembers[i]->distance(leader);
                        if (this->teamMembers[i]->isAlive() && dist < minDistance)
                        {
                        newLeader = this->teamMembers[i];
                        minDistance = dist;
                        }
                        }

                        leader = newLeader;
                        }
        
                Character *chosenVictom = enemy->chooseVictom(this->leader);
                for(std::vector<Character*>::size_type i=0; i<this->teamMembers.size(); i++)
                {
                        Cowboy *cowboy = dynamic_cast<Cowboy *>(this->teamMembers[i]);
                        if(cowboy != nullptr)
                        {
                                if(!cowboy->hasboolets())
                                {
                                        cowboy->reload();
                                }
                                else
                                {
                                        cowboy->shoot(chosenVictom);
                                }
                        }
                        else
                        {
                                Ninja *ninja = dynamic_cast<Ninja *>(this->teamMembers[i]);
                                if(ninja->distance(chosenVictom) <= 1)
                                {
                                        ninja->slash(chosenVictom);
                                }
                                else
                                {
                                        ninja->move(chosenVictom);
                                }
                        }
                        if(!chosenVictom->isAlive())
                        {
                                chosenVictom = enemy->chooseVictom(this->leader);
                        }
                        if(!enemy->stillAlive())
                        {
                                return;
                        }
                }
        }
       
        int Team::stillAlive()
        {
                int countAlive = 0;
                for(std::vector<Character*>::size_type  i = 0; i < this->teamMembers.size(); i++)
                {
                        if(this->teamMembers[i]->isAlive())
                        {
                                countAlive++;
                        }
                }
                return countAlive;
        }
       
        string Team::print()
        {
                string teamDetails = "";
                for(std::vector<Character*>::size_type  i = 0; i < this->teamMembers.size(); i++)
                {
                        teamDetails += this->teamMembers[i]->print();
                }
                return teamDetails;
        }

        Character* Team::closestMember(Character *leader)
        {
                int minDist = INT_MAX;
                Character *choosenMem;
                for(std::vector<Character*>::size_type i=0; i<this->teamMembers.size(); i++)
                {
                        if((this->teamMembers[i] != leader) && (this->teamMembers[i]->isAlive()) && (this->teamMembers[i]->distance(leader) < minDist))
                        {
                                minDist = this->teamMembers[i]->distance(leader);
                                choosenMem = this->teamMembers[i];
                        }
                }
                return choosenMem;
        }

        Character* Team::chooseVictom(Character *leader)
        {
                int minDist = INT_MAX;
                Character *choosenMem;
                for(std::vector<Character*>::size_type i=0; i<this->teamMembers.size(); i++)
                {
                        if((this->teamMembers[i]->isAlive()) && (this->teamMembers[i]->distance(leader) < minDist))
                        {
                                minDist = this->teamMembers[i]->distance(leader);
                                choosenMem = this->teamMembers[i];
                        }
                }
                return choosenMem;
        }

        Team::~Team()
        {
                for(std::vector<Character*>::size_type i = 0; i< this->teamMembers.size(); i++)
                {
                        delete this->teamMembers[i];
                }
                this->teamMembers.clear();
        }
}
