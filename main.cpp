#include <iostream>
using namespace std;
int procesarArreglo(char alfaabeto[], int totalalfabeto) {
    cout << "Tamaño recibido (sin el \\0): " << totalalfabeto << endl;
    // Aquí ya puedes usar 'tam' para tus bucles
    return totalalfabeto;
}
char * cifrado(char clave[], int n, char alfabeto[]){
   char * palabraCifrada = new char[n];  
    for (int i = 0; i < n; i++) {
        bool encontrado = false;
        
        // Segundo bucle: recorre el arreglo principal para comparar
        for (int j = 0; j < 53; j++) {
            if (clave[i] == alfabeto[j]) {
                encontrado = true;
                palabraCifrada[i]=alfabeto[j + i + 1];
                break; // Si lo encuentra, deja de buscar este numero
            }
        }
        if (!encontrado) {
            cout << "el elemento no fue encontrado, ? "; // Por si ingresan un símbolo que no está en el alfabeto
        }
    }
    return palabraCifrada;
}
//void * descifrado(char Cifrado, char alfabeto[], char totalalfabeto){
  // cout<<"mostrar: ">> alfabeto;

//}

int main()
{
    char alfabeto[]={
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
    'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
    'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D',
    'E', 'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
    'U', 'V', 'W', 'X', 'Y', 'Z'
    };
    int totalalfabeto = sizeof(alfabeto) - 1;
    procesarArreglo(alfabeto, totalalfabeto);
    cout << "Tamaño recibido (sin el \\0): " << totalalfabeto << endl;
    int n;
    cout << "Ingrese el numero de letras de la palbra que desea ingresar(Ingrese enteros): ";
    cin >>n;
    char clave[n + 1];
    cout<<"Ingresar la clave: ";
    cin>>clave;
    cin.ignore(); 
    char clavecifrada[n + 1];
    char * palabraCifrada = cifrado(clave, n, alfabeto);
    cout<<"mostrar clave cifrada: "<< palabraCifrada <<endl;
    int valorNumerico = + 1;
    //gdescifrado*(alfabeto, palabracifrada, totalalfabeto);
    return 0;
}