#include "Polygon2D.h"

template <typename T> 
Polygon2D<T>::Polygon2D(){}

template <typename T> 
Polygon2D<T>::Polygon2D(vector<Point2D<T>> points){
    this->points = points;
}

template <typename T> 
void Polygon2D<T>::add_point(Point2D<T> p2d){
    this->points.push_back(p2d);
}

template <typename T> 
void Polygon2D<T>::add_point(Point2D<T> p2d, int idx){
    this->points.insert(this->points.begin() + idx, p2d);
}

template <typename T> 
void Polygon2D<T>::erase_point(){
    this->points.pop_back();
}

template <typename T> 
void Polygon2D<T>::erase_point(Point2D<T> p2d){
    int idx;
    for(idx = 0; idx < this->points.size(); idx++){
        if(this->points[idx] == p2d) break;
    }
    this->points.erase(this->points.begin() + idx);
}

template <typename T> 
void Polygon2D<T>::erase_point(int idx){
    this->points.erase(this->points.begin() + idx);
}


template <typename T> 
long double Polygon2D<T>::area(){
    long double result = 0;
    if(this->points.size() < 3) return result;

    T result_tmp = 0;
    Point2D<T> reference_point(0,0);
    for(int i = 1; i < this->points.size(); i++){
        result_tmp += reference_point.signed_area_parallelogram(this->points[i-1], this->points[i]);
    }
    result_tmp += reference_point.signed_area_parallelogram(this->points.back(), this->points[0]);

    result = abs((long double) result_tmp) / 2.0;
    return result;
}

template <typename T> 
bool Polygon2D<T>::inside(Point2D<T> p2d){
    Ray2D<T> r2d(p2d);
    int ctr1 = 0;
    for(int i = 1; i < this->points.size(); i++){
        Segment2D<T> s2d(this->points[i-1], this->points[i]);
        if(r2d.intersect(s2d)){
            ctr1++;
            if(r2d.inside(this->points[i])) ctr1--;
        }
    }
    Segment2D<T> s2d(this->points.back(), this->points[0]);
    if(r2d.intersect(s2d)){
        ctr1++;
        if(r2d.inside(this->points[0])) ctr1--;
    } 
    return (ctr1&1);
}




template class Polygon2D<char>;
template class Polygon2D<unsigned char>;
template class Polygon2D<short>;
template class Polygon2D<unsigned short>;
template class Polygon2D<int>;
template class Polygon2D<unsigned int>;
template class Polygon2D<long>;
template class Polygon2D<unsigned long>;
template class Polygon2D<long long>;
template class Polygon2D<unsigned long long>;

template class Polygon2D<float>;
template class Polygon2D<double>;
template class Polygon2D<long double>;