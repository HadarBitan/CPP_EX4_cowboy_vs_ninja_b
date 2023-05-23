#include <iostream>
#include <string>
#include <math.h>
#include <stdexcept>
#include "Point.hpp"

using namespace std;

namespace ariel
{
    double Point::distance(Point p) const
    {
        double deltaX = this->x - p.x;
        double deltaY = this->y - p.y;
        return sqrt((deltaX * deltaX) + (deltaY * deltaY));    
    }
    
    string Point::print()
    {
        return "(" + std::to_string(this->x) + "," + std::to_string(this->y) + ")";
    }

    Point Point::moveTowards(Point source, Point dest, double dist)
    {
        if(dist < 0)
        {
            throw std::invalid_argument("");
        }
        double distance = source.distance(dest);

        if (distance <= dist) 
        {
            return dest; // we can reach the destination source in last then dist 
        } 
        else 
        {
            //look for the closest point in at least dist from source to dest
            double deltaX = dest.x-source.x ;
            double deltaY = dest.y-source.y ;
            double ratio = dist / distance;
            double newX = source.x + ratio * deltaX;
            double newY = source.y + ratio * deltaY;
            return Point(newX, newY);
        }
    }
}
