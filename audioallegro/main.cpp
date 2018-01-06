#include <allegro.h>
#define ancho 800
#define alto 400

int main()
{
	allegro_init();
	install_keyboard();

	int pausa;

	// incializa el audio en allegro
    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) {
       allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
       return 1;
    }

    // ajustamos el volumen
	set_volume(230, 200);

	// definimos el audio del programa
	SAMPLE *musica1 = load_wav("01.wav");
	SAMPLE *musica2 = load_wav("02.wav");
	SAMPLE *sonido1 = load_wav("03.wav");
	SAMPLE *sonido2 = load_wav("04.wav");
	SAMPLE *sonido3 = load_wav("05.wav");
	SAMPLE *sonido4 = load_wav("06.wav");
    SAMPLE *sonido5 = load_wav("07.wav");
    SAMPLE *sonido6 = load_wav("08.wav");
    SAMPLE *sonido7 = load_wav("09.wav");


	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, ancho, alto, 0, 0);

	BITMAP *buffer = create_bitmap(ancho, alto);
	pausa = 0;

    while ( !key[KEY_ESC] )
    {
       clear_to_color(buffer, 0x333333);
       if ( key[KEY_ENTER] )
       {
            if ( pausa == 0)
            {
               midi_pause();
               pausa = 1;
            }else{
               midi_resume();
               pausa = 0;
            }
       }

       if ( key[KEY_O] )
       {
            play_sample(musica1,200,150,1000,0);
       }

       if ( key[KEY_H] )
       {
            play_sample(musica2,200,150,1000,0);
       }

       if ( key[KEY_SPACE] )
       {
            play_sample(sonido1,200,150,1000,0);
       }
       if ( key[KEY_Z] )
       {
            play_sample(sonido2,200,150,1000,0);
       }
       if ( key[KEY_D] )
       {
            play_sample(sonido3,200,150,1000,0);
       }
       if ( key[KEY_I] )
       {
            play_sample(sonido4,200,150,1000,0);
       }
       if ( key[KEY_R] )
       {
            play_sample(sonido5,200,150,1000,0);
       }

       if ( key[KEY_W] )
       {
            play_sample(sonido6,200,150,1000,0);
       }

       if ( key[KEY_Q] )
       {
            play_sample(sonido7,200,150,1000,0);
       }


	   rectfill(buffer, 2, 2, ancho-4, alto-4, 0xDF1680);//0xDADADA
	   rectfill(buffer, 30, 30, ancho-30, alto-30, 0x000000);//0x000000

       textout_centre_ex(buffer, font, "ESC para Salir", ancho/2, 10, 0xFFFFFF, 0xDF1680);
       textout_centre_ex(buffer, font, "1.- Sonido 1", ancho/5, 110, 0xFFFFFF, 0x333333);
       textout_centre_ex(buffer, font, "2.- Sonido 2", ancho/2.5, 110, 0xFFFFFF, 0x333333);
       textout_centre_ex(buffer, font, "3.- Sonido 3", ancho/1.7, 110, 0xFFFFFF, 0x333333);

       textout_centre_ex(buffer, font, "4.- Sonido 4", ancho/5, 220, 0xFFFFFF, 0x333333);
       textout_centre_ex(buffer, font, "5.- Sonido 5", ancho/2.5, 220, 0xFFFFFF, 0x333333);
       textout_centre_ex(buffer, font, "6.- Sonido 6", ancho/1.7, 220, 0xFFFFFF, 0x333333);

       textout_centre_ex(buffer, font, "7.- Sonido 7", ancho/1.3, 160, 0xFFFFFF, 0x333333);
       //textout_centre_ex(buffer, font, "8.- Sonido 8", ancho/2, 280, 0xFFFFFF, 0x333333);
       //textout_centre_ex(buffer, font, "9.- Sonido 9", ancho/1.3, 280, 0xFFFFFF, 0x333333);



       //textout_centre_ex(buffer, font, "ENTER detiene musica", ancho/2, 250, 0xFFFFFF, 0x333333);

	   textout_centre_ex(buffer, font, "HECHO POR TEAM AlejandroAndreArturo", ancho/2, alto-20, 0xFFFFFF, 0xDF1680);

	   blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
    }


    // liberamos memoria
    destroy_sample(musica1);
    destroy_sample(musica2);
    destroy_sample(sonido1);
    destroy_sample(sonido2);
    destroy_sample(sonido3);
    destroy_sample(sonido4);
    destroy_sample(sonido5);
    destroy_sample(sonido6);
    destroy_sample(sonido7);
	destroy_bitmap(buffer);

	return 0;
}
END_OF_MAIN();
