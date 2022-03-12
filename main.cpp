#include <iostream>
#include "arreglo.hpp"
using namespace std;

int main() {
    // Arreglo<int> enteros = {1, 2, 4, 6, 8, 10, 12, 14};
    // for (size_t i = 0; i < enteros.size(); i++)
    // {
    //     cout << enteros[i] << ", ";
    // }
    Arreglo<int> enteros(10);
    cout << "Lleno: " << enteros.full() << endl;
    cout << "Vacio: " << enteros.empty() << endl;
    try
    {
        enteros.push_back(4);
        enteros.push_back(0);
        enteros.push_back(1);
        // enteros.push_back(2);
        for (size_t i = 0; i < enteros.size(); i++)
        {
            cout << enteros[i] << ", ";
        }
        cout << endl;
        cout << "Lleno: " << enteros.full() << endl;
        cout << "Vacio: " << enteros.empty() << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    enteros.push_front(-1);
    enteros.push_front(-2);
    for (size_t i = 0; i < enteros.size(); i++)
    {
        cout << enteros[i] << ", ";
    }
    cout << endl;
    enteros.insert(100, 2);
    for (size_t i = 0; i < enteros.size(); i++)
    {
        cout << enteros[i] << ", ";
    }
    cout<< endl;
    enteros.pop_back();
    for (size_t i = 0; i < enteros.size(); i++)
    {
        cout << enteros[i] << ", ";
    }
    cout << endl;
    enteros.pop_front();
    for (size_t i = 0; i < enteros.size(); i++)
    {
        cout << enteros[i] << ", ";
    }
    cout << endl;
    enteros.erase(0);
    for (size_t i = 0; i < enteros.size(); i++)
    {
        cout << enteros[i] << ", ";
    }
    return 0;
}