/**
 * First Assignment of Module 2 Data Structure
 * This assignment is given from hackerrank platform
 * The link : https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem
 *
 * @author Fajar Zuhri Hadiyanto
 * @version 1.0
 * @since April 9th 2021
 * */

// IMPORT PACKAGES
#include <stdio.h>
#include <stdlib.h>

/**
 * Node of tree element
 *
 * @note this struct is provided by hackerrank
 * */
struct node {
    int data;
    struct node *left;
    struct node *right;
};

/**
 * This function is used to insert node to a tree.
 *
 * @note this function is provided by hackerrank
 *
 * @param root root node of a tree
 * @param data value to be added to a tree
 * @return inserted node
 * */
struct node* insert( struct node* root, int data ) {

    if(root == NULL) {

        struct node* node = (struct node*)malloc(sizeof(struct node));

        node->data = data;

        node->left = NULL;
        node->right = NULL;
        return node;

    } else {

        struct node* cur;

        if(data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
        } else {
            cur = insert(root->right, data);
            root->right = cur;
        }

        return root;
    }
}

/**
 * This function is used to get the lowest common ancestor
 * of 2 given value from the given root of the tree
 *
 * @param root root of the tree
 * @param v1 first value
 * @param v2 second value
 * @return the lowest common ancestor node of the two values
 * */
struct node *lca( struct node *root, int v1, int v2 ) {
    if(root != NULL){
        // if the node matches either v1 or v2, return this node
        if(root->data == v1 || root->data == v2) {
            return root;
        }

        // if the node is greater than both v1 and v2, go to the left
        if(root->data > v1 && root->data > v2) return lca(root->left, v1, v2);

        // if the node is lower than both v1 and v2, go to the right
        if(root->data < v1 && root->data < v2) return lca(root->right, v1, v2);

        // if the v1 and v2 is separated by this node, return this node
        return root;
    }
    return NULL;
}

/**
 * This function is used as a main console app
 *
 * @note this function is provided by hackerrank
 *
 * @return error code if any, else 0
 */
int main() {
    // PREPARE THE TREE
    struct node* root = NULL;

    // GET THE NUMBER OF ELEMENT IN THE TREE
    int t;
    scanf("%d", &t);

    // INPUT ALL ELEMENTS OF THE TREE
    int data;
    while(t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    // GET THE VALUE TO BE LOOKED UP THE LOWEST COMMON ANCESTOR
    int v1;
    int v2;
    scanf("%d %d", &v1, &v2);

    // SEARCH AND PRINT THE LOWEST COMMON ANCESTOR
    struct node *ans = lca(root, v1, v2);
    printf("%d", ans->data);

    return 0;
}
