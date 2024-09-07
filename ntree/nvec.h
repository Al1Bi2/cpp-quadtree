#pragma once
#include <iostream>
#include <array>
#include <format>
#include <string>

template<typename T, size_t dimT>
class nVector{
public:
    nVector(){
        coord.fill(T());
        std::fill(std::begin(coord), std::end(coord), 0);
    };
    nVector(const std::initializer_list<T>& list){
        if(list.size()>dimT){
            throw std::invalid_argument(std::format("Too many arguments, should be {} instead of {}",dimT, list.size()));
        }
        size_t idx = 0;
        for(T elem: list){
            coord[idx++] = elem;            
        }
    }
    T get(size_t idx){
        return coord.at(idx);
    }
    T operator[](size_t idx){
        return get(idx);
    }
    constexpr nVector<T,dimT> operator+=(nVector<T, dimT>& other){
        for( int i = 0 ; i< dimT; i++){
            coord[i]+=other[i];
        }
    } 

    constexpr nVector<T,dimT> operator/=(T scalar){
        for( int i = 0 ; i< dimT; i++){
            coord[i]/=scalar;
        }
    } 
    constexpr nVector<T,dimT> operator*=(T scalar){
        for( int i = 0 ; i< dimT; i++){
            coord[i]*=scalar;
        }
    } 
public:
    std::array<T, dimT> coord;

};
