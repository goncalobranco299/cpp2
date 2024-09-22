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
            cin.ignore();
            getline(cin, produtos[quantidadeAtual].nome);

            // Preço do produto 
        cout << "Preco do produto " << endl;
            cin >> produtos[quantidadeAtual].preco;

            // Quantidade que o utilizar quer inserir 
        cout << "Quantidade do produto " << endl;
            cin >> produtos[quantidadeAtual].quantidade;      

};

    void exibirProdutos(const Produto produtos[], int quantidadeAtual) {
    if (quantidadeAtual == 0) {
        cout << "Nenhum produto registado." << endl;
    } else {
        for (int i = 0; i < quantidadeAtual; i++) {
            cout << "Produto " << i + 1 << ": " << endl;
            cout << "Nome: " << produtos[i].nome << endl;
            cout << "Preço: " << produtos[i].preco << " €" << endl;
            cout << "Quantidade: " << produtos[i].quantidade << endl;
        }
    }
}

    float calcularValorTotal (const Produto produtos[], int quantidadeAtual) {
        float valorTotal = 0.0;
        for (int i = 0; i < quantidadeAtual; i++) {
            valorTotal += produtos[i].preco * produtos[i].quantidade;
        
    }
        return valorTotal;
}

int main() {
    Produto Produtos [100];
    int quantidadeAtual = 0;
    int opcao;
do{


cout << "1. Adicionar Produto " << endl;
cout << "2. Exibir Produtos " << endl;
cout << "3. Calcular o Valor Total do Stock " << endl;
cout << "0. Sair " << endl;
cin >> opcao;

switch (opcao) {
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