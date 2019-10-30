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

    void RecHeapify(int rootIndex, int level);
    void Heapify() { RecHeapify(0, 0); }

    bool RecInsert(int * value, int index);
    void Insert(int * value);

    void DeleteMin();
    void FindMin();

    void Merge(MinLeftHeap* h1, MinLeftHeap* h2);

    void RecPrintPreorder(Node* root);
    void RecPrintPostorder(Node* root);
    void RecPrintInorder(Node* root);
    void RecPrintLevelorder(Node* root);

    void PrintPreorder();
    void PrintPostorder();
    void PrintInorder();
    void PrintLevelorder();

    //Helper Functions
    void IncTree_Size() { treeSize++; }
    void DecTree_Size() { treeSize--; }
    int GetTree_Size() { return treeSize; }

    void IncTree_Height() { treeHeight++; }
    void DecTree_Height() { treeHeight--; }
    int GetTree_Height() { return treeHeight; }

    Node* GetTree_Root() { return treeRoot; }

    void PrintHeap();

    bool isEmpty() { if(treeRoot == nullptr){ return(true); } return(false); }

  private:
    Node* treeRoot;
    int treeSize;
    int treeHeight;
};

#endif
