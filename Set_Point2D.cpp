#include "Set_Point2D.h"

template <typename T> 
Set_Point2D<T>::Set_Point2D(){}

template <typename T> 
Set_Point2D<T>::Set_Point2D(vector<Point2D<T>> points){
    this->points = points;
}

template <typename T> 
void Set_Point2D<T>::add_point(Point2D<T> p2d){
    this->points.push_back(p2d);
}

template <typename T> 
void Set_Point2D<T>::add_point(Point2D<T> p2d, int idx){
    this->points.insert(this->points.begin() + idx, p2d);
}

template <typename T> 
void Set_Point2D<T>::erase_point(){
    this->points.pop_back();
}

template <typename T> 
void Set_Point2D<T>::erase_point(Point2D<T> p2d){
    int idx;
    for(idx = 0; idx < this->points.size(); idx++){
        if(this->points[idx] == p2d) break;
    }
    this->points.erase(this->points.begin() + idx);
}

template <typename T> 
void Set_Point2D<T>::erase_point(int idx){
    this->points.erase(this->points.begin() + idx);
}
    


template <typename T> 
void Set_Point2D<T>::lex_sort(){
    sort(this->points.begin(),this->points.end());
}

template <typename T> 
void Set_Point2D<T>::angle_sort(){
    sort(this->points.begin(),this->points.end(), [](Point2D<T> a, Point2D<T> b) {
        return a.angle() < b.angle();
    });
}

template <typename T> 
void Set_Point2D<T>::angle_sort(Point2D<T> p2d){
    sort(this->points.begin(),this->points.end(), [&p2d](Point2D<T> a, Point2D<T> b) {
        return a.angle(p2d) < b.angle(p2d);
    });
}


template <typename T> 
Polygon2D<T> Set_Point2D<T>::convex_hull(){

    if(this->points.size() < 3){
        Polygon2D<T> ch(this->points);
        return ch;
    }

    this->lex_sort();
    
    Point2D<T> p2d1 = this->points[0], p2d2 = this->points.back();
    vector<Point2D<T>> up, down;
    up.push_back(p2d1);
    down.push_back(p2d1);
    
    for (int i = 1; i < this->points.size(); i++) {
        if (i == this->points.size() - 1 || p2d1.clockwise_area(this->points[i],p2d2)){
            while (up.size() >= 2 && !up[up.size()-2].clockwise_area(up[up.size()-1],this->points[i]))//!cw(up[up.size()-2], up[up.size()-1], a[i], include_collinear))
                up.pop_back();
            up.push_back(this->points[i]);
        }
        if (i == this->points.size() - 1 || !p2d1.clockwise_area(this->points[i],p2d2)){
            while (down.size() >= 2 && down[down.size()-2].clockwise_area(down[down.size()-1],this->points[i]))//!cw(up[up.size()-2], up[up.size()-1], a[i], include_collinear))
                down.pop_back();
            down.push_back(this->points[i]);
        }
    }

    Polygon2D<T> CH_result;
    for (int i = 0; i < (int)up.size(); i++)
        CH_result.add_point(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        CH_result.add_point(down[i]);
    return CH_result;
}


template class Set_Point2D<char>;
template class Set_Point2D<unsigned char>;
template class Set_Point2D<short>;
template class Set_Point2D<unsigned short>;
template class Set_Point2D<int>;
template class Set_Point2D<unsigned int>;
template class Set_Point2D<long>;
template class Set_Point2D<unsigned long>;
template class Set_Point2D<long long>;
template class Set_Point2D<unsigned long long>;

template class Set_Point2D<float>;
template class Set_Point2D<double>;
template class Set_Point2D<long double>;