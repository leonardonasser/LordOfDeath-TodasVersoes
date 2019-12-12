#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

//Menu
void menu();
//Sair do menu
void start();

//Os Controle do jogo.
void control();
void controlinimigo();
void dano();


//cordenadas dos personagens.
struct obj{
       float x, y, wx, wy, w, h;
};
struct obj p = {350, 500, 199, -1, 100, 90};
//----------teste-----------------

struct obj2{
       float z, t, qz, qt, q, g;
};
struct obj2 p2 = {300, 100, 199, -1, 96, 90};

//---------------------------
//cordernação das imagens do personagem.
float nTile = 0,dir = 0,i,nTile2 = 0,dir2 = 0;



//============variaveis globais=======================//
BITMAP *buffer, *menus, *PS, *gameover,*decisao,*vida,*vida1,*vida2,*vidaRenova, *sair;
//descidindo se tem menu ou nao
 int S_N=1;
//descidindo dano
 int danoper=8;
 int danoini=2;
   

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
   BITMAP* inimigo       = load_bitmap("SPmal4.bmp",NULL);
   //Fundos
   menus         = load_bitmap("Menu.bmp",NULL);
   PS            = load_bitmap("PS.bmp",NULL);         
   BITMAP* fundo = load_bitmap("fundoup.bmp",NULL);
   gameover      = load_bitmap("gameover.bmp",NULL);
   decisao       = load_bitmap("decisao.bmp",NULL);
    sair       = load_bitmap("sair.bmp",NULL);
    vida         = load_bitmap("vida.bmp",NULL);
    vidaRenova   = load_bitmap("vida.bmp",NULL);
    vida1        = load_bitmap("vida-1.bmp",NULL);
    vida2        = load_bitmap("vida-2.bmp",NULL);         
                       
   
    while(!key[KEY_ESC])
    {
       if(key[KEY_N]){
          break;             
              }
              
    control();
    controlinimigo();
    dano();
    
   
    
                
    //movimentação do cenario
    if(cx_0 < -1) cx_0 = 0;
    cx_0 -= 6;
    
    
    //Parte do desenho
    
    //Desenho do fundo
    draw_sprite(buffer, fundo,0,0);
    draw_sprite(buffer, vida,0,0);
    //Desenho do personagem
    masked_blit(personagem,buffer, p.wx - nTile * 100, p.wy + dir * 72, p.x, p.y, p.w, p.h); 
    masked_blit(inimigo,buffer, p2.qz - nTile2 * 100, p2.qt + dir2 * 72, p2.z, p2.t, p2.q, p2.g);      
    
    menu();                
    draw_sprite(screen, buffer, 0, 0);
  

  //limite para passar da parede
   if ( p.x < 0 )   p.x = 0;
   if ( p.x > 700 ) p.x = 700;
   if ( p.y < 0 )   p.y = 0;
   if ( p.y > 502 ) p.y = 502; 
   
    //Descançar por um tempo.
    rest(50);
    //Limpar buffer.
    clear(buffer); 
                    
}
     //Destruição das imagens
     destroy_bitmap(buffer);
     destroy_bitmap(menus);
     destroy_bitmap(gameover);
     destroy_bitmap(decisao);
     destroy_bitmap(PS);
     destroy_bitmap(fundo);
     destroy_bitmap(personagem);
     destroy_bitmap(vida);
      
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
         if(key[KEY_N]){
          break;             
              }
     //contador
      if(time > 20) time=0;
     
     
     draw_sprite(buffer, menus, 0, 0); 
     draw_sprite(buffer, sair, 0, 0);
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
  
void controlinimigo(){
 
 // Irá para a direita ao apertar
    if(p2.z<p.x) {
        p2.z += 5;
        dir2 = 2.7;
        nTile2++;
        }
    
    //Irá para a esquerda ao apertar
    if(p2.z>p.x) {
        p2.z -= 5;
        dir2 = 1.4;
        nTile2--;
}
     //Irá para cima ao apertar
    if(p2.t>p.y) {
        p2.t -= 5;
        dir2 = 4.1;
        nTile2++; 
        }
  //Irá para baixo ao apertar
    if(p2.t<p.y ) {
        p2.t += 5;
        dir2 = 0.1;
        nTile2--;
        }
    // Condição para movimentar.
    if (nTile2 < 0) nTile2 = 2;
    if (nTile2 > 2) nTile2 = 0;
    
  if( p.x == p2.z &&  p.y == p2.t ){
    
     }
  
}
void dano(){
  
  if(p.x == p2.z-60 ||  p.y == p2.t-60 || p.x == p2.z+60 ||  p.y == p2.t+60){
       
       danoper = danoper-1;  
 if(danoper==6){
  vida=vida1;
}
  if(danoper==2){
  vida=vida2;
}
         } 
   
    if(danoper==0){
     S_N=1;
     danoper=8;  
     vida=vidaRenova;

     p.x=350; p.y=500;
     p2.z=300; p2.t=100;           
   
   while(!key[KEY_Y]){
       if(key[KEY_N]){
          break;             
              }
   
        draw_sprite(buffer, gameover,130,100);
        draw_sprite(buffer, decisao,-30,480);
        draw_sprite(screen, buffer, 0, 0);
         rest(100);
         clear(buffer);

   }
  }
 }
