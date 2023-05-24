#include <iostream>
#include <string>
#include <stdexcept>
#include "Point.hpp"
#include "Cowboy.hpp"


namespace ariel
{
    // Copy assignment operator
    Cowboy& Cowboy::operator=(const Cowboy& other) {
        if (this != &other) {
            Character::operator=(other);    // Call base class's copy assignment operator
            numOfBullets = other.numOfBullets; // Copy Cowboy-specific member
        }
        return *this;
    }

    // Move assignment operator
    Cowboy& Cowboy::operator=(Cowboy&& other) noexcept {
        if (this != &other) {
            Character::operator=(std::move(other));  // Call base class's move assignment operator
            numOfBullets = std::move(other.numOfBullets); // Move Cowboy-specific member
        }
        return *this;
    }
    
    void Cowboy::shoot(Character *enemy)
    {
        if(enemy == this)
        {
            throw std::runtime_error("");
        }
        if(this->isAlive() && enemy->isAlive())
        {
            if(this->hasboolets())
            {
                this->numOfBullets -= 1;
                enemy->hit(10);
            }
        }
        else
        {
            throw std::runtime_error("");
        }
    }
    
    bool Cowboy::hasboolets(){return this->numOfBullets > 0;}
    
    void Cowboy::reload()
    {
        if(!this->isAlive())
        {
            throw std::runtime_error("");
        }
        this->numOfBullets = 6;
    }
    
    int Cowboy::getNumOfBoolets(){return this->numOfBullets;}
    
    string Cowboy::print()
    {
        if(this->isAlive())
            return "C: " + this->name + ", " + std::to_string(this->hitPoint) + ", location: " + this->location.print();
        else
            return "C: (" + this->name + "), location: " + this->location.print();
    }
}