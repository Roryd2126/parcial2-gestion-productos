#include "Producto.h"

Producto::Producto() : id(0), nombre(""), precio(0.0f), categoria(""), stock(0), calificacionPromedio(0.0f) {}

Producto::Producto(int _id, std::string _nombre, float _precio, 
                   std::string _categoria, int _stock, float _calificacion) {
    id = _id;
    nombre = _nombre;
    precio = _precio;
    categoria = _categoria;
    stock = _stock;
    calificacionPromedio = _calificacion;
}

void Producto::mostrar() const {
    std::cout << "ID: " << id << " | Nombre: " << nombre 
              << " | Precio: $" << std::fixed << std::setprecision(2) << precio
              << " | Categoria: " << categoria << " | Stock: " << stock
              << " | Calificacion: " << calificacionPromedio << std::endl;
}

bool Producto::compararPorPrecio(const Producto& a, const Producto& b) {
    return a.precio < b.precio;
}

bool Producto::compararPorCalificacion(const Producto& a, const Producto& b) {
    return a.calificacionPromedio > b.calificacionPromedio;
}

bool Producto::compararPorId(const Producto& a, const Producto& b) {
    return a.id < b.id;
}.