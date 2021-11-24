#ifndef _BST_
#define _BST_

#include <stdbool.h>
#include "Node.h"

typedef struct BST
{
    Node* root;
    int count;
} BST;

BST* initializeBST();
void deleteBST(BST* tree);
double* list(BST* tree);

bool contains(BST* tree, double value);
bool insert(BST* tree, double value);
bool delete(BST* tree, double value);
bool isEmpty(BST* tree);

int size(BST* tree);
#endif
