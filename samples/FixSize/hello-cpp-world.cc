#include <iostream>
#include "IFixedSizeMemoryManager.h"
#include <ctime>
using namespace std;

#define NUM 8
//#define KERNAL

class test{
  public:
  int a;
};

int main() {
    std::cout << "Hello World!" << std::endl;
    clock_t t = clock();
    char* pC[NUM];
    for(int i = 0;i<NUM;i++)
    {
        #ifdef KERNAL
        void* p = (void*) new char[2];
        #else
        void* p = mynew(6);
        #endif
        
        
        if(p == NULL)
        {
            cout<<"No Memory Allocation"<<endl;
        }
        else
        {
            pC[i] = (char*) p;
            *pC[i] = 'a';
        }
    }
    for(int i = 0;i<NUM;i++)
    {
        if(i%2 == 0)
        {
        #ifdef KERNAL
            delete pC[i];
        #else
            mydelete((void*)pC[i]);
        #endif
        }
    }
    
    void *pm = mynew(2);
    mydelete(pm);
    
    test t = new test;
    
    cout<<clock()-t<<endl;
}
