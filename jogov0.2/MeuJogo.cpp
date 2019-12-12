#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

//Menu
void menu();
//Sair do menu
void start();

//Os Controle do jogo.
void control();

//cordenadas dos personagens.
struct obj{
       float x, y, wx, wy, w, h;
};
struct obj p = {350, 500, 199, -1, 100, 90};
//cordernação das imagens do personagem.
float nTile = 0,dir = 0, i;

//variaveis globais
BITMAP *buffer, *menus, *PS;
  //descidindo se tem menu ou nao
     int S_N=1;
     
   

int main(){
    //Inicio
    allegro_init();
    //O tempo do jogo.
    install_timer();
    //Intalação do teclado.
    install_keyboard();
    //instalação das cores do jogo.
    set_color_depth(32);
    //Para detectar a placa de vídeo do computador
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
    //Nome do jogo. 
    set_window_title("JOGO");
     
     
   //variaveis LOCAIS
   int x,y, vel;
   int cx_0 = 0;
   
   
   
   
   //imagens
   buffer      = create_bitmap(800, 600);
   BITMAP* personagem  = load_bitmap("personagem2.bmp",NULL);
   //Fundos
   menus = load_bitmap("Menu.bmp",NULL);
   PS = load_bitmap("PS.bmp",NULL);         
   BITMAP* fundo       = load_bitmap("fundoUP.bmp",NULL);
   BITMAP* fundo2L     = load_bitmap("fundo2Atu.bmp",NULL);
   BITMAP* fundo2D     = load_bitmap("fundo2Atu.bmp",NULL);
   
              
                       
   
    while(!key[KEY_ESC])
    {
    control();
    

    
   
    
                
    //movimentação do cenario
    if(cx_0 < -1) cx_0 = 0;
    cx_0 -= 6;
    
    
    //Parte do desenho
    
    //Desenho do fundo
    draw_sprite(buffer, fundo, 0,0);
    //Desenho do personagem
    masked_blit(personagem,buffer, p.wx - nTile * 100, p.wy + dir * 72, p.x, p.y, p.w, p.h);   
    menu();                
    draw_sprite(screen, buffer, 0, 0);
  
   if ( p.x < 0 ) p.x = 0;
   if ( p.x > 700 ) p.x = 700;
   if ( p.y < 0 ) p.y = 0;
   if ( p.y > 502 ) p.y = 502; 
   
    //Descançar por um tempo.
    rest(50);
    //Limpar buffer.
    clear(buffer); 
                    
}
     //Destruição das imagens
     destroy_bitmap(buffer);
     destroy_bitmap(menus);
     destroy_bitmap(PS);
     destroy_bitmap(fundo);
     destroy_bitmap(personagem);
      
return 0;
}
END_OF_MAIN();  




void control(){
  
    // Irá para a direita ao apertar
    if (key[KEY_RIGHT]) {
        p.x += 10;
        dir = 2.7;
        nTile++;
    //Esse comando serve para correr
    if(key[KEY_Q]){
        p.x += 5;                
       }
    }
    //Irá para a esquerda ao apertar
     if (key[KEY_LEFT]) {
        p.x -= 10;
        dir = 1.4;
        nTile--;
        //Esse comando serve para correr
    if(key[KEY_Q]){
        p.x -= 5;                
       }  
    }
        //Irá para cima ao apertar
     if (key[KEY_UP]) {
        p.y -= 10;
        dir = 4.1;
        nTile++;
    //Esse comando serve para correr
    if(key[KEY_Q]){
        p.y -= 5;                
       }
    }
  //Irá para baixo ao apertar
    if (key[KEY_DOWN]) {
        p.y += 10;
        dir = 0.1;
        nTile--;
  //Esse comando serve para correr
    if(key[KEY_Q]){
        p.y += 5;                
       }
        
    }
    // Condição para movimentar.
    if (nTile < 0) nTile = 2;
    if (nTile > 2) nTile = 0;


     }  

//Aqui mostra como irá parar o meno
void start(){
       if(key[KEY_SPACE]){
        S_N=0;      
}  
     
     }

void menu(){
     int time = 0, flash = 0;
   
   
   
    if(S_N==1){ 
     while(!key[KEY_SPACE]){
     //contador
      if(time > 20) time=0;
     
     
     draw_sprite(buffer, menus, 0, 0); 
     //O time serve para fazer aparecer e sumir a imagem
      if(time < 10)
     draw_sprite(buffer, PS, 200, 400); 
     
     draw_sprite(screen, buffer, 0, 0);
         rest(100);
        clear(buffer);
         time++;
 //O start serve para parar o menu
 start();
   
     } 
    }
  } 
  
  
