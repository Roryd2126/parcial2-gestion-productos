#include "Busqueda.h"

int Busqueda::busquedaBinaria(const std::vector<Producto>& arr, int id) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid].id == id) return mid;
        if (arr[mid].id < id) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

std::vector<int> Busqueda::busquedaLinealNombre(const std::vector<Producto>& arr, const std::string& subcadena) {
    std::vector<int> resultados;
    for (int i = 0; i < (int)arr.size(); i++) {
        if (arr[i].nombre.find(subcadena) != std::string::npos) {
            resultados.push_back(i);
        }
    }
    return resultados;
}