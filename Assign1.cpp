/*
 
 CECS 326 Assignment 1: Programming Review
 Instructor: Ratana Ngo
 Assign1.cpp
 Assign1_ProgramReview file
 
 Created by Mark Aquiapao on 9/2/2019.
 Copyright © 2019 Mark Aquiapao. All rights reserved.
 
 Rev A by Mark Aquaiapo on 9/5/2019
 Description: Redid initialization for library & recent list.
 Added function for finding keyword in document.
 
 Rev B by Mark Aquiapao on 9/7/2019
 Description: Revised function for searching a substring within a string.
 Added and revsied algrorithm for sorting out the library
 and recent list structures if a document in relecent list
 does not match.
 Added logic to verify entry in dictionary and revised display.
 
 */


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// Prototypes:
bool SearchWord(string, string);
void SwapDocs(void);

// Declare Constants and Globals

const int   DOC_SIZE = 1024, POINTER = 128, MAX_MEM = 3000000, MIN_MEM = 2000000;

struct library {
    string doc;
};

struct recent_list {
    string rl_doc;
};

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
    "LAB"       };

int main()
{
    // Declare main variables
    library lib_document[DOC_SIZE];
    recent_list rl_document[POINTER];
    recent_list* ptr; // pointer for recent list
    ptr = rl_document;
    string key;
    bool valid = false; bool quit = false;
    int mem_size, count;
    
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
            (ptr+i)->rl_doc += rand() % 25 + 'A'; // pick randomly from A-Z
        }
    }
    
    do
    {
        
        cout << "Dictionary: FIRST, CPP, REVIEW, PROGRAM, ASSIGNMENT, CECS, BEACH, ECS,\n";
        cout << "            FALL, SPRING, OS, MAC, LINUX, WINDOWS, LAB \n\n";
        cout << "Enter keyword from dictionary: ";
        cin >> key;
        // Check if Key is in Dictionary
        do
        {
            for(int i=0; i<15; i++)
            {
                if(SearchWord(dictionary[i], key) == true)
                {
                    valid = true;
                }
                else
                    valid = false;
            }
            if(valid == false)
            {
                cout << "Invalid entry! Try again: ";
                cin >> key;
            }
        }while(valid==false);
        
        count = 0;
        for(int pos=0; pos<POINTER; pos++)
        {
            if(SearchWord((ptr+pos)->rl_doc, key)==false)
            { // For all documents that do NOT match keyword:
                cout << "Document ejected...Please wait...\n";
                count++; // document found, increment count
                
                // Save document from library and recent list that will be swapped
                string rl_temp = (ptr+pos)->rl_doc; // Save ejected recent list document
                string lib_temp = lib_document[0].doc; // Save first document from library
                
                // Eject document from recent list and shift other documents
                for(int i=pos; i<POINTER; i++)
                {
                    if(i!=POINTER-1) // delete document that doesn't MATCH and shift the rest
                        (ptr+i)->rl_doc =(ptr+(i+1))->rl_doc;
                    else
                        (ptr+i)->rl_doc = " "; // Empty value for last index
                }
                
                // Shift documents in library up and leave last element empty/null
                for(int j=0; j<DOC_SIZE; j++)
                {
                    if(j!=DOC_SIZE-1) // Shift the library documents up
                        lib_document[j].doc = lib_document[j+1].doc;
                    else
                        lib_document[j].doc = " "; // Empty value for last index
                }
                
                
                // Insert swapped, ejected documents to end of library and recent list
                lib_document[DOC_SIZE-1].doc = lib_temp;
                (ptr+(POINTER-1))->rl_doc = rl_temp;
            }
        }
        
        if(count==0)
            cout << key << ": " << count << " document(s) ejected \n";
        else
            cout << key << ": " << count << " document(s) ejected and reinitialized \n\n";
        
        cout << "Quit program? (Y/N): ";
        cin >> key;
        if(key=="Y" || key=="y")
            quit = true;
        else
            quit = false;
    }while(quit==false);
    
    return 0; // terminate program
    
}

bool SearchWord(string document, string key)
{
    bool found = false;
    if(document.find(key) != string::npos)
        found = true; // key is found in document
    return found;
}
