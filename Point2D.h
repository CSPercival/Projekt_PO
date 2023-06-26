#ifndef GEOMETRY_POINT_2D_H
#define GEOMETRY_POINT_2D_H

#include "Libraries_And_Macros.h"
#include "Point.h"

template <typename T>
class Point2D : private Point<Point2D<T>>{
    private:
        
    protected:

    public:
        T x, y;
        Point2D();
        Point2D(T,T);

        bool operator==(const Point2D<T>&);
        bool operator<=(const Point2D<T>&);
        bool operator<(const Point2D<T>&);
        bool operator>=(const Point2D<T>&);
        bool operator>(const Point2D<T>&);

        Point2D<T> operator+(const Point2D<T>&);
        Point2D<T> operator-(const Point2D<T>&);

        T norm();
        long double length();
        long double distance(Point2D<T>);
        T unrooted_distance(Point2D<T>);
        long double dot_product(Point2D<T>);
        
        T signed_area_parallelogram(Point2D<T>,Point2D<T>);
        long double triangle_area(Point2D<T>,Point2D<T>);
        bool clockwise_area(Point2D<T>,Point2D<T>);
        long double angle();
        long double angle(Point2D<T>);
        long double angle(Point2D<T>,Point2D<T>);
};

#endif