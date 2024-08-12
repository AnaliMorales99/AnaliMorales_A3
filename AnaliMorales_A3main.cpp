/******************************************************************************

                              Online C++ Compiler.
Proyecto final de lenguaje de progrmación  1
Desarrollado por Anali Morales Santos 
11/08/2024
*******************************************************************************/
#include <iostream>
#include <string>
// Función para obtener la primera vocal interna de una cadena
char obtenerPrimeraVocalInterna(const std::string& str) {
    for (size_t i = 1; i < str.length(); ++i) {
        char c = str[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        
            return c;
            
       }
       return 'X'; // si no se encuentra ninguna vocal interna, se usa una X
       }
       
       //Función principal para calcular el RFC
       std::string calcularRFC(const std::string& nombre, const std::string& apellidoPaterno, const std::string& 
       apellidoMaterno,  const  std::string& fechaNacimiento) {
           std::string rfc;
         
        // se obtiene la letra inicial y la primera vocal interna del apellido apellido paterno
        char letraInicial = apellidoPaterno[0];
        char primeraVocalInterna = obtenerPrimeraVocalInterna(apellidoPaterno);
        
        // se obtiene la inicial del apellido materno o se usa una "X" si no hay 
        char inicialApellidoMaterno = (!apellidoMaterno.empty()) ? apellidoMaterno[0] : 'X';
        
        // se obtiene la  inicial del primer nombre o se usa una "X" si no hay
        char inicialNombre = nombre[0];
        
        // se obtienen los dos últimos dígitos del año de nacimiento
        std::string anio = fechaNacimiento.substr(2, 2);
        
        // se obtiene el mes y el día de nacimiento
        std::string mes = fechaNacimiento.substr(5, 2);
        std::string dia = fechaNacimiento.substr(8, 2);
        
        // se construye el RFC
        rfc = letraInicial;
        rfc += primeraVocalInterna;
        rfc += inicialApellidoMaterno;
        rfc += inicialNombre;
        rfc += anio;
        rfc += mes;
        rfc += dia;
        return rfc;
       }
       
       int main() {
           std::string nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento;
           
           std::cout << "Ingrese el nombre: ";
           std::getline(std::cin, nombre);
           
           std::cout << "Ingrese el apellido paterno: ";
           std::getline(std::cin, apellidoPaterno);
           
           std::cout << "Ingrese el apellido materno (si no tiene, presione Enter): ";
           
           std::getline(std::cin, apellidoMaterno);
           std::cout << "Ingrese la fecha de nacimiento (YYYY-MM-DD): ";
           std::getline(std::cin, fechaNacimiento);
           
           std::string rfc = calcularRFC(nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento);
           std::cout << "RFC: " << rfc << std::endl;
           
           return 0;
       }
       
       
