#include <iostream>
#include <string>

using namespace std;

int main() {
    /* Escreva um programa que inverta os caracteres de um string.
    IMPORTANTE:
    a) Essa string pode ser informada através de qualquer entrada
    de sua preferência ou pode ser previamente definida no código;
    b) Evite usar funções prontas, como, por exemplo, reverse; */


    string entrada, invertida;

    // Solicita ao usuário que insira a string
    cout << "Digite uma string: ";
    getline(cin, entrada);

    // Inverte os caracteres da string
    for (int i = entrada.length() - 1; i >= 0; i--) {
        invertida += entrada[i];
    }

    // Imprime a string invertida
    cout << "String invertida: " << invertida << endl;

    return 0;
}
