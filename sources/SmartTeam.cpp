#include <iostream>
#include "SmartTeam.hpp"
#include <string>
#include <vector>
#include "Character.hpp"


namespace ariel
{
        SmartTeam::SmartTeam(Character *leader) : Team(leader), size(0) {}
       
        void SmartTeam::add(Character *teamMember)
        {
                if(this->size == 10)
                {
                        for(std::vector<Character*>::size_type i = 0; i < this->youngninjas.size(); i++)
                        {
                                this->teamMembers.push_back(this->youngninjas[i]);
                        }
                        for(std::vector<Character*>::size_type i = 0; i < this->trainedninjas.size(); i++)
                        {
                                this->teamMembers.push_back(this->trainedninjas[i]);
                        }
                        for(std::vector<Character*>::size_type i = 0; i < this->oldninjas.size(); i++)
                        {
                                this->teamMembers.push_back(this->oldninjas[i]);
                        }
                        for(std::vector<Character*>::size_type i = 0; i < this->cowboys.size(); i++)
                        {
                                this->teamMembers.push_back(this->cowboys[i]);
                        }
                }

                if(typeid(teamMember) == typeid(Cowboy))
                {
                        this->cowboys.push_back(teamMember);
                }
                if(typeid(teamMember) == typeid(TrainedNinja))
                {
                        this->trainedninjas.push_back(teamMember);
                }
                if(typeid(teamMember) == typeid(OldNinja))
                {
                        this->oldninjas.push_back(teamMember);
                }
                if(typeid(teamMember) == typeid(YoungNinja))
                {
                        this->youngninjas.push_back(teamMember);
                }
        }
       
        SmartTeam::~SmartTeam()
        {
                this->trainedninjas.clear();
                this->youngninjas.clear();
                this->oldninjas.clear();
                this->cowboys.clear();
        }
}
