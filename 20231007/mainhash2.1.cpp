#include "hash2.1.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	int cont=0;
    TB_HASH tabela;
    inicializarTabela(tabela);

    int chaves[] = {365, 112, 180, 213, 13, 27};
    int numChaves = sizeof(chaves) / sizeof(chaves[0]);

    // Sondagem linear
    for (int i = 0; i < numChaves; i++) {
        inserirChave(tabela, chaves[i], sondagemLinear,&cont);
    }
    printf("Houveram %d conflitos nessas sondagem!\n",cont);
    cont=0;
    printf("Sondagem linear: ");
    imprimirTabela(tabela);

    // Reinicializar tabela
    destruirTabela(tabela);
    inicializarTabela(tabela);

    // Sondagem quadrática
    for (int i = 0; i < numChaves; i++) {
        inserirChave(tabela, chaves[i], sondagemQuadratica,&cont);
    }
    printf("Houveram %d conflitos nessas sondagem!\n",cont);
    cont=0;
    printf("Sondagem quadratica: ");
    imprimirTabela(tabela);

    // Reinicializar tabela
    destruirTabela(tabela);
    inicializarTabela(tabela);

    // Sondagem quadrática com fator 2
    for (int i = 0; i < numChaves; i++) {
        inserirChave(tabela, chaves[i], sondagemQuadraticaFator2,&cont);
    }
    printf("Houveram %d conflitos nessas sondagem!\n",cont);
    cont=0;
    printf("Sondagem quadratica com fator 2: ");
    imprimirTabela(tabela);

    // Reinicializar tabela
    destruirTabela(tabela);
    inicializarTabela(tabela);

    // Hash duplo
    for (int i = 0; i < numChaves; i++) {
        inserirChave(tabela, chaves[i], hashDuplo,&cont);
    }
    printf("Houveram %d conflitos nessas sondagem!\n",cont);
    cont=0;
    printf("Hash duplo: ");
    imprimirTabela(tabela);

    // Destruir tabela
    destruirTabela(tabela);

    return 0;
}
