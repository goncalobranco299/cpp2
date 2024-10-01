#include <iostream>
#include <fstream>
#include <sstream> // Para manipulação de strings
using namespace std;

const string DBfile = "lista.txt"; // Nome do arquivo para armazenar os produtos
const int prodMax = 80; // Quantidade máxima de produtos

struct Produto {
    int id;
    string nome;
    float preco;
    int quantidade;
    char status;
};

    // Função para carregar produtos do arquivo

void loadProd(Produto produtos[], int& quantidadeAtual) {
    ifstream file(DBfile);
        if (!file) return; // Se o arquivo não pode ser aberto, sai da função

quantidadeAtual = 0; // Reseta a contagem de produtos carregados
        while (file.good() && quantidadeAtual < prodMax) {
    Produto p;
    string line;

    // Lê uma linha inteira do arquivo
        if (getline(file, line)) {
            stringstream ss(line);
            string status; // Para capturar o status
            getline(ss, status, ','); // Lê o status
            p.status = status[0]; // Define o status
            ss >> p.id; // Lê o ID
            ss.ignore(); // Ignora a vírgula
            getline(ss, p.nome, ','); // Lê o nome até a vírgula
            ss >> p.preco; // Lê o preço
            ss.ignore(); // Ignora a vírgula
            ss >> p.quantidade; // Lê a quantidade

            produtos[quantidadeAtual] = p; // Armazena o produto
            quantidadeAtual++; // Incrementa a quantidade atual
        }
    }
    file.close(); // Fecha o arquivo
}

// Função para salvar produtos no arquivo
void saveProd(const Produto produtos[], int quantidadeAtual) {
    ofstream file(DBfile); // Cria ou sobrescreve o arquivo
    for (int x = 0; x < quantidadeAtual; x++) {
        file << produtos[x].status << "," << produtos[x].id << "," 
             << produtos[x].nome << "," << produtos[x].preco << "," 
             << produtos[x].quantidade << endl; // Salva os dados do produto
    }
    file.close(); // Fecha o arquivo

    cout << "-----------------------------------------------" << endl;
    cout << "Produtos salvos com sucesso!" << endl;
}

// Função para consultar produtos
void consultProd(const Produto produtos[], int quantidadeAtual) {
    char opcao;
    if (quantidadeAtual == 0) {
        cout << "-----------------------------------------------" << endl;
        cout << "Sem produtos adicionados." << "\nVoltando ao menu..." << endl;
        return;
    }

    cout << "------------------------------------------------------------------" << endl;
    cout << "Quer consultar os produtos ativos(A), eliminados(E) ou todos(T)? ";
    cin >> opcao;
    system("clear");

    if (opcao == 'A' || 'a') {
        cout << "-----------------------------------------------" << endl;
        cout << "           Lista de produtos ativos" << endl; 
        for (int a = 0; a < quantidadeAtual; a++) {
            if (produtos[a].status == 'A') {
                cout << "-----------------------------------------------" << endl;
                cout << "ID: " << produtos[a].id << endl;
                cout << "Nome: " << produtos[a].nome << endl;
                cout << "Preco: " << produtos[a].preco << "€" << endl;
                cout << "Quantidade: " << produtos[a].quantidade << endl;
                cout << "Status: " << produtos[a].status << endl;
            }
        }
    } else if (opcao == 'E' || 'e') {
        cout << "-----------------------------------------------" << endl;
        cout << "         Lista de produtos eliminados" << endl; 
        for (int e = 0; e < quantidadeAtual; e++) {
            if (produtos[e].status == 'E') {
                cout << "-----------------------------------------------" << endl;
                cout << "ID: " << produtos[e].id << endl;
                cout << "Nome: " << produtos[e].nome << endl;
                cout << "Preço: " << produtos[e].preco << "€" << endl;
                cout << "Quantidade: " << produtos[e].quantidade << endl;
                cout << "Status: " << produtos[e].status << endl;
            }
        }
    } else if (opcao == 'T' || 't') {
        cout << "-----------------------------------------------" << endl;
        cout << "          Lista de todos os produtos" << endl; 
        for (int t = 0; t < quantidadeAtual; t++) {
            cout << "-----------------------------------------------" << endl;
            cout << "ID: " << produtos[t].id << endl;
            cout << "Nome: " << produtos[t].nome << endl;
            cout << "Preço: " << produtos[t].preco << "€" << endl;
            cout << "Quantidade: " << produtos[t].quantidade << endl;
            cout << "Status: " << produtos[t].status << endl;                                                                                         
        }
    }
}

// Função para mudar os produtos
void changeProd(Produto produtos[], int quantidadeAtual) {
    int id;
    cout << "-----------------------------------------------" << endl;
    cout << "Insira o ID do produto que deseja alterar: "; 
    cin >> id; 
    system("clear");

    for (int y = 0; y < quantidadeAtual; y++) {
        if (produtos[y].id == id && produtos[y].status == 'A') {
            cout << "-----------------------------------------------" << endl;
            cout << "Insira o novo nome do produto: ";
            cin.ignore(); 
            getline(cin, produtos[y].nome); 
            cout << "-----------------------------------------------" << endl;
            cout << "Insira o novo preço do produto: ";
            cin >> produtos[y].preco;
            cout << "-----------------------------------------------" << endl;
            cout << "Insira a nova quantidade do produto: ";
            cin >> produtos[y].quantidade;

            saveProd(produtos, quantidadeAtual); // Salva as alterações no arquivo
            system("clear");
            cout << "-----------------------------------------------" << endl;
            cout << "Produto alterado com sucesso." << endl;
            return;
        }
    }

    cout << "-----------------------------------------------" << endl;
    cout << "Produto nao foi encontrado ou ja foi eliminado." << endl;
}

// Função para eliminar produtos
void eliminateProd(Produto produtos[], int quantidadeAtual) {
    int id;
    cout << "-----------------------------------------------" << endl;
    cout << "Insira o ID do produto que deseja eliminar: ";
    cin >> id;

    for (int w = 0; w < quantidadeAtual; w++) {
        if (produtos[w].id == id && produtos[w].status == 'A') {
            produtos[w].status = 'E'; // Define o status como eliminado
            saveProd(produtos, quantidadeAtual);
            system("clear");
            cout << "-----------------------------------------------" << endl;
            cout << "Produto eliminado com sucesso!" << endl;
            return;
        }
    }

    system("clear");
    cout << "-----------------------------------------------" << endl;
    cout << "Produto não encontrado." << endl;
}

// Função que permite adicionar produtos
void addProduto(Produto produtos[], int& quantidadeAtual) {
    if (quantidadeAtual >= prodMax) {
        cout << "-----------------------------------------------" << endl;
        cout << "Atingiu o limite máximo de produtos." << "\nNão é possível adicionar mais produtos." << endl;
        return;
    } else {
        Produto newProduct; // Cria um novo produto
        newProduct.status = 'A'; // Define como A o status do novo produto

        if (quantidadeAtual == 0) {
            newProduct.id = 1; // Se for o primeiro produto
        } else {
            newProduct.id = produtos[quantidadeAtual - 1].id + 1; // Incrementa o id
        }       

        cout << "-----------------------------------------------" << endl;
        cout << "Insira o nome do produto: ";
        cin.ignore();
        getline(cin, newProduct.nome);

        cout << "-----------------------------------------------" << endl;
        cout << "Insira o preço do produto: ";
        cin >> newProduct.preco;

        cout << "-----------------------------------------------" << endl;
        cout << "Insira a quantidade do produto: ";
        cin >> newProduct.quantidade;

        produtos[quantidadeAtual] = newProduct; // Adiciona o novo produto no array
        quantidadeAtual++; // Incrementa a quantidade atual

        saveProd(produtos, quantidadeAtual); // Salva o novo produto no arquivo
        system("clear");

        cout << "-----------------------------------------------" << endl;
        cout << "O produto foi adicionado." << endl;
    }
}

// Função que calcula o valor total dos produtos
float calcularValorTotal(const Produto produtos[], int quantidadeAtual) {
    float total = 0.0;
    for (int i = 0; i < quantidadeAtual; i++) {
        if (produtos[i].status == 'A') { // Apenas soma os produtos ativos
            total += produtos[i].preco * produtos[i].quantidade;
        }
    }
    return total;
}

// Função que exibe o menu
void showMenu() {
    cout << "-----------------------------------------------" << endl;
    cout << "Selecione uma opcao:" << endl;
    cout << "1. Adicionar produto" << endl;
    cout << "2. Consultar valor total do stock" << endl;
    cout << "3. Consultar produtos" << endl;
    cout << "4. Alterar produto" << endl;
    cout << "5. Eliminar produto" << endl;
    cout << "0. Sair" << endl;
    cout << "-----------------------------------------------" << endl;
}

// Função principal que roda o programa
void runProgram() {
    Produto produtos[prodMax];
    int quantidadeAtual = 0;
    
    // Carrega produtos do arquivo ao iniciar
    loadProd(produtos, quantidadeAtual);

    int opcao = -1;
    while (opcao != 0) {
        showMenu();
        cin >> opcao;
        system("clear");

        switch (opcao) {
            case 1:
                addProduto(produtos, quantidadeAtual);
                break;
            case 2:
                cout << "-----------------------------------------------" << endl;
                cout << "Valor total do stock: " << calcularValorTotal(produtos, quantidadeAtual) << "€" << endl;
                break;
            case 3:
                consultProd(produtos, quantidadeAtual);
                break;
            case 4:
                changeProd(produtos, quantidadeAtual);
                break;
            case 5:
                eliminateProd(produtos, quantidadeAtual);
                break;
            case 0:
                cout << "Saindo do programa..." << endl;
                break;
            default:
                cout << "Opção inválida! Tente novamente." << endl;
                break;
        }
    }
}

int main() {
    runProgram(); // Inicia o programa
    return 0;
}