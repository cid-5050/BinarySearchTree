#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <BinaryNode.h>


class BinarySearchTree {
  public:
    BinarySearchTree();

    bool isEmpty(void);

    void makeEmpty(BinaryNode * node);
    void makeEmpty(void);

    BinaryNode * insert(BinaryNode * node, int key);
    void insert(int key);

    int size(BinaryNode * node);
    int size(void);

    void print(BinaryNode * node);
    void print(void);

    BinaryNode * find(BinaryNode * node, int key);
    bool find(int key);

    int findMin(BinaryNode * node);
    int findMin(void);

    int findMax(BinaryNode * node);
    int findMax(void);

    int next(BinaryNode * node);
    int next(int key);

    int prev(BinaryNode * node);
    int prev(int key);

    BinaryNode * remove(BinaryNode * node, int key);
    void remove(int key);

    void removeLessThan(BinaryNode * node, int key);
    void removeLessThan(int key);

    void removeMoreThan(BinaryNode * node, int key);
    void removeMoreThan(int key);

    void prune(BinaryNode * node, int key);
    void prune(int key);

  protected:
    BinaryNode * root = nullptr;

};

#endif // BINARYSEARCHTREE_H
