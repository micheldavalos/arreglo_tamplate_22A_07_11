#ifndef ARREGLO_H
#define ARREGLO_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
class Arreglo {
    T* arreglo;
    size_t cont{0};
    size_t tam;

public:
    Arreglo(size_t tam):tam(tam) {
        arreglo = new T[tam];
    }
    ~Arreglo() {
        delete[] arreglo;
    }
    Arreglo(const Arreglo<T>& a) {
        arreglo = new T[a.tam];
        for (size_t i = 0; i < a.cont; i++)
        {
            arreglo[i] = a.arreglo[i];
        }
        cont = a.cont;
        tam = a.tam; 
    }
    Arreglo<T>& operator=(const Arreglo<T>& a) {
        delete[] arreglo;

        arreglo = new T[a.tam];
        for (size_t i = 0; i < a.cont; i++)
        {
            arreglo[i] = a.arreglo[i];
        }
        cont = a.cont;
        tam = a.tam; 

        return *this;
    }
    Arreglo(initializer_list<T> e) {
        tam = e.size();
        arreglo = new T[tam];

        auto it = e.begin();
        for (size_t i = 0; i < tam; i++)
        {
            arreglo[i] = *it;
            it++;
            cont++;
        }
        
    }

    T& operator[](size_t pos) { return arreglo[pos]; }

    size_t size() { return cont; }
    size_t max_size() { return tam; }

    bool full() { return cont == tam; }
    bool empty() { return cont == 0; }

    void push_back(const T& e) {
        if (full()) throw out_of_range("Arreglo is full");
                
        arreglo[cont] = e;
        cont++;
    }
    void push_front(const T& e) {
        if (full()) throw out_of_range("Arreglo is full");

        for (size_t i = cont; i > 0; i--) {
            arreglo[i] = arreglo[i-1];
        }
        
        arreglo[0] = e;
        cont++;
    }
    void insert(const T& e, size_t pos) {
        if (full()) throw out_of_range("Arreglo is full");
        else if (pos >= cont) throw out_of_range("Invalid position");

        for (size_t i = cont; i > pos; i--) {
            arreglo[i] = arreglo[i-1];
        }
        arreglo[pos] = e;
        cont++;
    }
    void pop_back() {
        if (empty()) throw out_of_range("Arreglo is empty");
        cont--;
    }
    void pop_front() {
        if (empty()) throw out_of_range("Arreglo is empty");
        for (size_t i = 0; i < cont-1; i++)
        {
            arreglo[i] = arreglo[i+1];
        }
        cont--;        
    }
    void erase(size_t pos) {
        if (empty()) throw out_of_range("Arreglo is empty");
        else if (pos >= cont) throw out_of_range("Invalid position");

        for (size_t i = pos; i < cont-1; i++)
        {
            arreglo[i] = arreglo[i+1];
        }
        cont--;
    }

};

#endif