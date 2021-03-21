/**
 * First Assignment of Module 0 Data Structure
 * Implement forEachElement function to call a certain function on every element of a given list
 *
 * @author Fajar Zuhri Hadiyanto
 * @version 1.0
 * @since March 20th 2021
 * */

// IMPORT PACKAGE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DEFINE NODE TYPE
typedef struct node {
    int data;
    struct node *next;
} ListNode;

// DEFINE LIST TYPE
typedef struct list {
    unsigned _size;
    ListNode *_head;
} List;

// PROTOTYPING
void listInit(List *list);
bool listIsEmpty(List *list);
void listPushBack(List *list, int value);
void forEachElement(List *list, void (*fun)());
void printElement(const int *elem);
void multiply2(int *elem);

// MAIN FUNCTION
int main() {
    // PREPARE THE LIST
    List myList;
    listInit(&myList);

    // ADD DATA TO THE LIST
    listPushBack(&myList, 1);
    listPushBack(&myList, 2);
    listPushBack(&myList, 3);
    listPushBack(&myList, 4);
    listPushBack(&myList, 5);

    // PRINT EACH ELEMENT OF THE LIST
    forEachElement(&myList, printElement);

    // MULTIPLY EACH ELEMENT OF THE LIST BY 2
    forEachElement(&myList, multiply2);

    // PRINT EACH ELEMENT OF THE LIST (AGAIN) TO SEE CHANGES
    forEachElement(&myList, printElement);

    return 0;
}

/**
 * listInit
 * Used for List initialization
 *
 * @param list List object/instances
 */
void listInit(List *list) {
    list->_head = NULL;
    list->_size = 0;
}

/**
 * listIsEmpty
 * Used to check if a List object/instance is empty or not
 *
 * @param list List object/instance
 * @return (bool) true if head of a given list is NULL, else false
 */
bool listIsEmpty(List *list) {
    return (list->_head == NULL);
}

/**
 * listPushBack
 * Used to push an int data to tail of a given list
 *
 * @param list List object/instance
 * @param value int data to be added
 */
void listPushBack(List *list, int value) {
    ListNode *newNode = (ListNode*) malloc(sizeof(ListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;
        newNode->next = NULL;

        if (listIsEmpty(list))
            list->_head = newNode;
        else {
            ListNode *temp = list->_head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

/**
 * forEachElement
 * Used as a callback on every element of a given list
 *
 * @param list List object/instance
 * @param fun void type of function object
 */
void forEachElement(List *list, void (*fun)()) {
    if (!listIsEmpty(list)) {
        ListNode *temp = list->_head;
        while (temp->next != NULL) {
            fun(&temp->data);
            temp = temp->next;
        }
        fun(&temp->data);
    }
}

/**
 * printElement
 * Used to print value of a pointer to int
 *
 * @param elem pointer to int
 */
void printElement(const int *elem) {
    printf("%d\n", *elem);
}

/**
 * multiply2
 * Used to multiply value of a pointer to int by 2
 *
 * @param elem pointer to int
 */
void multiply2(int *elem) {
    *elem *= 2;
}