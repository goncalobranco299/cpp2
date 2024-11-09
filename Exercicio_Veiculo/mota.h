#ifndef MOTA_H
#define MOTA_H

#include "veiculo.h"

class Mota : public Veiculo{ // Define a classe "Mota" que herda da classe base "Veiculo"
    private:
        string tipoGuiadao; // Declara uma variável privada para armazenar o tipo de guiador da mota
    public:
        Mota(string nome, string rodas,string tipoGuiadao, int velocidadeMaxima, int velocidadeAtual)
            : Veiculo(nome, rodas, velocidadeMaxima, velocidadeAtual),tipoGuiadao(tipoGuiadao){}
    void menuMota();
};

#endif