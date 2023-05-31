#include <stdio.h>

void bubble(int *vetor) {
    int i, y;
    int cont = 0;
    for (i = 0; i < 10; i++) {
        for (y = 0; y < 10 - i - 1; y++) {
            if (vetor[y] > vetor[y+1]) {
                cont = vetor[y];
                vetor[y] = vetor[y+1];
                vetor[y+1] = cont;
            }
            
        }
    }
    printf("\nNuemros ordenados de fromna crescente:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
}


void insort(int *vetor) {
    int i, j, cal;
    
    for (i = 1; i < 10; i++) {
        cal = vetor[i];
        j = i - 1;
        
        while (j >= 0 && vetor[j] > cal) {
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = cal;
    }
    printf("\nNúmeros ordenados de forma crescente:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
}

int main()
{
    int vetor[10], opcao;
    
    printf("Qual funcao de organizacao que desejas:");
    printf("\n1 - Bubble Sort\n");
    printf("2 - InsertionSort");
    printf("\nEscolha: ");
    scanf("%d", &opcao);
    
    
    switch(opcao){
        case 1:
        printf("\n----- Funcao Bubble Sort -----\n");
        
        printf("\n--Digite 10 valores--\n");
        printf("\n");
         
        for(int i = 0; i < 10; i++){
            printf("Digite o valor do %d: ", i+1);
            scanf("%d", &vetor[i]);
        }
            bubble(vetor);
            break;
            
        case 2:
            printf("\n----- Funcao InsertionSort-----\n");
         
            printf("\n--Digite 10 valores--\n");
            printf("\n");
            
            for(int i = 0; i < 10; i++){
                printf("Digite o valor do %d: ", i+1);
                scanf("%d", &vetor[i]);
            }
            insort(vetor);
            break;
            
        default:
            printf("\nEscolha não compriendida!");
            break;
    }
    
    

    return 0;
}
