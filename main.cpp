#include "header.h"

	int prevMainField[40][60] = {NULL};
	int mainField[40][60] = {NULL};
	int suppFieldX[60][20] = {NULL}, suppFieldY[40][20] = {NULL};
	int helphelpField[40][60] = {NULL};
	bool user_exit = false;
	bool draw = true;
	bool redraw = true;
	int wight = 1024, height = 600;
	int centerX = 0, centerY = 0;
	int nullX = 0, nullY = 0;
	int scale = 0;
	int xMap = 0, yMap = 0;
	enum MENU;
	int mousePosX = 0, mousePosY = 0, prevMousePosX = 0, prevMousePosY = 0;
	bool buttonMenu[12] = {false, false, false, false, false, false, false, false, false, false, false, false};
	bool mainMenu = false;
	FILE *users;
	char user_name[10];
	int user_lvl = 0;
	int byteNumb = 0;
	struct button_level buttonStruct;
	int currentLevel = 0;
	int maxSuppX = 0, maxSuppY = 0;
	bool generate = false;
	ALLEGRO_BITMAP *image = NULL;
	ALLEGRO_SAMPLE *sound = NULL;
	int set_im = 0, set_music = 0;

int main()
{
	int i,j, read, count = 0;
	FILE *fmap;
	FILE *set;
	int create = 0;
	char c;
	int pos_x = wight / 2, pos_y = height / 2;
	int FPS = 100;
	int imageWight = 0, imageHeight = 0;

	
	if (!al_init() == -1)
		return -1;

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_SAMPLE_INSTANCE *songInstance = NULL;
	ALLEGRO_BITMAP *png = NULL, *emptyCell = NULL, *fullCell = NULL, *button = NULL;
	display = al_create_display(wight, height);
	

	if (!display == -1)
		return -1;
	// инициализация
	al_init_image_addon();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_acodec_addon();
	al_install_keyboard();
	al_install_mouse();
	al_install_audio();
	ALLEGRO_FONT *font36 = al_load_font("3.ttf",50, 0);
	ALLEGRO_FONT *font10 = al_load_font("1.ttf", 10, 0);

	al_reserve_samples(1);

	timer = al_create_timer(1.0 / FPS);
	event_queue = al_create_event_queue();
	png = al_load_bitmap("Resource/kub.png");
	button = al_load_bitmap("Resource/button3_300_60.png");

	// подключаем к очереди
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_start_timer(timer);

	// музыка	
	sound = al_load_sample("Resource/11.wav");
	songInstance = al_create_sample_instance(sound); 
	al_set_sample_instance_playmode(songInstance, ALLEGRO_PLAYMODE_LOOP); 
	al_attach_sample_instance_to_mixer(songInstance, al_get_default_mixer());


	readSetImage();
	readSetMusic(songInstance);

	ALLEGRO_EVENT ev;
	mainMenu = true;

	while (!user_exit) {

		al_wait_for_event(event_queue, &ev);

		if (mainMenu == true) {
			create_main_menu (image, button, &ev, event_queue);
			mainMenu = false;
		}

		if (buttonMenu[SETTING] == true)
		{
			create_setting_menu(&ev, event_queue, songInstance);
		}

		if (buttonMenu[LEVEL_MENU] == true)
		{
			create_level_menu (fmap, image, &ev, event_queue);
			buttonMenu[LEVEL_MENU] = false;
		}

		if (buttonMenu[GENERATE_MENU] == true)
		{
			create_generate_menu (image, &ev, event_queue);
			buttonMenu[GENERATE_MENU] = false;
		}

		if (buttonMenu[GENERATE_GAME] == true)
		{
			al_draw_bitmap(image, 0, 0, 0);
			generate = true;
			drawBitmapMainField(suppFieldX, suppFieldY, mainField, xMap, yMap, fullCell, emptyCell, font10);
			generate_game(image, &ev, event_queue);
			buttonMenu[GENERATE_GAME] = false;
			generate = false;
		}

		if (buttonMenu[PLAY_GAME] == true)
		{
			readLevel(currentLevel);
			al_draw_bitmap(image, 0, 0, 0);
			drawBitmapMainField(suppFieldX, suppFieldY, mainField, xMap, yMap, fullCell, emptyCell, font10);
			gamePlay(&ev, event_queue);
			buttonMenu[PLAY_GAME] = false;
		}

		if (buttonMenu[NEW_USER_MENU] == true){
			create_new_user_menu(image, &ev, event_queue);
			buttonMenu[NEW_USER_MENU] == false;
		}

		if (buttonMenu[LOAD_USER_MENU] == true){
			create_load_user_menu (image, &ev, event_queue);
			buttonMenu[LOAD_USER_MENU] = false;
		}

		if (buttonMenu[PLAY_MENU] == true)
		{
			create_play_menu (image, button, &ev, event_queue);
			buttonMenu[PLAY_MENU] = false;
		}
 
		if (buttonMenu[EXIT] == true)
		{
			user_exit = true;
		}
		

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) user_exit = true;

		if (redraw && al_is_event_queue_empty(event_queue))
		{
			redraw = false;

			al_flip_display();
		}

	}

	al_destroy_bitmap(image);
	al_destroy_font(font36);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
	al_destroy_sample(sound);
	al_destroy_sample_instance(songInstance);
	return 0;
}

