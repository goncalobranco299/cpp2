#ifndef VEICULO_H // Verifica se o header "VEICULO_H" nao foi defenido
#define VEICULO_H // Define o header "VEICULO_H"

#include <iostream>
using namespace std;

class Veiculo{  
    public:
        Veiculo(string nome, string rodas, int velocidadeMaxima, int velocidadeAtual); // Construtor da classe "Veiculo"
        string nome;
        string rodas;
        int velocidadeMaxima;
        int velocidadeAtual;
        void mostrarDetalhes();
        void acelerar();
        void travar();

};

#endif // Fim da definicao do header "VEICULO_H"

