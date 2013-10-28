//
//  sorting_main.c
//  ECE368PA1
//
//  Created by Jack Hammons on 9/15/13.
//  Copyright (c) 2013 Jack Hammons. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

long * Load_File(char *Filename, int *Size);
int Save_File(char *Filename, long *Array, int Size);
void Shell_Insertion_Sort_Seq1(long *Array, int Size, double *N_Comp, double *N_Move);
void Shell_Bubble_Sort_Seq1(long *Array, int Size, double *N_Comp, double *N_Move);
void Shell_Insertion_Sort_Seq2(long *Array, int Size, double *N_Comp, double *N_Move);
void Shell_Bubble_Sort_Seq2(long *Array, int Size, double *N_Comp, double *N_Move);
int Print_Seq_1(char *Filename, int Size);
long * create_sequence_1(int Size, int * sequenceSize);
int Print_Seq_2(char *Filename, int Size);
long * create_sequence_2(int Size, int * sequenceSize);


int main(int argc, const char * argv[])
{
    
    char * sequenceNumber = (char*)argv[1]; // 1/2
    
    char * insertOrBubble = (char*)argv[2]; // i/b
    
    char * inputFile = (char*)argv[3]; // input file
    
    char * sequenceOutputFile = (char*)argv[4]; // sequence output
    
    char * sortedOutputFile = (char*)argv[5]; // sorted output
    
    
    double N_Comp = 0;
    
    double N_Move = 0;
    
    int Size = 0;
    
    
    double timeOne = clock();
    
    long * Array = Load_File(inputFile, &Size);

    //Print the selected sequence to a file
    if (strcmp(sequenceNumber,"1") ==0 ) {
        Print_Seq_1(sequenceOutputFile, Size);
    }
    else if (strcmp(sequenceNumber,"2") == 0) {
        Print_Seq_2(sequenceOutputFile, Size);
    }
    
    double timeTwo = clock();
    
    
    if (strcmp(sequenceNumber,"1") == 0 ) {
        
        if (strcmp(insertOrBubble,"i") == 0 ) {
            
            Shell_Insertion_Sort_Seq1(Array, Size, &N_Comp, &N_Move);
            
        }
        
        else if (strcmp(insertOrBubble,"b") == 0) {
            
            Shell_Bubble_Sort_Seq1(Array, Size, &N_Comp, &N_Move);
            
        }
        
        
    }
    
    else if (strcmp(sequenceNumber,"2") == 0) {
        
        if (strcmp(insertOrBubble,"i") == 0 ) {
            
            Shell_Insertion_Sort_Seq2(Array, Size, &N_Comp, &N_Move);
            
        }
        
        else if (strcmp(insertOrBubble,"b") == 0) {
            
            Shell_Bubble_Sort_Seq2(Array, Size, &N_Comp, &N_Move);
            
        }
        
    }
    
    
    double timeThree = clock();
    
    
    Save_File(sortedOutputFile, Array, Size);
    
    double timeFour = clock();
    
    free(Array);
    
    double IOTime = (timeTwo - timeOne) + (timeFour - timeThree);
    
    double sortingTime = (timeThree - timeTwo);
    
    
    printf("Number of comparisons: %.4le\n", N_Comp);
    printf("Number of moves: %.4le\n", N_Move);
    printf("I/O time: %.4le\n", IOTime/CLOCKS_PER_SEC);
    printf("Sorting time: %.4le\n", sortingTime/CLOCKS_PER_SEC);
    
    return 0;
}

