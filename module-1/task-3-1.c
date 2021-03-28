/**
 * Third Assignment of Module 1 Data Structure
 * Modify the stack implementation from the given source
 * and set the data type of node to string with 100 as maximum character of each node
 *
 * Source :
 * https://github.com/AlproITS/StrukturData/blob/master/For%20C/D.Array%2C%20Stack%2C%20Queue%2C%20Deque%2C%20Pr.Queue/stack_list.c
 *
 * @author Bayu Laksana
 * @author Fajar Zuhri Hadiyanto
 * @version 1.0
 * @since March 26th 2021
 * */

// IMPORT PACKAGE
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// DEFINE THE STACK NODE
typedef struct stackNode_t {
    char data[101];
    struct stackNode_t *next;
} StackNode;

// DEFINE THE STACK
typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

// PROTOTYPING
void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, char *value);
void stack_pop(Stack *stack);
char* stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

/**
 * Main Function
 * Description :
 *      This function is used as a main console app
 * */
int main(){
    // PREPARE THE STACK
    Stack myStack;
    stack_init(&myStack);

    // PUSH ELEMENTS TO THE STACK
    stack_push(&myStack, "Hello");
    stack_push(&myStack, "World");
    stack_push(&myStack, "Well");
    stack_push(&myStack, "Damn");

    // DISPLAY ALL ELEMENTS OF THE STACK FROM THE TOP
    while (!stack_isEmpty(&myStack)) {
        printf("%s ", stack_top(&myStack));
        stack_pop(&myStack);
    }
    puts("");
    return 0;
}

/**
 * Function stack_init
 * Description :
 *      This function is used to initialize the stack
 *      by set the value of field _top to NULL
 *      and set the value of field _size to 0
 *
 * @param stack pointer to stack to be initialized
 * */
void stack_init(Stack *stack){
    stack->_size = 0;
    stack->_top = NULL;
}

/**
 * Function stack_isEmpty
 * Description :
 *      This function is used to check if the given stack is empty or not
 *
 * @param stack pointer to stack to be checked
 * @return true if top element of the stack is NULL, else false
 * */
bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

/**
 * Function stack_push
 * Description :
 *      This function is used to push an element to a stack
 *
 * @param stack pointer to the stack to be pushed by a given value
 * @param value value to be added to the stack
 * */
void stack_push(Stack *stack, char *value){
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        strcpy(newNode->data, value);

        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

/**
 * Function stack_pop
 * Description :
 *      This function is used to remove the top element of the stack
 *
 * @param stack pointer to stack to be removed at the top element
 * */
void stack_pop(Stack *stack){
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

/**
 * Function stack_top
 * Description :
 *      This function is used to get the top element of the given stack
 *
 * @param stack pointer to stack to be gotten at the top element
 * @return top element of the stack if the stack is not empty, else 0
 * */
char* stack_top(Stack *stack){
    if (!stack_isEmpty(stack))
        return stack->_top->data;
    return 0;
}

/**
 * Function stack_size
 * Description :
 *      This function is used to get the size of the given stack
 *
 * @param stack pointer to stack to be gotten of its size
 * @return size of the stack
 * */
unsigned stack_size(Stack *stack) {
    return stack->_size;
}