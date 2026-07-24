#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <vector>
#include <string>
#include "Producto.h"

class Busqueda {
public:
    static int busquedaBinaria(const std::vector<Producto>& arr, int id);
    static std::vector<int> busquedaLinealNombre(const std::vector<Producto>& arr, const std::string& subcadena);
};

#endif