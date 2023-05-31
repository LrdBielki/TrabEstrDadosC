//Questao 2 - b
struct Ordem{
    int conteudo;
    struct Ordem *prox;
    int tam;
};
typedef struct Ordem len;

int EMPTY(len *FILA){
    if(FILA->prox == NULL){
        return 1;
    }else{
        return 0;
    }
}

//enfileira
void ENQUEUE(len *FILA){
    int qntd;
    
    printf("\nQuantos deseja enfileirar?\n");
    printf("Escolha: ");
    scanf("%d", &qntd);
    printf("\n");
    FILA->tam = 0;
    
    for(int i = 0; i < qntd; i++){
    
    len *novo = (len *) malloc(sizeof(len));
    novo->prox = NULL;
    
    printf("Novo item da FILA: ");
    scanf("%d", &novo->conteudo);
    
    if(EMPTY(FILA)){
        FILA->prox = novo;
    }else{
        len *tmp = FILA->prox;
        while(tmp->prox != NULL){
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }
    FILA->tam++;
    }
}

//Desenfileira
void DEQUEUE(len *FILA){
    if(FILA->prox == NULL){
        printf("\nFILA esta vazia\n");
        return;
    }else{
        len *tmp = FILA->prox;
        FILA->prox = tmp->prox;
        FILA->tam--;
        free(tmp);
    }
}

//imprimir
void IMPRESSO(len *FILA){
    if(EMPTY(FILA)){
        printf("\nFILA vazia!\n");
        return;
    }
    len *tmp;
    tmp = FILA->prox;
    printf("\nFILA");
    while(tmp != NULL){
        printf("%3d", tmp->conteudo);
        tmp = tmp->prox;
    }
printf("\nQtde itens FILA: %d", FILA->tam);
printf("\n");
}

//limpar
void APAGAR(len *FILA){
    while(FILA->prox != NULL){
        DEQUEUE(FILA);
    }
    printf("\nFILA foi esvaziada!\n");
}

//maior elemento
int Maior(len *FILA){
    if(EMPTY(FILA)){
        printf("\nFILA vazia!\n");
        return -1;
    }
    int m = FILA->prox->conteudo;
    len* tmp = FILA->prox->prox;
    while(tmp != NULL){
        if(tmp->conteudo > m){
            m = tmp->conteudo;
        }
        tmp = tmp->prox;
    }
    printf("\nMaior elemento da FILA: %d\n", m);
}

//menor elemento
int Menor(len *FILA){
    if(EMPTY(FILA)){
        printf("\nFILA vazia!\n");
        return -1;
    }
    int n = FILA->prox->conteudo;
    len* tmp = FILA->prox->prox;
    while(tmp != NULL){
        if(tmp->conteudo < n){
            n = tmp->conteudo;
        }
        tmp = tmp->prox;
    }
    printf("\nMenor elemento da FILA: %d\n", n);
}




