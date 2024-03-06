#include <iostream>
#include <string>

using namespace std;

int main() {
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
