#include <iostream>
#include "IFixedSizeMemoryManager.h"
#include <ctime>
using namespace std;

#define NUM 80
//#define KERNAL


int main() {
    std::cout << "Hello World!" << std::endl;
    clock_t t = clock();
    char* pC[NUM];
    for(int i = 0;i<NUM;i++)
    {
        #ifdef KERNAL
        void* p = (void*) new char[2];
        #else
        void* p = mynew(2);
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
        #ifdef KERNAL
            delete pC[i];
        #else
            mydelete((void*)pC[i]);
        #endif
    }
    cout<<clock()-t<<endl;
}
