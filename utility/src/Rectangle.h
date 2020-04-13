//********************************************************//
//                                                        //
//   File    :   Rectangle.h                              //
//   Author  :   eezyl                                    //
//   Synopsis:   data structure: Rectangle                //
//   Date    :   2019/04/14                               //
//                                                        //
//********************************************************//

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <algorithm>

/*
             (rx, ry)
    .-----------.
    |           |
    |           |    
    |           |
    .-----------.
 (lx, ly)
 
*/
struct Rectangle{
    Rectangle (double a = -1, double b = -1, double c = -1, double d = -1)
        : lx(a), ly(b), rx(c), ry(d)
    {}
    double lx, ly, rx, ry;
    double area() { return (rx-lx) * (ry-ly); }
};

// Given two rectangles, return the overlap area
double overlapArea(Rectangle& r1, Rectangle& r2)
{
    double lx = std::max(r1.lx, r2.lx);
    double rx = std::min(r1.rx, r2.rx);
    double ly = std::max(r1.ly, r2.ly);
    double ry = std::min(r1.ry, r2.ry);
    
    double s1 = std::max(0.0, rx-lx);
    double s2 = std::max(0.0, ry-ly);
    
    return s1 * s2;
}

// Given two rectangles, return true if they are intersected
bool isIntersected(Rectangle& r1, Rectangle& r2)
{
    return !(r1.rx < r2.lx || r1.lx > r2.rx || 
             r1.ry < r2.ly || r1.ly > r2.ry)
        && !(r1.lx > r2.lx && r1.rx < r2.rx &&
             r1.ly > r2.ly && r1.ry < r2.ry)
        && !(r1.lx < r2.lx && r1.rx > r2.rx &&
             r1.ly < r2.ly && r1.ry > r2.ry);
}

#endif