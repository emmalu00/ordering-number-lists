/*
 * Author: Emma Lucas
 * project2.c
 *
 * This program takes in multiple lists of numbers from a text file.
 * The program then sorts the lists by length from least to greatest, 
 * and sorts the numbers in each list from least to greatest.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sortLists(int** list, int length);
void swapLists(int** list1, int** list2);
void sortElements(int* list, int length);
void swapElements(int* e1, int* e2);
void sortElements(int* list, int length);
void printarray(int* list, int length);

int main(int argc, char* argv[])
{
    if (argc != 2)
    {

        printf("Proper command line arguments were not supplied.\n");
        return 1;
    }

    FILE *in = fopen(argv[1], "r");
    char buffer[1000];
    int numbers[1000];
    if (in != NULL)
    {
        fgets(buffer, 1000, in);
        int numLists = atoi(buffer);
        int** matrix = malloc(numLists*sizeof(int*));
        for (int i = 0; i < numLists; i++)
        {
            fgets(buffer, 1000, in);
            int numElements = atoi(strtok(buffer, ": "));
            matrix[i] = malloc((numElements+1)*sizeof(int));
            matrix[i][0] = numElements;
            for (int j = 1; j < numElements + 1; j++)
            {
                matrix[i][j] = atoi(strtok(NULL, ", "));
            }
        }
        printf("Before sorting: \n");
        for (int i = 0; i < numLists; ++i)
        {
            printarray(matrix[i], matrix[i][0]);
        }
        printf("\n");
        //sorting numbers and then lists
        for (int i = 0; i < numLists; ++i)
        {
            sortElements(matrix[i], matrix[i][0]);
        }
        sortLists(matrix, numLists);
        //printing the jagged array
        printf("After sorting: \n");
        for (int i = 0; i < numLists; ++i)
        {
            printarray(matrix[i], matrix[i][0]);
        }
        //freeing memory in the jagged array
        for (int i = 0; i < numLists; ++i)
        {
            free(matrix[i]);
        }
        free(matrix);
    }
    fclose(in);
    return 0;
}

/*
 * Sorts the lists in the matrix from least amount of elements
 * to greatest amount of elements, using selection sort.
 *
 * int** list: 2D jagged array thats holds the lists of numbers
 * length: number of lists in the matrix
 */
void sortLists(int** list, int length)
{
    int minIndex;
    for (int i = 0; i < length; ++i)
    {
        minIndex = i;
        for (int j = i + 1; j < length; ++j)
        {
            if (list[j][0] < list[minIndex][0])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swapLists(&list[minIndex], &list[i]);
        }
    }
}

/*
 * Swaps two arrays/lists. 
 *
 * int** list1: first list
 * int** list2: second list
 */
void swapLists(int** list1, int** list2)
{
    int* temp = *list1;
    *list1 = *list2;
    *list2 = temp;
}

/*
 * Sorts the elements in the list from least to greatest,
 * using selection sort.
 *
 * int* list: array thats holds the lists of numbers
 * length: number of elements in the list
 */
void sortElements(int* list, int length)
{
    int minIndex;
    for (int i = 1; i < length + 1; ++i)
    {
        minIndex = i;
        for (int j = i + 1; j < length + 1; ++j)
        {
            if (list[j] < list[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swapElements(&list[minIndex], &list[i]);
        }
    }
}

/*
 * Swaps two elements. 
 *
 * int** e1: first element
 * int** e2: second element
 */
void swapElements(int* e1, int* e2)
{
    int temp = *e1;
    *e1 = *e2;
    *e2 = temp;
}

/*
 * Prints all elements in a list/array. 
 *
 * int* list: list being printed
 * int length: length of list
 */
void printarray(int* list, int length) 
{
    int* ptr = &list[1];
    while (ptr < list + length + 1) {
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");
}