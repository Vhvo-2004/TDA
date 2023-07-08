#include <stdio.h>
#include <stdlib.h>
#include "hash2.h"

int main() {
    TB_HASH tabela;
    PACIENTE p, *pr;
    inicializahash(tabela);

    p.cod = 102;
    p.nome = "Aguinaldo";
    p.cpf = "0000000";
    p.idade = 27;
    inserir(tabela, p);

    p.cod = 100;
    p.nome = "Renato";
    p.cpf = "0000001";
    p.idade = 29;
    inserir(tabela, p);

    p.cod = 101;
    p.nome = "Tibe";
    p.cpf = "0000002";
    p.idade = 34;
    inserir(tabela, p);

    mostrarhash(tabela);

    pr = busca(tabela, 1089);
    if (pr != NULL) {
        printf("\n 	Achou nome: %s\n", pr->nome);
    } else {
        printf("\n 	Nao encontrou o paciente.\n");
    }

    return 0;
}

