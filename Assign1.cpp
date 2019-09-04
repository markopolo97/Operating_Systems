//
//  CECS 326 Assignment 1: Programming Review
//  main.cpp
//  Assign1_ProgramReview file
//
//  Created by Mark Aquiapao on 9/2/19.
//  Copyright © 2019 Mark Aquiapao. All rights reserved.
//

#include <iostream>
using namespace std;


/*class StringPool
{
    struct StringReference {
        char *buffer;
        time_t created;
    } *Pool;
    
    size_t PoolSize;
    size_t Allocated;
    
    static const size_t INITIAL_SIZE = 1024;
    
    void GrowBuffer()
    {
        StringReference *newPool = new StringReference[PoolSize * 2];
        for (size_t i = 0; i < Allocated; ++i)
        newPool[i] = Pool[i];
        StringReference *oldPool = Pool;
        Pool = newPool;
        delete[] oldPool;
    }
    
    public:
    
    StringPool() : Pool(new StringReference[INITIAL_SIZE]), PoolSize(INITIAL_SIZE)
    {
    }
    
    ~StringPool()
    {
        ClearPool();
        delete[] Pool;
    }
    
    char *GetBuffer(size_t size)
    {
        if (Allocated == PoolSize)
        GrowBuffer();
        Pool[Allocated].buffer = new char[size];
        Pool[Allocated].buffer = time(NULL);
        ++Allocated;
    }
    
    void ClearPool()
    {
        for (size_t i = 0; i < Allocated; ++i)
        delete[] Pool[i].buffer;
        Allocated = 0;
    }
    
    void ClearBefore(time_t knownCleared)
    {
        size_t newAllocated = 0;
        for (size_t i = 0; i < Allocated; ++i)
        {
            if (Pool[i].created < knownCleared)
            {
                delete[] Pool[i].buffer;
            }
            else
            {
                Pool[newAllocated] = Pool[i];
                ++newAllocated;
            }
        }
        Allocated = newAllocated;
    }
    
    // This compares pointers, not strings!
    void ReleaseBuffer(char *knownCleared)
    {
        size_t newAllocated = 0;
        for (size_t i = 0; i < Allocated; ++i)
        {
            if (Pool[i].buffer == knownCleared)
            {
                delete[] Pool[i].buffer;
            }
            else
            {
                Pool[newAllocated] = Pool[i];
                ++newAllocated;
            }
        }
        Allocated = newAllocated;
    }
    
};*/


int main() {
    
    string dictionary[15] = {   "FIRST",
                                "CPP",
                                "REVIEW",
                                "PROGRAM",
                                "ASSIGNMENT",
                                "CECS",
                                "BEACH",
                                "ECS",
                                "FALL",
                                "SPRING",
                                "OS",
                                "MAC",
                                "LINUX",
                                "WINDOWS",
                                "LAB"   };
    
    string documents[1024];
    
    for(int i=0; i<1024; i++){
        // randomly assign capital letter
        documents[i] = rand() % 25 + 'A';
    }
    
    for(int i=0; i<1024; i++){
        // randomly assign capital letter
        cout << "documents[" << i << "] = " << documents[i] << "\n";
    }
    
    
    return 0;
    
}
