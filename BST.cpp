#include "BST.h"
#include "Node.h"
#include <stdbool.h>
#include <stdlib.h>

void postOrderDelete(Node* node);
int inOrderList(double* arr, Node* node, int index);
bool recursiveContains(Node* node, double value);
bool recursiveInsert(Node* current, Node* parent, double value);
void deleteNode(BST* tree, Node* node, Node* parent);

BST* initializeBST()
{
    BST* tree = malloc(sizeof(BST));
    tree->count = 0;
    tree->root = NULL;
    return tree;
}

void deleteBST(BST* tree)
{
    //post order traversal to delete each node
    if (tree->count > 0)
        postOrderDelete(tree->root);
    //delete BST
    free(tree);
}

void postOrderDelete(Node* node)
{

    //1-Traverse the left subtree, 2-Traverse the right subtree, 3-reach root
    if (node == NULL)//Base case
        return;
    else
    {
        //delete node and free from memory 
        postOrderDelete(node->left);
        postOrderDelete(node->right);
        free(node);
        node = NULL;
    }
}

double* list(BST* tree)
{
    if (tree->count == 0)
        return NULL;
    double* arr = calloc(tree->count, sizeof(double));
    inOrderList(arr, tree->root, 0);
    return arr;
}

int inOrderList(double* arr, Node* node, int index)
{
    if (node != NULL)
    {
        index = inOrderList(arr, node->left, index);
        arr[index] = node->value;
        index++;
        index = inOrderList(arr, node->right, index);
    }
    return index;

}

bool contains(BST* tree, double value)
{
    return recursiveContains(tree->root, value);
}

bool recursiveContains(Node* node, double value)
{
    if (node == NULL)
        return false;
    else
    {
        while (node->value != value)
        {
            if (value < node->value)
                node = node->left;
            else
                node = node->right;
            if (node == NULL)
                return false;
        }
    }
    return true;
}

bool insert(BST* tree, double value)
{
    //if there are no nodes yet, make this value the root
    if (tree->count == 0)
    {
        tree->root = malloc(sizeof(Node));
        tree->root->value = value;
        tree->root->left = NULL;
        tree->root->right = NULL;
        tree->count++;
        return true;
    }
    //call recursive insert to handle the rest
    if (recursiveInsert(tree->root, NULL, value))
    {
        tree->count++;
        return true;
    }
    else
        return false;
}

bool recursiveInsert(Node* current, Node* parent, double value)
{
    if (current == NULL)
    {
        //create new node to insert here
        Node* node = malloc(sizeof(Node));
        node->value = value;
        node->left = NULL;
        node->right = NULL;
        if (value < parent->value)
            parent->left = node;
        else
            parent->right = node;
        return true;
    }
    else if (value < current->value)
        return recursiveInsert(current->left, current, value);
    else if (value > current->value)
        return recursiveInsert(current->right, current, value);
    else
        return false;
}

bool delete(BST* tree, double value)
{
    //handle if tree is empty
    if (tree->count == 0)
        return false;
    //find the value in the tree and its parent
    Node* node = tree->root;
    Node* parent = NULL;
    bool foundIt = (node->value == value);
    while (node != NULL && !foundIt) {
        if (value < node->value)
        {
            parent = node;
            node = node->left;
        }
        else if (value > node->value)
        {
            parent = node;
            node = node->right;
        }
        else
        {
            foundIt = true;
        }
    }
    if (!foundIt)
        return false;
    //call the deleteNode function to delete the found node
    deleteNode(tree, node, parent);
    tree->count--;
    return true;
}

void deleteNode(BST* tree, Node* node, Node* parent)
{
    if (node->left == NULL && node->right == NULL)
    {
        if (parent == NULL)
            tree->root = NULL;
        else
        {
            if (parent->left == node)
                parent->left = NULL;
            if (parent->right == node)
                parent->right = NULL;
        }
        free(node);
    }
    else if (node->left == NULL)
    {
        if (parent->left == node)
            parent->left = node->right;
        if (parent->right == node)
            parent->right = node->right;
        free(node);
    }
    else if (node->right == NULL)
    {
        if (parent->left == node)
            parent->left = node->left;
        if (parent->right == node)
            parent->right = node->left;
        free(node);
    }
    else
    {
        Node* prev = node;
        Node* curr = node->left;
        //traverse left-subtree for max value
        while (curr->right != NULL)
        {
            prev = curr;
            curr = curr->right;
        }
        node->value = curr->value;
        if (node->left->right != NULL)
            prev->right = curr->left;
        else
            node->left = node->left->left;
        //delete max node
        free(curr);
    }
}

bool isEmpty(BST* tree)
{
    return (tree->count == 0);
}

int size(BST* tree)
{
    return tree->count;
}
