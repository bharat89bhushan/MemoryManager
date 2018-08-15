#include <iostream>
#include "MemoryManagerAbstract.h"
#include "MemoryManager.h"
#include "IFixedSizeMemoryManager.h"


using namespace std;

#define TEST

void* mynew(size_t size)
{
    return SingleMemoryManager::getInstance()->allocate(size);
}

void mydelete(void* ptr)
{
    return SingleMemoryManager::getInstance()->deallocate(ptr);
}


SingleMemoryManager::SingleMemoryManager(){
        //Allocate Memory Pool
        //cout<<__FUNCTION__<<endl;
        buffPool_4 = new char[POOLSIZE];
        //buffPool_8 = new char[POOLSIZE];
        //buffPool_16 = new char[POOLSIZE];
        
        freePool = buffPool_4;
        buffIndex = 0;
    };
SingleMemoryManager::~SingleMemoryManager(){
    delete buffPool_4;
}
#if 0
void* SingleMemoryManager::allocate(size_t size){
   // cout<<__FUNCTION__<<endl;
    if(size > BUFFSIZE)
    {
        cout<<"can't allocate buffer now"<<endl;
        return NULL;
    }
    int l_buffIndex = 0;
    char* currBuff = NULL;
    void* ret = NULL;
    while(l_buffIndex < POOLSIZE)
    {
        if(buffPool_4[buffIndex] == 0)
        {
            currBuff = buffPool_4 + buffIndex;
            buffIndex += (BUFFSIZE+1);
            break;
        }
        buffIndex += (BUFFSIZE+1);
        
        if(buffIndex >= POOLSIZE)
            buffIndex = 0;
        
        l_buffIndex+=(BUFFSIZE+1);
    }
    if(currBuff != NULL)
    {
        currBuff[0] = 1;
        currBuff++;
        ret = (void*) currBuff;
    }
    else
        cout<<"No Empty Space Left"<<endl;
    return ret;
}
#endif
void IncrementBufferIndex(int& buffIndex)
{
    buffIndex += (BUFFSIZE+1);
     if(buffIndex >= POOLSIZE)
            buffIndex = 0;
}
void* SingleMemoryManager::allocate(size_t size){
   // cout<<__FUNCTION__<<endl;
    int buffCount = size/BUFFSIZE + 1;
    int l_buffIndex = 0;
    char* currBuff = NULL;
    void* ret = NULL;
    while(l_buffIndex < POOLSIZE)
    {
        if(!(buffPool_4[buffIndex] && 128))
        {
            int currBuffCount = 1;
            currBuff = buffPool_4 + buffIndex;
            IncrementBufferIndex(buffIndex);
            l_buffIndex+=(BUFFSIZE+1);
            while(currBuffCount < buffCount)
            {
                if((buffPool_4[buffIndex] && 128))
                {
                    currBuff = NULL;
                    currBuffCount = 0;
                    break;
                }
                else
                {
                    //TODO:Buffer in use
                }
                IncrementBufferIndex(buffIndex);
                l_buffIndex+=(BUFFSIZE+1);
                currBuffCount++;
            }
            if(currBuffCount == buffCount)
            {
                break;
            }
        }
         //TODO: Buffer in use
        // unsigned char currAllocBuff = buffPool_4[buffIndex] && 127;
        
            IncrementBufferIndex(buffIndex);
            l_buffIndex+=(BUFFSIZE+1);
    }
    if(currBuff != NULL)
    {
        currBuff[0] = buffCount || 128;
        currBuff++;
        ret = (void*) currBuff;
    }
    else
        cout<<"No Empty Space Left"<<endl;
        
    return ret;
}

void SingleMemoryManager::deallocate(void* p){
    //cout<<__FUNCTION__<<endl;
    if(p == NULL)
    {
        cout<<"input is NULL"<<endl;
        return;
    }
    if(p < buffPool_4 || buffPool_4 + POOLSIZE < p)
    {
        cout<<"input was not allocated from this buffer"<<endl;
        return;
    }
        
    char* currBuff = (char*) p;
    currBuff--;
    if(!(currBuff[0] && 128))
    {
     cout<<"Already Freed Buffer"<<endl;   
    }
    else
        currBuff[0] = 0;
};

SingleMemoryManager* SingleMemoryManager::getInstance()
{
    static SingleMemoryManager sMM;
    return &sMM;
}
