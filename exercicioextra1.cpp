#include <iostream>
#include <vector>

using namespace std;

// Função que verifica se um número pertence à sequência de Fibonacci
bool pertenceSequenciaFibonacci(int numero) {

    // Inicializa as duas primeiras variáveis da sequência
    int a = 0; 
    int b = 1; 
    
    // Loop para gerar os números da sequência de Fibonacci até que a ultrapasse o número fornecido
    while (a <= numero) {

        
        if (a == numero) {
            return true; 
        }
        
        // Atualiza os valores de a e b para os próximos números da sequência
        int temp = b; 
        b = a + b; 
        a = temp; 
    }
    
    return false; // Retorna falso se o número fornecido não estiver na sequência
}

// Função principal (main) do programa
int main() {

    int numero; // Variável para armazenar o número fornecido pelo usuário

    // Solicita ao usuário que insira um número
    cout << "Digite um numero: ";
    cin >> numero;

    // Chama a função pertenceSequenciaFibonacci para verificar se o número pertence à sequência de Fibonacci
    if (pertenceSequenciaFibonacci(numero)) {
        
        cout << "O numero pertence a sequencia de Fibonacci." << endl;
    } else {
        
        cout << "O numero NAO pertence a sequencia de Fibonacci." << endl;
    }

    return 0; 
}
