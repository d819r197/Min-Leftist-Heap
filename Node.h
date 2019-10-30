#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

class Node {
  public:
    //Constructor
    Node();
    Node(int k);
    Node(int k, int r);
    
    //Helper Functions
    void setKey(int k) { key = k; }
    void setRank(int r) { rank = r; }
    void setLeftChild(Node* child) { leftChild = child; }
    void setRightChild(Node* child) { rightChild = child; }

    int getKey() { return(key); }
    int getRank() { return(rank); }
    Node* getLeftChild() { return(leftChild); }
    Node* getRightChild() { return(rightChild); }

  private:
    int key;
    int rank;
    Node* leftChild;
    Node* rightChild;
};

#endif
