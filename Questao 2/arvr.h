//Questao 2 - c
typedef struct no{
    int chave;
    struct no *esquerda, *direita;
} No;

typedef struct{
    No *raiz;
    int tam;
} ArvB;

No* inserir(No *raiz, int valor){
    if(raiz == NULL){
        No *novo = (No*) malloc (sizeof(No));
        novo->chave = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    } else{
        if(valor < raiz->chave){
            raiz->esquerda = inserir(raiz->esquerda, valor);
        }
        if(valor > raiz->chave){
            raiz->direita = inserir(raiz->direita, valor);
        }
        return raiz;
    }
}

void imprimir(No *raiz){
    if(raiz != NULL){
       imprimir(raiz->esquerda);
        printf(" %d ", raiz->chave);
        imprimir(raiz->direita);
    } 
}

No* remover(No *raiz, int item){
    if(raiz == NULL){
        printf("\nValor nao encontrado!\n");
        return NULL;
    } else {
        if(raiz->chave == item){
            if(raiz->esquerda == NULL && raiz->direita == NULL){
                free(raiz);
                return NULL;
            } else {
                if(raiz->esquerda == NULL || raiz->direita == NULL){
                    No *aux;
                    if(raiz->esquerda != NULL){
                        aux = raiz->esquerda;
                    } else {
                        aux = raiz->direita;
                    }
                    free(raiz);
                    return aux;
                } else {
                    No *aux = raiz->esquerda;
                    while(aux->direita != NULL){
                        aux = aux->direita;
                    }
                    raiz->chave = aux->chave;
                    aux->chave = item;
                    raiz->esquerda = remover(raiz->esquerda, item);
                    return raiz;
                }
            }
        } else {
            if(item < raiz->chave){
                raiz->esquerda = remover(raiz->esquerda, item);
            } else{
                raiz->direita = remover(raiz->direita, item);
            }
            return raiz;
        }
    }
}

//Questao 2 - c - i
int buscar(No *raiz, int val){
    if(raiz == NULL){
        printf("\nValor nao encontrado na Arvore!\n");
        return 1;
    }else{
        if(val < raiz->chave){
            return buscar(raiz->esquerda, val);
        } else if(val > raiz->chave){
            return buscar(raiz->direita, val);
        } else {
            printf("\nValor encontrado na Arvore!\n");
            return 0;
        }
    }
}


//Questao 2 - c - ii
void imprimirD(No *raiz){
    if(raiz != NULL){
        imprimir(raiz->direita);
        printf(" %d ", raiz->chave);
        imprimir(raiz->esquerda);
    }
}

//Questao 2 - c - iii
void maiorA(No *raiz) {
    if (raiz == NULL) {
        printf("\nArvore vazia!\n");
        return;
    }
    No *atual = raiz;
    while (atual->direita != NULL) {
        atual = atual->direita;
    }
    printf("\nMaior elemento da Arvore é: %d\n", atual->chave);
}



