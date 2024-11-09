#include "mota.h"

void Mota::menuMota() // Define o metodo "menuMota" da classe Mota
{
    int opcao;
    do { // Vai inicializar um loop do-while que ira continuar ate a opcao ser 0
        cout << "Menu da Mota: "<< endl;
        cout << "------------ " << endl;
        cout << "1. Mostrar detalhes "<< endl;
        cout << "3. Acelerar "<< endl;
        cout << "4. Travar "<< endl;
        cout << "0. Sair " << endl;
        cout << "Escolha uma opcao: "<< endl;
        cin >> opcao;

        switch (opcao) {
            case 1:
                mostrarDetalhes();
                break;
            case 2:
                acelerar();
                break;
            case 3:
                travar();
                break;        
            case 0:
                cout << "Saindo do menu da " << endl;
                break;
            default:
                cout << "Opção invalida! Tente novamente." << endl;
                break;
        }
    } while (opcao != 0);
}