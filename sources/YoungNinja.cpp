#include "YoungNinja.hpp"

namespace ariel
{
    // Copy constructor
    YoungNinja::YoungNinja(const YoungNinja& other) : Ninja(other) {}

    // Copy assignment operator
    YoungNinja& YoungNinja::operator=(const YoungNinja& other) 
    {
        if (this != &other) {
            Ninja::operator=(other);  // Call base class's copy assignment operator
        }
        return *this;
    }

    // Move assignment operator
    YoungNinja& YoungNinja::operator=(YoungNinja&& other) 
    {
        if (this != &other) {
            Ninja::operator=(std::move(other));  // Call base class's move assignment operator
        }
        return *this;
    }

    // Move constructor
    YoungNinja::YoungNinja(YoungNinja&& other) : Ninja(std::move(other)) {}
        
}