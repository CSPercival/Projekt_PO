#include "Point2D.h"

template <typename T> 
Point2D<T>::Point2D(){
    this->x = 0;
    this->y = 0;
}

template <typename T>
Point2D<T>::Point2D(T x, T y){
    this->x = x;
    this->y = y;
}

template <typename T>
bool Point2D<T>::operator==(const Point2D<T>&  p2d){
    if(this->x == p2d.x && this->y == p2d.y) return true;
    return false;
}

template <typename T>
bool Point2D<T>::operator<=(const Point2D<T>&  p2d){
    if(this->x != p2d.x) return this->x < p2d.x;
    return this->y <= p2d.y;
}

template <typename T>
bool Point2D<T>::operator<(const Point2D<T>&  p2d){
    if(this->x != p2d.x) return this->x < p2d.x;
    return this->y < p2d.y;
}

template <typename T>
bool Point2D<T>::operator>=(const Point2D<T>&  p2d){
    if(this->x != p2d.x) return this->x > p2d.x;
    return this->y >= p2d.y;
}

template <typename T>
bool Point2D<T>::operator>(const Point2D<T>&  p2d){
    if(this->x != p2d.x) return this->x > p2d.x;
    return this->y > p2d.y;
}

template <typename T>
Point2D<T> Point2D<T>::operator+(const Point2D<T>&  p2d){
    Point2D<T> res_p2d(this->x + p2d.x, this->y + p2d.y);
    return res_p2d;
}

template <typename T>
Point2D<T> Point2D<T>::operator-(const Point2D<T>&  p2d){
    Point2D<T> res_p2d(this->x - p2d.x, this->y - p2d.y);
    return res_p2d;
}

template <typename T>
T Point2D<T>::norm(){
    return (this->x*this->x + this->y*this->y);
}

template <typename T>
long double Point2D<T>::length(){
    return pow(this->norm(),0.5);
}

template <typename T>
long double Point2D<T>::distance(Point2D<T> p2d){
    long double dist_x = this->x - p2d.x;
    long double dist_y = this->y - p2d.y;
    return pow((dist_x*dist_x + dist_y*dist_y),0.5);
}

template <typename T>
T Point2D<T>::unrooted_distance(Point2D<T> p2d){
    T dist_x = this->x - p2d.x;
    T dist_y = this->y - p2d.y;
    return (dist_x*dist_x + dist_y*dist_y);
}

template <typename T>
long double Point2D<T>::dot_product(Point2D<T> p2d){
    return this->x*p2d.x + this->y*p2d.y;
}

template <typename T>
T Point2D<T>::signed_area_parallelogram(Point2D<T> p2d1, Point2D<T> p2d2){
    return (p2d1.x - this->x) * (p2d2.y - p2d1.y) - (p2d2.x - p2d1.x) * (p2d1.y - this->y);
}

template <typename T>
long double Point2D<T>::triangle_area(Point2D<T> p2d1, Point2D<T> p2d2){
    return my_abs(this->signed_area_parallelogram(p2d1,p2d2)) / 2.0;
}

template <typename T>
bool Point2D<T>::clockwise_area(Point2D<T> p2d1, Point2D<T> p2d2){
    return this->signed_area_parallelogram(p2d1,p2d2) < 0;
}

template <typename T>
long double Point2D<T>::angle(){
    Point2D<T> x(1,0);
    return this->angle(x);
}

template <typename T>
long double Point2D<T>::angle(Point2D<T> p2d){
    assert(my_abs(this->length() * p2d.length()) > EPSILON);
    return acos(this->dot_product(p2d) / (this->length() * p2d.length())) * 180.0 / M_PI;
}

template <typename T>
long double Point2D<T>::angle(Point2D<T> p2d1, Point2D<T> p2d2){
    p2d1 = p2d1 - (*this);
    p2d2 = p2d2 - (*this);
    return p2d1.angle(p2d2);
}


template class Point2D<char>;
template class Point2D<unsigned char>;
template class Point2D<short>;
template class Point2D<unsigned short>;
template class Point2D<int>;
template class Point2D<unsigned int>;
template class Point2D<long>;
template class Point2D<unsigned long>;
template class Point2D<long long>;
template class Point2D<unsigned long long>;

template class Point2D<float>;
template class Point2D<double>;
template class Point2D<long double>;