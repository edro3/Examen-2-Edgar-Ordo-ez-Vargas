#include <iostream> // Necesario para std::cout (imprimir en consola)
#include <vector>   // Necesario para std::vector (almacenar la lista de palabras a buscar)
#include <string>   // Necesario para std::string (manejar las palabras y la sopa de letras)
#include <utility>  // Necesario para std::pair (devolver la fila y columna como un par)
#include <cctype>   // Necesario para tolower() (convertir caracteres a minúsculas para la búsqueda)


const int FILAS = 10;
const int COLUMNAS = 10; 

char sopa[FILAS][COLUMNAS] = {
    'f', 'j', 'f', 'b', 'm', 'x', 'o', 'm', 'n', 'u', // Fila 0
    'j', 'h', 's', 'x', 'a', 'o', 'n', 'r', 'o', 't', // Fila 1
    'j', 'u', 'n', 'h', 'r', 's', 'y', 'g', 'h', 'b', // Fila 2
    'b', 'w', 'l', 'e', 't', 'r', 'y', 'h', 't', 'v', // Fila 3
    'b', 'i', 'n', 'g', 'e', 'q', 'j', 'e', 'y', 'v', // Fila 4
    'x', 'x', 'w', 'u', 'l', 'a', 'q', 'x', 'p', 'l', // Fila 5
    'r', 'e', 'c', 'o', 'n', 'r', 'a', 'd', 'a', 'r', // Fila 6
    'o', 'n', 'c', 'e', 'l', 'o', 'f', 'Y', 'j', 'n', // Fila 7
    'e', 'p', 'y', 't', 'r', 'e', 't', 'o', 'z', 'f', // Fila 8
    'o', 'z', 'u', 'l', 'c', 'l', 'a', 's', 'e', 'f'  // Fila 9
};

int dx[] = {0, 0, 1, -1, 1, -1, 1, -1}; 
int dy[] = {1, -1, 0, 0, 1, -1, -1, 1}; 

std::pair<int, int> buscarPalabra(const std::string& palabra) {
    
    for (int fila = 0; fila < FILAS; ++fila) {
        for (int col = 0; col < COLUMNAS; ++col) { 
                        if (sopa[fila][col] == palabra[0]) { 
                                for (int dir = 0; dir < 8; ++dir) {
                    int k; 
                    int nuevaFila = fila;
                    int nuevaCol = col;

                                        for (k = 0; k < palabra.length(); ++k) {
                        if (nuevaFila >= 0 && nuevaFila < FILAS &&
                            nuevaCol >= 0 && nuevaCol < COLUMNAS &&
                            sopa[nuevaFila][nuevaCol] == palabra[k]) {
                            nuevaFila += dx[dir];
                            nuevaCol += dy[dir];
                        } else {
                            break;
                        }
                    }

                    if (k == palabra.length()) {
                        
                        return std::make_pair(fila + 1, col + 1); 
                    }
                }
            }
        }
    }
    
    return std::make_pair(-1, -1); 
}

int main() {
    std::vector<std::string> palabras_a_buscar;
    palabras_a_buscar.push_back("LETRA");
    palabras_a_buscar.push_back("LUZ");
    palabras_a_buscar.push_back("RETO");
    palabras_a_buscar.push_back("CLASE");
    palabras_a_buscar.push_back("RADAR");
    palabras_a_buscar.push_back("PYTHON");

    std::cout << "Buscando palabras en la sopa de letras:" << std::endl;

    for (size_t i = 0; i < palabras_a_buscar.size(); ++i) {
        std::string palabra = palabras_a_buscar[i];

        std::string palabra_lower = palabra;
        for (size_t j = 0; j < palabra_lower.length(); ++j) {
            palabra_lower[j] = static_cast<char>(tolower(static_cast<unsigned char>(palabra_lower[j])));
        }

        std::pair<int, int> ubicacion = buscarPalabra(palabra_lower);

        if (ubicacion.first != -1) {
            std::cout << "Palabra '" << palabra << "' encontrada en: FIL "
                      << ubicacion.first << ", COL " << ubicacion.second << std::endl;
        } else {
            std::cout << "Palabra '" << palabra << "' NO encontrada." << std::endl;
        }
    }

    return 0;
}

