#include "Node.h"

//Constructor
  Node::Node(){
    key = 0;
    rank = 0;
    leftChild = nullptr;
    rightChild = nullptr;
  }
  Node::Node(int k){
    key = k;
    rank = 0;
    leftChild = nullptr;
    rightChild = nullptr;
  }
  Node::Node(int k, int r){
    key = key;
    rank = r;
    leftChild = nullptr;
    rightChild = nullptr;
  }
