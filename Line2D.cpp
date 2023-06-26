#include "Line2D.h"

template <typename T> 
Line2D<T>::Line2D(){
    this->A = 0;
    this->B = 1;
    this->C = 0;
    assert((this->A != 0 || this->B != 0));
    this->normalize();
}

template <typename T> 
Line2D<T>::Line2D(T a, T b){
    this->A = a;
    this->B = -1;
    this->C = b;
    assert((this->A != 0 || this->B != 0));
    this->normalize();
}

template <typename T> 
Line2D<T>::Line2D(T a, T b, T c){
    this->A = a;
    this->B = b;
    this->C = c;
    assert((this->A != 0 || this->B != 0));
    this->normalize();
}

template <typename T> 
Line2D<T>::Line2D(Point2D<T> p2d1, Point2D<T> p2d2){
    this->A = p2d1.y - p2d2.y;
    this->B = p2d2.x - p2d1.x;
    this->C = p2d1.y * (p2d1.x-p2d2.x) + p2d1.x * (p2d2.y-p2d1.y);
    assert((this->A != 0 || this->B != 0));
    this->normalize();
}

template <typename T> 
void Line2D<T>::normalize(){
    if(!if_int<T>()){
        long double Z = sqrt(this->A*this->A + this->B*this->B);
        if(Z == 0) return;

        this->A /= Z;
        this->B /= Z;
        this->C /= Z;
    } else{
        long long Z = __gcd(__gcd((long long)A,(long long)B),(long long)C);
        if(Z == 0) return;

        this->A /= Z;
        this->B /= Z;
        this->C /= Z;    
    }
    return;
}

template <typename T> 
bool Line2D<T>::parallel(Line2D<T> l2d){
    return my_abs(this->A * l2d.B - this->B * l2d.A) <= EPSILON;
}

template <typename T> 
bool Line2D<T>::inside(Point2D<T> p2d){
    return my_abs(this->A * p2d.x + this->B * p2d.y + this->C) <= EPSILON;
}

template <typename T> 
bool Line2D<T>::intersect(Line2D<T> &l2d){
    if(this->parallel(l2d)) return false;
    Point2D<T> intersection_point = this->intersection(l2d);
    return (this->inside(intersection_point) && l2d.inside(intersection_point));
}

template <typename T> 
Point2D<T> Line2D<T>::intersection(Line2D<T> l2d){
    assert(!(this->parallel(l2d)));
    T zt = this->A * l2d.B - this->B * l2d.A;
    T xt = -1 * (this->C * l2d.B - this->B * l2d.C);
    T yt = -1 * (this->A * l2d.C - this->C * l2d.A);
    Point2D<T> res(xt/zt,yt/zt);
    return res;
}

template <typename T> 
long double Line2D<T>::angle(){
    Line2D<T> OX;
    return this->angle(OX);
}

template <typename T> 
long double Line2D<T>::angle(Line2D<T> l2d){
    //assert((this->A * this->B + l2d.A * l2d.B) != 0);
    if((this->A * this->B + l2d.A * l2d.B) == 0) return 90.0;
    return atan((long double)(this->A * l2d.B - this->B * l2d.A) / (this->A * l2d.A + this->B * l2d.B)) * 180.0 / M_PI;
}



template class Line2D<char>;
template class Line2D<unsigned char>;
template class Line2D<short>;
template class Line2D<unsigned short>;
template class Line2D<int>;
template class Line2D<unsigned int>;
template class Line2D<long>;
template class Line2D<unsigned long>;
template class Line2D<long long>;
template class Line2D<unsigned long long>;

template class Line2D<float>;
template class Line2D<double>;
template class Line2D<long double>;