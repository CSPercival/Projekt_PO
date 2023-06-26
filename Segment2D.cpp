#include "Segment2D.h"

template <typename T> 
Segment2D<T>::Segment2D(Point2D<T> p2d1, Point2D<T> p2d2) : Line2D<T>(p2d1,p2d2){
    point_a = p2d1;
    point_b = p2d2;
}

template <typename T>
long double Segment2D<T>::length(){
    return point_a.distance(point_b);
}

template <typename T>
bool Segment2D<T>::inside(Point2D<T> p2d){
    if(Line2D<T>::inside(p2d)){
        if(min(point_a.x,point_b.x) <= p2d.x && p2d.x <= max(point_a.x,point_b.x) &&
            min(point_a.y,point_b.y) <= p2d.y && p2d.y <= max(point_a.y,point_b.y)) return true;
    }
    return false;
}


template class Segment2D<char>;
template class Segment2D<unsigned char>;
template class Segment2D<short>;
template class Segment2D<unsigned short>;
template class Segment2D<int>;
template class Segment2D<unsigned int>;
template class Segment2D<long>;
template class Segment2D<unsigned long>;
template class Segment2D<long long>;
template class Segment2D<unsigned long long>;

template class Segment2D<float>;
template class Segment2D<double>;
template class Segment2D<long double>;