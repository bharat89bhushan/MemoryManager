
#ifndef MMRMNGABS
#define MMRMNGABS
    
    class IMemoryManager{
        public:
        virtual void* allocate(size_t size) = 0;
        virtual void deallocate(void* p) = 0;
    };
    
#endif