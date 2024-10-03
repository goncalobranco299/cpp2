#include <iostream> 
#include <fstream> // Permite trabalhar com ficheiros
#include <sstream> // Manipular strings como se fossem fluxos de dados
#include <string>  // Permite trabalhar com strings

using namespace std;

void criarProduto(), consultarProdutos(), alterarProduto();
void eliminarProduto(), mostrarMenu();

int main() {
    int opcao;
    
    do { // Se o bloco de codigo estiver correto ele irá repetir o programa
        
        mostrarMenu(); 
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
                cout << "Opcao inválida. Tente novamente." << endl;
        }
    } while (opcao != 5); // Enquanto o utilizador nao escolher a opcao 5, ira repetir sempre o programa
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
    ofstream file("produtos.txt", ios::app); // Abrir o ficheiro em modo de adicionar ("ios::app" adiciona dados ao final do ficheiro)
    if (!file) {
        cout << "Erro ao abrir o ficheiro!" << endl; // Se nao houver nehum ficheiro guardado, ele vai dar erro
        return;
    }

    string id, nome, quantidade, preco, status = "A"; // Declarando 5 variáveis do tipo string
    
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
        cout << "Erro ao abrir o ficheiro ou nenhum ficheiro registado!" << endl;
        return;
    }

    string linha;
    cout << "Lista de Produtos Ativos:" << endl;
    while (getline(file, linha)) {  // While usa a função getline para ler linha por linha do ficheiro
        istringstream ss(linha); // Cria um stream a partir da linha para facilitar a extração de campos separados por vírgula
        string id, nome, quantidade, preco, status; // Extrai cada campo da linha (separado por vírgula) e armazena nas variáveis correspondentes
        getline(ss, id, ','); // Extrai o ID do produto
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
    ifstream fileIn("produtos.txt"); // Abrir o ficheiro para leitura
    if (!fileIn) {
        cout << "Erro ao abrir o ficheiro!" << endl;
        return;
    }

    ofstream fileOut("temp.txt"); // Abrir um ficheiro temporário para escrita
    if (!fileOut) {
        cout << "Erro ao criar ficheiro temporário!" << endl;
        return;
    }

    string idProcurado;
    cout << "Introduza o ID do produto a alterar: ";
    cin >> idProcurado;

    string linha;  // Declara uma variável chamada 'linha' do tipo 'string'
    bool encontrado = false; // Declara uma variável chamada 'encontrado' do tipo 'bool' e inicializa com o valor 'false'

    // Ler o ficheiro linha a linha
    while (getline(fileIn, linha)) {
        istringstream ss(linha);
        string id, nome, quantidade, preco, status;
        getline(ss, id, ',');
        getline(ss, nome, ',');
        getline(ss, quantidade, ',');
        getline(ss, preco, ',');
        getline(ss, status, ',');

        if (id == idProcurado && status == "A") {
            encontrado = true; // Define que o produto foi encontrado
            cout << "Produto encontrado." << endl;
            cout << "Introduza os novos dados:" << endl;
            cout << "Nome: ";
            cin >> nome;
            cout << "Quantidade: ";
            cin >> quantidade;
            cout << "Preço: ";
            cin >> preco;

            // Escrever os novos dados no ficheiro temporário
            fileOut << id << "," << nome << "," << quantidade << "," << preco << "," << status << endl;
        } else {
            // Escrever a linha original no ficheiro temporário
            fileOut << linha << endl;
        }
    }

    if (!encontrado) {
        cout << "Produto nao encontrado ou foi eliminado." << endl;
    }

    fileIn.close();
    fileOut.close();

    // Substituir o ficheiro original pelo temporário
    remove("produtos.txt");           // Apagar o ficheiro original
    rename("temp.txt", "produtos.txt"); // Renomear o ficheiro temporário
}

// Função para eliminar um produto
void eliminarProduto() {
    fstream file("produtos.txt", ios::in | ios::out); // Abrir o ficheiro para leitura e escrita
    if (!file) {
        cout << "Erro ao abrir o ficheiro!" << endl;
        return;
    }

    string idProcurado;
    cout << "Introduza o ID do produto a eliminar: ";
    cin >> idProcurado;

    string linha, id, nome, quantidade, preco, status; // Declarando 5 variáveis do tipo string
    bool encontrado = false;

    ofstream tempFile("temp.txt");

    while (getline(file, linha)) {
        istringstream ss(linha);
        getline(ss, id, ',');
        getline(ss, nome, ',');
        getline(ss, quantidade, ',');
        getline(ss, preco, ',');
        getline(ss, status, ',');

        if (id == idProcurado && status == "A") { // Verifica se o ID corresponde e se o status é "A"
            encontrado = true; // Produto encontrado
            tempFile << id << "," << nome << "," << quantidade << "," << preco << ",D" << endl; // Marcar como "D"
            cout << "Produto eliminado com sucesso." << endl;
        } else {
            tempFile << linha << endl; // Manter os outros produtos inalterados
        }
    }

    if (!encontrado) {
        cout << "Produto não encontrado ou já foi eliminado." << endl;
    }

    file.close();
    tempFile.close();

}
