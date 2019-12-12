#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <locale.h>

/**	  COR DA LETRA E FUNDO	 	  
 **
 **    0 = Preto       		 8 = Cinza
 **	  1 = Azul				 9 = Azul claro  
 **	  2 = Verde				10 = Verde claro
 **	  3 = Verde-água		11 = Verde-água claro
 **	  4 = Vermelho			12 = Vermelho claro
 **	  5 = Roxo			    13 = Lilás   
 **	  6 = Amarelo			14 = Amarelo claro
 **	  7 = Branco			15 = Branco brilhante
 **
 **/

void cor(int letra, int fundo){
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, letra);

  HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
  BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
  bufferInfo.wAttributes &= 0x000F;
  SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= (fundo << 4));

}     

//POSIÇÃO DO CURSOR (LINHA,COLULA)
void setcursor(int y, int x){ 
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}
int potencia(int ba, int ex){
int x,r=1;    
   for (x=1; x<=ex; x++)
      r=r*ba;
   return (r);   
}
