#ifndef LIBRARIES_AND_MACROS_H
#define LIBRARIES_AND_MACROS_H

#include <bits/stdc++.h>
#include <type_traits>

using namespace std;

const long double EPSILON = (long double)1/1e6;

template <typename T>
T my_abs(T x){
    if(x < 0) x *= -1;
    return x;
}

template <typename T>
bool if_int(){
    if (is_same<T, double>::value || 
        is_same<T, long double>::value ||
        is_same<T, float>::value) {
        return false;
    }
    return true;
}

#endif
