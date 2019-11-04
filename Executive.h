#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <string>

#include "MinLeftHeap.h"

class Executive {
  public:
    //Constructor
    Executive(std::string path);

    //Class Methods
    int menuInput();
    void run();
    bool parseInputFile();

    void setHeap(MinLeftHeap * heap) { mlHeap = heap; }

  private:
    std::string filePath;
    MinLeftHeap * mlHeap;

};

#endif
