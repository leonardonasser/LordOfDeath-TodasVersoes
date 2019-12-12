#include <stdio.h>
#include <stdlib.h>

int potencia(int ba, int ex){
int x,r=1;    
   for (x=1; x<=ex; x++)
      r=r*ba;
   return (r);   
}
