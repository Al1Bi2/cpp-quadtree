#include "nvec.h"

template< typename T,size_t dimT>
class nBox{
public:
nBox(): center(),halfsizes() {}
nBox(nVector<T,dimT> c,nVector<T,dimT> hs): center(c),halfsizes(hs);
void print(){
    std::cut
}
public:
    nVector<T,dimT> center;
    nVector<T,dimT> halfsizes;
};