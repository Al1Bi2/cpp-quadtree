#include <iostream>
#include "ntree/ntree.h"
#include <assert.h>

using namespace std;

void testBox();
void testNode();
int main(int argc, char** argv){


  testNode();
  
	return 0;
}
///TODO: Z curve is one for each depth level + 1 shifted by depth * dimension.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
//Such theres a contiguous range of Z values for each level.
/* static inline MortonNodeID GetHash(depth_t depth, MortonNodeIDCR key) noexcept
    {
      assert(key < (MortonNodeID(1) << (depth * DIMENSION_NO)));
      return (MortonNodeID{ 1 } << (depth * DIMENSION_NO)) | key;
    } */

void testNode(){

  nBox<int, 2> box1(nVector<int,2>{3,3},nVector<int,2>{3,3});
  NTree<int,2> tree;
  tree.Init(box1,2);  
  tree.nodes[1] = NTree<int,2>::Node(box1);
  assert(!tree.nodes.at(1).hasChildren());
  assert();
}







///TODO: THIIIIIIIIIIIS
void testBox(){
    nBox<int, 2> box1(nVector<int,2>({6,6}),nVector<int,2>{3,3});
    nBox<int, 2> box2(nVector<int,2>({3,4}),nVector<int,2>{2,2});
	nBox<int, 2> box3(nVector<int,2>({-3,-4}),nVector<int,2>{2,2});
    assert(box1.contains(nVector<int,2>({7,8})));
    assert(!box2.contains(nVector<int,2>({7,8})));
    assert(box1.intersects(box2));
	assert(!box1.intersects(box3));
    
}





