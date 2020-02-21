/* Main function file for Assignment 1 COMP20003, stage 1. 
 * Created by Tom Hanson (hansont@student.unimelb.edu.au) 09/09/19
 * This program grabs and stores taxi ride data from an input file. 
 * Seaches through this data can be made by inputing the pick up time into stdin. 
 * Search results are printed to an output file.
 */

#include "assg1_headder.h"

int  main (int argc, char *argv[]){
    FILE *ifp = NULL;
    FILE *ofp = NULL;
    data_t* nextdata = NULL;
    dict_t* dict1 = NULL;
    node_t* found = NULL;
    
    int comparisons = 0;
    
   
//Opening data file
    ifp = fopen(argv[READ_FILE],"r");
    assert(ifp); 
    

    
//Creating Output file
    ofp = fopen(argv[WRITE_FILE],"w");
    assert(ifp); 
    
    
//Creating new dictionary
    dict1 =(dict_t*)newDict();
   	
    
//Reading data from file into BST structure
    nextdata = getData(ifp);
    while(nextdata){
        nodeInsert(dict1,nextdata,PU_DATETIME,PU_DATETIME);
        nextdata = getData(ifp);
    }
    
    
//Reads in keys, for every read key, seacherches BST for match and prints result. 
//Then checks for dupicates and prints them if found.
    char* key = (char*)malloc(sizeof(char)*MAX_ENTRY);
    assert(key);
    key = (char*)scanInKey(key);
    
    
    while(key){
        fprintf(ofp,"%s --> ",key);
        found = dictSearch(dict1,key,&comparisons,PU_DATETIME);
        
//Checks if key is found, prints NOTFOUND if not found, otherwise prints associated data
        if(found == NULL){
            fprintf(ofp,"NOTFOUND\n");
            printf("%s --> %d\n",key,comparisons);
            
        }else{
            printNode1(found,ofp);
            
//Checks for and prints found duplicates
            found = found->dupes;
            while(found != NULL){
                fprintf(ofp,"%s --> ",key);
                printNode1(found,ofp);
                
                found = found->dupes;
               
            }
            printf("%s --> %d\n",key,comparisons);
        }
        
//Scan in next key        
        key = scanInKey(key);
        comparisons = 0;
    }
       
//Close files and free memory    
    fclose(ifp);
    fclose(ofp);
    freeDict(dict1);
    return 0;
}