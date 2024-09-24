#include <iostream>
using namespace std;

struct Produto //Define uma estrutura(struct) chamada Produto
{
    string nome;
    float preco;
    int quantidade;
};

    Produto produtos[150];
    int quantidadeAtual = 0;

    // Função para adicionar o produto
    void adicionarProduto(Produto produtos[], int &quantidadeAtual) {

            // Funçao para adicionar o produto
        cout << "Nome do produto: ";
            cin >> produtos[quantidadeAtual].nome;
            // Preço do produto 
        cout << "Preco do produto: ";
            cin >> produtos[quantidadeAtual].preco;

            // Quantidade que o utilizar quer inserir 
        cout << "Quantidade do produto: ";
            cin >> produtos[quantidadeAtual].quantidade;    

            quantidadeAtual++;  // Incrementar a quantidade atual apos adicionar o produto

};

    void exibirProdutos(const Produto produtos[], int quantidadeAtual) {
    if (quantidadeAtual == 0) { // Verifica se existe produtos armazenados 
        cout << " Nenhum produto registado." << endl;
    } else {
            cout << "==========================" <<endl;
            cout << "  Lista de Produtos" <<endl;
        for (int i = 0; i < quantidadeAtual; i++) {
            cout << "Produto " << i + 1 << ": " << endl;
            cout << "Nome: " << produtos[i].nome << endl;
            cout << "Preco: " << produtos[i].preco << endl;
            cout << "Quantidade: " << produtos[i].quantidade << endl;
        }
    }
}

    float calcularValorTotal (const Produto produtos[], int quantidadeAtual) {
        float valorTotal = 0.0; // Inicializa a variavel valorTotal como valor de 0
        for (int i = 0; i < quantidadeAtual; i++) {
            valorTotal += produtos[i].preco * produtos[i].quantidade;
        
    }
        return valorTotal;
}

int main() {
    Produto Produtos [100];
    int quantidadeAtual = 0; // Faz com que possa contar quantos produtos forem adicionados 
    int opcao;
do{


cout << "==========================" <<endl;
cout << "1. Adicionar Produto " << endl;
cout << "2. Exibir Produtos " << endl;
cout << "3. Calcular o Valor Total do Stock " << endl;
cout << "0. Sair " << endl;
cout << "==========================" <<endl;
cin >> opcao;

switch (opcao) { // Utilizavel para varias opcoes que o utilizador que escolher
    case 1:
            adicionarProduto(Produtos, quantidadeAtual);
        break;

    case 2:
            exibirProdutos(Produtos, quantidadeAtual);
        break;

    case 3:
            cout <<  "Valor total do stock: " << calcularValorTotal(Produtos, quantidadeAtual) << endl;
        break;

    case 0:
            cout << "Sair... " << endl;
        break;

    default:
            cout << "Opcao invalida, tente novamente " << endl;
        break;
}   
    }
    while (opcao != 0);  // O loop continua até o usuário escolher sair (escolha == 0)

    return 0;
};
