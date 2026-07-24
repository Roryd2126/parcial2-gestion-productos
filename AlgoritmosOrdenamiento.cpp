#include "AlgoritmosOrdenamiento.h"
#include <algorithm>

// MERGE SORT
void AlgoritmosOrdenamiento::merge(std::vector<Producto>& arr, int left, int mid, int right, bool porPrecio) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<Producto> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        bool cond = porPrecio ? (L[i].precio <= R[j].precio) : (L[i].calificacionPromedio >= R[j].calificacionPromedio);
        if (cond) arr[k] = L[i], i++;
        else arr[k] = R[j], j++;
        k++;
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void AlgoritmosOrdenamiento::mergeSortRec(std::vector<Producto>& arr, int left, int right, bool porPrecio) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortRec(arr, left, mid, porPrecio);
        mergeSortRec(arr, mid + 1, right, porPrecio);
        merge(arr, left, mid, right, porPrecio);
    }
}

void AlgoritmosOrdenamiento::mergeSort(std::vector<Producto>& arr, bool porPrecio) {
    if (arr.size() <= 1) return;
    mergeSortRec(arr, 0, arr.size() - 1, porPrecio);
}

// QUICK SORT
int AlgoritmosOrdenamiento::partition(std::vector<Producto>& arr, int low, int high, bool porPrecio) {
    Producto pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        bool cond = porPrecio ? (arr[j].precio <= pivot.precio) : (arr[j].calificacionPromedio >= pivot.calificacionPromedio);
        if (cond) std::swap(arr[++i], arr[j]);
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void AlgoritmosOrdenamiento::quickSortRec(std::vector<Producto>& arr, int low, int high, bool porPrecio) {
    if (low < high) {
        int pi = partition(arr, low, high, porPrecio);
        quickSortRec(arr, low, pi - 1, porPrecio);
        quickSortRec(arr, pi + 1, high, porPrecio);
    }
}

void AlgoritmosOrdenamiento::quickSort(std::vector<Producto>& arr, bool porPrecio) {
    if (arr.size() <= 1) return;
    quickSortRec(arr, 0, arr.size() - 1, porPrecio);
}

// INSERTION SORT
void AlgoritmosOrdenamiento::insertionSort(std::vector<Producto>& arr, bool porPrecio) {
    for (int i = 1; i < (int)arr.size(); i++) {
        Producto key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            bool cond = porPrecio ? (arr[j].precio > key.precio) : (arr[j].calificacionPromedio < key.calificacionPromedio);
            if (!cond) break;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}