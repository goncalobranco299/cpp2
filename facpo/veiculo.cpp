#include "veiculo.h"

Veiculo::Veiculo(string nome, string rodas, int velocidadeAtual, int velocidadeMaxima)
{
    this -> nome = nome;  // Inicializa a variável membro 'nome' com o valor fornecido
    this -> rodas = rodas;
    this -> velocidadeMaxima = velocidadeMaxima;
    this -> velocidadeAtual = velocidadeAtual;
}

void Veiculo::mostrarDetalhes() // Método que exibe os detalhes do veículo (nome, tipo de rodas, velocidade atual e máxima)
{
    cout << "Nome do veiculo " << nome << endl;
    cout << "Rodas " << rodas << endl;
    cout << "Velocidade atual: " << velocidadeAtual << "km/h" << endl;
    cout << "Velocidade maxima: " << velocidadeMaxima << "km/h" << endl;
}

void Veiculo::acelerar()
{
    while (velocidadeAtual <= velocidadeMaxima)
    {
        cout << "Aceleraste o carro " << velocidadeAtual << endl;
        velocidadeAtual++; // Aumenta a velocidade atual em 1 km/h
    }
    cout << "Velocidade maxima atingida: " << velocidadeMaxima << "km/h" << endl;   
}

void Veiculo::travar()
{
    while (velocidadeAtual >= 0)
    {
        cout << "Estas a travar o carro" << velocidadeAtual << endl;
        velocidadeAtual--;  // Diminui a velocidade atual em 1 km/h
    }
}



