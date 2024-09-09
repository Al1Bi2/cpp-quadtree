#pragma once

#include "nbox.h"
#include <unordered_map>

using NodeID = size_t;


template< typename T, size_t dimT>
class nTree{
public:
class Node{
    public:
    nBox box;
    std::vector<NodeID> children;
}
///TODO: iplement Node aaray with z order
private:
    std::unordered_map<NodeID,Node> nodes;
    nBox<T,dimT> box;

};
