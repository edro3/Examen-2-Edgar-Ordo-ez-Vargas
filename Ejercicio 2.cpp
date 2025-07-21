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
        std::cerr << "Error: No se pudo abrir el archivo palabras.txt. Aseg�rate de que est� en el mismo directorio que el ejecutable o que la ruta sea correcta." << std::endl;
        return 1; 
    }

    std::cout << "--- Ejercicios de Manipulaci�n de Cadenas (Datos de palabras.txt) ---\n" << std::endl;

    
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

    
    std::cout << "2. Transformaci�n de lenguaje de programaci�n para encabezado:\n";
    std::string lenguaje_prog_min = "c++"; 
    std::string lenguaje_prog_encabezado = "C++"; 
    std::cout << "Original: '" << lenguaje_prog_min << "'" << std::endl;
    std::cout << "Como encabezado: '" << lenguaje_prog_encabezado << " Programming Language'" << std::endl;
    std::cout << "\n";

    
    std::cout << "3. Verificaci�n de valor num�rico:\n";
    if (palabras_del_archivo.size() > 15) {
        std::string valor_a_verificar = palabras_del_archivo[15]; 
        std::cout << "Valor: '" << valor_a_verificar << "'" << std::endl;
        if (esNumerico(valor_a_verificar)) {
            std::cout << "Puede ser interpretado como un valor cuantitativo (es num�rico)." << std::endl;
        } else {
            std::cout << "No puede ser interpretado como un valor cuantitativo (no es puramente num�rico)." << std::endl;
        }
    } else {
        std::cout << "No hay suficientes datos en palabras.txt para este ejercicio." << std::endl;
    }
    std::cout << "\n";

    
    std::cout << "4. Extracci�n de referencia visible de frase de agua:\n";
    if (palabras_del_archivo.size() > 3) {
        std::string frase_agua = palabras_del_archivo[3]; 
        std::string lo_visible;
        size_t pos_espacio = frase_agua.find(' ');
        if (pos_espacio != std::string::npos) {
            lo_visible = frase_agua.substr(pos_espacio + 1);
        } else {
            lo_visible = "No se encontr� un segundo t�rmino.";
        }
        std::cout << "Frase original: '" << frase_agua << "'" << std::endl;
        std::cout << "Referencia a lo visible: '" << lo_visible << "'" << std::endl;
    } else {
        std::cout << "No hay suficientes datos en palabras.txt para este ejercicio." << std::endl;
    }
    std::cout << "\n";

    
    std::cout << "5. Validaci�n de identificador alfab�tico:\n";
    if (palabras_del_archivo.size() > 17) {
        std::string identificador_combinado = palabras_del_archivo[17]; 
        std::cout << "Identificador: '" << identificador_combinado << "'" << std::endl;
        if (esSoloAlfabetico(identificador_combinado)) {
            std::cout << "Es un identificador puramente alfab�tico." << std::endl;
        } else {
            std::cout << "NO es un identificador puramente alfab�tico (contiene n�meros o caracteres no alfab�ticos)." << std::endl;
        }
    } else {
        std::cout << "No hay suficientes datos en palabras.txt para este ejercicio." << std::endl;
    }
    std::cout << "\n";

    std::cout << "6. Estandarizaci�n de t�rminos de lenguaje de programaci�n para comparaci�n:\n";
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
        std::cout << "No se encontraron t�rminos relacionados con C++ en palabras.txt." << std::endl;
    }
    std::cout << "\n";

    std::cout << "7. Transformaci�n de frase pac�fica con formato desigual:\n";
    if (palabras_del_archivo.size() > 27) {
        std::string frase_pacifica = palabras_del_archivo[27]; 
        std::string frase_alternada = alternarMayusculasMinusculas(frase_pacifica);
        std::cout << "Original: '" << frase_pacifica << "'" << std::endl;
        std::cout << "Alternada: '" << frase_alternada << "'" << std::endl;
    } else {
        std::cout << "No hay suficientes datos en palabras.txt para este ejercicio." << std::endl;
    }
    std::cout << "\n";

    std::cout << "8. Detecci�n de menci�n de divisi�n de cadenas:\n";
    if (palabras_del_archivo.size() > 19) {
        std::string frase_strtok = palabras_del_archivo[19]; 
        std::string palabra_clave = "strtok";
        size_t posicion = frase_strtok.find(palabra_clave);

        std::cout << "Frase: '" << frase_strtok << "'" << std::endl;
        if (posicion != std::string::npos) {
            std::cout << "La menci�n '" << palabra_clave << "' comienza en la posici�n: " << posicion << std::endl;
        } else {
            std::cout << "La menci�n '" << palabra_clave << "' no fue encontrada." << std::endl;
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

    std::string otra_frase_con_residuo = "jugar f�tbol   ";
    std::string otra_frase_limpia = trim(otra_frase_con_residuo);
    std::cout << "Original (ejemplo extra): '" << otra_frase_con_residuo << "'" << std::endl;
    std::cout << "Limpia (ejemplo extra): '" << otra_frase_limpia << "'" << std::endl;
    std::cout << "\n";

    std::cout << "10. Recuperaci�n de informaci�n escondida en texto 'vac�o':\n";
    std::string texto_aparentemente_vacio = "";
    std::string info_escondida = "T�tulo Principal Recopilado";
    
    texto_aparentemente_vacio.insert(0, info_escondida);
    
    std::cout << "Texto recuperado y presentado como t�tulo: '" << texto_aparentemente_vacio << "'" << std::endl;
    std::cout << "\n";

    return 0;
}
