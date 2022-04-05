#include "BinarySearchTree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree() {
}

bool BinarySearchTree::
isEmpty() {
    return (root == nullptr);
}

void BinarySearchTree::
makeEmpty(BinaryNode * node) {

    if (node != nullptr) {
        makeEmpty(node->left);
        makeEmpty(node->right);
        delete node;
    }
    node = nullptr;
}

// Sobrecarga para comodidad
void BinarySearchTree::
makeEmpty() {
    makeEmpty(root);
}

BinaryNode * BinarySearchTree::
insert(BinaryNode * node, int key) {

    if (find(key))
        throw (std::string("Insert: Nodo ya existe"));

    // Si no existe ningún nodo, se crea el primer nodo (root)
    if(node == nullptr) {
        node = new BinaryNode;
        node->key = key;
        node->left = nullptr;
        node->right = nullptr;
        node->parent = nullptr;

    // Si la key dada es mayor que la key del nodo, vamos al subárbol derecho
    } else if(node->key < key) {
        node->right = insert(node->right, key);
        node->right->parent = node;


    // Si la key dada es menor que la key del nodo, vamos al subárbol izquierdo
    } else {
        node->left = insert(node->left, key);
        node->left->parent = node;
    }

    return node;
}

// Sobrecarga de insert para comodidad
void BinarySearchTree::
insert(int key) {
    root = insert(root, key);
}


int BinarySearchTree::
size(BinaryNode * node) {
    if (node == nullptr)
        return 0;
    else
        return(size(node->left) + 1 + size(node->right));
}

// Sobrecarga para comodidad
int BinarySearchTree::
size() {
    return size(root);
}


void BinarySearchTree::
print(BinaryNode * node) {

    // Deja de imprimir si no encuentra más nodos
    if(node == nullptr)
        return;

    // Busca la key más pequeña, en el subárbol izquierdo
    print(node->left);

    // Imprime
    std::cout << node->key << " > ";

    // Busca las keys más grandes, en el subárbol derecho
    print(node->right);
}

// Sobrecarga para comodidad
void BinarySearchTree::
print() {
    print(root);
    std::cout << std::endl;
}


BinaryNode * BinarySearchTree::
find(BinaryNode * node, int key) {

    // No se encuentra la key dentro del árbol
    if (node == nullptr)
        return nullptr;

    // Se encuentra la key
    else if(node->key == key)
        return node;

    // La key dada es mayor que la del nodo actual
    else if(node->key < key)
        return find(node->right, key);

    // La key dada es menor que la del nodo actual
    else
        return find(node->left, key);
}

// Sobrecarga para utilizar como bool
bool BinarySearchTree::
find(int key) {
    BinaryNode * resultado = find(root, key);
    return (resultado != nullptr);
}


int BinarySearchTree::
findMin(BinaryNode * node) {
    if(node == nullptr)
        return -1;

    else if(node->left == nullptr)
        return node->key;

    else
        return findMin(node->left);
}

int BinarySearchTree::
findMax(BinaryNode * node) {
    if(node == nullptr)
        return -1;

    else if(node->right == nullptr)
        return node->key;

    else
        return findMax(node->right);
}

int BinarySearchTree::
findMin() {
    return findMin(root);
}
int BinarySearchTree::
findMax() {
    return findMax(root);
}


int BinarySearchTree::
next(BinaryNode * node) {

    // El next es el mínimo valor del subárbol derecho
    if (node->right != nullptr) {
        return findMin(node->right);

    // Si no hay subárbol derecho
    } else {
        BinaryNode * parentNode = node->parent;
        BinaryNode * currentNode = node;

        // Si el nodo actual no es root y
        // el nodo actual es hijo derecho
        while ((parentNode != nullptr) && (currentNode == parentNode->right)) {
            currentNode = parentNode;
            parentNode = currentNode->parent;
        }

        // Si el nodo no es root, entonces la key del padre es el next
        return parentNode == nullptr ?
            -1 : parentNode->key;
    }
}

int BinarySearchTree::
next(int key) {
    BinaryNode * keyNode = find(root, key);

    return keyNode == nullptr ?
        -1 : next(keyNode);
}


int BinarySearchTree::
prev(BinaryNode * node) {

    // El prev el el máxmimo valor del subárbol izquierdo
    if (node->left != nullptr) {
        return findMax(node->left);

    // Si no hay subárbol izquierdo
    } else {
        BinaryNode * parentNode = node->parent;
        BinaryNode * currentNode = node;

        // Si el nodo actual no es root y
        // el nodo actual es hijo izquierdo
        while ((parentNode != nullptr) && (currentNode == parentNode->left)) {
            currentNode = parentNode;
            parentNode = currentNode->parent;
        }

        // Si el nodo no es root entonces su padre es el prev
        return parentNode == nullptr ?
            -1 : parentNode->key;
    }
}

int BinarySearchTree::
prev(int key) {
    BinaryNode * keyNode = find(root, key);

    return keyNode == nullptr ?
        -1 : prev(keyNode);
}


BinaryNode * BinarySearchTree::
remove(BinaryNode * node, int key) {

    // No se encuentra el nodo
    if (node == nullptr)
        return nullptr;

    // Se encuentra el nodo
    if (node->key == key) {

        // Si el nodo es una hoja, se puede borrar
        if (node->left == nullptr && node->right == nullptr)
            node = nullptr;

        // El nodo solo tiene un hijo en la derecha
        else if (node->left == nullptr && node->right != nullptr) {

            // El único hijo se conecta al nuevo padre
            node->right->parent = node->parent;

            // Saltamos de nodo
            node = node->right;

        // El nodo solo tiene un hijo en la izquierda
        } else if (node->left != nullptr && node->right == nullptr) {

            // El único hijo se conecta al nuevo padre
            node->left->parent = node->parent;

            // Saltamos de nodo
            node = node->left;

        // El nodo tiene dos hijos (izquierda y derecha)
        } else {

            // Busca el next (o prev) para evitar conflicto
            int successorKey = next(key);

            // Sustituye la key del nodo con la del next
            node->key = successorKey;

            // Borra la llave del next antiguo
            node->right = remove(node->right, successorKey);
        }

    // La key del nodo actual es menor que la key dada
    // Buscamos por la derecha
    } else if (node->key < key) {
        node->right = remove(node->right, key);

    // La key del nodo actual es mayor que la key dada
    // Buscamos por la izquierda
    } else {
        node->left = remove(node->left, key);
    }

    // Devolvemos el árbol modificado
    return node;
}

void BinarySearchTree::
remove(int key) {
    root = remove(root, key);
}


void BinarySearchTree::
removeLessThan(BinaryNode * node, int key) {

    if (node == nullptr)
        return;

    if (node->key < key) {
        removeLessThan(node->left, key);
        removeLessThan(node->right, key);
        remove(node->key);
    } else {
        removeLessThan(node->left, key);
    }
}

void BinarySearchTree::
removeLessThan(int key) {
    removeLessThan(root, key);
}


void BinarySearchTree::
removeMoreThan(BinaryNode * node, int key) {

    if (node == nullptr)
        return;

    if (node->key > key) {
        removeMoreThan(node->left, key);
        removeMoreThan(node->right, key);
        remove(node->key);
    } else {
        removeMoreThan(node->right, key);
    }
}

void BinarySearchTree::
removeMoreThan(int key) {
    removeMoreThan(root, key);
}


void BinarySearchTree::
prune(BinaryNode * node, int key) {
    if (node == nullptr)
        return;

    if (find(key)) {
        prune(node->left, key);
        prune(node->right, key);
        remove(key);
    }
}

void BinarySearchTree::
prune(int key) {
    prune(root, key);
}
