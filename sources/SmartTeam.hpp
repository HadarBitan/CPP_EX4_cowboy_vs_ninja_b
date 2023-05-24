#pragma once

#include "Team.hpp"

namespace ariel
{
    class SmartTeam: public Team
    {
        public:
            SmartTeam(Character *leader);
            void attack(Team *enemy) override;
            void print() const override;
    };
}