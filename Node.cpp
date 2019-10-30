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
    rank = ComputeRank();
    leftChild = nullptr;
    rightChild = nullptr;
  }

//Helper Functions
int Node::ComputeRank() {
  int r = 0;
  if(leftChild != nullptr) {
    r++;
  }
  if(rightChild != nullptr) {
    r++;
  }
  rank = r;
}
