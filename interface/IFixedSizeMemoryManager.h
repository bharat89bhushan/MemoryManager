
#ifndef _I_MMR_MNG_H
#define _I_MMR_MNG_H


#define POOLSIZE 40000  //Total size in Bytes
#define BUFFSIZE 4  //Buffer chuk size in Bytes excluded 1 byte header

extern void* mynew(size_t size);

extern void mydelete(void* ptr);


//Inherit class from Imemory to allocate memory from Memory manager application
class Imemory{
    public:
    void* operator new(size_t size)
    {
        return ::mynew(size);
    }
    void operator delete(void* ptr)
    {
        return ::mydelete(ptr);
    }
};

#endif