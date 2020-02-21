/*Fuction file for creating and managing dictionaries. 
 *Created by Tom Hanson (hansont@student.unimelb.edu.au) 09/09/19
 */

#include "assg1_headder.h"


/*Creates a new dictionary. Function returns pointer to dictionary.*/
dict_t* newDict(void){
	dict_t* new_dict;
//Allocates memory for dictionary and initializes values
    new_dict = (dict_t*)malloc(sizeof(dict_t));
	assert(new_dict);
	
	new_dict->root = NULL;
	new_dict->num_elements = 0;
	
	
	return new_dict;
}

/*Inserts new node into BST. 
 * Requires dict_t pointer, data_t pointer and integer sort and 
 * dupelacate keys as arguments.
 */ 
void nodeInsert(dict_t* dict, data_t* data, int sort_key, int dupe_key){
   
    int comp;
    node_t* parent = NULL;
    data_t* temp_data = NULL;
    
    
//Creates and initializes new node  
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    assert(new_node);
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->dupes = NULL; 
    new_node->data = data;
    
    dict->num_elements += 1;
    
    parent = dict->root;

//Check for first node in dictionary    
    if(!parent){
        dict->root = new_node;
        return;
    }
    
    
//Compares sort key of new data to parent data. 
//Then traverses tree until empty spot is found.    
    while(TRUE){
        comp = nodecmp(data->fields[sort_key],
          parent->data->fields[sort_key]);
        
        if(comp<0){
            if(parent->left == NULL){
                parent->left = new_node;
                return;
            }else{
                parent = parent->left;
           }
        
        }else if(comp>0){
            if(parent->right == NULL){
                parent->right = new_node;
                return;
            }else{
                parent = parent->right;
            } 
       
        }else{

//Puts duplicates into a sorted linked list 
            parent->dupes = dupeSort(dupe_key,parent->dupes,new_node);

//Handles special case where new node should be put before the first node 
//in the linked list by switching the data pointers in first 2 nodes.            
            comp = nodecmp(parent->dupes->data->fields[dupe_key],
                   parent->data->fields[dupe_key]);
            
            if(comp<0){
            temp_data = parent->data;
            parent->data = parent->dupes->data;
            parent->dupes->data = temp_data;    
            }
             
            return;
        }
    }
}


/*Sorts duplicates into a linked list based on a sort key.
 *Returns node in first position.
 *Requires an integer sort key and 2 node_t pointers as arguments.
 */
node_t* dupeSort(int sort_key, node_t* parent, node_t* new_node){
    int comp;
    
    if(!parent){
        return new_node;
    }else{
//Compares and sorts elements of linked list
        comp = nodecmp(new_node->data->fields[sort_key],
               parent->data->fields[sort_key]);
        if(comp>0){
            parent->dupes = dupeSort(sort_key,parent->dupes,new_node);
            return parent;
        }else{
            new_node->dupes = parent; 
            return new_node;
        }
    }
}

/*Compares 2 string arguments and returns integer depending on the smaller value*/     
int nodecmp(char* new ,char* parent){
	return strcmp(new,parent);
}

/*Frees all memory associated with a dictionary. 
 *Requires a dict_t pointer as an argument
 */
void freeDict(dict_t* dict){
   freeTree(dict->root);
   free(dict);
}

/*Frees all memory associated with a BST recursively.
 *Requires a node_t pointer as an argument
 */
void freeTree(node_t* parent){
    int i = 0;
    if(! parent){
        
    	return;
    }
//Calls freeTree for children branches then frees memory associated with 
//parent node.     
    freeTree(parent->left);
    freeTree(parent->right);
    freeTree(parent->dupes);
    for(i = 0; i < NUM_FIELD; i++ ){
        free(parent->data->fields[i]);
    }
    free(parent->data);
    free(parent);
}

