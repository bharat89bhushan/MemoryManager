#include <iostream>
#include <string>
#include <ctime>
#include "IFixedSizeMemoryManager.h"

using namespace std;



int main()
{
START:
    int count;
    cout<<"Enter number of allocation:";
    cin>>count;
    
    int size;
    cout<<"Enter size of allocation:";
    cin>>size;
    
    //Check if all allocations are possible
    if(((size/(BUFFSIZE+1))+1)*count > POOLSIZE/(BUFFSIZE+1))
    {
        cout<<"All allocations can not be made"<<endl;
        cout<<"Either change POOLSIZE and BUFFSIZE in config/interface or change value"<<endl;
        cout<<"You want to continue with new parameters? Enter Y/N: ";
        string input;
        cin>>input;
        if(input == "Y" || input == "y")
            goto START;
        else
            goto END;
    }
    {
    #if 1    
        char* ptr[count];
     
        clock_t t1 = clock();
        for(int i =0;i<count;i++)
        {
            ptr[i] = (char*)mynew(size);
        }
        cout<<"Application: Time taken in allocate "<<clock()-t1<<endl;
     
        clock_t t2 = clock();
        for(int i =0;i<count;i++)
        {
            mydelete((void*)ptr[i]);
        }
        cout<<"Application: Time taken in deallocate "<<clock()-t2<<endl;
        
        clock_t t3 = clock();
        for(int i =0;i<count;i++)
        {
            ptr[i] = new char[size];
        }
        cout<<"Kernal: Time taken in allocate "<<clock()-t3<<endl;
        
        clock_t t4 = clock();
        for(int i =0;i<count;i++)
        {
            delete ptr[i];
        }
        cout<<"Kernal: Time taken in deallocate "<<clock()-t4<<endl;
    #endif
    
    string val;
    cout<<"Retry (Y/N) - ";
    cin>>val;
    if(val == "Y" || val == "y")
            goto START;
        else
            goto END;
    }
END:
    return 0;
}