#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"
#include "arvr.h"

int main (){
  int opcao;
  int p, f, a;
    
  node *PILHA = (node *) malloc (sizeof (node));
  PILHA->prox = NULL;
  
  len *FILA = (len *) malloc(sizeof(len));
  FILA->prox = NULL;
  
  //Questao 2
  ArvB arv;
  arv.raiz = NULL;
  No *raiz = NULL;
  do{
        //menu principal
        printf ("\n--Escolha a estrutura que deseja--\n");
        printf ("\n1- Estrutura de PILHA");
        printf ("\n2- Estrutura de Fila");
        printf ("\n3- Estrutura de Arvore");
        printf("\n0- Fechar programa!\n");
        printf ("Escolha: ");
        scanf ("%d", &opcao);
        
        printf ("\n-------------------------------------\n");
        
        switch (opcao) {
        //menu PILHA
            case 1:
                do{
                    printf ("\nEscolha o que deseja fazer na estrutura de PILHA:");
                    printf ("\n1- Empilhar");
                    printf ("\n2- Desempilhar");
                    printf ("\n3- Imprimir");
                    printf ("\n4- Limpar");
                    printf ("\n5- Topo");
                    printf("\n0- Inicio\n");
                    printf ("Escolha: ");
                    scanf ("%d", &p);
                    
                    switch (p){
                        case 0:
                            printf("\nRetornando a menu principal...\n");
                            break;
                        case 1:
                            PUSH(PILHA);
                            break;
                            
                        case 2:
                            POP(PILHA);
                            break;
                            
                        case 3:
                            IMPRIME(PILHA);
                            break;
                            
                        case 4:
                            LIMPAR(PILHA);
                            break;
                            
                        case 5:
                            Topo(PILHA);
                            break;
                            
                        default:
                            printf ("\nErro ao indentificar escolha!\n");
                    }
                } while(p != 0);
            break;
            
            //menu FILA
            case 2:
                do{
                    printf ("\nEscolha o que deseja fazer na estrutura de FILA:");
                    printf ("\n1- Enfileirar");
                    printf ("\n2- Desenfileirar");
                    printf ("\n3- Imprimir");
                    printf ("\n4- Limpar");
                    printf ("\n5- Maior elemento");
                    printf ("\n6- Menor elemento");
                    printf ("\n0- Inicio\n");
                    printf ("Escolha: ");
                    scanf ("%d", &f);
                    
                    switch(f){
                        case 0:
                            printf("\nRetornando a menu principal...\n");
                            break;
                        case 1:
                            ENQUEUE(FILA);
                            break;
                        case 2:
                            DEQUEUE(FILA);
                            break;
                            
                        case 3:
                            IMPRESSO(FILA);
                            break;
                            
                        case 4:
                            APAGAR(FILA);
                            break;
                            
                        case 5:
                            Maior(FILA);
                            break;
                            
                        case 6:
                            Menor(FILA);
                            break;
                            
                        default:
                            printf("\nErro ao indentificar escolha!\n");
                            break;
                    }
                }while(f != 0);
            break;
            
            //menu Arvore
            case 3:
                do{
                   printf ("\nEscolha o que deseja fazer na estrutura de Arvore:");
                   printf ("\n1- Inserir");
                   printf ("\n2- Imprimir");
                   printf ("\n3- Remover");
                   printf ("\n4- Buscar");
                   printf ("\n5- Imprimir(SubArvore a direita primeiro!)");
                   printf ("\n6- Maior elemento");
                   printf ("\n0- Inicio\n");
                   printf ("Escolha: ");
                   scanf ("%d", &a);
                   
                    switch (a){
                        case 0:
                            printf("\nRetornando a menu principal...\n");
                            break;
                        case 1:
                            int esc;
                            printf("\nDigite o valor que deseja inserir: ");
                            scanf("%d", &esc);
                            raiz = inserir(raiz, esc);
                            break;
                            
                        case 2:
                            printf("\n");
                            imprimir(raiz);
                            printf("\n");
                            break;
                             
                        case 3:
                            int v;
                            printf("\n");
                            printf("Itens da arvore atual: ");
                            imprimir(raiz);
                            printf("\nQual dos valores deseja remover? ");
                            scanf("%d", &v);
                            
                            remover(raiz, v);
                            break;
                            
                        case 4:
                            int val;
                            
                            printf("\nQual valor deseja busca? ");
                            scanf("%d", &val);
                            buscar(raiz,val);
                            break;
                            
                        case 5:
                            printf("\n");
                            imprimirD(raiz);
                            printf("\n");                            
                            break;
                         
                        case 6:
                            maiorA(raiz);
                            break;
                         
                        default:
                            printf ("\nErro ao indentificar escolha!\n");
                            break;
                    } 
                }while(a != 0);  
            break;
            case 0:
                printf("\nPrograma finalizado!\n");
                break;
            default:
                printf("\nErro ao indentificar escolha!\n");
                break;
        }
    }while(opcao != 0);
}