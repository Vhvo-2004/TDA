#ifndef HASH2.1_H
#define HASH2.1_H
typedef struct {
    int chave;
    // Outros campos do paciente...
} PACIENTE;

typedef PACIENTE* TB_HASH[11];

void inicializarTabela(TB_HASH tabela);
void inserirChave(TB_HASH tabela, int chave, int (*funcaoHash)(int, int),int* cont);
void imprimirTabela(TB_HASH tabela);
void destruirTabela(TB_HASH tabela);
int sondagemLinear(int chave, int i);
int sondagemQuadratica(int chave, int i);
int sondagemQuadraticaFator2(int chave, int i);
int hashDuplo(int chave, int i);

// TABELA_HASH_H


#endif
