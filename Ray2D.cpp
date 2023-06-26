#include "Ray2D.h"

template <typename T> 
Ray2D<T>::Ray2D(Point2D<T> p2d1) : Line2D<T>(0,1,p2d1.y*-1){
    this->point_a = p2d1;
    side = 1;
}


template <typename T> 
Ray2D<T>::Ray2D(Point2D<T> p2d1, Point2D<T> p2d2) : Line2D<T>(p2d1,p2d2){
    assert(!(p2d1 == p2d2));
    this->point_a = p2d1;
    if(p2d1.x != p2d2.x){
        side = p2d1.x < p2d2.x;
    } else {
        side = p2d1.y < p2d2.y;
    }
}

template <typename T> 
Ray2D<T>::Ray2D(Line2D<T> l2d1, Point2D<T> p2d1, bool side){
    this->A = l2d1.A;
    this->B = l2d1.B;
    this->C = l2d1.C;
    this->point_a = p2d1;
    this->side = side;
}

template <typename T>
bool Ray2D<T>::inside(Point2D<T> p2d){
    if(p2d == this->point_a) return true;
    if(Line2D<T>::inside(p2d)){
        if(this->point_a.x == p2d.x){
            if(this->point_a.y < p2d.y){
                if(this->side) return true;
                else return false;
            } else {
                if(this->side) return false;
                else return true;
            }
        } else {
            if(this->point_a.x < p2d.x){
                if(this->side) return true;
                else return false;
            } else {
                if(this->side) return false;
                else return true;
            }
        }
    }
    return false;
}


template class Ray2D<char>;
template class Ray2D<unsigned char>;
template class Ray2D<short>;
template class Ray2D<unsigned short>;
template class Ray2D<int>;
template class Ray2D<unsigned int>;
template class Ray2D<long>;
template class Ray2D<unsigned long>;
template class Ray2D<long long>;
template class Ray2D<unsigned long long>;

template class Ray2D<float>;
template class Ray2D<double>;
template class Ray2D<long double>;