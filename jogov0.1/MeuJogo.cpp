#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

//Os Controle do jogo.
void control();

//cordenadas dos personagens.
struct obj{
       float x, y, wx, wy, w, h;
};
struct obj p = {350, 500, 199, -1, 100, 90};
//cordernação das imagens do personagem.
float nTile = 0,dir = 0, i;


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
     
     
   //variaveis
   int x,y, vel;
   int cx_0 = 0;
   
   
   //imagens
   BITMAP* buffer   = create_bitmap(800, 600);
   BITMAP* personagem = load_bitmap("personagem2.bmp",NULL);

   BITMAP* fundo  = load_bitmap("fundoUP.bmp",NULL);
   BITMAP* fundo2L  = load_bitmap("fundo2Atu.bmp",NULL);
   BITMAP* fundo2D  = load_bitmap("fundo2Atu.bmp",NULL);
   //BITMAP* casas  = load_bitmap("casas.bmp",NULL);
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
    }
        //Irá para a esquerda ao apertar
    else if (key[KEY_LEFT]) {
        p.x -= 10;
        dir = 1.4;
        nTile--;
    }
        //Irá para cima ao apertar
    else if (key[KEY_UP]) {
        p.y -= 10;
        dir = 4.1;
        nTile++;
    }
        //Irá para baixo ao apertar
    else if (key[KEY_DOWN]) {
        p.y += 10;
        dir = 0.1;
        nTile--;
    }
    // Condição para movimentar.
    if (nTile < 0) nTile = 2;
    if (nTile > 2) nTile = 0;


     }  
