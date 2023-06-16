#include<stdio.h>
#define MAX 20

typedef struct{
    int matricula;
} reg;

typedef struct{
    int prox;
    int valor;
} ELEMENTO;

typedef struct{
    ELEMENTO A[MAX];
    int disp;
    int inicio;
} Lista;

void criar_lista(Lista* l){
    int i;
    for(i=0;i<MAX-1;i++){
        l->A[i].prox=i+1;
    }
    l->A[MAX-1].prox=-1;
    l->disp=0;
    l->inicio=-1;
}

int obterdisponivel(Lista* m){
    int disp=m->disp;
    if(m->disp != -1){
        m->disp=m->A[disp].prox;
    }
    return disp;
}

void exibir(Lista* m){
    int i=m->inicio;
    while(i!=-1){
        printf("%d \n",m->A[i].valor);
        i=m->A[i].prox;
    }
}

void inserirelemento(Lista* m, int valor){
    if(m->disp==-1){
        return;
    }
    int i=m->inicio;
    int pos_inserir=-1;
    while(i!=-1){
        pos_inserir=i;
        i=m->A[i].prox;
    }
    i=obterdisponivel(m);
    m->A[i].valor=valor;
    if(pos_inserir==-1){
        m->A[i].prox=m->inicio;
        m->inicio=i;
    }else{
        m->A[i].prox=m->A[pos_inserir].prox;
        m->A[pos_inserir].prox=i;
    }
}

void inserir_ordenado(Lista* m, int valor) {
    if (m->disp == -1) {
        return;  // Lista cheia
    }
    
    int i = m->inicio;
    int pos_inserir = -1;
    int pos_anterior = -1;
    
    // Procurar a posição correta para inserir o elemento
    while (i != -1 && m->A[i].valor < valor) {
        pos_anterior = i;
        i = m->A[i].prox;
    }
    
    // Verificar se o elemento já existe na lista
    if (i != -1 && m->A[i].valor == valor) {
        return;  // Elemento já existe na lista, não inserir novamente
    }
    
    // Obter um índice disponível
    int novo_indice = obterdisponivel(m);
    m->A[novo_indice].valor = valor;
    
    // Inserir o elemento na posição correta
    if (pos_anterior == -1) {
        m->A[novo_indice].prox = m->inicio;
        m->inicio = novo_indice;
    } else {
        m->A[novo_indice].prox = m->A[pos_anterior].prox;
        m->A[pos_anterior].prox = novo_indice;
    }
}

int buscar_elemento(Lista* m, int valor) {
    int i = m->inicio;
    int pos = 0;
    
    // Percorrer a lista até encontrar o elemento ou o final da lista
    while (i != -1) {
        if (m->A[i].valor == valor) {
            return pos;  // Elemento encontrado, retorna a posição
        }
        i = m->A[i].prox;
        pos++;
    }
    
    return -1;  // Elemento não encontrado
}

void excluir_elemento_posicao(Lista* m, int posicao) {
    if (m->inicio == -1 || posicao < 0) {
        return;  // Lista vazia ou posição inválida
    }
    
    if (posicao == 0) {
        int indice_remover = m->inicio;
        m->inicio = m->A[indice_remover].prox;
        m->A[indice_remover].prox = m->disp;
        m->disp = indice_remover;
    } else {
        int i = m->inicio;
        int pos = 0;
        int pos_anterior = -1;
        
        // Procurar a posição correta para remover o elemento
        while (i != -1 && pos < posicao) {
            pos_anterior = i;
            i = m->A[i].prox;
            pos++;
        }
        
        if (i != -1) {
            int indice_remover = i;
            m->A[pos_anterior].prox = m->A[i].prox;
            m->A[indice_remover].prox = m->disp;
            m->disp = indice_remover;
        }
    }
}

void excluir_elemento_valor(Lista* m, int valor) {
    if (m->inicio == -1) {
        return;  // Lista vazia
    }
    
    int i = m->inicio;
    int pos_anterior = -1;
    
    // Procurar a posição correta para remover o elemento
    while (i != -1 && m->A[i].valor != valor) {
        pos_anterior = i;
        i = m->A[i].prox;
    }
    
    if (i != -1) {
        if (pos_anterior == -1) {
            m->inicio = m->A[i].prox;
        } else {
            m->A[pos_anterior].prox = m->A[i].prox;
        }
        
        m->A[i].prox = m->disp;
        m->disp = i;
    }
}

int main(){
    Lista a;
    criar_lista(&a);
    inserir_ordenado(&a, 3);
    inserir_ordenado(&a, 1);
    inserir_ordenado(&a, 4);
    inserir_ordenado(&a, 2);
    exibir(&a);
    
    int posicao = buscar_elemento(&a, 4);
    printf("Posição do elemento 4: %d\n", posicao);
    
    excluir_elemento_posicao(&a, 2);
    exibir(&a);
    
    excluir_elemento_valor(&a, 2);
    exibir(&a);
    
    return 0;
}
