#include <stdio.h>

int buscar(int *vet, int inicio, int fim, int item)
{
    
    int i = (inicio + fim) / 2;

    if (inicio > fim) { 
        return -1;
    }
    if (vet[i] == item) { 
        return i;
    }
    if (vet[i] < item) {
        return buscar(vet, i + 1, fim, item);
    } else {  
        return buscar(vet, inicio, i - 1, item);
    }
}    

int main(){
    int vet[5];
    int inicio;
    int fim;
    int item = 5;
    
    for (int x = 0; x < 5; x++)
  {
    printf("Digite os valores das notas: ");
    scanf("%d", &vet[x]);
  }
    
    printf("Esta no Vetor", buscar(vet, inicio, fim, item));
    
}