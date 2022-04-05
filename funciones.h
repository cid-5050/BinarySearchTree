#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <vector>
#include <random>
#include <ctime>

std::vector<int> generarNumerosAleatorios(int cantidad) {
    std::vector<int> numeros;

    std::default_random_engine defEngine(std::time(0));
    std::uniform_int_distribution<int> intDistro(0, 999);

    for (int i = 1; i <= cantidad; i++)
        numeros.push_back(intDistro(defEngine));

    return numeros;
}

#endif // FUNCIONES_H
