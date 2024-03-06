#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    // Definindo um mapa para armazenar os valores de faturamento por estado
    map<string, double> faturamentoPorEstado = {
        {"SP", 67836.43},
        {"RJ", 36678.66},
        {"MG", 29229.88},
        {"ES", 27165.48},
        {"Outros", 19849.53}
    };
    
    // Calculando o valor total do faturamento mensal
    double faturamentoTotal = 0.0;
    for (const auto& par : faturamentoPorEstado) {
        faturamentoTotal += par.second;
    }
    
    // Imprimindo o percentual de representação de cada estado
    cout << "Percentual de representacao de cada estado:" << endl;
    cout << fixed << setprecision(2);
    for (const auto& par : faturamentoPorEstado) {
        double percentual = (par.second / faturamentoTotal) * 100.0;
        cout << par.first << " - " << percentual << "%" << endl;
    }
    
    return 0;
}
