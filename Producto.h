#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <iostream>
#include <iomanip>

class Producto {
public:
    int id;
    std::string nombre;
    float precio;
    std::string categoria;
    int stock;
    float calificacionPromedio;

    Producto();
    Producto(int _id, std::string _nombre, float _precio, 
             std::string _categoria, int _stock, float _calificacion);

    void mostrar() const;
    static bool compararPorPrecio(const Producto& a, const Producto& b);
    static bool compararPorCalificacion(const Producto& a, const Producto& b);
    static bool compararPorId(const Producto& a, const Producto& b);
};

#endif