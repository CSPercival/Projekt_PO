#ifndef GEOMETRY_SET_2D_H
#define GEOMETRY_SET_2D_H

#include "Libraries_And_Macros.h"
#include "Point.h"
#include "Point2D.h"
#include "Line2D.h"
#include "Segment2D.h"
#include "Ray2D.h"
#include "Polygon2D.h"

template <typename T>
class Set_Point2D{
    public:
        vector<Point2D<T>> points;

        Set_Point2D();
        Set_Point2D(vector<Point2D<T>>);

        void add_point(Point2D<T>);
        void add_point(Point2D<T>, int);
        void erase_point();
        void erase_point(Point2D<T>);
        void erase_point(int);

        void lex_sort();
        void angle_sort();
        void angle_sort(Point2D<T>);
        
        Polygon2D<T> convex_hull();
};

#endif

