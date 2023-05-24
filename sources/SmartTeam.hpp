#pragma once

#include "Team.hpp"

namespace ariel
{
    class SmartTeam: public Team
    {
         //in Smart Team the method is to go over the ninjas first because the hit the most points
        //in the ninjas we go over the fastes ninjas first in case the ninja is far from the target
        public:
            SmartTeam(Character *leader);
            void attack(Team *enemy) override;
            void print() const override;
    };
}
