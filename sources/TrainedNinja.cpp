#include "TrainedNinja.hpp"

namespace ariel
{
  // Copy constructor
    TrainedNinja::TrainedNinja(const TrainedNinja& other) : Ninja(other) {}

    // Copy assignment operator
    TrainedNinja& TrainedNinja::operator=(const TrainedNinja& other) 
    {
        if (this != &other) {
            Ninja::operator=(other);  // Call base class's copy assignment operator
        }
        return *this;
    }

    // Move assignment operator
    TrainedNinja& TrainedNinja::operator=(TrainedNinja&& other) 
    {
        if (this != &other) {
            Ninja::operator=(std::move(other));  // Call base class's move assignment operator
        }
        return *this;
    }

    // Move constructor
    TrainedNinja::TrainedNinja(TrainedNinja&& other) : Ninja(std::move(other)) {}
  
} 
