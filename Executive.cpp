#include <iostream>
#include <string>
#include <fstream>

#include "MinLeftHeap.h"
#include "Executive.h"

#define MAXINPUT 9

Executive::Executive(std::string path) {
  mlHeap = new MinLeftHeap();
  filePath = path;
}

int Executive::menuInput() {
  int choice;

  std::cout << "Please choose one of the following commands: \n";
  std::cout << "1. Insert \n";
  std::cout << "2. Merge \n";
  std::cout << "3. DeleteMin \n";
  std::cout << "4. FindMin \n";
  std::cout << "5. Preorder \n";
  std::cout << "6. Inorder \n";
  std::cout << "7. Postorder \n";
  std::cout << "8. Levelorder \n";
  std::cout << "9. Exit \n";

  std::cout << ">> ";
  std::cin >> choice;
  std::cout << std::endl;

  return(choice);
}

void Executive::run() {
  bool quit = false;
  while(!quit) {
    switch (menuInput()) {
      //Insert
      case 1: {
        int input;
        std::cout << "Please enter the value which you want to enter into the Min-Left Heap: ";
        std::cin >> input;
        mlHeap->Insert(input);
        std::cout << "Output: ";

        break;
      }
      //Merge
      case 2: {
        std::cout << "Output: ";

        break;
      }
      //DeleteMin
      case 3: {
        std::cout << "Output: ";
        if(mlHeap->isEmpty()) {
          std::cout << "Empty tree, no element to delete\n.";
        }
        else {
          mlHeap->DeleteMin();
          std::cout <<"Min element has been removed from the tree.\n";
        }
        break;
      }
      //FindMin
      case 4: {
        std::cout << "Output: ";
        if(mlHeap->isEmpty()) {
          std::cout << "Empty tree, no element to find\n.";
        }
        else {
          int min;
          min = mlHeap->FindMin();
          std::cout <<"Min element of tree: " <<min <<".\n";
        }
        break;
      }
      //Preorder
      case 5: {
        std::cout <<"Output: ";
        if(mlHeap->isEmpty()) {
          std::cout << "Empty tree, no traversal shown.\n.";
        }
        else {
          std::cout <<"Preorder traversal: ";
          mlHeap->Preorder();
          std::cout << std::endl;
        }
        break;
      }
      //Inorder
      case 6: {
        std::cout <<"Output: ";
        if(mlHeap->isEmpty()) {
          std::cout << "Empty tree, no traversal shown.\n.";
        }
        else {
          std::cout <<"Inorder traversal: ";
          mlHeap->Inorder();
          std::cout << std::endl;
        }
        break;
      }
      //Postorder
      case 7: {
        std::cout <<"Output: ";
        if(mlHeap->isEmpty()) {
          std::cout << "Empty tree, no traversal shown.\n.";
        }
        else {
          std::cout <<"Postorder traversal: ";
          mlHeap->Postorder();
          std::cout << std::endl;
        }
        break;
      }
      //Levelorder
      case 8: {
        std::cout <<"Output: ";
        if(mlHeap->isEmpty()) {
          std::cout << "Empty tree, no traversal shown.\n.";
        }
        else {
          std::cout <<"Levelorder traversal: ";
          mlHeap->Levelorder();
          std::cout << std::endl;
        }
        break;
      }
      //Exit
      case 9: {
        std::cout <<"Output: Bye!!!\n";
        quit = true;
        break;
      }
      //Invalid Input
      default: {
          std::cout << "Please input a number between 1 and " <<MAXINPUT <<".\n\n";
          break;
      }
    }
  }
}

bool Executive::parseInputFile() {
  // pq = *mlHeap;
  std::ifstream inputFile(filePath);
  std::string input;
  char c;
  if (inputFile.is_open()) {
    while(inputFile.get(c)) {
      if (c != ' ' && c != '\n') {
        input += c;
        // std::cout <<"current input: " <<input <<std::endl;
      }
      else {
        // std::cout << "In loop, inserting: " <<input <<" into pq of size: " <<mlHeap->GetHeap_Size() <<std::endl;
        int strInt = std::stoi(input);
        mlHeap->Insert(strInt);
        // mlHeap->PrintHeap();
        input = "";
      }
    }
    inputFile.close();
    return(true);
  }
  else {
    std::cout << "File Path: " <<filePath <<" is an invalid path.\n";
    return(false);
  }
}
