#include <stdio.h>
#include <stdlib.h>
/*
 * The Open University of Israel - Introduction to Algorithms and Data Structures (20407) - Instructor Assignment #13:
 *   General note - following the course's practices, the first element in the array will be assigned to index 1.
 *   Let A be an array, Length[A] = n. We can represent a d-heap with A by using the following logic:
 *   Each node has d children. The root's children will be found at the array's 2 to d+1 indexes:
 *   A = [ROOT|CHILD1|CHILD2|...|CHILDd|...]
 *      CHILD1's children will be found at CHILDd+1 to CHILDd+d indexes.
 *      CHILD2's children will be found at CHILDd+d+1 to CHILDd+d+d indexes.
 *      Generalizing this pattern allows us to understand the positioning of the child nodes:
 *      For an array member k, 1 <= k < floor(n/2), the children of A[k] will be found at d*k to (d*k+d) -1.
 *
 *
 *
 */

#define MAX_PATH_SIZE 500

typedef enum {false,true} bool;

//declarations
void heapify(int *heap,int d);
int extractMax(int *heap,int d);
void insert(int *heap,int d, int newValue);
void increaseKey(int *heap, int d, int addition);
void removeNode(int *heap,int d);

/*
 * Driver function
 */
int main()
{
    int d = 0; // number of sons
    int currentChar = 0; //file pointer
    int length = 0; //array len var for malloc
    int index = 0; // iteration variable
    int *dheap; // array pointer

    char *path = malloc(MAX_PATH_SIZE); //pointers
    FILE *filePointer;
    while(true)
    {
        printf("Enter the number of sons per node (bigger than 2):\n");
        scanf("%d", &d);
            if (d >= 2)
                break;
    }

    printf("Enter the text file path containing the array:"); //read from file
    scanf("%s",path);
    filePointer = fopen(path,"r");
    if (filePointer != NULL) //file not null
    {
        while((currentChar = getc(filePointer)) != EOF) //count elements for dynamic allocation
        {
            if (currentChar > 47 && currentChar < 58)
                length++;
        }

        dheap = malloc(sizeof(int)*length);
        if(dheap == NULL) // memory allocation check
        {
            printf("Runtime error found: Memory allocation error.");
            exit(EXIT_FAILURE);
        }

        fseek(filePointer,0,SEEK_SET); //set pointer

        while((currentChar = getc(filePointer)) != EOF) //fill array with values
        {
            if (currentChar > 47 && currentChar < 58)
                dheap[index] = currentChar;
            index++;
        }
    }

}