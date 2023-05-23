#ifndef TEAM2_HPP
#define TEAM2_HPP

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Point.hpp"
#include "Character.hpp"
#include "Team.hpp"

namespace ariel
{
    class Team2 : public Team
    {
        public:
            Team2(const Team2& other) : Team(other){} 
            Team2& operator=(const Team2& other);
            Team2& operator=(Team2&& other);
            Team2(Team2&& other) : Team(std::move(other)){}
            Team2(Character *leader);
            void add(Character *teamMember) override;
            ~Team2() override;
    };
}

#endif