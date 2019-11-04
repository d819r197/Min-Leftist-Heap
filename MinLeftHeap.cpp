#include <iostream>
#include <ctime>

#include "MinLeftHeap.h"

//Constructor
MinLeftHeap::MinLeftHeap() {
  treeRoot = nullptr;
  treeSize = 0;
  treeHeight = 0;

  nodesInLevel = 0;
  maxNodesInLevel = 1;
}

//Class Methods
void MinLeftHeap::Insert(int key) {
  treeSize++;
  nodesInLevel++;
  if(nodesInLevel == maxNodesInLevel) {
    treeHeight++;
    maxNodesInLevel = maxNodesInLevel*2;
    nodesInLevel = 0;
    std::cout <<"incrementing tree height. Current height: " <<treeHeight <<std::endl;
  }
  treeRoot = Merge(new Node(key), treeRoot);
}

Node* MinLeftHeap::RecMerge(Node* h1, Node* h2) {
  if (h1->getLeftChild() == nullptr) {
    h1->setLeftChild(h2);
  }
  else {
    h1->setRightChild(Merge(h1->getRightChild(), h2));
    if ((h1->getLeftChild())->getRank() < (h1->getRightChild())->getRank()) {
      Node * temp = h1->getLeftChild();
      h1->setLeftChild(h1->getRightChild());
      h1->setRightChild(temp);
    }
    h1->ComputeRank();
    }
  return(h1);
}

Node* MinLeftHeap::Merge(Node* h1, Node* h2) {
  if (h1 == nullptr) {
    return(h2);
  }
  if (h2 == nullptr) {
    return(h1);
  }
  // std::cout <<"H1 and H2 are not null\n";
  if (h1->getKey() < h2->getKey())
    return(RecMerge(h1, h2));
  else
    return(RecMerge(h2, h1));
}

void MinLeftHeap::DeleteMin() {
  Node * tempNode = treeRoot;
  treeRoot = Merge(tempNode->getLeftChild(), tempNode->getRightChild());
  delete(tempNode);
}

void MinLeftHeap::RecPrintPreorder(Node* root) {
  if(treeRoot != nullptr) {
      std::cout <<root->getKey() << ", ";
      if(root->getLeftChild() != nullptr) {
        RecPrintInorder(root->getLeftChild());
      }
      if(root->getRightChild() != nullptr) {
        RecPrintInorder(root->getRightChild());
      }
    }
}

void MinLeftHeap::RecPrintPostorder(Node* root) {
  if(treeRoot != nullptr) {
      if(root->getLeftChild() != nullptr) {
        RecPrintInorder(root->getLeftChild());
      }
      if(root->getRightChild() != nullptr) {
        RecPrintInorder(root->getRightChild());
      }
      std::cout <<root->getKey() << ", ";
    }
}

void MinLeftHeap::RecPrintInorder(Node* root) {
  if(treeRoot != nullptr) {
    if(root->getLeftChild() != nullptr) {
      RecPrintInorder(root->getLeftChild());
    }
    std::cout <<root->getKey() << ", ";
    if(root->getRightChild() != nullptr) {
      RecPrintInorder(root->getRightChild());
    }
  }
}

void MinLeftHeap::RecPrintLevelorder(Node* root, int level) {
  if(!isEmpty() && root != nullptr) {
    if(level == 1) {
      std::cout <<root->getKey() <<", ";
    }
    else {
      level--;
      RecPrintLevelorder(root->getLeftChild(), level);
      RecPrintLevelorder(root->getRightChild(), level);
    }
  }
}

void MinLeftHeap::Levelorder() {
  for(int lcv = 1; lcv <= treeHeight+1; lcv++) {
    RecPrintLevelorder(treeRoot, lcv);
  }
}

bool MinLeftHeap::FindValue(Node* root, int value) {
  if(root != nullptr) {
    if(root->getKey() == value) {
      return(true);
    }
  }
  if(root->getLeftChild() != nullptr && root->getRightChild() != nullptr) {
    if(FindValue(root->getLeftChild(), value)) {
      return(true);
    }
    else if(FindValue(root->getLeftChild(), value)) {
      return(true);
    }
    else{
      return(false);
    }
  }
  else if(root->getLeftChild() != nullptr) {
    if(FindValue(root->getLeftChild(), value)) {
      return(true);
    }
  }
  else if(root->getRightChild() != nullptr) {
    if(FindValue(root->getRightChild(), value)) {
      return(true);
    }
  }
  return(false);
}
