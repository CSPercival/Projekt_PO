#ifndef GEOMETRY_RAY_2D_H
#define GEOMETRY_RAY_2D_H

#include "Libraries_And_Macros.h"
#include "Point.h"
#include "Point2D.h"
#include "Line2D.h"

template <typename T>
class Ray2D : public Line2D<T>{
    public:

        Point2D<T> point_a;
        bool side;         // 1 - x rosnie lub x w miejscu i y rosnie   0 - x maleje lub x w miejscu i y maleje
        Ray2D(Point2D<T>);
        Ray2D(Point2D<T>,Point2D<T>);
        Ray2D(Line2D<T>,Point2D<T>, bool);

        virtual bool inside(Point2D<T>);
};

#endif