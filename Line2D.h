#ifndef GEOMETRY_LINE_2D_H
#define GEOMETRY_LINE_2D_H

#include "Libraries_And_Macros.h"
#include "Point.h"
#include "Point2D.h"

template <typename T>
class Line2D{
    protected:
        void normalize();
    public:
        T A,B,C;

        Line2D();
        Line2D(T,T);
        Line2D(T,T,T);
        Line2D(Point2D<T>, Point2D<T>);

        bool parallel(Line2D<T>);
        virtual bool inside(Point2D<T>);
        bool intersect(Line2D<T>&);
        Point2D<T> intersection(Line2D<T>);
        long double angle();
        long double angle(Line2D<T>);
};

#endif