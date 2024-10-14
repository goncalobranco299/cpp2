#include <iostream>
#include <string>
using namespace std;

class Refrigerante {
    private:
        string sabor;
        string cal;
        string marca;
        string ingredientes;
        string ml;
        string cor;
        string fruta;
        string tamanho;
        string numTelemovel;
        string qrCode;

    bool state = false;     // Se a lata está aberta
    bool condicion = false; // Se pode beber

    void abrirLata() {
        if (!state) {
            state = true; // Alterar o estado para aberto
            cout << "A lata está aberta!" << endl;
        } else {
            cout << "A lata já está aberta!" << endl;
            state = false; 
        }
    }

    void beber() {
        if (state) {
            cout << "A lata está aberta, pode beber!" << endl;
            condicion = true; // Atualiza a condição para que se possa beber
        } else {
            cout << "A lata está fechada, não pode beber!" << endl; 
            condicion = false; // A condição permanece falsa
        }
    }

    void lataLixo() {
        cout << "Lata descartada no lixo." << endl;
    }
    
    void reciclarLata() {
        cout << "A lata foi reciclada." << endl;
    }

    void verLata() {
        cout << "Sabor: " << sabor << ", Marca: " << marca << ", Cor: " << cor << endl;
    }

    void informacoes(){
       this-> sabor = "ananas";
       this-> cal = "?";
       this-> marca = "fanta";
       this-> ingredientes = "agua,sumo de ananas, etc...";
       this-> ml = "300ml";
       this-> cor = "laranja";
       this-> fruta = "ananas";
       this-> tamanho = "15cm";
       this-> numTelemovel = "800 286 286";
       this-> qrCode = "?";
    };
};

int main() {


    return 0;
}
