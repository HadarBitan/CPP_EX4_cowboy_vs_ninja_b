#include <iostream>
#include <string>
#include "Point.hpp"
#include "Character.hpp"

using namespace std;

namespace ariel
{
        Character::Character(Point location, int hitPoint, string name):location(location), hitPoint(hitPoint), name(name), isInTeam(false) {}
        
        // Copy constructor
        Character::Character(const Character& other) 
                : location(other.location), 
                hitPoint(other.hitPoint),
                name(other.name),
                isInTeam(other.isInTeam) {}

        // Copy assignment operator
        Character& Character::operator=(const Character& other) 
        {
                if (this != &other) 
                {
                        location = other.location;      // Copy member variables
                        hitPoint = other.hitPoint;
                        name = other.name;
                        isInTeam = other.isInTeam;
                }
                return *this;
        }

        // Move assignment operator
        Character& Character::operator=(Character&& other) noexcept
        {
                if (this != &other) 
                {
                        location = std::move(other.location);  // Move member variables
                        hitPoint = std::move(other.hitPoint);
                        name = std::move(other.name);
                        isInTeam = std::move(other.isInTeam);
                }
                return *this;
        }

        // Move constructor
        Character::Character(Character&& other) noexcept
                : location(std::move(other.location)),
                hitPoint(std::move(other.hitPoint)),
                name(std::move(other.name)),
                isInTeam(std::move(other.isInTeam)) {}

        bool Character::isAlive()
        {
                return this->hitPoint > 0;
        }
        
        double Character::distance(Character *other) const
        {
                return this->location.distance(other->location);
        }
        
        void Character::hit(int numOfPoints)
        {
                if(numOfPoints < 0)
                {
                        throw std::invalid_argument("");
                }
                this->hitPoint -= numOfPoints;
        }
        
        string Character::getName(){return this->name;}
        
        Point Character::getLocation(){return this->location;}
        
        int Character::getHitPoint(){return this->hitPoint;}
}