#ifndef POINT_HPP
#define POINT_HPP

#pragma once

#include <iostream>
#include <string>

using namespace std;

namespace ariel
{
    class Point
    {
        private:
            double x;
            double y;
        public:
            Point(double x_value, double y_value): x(x_value), y(y_value){}
            double distance(Point other) const;
            string print();
            static Point moveTowards(Point source, Point dest, double dist);
    };
}

#endif