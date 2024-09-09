#pragma once

#include "nvec.h"

template< typename T,size_t dimT>
class nBox{
public:
    nBox(): center(),halfsizes() {}
    nBox(nVector<T,dimT> c,nVector<T,dimT> hs): center(c),halfsizes(hs){}
    void print(){
        for(int i = 0; i < dimT; i++){
            std::cout<<center[i]<<":";

        }
        std::cout<<std::endl;
        for(int i = 0; i < dimT; i++){
            std::cout<<halfsizes[i]<<":";
            
        }
    }

    bool contains(nVector<T,dimT> point){
        for(int i = 0; i < dimT; i++){
            if(point[i] < center[i] - halfsizes[i] || point[i] > center[i] + halfsizes[i] ){
                return false;
            }
        }
        return true;
    }

    bool intersects(nBox<T,dimT> other){
        for(int i = 0; i < dimT; i++){
            if(!((center[i] - halfsizes[i] >= other.center[i] + other.halfsizes[i]) || (center[i] + halfsizes[i] <= other.center[i] - other.halfsizes[i]))){
                return true;
            }
        }
        return false;
    }
    
public:
    nVector<T,dimT> center;
    nVector<T,dimT> halfsizes;
};
