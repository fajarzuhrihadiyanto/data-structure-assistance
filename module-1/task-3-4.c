/**
 * Third Assignment of Module 1 Data Structure
 * Modify the priority queue implementation from the given source
 * and set the data type of node to string with 100 as maximum character of each node
 *
 * Source :
 * https://github.com/AlproITS/StrukturData/blob/master/For%20C/D.Array%2C%20Stack%2C%20Queue%2C%20Deque%2C%20Pr.Queue/deque_list.c
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

// DEFINE PRIORITY QUEUE NODE
typedef struct pqueueNode_t {
    char data[101];
    struct pqueueNode_t *next;
} PQueueNode;

// DEFINE PRIORITY QUEUE
typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

// PROTOTYPIN G
void pqueue_init(PriorityQueue *pqueue);
bool pqueue_isEmpty(PriorityQueue *pqueue);
void pqueue_push(PriorityQueue *pqueue, char *value);
void pqueue_pop(PriorityQueue *pqueue);
char*  pqueue_top(PriorityQueue *pqueue);

/**
 * Main Function
 * Description :
 *      This function is used as a main console app
 * */
int main(){
    // PREPARE THE PRIORITY QUEUE
    PriorityQueue myPque;
    pqueue_init(&myPque);

    // PUSH DATA TO THE PQUEUE
    pqueue_push(&myPque, "Hadiyanto");
    pqueue_push(&myPque, "Fajar");
    pqueue_push(&myPque, "Zuhri");

    // DISPLAY ALL ELEMENTS OF THE PQUEUE
    while (!pqueue_isEmpty(&myPque)) {
        printf("%s ", pqueue_top(&myPque));
        pqueue_pop(&myPque);
    }
    puts("");
    return 0;
}

/**
 * Function pqueue_initialize
 * Description :
 *      This function is used to initialize the given priority queue
 *      By setting the top value to NULL
 *      and setting the size value to 0
 *
 * @param pqueue pointer to queue to be initialized
 * */
void pqueue_init(PriorityQueue *pqueue){
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

/**
 * Function pqueue_isEmpty
 * Description :
 *      This function is used to check if the queue is empty or not
 *
 * @param pqueue pointer to queue to be checked the emptiness
 * @return true if the queue is empty, else false
 * */
bool pqueue_isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL);
}

/**
 * Function pqueue_push
 * Description :
 *      This function is used to add a new element to the queue.
 *
 * @param pqueue pointer to queue to be added by new element
 * @param value value to be added to the queue
 * */
void pqueue_push(PriorityQueue *pqueue, char *value){
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = \
        (PQueueNode*) malloc (sizeof(PQueueNode));
    strcpy(newNode->data, value);
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if (strcmp(value, pqueue->_top->data) >= 0 ) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL &&
                strcmp(temp->next->data, value) >= 0)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

/**
 * Function pqueue_pop
 * Description :
 *      This function is used to remove the front element of the queue
 *
 * @param pqueue pointer to queue to be removed at the front element
 * */
void pqueue_pop(PriorityQueue *pqueue){
    if (!pqueue_isEmpty(pqueue)) {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

/**
 * Function pqueue_top
 * Description :
 *      This function is used to get the front element of the queue
 *
 * @param pqueue pointer to queue to be gotten at the front element
 * @return value of the front element
 * */
char* pqueue_top(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->data;
    else return 0;
}