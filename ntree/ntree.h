#pragma once

#include "nbox.h"
#include <unordered_map>
#include <vector>
#include <optional>
using NodeID = size_t ;


template< typename T, size_t dimT, typename dataT>
class NTree{
public:
    class Node{
        public:
            nBox<T,dimT> box;
            std::vector<std::optional<NodeID>> children;
            std::vector<dataT> content;

        public:
            Node(): box(),children(){}
            Node( nBox<T,dimT> box):box(box), children(){}
        public:
            void addChild(int sub_node_id,NodeID child_id){
                for(size_t i = 0; i< sub_node_id, i<(1<<max_depth);i++){
                    children.at(i) = std::nullopt;
                }
                children.at(sub_node_id) = child_id;
            }
            bool hasChild(int sub_node_id){return children.at(sub_node_id).has_value();}
            bool hasChildren(){return !children.empty();}
            NodeID getChild(int sub_node_id){
                return children.at(sub_node_id).value();
            }
            void addData(Data data){this->content.push_back(data)}
    };
///TODO: iplement Node aaray with z order
//private:
public:
    std::unordered_map<NodeID,Node> nodes;
    nBox<T,dimT> size;
    size_t max_depth = 0;
    size_t cur_depth = 0;
    size_t cur_grid = 0;
public:
    NTree():nodes(),size(){}
    void Init(nBox<T,dimT> size, size_t max_depth){
        this->size = size;
        this->max_depth = max_depth;
        nodes.at(1)  = Node(size);

    }

public:
    NodeID getCode(nVector<T,dimT> point){
        
    }
};
