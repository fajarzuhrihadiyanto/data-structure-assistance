/**
 * Third Assignment of Module 0 Data Structure
 * Modify Linked list implementation to store array of string, with this link is the source :
 * https://github.com/AlproITS/StrukturData/blob/master/For%20C/D.Array%2C%20Stack%2C%20Queue%2C%20Deque%2C%20Pr.Queue/dynamic_array.c
 *
 * @author Fajar Zuhri Hadiyanto
 * @version 1.0
 * @since March 21st 2021
 * */

// IMPORT PACKAGE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// DEFINE NODE TYPE
typedef struct snode_t {
    char data[100];
    struct snode_t *next;
} SListNode;

// DEFINE LIST TYPE
typedef struct slist_t {
    unsigned _size;
    SListNode *_head;
} SinglyList;

// PROTOTYPING
void slist_init(SinglyList *list);
bool slist_isEmpty(SinglyList *list);
void slist_pushFront(SinglyList *list, char *value);
void slist_popFront(SinglyList *list);
void slist_pushBack(SinglyList *list, char *value);
void slist_popBack(SinglyList *list);
void slist_insertAt(SinglyList *list, int index, char *value);
void slist_removeAt(SinglyList *list, int index);
void slist_remove(SinglyList *list, char *value);
char* slist_front(SinglyList *list);
char* slist_back(SinglyList *list);
char* slist_getAt(SinglyList *list, int index);

// MAIN FUNCTION
int main() {
    // PREPARE THE LIST
    SinglyList myList;
    slist_init(&myList);

    slist_pushBack(&myList, "Hello");
    slist_pushBack(&myList, "World");
    slist_pushBack(&myList, "Fajar");
    slist_pushBack(&myList, "Zuhri");
    slist_pushBack(&myList, "Hadiyanto");
    // THE DATA SHOULD BE ["Hello", "World", "Fajar", "Zuhri", "Hadiyanto"]

    slist_pushFront(&myList, "Lorem");
    slist_pushFront(&myList, "Ipsum");
    slist_pushFront(&myList, "Dolor");
    slist_pushFront(&myList, "Sit Amet");
    // THE DATA SHOULD BE ["Sit Amet", "Dolor", "Ipsum", "Lorem", "Hello", "World", "Fajar", "Zuhri", "Hadiyanto"]

    slist_popBack(&myList);
    slist_popFront(&myList);
    // THE DATA SHOULD BE ["Dolor", "Ipsum", "Lorem", "Hello", "World", "Fajar", "Zuhri"]

    slist_removeAt(&myList, 3);
    // THE DATA SHOULD BE ["Dolor", "Ipsum", "Lorem", "World", "Fajar", "Zuhri"]

    slist_insertAt(&myList, 1, "Well");
    // THE DATA SHOULD BE ["Dolor", "Well", "Ipsum", "Lorem", "World", "Fajar", "Zuhri"]

    slist_pushBack(&myList, "Damn");
    // THE DATA SHOULD BE ["Dolor", "Well", "Ipsum", "Lorem", "World", "Fajar", "Zuhri", "Damn"]

    slist_remove(&myList, "Dolor");
    // THE DATA SHOULD BE ["Well", "Ipsum", "Lorem", "World", "Fajar", "Zuhri", "Damn"]

    // DISPLAY THE FIRST AND THE LAST ELEMENT OF THE LIST
    printf("%s\n", slist_front(&myList));
    printf("%s\n", slist_back(&myList));

    // DISPLAY THE CERTAIN INDEX OF THE LIST
    printf("%s\n", slist_getAt(&myList, 3));

    // DISPLAY THE DATA BACKWARD
    while (myList._head != NULL) {
        printf("%s ", slist_back(&myList));
        slist_popBack(&myList);
    }
    puts("");

    return 0;
}

/**
 * slist_init
 * Used for List initialization
 *
 * @param list List object/instances
 */
void slist_init(SinglyList *list) {
    list->_head = NULL;
    list->_size = 0;
}

/**
 * slist_isEmpty
 * Used to check if a List object/instance is empty or not
 *
 * @param list List object/instance
 * @return (bool) true if head of a given list is NULL, else false
 */
bool slist_isEmpty(SinglyList *list) {
    return (list->_head == NULL);
}

/**
 * slist_pushFront
 * Used to add a string at the front of the given list
 *
 * @param list List object/instance
 * @param value string to be added at the front of the given list
 */
void slist_pushFront(SinglyList *list, char *value) {
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        strcpy(newNode->data, value);

        if (slist_isEmpty(list)) newNode->next = NULL;
        else newNode->next = list->_head;
        list->_head = newNode;
    }
}

/**
 * slist_popFront
 * Used to pop/remove front element of the given list
 *
 * @param list List object/instance
 */
void slist_popFront(SinglyList *list) {
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        list->_head = list->_head->next;
        free(temp);
        list->_size--;
    }
}

/**
 * slist_pushBack
 * Used to add a string element at the tail of the given list
 *
 * @param list List object/instance
 * @param value string to be added at the tail of the given list
 */
void slist_pushBack(SinglyList *list, char *value) {
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        strcpy(newNode->data, value);
        newNode->next = NULL;

        if (slist_isEmpty(list))
            list->_head = newNode;
        else {
            SListNode *temp = list->_head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

/**
 * slist_popBack
 * Used to pop/remove tail element of the given list
 *
 * @param list List object/instance
 */
void slist_popBack(SinglyList *list) {
    if (!slist_isEmpty(list)) {
        SListNode *nextNode = list->_head->next;
        SListNode *currNode = list->_head;

        if (currNode->next == NULL) {
            free(currNode);
            list->_head = NULL;
            return;
        }

        while (nextNode->next != NULL) {
            currNode = nextNode;
            nextNode = nextNode->next;
        }
        currNode->next = NULL;
        free(nextNode);
        list->_size--;
    }
}

/**
 * slist_insertAt
 * Used to add a string element at the given index of the given list
 *
 * @param list List object/instance
 * @param index index of the given list to be added by some value
 * @param value string to be added at the given index of the given list
 */
void slist_insertAt(SinglyList *list, int index, char *value) {
    if (slist_isEmpty(list) || index >= list->_size) {
        slist_pushBack(list, value);
        return;
    }
    else if (index == 0 || index < 0) {
        slist_pushFront(list, value);
        return;
    }

    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index-1) {
            temp = temp->next;
            _i++;
        }
        strcpy(newNode->data, value);
        newNode->next = temp->next;
        temp->next = newNode;
        list->_size++;
    }
}

/**
 * slist_removeAt
 * Used to remove element at the given index of the given list
 *
 * @param list List object/instance
 * @param index index of the given list to be removed
 */
void slist_removeAt(SinglyList *list, int index) {
    if (!slist_isEmpty(list)) {

        if (index >= list->_size) {
            slist_popBack(list);
            return;
        }
        else if (index == 0 || index < 0) {
            slist_popFront(list);
            return;
        }

        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index-1) {
            temp = temp->next;
            _i++;
        }
        SListNode *nextTo = temp->next->next;
        free(temp->next);
        temp->next = nextTo;
        list->_size--;
    }
}

/**
 * slist_remove
 * Used to remove element with the given value from the given list
 *
 * @param list List object/instance
 * @param value string to be removed from the given list
 */
void slist_remove(SinglyList *list, char *value) {
    if (!slist_isEmpty(list)) {
        SListNode *temp, *prev;
        temp = list->_head;

        if (strcmp(temp->data, value) == 0) {
            slist_popFront(list);
            return;
        }
        while (temp != NULL && strcmp(temp->data, value) != 0) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) return;
        prev->next = temp->next;
        free(temp);
        list->_size--;
    }
}

/**
 * slist_front
 * Used to get the value of the first element of the given list
 *
 * @param list List object/instance
 * @return (*char) the first element of the given list
 */
char* slist_front(SinglyList *list) {
    if (!slist_isEmpty(list)) {
        return list->_head->data;
    }
    return "";
}

/**
 * slist_back
 * Used to get the value of the last element of the given list
 *
 * @param list List object/instance
 * @return (*char) the last element of the given list
 */
char* slist_back(SinglyList *list) {
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        while (temp->next != NULL)
            temp = temp->next;
        return temp->data;
    }
    return "";
}

/**
 * slist_getAt
 * Used to get value od the given index of the given list
 *
 * @param list List object/instance
 * @param index index of the given list to be looked up
 * @return
 */
char* slist_getAt(SinglyList *list, int index) {
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index) {
            temp = temp->next;
            _i++;
        }
        return temp->data;
    }
    return "";
}