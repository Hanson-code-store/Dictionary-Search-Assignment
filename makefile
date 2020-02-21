#Makefile for Assignment 1 COMP20003 
#Created by Tom Hanson (hansont@student.unimelb.edu.au) 09/09/19

all: dict1 dict2

objs = assg1_bstManage.o assg1_strings.o assg1_search.o


#Compilation rules for dict1.exe

dict1 : dict1_main.o $(objs)
	gcc -Wall -g -o dict1 dict1_main.o $(objs) -I.
dict1_main.o : dict1_main.c assg1_headder.h
	gcc -g -c dict1_main.c
    
    
#Compilation rules for dict2.exe 

dict2 : dict2_main.o $(objs)
	gcc -Wall -g -o dict2 dict2_main.o $(objs) -I.
dict2_main.o : dict2_main.c assg1_headder.h
	gcc -g -c dict2_main.c    
    

#Compilation rules for supporting funtions

assg1_bstManage.o : assg1_bstManage.c assg1_headder.h
	gcc -g -c assg1_bstManage.c 
assg1_strings.o : assg1_strings.c assg1_headder.h
	gcc -g -c assg1_strings.c
assg1_search.o : assg1_search.c assg1_headder.h
	gcc -g -c assg1_search.c
    

.PHONY : clean
clean :
	rm dict1.exe dict2.exe dict1_main.o dict2_main.o $(objs)



















