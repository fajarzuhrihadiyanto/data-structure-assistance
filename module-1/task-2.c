/**
 * Second Assignment of Module 1 Data Structure
 * Implement priority queue to handle patient queue in 'Klinik TC'
 * with the given id and priority value in every patient. Patient
 * with higher priority will be served first. If the priority value
 * are the same, then the one who came first will be served first.
 *
 * @author Fajar Zuhri Hadiyanto
 * @version 1.0
 * @since March 26th 2021
 * */

// IMPORT PACKAGE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// DEFINE THE QUEUE NODE
typedef struct pqueueNode_t {
    int data, id;
    struct pqueueNode_t *next;
} PQueueNode;

// DEFINE THE QUEUE
typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

// PROTOTYPING
void pqueue_initialize(PriorityQueue *pqueue);
bool pqueue_isEmpty(PriorityQueue *pqueue);
void pqueue_push(PriorityQueue *pqueue, int value, int id);
void pqueue_pop(PriorityQueue *pqueue);
int pqueue_top(PriorityQueue *pqueue);

/**
 * Main Function
 * Description :
 *      This function is used as a main console app
 * */
int main(){
    char input[100];

    // PREPARE THE PRIORITY QUEUE
    PriorityQueue queue;
    pqueue_initialize(&queue);

    // GET THE NUMBER OF QUERY
    int nQuery;
    scanf("%d\n", &nQuery);

    // REPEAT FOR THE NUMBER OF QUERY
    for(int i = 0; i < nQuery; i++){

        // GET THE QUERY
        scanf("%[^\n]%*c", input);

        // CHECK IF QUERY IS "LAYANI"
        if(strcmp(input, "LAYANI") == 0){

            // IF QUEUE IS NOT EMPTY, THEN PRINT THE ID
            // AND POP THE QUEUE
            if(!pqueue_isEmpty(&queue)){
                printf("%d\n", pqueue_top(&queue));
                pqueue_pop(&queue);
            }
            // BUT IF QUEUE IS EMPTY, THEN PRINT "HORE"
            else {
                printf("HORE");
            }
        }
        // IF QUERY IS NOT "LAYANI", THEN ...
        else {

            // ... GET THE ID AND THE PRIORITY OF INCOMING PATIENT
            char *token = strtok(input, " ");
            token = strtok(NULL, " ");
            int id = atoi(token);
            token = strtok(NULL, " ");
            int val = atoi(token);

            // THEN PUSH THEM TO THE QUEUE
            pqueue_push(&queue, val, id);
        }
    }

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
void pqueue_initialize(PriorityQueue *pqueue){
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
 *      In this case, add patient to the queue. The new element
 *      will be placed based on the id and priority level.
 *
 * @param pqueue pointer to queue to be added by new element (patient)
 * @param value priority level of the element (patient)
 * @param id id of the element (patient)
 * */
void pqueue_push(PriorityQueue *pqueue, int value, int id){
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = \
        (PQueueNode*) malloc (sizeof(PQueueNode));
    newNode->data = value;
    newNode->id = id;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if (value > pqueue->_top->data) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL &&
                temp->next->data >= value)
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
int pqueue_top(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->id;
    else return 0;
}