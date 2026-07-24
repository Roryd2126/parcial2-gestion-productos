#ifndef GENERADOR_DATOS_H
#define GENERADOR_DATOS_H

#include <vector>
#include <string>
#include "Producto.h"

class GeneradorDatos {
private:
    static const std::vector<std::string> NOMBRES_BASE;
    static const std::vector<std::string> CATEGORIAS;

public:
    static std::string generarNombre();
    static std::string generarCategoria();
    static float generarPrecio();
    static int generarStock();
    static float generarCalificacion();
    static std::vector<Producto> generarProductos(int cantidad);
};

#endif