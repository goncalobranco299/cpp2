#ifndef MOTA_H
#define MOTA_H

#include "veiculo.h"

class Mota : public Veiculo{ // Define a classe "Mota" que herda da classe base "Veiculo"
    private:
        string tipoGuiadao; // Declara uma variável privada para armazenar o tipo de guiador da mota
    public:
        // Construtor da classe "Mota".
        // Ele inicializa os atributos do veículo utilizando o construtor da classe base "Veiculo",
        // e também inicializa o atributo específico "tipoGuiadao".
        Mota(string nome, string rodas,string tipoGuiadao, int velocidadeMaxima, int velocidadeAtual)
            : Veiculo(nome, rodas, velocidadeMaxima, velocidadeAtual),tipoGuiadao(tipoGuiadao){}
        // Declaração de um método público chamado "menuMota".
        // Este método provavelmente será usado para exibir opções ou funcionalidades específicas da moto.
    void menuMota();
};

#endif
