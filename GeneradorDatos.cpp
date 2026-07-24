#include "GeneradorDatos.h"
#include <cstdlib>

const std::vector<std::string> GeneradorDatos::NOMBRES_BASE = {
    "Laptop", "Smartphone", "Tablet", "Audifonos", "Teclado", 
    "Mouse", "Monitor", "Camara", "Impresora", "Router",
    "Camisa", "Pantalon", "Vestido", "Chaqueta", "Zapatos",
    "Bufanda", "Gorra", "Bolso", "Reloj", "Cinturon",
    "Libro", "Cuaderno", "Boligrafo", "Lapiz", "Borrador",
    "Sofa", "Mesa", "Silla", "Lampara", "Espejo",
    "Taza", "Plato", "Cuchara", "Tenedor", "Cuchillo",
    "Pelota", "Raqueta", "Bicicleta", "Patineta", "Balon"
};

const std::vector<std::string> GeneradorDatos::CATEGORIAS = {
    "Electronica", "Ropa", "Libros", "Hogar", "Deportes"
};

std::string GeneradorDatos::generarNombre() {
    return NOMBRES_BASE[rand() % NOMBRES_BASE.size()] + " " + std::to_string(rand() % 100 + 1);
}

std::string GeneradorDatos::generarCategoria() {
    return CATEGORIAS[rand() % CATEGORIAS.size()];
}

float GeneradorDatos::generarPrecio() {
    return (rand() % 20000 + 100) / 100.0f;
}

int GeneradorDatos::generarStock() {
    return rand() % 200 + 1;
}

float GeneradorDatos::generarCalificacion() {
    return (rand() % 401 + 100) / 100.0f;
}

std::vector<Producto> GeneradorDatos::generarProductos(int cantidad) {
    std::vector<Producto> productos;
    for (int i = 0; i < cantidad; i++) {
        productos.push_back(Producto(i + 1, generarNombre(), generarPrecio(),
                                     generarCategoria(), generarStock(), generarCalificacion()));
    }
    return productos;
}