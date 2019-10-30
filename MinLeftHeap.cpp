#include <iostream>
#include <ctime>

#include "MinLeftHeap.h"

//Constructor
MinLeftHeap::MinLeftHeap() {
  treeRoot = nullptr;
  treeSize = 0;
  treeHeight = 0;
}

//Class Methods
void MinLeftHeap::Build(){

}

void MinLeftHeap::RecHeapify(int rootIndex, int level){

}

bool MinLeftHeap::RecInsert(int * value, int rootIndex) {

}

void MinLeftHeap::Insert(int * value) {

}

void MinLeftHeap::DeleteMin() {

}

void MinLeftHeap::FindMin() {

}

void MinLeftHeap::PrintHeap() {

}

void MinLeftHeap::RecPrintPreorder(Node* root) {

}

void MinLeftHeap::RecPrintPostorder(Node* root) {

}

void MinLeftHeap::RecPrintInorder(Node* root) {
  if(root->getLeftChild() != nullptr) {
    RecPrintInorder(root->getLeftChild());
  }
  std::cout <<root->getKey() << ", ";
  if(root->getRightChild() != nullptr) {
    RecPrintInorder(root->getRightChild());
  }
}

void MinLeftHeap::RecPrintLevelorder(Node* root) {

}

void MinLeftHeap::PrintPreorder() {

}

void MinLeftHeap::PrintPostorder() {

}

void MinLeftHeap::PrintInorder() {
  std::cout << "Printing the tree in In-Order: ";
  RecPrintInorder(treeRoot);
  std::cout << std::endl;
}

void MinLeftHeap::PrintLevelorder() {

}
