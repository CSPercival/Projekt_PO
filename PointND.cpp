#include "PointND.h"

template <typename T> 
PointND<T>::PointND(){
    this->coords.push_back(0);
}

template <typename T>
PointND<T>::PointND(vector<T> coords){
    this->coords = coords;
}

template <typename T>
bool PointND<T>::operator==(const PointND<T>&  pnd){
    assert(this->coords.size() == pnd.coords.size());
    for(int i = 0; i < this->coords.size(); i++){
        if(this->coords[i] != pnd.coords[i]) return false;
    }
    return true;
}

template <typename T>
bool PointND<T>::operator<=(const PointND<T>&  pnd){
    assert(this->coords.size() == pnd.coords.size());
    for(int i = 0; i < this->coords.size(); i++){
        if(this->coords[i] != pnd.coords[i]) return this->coords[i] < pnd.coords[i];
    }
    return true;
}

template <typename T>
bool PointND<T>::operator<(const PointND<T>&  pnd){
    assert(this->coords.size() == pnd.coords.size());
    for(int i = 0; i < this->coords.size(); i++){
        if(this->coords[i] != pnd.coords[i]) return this->coords[i] < pnd.coords[i];
    }
    return false;
}

template <typename T>
bool PointND<T>::operator>=(const PointND<T>&  pnd){
    assert(this->coords.size() == pnd.coords.size());
    for(int i = 0; i < this->coords.size(); i++){
        if(this->coords[i] != pnd.coords[i]) return this->coords[i] > pnd.coords[i];
    }
    return true;
}

template <typename T>
bool PointND<T>::operator>(const PointND<T>&  pnd){
    assert(this->coords.size() == pnd.coords.size());
    for(int i = 0; i < this->coords.size(); i++){
        if(this->coords[i] != pnd.coords[i]) return this->coords[i] > pnd.coords[i];
    }
    return false;
}

template <typename T>
PointND<T> PointND<T>::operator+(const PointND<T>&  pnd){
    assert(this->coords.size() == pnd.coords.size());
    vector<T> res_coords = this->coords;
    for(int i = 0; i < pnd.coords.size(); i++){
        res_coords[i] += pnd.coords[i];
    }
    PointND<T> res_pnd(res_coords);
    return res_pnd;
}

template <typename T>
PointND<T> PointND<T>::operator-(const PointND<T>&  pnd){
    assert(this->coords.size() == pnd.coords.size());
    vector<T> res_coords = this->coords;
    for(int i = 0; i < pnd.coords.size(); i++){
        res_coords[i] -= pnd.coords[i];
    }
    PointND<T> res_pnd(res_coords);
    return res_pnd;
}


template <typename T>
T PointND<T>::norm(){
    T res = 0;
    for(int i = 0; i < this->coords.size(); i++){
        res += (this->coords[i] * this->coords[i]);
    }
    return res;
}

template <typename T>
long double PointND<T>::length(){
    return pow(this->norm(),(long double)1/this->coords.size());
}

template <typename T>
long double PointND<T>::distance(PointND<T> pnd){
    long double res = 0;
    for(int i = 0; i < this->coords.size(); i++){
        res += ((this->coords[i] - pnd.coords[i]) * (this->coords[i] - pnd.coords[i]));
    }
    return pow(res,(long double)1/this->coords.size());
}

template <typename T>
T PointND<T>::unrooted_distance(PointND<T> pnd){
    T res = 0;
    for(int i = 0; i < this->coords.size(); i++){
        res += ((this->coords[i] - pnd.coords[i]) * (this->coords[i] - pnd.coords[i]));
    }
    return res;
}

template <typename T>
long double PointND<T>::dot_product(PointND<T> pnd){
    long double res = 0;
    for(int i = 0; i < this->coords.size(); i++){
        res += this->coords[i] * pnd.coords[i];
    }
    return res;
}


template class PointND<char>;
template class PointND<unsigned char>;
template class PointND<short>;
template class PointND<unsigned short>;
template class PointND<int>;
template class PointND<unsigned int>;
template class PointND<long>;
template class PointND<unsigned long>;
template class PointND<long long>;
template class PointND<unsigned long long>;

template class PointND<float>;
template class PointND<double>;
template class PointND<long double>;