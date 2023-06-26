#include "Point3D.h"

template <typename T> 
Point3D<T>::Point3D(){
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

template <typename T>
Point3D<T>::Point3D(T x, T y, T z){
    this->x = x;
    this->y = y;
    this->z = z;
}

template <typename T>
bool Point3D<T>::operator==(const Point3D<T>&  p3d){
    if(this->x == p3d.x && this->y == p3d.y && this->z == p3d.z) return true;
    return false;
}

template <typename T>
bool Point3D<T>::operator<=(const Point3D<T>&  p3d){
    if(this->x != p3d.x) return this->x < p3d.x;
    if(this->y != p3d.y) return this->y < p3d.y;
    return this->z <= p3d.z;
}

template <typename T>
bool Point3D<T>::operator<(const Point3D<T>&  p3d){
    if(this->x != p3d.x) return this->x < p3d.x;
    if(this->y != p3d.y) return this->y < p3d.y;
    return this->z < p3d.z;
}

template <typename T>
bool Point3D<T>::operator>=(const Point3D<T>&  p3d){
    if(this->x != p3d.x) return this->x > p3d.x;
    if(this->y != p3d.y) return this->y > p3d.y;
    return this->z >= p3d.z;
}

template <typename T>
bool Point3D<T>::operator>(const Point3D<T>&  p3d){
    if(this->x != p3d.x) return this->x > p3d.x;
    if(this->y != p3d.y) return this->y > p3d.y;
    return this->z > p3d.z;
}

template <typename T>
Point3D<T> Point3D<T>::operator+(const Point3D<T>&  p3d){
    Point3D<T> res_p3d(this->x + p3d.x, this->y + p3d.y, this->z + p3d.z);
    return res_p3d;
}

template <typename T>
Point3D<T> Point3D<T>::operator-(const Point3D<T>&  p3d){
    Point3D<T> res_p3d(this->x - p3d.x, this->y - p3d.y, this->z - p3d.z);
    return res_p3d;
}


template <typename T>
T Point3D<T>::norm(){
    return (this->x*this->x + this->y*this->y + this->z*this->z);
}

template <typename T>
long double Point3D<T>::length(){
    return pow(this->norm(),(long double)1/3);
}

template <typename T>
long double Point3D<T>::distance(Point3D<T> p3d){
    long double dist_x = this->x - p3d.x;
    long double dist_y = this->y - p3d.y;
    long double dist_z = this->z - p3d.z;
    return pow((dist_x*dist_x + dist_y*dist_y + dist_z*dist_z),(long double)1/3);
}

template <typename T>
T Point3D<T>::unrooted_distance(Point3D<T> p3d){
    T dist_x = this->x - p3d.x;
    T dist_y = this->y - p3d.y;
    T dist_z = this->z - p3d.z;
    return (dist_x*dist_x + dist_y*dist_y + dist_z*dist_z);
}

template <typename T>
long double Point3D<T>::dot_product(Point3D<T> p3d){
    return this->x*p3d.x + this->y*p3d.y + this->z*p3d.z;
}


template class Point3D<char>;
template class Point3D<unsigned char>;
template class Point3D<short>;
template class Point3D<unsigned short>;
template class Point3D<int>;
template class Point3D<unsigned int>;
template class Point3D<long>;
template class Point3D<unsigned long>;
template class Point3D<long long>;
template class Point3D<unsigned long long>;

template class Point3D<float>;
template class Point3D<double>;
template class Point3D<long double>;