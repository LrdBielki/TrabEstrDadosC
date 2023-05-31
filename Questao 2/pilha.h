//Questao 2 - a
struct Node{
    int item;
    struct Node *prox;
    int tam;
    struct Node *topo;
};
typedef struct Node node;

int vazia(node *PILHA){
    if(PILHA->prox == NULL){
        return -1;
    }else{
        return 0;
    }
}

//Empilha
void PUSH(node *PILHA){
    node *novo = (node *) malloc(sizeof(node));
    novo->prox = NULL;
    novo->item = PILHA->item;
    PILHA->topo = novo;

    printf("\nDigite o novo item da PILHA: ");
    scanf("%d", &novo->item);
    
    if(vazia(PILHA)){
        PILHA->prox = novo;
    }else{
        node *tmp = PILHA->prox;
        while(tmp->prox != NULL){
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }
    PILHA->tam++;
  }

//imprimir
void IMPRIME(node *PILHA){
    if(vazia(PILHA)){
        printf("\nPILHA vazia!\n");
        return;
    }
    node *tmp;
    tmp = PILHA->prox;
    printf("\nPILHA: ");
    while(tmp != NULL){
        printf("% d ", tmp->item);
        tmp = tmp->prox;
    }
printf("\nQtde itens PILHA: %d\n", PILHA->tam);
}

//desempilhar
void POP(node *PILHA){
    if(PILHA->prox == NULL){
        printf("\nPILHA ja esta vazia!\n");
        return;
    }else{
        node *ultimo = PILHA->prox;
        node *penultimo = PILHA;
        
        while(ultimo->prox != NULL){
            penultimo = ultimo;
            ultimo = ultimo->prox;
        }
        free(ultimo);
        penultimo->prox = NULL;
        PILHA->topo = penultimo;
        PILHA->tam--;
    }
}

//limpar
void LIMPAR(node *PILHA){
    while(PILHA->prox != NULL){
        POP(PILHA);
    }
    printf("\nPILHA foi limpa!\n");
}

//topo
int Topo(node *PILHA){
    if (PILHA->prox == NULL) {
        printf("\nA PILHA está Vazia!\n");
        return -1;
    } else {
        int i = PILHA->topo->item;
        printf("\nTopo da PILHA eh: %d\n", i);
    }
}

