#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Point.hpp"
#include "Character.hpp"
#include "Team.hpp"

namespace ariel
{
    class SmartTeam : public Team
    {
        private:
            vector<Character*> cowboys;
            vector<Character*> trainedninjas;
            vector<Character*> youngninjas;
            vector<Character*> oldninjas;
            int size;
        public:
            SmartTeam(const SmartTeam&); 
            SmartTeam& operator=(const SmartTeam&);
            SmartTeam& operator=(SmartTeam&&);
            SmartTeam(SmartTeam&&);
            SmartTeam(Character *leader);
            void add(Character *teamMember);
            ~SmartTeam();
    };
}

#endif