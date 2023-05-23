#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP

#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "Ninja.hpp"

// constexpr int hitPointYoung = 100;
constexpr int SpeedYoung = 14;

namespace ariel
{
    class YoungNinja : public Ninja
    {
        public:
            YoungNinja(string name, Point location): Ninja(location, 100, std::move(name), SpeedYoung){}
            YoungNinja(const YoungNinja& other); 
            YoungNinja& operator=(const YoungNinja& other);
            YoungNinja& operator=(YoungNinja&& other);
            YoungNinja(YoungNinja&& otehr);
            ~YoungNinja() override {}
    };
}

#endif