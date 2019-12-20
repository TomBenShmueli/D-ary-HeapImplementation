#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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
 *
 *
 */

#define HEAP_UNDERFLOW INT_MIN
#define MAX_PATH_SIZE 500
#define MAX_ALLOWED_SIZE 1000
#define FATHER(i,d) (i-1)/d //get father macro - support for all d values.
#define SON(i,k,d) (d*i + k) + 1 //get son macro - support for all d values.

typedef struct Heap {
    int *array; // numbers the heap stores
    int d; // number of sons per node
    int n; // heap size
} dheap; // heap data structure definition



//declarations
void heapify(int *array, int n ,int d ,int i); //max heapify for d sons.
int extractMax(int *array, int n ,int d); //extract max.
void insert(int *array, int n ,int d ,int newValue); //insert a node to the heap.
void increaseKey(int *array, int n ,int d, int i, int newValue); //add a positive addition to a heap element value.
void removeNode(int *array, int n ,int d, int i); //removes a node from the heap.
void printArray(int *array, int n ,int d); // general purpose print array function.
void swap(int *a, int *b); //swaps two integers


//************************implementations**************************//

//max-heapify as given on chapter 6.2 on CLRS (page 109 on the openU edition), adapted to handle d sons.
//runtime is Theta of d*log(d,n)
void heapify(int *array, int n ,int d,int i)
{
    int largest = i; //variables
    int son = -1;

    for(int index = 0 ; index < d ; index++) // loop through all the node's child and compare to the assumed largest element
    {
        son = SON(i,index,d); //get the indexTH son
        if(son < n && array[son] > array[i]) //evaluate the value and switch if necessary
        {
                largest = son;
        }
    }

    if (largest != i) //swap son and root
    {
        swap(&(array[i]), &(array[largest]));
        printf("Swapped %d,%d\n",array[i],array[largest]);
        heapify(&array, n,d ,largest);
    }
}
/*
//extract-max as given on chapter 6.2 on CLS (page 109 on the openU edition)
//runtime is Theta of d*log(d,n) + 4 = Theta of d*log(d,n)
int extractMax(int *array, int n ,int d)
{
    int max = -1;
    if (heapnode->n < 1)
    {
        printf("Error: Heap underflow.");
        return HEAP_UNDERFLOW;
    }
    max = heapnode->array[0]; //get max element & extract it from the heap
    heapnode->array[0] = heapnode->array[heapnode->n - 1];
    (heapnode->n)--;
    heapify(heapnode,1); //fix heap
    return max;
}

//insert a new node to the heap
//runtime is the same as increaseKey function runtime. Theta log(d,n) + Theta(1) = Theta log(d,n)
void insert(int *array, int n ,int d,int newValue)
{
    (heapnode->n)++;
    heapnode->array[heapnode->n] = INT_MIN;
    increaseKey(heapnode,heapnode->n,newValue);
}

// increase a node's value and place it in the correct location
// iteration is made through the heaps floors, therefore the runtime is Theta of log(d,n)
void increaseKey(int *array, int n ,int d, int i ,int newValue)
{
    if (newValue <= heapnode->array[i]) //check new desired key value
    {
        printf("Error: new value is lower or equal to the current key value. Please use DECREASEKEY for this operation.");
        return;
    }
    heapnode->array[i] = newValue;
    while( i > 1 && heapnode->array[FATHER(i,heapnode->d)] < heapnode->array[i]) //loop through the heap's floors
    {
        swap( &(heapnode->array[FATHER(i,heapnode->d)]), &(heapnode->array[i]) );
        i = FATHER(i,heapnode->d); //update index
    }
}

// removes a node from the heap
// runtime is identical to heapify, Theta of log(d,n
void removeNode(int *array, int n ,int d, int i)
{
    heapnode->array[i] = heapnode->array[heapnode->n]; //overwrite the removed element and decrease heap size by one
    (heapnode->n)--;
    heapify(heapnode,0); //fix heap
}
*/
//prints the array to the console
void printArray(int *array, int n ,int d)
{
    for (int i = 0 ; i < n ;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}

//self explanatory swap function for two integers
void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a=*b;
    *b=tmp;
}

//********************************MAIN***************************************//

/*
 * Driver function
 */
int main()
{
    int d = 0; // number of sons
    int currentChar = 0; //file pointer
    int length = 0; //array len var for malloc
    int index = 0; // iteration variable

    char *path[MAX_PATH_SIZE]; //pointers
    FILE *filePointer;
    while(1)
    {
        printf("Enter the number of sons per node (bigger than 2):\n");
        scanf("%d", &d);
        if (d >= 2)
            break;
    }
/*
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
    */

    int inputArr[] = {1,6,7,3,4,5,22,34,11,9,2,3,10,8,31,4}; //16
    int n = 16;
    length = sizeof(inputArr)/sizeof(inputArr[0]);

    struct Heap dheap = {inputArr,d,16}; //initialize a d-ary heap
    printArray(inputArr , 16, d );
    for (int j = 0 ; j < n/2 ; j++) {
        heapify(inputArr, n,d,j);
        printArray(inputArr,n,d);
    }

}
