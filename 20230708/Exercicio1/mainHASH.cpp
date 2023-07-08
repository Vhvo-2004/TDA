#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include <string.h>
int main() {
    TB_HASH tabela;
    PACIENTE p, *pr;
    inicializahash(tabela);

    p.cod = 1291;
    p.nome = strdup("Aguinaldo");
    p.cpf = strdup("0000000");
    p.idade = 27;
    inserir(tabela, p);

    p.cod = 1012;
    p.nome = strdup("Renato");
    p.cpf = strdup("0000001");
    p.idade = 29;
    inserir(tabela, p);

    p.cod = 1987;
    p.nome = strdup("Tibe");
    p.cpf = strdup("0000002");
    p.idade = 34;
    inserir(tabela, p);
    mostrarhash(tabela);
    pr = busca(tabela, 1012);
    if (pr != NULL) {
        printf("\n 	Achou nome: %s", pr->nome);
    } else {
        printf("\n 	Nao encontrou o paciente.\n");
    }

    return 0;
}

