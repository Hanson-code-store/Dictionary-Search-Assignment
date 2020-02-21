/*Fuction file for seaching and printing node data. 
 *Created by Tom Hanson (hansont@student.unimelb.edu.au) 09/09/19
 */

#include "assg1_headder.h"

/*Finds requested node in dictionary
 *Returns the node_t pointer of the requested data. If data not found returns NULL.
 *Requires dict_t pointer, pointer to key string, int pointer to comparisons 
 *variable and int that denotes the search key.
 */
node_t* dictSearch(dict_t* dict,  char* key, int* comparisons, int search_field){      
	node_t* current_node = dict->root;
	int comp = 0;
	
	while(current_node){
//Compares key to current node data and traverses tree until found
//If parent becomes NULL before nodecmp finds a match, returns NULL 
        comp = nodecmp(key,current_node->data->fields[search_field]);
        
        *comparisons = *comparisons + 1; 
		if(comp==0){	
			return current_node;
		}else if(comp<0){
			current_node = current_node->left;
			
		}else{
			current_node = current_node->right;
        }
	}
    return NULL;
}

/*Funtion to print data required in stage 1.
 *Requires node_t pointer of node to print and file pointer to output file 
 *as input arguments
 */
void printNode1(node_t* node, FILE *ofp){
    
    fprintf(ofp,"VendorID: %s || ",node->data->fields[VENDOR_ID]);
    fprintf(ofp,"passenger_count: %s || ",node->data->fields[PASSENGER_COUNT]);
    fprintf(ofp,"trip_distance: %s || ",node->data->fields[TRIP_DISTANCE]);
    fprintf(ofp,"RatecodeID: %s || ",node->data->fields[RATECODE_ID]);
    fprintf(ofp,"store_and_fwd_flag: %s || ",node->data->fields[STORE_FLAG]);
    fprintf(ofp,"PULocationID: %s || ",node->data->fields[PU_LOCATION]);
    fprintf(ofp,"DOLocationID: %s || ",node->data->fields[DO_LOCATION]);
    fprintf(ofp,"payment_type: %s || ",node->data->fields[PAYMENT_TYPE]);
    fprintf(ofp,"fare_amount: %s || ",node->data->fields[FARE_AMOUNT]);
    fprintf(ofp,"extra: %s || ",node->data->fields[EXTRA]);
    fprintf(ofp,"mta_tax: %s || ",node->data->fields[MTA_TAX]);
    fprintf(ofp,"tip_amount: %s || ",node->data->fields[TRIP_AMOUNT]);
    fprintf(ofp,"tolls_amount: %s || ",node->data->fields[TOLLS_AMOUNT]);
    fprintf(ofp,"improvement_surcharge: %s || ",node->data->fields[IMP_SURCHARGE]);
    fprintf(ofp,"total_amount: %s || ",node->data->fields[TOTAL_AMOUNT]);
    //fprintf(ofp,"PUdatetime: %s || ",node->data->fields[PU_DATETIME]);
    fprintf(ofp,"DOdatetime: %s || ",node->data->fields[DO_DATETIME]);
    fprintf(ofp,"trip_duration: %s ||\n",node->data->fields[TRIP_DURATION]);       
            
 }

/*Funtion to print data required in stage 2.
 *Requires node_t pointer of node to print and file pointer to output file 
 *as input arguments
 */
void printNode2(node_t* node, FILE *ofp){
    
    fprintf(ofp,"%s\n",node->data->fields[PU_DATETIME]);
    return;
}