#include <stdio.h>
#define MIN 3
#define MAX 6

void zeramatriz(short int n, short int mat[n][n]){
    //Preenche uma matriz com 0s
    short int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            mat[i][j]=0;
        }
    }
}

void matrizcontinua(short int n, short int mat[n][n]){
    //Preenche uma matriz com números de 1 a n
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
    /*Substitui os valores das diagonais principal e secundária por zeros.
      Salva esses valores em um vetor auxiliar*/
    short int i, j, aux;
    aux=0;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if((i==j) || (i+j==n-1)){
                vet[aux]= mat[i][j];
                mat[i][j]= 0;
                aux++;
            }
        }
    }
}

void trocadiagonal(short int n, short int mat[n][n], short int *vet){
    /*Substitui os zeros adicionados na função removediagonal pelos valores do vetor auxiliar.
      Porém, eles são inseridos na ordem inversa na qual eles foram removidos, isto é,
      o primeiro valor removido, será o último a ser inserido novamente na matriz.*/
    short int l, c, aux;
    aux=0;
    for(l=n-1; l>=0; l--){
        for(c=n-1; c>=0; c--){
            if(mat[l][c]==0){
                mat[l][c]= vet[aux];
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

void qmagimp(short int n, short int quad[n][n]){
    zeramatriz(n, quad);
    //l para linhas, c para colunas
    short int l, c, cont;
    l=0;
    cont= 1;
    c= n/2;
    //cont é o flag de valores inseridos na matriz, sendo n^2 o valor máximo de cont
    while(cont<=(n*n)){
        //Verifica se o valor é zero, se for, adiciona o valor e move o cursor para a diagonal superior
        if(quad[l][c]== 0){
            quad[l][c]= cont;
            c++;
            l--;
            cont++;
        //Se não for, adiciona o valor na linha abaixo e mesma coluna
        }else{
            l+=2;
            c--;
            quad[l][c]= cont;
            c++;
            l--;
            cont++;
        }
        //Exceção da regra, posição diagonal superior acima da ultima coluna e primeira linha
        if(l==-1 && c==n){
            l=1;
            c=n-1;
        }else{
            //Se a linha atual for anterior à primeira linha, muda o cursor para a última linha
            if(l<0){
                l= n-1;
            }
            //Se a coluna for superior à última coluna, muda o cursor para a primeira coluna
            if(c==n){
                c= 0;
            }
        }
    }
}

void organizaposicao(short int n, short int quad[n][n]){
    /*Após reutilizar o código do quadrado mágico 3x3 no quadrado mágico 6x6, os valores são inseridos
      em posições contíguas na matriz, logo, precisamos realocá-los*/
    short int i;
    for(i=0; i<3; i++){
        quad[2][i]= quad[1][i];
        quad[1][i]= quad[0][i+3];
        quad[0][i+3]= 0;
    }
}

void preencheordemseis(short int quad[6][6]){
    //Copia os valores somados a uma constante para os subquadrados 3x3 restantes
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

void trocaordemseis(short int n, short int quad[n][n]){
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
    if(n==4){
        short int vet[n*2];
        matrizcontinua(n, quad);
        removediagonal(n, quad, vet);
        trocadiagonal(n, quad, vet);
    }else{
        zeramatriz(n, quad);
        qmagimp(n/2, quad);
        organizaposicao(n, quad);
        preencheordemseis(quad);
        trocaordemseis(n, quad);
    }
}

int main(){
    short int n, soma;
    //Valida a entrada de dados
    do{
        printf("\nDigite a ordem do quadrado magico (Entre 3 e 6): ");
        scanf("%hi", &n);
    }while(n<MIN || n>MAX);
    //Calcula a soma mágica
    soma= ((n*n+1)*n)/2;
    printf("\nSoma Magica= %hi\n", soma);
    short int quad[n][n];
    //Quadrados mágicos pares e ímpares são implementados de formas diferentes
    if(n%2==1)
        qmagimp(n, quad);
    else
        qmagpar(n, quad);
    printamatriz(n, quad);

    return 0;
}