#include <iostream>
#include <string>
using namespace std;

struct lata {
        string marca;
        string sabor;
        string validade;
        string fornecedor;
        string codBarras;
        string lote;
        string dataFabricacao;
        string materialEmbalgem;
        string infoNutricional[5];
        double capacidade;
        double preco;
        double peso;
        bool status;
};


class Refrigerante{
    private:
        lata refrigerante;
        double qntSumoDisponivel;

    public:

        //Construtor
        Refrigerante(lata lata){
            refrigerante = lata;
            qntSumoDisponivel = lata.capacidade;
        }

        //Abrir a lata
        void abrirLata(){
            if (refrigerante.status == false){
                cout << "Abrindo a lata " << endl;
            }else{
                cout << "A lata esta fechada " << endl;
                refrigerante.status = true;
            }
            
        }


        void beberRefrigerante(){
            double qnt;
            
            if(refrigerante.status){
            cout << "há" << qntSumoDisponivel << "de refrigerante na lata " << endl;
            cout << "Digite a quantidade de refrigerante que deseja beber" << endl;
            cin >> qnt;
                if(qnt <= qntSumoDisponivel){
                    qntSumoDisponivel -= qnt;
                    cout << "Voce bebeu" << qnt << "litros de referencia" << endl;
                }else{
                    cout << "Nao ha refrigerante sufeciente " << endl;
                    }
                }else{
                    cout << "Voce precisa abrir a lata antes de beber" << endl;
            }
        }
};

int main(){

    lata lata1 = {"Coca-Cola", "Cola", "10/10/2021",
                  "Coca-Cola", "123456789", "123456",
                  "10/10/2020", "Aluminio",
                                {"Calorias: 100",
                                "Carboidratos: 30",
                                "Proteinas: 0",
                                "Gorduras: 0",
                                "Sodio: 10"},
                    350, 5.00, 0.350, false};
    
    Refrigerante refri1(lata1);

    while (true){
        int opcao;
        cout << "1 - Abrir lata " << endl;
        cout << "2 - Beber refrigerante " << endl;
        cout << "3 - Sair " << endl;
        cout << "Escolha uma opcao " << endl;
        cin >> opcao;

        if(opcao == 1){
            refri1.abrirLata();
        }else if(opcao == 2){
            double qnt;
            cout << "Digite a quantidade de refrigerante que deseja beber: ";
            cin >> qnt;
            refri1.beberRefrigerante();
        }else if(opcao == 3){
            break;
        }else{
            cout << "Opcao invalida " << endl;
        }
    }






    
    return 0;
}
