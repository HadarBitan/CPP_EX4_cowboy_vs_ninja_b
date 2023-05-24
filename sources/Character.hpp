#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#pragma once

#include <iostream>
#include <string>
#include "Point.hpp"

using namespace std;

namespace ariel
{
    class Character
    {
        public:
            Point location;
            int hitPoint;
            string name;
            bool isInTeam;
            Character(const Character& other); 
            Character& operator=(const Character& other);
            Character& operator=(Character&& other) noexcept;
            Character(Character&& other) noexcept;
            Character(Point location, int hitPoint, string name);
            bool isAlive();
            double distance(Character *other) const;
            void hit(int numOfPoints);
            string getName();
            Point getLocation();
            void assignTeam(){this->isInTeam = true;}
            bool hasTeam() const {return this->isInTeam;}
            virtual string print() = 0;
            int getHitPoint();
            virtual ~Character() = default;
    };
}

#endif