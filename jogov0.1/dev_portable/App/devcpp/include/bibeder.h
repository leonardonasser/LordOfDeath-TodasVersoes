#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.c>
#include <locale.h>

int * bubble_sort(int vet[], int tamanho);
int * selection_sort(int vet[], int tamanho);
int * insertion_sort (int vet[],int tamanho);
int * vetor_randomizado(int n);
void escreve(char *msg, int lin, int col, int corL, int corF);
void janela(int linI,int linF,int colI,int colF, int corLetra, int corFundo);
void limpa(int linI,int linF,int colI,int colF, int corFundo);

//----------------------------------------------------------
void janela(int linI,int linF,int colI,int colF, int corLetra, int corFundo){
  //setlocale(LC_ALL,"en_us");
  textcolor(corLetra);
  textbackground(corFundo);
  for (int x=colI+1;x<colF;x++){
    gotoxy(x,linI);
    
    printf("%c",205);
    gotoxy(x,linF);
    printf("%c",205);
    
    }     
  for (int x=linI+1;x<linF;x++){
    gotoxy(colI,x);
    printf("%c",186);
    gotoxy(colF,x);
    printf("%c",186);
    
    }     
    gotoxy(colI,linI);
    printf("%c",201); 
    gotoxy(colI,linF);
    printf("%c",200);
    gotoxy(colF,linI);
    printf("%c",187);
    gotoxy(colF,linF);
    printf("%c",188);
     
    textcolor(7);
    textbackground(0);
    //setlocale(LC_ALL,"portuguese");
}    
//----------------------------------------------------------

void limpa(int linI,int linF,int colI,int colF, int corFundo){
  
  
  textbackground(corFundo);
  
  for (int x=linI+1;x<linF;x++){
    for (int y=colI+1;y<colF;y++){
      gotoxy(y,x);
      printf(" ");
    } 
  }
  textbackground(0);      
}    
//----------------------------------------------------------
void escreve(char *msg, int lin, int col, int corL, int corF){
     setlocale(LC_ALL,"portuguese");
     gotoxy(col,lin);
     textcolor(corL);
     textbackground(corF);
     printf("%s",msg);
}
//----------------------------------------------------------
int * bubble_sort(int vet[], int tamanho) {
    int i, j, aux;
     
     for (i=0; i<tamanho; i++){
         for (j=0; j<tamanho-1-i; j++) {
            if (vet[j] > vet[j+1]) { //efetuará a troca caso a condição seja satisfeita
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
                
            }
         }
     }
    return vet;
}
//----------------------------------------------------------
int * selection_sort(int vet[], int tamanho) {
   int i, j, aux;
   
   for (i = 1; i < tamanho; i++) {
       aux = vet[i];
       j = i-1;
 
       while (j >= 0 && vet[j] > aux)  {
           vet[j+1] = vet[j];
           j = j-1;
		   
       }
       vet[j+1] = aux;
   }
   return vet;
}
//----------------------------------------------------------
int * insertion_sort (int vet[],int tamanho) {
  int i, j, min, aux;
    
  for (i = 0; i < (tamanho - 1); i++) {
    /* O minimo é o primeiro número não ordenado ainda */
    min = i;
    for (j = i+1; j < tamanho; j++) {
      /* Caso tenha algum numero menor ele faz a troca do minimo*/
      if (vet[j] < vet[min]) {
   		min = j;
      }
    }
    /* Se o minimo for diferente do primeiro numero não ordenado ele faz a troca para ordena-los*/
    if (i != min) {
      aux = vet[i];
      vet[i] = vet[min];
      vet[min] = aux;
      
    }
  }
 return vet; 
}
//----------------------------------------------------------
int * vetor_randomizado(int tamanho) {
    
    int * array = (int *) calloc (tamanho, sizeof (int));
    
    for (int i = 0; i < tamanho; ++i) {
        array[i] = rand()%50000; //sorteia 50.000 possibilidades (0-49.999)
    }
    return array;
}
//----------------------------------------------------------
