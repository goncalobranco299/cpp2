#include "carro.h"

void Carro::abrirPortas()
{
     int portas;
    cout << "Quantas portas queres abrir? " << endl;
        cin >> portas;
       if(portas <= numPortas){  // Verifica se o número de portas a fechar é válido (menor ou igual ao número de portas do carro)
            cout << "Abriste " << portas << "portas" << endl;  // Exibe o número de portas que foram fechadas
       } else{
        cout << "Numero de portas ivalido " << endl; // Exibe mensagem de erro caso o número de portas seja inválido
        }
}

void Carro::fecharPortas(){
    int portas;
        cout << "Quantas portas queres fechar? " << endl;
            cin >> portas;
        if(portas <= numPortas){
        cout << "Fechaste: " << portas << "portas" << endl;
        } else {
            cout << "Numero de portas invalido " << endl;
        }
}

void Carro::menuCarro() // Função para exibir o menu de opções do carroo
{
    int opcao;

    do {
    // Exibe o menu de opções para o utilizador
     cout << "Menu do carro " <<  endl;
     cout << "---------------------- " << endl;
     cout << "1. Mostrar detalhes" << endl;
     cout << "2. Abrir portas "<< endl;
     cout << "3. Fechar portas "<< endl;
     cout << "4. Acelerar "<< endl;
     cout << "5. Travar "<< endl;
     cout << "0. Sair"<< endl;
     cout << "Escolha uma opcao "<< endl;
     cin >> opcao;

    // Verifica qual a opção escolhida e executa a ação correspondente
     switch (opcao){
    
    case 1:
        mostrarDetalhes();
            break;
    case 2:
        abrirPortas();
            break;
    case 3:
        fecharPortas();
            break;
    case 4:
        acelerar();
            break;
    case 5:
        travar();
            break;
    case 0:
        cout << "Sair do menu do carro " << endl;
            break;
    default:
        cout << "Opcao invalida. Tente novamente!" << endl;
            break;
        }
     } while (opcao != 0); 
 }



