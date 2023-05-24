#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP

#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "Ninja.hpp"

constexpr int hitPointYoung = 100;
constexpr int SpeedYoung = 14;

namespace ariel
{
    class YoungNinja : public Ninja
    {
        public:
            YoungNinja(string name, Point location): Ninja(location, hitPointYoung, std::move(name), SpeedYoung){}
    };
}

#endif