#include <iostream> 
#include <fstream> // permite trabalhar com ficheiros
#include <sstream> // manipular strings como se fossem fluxos de dados
#include <string>  // permite trabalhar com strings

using namespace std;

// Protótipos das funções
void criarProduto(), consultarProdutos(), alterarProduto();
void eliminarProduto(), mostrarMenu();

int main() {
    int opcao;
    do { // se o bloco de codigo estiver correto ele irá repetir o programa
        
        mostrarMenu(); //funcao para amostrar o menu ao utilizador
        cin >> opcao;

        switch (opcao) {
            case 1:
                criarProduto();
                break;
            case 2:
                consultarProdutos();
                break;
            case 3:
                alterarProduto();
                break;
            case 4:
                eliminarProduto();
                break;
            case 5:
                cout << "A sair do programa..." << endl;
                break;
            default:
                cout << "Opção invalida. Tente novamente." << endl;
        }
    } while (opcao != 5); // enquanto o utiliador nao escolher a opcao 5, ira repetir sempre o programa
    return 0;
}

// Função para mostrar o menu ao utilizador
void mostrarMenu() {

    cout << "Menu:" << endl;
    cout << "1. Criar Produto" << endl;
    cout << "2. Consultar Produtos" << endl;
    cout << "3. Alterar Produto" << endl;
    cout << "4. Eliminar Produto" << endl;
    cout << "5. Sair" << endl;
    cout << "Escolha uma opcao: ";
}

// Função para criar um novo produto e gravar no ficheiro
void criarProduto() {
    ofstream file("produtos.txt", ios::app); // Abrir o ficheiro em modo de adicionar ("ios::app" adicionar dados ao final do ficheiro)
    if (!file) {
        cout << "Erro ao abrir o ficheiro!" << endl; // se nao houver nehum ficheiro aguardado, ele vai dar erro
        return;
    }

    string id, nome, quantidade, preco, status = "A"; // declarando 5 variaveis do tipo string
    
    cout << "Introduza o ID do produto: ";
        cin >> id;
    cout << "Introduza o nome do produto: ";
        cin >> nome;
    cout << "Introduza a quantidade: ";
        cin >> quantidade;
    cout << "Introduza o preco: ";
        cin >> preco;

    // Escrever no ficheiro
    file << id << "," << nome << "," << quantidade << "," << preco << "," << status << endl;

    file.close();
    cout << "Produto criado com sucesso!" << endl;
}

// Função para consultar produtos ativos
void consultarProdutos() {
    ifstream file("produtos.txt");
    if (!file) {
        cout << "Erro ao abrir o ficheiro!" << endl;
        return;
    }

    string linha;
    cout << "\nLista de Produtos Ativos:" << endl;
    while (getline(file, linha)) {
        istringstream ss(linha);
        string id, nome, quantidade, preco, status;
        getline(ss, id, ',');
        getline(ss, nome, ',');
        getline(ss, quantidade, ',');
        getline(ss, preco, ',');
        getline(ss, status, ',');

        if (status == "A") { // Apenas mostrar produtos ativos
            cout << "ID: " << id << ", Nome: " << nome << ", Quantidade: " << quantidade 
                 << ", Preco: " << preco << ", Status: " << status << endl;
        }
    }

    file.close();
}

// Função para alterar um produto
void alterarProduto() {
    fstream file("produtos.txt", ios::in | ios::out);
    if (!file) {
        cout << "Erro ao abrir o ficheiro!" << endl;
        return;
    }

    string id, nome, quantidade, preco, status;
    string idProcurado;
    cout << "Introduza o ID do produto a alterar: ";
    cin >> idProcurado;

    string linha;
    long pos;
    bool encontrado = false;

    while (file.seekg(0, ios::cur), pos = file.tellg(), getline(file, linha)) {
        istringstream ss(linha);
        getline(ss, id, ',');
        getline(ss, nome, ',');
        getline(ss, quantidade, ',');
        getline(ss, preco, ',');
        getline(ss, status, ',');

        if (id == idProcurado && status == "A") {
            encontrado = true;
            cout << "Produto encontrado. Introduza os novos dados." << endl;
            cout << "Nome: "; getline(cin, nome);
            cout << "Quantidade: "; getline(cin, quantidade);
            cout << "Preço: "; getline(cin, preco);

            file.seekp(pos);
            file << id << "," << nome << "," << quantidade << "," << preco << "," << status << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "Produto nao encontrado ou foi eliminado." << endl;
    }

    file.close();
}

// Função para eliminar um produto
void eliminarProduto() {
    fstream file("produtos.txt", ios::in | ios::out);
    if (!file) {
        cout << "Erro ao abrir o ficheiro!" << endl;
        return;
    }

    string idProcurado;
    cout << "Introduza o ID do produto a eliminar: ";
    cin >>  idProcurado;

    string linha, id, nome, quantidade, preco, status;
    long pos;
    bool encontrado = false;

    while (file.seekg(0, ios::cur), pos = file.tellg(), getline(file, linha)) {
        istringstream ss(linha);
        getline(ss, id, ',');
        getline(ss, nome, ',');
        getline(ss, quantidade, ',');
        getline(ss, preco, ',');
        getline(ss, status, ',');

        if (id == idProcurado && status == "A") {
            encontrado = true;
            file.seekp(pos);
            file << id << "," << nome << "," << quantidade << "," << preco << "," << "D" << endl;
            cout << "Produto eliminado com sucesso." << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "Produto nao encontrado ou ja foi eliminado." << endl;
    }

    file.close();
}
