#ifndef CARRO_H
#define CARRO_H

#include "veiculo.h"

class Carro : public Veiculo {  // Define a classe "Carro", que herda da classe base "Veiculo"
    private:
        int numPortas;
    public:
        Carro(string nome, string rodas, int velocidadeMaxima, int velocidadeAtual, int numPortas)
        : Veiculo(nome, rodas, velocidadeMaxima, velocidadeAtual), numPortas(numPortas) {}
             // Declaração dos métodos da classe Carro
            void abrirPortas();
            void fecharPortas();
            void menuCarro();

};

#endif