#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include <string.h>
int main() {
    TB_HASH tabela;
    PACIENTE p, *pr,p1;
    inicializahash(tabela);
    
    p1.cod = 1987;
    p1.nome = strdup("Soteldo");
    p1.cpf = strdup("0000004");
    p1.idade = 34;

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
    printf("Tabela antes de excluir um paciente.\n");
    mostrarhash(tabela);
    pr = busca(tabela, 1012);
    if (pr != NULL) {
        printf("\n 	Achou nome: %s\n", pr->nome);
    } else {
        printf("\n 	Nao encontrou o paciente.\n");
    }
    excluir_paciente(tabela,1987);
    printf("Tabela apos excluir um paciente!\n");
    busca(tabela,1987);
    printf("Tabela apos incluir um paciente no lugar de um paciente exluido!\n");
     inserir(tabela, p1);
    mostrarhash(tabela);
    return 0;
}

