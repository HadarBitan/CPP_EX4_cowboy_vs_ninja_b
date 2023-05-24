#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP

#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "Ninja.hpp"

constexpr int hitPointTrained = 120;
constexpr int SpeedTrained = 12;

namespace ariel
{
    class TrainedNinja : public Ninja
    {
        public:
            TrainedNinja(string name, Point location): Ninja(location, hitPointTrained, std::move(name), SpeedTrained){}
    };
}

#endif