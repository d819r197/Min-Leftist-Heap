#ifndef MINLEFTHEAP_H
#define MINLEFTHEAP_H

#include <iostream>

#include "Node.h"

class MinLeftHeap {
  public:
    //Constructor
    MinLeftHeap();

    //Class Methods
    void Build();

    void Insert(int key);

    void DeleteMin();
    int FindMin() { return(treeRoot->getKey()); }

    Node* RecMerge(Node* h1, Node* h2);
    Node* Merge(Node* h1, Node* h2);

    void RecPrintPreorder(Node* root);
    void RecPrintPostorder(Node* root);
    void RecPrintInorder(Node* root);
    void RecPrintLevelorder(Node* root);

    void Preorder() { RecPrintPreorder(treeRoot); }
    void Postorder() { RecPrintPostorder(treeRoot); }
    void Inorder() { RecPrintInorder(treeRoot); }
    void Levelorder() { RecPrintLevelorder(treeRoot); }

    //Helper Functions
    void IncTree_Size() { treeSize++; }
    void DecTree_Size() { treeSize--; }
    int GetTree_Size() { return treeSize; }

    void IncTree_Height() { treeHeight++; }
    void DecTree_Height() { treeHeight--; }
    int GetTree_Height() { return treeHeight; }

    Node* GetTree_Root() { return treeRoot; }

    bool isEmpty() { if(treeRoot == nullptr){ return(true); } return(false); }

  private:
    Node* treeRoot;
    int treeSize;
    int treeHeight;
};

#endif
