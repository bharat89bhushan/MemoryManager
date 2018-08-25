#include <iostream>
#include "IFixedSizeMemoryManager.h"

using namespace std;


//Inherit class from Imemory
class test:public Imemory
{
    int a;
};

int main()
{
    test* obj = new test;
    return 0;
}