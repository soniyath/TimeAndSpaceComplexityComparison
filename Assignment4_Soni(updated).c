/*
Yatharth Alpeshkumar Soni <soniyat@sheridan.desire2learn.com>
----------------------------------------------------------------------
 */

/* 
 * File:   Assignment4_Soni.c
 * Author: Yatharth Alpeshkumar Soni <soniyat@sheridan.desire2learn.com>
 *
 * Created on July 30, 2019, 7:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

//Prototypes
void randGenerator(int[], int, int, int);
void printArray(int[], int);
void copyArray(int[], int[], int);
void bubbleSort(int[], int);
void insertionSort(int[], int);
void quickSort(int[], int, int);
int partitionMedian (int[], int, int);
int partitionLast (int[], int, int); 
void swap(int *xp, int *yp);

	



int main(int argc, char ** argv) {
    srand(time(0));
    //Getting user inputs
	int numOfInputs, minValue, maxValue, numOfTests;
	printf("Enter size of input for testing: ");
    scanf("%d", &numOfInputs);
    printf("\nEnter min and max values for testing: ");
    scanf("%d %d", &minValue, &maxValue);
    printf("\nEnter the times of runs for testing: ");
    scanf("%d", &numOfTests);
    
	//Creating the arrays for testing
	int randNum[numOfInputs];
    int bubbleArray[numOfInputs];
    int insertionArray[numOfInputs];
    int quickArray[numOfInputs];
    
	
	int i, j, k;
	//Number of tests
	 for(i= 1; i <=numOfTests; ++i){
 	printf("\n");
 	printf("=== Test #%d ===", i);
   	
   	//Assigning random values
	randGenerator(randNum, numOfInputs, minValue, maxValue);
	printf(">> Data to Sort :    ");
	printArray(randNum, numOfInputs);
	
	//Copying the random values into Testing arrays
	copyArray(randNum, bubbleArray, numOfInputs);
	copyArray(randNum, insertionArray, numOfInputs);
	copyArray(randNum, quickArray, numOfInputs);
	
	//Bubble sort portion
	printf(">> Bubble Sort :     ");
	bubbleSort(bubbleArray, numOfInputs);
	printArray(bubbleArray, numOfInputs);
	
	//Insertion sort portion
	printf(">> Insertion Sort :  ");
	insertionSort(insertionArray, numOfInputs);
	printArray(insertionArray, numOfInputs);
	
	
	//quick sort portion
	printf(">> Quick Sort :      ");
	quickSort(quickArray, 0, numOfInputs-1);
	printArray(quickArray, numOfInputs);	
	}	

	//Comparision Task : 2
	int increment, startingSize;
	printf("\n");
	printf("=== Comparison ===");
	printf("\n");
	
	//Getting Inputs for the Comparision
	printf("Enter starting size and increment of input for comparison : ");
    scanf("%d %d", &startingSize, &increment);
    printf("\nEnter min and max values for comparison: ");
    scanf("%d %d", &minValue, &maxValue);
    printf("\nEnter the times of runs for comparison: ");
    scanf("%d", &numOfTests);
	
	
	printf("*. Average running itme of 5 runs each, in ms ");
	printf("\n");
	
	//Clock initialization
	clock_t start, stop;
	
	//Temporary Variable declarations
	int bubbleTime = 0, insertionTime = 0, quickTime = 0;
	int bubbleTemp = 0;
	int insertionTemp = 0;
	int quickTemp = 0;
	i = 0;
	j = 0;
	
	printf("No.	Size	Bubble Sort		Inserion Sort	QuickSort");
	
	//Testing Loop Starts
	for(i = 1; i <= numOfTests; i++){
	int randNew[startingSize]; 
	int bubbleCompare[startingSize];
	int insertionCompare[startingSize];
	int quickCompare[startingSize];

		bubbleTemp, insertionTemp, quickTemp;

		//Actual Checking 5 times
		for(j = 0; j < 5 ; j++){

		//Generating new Random values five times
		randGenerator(randNew, startingSize, minValue, maxValue);
		copyArray(randNew, bubbleCompare, startingSize);
		copyArray(randNew, insertionCompare, startingSize);
		copyArray(randNew, quickCompare, startingSize);
	
			
			//Calculating times
			start = clock();
			bubbleSort(bubbleCompare, startingSize);
			stop = clock(); 
			bubbleTemp += 1000* (stop - start)/CLOCKS_PER_SEC; 
			
			start = clock(); 
			insertionSort(insertionCompare, startingSize); 
			stop = clock(); 
			insertionTemp += 1000* (stop - start)/CLOCKS_PER_SEC; 


			start = clock(); 
			quickSort(quickCompare, 0, startingSize-1); 
			stop = clock(); 
			quickTemp += 1000* (stop - start)/CLOCKS_PER_SEC; 
		}
		bubbleTime = bubbleTemp / 5;
		insertionTime = insertionTemp / 5;
		quickTime = quickTemp / 5;
		
		printf("%d	%d		%d		%d		%d", i, startingSize, bubbleTime, insertionTime, quickTime);
		startingSize += increment;	
	}

    return (0);
}

//Random Value Generator
void randGenerator(int randNum[], int numOfInputs, int minValue, int maxValue){
int i;
int j;
    for(j = 0; j < numOfInputs; ++j){
    	//seg fault...........................
		randNum[j] = (rand() % maxValue + 1 - minValue) + minValue;
	}
	printf("\n");	
}

//Printing entire array
void printArray(int randNum[], int numOfInputs){
	int i;
	for(i = 0; i < numOfInputs; i++){
		printf("%d ", randNum[i]);
	}
	printf("\n");
}

//Copying one array to another
void copyArray(int randNum[], int resultArray[], int numOfInputs){
	int i;
	for(i = 0; i < numOfInputs; i++){
		resultArray[i] = randNum[i];
	}		
}

//Bubble Sorting Algorithm
void bubbleSort(int bubbleArray[], int numOfInputs){
	int comp = 0, swp = 0;
	bool swapped;
	//i = current Vlaue and j = next value
	int i, j;
	for (i = 0; i < numOfInputs-1; i++) {
		swapped = false;
		for (j = 0; j < numOfInputs-i-1; j++) {
			if (bubbleArray[j] > bubbleArray[j+1]) {
				swap(&bubbleArray[j], &bubbleArray[j+1]);
				//swapping the values if current Value >  Next Value
				swapped = true;
				swp++;
			}
			comp++;
		}
		//if swapped == false --> Table is sorted... the algorith ends
		if (swapped == false) break;
	}
}
//Swapping algorithm used in Bubble sort
void swap(int *xp, int *yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

//Insertion Sort Algorithm
void insertionSort(int insertionArray[], int numOfInputs){
	int comp = 0, assg = 0, h;
	//loop where the key is generated and the values are swapped likewise...
	for (h = 1; h < numOfInputs; h++) {
		int key = insertionArray[h];
		int k = h - 1; 
		while (k >= 0 && key < insertionArray[k]) {
			insertionArray[k + 1] = insertionArray[k];
			comp++;
			assg++;
			--k;
		}
		insertionArray[k + 1] = key;
	}
}

//Quick Sort Algorithm
void quickSort(int quickArray[], int low, int numOfInputs){
	if (low < numOfInputs) {
		//returns the pivot -> some random middle value
		int pi = partitionMedian(quickArray, low, numOfInputs); 
		//Sorting elements before the pivot
		quickSort(quickArray, low, pi - 1);
		//Sprtin the elements after the pivot
		quickSort(quickArray, pi + 1, numOfInputs);
	}
}	

//Partition Median Called from the quick Sort Algorithm
int partitionMedian (int arr[], int low, int high) {
	swap(&arr[(low + high)/2], &arr[high]);
	//Calling the Partition Last Algorithm
	return partitionLast(arr, low, high);
}

//Partition Last Algorithm called from the partition Median Algorithm
int partitionLast (int arr[], int low, int high) {
	int pivot = arr[high]; 
	int i = low, j;  
	for (j = low; j <= high- 1; j++)  {
		if (arr[j] <= pivot) {
			swap(&arr[i], &arr[j]); 
			i++;	
		}
	}
	swap(&arr[i], &arr[high]); 
	return i;
}
