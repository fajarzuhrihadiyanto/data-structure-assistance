/**
 * First Assignment of Module 1 Data Structure
 * Implement stack to check whether a string is palindrome or not
 *
 * @author Fajar Zuhri Hadiyanto
 * @version 1.0
 * @since March 26th 2021
 * */

// IMPORT PACKAGE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DEFINE THE STACK NODE
typedef struct stackNode_t {
    char data;
    struct stackNode_t *next;
} StackNode;

// DEFINE THE STACK
typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

// PROTOTYPING
void stack_push(Stack *stack, char value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_initialize(Stack *stack);
unsigned string_length(char *word);

/**
 * Main Function
 * Description :
 *      This function is used as a main console app
 * */
int main(){
    bool isPalindrome = true;

    // PREPARE THE STACK
    Stack word;
    stack_initialize(&word);

    // GET THE INPUT WORD
    char input[100];
    scanf("%[^\n]%*c", input);

    // GET THE MIDDLE INDEX
    unsigned input_length = string_length(input);
    unsigned half = input_length / 2;

    // PUSH HALF OF THE WORD TO THE STACK
    for (int i = 0; i < half; i++){
        stack_push(&word, input[i]);
    }

    // IGNORE THE MIDDLE CHARACTER IF THERE ARE ODD NUMBER OF CHARACTERS
    if (input_length % 2 != 0) half++;

    // COMPARE CHARACTER IN STACK WITH CHARACTER IN WORD
    for(unsigned i = half; i < input_length; i++){
        if(stack_top(&word) != input[i]){
            isPalindrome = false;
            break;
        }
        stack_pop(&word);
    }

    if(isPalindrome){
        printf("Palindrome");
    } else {
        printf("Not Palindrome");
    }

    return 0;
}

/**
 * Function stack_push
 * Description :
 *      This function is used to push an element to a stack
 *
 * @param stack pointer to the stack to be pushed by a given value
 * @param value value to be added to the stack
 * */
void stack_push(Stack *stack, char value){
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;

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
int stack_top(Stack *stack){
    if (!stack_isEmpty(stack))
        return stack->_top->data;
    return 0;
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
 * Function stack_initialize
 * Description :
 *      This function is used to initialize the stack
 *      by set the value of field _top to NULL
 *      and set the value of field _size to 0
 *
 * @param stack pointer to stack to be initialized
 * */
void stack_initialize(Stack *stack){
    stack->_top = NULL;
    stack->_size = 0;
}

/**
 * Function string_length
 * Description :
 *      This function is used to find length of the given string
 *
 * @param word string to be looked for the length
 * @return length of the given string
 * */
unsigned string_length(char *word){
    unsigned length = 0;
    while(*word != '\0'){
        length++;
        word++;
    }
    return length;
}