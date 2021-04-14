/**
 * Second Assignment of Module 2 Data Structure
 * Implement tree data structure to insert and find level of element in a tree
 *
 * @author Fajar Zuhri Hadiyanto
 * @version 1.0
 * @since April 9th 2021
 * */

// IMPORT PACKAGE
#include <stdio.h>
#include <stdlib.h>

/**
 * Node of tree element
 * */
typedef struct bstnode_t {
    int key;
    struct bstnode_t \
        *left, *right;
} BSTNode;

/**
 * Tree element
 * */
typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

// PROTOTYPING
void tree_init(BST* tree);
int find(BSTNode* root, int key);
void insert(BST* tree, int data);

/**
 * This function is used as a main console app
 *
 * @return error code if any, else 0
 */
int main() {

    // PREPARE THE TREE
    BST tree;
    tree_init(&tree);

    // GET THE NUMBER OF QUERIES
    int nQuery;
    scanf("%d", &nQuery);

    // REPEAT FOR THE NUMBER OF QUERIES
    for (int i = 0; i < nQuery; i++) {

        // GET THE QUERY AND YEAR
        int query, year;
        scanf("%d %d", &query, &year);

        // IF QUERY IS 1 ...
        if (query == 1) {

            // ... INSERT YEAR TO THE TREE
            insert(&tree, year);
        }
            // ELSE ...
        else {

            // ... FIND YEAR LEVEL IN THE TREE
            int level = find(tree._root, year);

            // IF LEVEL IS NOT -1 (FOUND) ...
            if (level != -1) {

                // ... DISPLAY THE LEVEL
                printf("%d\n", level);
            }
                // ELSE ...
            else {

                // ... DISPLAY CERTAIN MESSAGE
                printf("Buku tidak ada\n");
            }
        }
    }

    return 0;
}

/**
 * This function is used to initialize the tree
 *
 * @param tree tree to be initialized
 */
void tree_init(BST* tree) {
    tree->_root = NULL;
    tree->_size = 0;
}

/**
 * This function is used to find element in a tree
 *
 * @param root root to be looked for it's element
 * @param key key value to be looked for
 * @return level of the found key
 * */
int find(BSTNode* root, int key) {
    int level = 0;

    if (root != NULL) {
        while (key < root->key ? root->left != NULL : key == root->key || root->right != NULL) {
            level++;

            if (key < root->key) {
                root = root->left;
            } else if (key > root->key) {
                root = root->right;
            } else if (find(root->right, key) != -1) {
                root = root->right;
            } else {
                return level;
            }
        }
    }
    return -1;
}

/**
 * This function is used to insert node to a tree.
 *
 * @param tree tree
 * @param data value to be added to a tree
 * */
void insert(BST* tree, int data) {

    BSTNode* temp = tree->_root;

    BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));
    node->key = data;
    node->left = NULL;
    node->right = NULL;

    if(temp == NULL) {
        tree->_root = node;
    } else {
        while (data < temp->key ? temp->left != NULL : temp->right != NULL) {
            if(data < temp->key) temp = temp->left;
            else temp = temp->right;
        }

        if (data < temp->key) temp->left = node;
        else temp->right = node;
    }
}
