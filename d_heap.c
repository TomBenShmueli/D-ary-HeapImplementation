#include <stdio.h>
/*
 * The Open University of Israel - Introduction to Algorithms and Data Structures (20407) - Instructor Assignment #13:
 *   General note - following the course's practices, the first element in the array will be assigned to index 1.
 *   Let A be an array, Length[A] = n. We can represent a d-heap with A by using the following logic:
 *   Each node has d children. The root's children will be found at the array's 2 to d+1 indexes:
 *   A = [ROOT|CHILD1|CHILD2|...|CHILDd|...]
 *      CHILD1's children will be found at CHILDd+1 to CHILDd+d indexes.
 *      CHILD2's children will be found at CHILDd+d+1 to CHILDd+d+d indexes.
 *      Generalizing this pattern allows us to understand the positioning of the child nodes:
 *      For an array member k, 1 <= k < floor(n/2), the children of A[k] will be found at d*k+1 to d*k+d.
 *
 *
 *
 */
}
