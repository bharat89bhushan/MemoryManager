
#ifndef _I_MMR_MNG_H
#define _I_MMR_MNG_H


#define POOLSIZE 40  //Total size in Bytes
#define BUFFSIZE 4  //Buffer chuk size in Bytes


extern void* mynew(size_t size);

extern void mydelete(void* ptr);

#endif