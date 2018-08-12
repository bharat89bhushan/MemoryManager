

#ifndef IMMRMNG
#define IMMRMNG

class SingleMemoryManager:public IMemoryManager{
    char* buffPool_4;
    char* buffPool_8;
    char* buffPool_16;
    
    char* freePool;
    int buffIndex;
    SingleMemoryManager();
    ~SingleMemoryManager();
    
    public:
    void* allocate(size_t size);
    void deallocate(void* p);
    static SingleMemoryManager* getInstance();
};
#endif