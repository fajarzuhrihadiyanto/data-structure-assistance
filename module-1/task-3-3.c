/**
 * Third Assignment of Module 1 Data Structure
 * Modify the double-ended queue implementation from the given source
 * and set the data type of node to string with 100 as maximum character of each node
 *
 * Source :
 * https://github.com/AlproITS/StrukturData/blob/master/For%20C/D.Array%2C%20Stack%2C%20Queue%2C%20Deque%2C%20Pr.Queue/priority_queue_list.c
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

// DEFINE THE DEQUEUE NODE
typedef struct dnode_t {
    char data[101];
    struct dnode_t      \
        *next,
            *prev;
} DListNode;

// DEFINE THE DEQUEUE
typedef struct deque_t {
    DListNode           \
        *_head,
            *_tail;
    unsigned _size;
} Deque;

// PROTOTYPING
DListNode* __dlist_createNode(char *value);
void deq_init(Deque *deque);
bool deq_isEmpty(Deque *deque);
void deq_pushFront(Deque *deque, char *value);
void deq_pushBack(Deque *deque, char *value);
char*  deq_front(Deque *deque);
char*  deq_back(Deque *deque);
void deq_popFront(Deque *deque);
void deq_popBack(Deque *deque);

/**
 * Main Function
 * Description :
 *      This function is used as a main console app
 * */
int main(){
    // PREPATE THE QUEUE
    Deque mydeq;
    deq_init(&mydeq);

    // PUSH ELEMENT FROM THE BACK OF THE QUEUE
    deq_pushBack(&mydeq, "Hello");
    deq_pushBack(&mydeq, "World");
    deq_pushBack(&mydeq, "Well");
    deq_pushBack(&mydeq, "God");
    deq_pushBack(&mydeq, "Damn");

    // PUSH ELEMENT FROM THE FRONT OF THE QUEUE
    deq_pushFront(&mydeq, "Hadiyanto");
    deq_pushFront(&mydeq, "Zuhri");
    deq_pushFront(&mydeq, "Fajar");

    // DELETE THE REAR ELEMENT OF THE QUEUE
    deq_popBack(&mydeq);

    // DELETE THE FRONT ELEMENT OF THE QUEUE
    deq_popFront(&mydeq);

    // DISPLAY ALL ELEMENTS OF THE QUEUE FROM THE FRONT
    while (!deq_isEmpty(&mydeq)) {
        printf("%s ", deq_front(&mydeq));
        deq_popFront(&mydeq);
    }
    puts("");
    return 0;
}

/**
 * Function __dlist_createNode
 * Description :
 *      This function is used to create new node
 *
 * @param value value of the new node
 * @return whole new node
 * */
DListNode* __dlist_createNode(char *value){
    DListNode *newNode = \
        (DListNode*) malloc (sizeof(DListNode));

    if (!newNode) return NULL;
    strcpy(newNode->data, value);
    newNode->next = NULL;
    newNode->prev = NULL;

    return (DListNode*) newNode;
}

/**
 * Function deq_init
 * Description :
 *      This function is used to initialize the dequeue
 *
 * @param deque pointer to dequeue to be initialized
 * */
void deq_init(Deque *deque){
    deque->_head = deque->_tail = NULL;
    deque->_size = (unsigned) 0;
}

/**
 * Function deq_isEmpty
 * Description :
 *      This function is used to check if the dequeue is empty or not
 *
 * @param deque pointer to dequeue to be checked of the emptiness
 * @return true if the dequeue is empty, else false
 * */
bool deq_isEmpty(Deque *deque) {
    return (deque->_head == NULL && \
            deque->_tail == NULL);
}


/**
 * Function deq_pushFront
 * Description :
 *      This function is used to push new element to the dequeue from the front
 *
 * @param deque pointer to dequeue to be added by new element
 * @param value value to be added to the dequeue
 * */
void deq_pushFront(Deque *deque, char *value){
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        deque->_size++;
        if (deq_isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        newNode->next = deque->_head;
        deque->_head->prev = newNode;
        deque->_head = newNode;
    }
}

/**
 * Function deq_pushBack
 * Description :
 *      This function is used to push new element to the dequeue from the back
 *
 * @param deque pointer to dequeue to be added by new element
 * @param value value to be added to the dequeue
 * */
void deq_pushBack(Deque *deque, char *value){
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        deque->_size++;
        if (deq_isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        deque->_tail->next = newNode;
        newNode->prev = deque->_tail;
        deque->_tail = newNode;
    }
}

/**
 * Function deq_front
 * Description :
 *      This function is used to get the front element of the dequeue
 *
 * @param deque pointer to dequeue to be gotten of its front element
 * @return front element of the dequeue
 * */
char* deq_front(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_head->data);
    }
    return 0;
}

/**
 * Function deq_back
 * Description :
 *      This function is used to get the back element of the dequeue
 *
 * @param deque pointer to dequeue to be gotten of its back element
 * @return back element of the dequeue
 * */
char* deq_back(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_tail->data);
    }
    return 0;
}

/**
 * Function deq_popFront
 * Description :
 *      This function is used to remove the front element of the dequeue
 *
 * @param deque pointer to dequeue to be removed at the front element
 * */
void deq_popFront(Deque *deque){
    if (!deq_isEmpty(deque)) {
        DListNode *temp = deque->_head;
        if (deque->_head == deque->_tail) {
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            deque->_head = deque->_head->next;
            deque->_head->prev = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

/**
 * Function deq_popBack
 * Description :
 *      This function is used to remove the back element of the dequeue
 *
 * @param deque pointer to dequeue to be removed at the back element
 * */
void deq_popBack(Deque *deque){
    if (!deq_isEmpty(deque)) {
        DListNode *temp;
        if (deque->_head == deque->_tail) {
            temp = deque->_head;
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            temp = deque->_tail;
            deque->_tail = deque->_tail->prev;
            deque->_tail->next = NULL;
            free(temp);
        }
        deque->_size--;
    }
}