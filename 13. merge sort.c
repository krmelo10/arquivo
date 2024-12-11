#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//gera um vetor aleatório
void vrandom(int *v, int tam){
    for(int i=0;i<tam;i++){
        v[i]=rand();
    }
}

//merge de dois subvetores
void merge(int v[],int e,int m,int d){
    int i,j,k;
    int n1=m-e+1;//tamanho do primeiro subvetor
    int n2=d-m;//tamanho do segundo subvetor

    //arrays temporários
    int E[n1],D[n2];

    //copia os dados para os arrays temporários
    for(i=0;i<n1;i++){
        E[i]=v[e+i];
    }
    for(j=0;j<n2;j++){
        D[j]=v[m+1+j];
    }

    //merge os dois arrays de volta no vetor v[]
    i=0;
    j=0;
    k=e;
    while(i<n1&&j<n2){
        if(E[i]<=D[j]){
            v[k]=E[i];
            i++;
        }else{
            v[k]=D[j];
            j++;
        }
        k++;
    }

    //copia os elementos restantes de E[],se houverem.
    while(i<n1){
        v[k]=E[i];
        i++;
        k++;
    }

    //copia os elementos restantes de D[],se houverem.
    while(j<n2){
        v[k]=D[j];
        j++;
        k++;
    }
}

//função recursiva de ordenação merge_sort
void merge_sort(int v[],int e,int d){
    if(e<d){
        //encontra o ponto médio
        int m=e+(d-e)/2;

        //ordena as duas metades
        merge_sort(v,e,m);
        merge_sort(v,m+1,d);

        //faz o merge das duas metades ordenadas
        merge(v,e,m,d);
    }
}

//função mede o tempo de execução
double execucao(int v[],int tam){
    clock_t t=clock();
    merge_sort(v,0,tam-1);
    t=clock()-t;
    return((double)t)/(CLOCKS_PER_SEC/1000);
}

//função principal
int main(){
    int tam;
    printf("digite o tamanho do vetor: ");
    scanf("%d",&tam);

    int *v=(int *)malloc(tam*sizeof(int));

    //gera o vetor aleatório
    vrandom(v,tam);

    //calcula o tempo de execução
    double tempo=execucao(v,tam);
    printf("tempo de execução: %.2lf ms\n",tempo);

    free(v);
    return 0;
}
