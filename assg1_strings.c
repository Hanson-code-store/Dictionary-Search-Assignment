/* Fuction file for reading data from an input file into data_t structure. 
 *Created by Tom Hanson (hansont@student.unimelb.edu.au) 09/09/19
 */
#include "assg1_headder.h"


/*Gets key from stdin, one key per line.
 *Returns char pointer to key string if string got, otherwise returns NULL.
 *Requires pointer to key memory allocation as input argument
 */
 char* scanInKey(char* key){
    
    if(fgetstr(key,sizeof(char)*MAX_ENTRY,stdin)){
        return key;
    }
    else{
        free(key);
        return NULL;
    }   
}

/*Gets line from file pointer and removes new line char
 *Returns pointer to string.
 *Requires pointer to allocated string memory, the size of the allocated memory 
 *as an interget and file pointer to input stream as input arguments.
 */
char* fgetstr(char* string, int n, FILE *stream){
    char *result;
    result = fgets(string, n, stream);
    if(!result){
        return(result);
    }
//If newline char is found, replace it with string terminator    
    if(string[strlen(string) - 1] == '\n'){
        string[strlen(string) - 1] = '\0';
    }
    return(string);
}

/*Reads in data from file stream and puts it into a data_t struct.
 *Returns data_t pointer to new data struct.
 *Requires file pointer as an input argument. 
 */
data_t* getData(FILE *ifp){
    int i = 0;
    int j = 0;
    int length = 0;
    char init[MAX_ENTRY] = {'\0'};
    
    
//Allocates required memory    
    char* buffer = (char*)malloc(sizeof(char)*MAX_LINE);
    char* entry = (char*)malloc(sizeof(char)*MAX_ENTRY);
    char* new_char = (char*)malloc(sizeof(char));
    data_t* new = (data_t*)malloc(sizeof(data_t));
    assert(new);
    assert(entry);
    assert(new_char);
    assert(buffer);
    
//Tests if more data can be read, if not, free memory and return NULL    
    if (fgetstr(buffer,sizeof(char)*MAX_LINE,ifp) == NULL){
        free(buffer);
        free(entry);
        free(new_char);
        free(new);
        return NULL;
    }
    
//Looks at ith char within the stored link, if delimiter is found, 
//add pointer to the competed entry to the next array element within the data struct     
    while(buffer[i] != '\0'){
        if(buffer[i] == ','){
            
            entry[length]='\0';
            
            new->fields[j] = entry;
//Allocate and initialise memory for new data entry            
            entry = (char*)malloc(sizeof(char)*MAX_ENTRY);
            memcpy(entry, init, sizeof(entry));
            
            i += 1;
            j += 1;
            length = 0;
           
        }else{
//adds the ith element of the buffer to the current entry string             
            length += 1;
            *new_char = buffer[i];
            entry[length-1] = *new_char;
           
            i += 1; 
            
        }
    }
//enter final entry to data struct and free memory    
    new->fields[j] = entry;
    
    free(new_char);
    free(buffer);
   
    return new;
}
    
    
    
    

