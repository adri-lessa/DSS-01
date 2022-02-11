#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//1. Vetor crescente:
void Growing_vector(int *vetor,int n){
    int i;
    for (i=0;i<n;i++){
        vetor[i]=i;
    }
}
//2. Vetor decrescente 
void Descending_vector(int *vetor,int n){
    int i;
    for (i=0;i<n;i++){
            vetor[i]=n-i-1;
    }
}
//3. Vetor aleatorio 
void Random_vector(int *vetor,int n){
    int i;
    srand(time(NULL));

    for (i=0;i<n;i++){
            vetor[i]=rand();
    }
}
//4. Vetor copia
void Copy_vector(int *original,int *copia,int n){
    int i;
    for (i=0;i<n;i++){
    copia[i]=original[i];
    }
}

//5. funcao imprimir vetor:
void Print_vector (int *vetor,int n){
    int i;
    printf("-A [");
    for (i=0;i<n;i++){
        printf("%d ",vetor[i]);
    }
    printf("]\n");
}

//6. funcao bubble com flag
void Bubble_sort(int *vetor, int n) {
    clock_t start, end;
    int i, j, aux, flag, cont=0;
    
    start=clock();
    for (i=0;i<n-1;i++){
        flag=0;
        for (j=0;j<n-i-1;j++){
            if (vetor[j]>vetor[j+1]){
                aux=vetor[j];
                vetor[j]=vetor[j+1];
                vetor[j+1]=aux;
                flag=1;
            }
            cont++;
        }
        if (flag==0){
            break;
        }
    }
    end=clock();
    double difTempo=((double)end-start)/CLOCKS_PER_SEC;
        
    printf("*** Bubble sort ***\n");
    printf("-comparacoes: %d\n",cont);
    printf("-tempo em s: %lf, Tempo em ms: %lf\n\n", difTempo, difTempo*1000);
}

//funcao selection:
void Selection_sort (int *vetor, int n){
    clock_t start, end;
    int i, j, aux, cont=0, menor;
    
    start = clock();
    for (i=0; i<n-2; i++){
        menor=i;
        for (j=i+1;j<n-i-1; j++){
            cont++;
            if (vetor[menor]>vetor[j]){
                aux=vetor[j];
                vetor[j]=vetor[menor];
                vetor[menor]=aux;
            }
            
        }
    }
    end = clock();
    double difTempo=((double)end-start)/CLOCKS_PER_SEC;
        
    printf("*** Selection sort ***\n");
    printf("-comparacoes: %d\n",cont);
    printf("-tempo em s: %lf, Tempo em ms: %lf\n\n", difTempo, difTempo*1000);
}
//funcao insertion:
void Insertion_sort (int *vetor, int n){
    clock_t start, end;
    int i, j, aux, cont=0;
    
    start = clock();
    for (i=1; i<n; i++){
        aux=vetor[i];

        for (j=i;j>0 && aux<(vetor[j-1]); j--){
            cont++;
            vetor[j]=vetor[j-1];
        }
        vetor[j]=aux;
    }
    end = clock();
    double difTempo=((double)end-start)/CLOCKS_PER_SEC;
        
    printf("*** Insertion sort ***\n");
    printf("-comparacoes: %d\n",cont);
    printf("-tempo em s: %lf, Tempo em ms: %lf\n\n", difTempo, difTempo*1000); 
}

int main (){
    int op=0;
    int n;
    printf ("Digite o tamanho do vetor (A):\n");
    scanf ("%d",&n);
    int A1[n];
    int A2[n];
    int A3[n];
    do{

        printf ("Escolha a ordenacao do vetor de entrada:\n1- Crescente\n2- Descrescente\n3- Aleatoria\n4- Sair\n");
        scanf("%d", &op);
        switch (op){
            case 1 :
                Growing_vector(A1,n);
                Copy_vector(A1,A2,n);
                Copy_vector(A1,A3,n);

                Bubble_sort(A1,n);
                Selection_sort(A2,n);
                Insertion_sort(A3,n); 
            break;

            case 2 :
                Descending_vector(A1,n);
                Copy_vector(A1,A2,n);
                Copy_vector(A1,A3,n);

                Bubble_sort(A1,n);
                Selection_sort(A2,n);
                Insertion_sort(A3,n);
            break;

            case 3 :
                Random_vector(A1,n);
                Copy_vector(A1,A2,n);
                Copy_vector(A1,A3,n);

                Bubble_sort(A1,n);
                Selection_sort(A2,n);
                Insertion_sort(A3,n);
            break;

            case 4 :
                printf ("Saindo...");
            break;

            default :
                printf ("Valor invalido!\n");
            break;
        }
    }while(op!=4);
}
