#ifndef GEOMETRY_POLYGON_2D_H
#define GEOMETRY_POLYGON_2D_H

#include "Libraries_And_Macros.h"
#include "Point.h"
#include "Point2D.h"
#include "Line2D.h"
#include "Segment2D.h"
#include "Ray2D.h"

template <typename T>
class Polygon2D{
    public:
        vector<Point2D<T>> points;

        Polygon2D();
        Polygon2D(vector<Point2D<T>>);

        void add_point(Point2D<T>);
        void add_point(Point2D<T>, int);
        void erase_point();
        void erase_point(Point2D<T>);
        void erase_point(int);
        
        long double area();
        bool inside(Point2D<T>);
};

#endif

