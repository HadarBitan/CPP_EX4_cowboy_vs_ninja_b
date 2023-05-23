#ifndef NINJA_HPP
#define NINJA_HPP

#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "Point.hpp"
#include "Character.hpp"


namespace ariel
{
    class Ninja : public Character
    {
        public:
            int speed;
            Ninja(Point location, int hitPoint, string name, int speed): Character(location, hitPoint, std::move(name)), speed(speed){}
            // Copy constructor
            Ninja(const Ninja& other) : Character(other), speed(other.speed){} 
            Ninja& operator=(const Ninja& other);
            Ninja& operator=(Ninja&& other);
            // Move constructor
            Ninja(Ninja&& other) : Character(std::move(other)), speed(std::move(other.speed)){}
            void move(Character *enemy);
            void slash(Character *enemy);
            int getSpeed();
            string print() override;
            ~Ninja() override {}
    };
}

#endif