#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Node.h"
#include "BST.h"

void testStartEnd();
void testEmpty();
void testSorted();
void testReverseSorted();
void testBalanced();
void printTree(BST* tree);
void printNodes(Node* node, int spaces);

int main()
{
    printf("%s\n", "==========================================");
    printf("%s\n", "             TESTING BST");
    printf("%s\n", "         1 = true, 0 = false");
    printf("%s\n", "==========================================");
    testStartEnd();
    printf("%s\n", "==========================================");
    testEmpty();
    printf("%s\n", "==========================================");
    testSorted();
    printf("%s\n", "==========================================");
    testReverseSorted();
    printf("%s\n", "==========================================");
    testBalanced();
    //end
    getchar();
}

void testStartEnd()
{
   
    BST* tree = initializeBST();
    printf("%s\n", "POST BST INITIALIZATION");
    printf("tree is initialized = %i\n", (tree->count == 0));
    //test deleteBST
    deleteBST(tree);
    printf("%s\n", "POST BST DELETE");
    printf("tree is initialized = %i\n", (tree->count == 0));
}

void testEmpty()
{
    BST* tree = initializeBST();
    printf("%s\n", "WITHOUT NODES:");
    double* arr1 = list(tree);
    printf("tree list is empty = %i\n", (arr1 == NULL));
    printf("contains 7 = %i\n", contains(tree, 7));
    printf("deleted 7 = %i\n", delete(tree, 7));
    printf("tree is empty = %i\n", isEmpty(tree));
    printf("count = %i\n", size(tree));
    deleteBST(tree);
}

void testSorted()
{
    BST* tree = initializeBST();
    printf("%s\n", "WITH SORTED NODES:");
    printf("add 3 = %i\n", insert(tree, 3));
    printf("add 6 = %i\n", insert(tree, 6));
    printf("add 7 = %i\n", insert(tree, 7));
    printf("add 13 = %i\n", insert(tree, 13));
    printf("add 14 = %i\n", insert(tree, 14));
    printTree(tree);
    printf("add 6 again = %i\n", insert(tree, 6));
    printf("count = %i\n", size(tree));
    printf("contains 7 = %i\n", contains(tree, 7));
    printf("deleting 7 = %i\n", delete(tree, 7));
    printTree(tree);
    printf("deleting 8 = %i\n", delete(tree, 7));
    printf("count = %i\n", size(tree));
    printf("contains 7 = %i\n", contains(tree, 7));
    double* arr = list(tree);
    for (int i = 0; i < size(tree); i++)
        printf("%f ", arr[i]);
    printf("\n");
    free(arr);
    deleteBST(tree);
}

void testReverseSorted()
{
    //start
    BST* tree = initializeBST();
    printf("%s\n", "WITH REVERSE SORTED NODES:");
    printf("add 51 = %i\n", insert(tree, 51));
    printf("add 39 = %i\n", insert(tree, 39));
    printf("add 21 = %i\n", insert(tree, 21));
    printf("add 11 = %i\n", insert(tree, 11));
    printf("add 5 = %i\n", insert(tree, 5));
    printTree(tree);
    printf("add 21 again = %i\n", insert(tree, 21));
    printf("count = %i\n", size(tree));
    printf("contains 39 = %i\n", contains(tree, 39));
    printf("deleting 39 = %i\n", delete(tree, 39));
    printTree(tree);
    printf("deleting 77 = %i\n", delete(tree, 77));
    printf("count = %i\n", size(tree));
    printf("contains 77 = %i\n", contains(tree, 77));
    double* arr = list(tree);
    for (int i = 0; i < size(tree); i++)
        printf("%f ", arr[i]);
    printf("\n");
    free(arr);
    deleteBST(tree);
}

void testBalanced()
{
    BST* tree = initializeBST();
    printf("%s\n", "WITH BALANCED NODES:");
    printf("add 31 = %i\n", insert(tree, 31));
    printf("add 49 = %i\n", insert(tree, 49));
    printf("add 17 = %i\n", insert(tree, 17));
    printf("add 10 = %i\n", insert(tree, 10));
    printf("add 23 = %i\n", insert(tree, 23));
    printf("add 38 = %i\n", insert(tree, 38));
    printf("add 62 = %i\n", insert(tree, 62));
    printTree(tree);
    printf("add 17 again = %i\n", insert(tree, 17));
    printf("count = %i\n", size(tree));
    printf("contains 49 = %i\n", contains(tree, 49));
    printf("deleting 17 = %i\n", delete(tree, 17));
    printTree(tree);
    printf("deleting 100 = %i\n", delete(tree, 100));
    printf("count = %i\n", size(tree));
    printf("contains 100 = %i\n", contains(tree, 100));
    printf("delete 49 = %i\n", delete(tree, 49));
    printTree(tree);
    double* arr = list(tree);
    for (int i = 0; i < size(tree); i++)
        printf("%f ", arr[i]);
    printf("\n");
    free(arr);
    //end
    deleteBST(tree);
}

void printTree(BST* tree)
{
    printf("\n%s\n", "Current tree structure: ");
    printNodes(tree->root, 4);
    printf("\n");
}

void printNodes(Node* node, int spaces)
{
    int i;
    if (node != NULL)
    {
        printNodes(node->right, spaces + 10);
        for (i = 0; i < spaces; i++)
            printf(" ");
        printf("%f\n", node->value);
        printNodes(node->left, spaces + 10);
    }
}

void printList(BST* tree)
{
    //print values in list (nodes)
    double* arr = list(tree);
    for (int i = 0; i < size(tree); i++)
        printf("%.2f ", arr[i]);
    printf("\n");
    free(arr);
}
