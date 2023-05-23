#include "OldNinja.hpp"

namespace ariel
{
    // Copy constructor
    OldNinja::OldNinja(const OldNinja& other) : Ninja(other) {}

    // Copy assignment operator
    OldNinja& OldNinja::operator=(const OldNinja& other) 
    {
        if (this != &other) {
            Ninja::operator=(other);  // Call base class's copy assignment operator
        }
        return *this;
    }

    // Move assignment operator
    OldNinja& OldNinja::operator=(OldNinja&& other) 
    {
        if (this != &other) {
            Ninja::operator=(std::move(other));  // Call base class's move assignment operator
        }
        return *this;
    }

    // Move constructor
    OldNinja::OldNinja(OldNinja&& other) : Ninja(std::move(other)) {}

}