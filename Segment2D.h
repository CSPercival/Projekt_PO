#ifndef GEOMETRY_SEGMENT_2D_H
#define GEOMETRY_SEGMENT_2D_H

#include "Libraries_And_Macros.h"
#include "Point.h"
#include "Point2D.h"
#include "Line2D.h"

template <typename T>
class Segment2D : public Line2D<T>{
    public:

        Point2D<T> point_a;
        Point2D<T> point_b;
        Segment2D(Point2D<T>,Point2D<T>);

        long double length();
        virtual bool inside(Point2D<T>);
};

#endif