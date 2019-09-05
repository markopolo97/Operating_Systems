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

// Declare Constants and Globals

const int   DOC_SIZE = 1024, POINTER = 128, MAX_MEM = 3000000, MIN_MEM = 2000000;

struct library {
    string doc;
};

struct recent_list {
    string doc;
};

string dictionary[15] = {       "FIRST",
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
                                "LAB"       };


int main()
{
    // declare main variables
    library lib_document[DOC_SIZE];
    recent_list rl_document[POINTER];
    recent_list* ptr;
    ptr = rl_document;
    int mem_size;
    
    // Initialize 1024 documents for library
    for(int i=0; i<DOC_SIZE; i++)
    {
        // Choose memory size between 2MB and 3MB randomly
        // char = 1 byte -> 1 MB = 1,000,000 bytes
        mem_size = (rand() > RAND_MAX/2) ? MIN_MEM : MAX_MEM;
        for(int j=0; j<mem_size; j++)
        {
            lib_document[i].doc += rand() % 25 + 'A'; // pick randomly from A-Z
        }
    }
    
    // Initialize 128 documents for recent_list
    for(int i=0; i<POINTER; i++)
    {
        // Choose memory size between 2MB and 3MB randomly
        // char = 1 byte -> 1 MB = 1,000,000 bytes
        mem_size = (rand() > RAND_MAX/2) ? MIN_MEM : MAX_MEM;
        for(int j=0; j<mem_size; j++)
        {
            rl_document[i].doc += rand() % 25 + 'A'; // pick randomly from A-Z
        }
    }
    
    
    
    
    
    
    return 0; // terminate program
    
}

void SearchWord(char text[], char word[])
{/*
    int i=0, c=0;
    while (text[i]!='\0')
    {
        if (text[i]==word[c] && word[c]!='\0' && text[i]!=' ')
            c++;
        else
            c=0;
        
        i++;
    }
    if (c==sizeof(word))
        cout<<"\nWord found"<<endl;
    else
        cout<<"\nWord not found"<<endl;*/
}
