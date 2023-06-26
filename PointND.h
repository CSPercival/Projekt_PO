#ifndef GEOMETRY_POINT_ND_H
#define GEOMETRY_POINT_ND_H

#include "Libraries_And_Macros.h"
#include "Point.h"

template <typename T>
class PointND : private Point<PointND<T>>{
    private:
        
    protected:

    public:
        vector<T> coords;
        PointND();
        PointND(vector<T>);

        bool operator==(const PointND<T>&);
        bool operator<=(const PointND<T>&);
        bool operator<(const PointND<T>&);
        bool operator>=(const PointND<T>&);
        bool operator>(const PointND<T>&);

        PointND<T> operator+(const PointND<T>&);
        PointND<T> operator-(const PointND<T>&);

        T norm();
        long double length();
        long double distance(PointND<T>);
        T unrooted_distance(PointND<T>);
        long double dot_product(PointND<T>);
        
};

#endif