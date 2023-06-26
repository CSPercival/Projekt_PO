#ifndef GEOMETRY_POINT_3D_H
#define GEOMETRY_POINT_3D_H

#include "Libraries_And_Macros.h"
#include "Point.h"

template <typename T>
class Point3D : private Point<Point3D<T>>{
    private:
        
    protected:

    public:
        T x, y, z;
        Point3D();
        Point3D(T,T,T);

        bool operator==(const Point3D<T>&);
        bool operator<=(const Point3D<T>&);
        bool operator<(const Point3D<T>&);
        bool operator>=(const Point3D<T>&);
        bool operator>(const Point3D<T>&);

        Point3D<T> operator+(const Point3D<T>&);
        Point3D<T> operator-(const Point3D<T>&);

        T norm();
        long double length();
        long double distance(Point3D<T>);
        T unrooted_distance(Point3D<T>);
        long double dot_product(Point3D<T>);
        
};

#endif