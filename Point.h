#ifndef GEOMETRY_POINT_H
#define GEOMETRY_POINT_H

#include "Libraries_And_Macros.h"

template <class X>
class Point{
    virtual bool operator==(const X&) = 0;
    virtual bool operator<=(const X&) = 0;
    virtual bool operator<(const X&) = 0;
    virtual bool operator>=(const X&) = 0;
    virtual bool operator>(const X&) = 0;

    virtual X operator+(const X&) = 0;
    virtual X operator-(const X&) = 0;

    virtual long double distance(X) = 0;
    virtual long double length() = 0;
    virtual long double dot_product(X) = 0;
};

#endif