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
//parte dos mapas
void colisao();
void ataque();
void mudamapa();
void cenarios();



//cordenadas dos personagens.
struct obj{
       float x, y, wx, wy, w, h;
};
struct obj p = {350, 500, 201, -1, 87, 90};
//----------teste-----------------

struct obj2{
       float z, t, qz, qt, q, g;
};
struct obj2 p2 = {350, 100, 199, -1, 96, 90};

//---------------------------
//cordernação das imagens do personagem.
float nTile = 0,dir = 0,i,nTile2 = 0,dir2 = 0;



//============variaveis globais=======================//
BITMAP *buffer, *menus, *PS, *gameover,*decisao,*vida,*vida1,*vida2,*vidaRenova, *sair;
BITMAP *persoatk, *personagem, *personagem2, *inimigo, *inimigo2, *vidaini, *NOT, *fundo, *fundo2;
BITMAP *paredefalsa,*bau,*bauaberto, *fundodnv, *baufechado, *baucore, *fundo3SairCavF, *fundo3SairCavA;
//descidindo se tem menu ou nao
 int S_N=1;
//descidindo dano
 int danoper=8;
 int danoini=4;
//matar inimigo 
 int matar=1;
//ataque 
 int atq=1;
 int B_C=2;
 int E_D=0;
//Mudar o mapa 
int mm=0;
int mm2=0;
int mf=0; 
int cx_0=0;
int pf=10,pf2=270;
//pegar coração
int core=0;
 
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
 
   
   
   
   
   //imagens
   buffer        = create_bitmap(800, 600);
   personagem    = load_bitmap("personagem3.bmp",NULL);
   personagem2   = load_bitmap("personagem3.bmp",NULL);
   persoatk      = load_bitmap("Atakperson3.bmp",NULL);
   inimigo       = load_bitmap("SPmal4.bmp",NULL);
   inimigo2      = load_bitmap("SPmal6.bmp",NULL);
   //Fundos
   menus         = load_bitmap("Menu.bmp",NULL);
   PS            = load_bitmap("PS.bmp",NULL);         
   fundo         = load_bitmap("fundocavern.bmp",NULL);
   fundodnv      = load_bitmap("fundocavern.bmp",NULL);
   fundo2        = load_bitmap("carvernaup.bmp",NULL);
   paredefalsa   = load_bitmap("colisao.bmp",NULL);
   fundo3SairCavF= load_bitmap("saindocavF.bmp",NULL);
   fundo3SairCavA= load_bitmap("saindocavA.bmp",NULL);
   gameover      = load_bitmap("gameover.bmp",NULL);
   decisao       = load_bitmap("decisao.bmp",NULL);
    sair         = load_bitmap("sair.bmp",NULL);
    vida         = load_bitmap("vida.bmp",NULL);
    vidaini      = load_bitmap("vida.bmp",NULL);
    NOT          = load_bitmap("NOT.bmp",NULL);
    vidaRenova   = load_bitmap("vida.bmp",NULL);
    vida1        = load_bitmap("vida-1.bmp",NULL);
    vida2        = load_bitmap("vida-2.bmp",NULL);  
    bau          = load_bitmap("bau.bmp",NULL);  
    bauaberto    = load_bitmap("bauaberto.bmp",NULL);
    baufechado   = load_bitmap("bau.bmp",NULL); 
    baucore      = load_bitmap("baucore.bmp",NULL);                   
 //------------------------COMEÇOOOOOOOOO--------------------------------------////  
    while(!key[KEY_ESC])
    {
       if(key[KEY_N]){
          break;             
              }
      
    control();
    controlinimigo();
    dano();
    cenarios();   
    colisao();
    ataque();
    mudamapa();
    
   
    
                
    //movimentação do cenario
    if(cx_0 < -1) cx_0 = 0;
    cx_0 -= 100;
    
    
    //Parte do desenho
    
    //vidas
    draw_sprite(buffer, vidaini,0+p2.z,-30+p2.t);
    
    draw_sprite(buffer, vida,30,560);
    //Desenho do personagem
    masked_blit(personagem,buffer, p.wx - nTile * 100, p.wy + dir * 72, p.x, p.y, p.w, p.h); 
    if(matar==1){
    masked_blit(inimigo,buffer, p2.qz - nTile2 * 100, p2.qt + dir2 * 72, p2.z, p2.t, p2.q, p2.g);     
}
 
    menu();                
    draw_sprite(screen, buffer, 0, 0);
  

 
   
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
     destroy_bitmap(persoatk);
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
        E_D=2;
        B_C=0;
    //Esse comando serve para correr
    if(key[KEY_Q]){
        p.x += 2;                
       }
    
    if(key[KEY_SPACE]){
     personagem=persoatk;
        dir = 2.7;
        nTile++;
     }
    else{
    personagem=personagem2;
 }
}



    //Irá para a esquerda ao apertar
     if (key[KEY_LEFT]) {
        p.x -= 10;
        dir = 1.4;
        nTile--;
        E_D=1;
        B_C=0;
        //Esse comando serve para correr
    if(key[KEY_Q]){
        p.x -= 2;                
       }  
    
     if(key[KEY_SPACE]){
     personagem=persoatk;
        dir = 1.4;
        nTile--;
     }
    else{
    personagem=personagem2;
 }   
}
    
        //Irá para cima ao apertar
     if (key[KEY_UP]) {
        p.y -= 10;
        dir = 4.1;
        nTile++;
        B_C=1;
        E_D=0;
    //Esse comando serve para correr
    if(key[KEY_Q]){
        p.y -= 2;                
       }
    if(key[KEY_SPACE]){
    personagem=persoatk;
        dir = 4.1;
        nTile++;
     }
    else{
    personagem=personagem2;
}   
    
    }
  //Irá para baixo ao apertar
    if (key[KEY_DOWN]) {
        p.y += 10;
        dir = 0.1;
        nTile--;
        B_C=2;
        E_D=0;
  //Esse comando serve para correr
    if(key[KEY_Q]){
        p.y += 2;                
       }
  if(key[KEY_SPACE]){
     personagem=persoatk;
        dir = 0.1;
        nTile--;
     }
    else{
    personagem=personagem2;
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
     int time = 0;
   
   
   
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

 if(p.y != 500){
        
       
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
}
 
  
}

void dano(){
  
  //=============dano do personagem ao inimigo==============
  if(key[KEY_SPACE]){
   if(p.x == p2.z &&  p.y == p2.t    || p.x == p2.z+80 &&  p.y == p2.t ||
      p.x == p2.z &&  p.y == p2.t+80 || p.x == p2.z-80 &&  p.y == p2.t ||
      p.x == p2.z &&  p.y == p2.t-80 ||
      p.x == p2.z &&  p.y == p2.t+60 || p.x == p2.z-60 &&  p.y == p2.t ||
      p.x == p2.z &&  p.y == p2.t-60 ||
      p.x == p2.z &&  p.y == p2.t+40 || p.x == p2.z-40 &&  p.y == p2.t ||
      p.x == p2.z &&  p.y == p2.t-40 ||
      p.x == p2.z &&  p.y == p2.t+20 || p.x == p2.z-20 &&  p.y == p2.t ||
      p.x == p2.z &&  p.y == p2.t-20 ||
      p.x == p2.z &&  p.y == p2.t+10 || p.x == p2.z-10 &&  p.y == p2.t ||
      p.x == p2.z &&  p.y == p2.t-10){
    
    danoini=danoini-1;
   
   if(danoini==3){
   vidaini=vida1;
      }
   if(danoini==1){
   vidaini=vida2;
      }
    
     }
   }

 if(danoini==0){
    matar=0;
     vidaini=NOT;
       mm=1;
}
 


//=================dano do inimigo ao perso=========================
if(matar==1){
if(p.x == p2.z &&  p.y == p2.t || p.x == p2.z+80 &&  p.y == p2.t ||
      p.x == p2.z &&  p.y == p2.t+40 || p.x == p2.z-40 &&  p.y == p2.t ||
      p.x == p2.z &&  p.y == p2.t-40 ||
      p.x == p2.z &&  p.y == p2.t+20 || p.x == p2.z-20 &&  p.y == p2.t ||
      p.x == p2.z &&  p.y == p2.t-20 ||
      p.x == p2.z &&  p.y == p2.t+10 || p.x == p2.z-10 &&  p.y == p2.t ||
      p.x == p2.z &&  p.y == p2.t-10){
          
  danoper = danoper-1;  
  if(danoper==6){
  vida=vida1;
 }
  if(danoper==2){
  vida=vida2;
  }
 }
}

   
if(danoper==0){
     S_N=1;
     danoper=8;  
     danoini==6;
     vida=vidaRenova;
     vidaini=vidaRenova;
     p.x=350; p.y=500;
     p2.z=350; p2.t=100;
     fundo=fundodnv;    
     bau=baufechado;
     mf=0;
     mm=0; 
     mm2=0;      
   
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
 
void colisao(){
   
   //colisão no personagem

   //limite para passar da parede
   
  //parte inicio
if(mm==0){
   if ( p.x < 0   )  p.x = 0;
   if ( p.x > 700 )  p.x = 700;
   if ( p.y < 0   )  p.y = 0;
   if ( p.y > 515 )  p.y = 515; 
  }
  
   //parte caverna
if(mm==2){    
   //if( p.x < pf ) p.x=pf;
   if( p.y > pf2) p.y=pf2;
   if ( p.x < 10  )   p.x = 10;
   if ( p.x >400  )   p.x = 400;
   if ( p.y < 30  )   p.y = 30;
   if ( p.y > 480 )   p.y = 480; 
  }
    
  
  
  //parte saindo da caverna
if(mm2==3){
   if ( p.x < 0 )   p.x = 0;
   if ( p.x > 700 ) p.x = 700;
   if ( p.y < 150 )   p.y = 150;
   if ( p.y > 502 ) p.y = 502; 
     }
    }  
   

void ataque(){
  if(key[KEY_UP] || key[KEY_DOWN] || key[KEY_LEFT] || key[KEY_RIGHT]){ 
   atq=0; 
   }
   else{
   atq=1;
   }
 


 
if(atq==1){
  
  //DOWN
  if(B_C==2){
if(key[KEY_SPACE]){
     personagem=persoatk;
        dir = 0.1;
        nTile--;
     }
    else{
    personagem=personagem2;
}
 }
  
  
  //UP
  if(B_C==1){
    if(key[KEY_SPACE]){
    personagem=persoatk;
        dir = 4.1;
        nTile++;
     }
    else{
    personagem=personagem2;
 } 
  }
  
  
//LEFT
if(E_D==1){
     if(key[KEY_SPACE]){
     personagem=persoatk;
        dir = 1.4;
        nTile--;
     }
    else{
    personagem=personagem2;
 } 
} 


//RIGHT
 if(E_D==2){
 if(key[KEY_SPACE]){
     personagem=persoatk;
        dir = 2.7;
        nTile++;
     }
    else{
    personagem=personagem2;
  }  
 }
}
     }   
     
     
     
     
     
     
     
     
     
// Aonde muda os mapas===================     
     
   
void mudamapa(){

 //==========segundo mapa entrando na caverna===============
 if(mm==1){
  if(p.y>41 && p.y<140 && p.x>600 && p.x<700){
   fundo=fundo2;    
    p.y=200;
    p.x=500;
    p2.t=100;
    p2.z=200;
    mm=2;
    mf=1;
    matar=1;
     danoini=6;  
     vidaini=vidaRenova;
           }    
       }
//=========terceiro mapa- saindo da caverna===========       
 if(mm2==2){
  if(p.y>20 && p.y<40 && p.x>200 && p.x<280){
    fundo=fundo3SairCavF; 
    inimigo=inimigo2;   
    p.y=300;
    p.x=0;
    p2.t=300;
    p2.z=500;
    mm2=3;
    mm=4;
    mf=2;
    matar=1;
     danoini=6;  
     vidaini=vidaRenova;
           }    
        }  
     }
 
 
 
 
 
 //parte de configuração dos mapas===================    
     
     
void cenarios(){ 
   if(cx_0 < -800){
    cx_0 = 0;
    cx_0 -= 100;
}

//Desenho do fundo
if(mf==0){
  draw_sprite(buffer, fundo,0,0);
 }
 
 //tudo sobre o mapa da caverna//////////
if(mf==1){
mm=2;
draw_sprite(buffer, fundo,cx_0 - p.x,cx_0 - p.y);
draw_sprite(buffer, paredefalsa,pf,pf2);
draw_sprite(fundo, bau,300,200);

if(core==0){
int time=0;
if(key[KEY_SPACE]){
if(p.y>41 && p.y<80 && p.x>80 && p.x<150){
bau=baucore;

core=1;

  }
 }
}

if(core==1){
if(key[KEY_Y]){
if(p.y>41 && p.y<80 && p.x>80 && p.x<150){
bau=bauaberto;
vida=vidaRenova; 
danoper=8;
mm2=2; 
 
    }            
   }           
  }
 }
 
 
//======mapa-> saindo da caverna======= 
if(mf==2){
mm=4;
mm2=3;
draw_sprite(buffer, fundo,0,0);
if(danoini==0){              
fundo=fundo3SairCavA;               
               }
 
 }
}     
    
     

