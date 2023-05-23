#ifndef COWBOY_HPP
#define COWBOY_HPP

#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "Point.hpp"
#include "Character.hpp"

constexpr int hitPointCowboy = 110;
constexpr int bullets = 6;

namespace ariel
{
    class Cowboy : public Character
    {
        private:
            int numOfBullets;
        public:
            Cowboy(string name, Point location): Character(location, 110, std::move(name)), numOfBullets(bullets){}
            Cowboy(const Cowboy& other) : Character(other), numOfBullets(other.numOfBullets){}
            Cowboy& operator=(const Cowboy& other);
            Cowboy& operator=(Cowboy&& other);
            Cowboy(Cowboy&& other) : Character(std::move(other)), numOfBullets(std::move(other.numOfBullets)){}
            void shoot(Character *enemy);
            bool hasboolets();
            void reload();
            int getNumOfBoolets();
            string print() override;
            ~Cowboy() override {}
    };
}

#endif