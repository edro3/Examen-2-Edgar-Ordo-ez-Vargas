#include <iostream>   // Necesario para std::cout, std::cerr, std::endl
#include <fstream>    // Necesario para std::ifstream (lectura de archivos)
#include <vector>     // Necesario para std::vector (almacenar la lista de palabras/frases)
#include <string>     // Necesario para std::string (manejar las palabras/frases)
#include <utility>    // Necesario para std::pair y std::make_pair
#include <cctype>     // Necesario para tolower(), isspace(), isdigit(), isalpha(), isupper()
#include <algorithm>  // Necesario para std::find_if
#include <iomanip>    // Necesario para std::setw (para formato de tabla)
#include <clocale>    // Necesario para setlocale()


std::string toLower(std::string s) {
    for (size_t i = 0; i < s.length(); ++i) {
        s[i] = static_cast<char>(tolower(static_cast<unsigned char>(s[i])));
    }
    return s;
}


bool isNotSpace(char c) {
    return !std::isspace(static_cast<unsigned char>(c));
}


std::string trim(std::string s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), isNotSpace));
    s.erase(std::find_if(s.rbegin(), s.rend(), isNotSpace).base(), s.end());
    return s;
}


bool esNumerico(const std::string& s) {
    if (s.empty()) {
        return false;
    }
    for (size_t i = 0; i < s.length(); ++i) {
        if (!std::isdigit(static_cast<unsigned char>(s[i]))) {
            return false;
        }
    }
    return true;
}


bool esSoloAlfabetico(const std::string& s) {
    if (s.empty()) {
        return false;
    }
    for (size_t i = 0; i < s.length(); ++i) {
        if (!std::isalpha(static_cast<unsigned char>(s[i]))) {
            return false;
        }
    }
    return true;
}


std::string alternarMayusculasMinusculas(std::string s) {
    for (size_t i = 0; i < s.length(); ++i) {
        if (i % 2 == 0) { 
            s[i] = static_cast<char>(toupper(static_cast<unsigned char>(s[i])));
        } else { 
            s[i] = static_cast<char>(tolower(static_cast<unsigned char>(s[i])));
        }
    }
    return s;
}

int main() {
    
    std::setlocale(LC_ALL, "Spanish"); 
    

    std::vector<std::string> palabras_del_archivo;
    std::string linea_leida;

   
    std::ifstream archivo("palabras.txt");

    
    if (archivo.is_open()) {
        while (getline(archivo, linea_leida)) {
            palabras_del_archivo.push_back(linea_leida);
        }
        archivo.close(); 
    } else {
        std::cerr << "Error: No se pudo abrir el archivo palabras.txt. Asegúrate de que esté en el mismo directorio que el ejecutable o que la ruta sea correcta." << std::endl;
        return 1; 
    }

    std::cout << "--- Ejercicios de Manipulación de Cadenas (Datos de palabras.txt) ---\n" << std::endl;

    
    std::cout << "1. Limpieza de nombre de animal con espacios:\n";
    if (palabras_del_archivo.size() > 1) {
        std::string animal_con_espacios = palabras_del_archivo[1]; 
        std::string animal_limpio = trim(animal_con_espacios);
        std::cout << std::left << std::setw(20) << "Original:" << "'" << animal_con_espacios << "'" << std::endl;
        std::cout << std::left << std::setw(20) << "Limpio:" << "'" << animal_limpio << "'" << std::endl;
    } else {
        std::cout << "No hay suficientes datos en palabras.txt para este ejercicio." << std::endl;
    }
    std::cout << "\n";

    
    std::cout << "2. Transformación de lenguaje de programación para encabezado:\n";
    std::string lenguaje_prog_min = "c++"; 
    std::string lenguaje_prog_encabezado = "C++"; 
    std::cout << "Original: '" << lenguaje_prog_min << "'" << std::endl;
    std::cout << "Como encabezado: '" << lenguaje_prog_encabezado << " Programming Language'" << std::endl;
    std::cout << "\n";

    
    std::cout << "3. Verificación de valor numérico:\n";
    if (palabras_del_archivo.size() > 15) {
        std::string valor_a_verificar = palabras_del_archivo[15]; 
        std::cout << "Valor: '" << valor_a_verificar << "'" << std::endl;
        if (esNumerico(valor_a_verificar)) {
            std::cout << "Puede ser interpretado como un valor cuantitativo (es numérico)." << std::endl;
        } else {
            std::cout << "No puede ser interpretado como un valor cuantitativo (no es puramente numérico)." << std::endl;
        }
    } else {
        std::cout << "No hay suficientes datos en palabras.txt para este ejercicio." << std::endl;
    }
    std::cout << "\n";

    
    std::cout << "4. Extracción de referencia visible de frase de agua:\n";
    if (palabras_del_archivo.size() > 3) {
        std::string frase_agua = palabras_del_archivo[3]; 
        std::string lo_visible;
        size_t pos_espacio = frase_agua.find(' ');
        if (pos_espacio != std::string::npos) {
            lo_visible = frase_agua.substr(pos_espacio + 1);
        } else {
            lo_visible = "No se encontró un segundo término.";
        }
        std::cout << "Frase original: '" << frase_agua << "'" << std::endl;
        std::cout << "Referencia a lo visible: '" << lo_visible << "'" << std::endl;
    } else {
        std::cout << "No hay suficientes datos en palabras.txt para este ejercicio." << std::endl;
    }
    std::cout << "\n";

    
    std::cout << "5. Validación de identificador alfabético:\n";
    if (palabras_del_archivo.size() > 17) {
        std::string identificador_combinado = palabras_del_archivo[17]; 
        std::cout << "Identificador: '" << identificador_combinado << "'" << std::endl;
        if (esSoloAlfabetico(identificador_combinado)) {
            std::cout << "Es un identificador puramente alfabético." << std::endl;
        } else {
            std::cout << "NO es un identificador puramente alfabético (contiene números o caracteres no alfabéticos)." << std::endl;
        }
    } else {
        std::cout << "No hay suficientes datos en palabras.txt para este ejercicio." << std::endl;
    }
    std::cout << "\n";

    std::cout << "6. Estandarización de términos de lenguaje de programación para comparación:\n";
    std::vector<std::string> terminos_cxx_del_archivo;
    
    for (size_t i = 0; i < palabras_del_archivo.size(); ++i) {
        std::string temp_s = toLower(trim(palabras_del_archivo[i]));
        if (temp_s.find("c++") != std::string::npos) {
             terminos_cxx_del_archivo.push_back(palabras_del_archivo[i]);
        }
    }

    if (!terminos_cxx_del_archivo.empty()) {
        for (size_t i = 0; i < terminos_cxx_del_archivo.size(); ++i) {
            std::string original = terminos_cxx_del_archivo[i];
            std::string estandarizado = toLower(trim(original)); 
            std::cout << "Original: '" << original << "' -> Estandarizado: '" << estandarizado << "'" << std::endl;
        }
    } else {
        std::cout << "No se encontraron términos relacionados con C++ en palabras.txt." << std::endl;
    }
    std::cout << "\n";

    std::cout << "7. Transformación de frase pacífica con formato desigual:\n";
    if (palabras_del_archivo.size() > 27) {
        std::string frase_pacifica = palabras_del_archivo[27]; 
        std::string frase_alternada = alternarMayusculasMinusculas(frase_pacifica);
        std::cout << "Original: '" << frase_pacifica << "'" << std::endl;
        std::cout << "Alternada: '" << frase_alternada << "'" << std::endl;
    } else {
        std::cout << "No hay suficientes datos en palabras.txt para este ejercicio." << std::endl;
    }
    std::cout << "\n";

    std::cout << "8. Detección de mención de división de cadenas:\n";
    if (palabras_del_archivo.size() > 19) {
        std::string frase_strtok = palabras_del_archivo[19]; 
        std::string palabra_clave = "strtok";
        size_t posicion = frase_strtok.find(palabra_clave);

        std::cout << "Frase: '" << frase_strtok << "'" << std::endl;
        if (posicion != std::string::npos) {
            std::cout << "La mención '" << palabra_clave << "' comienza en la posición: " << posicion << std::endl;
        } else {
            std::cout << "La mención '" << palabra_clave << "' no fue encontrada." << std::endl;
        }
    } else {
        std::cout << "No hay suficientes datos en palabras.txt para este ejercicio." << std::endl;
    }
    std::cout << "\n";

    std::cout << "9. Limpieza de frases con residuos al final:\n";
    if (palabras_del_archivo.size() > 13) {
        std::string frase_con_residuos = palabras_del_archivo[13]; 
        std::string frase_limpia_residuo = trim(frase_con_residuos);

        std::cout << "Original: '" << frase_con_residuos << "'" << std::endl;
        std::cout << "Limpia: '" << frase_limpia_residuo << "'" << std::endl;
    } else {
        std::cout << "No hay suficientes datos en palabras.txt para este ejercicio." << std::endl;
    }

    std::string otra_frase_con_residuo = "jugar fútbol   ";
    std::string otra_frase_limpia = trim(otra_frase_con_residuo);
    std::cout << "Original (ejemplo extra): '" << otra_frase_con_residuo << "'" << std::endl;
    std::cout << "Limpia (ejemplo extra): '" << otra_frase_limpia << "'" << std::endl;
    std::cout << "\n";

    std::cout << "10. Recuperación de información escondida en texto 'vacío':\n";
    std::string texto_aparentemente_vacio = "";
    std::string info_escondida = "Título Principal Recopilado";
    
    texto_aparentemente_vacio.insert(0, info_escondida);
    
    std::cout << "Texto recuperado y presentado como título: '" << texto_aparentemente_vacio << "'" << std::endl;
    std::cout << "\n";

    return 0;
}
