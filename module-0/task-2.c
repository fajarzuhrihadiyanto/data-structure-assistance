/**
 * Second Assignment of Module 0 Data Structure
 * Implement several function with dynamic array :
 * - insert at -> function to insert an element to a given list at a certain index
 * - remove at -> function to remove an element from a given list at a certain index
 *
 * @author Fajar Zuhri Hadiyanto
 * @version 1.0
 * @since March 20th 2021
 * */

// IMPORT PACKAGE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DEFINE DYNAMIC ARRAY
typedef struct dynamicarr_t {
    int *_arr;
    unsigned _size, _capacity;
} DynamicArray;

// PROTOTYPING
bool dArray_isEmpty(DynamicArray *darray);
void dArray_init(DynamicArray *darray);
void dArray_insertAt(DynamicArray *darray, unsigned index, int value);
void dArray_removeAt(DynamicArray *darray, unsigned index);

// MAIN FUNCTION
int main(){
    // PREPARE THE ARRAY
    DynamicArray myArray;
    dArray_init(&myArray);

    // INSERT VALUE OF AN ARRAY
    for(int i = 0; i < 5; i++){
        dArray_insertAt(&myArray, i, i+1);
    }

    // PRINT VALUE OF AN ARRAY
    for(int i = 0; i < myArray._size; i++){
        printf("%d\n", myArray._arr[i]);
    }
    printf("==========\n");

    // INSERT VALUE TO OUT RANGE INDEX
    dArray_insertAt(&myArray, 10, 20);

    // PRINT VALUE OF AN ARRAY
    for(int i = 0; i < myArray._size; i++){
        printf("%d\n", myArray._arr[i]);
    }
    printf("==========\n");

    // INSERT VALUE TO A CERTAIN INDEX OF AN ARRAY
    dArray_insertAt(&myArray, 3, 67);

    // PRINT VALUE OF AN ARRAY
    for(int i = 0; i < myArray._size; i++){
        printf("%d\n", myArray._arr[i]);
    }
    printf("==========\n");

    // REMOVE ELEMENT ARRAY AT A CERTAIN INDEX
    dArray_removeAt(&myArray, 3);

    // PRINT VALUE OF AN ARRAY
    for(int i = 0; i < myArray._size; i++){
        printf("%d\n", myArray._arr[i]);
    }
    printf("==========\n");

    // REMOVE ELEMENT ARRAY AT A CERTAIN INDEX
    dArray_removeAt(&myArray, 5);

    // PRINT VALUE OF AN ARRAY
    for(int i = 0; i < myArray._size; i++){
        printf("%d\n", myArray._arr[i]);
    }
    printf("==========\n");

    return 0;
}

/**
 * dArray_isEmpty
 * Used to check if a DynamicArray object/instance is empty or not
 *
 * @param darray DynamicArray object/instance
 * @return (bool) true if size of darray is 0, else false
 */
bool dArray_isEmpty(DynamicArray *darray) {
    return (darray->_size == 0);
}

/**
 * dArray_init
 * Used for dynamic array initialization
 *
 * @param darray DynamicArray object/instance
 */
void dArray_init(DynamicArray *darray)
{
    darray->_capacity = 2u;
    darray->_size = 0u;
    darray->_arr = (int*) malloc(sizeof(int) * 2);
}

/**
 * dArray_insertAt
 * Used to insert an int data to a certain index of a given dynamic array
 *
 * @param darray DynamicArray object/instance
 * @param index index of given dynamic array to be added by some value
 * @param value int type of a value to be added to a given dynamic array
 */
void dArray_insertAt(DynamicArray *darray, unsigned index, int value){
    if (darray->_size + 1 > darray->_capacity) {
        unsigned it;
        darray->_capacity *= 2;
        int *newArr = (int*) malloc(sizeof(int) * darray->_capacity);

        for (it=0; it < darray->_size; ++it)
            newArr[it] = darray->_arr[it];

        int *oldArray = darray->_arr;
        darray->_arr = newArr;
        free(oldArray);
    }

    if(index > darray->_size){
        darray->_arr[darray->_size++] = value;
    } else {
        for(unsigned i = darray->_size++; i > index; i--){
            darray->_arr[i] = darray->_arr[i-1];
        }
        darray->_arr[index] = value;
    }

}

/**
 * dArray_removeAt
 * Used to remove an int data from a certain index of a given dynamic array
 *
 * @param darray DynamicArray object/instance
 * @param index index of given dynamic array to be removed
 */
void dArray_removeAt(DynamicArray *darray, unsigned index){
    if(!dArray_isEmpty(darray)){
        if(index < darray->_size){
            for(unsigned i = index; i+1 < darray->_size; i++){
                darray->_arr[i] = darray->_arr[i+1];
            }

            darray->_size--;
        }
    }
}
