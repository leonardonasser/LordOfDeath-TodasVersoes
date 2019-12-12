#include <allegro.h>

int main(){
    //Inicio
    allegro_init();
    install_timer();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
    set_window_title("JOGO");
     
     
   //variaveis
   int x=100,y=100, vel=5;
   BITMAP* buffer   = create_bitmap(800, 600);
   BITMAP* defrente = load_bitmap("Defrente.bmp",NULL);
   BITMAP* defrente2  = load_bitmap("Defrente2.bmp",NULL);
   BITMAP* defrente3  = load_bitmap("Defrente.bmp",NULL);
   BITMAP* detras   = load_bitmap("Detras.bmp",NULL);
   BITMAP* detrasT   = load_bitmap("Detras.bmp",NULL);
   BITMAP* deladoE  = load_bitmap("DeladoE.bmp",NULL);
   BITMAP* deladoD  = load_bitmap("DeladoD.bmp",NULL);
   
  
    while(!key[KEY_ESC])
    {
    //Começo  
    if(key[KEY_RIGHT]){x += 1; detras = deladoD; }
    if(key[KEY_LEFT]) {x -= 1; detras = deladoE; }
    if(key[KEY_UP])   {y -= 1; detras = detrasT; }
    
   if(key[KEY_DOWN]) { 
    y += 1; 
  detras=defrente; 
  defrente=defrente2;
  defrente2=defrente3;
  
  }            
    
    draw_sprite(buffer, detras, 260 + x, 400 + y);                    
     
    draw_sprite(screen, buffer, 0, 0);
    rest(5);
    clear(buffer); 
                    
}
     destroy_bitmap(buffer);
     destroy_bitmap(defrente);
     destroy_bitmap(defrente2);
     destroy_bitmap(defrente3);
     destroy_bitmap(detras);
     destroy_bitmap(detrasT);
     destroy_bitmap(deladoE);
     destroy_bitmap(deladoD);      
return 0;
}
END_OF_MAIN();    
