#ifndef ALGORITMOS_ORDENAMIENTO_H
#define ALGORITMOS_ORDENAMIENTO_H

#include <vector>
#include "Producto.h"

class AlgoritmosOrdenamiento {
private:
    static void merge(std::vector<Producto>& arr, int left, int mid, int right, bool porPrecio);

public:
    static void mergeSort(std::vector<Producto>& arr, bool porPrecio);
    static void mergeSortRec(std::vector<Producto>& arr, int left, int right, bool porPrecio);
    static void quickSort(std::vector<Producto>& arr, bool porPrecio);
    static void quickSortRec(std::vector<Producto>& arr, int low, int high, bool porPrecio);
    static int partition(std::vector<Producto>& arr, int low, int high, bool porPrecio);
    static void insertionSort(std::vector<Producto>& arr, bool porPrecio);
};

#endif