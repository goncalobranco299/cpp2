#include "carro.h"
#include "mota.h"

int main(){
    Carro carro("Tesla",2);
    carro.mostrarDetalhes();

    Mota mota("Yamaha","Desportivo");
    mota.mostrarDetalhes();

    return 0;
}
