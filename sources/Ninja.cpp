#include <iostream>
#include <string>
#include <stdexcept>
#include "Point.hpp"
#include "Ninja.hpp"

namespace ariel
{
    // Copy assignment operator
    Ninja& Ninja::operator=(const Ninja& other) 
    {
        if (this != &other) {
            Character::operator=(other);  // Call base class's copy assignment operator
            speed = other.speed;          // Copy Ninja-specific member
        }
        return *this;
    }   

    // Move assignment operator
    Ninja& Ninja::operator=(Ninja&& other) 
    {
        if (this != &other) {
            Character::operator=(std::move(other));  // Call base class's move assignment operator
            speed = std::move(other.speed);          // Move Ninja-specific member
        }
        return *this;
    }

    void Ninja::move(Character *enemy)
    {
        if (enemy == nullptr)
            throw invalid_argument("Other character is null!");

        else if (enemy == this)
            throw invalid_argument("Cannot move to yourself!");

        else if (!isAlive())
            throw runtime_error("Cannot move while dead!");
    
        this->location = Point::moveTowards(this->location, enemy->getLocation(), this->speed);
    }
    
    void Ninja::slash(Character *enemy)
    {
        if(enemy == this)
        {
            throw std::runtime_error("");
        }
        if(this->isAlive() && enemy->isAlive())
        {
            if(this->location.distance(enemy->getLocation()) <= 1)
            {
                enemy->hit(40);
            }
        }
        else
        {
            throw std::runtime_error("");
        }
    }
    
    int Ninja::getSpeed(){return this->speed;}
    
    string Ninja::print()
    {
        if(this->isAlive())
            return "N: " + this->name + ", " + std::to_string(this->hitPoint) + ", location: " + this->location.print();
        else
            return "N: (" + this->name + "), location: " + this->location.print();
    }
}