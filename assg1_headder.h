/* Headder file for Assignment 1 COMP20003. Tom Hanson 09/09/19 */
#ifndef DICT1_DEFS_H
#define DICT1_DEFS_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define VENDOR_ID 0 
#define PASSENGER_COUNT 1
#define TRIP_DISTANCE 2
#define RATECODE_ID 3
#define STORE_FLAG 4
#define PU_LOCATION 5
#define DO_LOCATION 6
#define PAYMENT_TYPE 7
#define FARE_AMOUNT 8
#define EXTRA 9
#define MTA_TAX 10
#define TRIP_AMOUNT 11
#define TOLLS_AMOUNT 12 
#define IMP_SURCHARGE 13
#define TOTAL_AMOUNT 14
#define PU_DATETIME 15
#define DO_DATETIME 16
#define TRIP_DURATION 17

#define MAX_ENTRY 129
#define MAX_LINE 2210
#define NUM_FIELD 18

#define TRUE 1
#define FALSE 0
#define READ_FILE 1
#define WRITE_FILE 2

/*Type defining structs for all functions */
typedef struct dictionary dict_t;
typedef struct node node_t;
typedef struct data data_t;


struct dictionary {
    int num_elements;
	node_t* root;
	
};

struct node {
	
    node_t* left;
    node_t* right;
    node_t* dupes; 
    data_t* data;
};

struct data{
	char* fields[NUM_FIELD];
};


/* Headers for assg1_bstManage.c */
dict_t* newDict(void);
void nodeInsert(dict_t*, data_t*, int, int);
node_t* dupeSort(int , node_t*, node_t*);

void freeDict(dict_t*);
void freeTree(node_t*);
int nodecmp(char*, char*);

/* Headers for assg1_getStrings.c */
data_t* getData(FILE *ifp);
char* scanInKey(char*);
char* fgetstr(char*, int, FILE *stream);

/* Headers for assg1_search.c */
node_t* dictSearch(dict_t*, char*, int*, int);
void printNode1(node_t*, FILE *ofp);
void printNode2(node_t*, FILE *ofp);


#endif
