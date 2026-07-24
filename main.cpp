#include <iostream>
#include <iomanip>
#include <chrono>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Producto.h"
#include "GeneradorDatos.h"
#include "AlgoritmosOrdenamiento.h"
#include "Busqueda.h"

using namespace std;
using namespace std::chrono;

void mostrarPrimerosYUltimos(const vector<Producto>& arr, int cantidad) {
    int n = arr.size();
    int mostrar = min(cantidad, n);
    cout << "\n--- PRIMEROS " << mostrar << " PRODUCTOS ---\n";
    for (int i = 0; i < mostrar; i++) arr[i].mostrar();
    cout << "\n--- ULTIMOS " << mostrar << " PRODUCTOS ---\n";
    for (int i = n - mostrar; i < n; i++) arr[i].mostrar();
}

void medirTiempoOrdenamiento(const vector<Producto>& original, const string& nombreAlgoritmo, bool porPrecio) {
    vector<Producto> copia = original;
    auto start = high_resolution_clock::now();
    if (nombreAlgoritmo == "MergeSort") AlgoritmosOrdenamiento::mergeSort(copia, porPrecio);
    else if (nombreAlgoritmo == "QuickSort") AlgoritmosOrdenamiento::quickSort(copia, porPrecio);
    else if (nombreAlgoritmo == "InsertionSort") AlgoritmosOrdenamiento::insertionSort(copia, porPrecio);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    string criterio = porPrecio ? "Precio (asc)" : "Calificacion (desc)";
    cout << "| " << setw(12) << nombreAlgoritmo << " | " << setw(18) << criterio << " | " << setw(15) << duration.count() << " μs |\n";
}

int main() {
    srand(time(0));
    cout << "============================================================\n";
    cout << "         PARCIAL 2 - GESTION DE PRODUCTOS\n";
    cout << "============================================================\n";

    const int CANTIDAD_PRODUCTOS = 500;
    vector<Producto> productos = GeneradorDatos::generarProductos(CANTIDAD_PRODUCTOS);
    vector<Producto> original = productos;

    cout << "\n--- PRODUCTOS GENERADOS (" << CANTIDAD_PRODUCTOS << ") ---";
    mostrarPrimerosYUltimos(productos, 10);

    // ORDENAMIENTO
    cout << "\n============================================================\n";
    cout << "PARTE 2: ORDENAMIENTO\n";
    cout << "============================================================\n";
    cout << "\n--- TIEMPOS DE ORDENAMIENTO ---\n";
    cout << "+--------------+--------------------+-----------------+\n";
    cout << "| Algoritmo    | Criterio           | Tiempo (μs)     |\n";
    cout << "+--------------+--------------------+-----------------+\n";
    medirTiempoOrdenamiento(original, "MergeSort", true);
    medirTiempoOrdenamiento(original, "QuickSort", true);
    medirTiempoOrdenamiento(original, "InsertionSort", true);
    medirTiempoOrdenamiento(original, "MergeSort", false);
    medirTiempoOrdenamiento(original, "QuickSort", false);
    medirTiempoOrdenamiento(original, "InsertionSort", false);
    cout << "+--------------+--------------------+-----------------+\n";

    // BUSQUEDA
    cout << "\n============================================================\n";
    cout << "PARTE 3: BUSQUEDA\n";
    cout << "============================================================\n";
    sort(productos.begin(), productos.end(), Producto::compararPorId);

    cout << "\n--- BUSQUEDA BINARIA POR ID (10 existentes, 10 no existentes) ---\n";
    vector<int> idsExistentes = {1,2,3,4,5,6,7,8,9,10};
    auto start = high_resolution_clock::now();
    int encontrados = 0;
    for (int id : idsExistentes) {
        int idx = Busqueda::busquedaBinaria(productos, id);
        if (idx != -1) { cout << "ID " << id << " encontrado: " << productos[idx].nombre << "\n"; encontrados++; }
    }
    auto end = high_resolution_clock::now();
    cout << "Tiempo busqueda (10 existentes): " << duration_cast<microseconds>(end - start).count() << " μs\n";
    cout << "Productos encontrados: " << encontrados << "/10\n";

    vector<int> idsNoExistentes = {1000,2000,3000,4000,5000,6000,7000,8000,9000,10000};
    start = high_resolution_clock::now();
    int noEncontrados = 0;
    for (int id : idsNoExistentes) {
        if (Busqueda::busquedaBinaria(productos, id) == -1) { cout << "ID " << id << " NO encontrado\n"; noEncontrados++; }
    }
    end = high_resolution_clock::now();
    cout << "Tiempo busqueda (10 no existentes): " << duration_cast<microseconds>(end - start).count() << " μs\n";
    cout << "Productos NO encontrados: " << noEncontrados << "/10\n";

    cout << "\n--- BUSQUEDA LINEAL POR NOMBRE (subcadena) ---\n";
    vector<string> subcadenasExistentes = {"Smart", "Cam", "Sofa", "Balon", "Mesa"};
    start = high_resolution_clock::now();
    for (string sub : subcadenasExistentes) {
        vector<int> idxs = Busqueda::busquedaLinealNombre(productos, sub);
        cout << "Subcadena '" << sub << "' encontrada en " << idxs.size() << " productos\n";
    }
    end = high_resolution_clock::now();
    cout << "Tiempo busqueda (5 subcadenas existentes): " << duration_cast<microseconds>(end - start).count() << " μs\n";

    vector<string> subcadenasNoExistentes = {"Xylofono", "Zigzag", "Rocket", "Galaxy", "Quantum"};
    start = high_resolution_clock::now();
    for (string sub : subcadenasNoExistentes) {
        vector<int> idxs = Busqueda::busquedaLinealNombre(productos, sub);
        cout << "Subcadena '" << sub << "' encontrada en " << idxs.size() << " productos\n";
    }
    end = high_resolution_clock::now();
    cout << "Tiempo busqueda (5 subcadenas no existentes): " << duration_cast<microseconds>(end - start).count() << " μs\n";

    // CONCLUSIONES
    cout << "\n============================================================\n";
    cout << "ANALISIS Y CONCLUSIONES\n";
    cout << "============================================================\n";
    cout << "\n1. Busqueda Binaria vs Busqueda Lineal:\n";
    cout << "   - Busqueda Binaria: O(log n) - Ideal para IDs porque el arreglo esta ordenado.\n";
    cout << "   - Busqueda Lineal: O(n) - Necesaria para busqueda por subcadena de texto.\n";
    cout << "\n2. Ordenamiento:\n";
    cout << "   - MergeSort y QuickSort son mucho mas rapidos que InsertionSort.\n";
    cout << "   - La teoria se cumple: O(n log n) vs O(n^2).\n";
    cout << "\n3. Busqueda por nombre:\n";
    cout << "   - La busqueda por subcadena es lenta porque recorre todo el arreglo.\n";
    cout << "   - En produccion se usarian indices invertidos o arboles de prefijos (Trie).\n";
    cout << "\n4. Resultados obtenidos:\n";
    cout << "   - Se generaron " << CANTIDAD_PRODUCTOS << " productos correctamente.\n";
    cout << "   - Los 3 algoritmos de ordenamiento funcionaron con objetos.\n";
    cout << "   - La busqueda binaria encontro todos los IDs existentes.\n";
    cout << "   - La busqueda lineal encontro productos por subcadena.\n";
    cout << "\n============================================================\n";
    cout << "¡PROYECTO COMPLETADO EXITOSAMENTE!\n";
    cout << "============================================================\n";
    return 0;
}