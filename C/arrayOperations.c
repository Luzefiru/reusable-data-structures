/**
 * @file ArrayOperations.c
 * @author functions definitions by Luzefiru, main & function prototypes by Wayne Dayata of DCISM 2022-2023
 * @brief implementations on different array functions and Selection Sort {sortArray}
 * @version 0.1
 * @date 2022-12-01
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 10

/* FUNCTION PROTOTYPES - Implementations begin at line 190 */
void initialize(int arr[], int* count);
void display(int arr[], int count);
int searchElem(int arr[], int count, int elem);
int insertLast(int arr[], int* count, int elem);
int insertFirst(int arr[], int* count, int elem);
int insertAtPos(int arr[], int* count, int elem, int pos);
int removeLast(int arr[], int* count);
int removeFirst(int arr[], int* count);
int removeAtPos(int arr[], int* count, int pos);
int removeElem(int arr[], int* count, int elem);

int getRange(int arr[], int count);
int* getEven(int arr[], int count);
int isSortedAscending(int arr[], int count);
void moveSmallestToFirst(int array[], int count);
void sortArray(int arr[], int count);

int main(void) {

    int array[MAX];
    int count;

    //initialize the array
    initialize(array, &count);

    //variables for command selection, number input, and position selection
    int command;
    int elem, pos;

    //return value
    int ret;
    
    //for the array of even numbers (command #12)
    int *even;
    
    
    do {
      system("cls");
      printf("\n-------------------");
      printf("\n 1  - Initialize/reset array");
      printf("\n 2  - Display array");
      printf("\n 3  - Search for an element");
      printf("\n 4  - Insert new element at the end");
      printf("\n 5  - Insert new element at the start");
      printf("\n 6  - Insert new element at a custom position");
      printf("\n 7  - Delete an element at the end");
      printf("\n 8  - Delete an element at the start");
      printf("\n 9  - Delete an element at a custom position");
      printf("\n 10 - Delete a specific element");
      printf("\n");
      printf("\n 11 - Get the range");
      printf("\n 12 - Get the even numbers");
      printf("\n 13 - Check if sorted in ascending order");
      printf("\n 14 - Moving the smallest element to the beginning of the array");
      printf("\n 15 - Sort array");
      printf("\n");
      printf("\n 0  - Exit");
      printf("\n-------------------");
      printf("\nCOMMAND #: ");
      scanf("%d", &command);
      
      switch(command) {
        case 1:
          initialize(array, &count);
          printf("\nArray initialized!");
          break;
        case 2:
          display(array, count);
          printf("\n");
          break;
        case 3:
          printf("Enter element: ");
          scanf("%d", &elem);
          ret = searchElem(array, count, elem);
          if(ret!=-1){
        	printf("\nElement found at index %d.",ret);
		  }else{
		  	printf("\nElement not found.");
		  }
          printf("\n");
          break;
        case 4:
          printf("Enter element: ");
          scanf("%d", &elem);
          ret = insertLast(array, &count, elem);
          if(ret!=0){
        	printf("\nElement successfully inserted!");
		  }else{
		  	printf("\nOperation failed.");
		  }
          break;
        case 5:
          printf("Enter element: ");
          scanf("%d", &elem);
          ret = insertFirst(array, &count, elem);
          if(ret!=0){
        	printf("\nElement successfully inserted!");
		  }else{
		  	printf("\nOperation failed.");
		  }
		  break;
 		case 6:
          printf("Enter element: ");
          scanf("%d", &elem);
          printf("Enter position: ");
          scanf("%d", &pos);
          ret = insertAtPos(array, &count, elem, pos);
          if(ret!=0){
        	printf("\nElement successfully inserted!");
		  }else{
		  	printf("\nOperation failed.");
		  }
		  break;
        case 7:
          ret = removeLast(array, &count);
          if(ret!=0){
        	printf("\nElement successfully removed!");
		  }else{
		  	printf("\nOperation failed.");
		  }
          break;
        case 8:
          ret = removeFirst(array, &count);
          if(ret!=0){
        	printf("\nElement successfully removed!");
		  }else{
		  	printf("\nOperation failed.");
		  }
          break;
        case 9:
          printf("Enter position: ");
          scanf("%d", &pos);
          ret = removeAtPos(array, &count, pos);
          if(ret!=0){
        	printf("\nElement successfully removed!");
		  }else{
		  	printf("\nOperation failed.");
		  }
          break;
        case 10:
          printf("Enter element: ");
          scanf("%d", &elem);
          ret = removeElem(array, &count, elem);
          if(ret!=0){
        	printf("\nElement successfully removed!");
		  }else{
		  	printf("\nOperation failed.");
		  }
          break;
        case 11:
          printf("\nThe range is %d", getRange(array, count));
          break;
        case 12:
          even = getEven(array, count);
          printf("\nEven numbers: ");
          for(pos=0; even[pos]!=-1; pos++){
          	printf("%d ",even[pos]);
		  }
		  break;
		case 13:
		  ret = isSortedAscending(array, count);
          if(ret==1){
        	printf("\nElements are sorted.");
		  }else{
		  	printf("\nElements are not sorted.");
		  }
		  break;
		case 14:
		  moveSmallestToFirst(array, count);
          printf("\nSmallest element transferred to beginning of array.");
          break;
        case 15:
		  sortArray(array, count);
          printf("\nArray is sorted!");
          break;
      }
      if(command!=0){
      	printf("\nPress any key to continue.");
        getch();	
	  }
    } while (command != 0);

    return 0;
}

/* WRITE YOUR CODES HERE! */
void initialize(int arr[], int* count){
	for (int i = 0; i < *count; i++)
        arr[i] = 0;

    *count = 0;
}

void display(int arr[], int count){
	if (count == 0)
        printf("List is empty");
    else
        printf("Elements: ");
        for (int i = 0; i < count; i++) // algorithm
            (i != count-1) ? printf("%d ", arr[i]) : printf("%d", arr[i]); 
}

int searchElem(int arr[], int count, int elem){
	for (int i = 0; i < count; i++) // algorithm
        if (arr[i] == elem)
            return i;
    
    return -1;
}

int insertLast(int arr[], int* count, int elem){
    if (searchElem(arr, *count, elem) != -1) // error catcher
    {
        printf("Element already exists");
        return 0;
    }
    if (*count == MAX) // error catcher
        return 0;

	arr[(*count)++] = elem; // algorithm
    
    return 1;
}

int insertFirst(int arr[], int* count, int elem){
	if (*count == MAX) // error catcher
    {
        printf("List is full");
        return 0;
    }
    if (searchElem(arr, *count, elem) != -1) // error catcher
    {
        printf("Element already exists");
        return 0;
    }
    
    for (int i = *count; i >= 1; i--) // algorithm
        arr[i] = arr[i-1];

    arr[0] = elem;
    (*count)++;

    return 1;
}

int insertAtPos(int arr[], int* count, int elem, int pos){
	  if (*count == MAX) // error catcher
    {
        printf("List is full");
        return 0;
    }
    if (*count == 0 && pos == 0) // edge case catcher
    {
      arr[0] = elem;
      (*count)++;
      return 1;
    }
    if (0 > pos || pos > *count - 1) // error catcher
    {
        printf("Invalid position"); 
        return 0;
    }
    if (searchElem(arr, *count, elem) != -1) // error catcher
    {
        printf("Element already exists");
        return 0;
    }

    for (int i = *count; i >= pos; i--) // algorithm
        arr[i] = arr[i-1];

    arr[pos] = elem;
    (*count)++;

    return 1;
}

int removeLast(int arr[], int* count){
	if (*count == 0) // error catcher
    {
        printf("List is empty");
        return 0;
    }
    
    (*count)--;
    return 1;
}

int removeFirst(int arr[], int* count){
	if (*count == 0) // error catcher
    {
        printf("List is empty");
        return 0;
    }

    for (int i = 0; i < *count - 1; i++) // algorithm
        arr[i] = arr[i+1];
    
    (*count)--;
    return 1;
}

int removeAtPos(int arr[], int* count, int pos){
    if (*count == 0) // error catcher
    {
        printf("List is empty");
        return 0;
    }
    if (0 > pos || pos > *count - 1) // error catcher
    {
        printf("Invalid position"); 
        return 0;
    }

	for (int i = pos; i < *count; i++) // algorithm
        arr[i] = arr[i+1];

    (*count)--;
}

int removeElem(int arr[], int* count, int elem){
    if (*count == 0) // error catcher
    {
        printf("List is empty");
        return 0;
    }
	if (searchElem(arr, *count, elem) == -1) // error catcher
    {
        printf("Element does not exist");
        return 0;
    }

    for (int i = 0; i < *count; i++)
    {
        if (arr[i] == elem)
        {
            for (int j = i; j < *count; j++) // algorithm
                arr[j] = arr[j+1];
            (*count)--;
        }
    }

    return 1;
}

int getMin(int arr[], int count) // helper function for getRange
{
    int min = arr[0];
    for (int i = 1; i < count; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }

    return min;
}

int getMax(int arr[], int count) // helper function for getRange
{
    int max = arr[0];
    for (int i = 1; i < count; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

int getRange(int arr[], int count){
	if (count == 1) // edge case
        return arr[0];
    if (count == 0) // error catcher
        return 0;

    return getMax(arr, count) - getMin(arr, count);
}

int* getEven(int arr[], int count){
    if (count == 0) // error catcher
    {
        printf("ERROR: The array is empty.");
        exit(EXIT_FAILURE);
    }

    int even_numbers = 0;
	for (int i = 0; i < count; i++) // counts the even numbers for calloc
    {
        if (arr[i] % 2 == 0)
        {
            even_numbers++;
        }
    }

    int *newArr = calloc(even_numbers + 1, sizeof(int));
    int newArr_index = 0;

    for (int i = 0; i < count; i++) // puts the even numbers into the allocated array
    {
        if (arr[i] % 2 == 0)
        {
            newArr[newArr_index++] = arr[i];
        }
    }

    newArr[newArr_index] = -1;

    return newArr;
}

int isSortedAscending(int arr[], int count){
    if (count == 0) return 0; // error catcher

	for (int i = 0; i < count; i++)
        if (i != count-1 && arr[i] > arr[i+1])
            return 0;
    
    return 1;
}

void moveSmallestToFirst(int arr[], int count){
	int tmp = arr[0];
    int min = getMin(arr, count);

    for (int i = 0; i < count; i++)
    {
        if (arr[i] == min)
        {
            arr[0] = arr[i];
            arr[i] = tmp;

            return; // stop early for optimization
        }
    }
}

void sortArray(int arr[], int count){
	for (int i = 0; i < count-1; i++)
    {
        // shift starting pos by i and decrement count by the same amount to isolate area (no segfault)
        moveSmallestToFirst(arr+i, count-i); 
    }
}