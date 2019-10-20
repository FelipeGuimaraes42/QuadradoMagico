#include <stdio.h>
#define MIN 3
#define MAX 6

void zeramatriz(short int n, short int mat[n][n]){
    short int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            mat[i][j]=0;
        }
    }
}

void matrizcontinua(short int n, short int mat[n][n]){
    short int i, aux, j;
    aux=1;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            mat[i][j]= aux;
            aux++;
        }
    }
}

void removediagonal(short int n, short int mat[n][n], short int *vet){
    short int i, j, aux;
    aux=0;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if((i==j) || (i+j==3)){
                vet[aux]= mat[i][j];
                mat[i][j]= 0;
                aux++;
            }
        }
    }
}

void printamatriz(short int n, short int mat[n][n]){
    short int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%hi\t", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void qmagimp(short int n){
    short int quad[n][n];
    zeramatriz(n, quad);
    short int l, c, cont;
    l=0;
    cont= 1;
    c= n/2;
    while(cont<=(n*n)){
        if(quad[l][c]== 0){
            quad[l][c]= cont;
            c++;
            l--;
            cont++;
        }else{
            l+=2;
            c--;
            quad[l][c]= cont;
            c++;
            l--;
            cont++;
        }
        if(l==-1 && c==n){
            l=1;
            c=n-1;
        }else{
            if(l<0){
                l= n-1;
            }
            if(c==n){
                c= 0;
            }
        }
    }
    printamatriz(n, quad);
}

void qmagpar(short int n){
    short int quad[n][n];
    short int l, c, aux;
    aux=0;
    if(n==4){
        short int vet[8];
        matrizcontinua(n, quad);
        removediagonal(n, quad, vet);
        for(l=n-1; l>=0; l--){
            for(c=n-1; c>=0; c--){
                if(quad[l][c]==0){
                    quad[l][c]= vet[aux];
                    aux++;
                }
            }
        }
        printamatriz(n, quad);
    }else{
        qmagimp(3);
    }
}

void main(){
    short int n, soma;
    do{
        printf("Digite a ordem do quadrado magico (Entre 3 e 6): ");
        scanf("%hi", &n);
    }while(n<MIN || n>MAX);
    soma= ((n*n+1)*n)/2;
    printf("Soma= %hi\n", soma);
    if(n%2==1){
        qmagimp(n);
    }else{
        qmagpar(n);
    }
}