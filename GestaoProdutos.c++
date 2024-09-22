#include <iostream>
#include <string>

using namespace std;

struct Produto
{
    string nome;
    float preco;
    int quantidade;
};

    // Função para adicionar o produto
    void adicionarProduto(Produto produtos[], int quantidadeAtual) {

            // Funçao para adicionar o produto
        cout << "Nome do produto " << endl;
            getline(cin, produtos[quantidadeAtual].nome);

            // Preço do produto 
        cout << "Preco do produto " << endl;
            cin >> produtos[quantidadeAtual].preco;

            // Quantidade que o utilizar quer inserir 
        cout << "Quantidade do produto " << endl;
            cin >> produtos[quantidadeAtual].quantidade;      

};

    // Função para exibir os produtos 
    void exibirProdutos( const Produto produtos[], int quantidadeAtual) {

        



    }

int main() {

cout << "1. Adicionar Produto " << endl;
cout << "2. Exibir Produtos " << endl;
cout << "3. Calcular o Valor Total do Stock " << endl;
cout << "4. Sair " << endl;
cin >> escolha;

switch (escolha)
{
case 1:
    adicionarProduto(Produto);
    break;

default:
    cout << "Opcao invalida, tente novamente " << endl;
    break;
}

};