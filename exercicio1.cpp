#include <iostream>
#include <vector>

using namespace std;
/*Dado a sequência de Fibonacci, onde se inicia por 0 e 1 e o próximo valor sempre será a soma dos 2 valores
 anteriores (exemplo: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34...), escreva um programa na linguagem que desejar onde, 
 informado um número, ele calcule a sequência de Fibonacci e retorne uma mensagem avisando se o número 
 informado pertence ou não a sequência.

IMPORTANTE:
Esse número pode ser informado através de qualquer entrada de sua preferência ou pode ser previamente definido
no código;*/

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
