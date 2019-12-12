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
void arvores();
void tutoriais();
void historia();



//cordenadas dos personagens.
struct personagem{
       float x, y, wx, wy, w, h;
};
struct personagem p = {350, 500, 201, -1, 87, 90};
//----------teste-----------------

//inimigo normal
struct ini{
       float z, t, qz, qt, q, g;
};
struct ini p2 = {350, 100, 199, -1, 96, 90};

//chefaoo
struct irmaoo{
       float c, u, eu, ec, e, j;
};
struct irmaoo p3 = {350, 100, 201, -1, 87, 90};

//---------------------------
//corderna��o das imagens do personagem.
float nTile = 0,dir = 0,i,nTile2 = 0,dir2 = 0,nTile3=0,dir3=0;



//============variaveis globais=======================//
BITMAP *buffer, *menus,*menusvolta,*creditos,*voltar,*PS,*setadireita,*paracontinuar,*textocreditos,*sairvolta,*space,*spacehist, *gameover,*decisao,*vida,*vida1,*vida2,*vidaRenova, *sair;
BITMAP *persoatk, *personagem, *personagem2,*irmao, *inimigo, *inimigo2, *vidaini, *NOT, *fundo, *fundo2;
BITMAP *paredefalsa,*bau,*bauaberto, *fundodnv, *baufechado, *baucore, *fundo3SairCavF, *fundo3SairCavA, *inimigodnv;
BITMAP *toco,*folhas,*pontecastelo,*castelo,*quartocastelo,*poraoCastelo,*armarioNormal,*armarioAberto,*chefaoprimeiro,*chefaosegundo;
BITMAP *irmaocenario,*textoPressY,*textoInstrucional,*textoPressF;
//vida do chefao
BITMAP *vidachefao,*vidachefao1,*vidachefao2,*vidachefao3,*vidachefao4,*vidachefao5,*vidachefao6;
BITMAP *vidachefao7,*vidachefaofinal,*chefaosp,*vidachefaodnv,*tutorial,*historiainicio,*historiafinal;
BITMAP *Imagensdahistoria,*Imagensdahistoria2;
//SAMPLE *proerdSamp;
MIDI *proerd,*musica,*battleboss;
//descidindo se tem menu ou nao
int S_N=1;
//historias conifg
int HistoriaS_N=0;
int mudarimagens=0;
//decidindo se tem toturial o nao
int ligadesligatoturial=0;
//descidindo dano
int danoper=8;
int danoini=4;
int chefao=0;
int perirmao=0;
//matar inimigo 
int matar=1;
//ataque 
int atq=1;
int B_C=2; //BAIXO E PARA CIMA
int E_D=0; //ESQUERDA E PARA DIREITA
//Mudar o mapa 
int mm=0; //muda mapa
int mm2=0;//muda mapa 2
int mc=0;//muda cenario
int mf=0; //muda fundo e o confifura
int cx_0=0; //mexer o mapa
int pf=10,pf2=270; // parede falsa
//pegar cora��o
int core=0; //cora��o
int tempinho = 0, flash = 0; //faz cenarios piscarem
 //armario
 int armarioEntrando=0;
int main(){
    //Inicio
    allegro_init();
    //O tempo do jogo.
    install_timer();
    //Intala��o do teclado.
    install_keyboard();
    //instala��o das cores do jogo.
    set_color_depth(32);
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
    //Para detectar a placa de v�deo do computador
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
    //Nome do jogo. 
    set_window_title("JOGO");
     
       
   
   
   //imagens
   buffer        = create_bitmap(800, 600);
   
   //personagens
   personagem    = load_bitmap("personagem3.bmp",NULL);
   personagem2   = load_bitmap("personagem3.bmp",NULL);
   irmao         = load_bitmap("irmao.bmp",NULL);
   irmaocenario  = load_bitmap("irmaocenario.bmp",NULL);
   persoatk      = load_bitmap("Atakperson3.bmp",NULL);
   inimigo       = load_bitmap("SPmal4.bmp",NULL);
   inimigodnv    = load_bitmap("SPmal4.bmp",NULL);
   inimigo2      = load_bitmap("SPmal6.bmp",NULL);
   chefaoprimeiro= load_bitmap("chefaoprimeiro.bmp",NULL);
   chefaosegundo = load_bitmap("chefaosegundo.bmp",NULL);
   //irmao      = load_bitmap("chefao.bmp",NULL);
   
   //menu ou gameover
   gameover            = load_bitmap("gameover.bmp",NULL);
   decisao             = load_bitmap("decisao.bmp",NULL);
    sair               = load_bitmap("sair.bmp",NULL);
    sairvolta          = load_bitmap("sair.bmp",NULL);
   textocreditos       = load_bitmap("textocreditos.bmp",NULL);
   textoPressY         = load_bitmap("textoPressY.bmp",NULL);
    textoInstrucional  = load_bitmap("textoInstrucional.bmp",NULL);
    space              = load_bitmap("space.bmp",NULL);
    textoPressF        = load_bitmap("textoPressF.bmp",NULL);
    voltar             = load_bitmap("voltar.bmp",NULL);
   menus               = load_bitmap("Menu.bmp",NULL);
   menusvolta          = load_bitmap("Menu.bmp",NULL);
   creditos            = load_bitmap("creditos.bmp",NULL);
   PS                  = load_bitmap("PS.bmp",NULL);         
   //parte dos fundos
   fundo         = load_bitmap("fundocavern.bmp",NULL);
   fundodnv      = load_bitmap("fundocavern.bmp",NULL);
   fundo2        = load_bitmap("carvernaup.bmp",NULL);
   paredefalsa   = load_bitmap("colisao.bmp",NULL);
   fundo3SairCavF= load_bitmap("saindocavF.bmp",NULL);
   fundo3SairCavA= load_bitmap("saindocavA.bmp",NULL);
   pontecastelo  = load_bitmap("pontecastelo.bmp",NULL);
   castelo       = load_bitmap("castelo.bmp",NULL);
   quartocastelo = load_bitmap("quartocastelo.bmp",NULL);
   poraoCastelo = load_bitmap("poraoCastelo.bmp",NULL);
    //vidas
    vida         = load_bitmap("vida.bmp",NULL);
    vidaini      = load_bitmap("vida.bmp",NULL);
    NOT          = load_bitmap("NOT.bmp",NULL);
    vidaRenova   = load_bitmap("vida.bmp",NULL);
    vida1        = load_bitmap("vida-1.bmp",NULL);
    vida2        = load_bitmap("vida-2.bmp",NULL);  
    //baus e cenarios que interagem
    bau          = load_bitmap("bau.bmp",NULL);  
    bauaberto    = load_bitmap("bauaberto.bmp",NULL);
    baufechado   = load_bitmap("bau.bmp",NULL); 
    baucore      = load_bitmap("baucore.bmp",NULL);   
    armarioNormal= load_bitmap("armarioNormal.bmp",NULL);
    armarioAberto= load_bitmap("armarioAberto.bmp",NULL);   
   //arvores
    folhas       = load_bitmap("folhas.bmp",NULL); 
    toco         = load_bitmap("toco.bmp",NULL);  
   //toturiais
    tutorial     = load_bitmap("tutorial.bmp",NULL);
    //historias   
    historiainicio= load_bitmap("HistoriaInicial.bmp",NULL); 
       Imagensdahistoria  = load_bitmap("Imagensdahistoria.bmp",NULL);    
       Imagensdahistoria2 = load_bitmap("Imagensdahistoria2.bmp",NULL); 
       setadireita        = load_bitmap("setadireita.bmp",NULL);       
       spacehist          = load_bitmap("spacehist.bmp",NULL);
       paracontinuar      = load_bitmap("paracontinuar.bmp",NULL);
       historiafinal      = load_bitmap("historiafinal.bmp",NULL);
 //===vidas chefao====
 vidachefao      = load_bitmap("vidachefao.bmp",NULL); 
 vidachefao1     = load_bitmap("vidachefao-1.bmp",NULL); 
 vidachefao2     = load_bitmap("vidachefao-2.bmp",NULL); 
 vidachefao3     = load_bitmap("vidachefao-3.bmp",NULL);
 vidachefao4     = load_bitmap("vidachefao-4.bmp",NULL); 
 vidachefao5     = load_bitmap("vidachefao-5.bmp",NULL); 
 vidachefao6     = load_bitmap("vidachefao-6.bmp",NULL); 
 vidachefao7     = load_bitmap("vidachefao-7.bmp",NULL); 
 vidachefaofinal = load_bitmap("vidachefao-final.bmp",NULL);
 vidachefaodnv   = load_bitmap("vidachefao.bmp",NULL);  
  
 //SONS
  // proerdSamp = load_sample("proerdwav.wav");
   proerd = load_midi("PROERD.mid");
   musica = load_midi("Radioactive.mid");
   battleboss = load_midi("BossBattle.mid"); 
    
    //musica do menuuuuu 



 
 

 //------------------------COME�OOOOOOOOO--------------------------------------////  
    while(!key[KEY_ESC])
    {
       if(key[KEY_N]){
          break;             
              }
     //Musica Menu
 if(S_N==1){play_midi(proerd,0);}
           
    menu();
    historia(); 
    control();
    controlinimigo();
    dano();
    cenarios();   
    colisao();
    ataque();
    mudamapa();
    
   
    
                
    //movimenta��o do cenario
    if(cx_0 < -1) cx_0 = 0;
      cx_0 -= 100;
    
    
    //Parte do desenho
    
//Desenho dos personagem

//Meu personagem
      masked_blit(personagem, buffer, p.wx - nTile * 100, p.wy + dir * 72, p.x, p.y, p.w, p.h); 

    if(matar==1){
//inimigo normal 
      masked_blit(inimigo,buffer, p2.qz - nTile2 * 100, p2.qt + dir2 * 72, p2.z, p2.t, p2.q, p2.g);     
}
    if(perirmao==1){
//personagem irmao           
      masked_blit(irmao,buffer, p3.ec - nTile3 * 122, p3.eu + dir3 * 100, p3.c, p3.u, p3.e, p3.j);            
              }
    if(perirmao==2){
       draw_sprite(buffer, irmaocenario,350,20);             
                    }          
     
     //cenarios que fazem diferen�a
     arvores();
     tutoriais();
//vida do inimigo padrao
    if(chefao==0){draw_sprite(buffer, vidaini,0+p2.z,-30+p2.t);}
//vida do chefao
    if(chefao==1){draw_sprite(buffer, vidachefao,150,10);}

//vida do personagem
    draw_sprite(buffer, vida,30,560);
    
 textprintf(buffer,font,0,0,221,"P.x=%f \n P.y=%f",p.x,p.y);
    //buffer, fundo preto
    draw_sprite(screen, buffer, 0, 0);
    //Descan�ar por um tempo.
    rest(50);
    //Limpar buffer.
    clear(buffer);
    tempinho++;                    
}
     //Destrui��o das imagens
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



//===============Inicia o controle do personagem=================
void control(){
     
    // Ir� para a direita ao apertar
    if (key[KEY_RIGHT]) {
        p.x += 10;
        dir = 2.7;
        nTile++;
        E_D=2;
        B_C=0;
    //esse comando serve para atacar
    if(key[KEY_SPACE]){
     personagem=persoatk;
        dir = 2.7;
        nTile++;
     }
    else{personagem=personagem2;}
}



    //Ir� para a esquerda ao apertar
     if (key[KEY_LEFT]) {
        p.x -= 10;
        dir = 1.4;
        nTile--;
        E_D=1;
        B_C=0;
    //esse comando serve para atacar 
     if(key[KEY_SPACE]){
     personagem=persoatk;
        dir = 1.4;
        nTile--;
     }
    else{personagem=personagem2;}   
}
    
    //Ir� para cima ao apertar
     if (key[KEY_UP]) {
        p.y -= 10;
        dir = 4.1;
        nTile++;
        B_C=1;
        E_D=0;
    //esse comando serve para atacar
    if(key[KEY_SPACE]){
    personagem=persoatk;
        dir = 4.1;
        nTile++;
     }
    else{personagem=personagem2;}   
    
}

  //Ir� para baixo ao apertar
    if (key[KEY_DOWN]) {
        p.y += 10;
        dir = 0.1;
        nTile--;
        B_C=2;
        E_D=0;
    //esse comando serve para atacar
  if(key[KEY_SPACE]){
     personagem=persoatk;
        dir = 0.1;
        nTile--;
     }
    else{personagem=personagem2;}   
   
}
    // Condi��o para movimentar.
    if (nTile < 0) nTile = 2;
    if (nTile > 2) nTile = 0;

}
  

//=========Aqui mostra como ir� parar o menu=============
void start(){
   if(key[KEY_SPACE]){              
     //troca a musica;                    
       play_midi(musica,1);
     //desliga menu
       if(S_N==1){S_N=0;}}  
   }
//==============Aqui Inicia o Menu========================
void menu(){
     int time = 0, flash = 0,desligaPs=0;
  
 //Aqui � aonde inicia o menu- S_N liga e desliga o Menu 
    if(S_N==1){ 
     while(!key[KEY_SPACE]){
         if(key[KEY_N]){break;}
//contador
      if(time > 20) time=0;
      
      
      if(key[KEY_C]){menus=creditos;sair=voltar; desligaPs=1;}
      if(key[KEY_ESC]){menus=menusvolta; desligaPs=0; sair=sairvolta;}  
     
     draw_sprite(buffer, menus, 0, 0);
    if(desligaPs==0){
     draw_sprite(buffer, textocreditos, 400, 550); 
     }
     draw_sprite(buffer, sair, 0, 0);
     //O time serve para fazer aparecer e sumir a imagem
      if(desligaPs==0){
      if(time < 10){
     draw_sprite(buffer, PS, 200, 380);
     draw_sprite(buffer, space, 620, 420);
     }
     } 
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
        
      
    //Ir� para a direita 
    if(p2.z<p.x){
        p2.z += 4;
        p2.z+=1;
        dir2 = 2.7;
        nTile2++;
        }
    //Ir� para a esquerda 
    if(p2.z>p.x) {
        p2.z -= 4;
       p2.z-=1;
        dir2 = 1.4;
        nTile2--;
}
    //Ir� para cima 
    if(p2.t>p.y){
        p2.t -= 4;
        p2.t-=1;
        dir2 = 4.1;
        nTile2++;
        }
    //Ir� para baixo ao apertar
    if(p2.t<p.y ){
        p2.t += 4;
        p2.t+=1;
        dir2 = 0.1;
        nTile2--;
        }
    // Condi��o para movimentar.
    if (nTile2 < 0){ nTile2 = 2;}
    if (nTile2 > 2){ nTile2 = 0;}     

//contrle do irmao do personagem   
   if(perirmao==1){
    if(p3.c<p.x){
        p3.c += 7;
        dir3 = 2.7;
        nTile3++;  
        }
    if(p3.c>p.x){
        p3.c -= 7;
        dir3 = 1.4;
        nTile3--;
        }
    if(p3.u>p.y) { 
        p3.u -= 5;
        dir3 = 4.1;
        nTile3++;
        }
    if(p3.u<p.y ){
        p3.u += 5;
        dir3 = 0.1;
        nTile3--;
        }
  
    if (nTile3 < 0){ nTile3 = 2;}
    if (nTile3 > 2){ nTile3 = 0;}
}
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

      
    //reduz a vida do inimigo
    
    danoini=danoini-1;
    
  if(chefao==0){
     //vida do inimigo normal
   if(danoini==3){vidaini=vida1;}
   if(danoini==1){ vidaini=vida2;}
}

//vida do chefao 
   if(chefao==1){
     if(danoini==11){ vidachefao =  vidachefao1;   }   
     if(danoini==9) { vidachefao =  vidachefao2;   }         
     if(danoini==8) { vidachefao =  vidachefao3;   }
     if(danoini==6) { vidachefao =  vidachefao4;   }
     if(danoini==4) { vidachefao =  vidachefao5;   } 
     if(danoini==3) { vidachefao =  vidachefao6;   }
     if(danoini==2) { vidachefao =  vidachefao7;   }
     if(danoini==1) { vidachefao =  vidachefaofinal; play_midi(musica,1); mm2=3;}         
} 
  }
 }
//==========================================


//===Quando chega ao zero mata===========
 if(danoini==0){
    matar=0;
    vidaini=NOT;
    mm=1;
    chefao=0;
}
 


//=================dano do inimigo ao personagem=========================
if(matar==1){ 
   if(p.x == p2.z &&  p.y == p2.t    || p.x == p2.z+80 &&  p.y == p2.t ||
      p.x == p2.z &&  p.y == p2.t+40 || p.x == p2.z-40 &&  p.y == p2.t ||
      p.x == p2.z &&  p.y == p2.t-40 ||
      p.x == p2.z &&  p.y == p2.t+20 || p.x == p2.z-20 &&  p.y == p2.t ||
      p.x == p2.z &&  p.y == p2.t-20 ||
      p.x == p2.z &&  p.y == p2.t+10 || p.x == p2.z-10 &&  p.y == p2.t ||
      p.x == p2.z &&  p.y == p2.t-10){ 
          
   
   //reduz a vida do personagem
   danoper = danoper-1;
   
  if(danoper==6){vida=vida1;}
  if(danoper==2){vida=vida2;}
 }
}

   
if(danoper==0){
     matar=1;
     S_N=1;
     danoper=8;  
     danoini=4;
     inimigo=inimigodnv;
     vida=vidaRenova;
     vidaini=vidaRenova;
     vidachefao=vidachefaodnv;
     p.x=350; p.y=500;
     p2.z=350; p2.t=100;
     fundo=fundodnv;
     core=0;    
     bau=baufechado;
     mf=0;
     mm=0; 
     mm2=0;
     mc=0; 
     chefao=0; 
        
     
   //============PARTE DO GAMEOVER=============
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
     
 //===========Primeiro mapa=================
if(mc==0){
     //colis�o do tronco
//TRONCO DA DIREITA
  //encima e baixo
   if(p.x>560 && p.x<665 && p.y==360){p.y=p.y-20;}   
   if(p.x>560 && p.x<665 && p.y==430){p.y=p.y+20;}
//lados
   if(p.y>350 && p.y<430 && p.x==560){p.x=p.x-20;}
   if(p.y>350 && p.y<430 && p.x==690){p.x=p.x+20;}


//TRONCO DA ESQUERDA
  //encima e baixo
   if(p.x>20 && p.x<160 && p.y==360){p.y=p.y-20;}   
   if(p.x>20 && p.x<160 && p.y==430){p.y=p.y+20;}
//lados
   if(p.y>350 && p.y<430 && p.x==30){p.x=p.x-20;}
   if(p.y>350 && p.y<430 && p.x==160){p.x=p.x+20;}

   if ( p.x < 0   )  p.x = 0;
   if ( p.x > 730 )  p.x = 730;
   if ( p.y < 0   )  p.y = 0;
   if ( p.y > 515 )  p.y = 515; 
  }
  //============================================= 
   
 //============MAPA CAVERNA====================
if(mc==1){    
   //if( p.x < pf ) p.x=pf;
   if( p.y > pf2) p.y=pf2;
   if ( p.x < 10  )   p.x = 10;
   if ( p.x >400  )   p.x = 400;
   if ( p.y < 30  )   p.y = 30;
   if ( p.y > 480 )   p.y = 480; 
  }
//==============================================    
  
  
//========PARTE SAINDO DA CAVERNA===============
if(mc==2){
   if ( p.x < 0   )   p.x = 0;
   if ( p.x > 700 )   p.x = 700;
   if ( p.y < 150 )   p.y = 150;
   if ( p.y > 500 )   p.y = 500;  
}
//===============================================   

//colisao ponte
if(mc==3){
   //esquerdo ponte
   if ( p.y>287 && p.x <  395  )   p.x =  395;
   //esquerda encima      
   if(p.y<287 && p.x<325){p.x=325;} 
   if(p.x<355 && p.y>275){p.y=275;}  
  
   //direito ponte
   if ( p.y>287 && p.x >  580  )   p.x =  580;
    //direita encima
   if(p.y<287 && p.x>656){p.x=635;} 
   if(p.x>606 && p.y>275){p.y=275;} 
   
   if ( p.y <  175 )   p.y =  175;
   if ( p.y >  500 )   p.y =  500;              
          }
//colisao castelo
if(mc==4){
   //esquerda vaso verde
   if(p.x>10 && p.x<130 && p.y==360){p.y=p.y+10;}
   if(p.x>10 && p.x<130 && p.y==270){p.y=p.y-10;}
   
   //mureta do tapete e escada esquerda 
   if(p.y>35 && p.y<360 && p.x==140){p.x=p.x+10;}
   if(p.y>35 && p.y<360 && p.x==80){p.x=p.x-10;}
   //escada esquerda
   if(p.y>45 && p.y<150 && p.x==180){p.x=p.x-10;}
   if(p.y>120 && p.y<150 && p.x==240){p.x=p.x+10;}
   
   //mureta que fica encima da porta
   if(p.x>190 && p.x<580 && p.y==40){p.y=p.y-10;}
   //colisao porta
   if(p.x>190 && p.x<570 && p.y==120){p.y=p.y+10;}
    
   //parte esquerda
   
      //escada direita
   if(p.y>45 && p.y<150 && p.x==590){p.x=p.x+10;}
    if(p.y>120 && p.y<150 && p.x==540){p.x=p.x-10;}
   
   
    
   if ( p.x < 20 )   p.x = 20;
   if ( p.x > 620 )   p.x = 620;
   
   if ( p.y <  10 )   p.y =  10;
   if ( p.y >  370)   p.y =  370;        
          
          }          
  
  
  //COLISAO QUARTO DO CASTELO
  if(mc==5){
            //MESA PONTA DIREITA
    if(p.y>170 && p.y<310 && p.x==500){p.x=p.x+10;} 
    //MESA PONTA ESQUERDA
     if(p.y>170 && p.y<310 && p.x==210){p.x=p.x-10;}         
     
     //MESA ENCIMA
      if(p.x>210 && p.x<500 && p.y==170){p.y=p.y-10;}
     
     //MESA BAIXO
    if(p.x>210 && p.x<500 && p.y==310){p.y=p.y+10;}
    
    //planta lado direito
    if(p.y>=90 && p.y<=140 && p.x==70){p.x=p.x+10;}
    //planta baixo 
    if(p.x>=10 && p.x<=70 && p.y==150){p.y=p.y+10;}
    
    //colisao armario        
      //colisao embaxio
    if(p.x>=400 && p.x<=710 && p.y==140){p.y=p.y+10;}
      //lado esqueurdo
     if(p.y>100 && p.y<140 && p.x==360){p.x=p.x-10;}     
    
    
   if ( p.x < 20   )   p.x = 20;
   if ( p.x > 700 )   p.x = 700;
   if ( p.y < 110 )   p.y = 110;
   if ( p.y > 440 )   p.y = 440;  
}   
  
  
//COLISAO MAPA PORAO   
     if(mc==6){
   
   //PAREDE BAIXO -> ESQUERDA           
  if(p.y>=280 && p.y<=530 && p.x==60){p.x=p.x-10;}
   
   //PAREDE BAIXO -> ENCIMA
  if(p.x>=60 && p.x<=730 && p.y==270){p.y=p.y-10;} 
   
  
   //PAREDE ENCIMA -> BAIXO
  if(p.x>=60 && p.x<=700 && p.y==190){p.y=p.y+10;}  
   
   //PAREDE ENCIMA -> DIREITA
  if(p.y>=80 && p.y<=190 && p.x==700){p.x=p.x+10;} 
  
  //PARE ENCIMA -> ESQUERDA
  
   if(p.y>=-20 && p.y<=190 && p.x==50){p.x=p.x-10;} 
  
  
  //PAREDE ENCIMA, ENCIMA -> PARA DIREITA
   if(p.x>=700 && p.x<=730 && p.y==100){p.y=p.y+10;}  
   
   if ( p.x < 0 )   p.x = 0;
   if ( p.x > 710 )   p.x = 710;
   if ( p.y < 0 )   p.y = 0;
   if ( p.y > 510 )   p.y = 510;  
              
         
               }     

}

//CONFIGURA��O DOS ATAQUES DO PERSONAGEM
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
//=========================================================
     
     
     
     
     
     
     
//==============Aonde muda os mapas=========================       
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
    mc=1;
    mf=1;
    matar=1;
     danoini=6;  
     vidaini=vidaRenova;
           }    
       }
//=========terceiro mapa- saindo da caverna===========       
 if(mm2==2){
  if(p.y>20 && p.y<40 && p.x>200 && p.x<280){
    play_midi(battleboss,1);
    inimigo=chefaoprimeiro;
    fundo=fundo3SairCavF; 
    //inimigo=inimigo2;   
    p.y=300;
    p.x=0;
    p2.t=300;
    p2.z=500;
    mc=2;
    mm=4;
    mf=2;
    matar=1;
    danoini=12;  
    chefao=1;
    vidaini=vidaRenova;
           }    
        }  
     
 //muda para a ponte    
if(mm2==3){
 if(p.y>150 && p.y<170 && p.x>460 && p.x<570) {
  fundo=pontecastelo;
  p.y=490;
  p.x=500;
  mc=3;
  mf=3;
  mm2=4;
  danoini=6;
  matar=1;
  chefao=0;
  inimigo=inimigo2;  
  vidaini=vidaRenova;
  p2.z=490; p2.t=300;
   
  
    }     
  }
  
//ENTRA NO CASTELO
 if(mm2==4){
  if(p.y>177 && p.y<187 && p.x>420 && p.x<560) { 
     fundo=castelo;
     p.y=150;p.x=380;
     mf=4;
     mc=4;  
     mm=10;
     mm2=5;
     matar=1;
     chefao=0;
     danoini=8;
     inimigo=inimigodnv;  
     vidaini=vidaRenova;
     p2.z=380; p2.t=470;
 
  }            
}

//DENTRO DO QUARTO DO CASTELO
if(mm2==5){
    if(p.y>=10 && p.y<=20 && p.x>340 && p.x<430){
    fundo=quartocastelo;    
    //mc=5;
    mf=5;   
    mc=5;
    p.x=30;
    p.y=170;
        }  
}
//DENTRO DO PORAO CASTELO
 if(mm2==6){
   fundo=poraoCastelo;
   mc=6;       
   mf=6;    
  p.x=20;
  p.y=500;
  mm2=7;
  perirmao=2;
  
  
            }
 
}
//========================================================== 
 
 
 
 
//=======Parte de configura��o dos mapas===================    
     
void cenarios(){ 

//para mexer o cenario junto com o personagem;
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


 draw_sprite(fundo, textoInstrucional,200,150);




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
     mc=2;
     draw_sprite(buffer, fundo,0,0);
  if(danoini==0){              
     fundo=fundo3SairCavA;               
     
   }
     
  }

//Mapa-> Ponte para caverna
if(mf==3){       
  draw_sprite(buffer, fundo,0,-150);        
 }
 
//Mapa -> Castelo
if(mf==4){
  draw_sprite(buffer, fundo,-10,cx_0 - p.y);        
    if(p.y<250){mm=10;}
          }
 
 
//Mapa -> Quarto castelo 
if(mf==5){
  draw_sprite(buffer, fundo,0,0);  
 
   draw_sprite(fundo, armarioAberto,450,100);

 
   if(key[KEY_SPACE]){
      if(p.y>130 && p.y<160 && p.x>470 && p.x<530){
       mm2=6; 
   }
 }          
 
}          

//Mapa-> Por�o castelo 
  if(mf==6){
   
   if(tempinho > 20) tempinho=0;
   
            
   draw_sprite(buffer,fundo,0,0);       
   
   if(tempinho < 10)
   draw_sprite(buffer,textoPressF,160,180);        
       
       
 if(key[KEY_F]){HistoriaS_N=3;}      
          }


}     



 void arvores(){   
     
  //mapa inicio   
     if(mf==0){          
     //Arvore Esquerda Inferior
     draw_sprite(buffer, folhas,0,0);  
     draw_sprite(fundo, toco,88,250);    
     //Arvore Esquerda Superior
     draw_sprite(buffer, folhas,0,200);  
     draw_sprite(fundo, toco,88,440);    
     //Arvore Direita Inferior 
     draw_sprite(buffer, folhas,530,200);  
     draw_sprite(fundo, toco,618,440);
  }
} 
    
void tutoriais(){
 
 
 //para ligar e desligar o toturial
 if(p.y<450){
  if(key[KEY_SPACE]){ligadesligatoturial=1;}          
    }
 //tutorial
  if(ligadesligatoturial==0){
  if(tempinho > 25) tempinho=0;
  if(tempinho < 10)                           
  draw_sprite(buffer, tutorial,30,250); 
  }
         
}

void historia(){     
     int timehist= 0;
   
    //HITORIAFINAL
    if(HistoriaS_N==3){            
                       
     while(!key[KEY_SPACE]){
      if(key[KEY_N]){break;}
    draw_sprite(buffer,historiafinal,0,0);
     
      if(key[KEY_N]){HistoriaS_N=1;
      danoper=0;} 
     
     draw_sprite(screen, buffer, 0, 0);
     rest(100);
     clear(buffer); 
    
    }                  
      }
    
    //HISTORIA INICO
    if(HistoriaS_N==0){ 
     while(!key[KEY_SPACE]){
     if(key[KEY_N]){break;}
     if(timehist > 20) timehist=0;
  
        draw_sprite(buffer,historiainicio,0,0);
      
        draw_sprite(buffer,paracontinuar,530,350);
       if(mudarimagens==0){ 
         draw_sprite(buffer,Imagensdahistoria,40,320);
        if(timehist < 10)
         draw_sprite(buffer,setadireita,620,430);
         }
       if(mudarimagens==1){
         draw_sprite(buffer,Imagensdahistoria2,40,320);                  
         if(timehist < 10)
         draw_sprite(buffer,spacehist,600,430); 
                             }
                   
                           
        draw_sprite(screen, buffer, 0, 0);
        rest(100);
        clear(buffer); 
        if(key[KEY_RIGHT]){mudarimagens=1;}
       
        if(key[KEY_SPACE]){HistoriaS_N=1;}  
        timehist ++;
}
 }
  }
     

