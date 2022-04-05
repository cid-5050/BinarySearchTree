#include <BinarySearchTree.h>
#include <funciones.h>
#include <iostream>


int main() {
    BinarySearchTree tree;

    for (auto num : generarNumerosAleatorios(50)) {
        try {
            tree.insert(num);
        } catch (std::string e) {
            std::cout << "Intento de insercion de duplicado: "
                      << num << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "Arbol:" << std::endl;
    tree.print();
    std::cout << std::endl;

    std::cout << "SIZE: " << tree.size() << std::endl;
    std::cout << "MIN: " << tree.findMin() << std::endl;
    std::cout << "MAX: " << tree.findMax() << std::endl;

    std::cout << "SEGUNDO: " << tree.next(tree.findMin()) << std::endl;
    std::cout << "ANTEPENULTIMO: " << tree.prev(tree.findMax()) << std::endl;

    std::cout << std::endl;
    std::cout << "69, 420 o 777? ";

    (tree.find(69) or tree.find(420))
            ? std::cout << "Aw YEAH" << std::endl
            : std::cout << "NOPE" << std::endl;

    std::cout << std::endl;
    std::cout << "removeMax()..." << std::endl;
    tree.remove(tree.findMax());
    std::cout << "Nuevo Max: " << tree.findMax() << std::endl;

    std::cout << std::endl;
    std::cout << "removeMin()..." << std::endl;
    tree.remove(tree.findMin());
    std::cout << "Nuevo Min: " << tree.findMin() << std::endl;

    std::cout << std::endl;
    std::cout << "Arbol:" << std::endl;
    tree.print();

    std::cout << std::endl;
    std::cout << "removeLessThan(600)..." << std::endl;
    tree.removeLessThan(600);
    std::cout << "Arbol:" << std::endl;
    tree.print();

    std::cout << std::endl;
    std::cout << "removeMoreThan(800)..." << std::endl;
    tree.removeMoreThan(800);
    std::cout << "Arbol:" << std::endl;
    tree.print();

    std::cout << std::endl;
    std::cout << "Ok!" << std::endl;
    return 0;
}
