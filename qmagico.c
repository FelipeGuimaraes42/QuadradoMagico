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

void organizaposicao(short int n, short int quad[n][n]){
    short int i, j;
    for(i=0; i<3; i++){
        quad[2][i]= quad[1][i];
        quad[1][i]= quad[0][i+3];
        quad[0][i+3]= 0;
    }
}

void qmagimp(short int n, short int quad[n][n]){
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
    //printamatriz(n, quad);
}

void preencheordemseis(short int quad[6][6]){
    short int l, c, soma;
    soma=18;
    for(l=0; l<3; l++){
        for(c=3; c<6; c++){
            quad[l][c]= soma+quad[l][c-3];
        }
    }
    soma=27;
    for(l=3; l<6; l++){
        for(c=0; c<3; c++){
            quad[l][c]= soma+quad[l-3][c];
        }
    }
    soma=9;
    for(l=3; l<6; l++){
        for(c=3; c<6; c++){
            quad[l][c]= soma+quad[l-3][c-3];
        }
    }
}

void trocaordemseis(short int quad[6][6]){
    short int aux;
    aux= quad[0][0];
    quad[0][0]= quad[3][0];
    quad[3][0]= aux;
    aux= quad[1][1];
    quad[1][1]= quad[4][1];
    quad[4][1]= aux;
    aux= quad[2][0];
    quad[2][0]= quad[5][0];
    quad[5][0]= aux;
}

void qmagpar(short int n, short int quad[n][n]){
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
        zeramatriz(n, quad);
        qmagimp(3, quad);
        organizaposicao(n, quad);
        preencheordemseis(quad);
        trocaordemseis(quad);
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
    short int quad[n][n];
    if(n%2==1){
        qmagimp(n, quad);
    }else{
        qmagpar(n, quad);
    }
    printamatriz(n, quad);
}