#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;
/*Dado um vetor que guarda o valor de faturamento diário de uma distribuidora, 
faça um programa, na linguagem que desejar, que calcule e retorne:
• O menor valor de faturamento ocorrido em um dia do mês;
• O maior valor de faturamento ocorrido em um dia do mês;
• Número de dias no mês em que o valor de faturamento diário foi superior à média mensal.

IMPORTANTE:
a) Usar o json ou xml disponível como fonte dos dados do faturamento mensal;
b) Podem existir dias sem faturamento, como nos finais de semana e feriados. Estes dias 
devem ser ignorados no cálculo da média;*/

// Função para ler os dados do faturamento do arquivo JSON
vector<double> lerFaturamentoDoArquivo(const string& nomeArquivo) {
    vector<double> faturamento;
    
    // Abrindo o arquivo para leitura
    ifstream arquivo("JSONdata.txt");
    
    // Verificando se o arquivo foi aberto com sucesso
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo " << nomeArquivo << endl;
        return faturamento; // Retorna vetor vazio se não for possível abrir o arquivo
    }
    
    // Lendo o conteúdo do arquivo linha por linha
    string linha;
    while (getline(arquivo, linha)) {
        // Ignorando linhas vazias
        if (linha.empty()) {
            continue;
        }
        
        // Criando um fluxo de string para processar a linha
        stringstream ss(linha);
        
        // Lendo o valor do faturamento e armazenando no vetor
        double valor;
        ss >> valor;
        faturamento.push_back(valor);
    }
    
 
    arquivo.close();
    
    return faturamento;
}

int main() {
    // Lendo os dados do faturamento do arquivo JSON
    vector<double> faturamento = lerFaturamentoDoArquivo("faturamento.json");
    
    // Verificando se houve algum erro na leitura dos dados
    if (faturamento.empty()) {
        return 1; // Retornando 1 para indicar erro na execução do programa
    }
    
    // Calculando o menor e o maior valor de faturamento
    double menorFaturamento = *min_element(faturamento.begin(), faturamento.end());
    double maiorFaturamento = *max_element(faturamento.begin(), faturamento.end());
    
    // Calculando a média mensal de faturamento (ignorando dias sem faturamento)
    double somaFaturamento = 0.0;
    int diasComFaturamento = 0;
    for (double valor : faturamento) {
        if (valor > 0) {
            somaFaturamento += valor;
            diasComFaturamento++;
        }
    }
    double mediaMensal = diasComFaturamento > 0 ? somaFaturamento / diasComFaturamento : 0.0;
    
    // Contando o número de dias com faturamento superior à média mensal
    int diasAcimaDaMedia = 0;
    for (double valor : faturamento) {
        if (valor > mediaMensal) {
            diasAcimaDaMedia++;
        }
    }
    
    // Imprimindo os resultados
    cout << "Menor valor de faturamento: " << fixed << setprecision(2) << menorFaturamento << endl;
    cout << "Maior valor de faturamento: " << fixed << setprecision(2) << maiorFaturamento << endl;
    cout << "Número de dias com faturamento acima da média mensal: " << diasAcimaDaMedia << endl;
    
    return 0; // Retornando 0 para indicar que o programa foi executado com sucesso
}
