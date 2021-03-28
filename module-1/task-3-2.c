/**
 * Third Assignment of Module 1 Data Structure
 * Modify the queue implementation from the given source
 * and set the data type of node to string with 100 as maximum character of each node
 *
 * Source :
 * https://github.com/AlproITS/StrukturData/blob/master/For%20C/D.Array%2C%20Stack%2C%20Queue%2C%20Deque%2C%20Pr.Queue/queue_list.c
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

// DEFINE THE QUEUE NODE
typedef struct queueNode_t {
    char data[101];
    struct queueNode_t *next;
} QueueNode;

// DEFINE THE QUEUE
typedef struct queue_t {
    QueueNode   *_front,
            *_rear;
    unsigned _size;
} Queue;

// PROTOTYPING
void queue_init(Queue *queue);
bool queue_isEmpty(Queue *queue);
void queue_push(Queue *queue, char *value);
void queue_pop(Queue *queue);
char*  queue_front(Queue *queue);
int queue_size(Queue *queue);

/**
 * Main Function
 * Description :
 *      This function is used as a main console app
 * */
int main(){
    // PREPARE THE QUEUE
    Queue myQueue;
    queue_init(&myQueue);

    // PUSH ELEMENTS TO THE QUEUE
    queue_push(&myQueue, "Hello");
    queue_push(&myQueue, "World");
    queue_push(&myQueue, "Well");
    queue_push(&myQueue, "Damn");

    // DISPLAY ALL ELEMENTS OF THE QUEUE
    while (!queue_isEmpty(&myQueue)) {
        printf("%s ", queue_front(&myQueue));
        queue_pop(&myQueue);
    }
    puts("");
    return 0;
}

/**
 * Function queue_init
 * Description :
 *      This function is used to initialize queue
 *      by setting the queue size to 0
 *      and setting the front and rear element to NULL
 *
 * @param queue pointer to queue to be initialized
 * */
void queue_init(Queue *queue){
    queue->_size = 0;
    queue->_front = NULL;
    queue->_rear = NULL;
}

/**
 * Function queue_isEmpty
 * Description :
 *      This function is used to check if the queue is empty or not
 *
 * @param queue pointer to queue to be checked the emptiness
 * @return true if the queue is empty, else false
 * */
bool queue_isEmpty(Queue *queue) {
    return (queue->_front == NULL && queue->_rear == NULL);
}

/**
 * Function queue_push
 * Description :
 *      This function is used to add new element to queue
 *
 * @param queue pointer to queue to be added by new value
 * @param value value to be added to queue
 * */
void queue_push(Queue *queue, char *value){
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        strcpy(newNode->data, value);
        newNode->next = NULL;

        if (queue_isEmpty(queue))
            queue->_front = queue->_rear = newNode;
        else {
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
}

/**
 * Function queue_pop
 * Description :
 *      This function is used to remove the front element of the queue
 *
 * @param queue pointer to queue to be removed at the front element
 * */
void queue_pop(Queue *queue){
    if (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front;
        queue->_front = queue->_front->next;
        free(temp);

        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
    }
}

/**
 * Function queue_front
 * Description :
 *      This function is used to get the front element of the queue
 *
 * @param queue pointer to queue to be gotten of its front element
 * @return first element of the queue if queue is not empty, else an empty string
 * */
char* queue_front(Queue *queue){
    if (!queue_isEmpty(queue)) {
        return (queue->_front->data);
    }
    return "";
}

/**
 * Function queue_size
 * Description :
 *      This function is used to get the size of the queue
 *
 * @param queue pointer to queue to be gotten of its size
 * @return size of the queue
 * */
int queue_size(Queue *queue) {
    return queue->_size;
}

