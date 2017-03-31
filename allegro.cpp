#include "header.h"

void create_setting_menu (ALLEGRO_EVENT *ev, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_SAMPLE_INSTANCE *songInstance)
{
	bool user_exit = false;
	ALLEGRO_BITMAP *mini0, *mini1, *mini2, *mini3, *mini4;
	ALLEGRO_BITMAP *backStr;
	ALLEGRO_FONT *font_menu;
	font_menu = al_load_font("japan.ttf", 35, 0);
	
	al_draw_bitmap(image, 0, 0, 0);
	mini0 = al_load_bitmap("Resource/set_background.png");
	mini1 = al_load_bitmap("Resource/set_background1.png");
	mini2 = al_load_bitmap("Resource/set_background2.png");
	mini3 = al_load_bitmap("Resource/set_background3.png");
	mini4 = al_load_bitmap("Resource/set_background4.png");
	backStr = al_load_bitmap("Resource/name_line.png");


	al_draw_bitmap(backStr, wight/2 - 165, 100, 0);
	al_draw_text(font_menu, al_map_rgb(43, 43, 43), wight / 2, 110,  ALLEGRO_ALIGN_CENTRE, "TAKE BACKGROUND");
	al_draw_bitmap(mini0, wight/2 - 475, 200, 0);
	al_draw_bitmap(mini1, wight/2 - 275, 200, 0);
	al_draw_bitmap(mini2, wight/2 - 75, 200, 0);
	al_draw_bitmap(mini3, wight/2 + 125, 200, 0);
	al_draw_bitmap(mini4, wight/2 + 325, 200, 0);

	al_draw_bitmap(backStr, wight/2 - 165, 350, 0);
	if (set_music == 0)
	al_draw_text(font_menu, al_map_rgb(43, 43, 43), wight / 2, 360,  ALLEGRO_ALIGN_CENTRE, "MUSIC: OFF");
	else
	al_draw_text(font_menu, al_map_rgb(43, 43, 43), wight / 2, 360,  ALLEGRO_ALIGN_CENTRE, "MUSIC: ON");

	al_draw_bitmap(backStr, wight/2 - 165, 420, 0);
	al_draw_text(font_menu, al_map_rgb(43, 43, 43), wight / 2, 430,  ALLEGRO_ALIGN_CENTRE, "BACK TO MAIN");

	al_flip_display();

	while (!user_exit) {
		al_wait_for_event(event_queue, ev);

	if (ev->type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			for (int im = 0; im < 12; im++)
			buttonMenu[im] = false;
			buttonMenu[EXIT] = true;
			user_exit = true;
	}

		if (ev->type == ALLEGRO_EVENT_KEY_UP){
			if (ev->keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				mainMenu = true;
				buttonMenu[SETTING] = false;
				user_exit = true;
			}
		}

		if (ev->type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
			if (ev->mouse.button & 1 && ev->mouse.x > wight/2 - 165 && 
				ev->mouse.y > 420 && ev->mouse.x < wight/2 + 165 && ev->mouse.y < 470){
					// back to main
				mainMenu = true;
				buttonMenu[SETTING] = false;
				user_exit = true;
			}
			
			if (ev->mouse.button & 1 && ev->mouse.x > wight/2 - 165 && 
				ev->mouse.y > 350 && ev->mouse.x < wight/2 + 165 && ev->mouse.y < 400){

				if (set_music == 0) {
					set_music = 1;
					changeSet();
					readSetMusic(songInstance);
					al_play_sample_instance(songInstance);
					
				}
				else {
					set_music = 0;
					changeSet();
					readSetMusic(songInstance);
					al_stop_sample_instance(songInstance);
				}

				buttonMenu[SETTING] = true;
				user_exit = true;
			}
			if (ev->mouse.button & 1 && ev->mouse.x > wight/2 - 475 && 
				ev->mouse.y > 200 && ev->mouse.x < wight/2 - 325 && ev->mouse.y < 285){
					// mini0
				image = al_load_bitmap("Resource/background.png");
				set_im = 0;
				changeSet();
				readSetImage();
				buttonMenu[SETTING] = true;
				user_exit = true;
			}

			if (ev->mouse.button & 1 && ev->mouse.x > wight/2 - 275 && 
				ev->mouse.y > 200 && ev->mouse.x < wight/2 - 125 && ev->mouse.y < 285){
					// mini1
				image = al_load_bitmap("Resource/background1.png");
				set_im = 1;
				changeSet();
				readSetImage();
				buttonMenu[SETTING] = true;
				user_exit = true;
			}

			if (ev->mouse.button & 1 && ev->mouse.x > wight/2 - 75 && 
				ev->mouse.y > 200 && ev->mouse.x < wight/2 + 75 && ev->mouse.y < 285){
					// mini2
				image = al_load_bitmap("Resource/background2.png");
				set_im = 2;
				changeSet();
				readSetImage();
				buttonMenu[SETTING] = true;
				user_exit = true;
			}

			if (ev->mouse.button & 1 && ev->mouse.x > wight/2 + 125 && 
				ev->mouse.y > 200 && ev->mouse.x < wight/2 +275 && ev->mouse.y < 285){
					// mini3
				image = al_load_bitmap("Resource/background3.png");
				set_im = 3;
				changeSet();
				readSetImage();
				buttonMenu[SETTING] = true;
				user_exit = true;
			}

			if (ev->mouse.button & 1 && ev->mouse.x > wight/2 + 325 && 
				ev->mouse.y > 200 && ev->mouse.x < wight/2 + 475 && ev->mouse.y < 285){
					// mini4
				image = al_load_bitmap("Resource/background4.png");
				set_im = 4;
				changeSet();
				readSetImage();
				buttonMenu[SETTING] = true;
				user_exit = true;
			}

		}



	}
}

void create_generate_menu(ALLEGRO_BITMAP *image, ALLEGRO_EVENT *ev, ALLEGRO_EVENT_QUEUE *event_queue)
{
	generate = true;
	nullSuppField();
	nullMainField(mainField);
	char user_name_1[10];
	strcpy(user_name_1, user_name);
	xMap = 0; 
	yMap = 0;
	ALLEGRO_BITMAP *input_line, *user_name_field;
	ALLEGRO_BITMAP *back_namescan;
	ALLEGRO_BITMAP *button = al_load_bitmap("Resource/name_line.png");
	bool user_exit = false;
	input_line = al_load_bitmap("Resource/input_line.png");
	back_namescan = al_load_bitmap("Resource/back_to_namescan.png");
	char x[2], y[2];
	al_draw_bitmap(image, 0, 0, 0);

	ALLEGRO_FONT *font_nick;
	user_name_field = al_load_bitmap("Resource/user_name_field.png");
	font_nick = al_load_font("japan.ttf", 15, 0);

	al_draw_bitmap(image, 0, 0, 0);
	al_draw_bitmap(user_name_field, 0, 0, 0);
	al_draw_textf(font_nick, al_map_rgb(43, 43, 43), 75, 3, ALLEGRO_ALIGN_CENTRE, "%s LV. %d", user_name, user_lvl);


	ALLEGRO_FONT *font_menu;
	font_menu = al_load_font("japan.ttf", 35, 0);

	al_draw_bitmap(back_namescan, wight/2 - 220, height/2 - 80, 0);
	al_draw_bitmap(input_line, wight/2 - 165, height/2 - 25, 0);
	al_draw_bitmap(input_line, wight/2 + 15, height/2 - 25, 0);
	al_draw_text(font_menu, al_map_rgb(43,43,43), wight/2, height/2 - 65, ALLEGRO_ALIGN_CENTRE, "MAP X:        MAP Y:");
//	al_draw_bitmap(button, wight / 2 - 165, 350, 0);
//	al_draw_text(font_menu, al_map_rgb(43,43,43), wight/2, 360, ALLEGRO_ALIGN_CENTRE, "GENERATE MAP");
	al_flip_display();
	
	while (!user_exit) {
		al_wait_for_event(event_queue, ev);
	
		if (ev->type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			for (int im = 0; im < 12; im++)
			buttonMenu[im] = false;
			buttonMenu[EXIT] = true;
			user_exit = true;
		}

		if (ev->type == ALLEGRO_EVENT_KEY_UP){
			if (ev->keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				buttonMenu[PLAY_MENU] = true;
				buttonMenu[GENERATE_MENU] = false;
				user_exit = true;
			}
		}


		if (ev->type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
			if (ev->mouse.button & 1 && ev->mouse.x > wight/2 - 165 && 
				ev->mouse.y > height/2 - 25 && ev->mouse.x < wight/2 - 15 && ev->mouse.y < height/2 + 25){
				scanf_text(x, input_line, font_menu, wight/2 - 165, height/2 - 25, 2, ev, event_queue);
				if ((x[0] == '0' || x[0] == '1' || x[0] == '2' || x[0] == '3' || x[0] == '4' 
					|| x[0] == '5' || x[0] == '6' || x[0] == '7' || x[0] == '8' || x[0] == '9') && 
					(x[1] == '0' || x[1] == '1' || x[1] == '2' || x[1] == '3' || x[1] == '4' 
					|| x[1] == '5' || x[1] == '6' || x[1] == '7' || x[1] == '8' || x[1] == '9' || x[1] == '\0')) 
					sscanf(x, "%d", &xMap);
				else {
					al_draw_bitmap(input_line, wight/2 - 165, height/2 - 25, 0);
					al_draw_tinted_bitmap(input_line, al_map_rgba(255, 0, 0, 0.2), wight/2 - 165, height/2 - 25, 0);
					al_flip_display();
					xMap = 0;
					user_exit = false;
				}
				if (xMap>60) { 
					al_draw_bitmap(input_line, wight/2 - 165, height/2 - 25, 0);
					al_draw_tinted_bitmap(input_line, al_map_rgba(255, 0, 0, 0.2), wight/2 - 165, height/2 - 25, 0);
					al_flip_display();
					xMap = 0;
					user_exit = false;
				}
			}

			if (ev->mouse.button & 1 && ev->mouse.x > wight/2 + 15 && 
				ev->mouse.y > height/2 - 25 && ev->mouse.x < wight/2 + 165 && ev->mouse.y < height/2 + 25){
				scanf_text(y, input_line, font_menu, wight/2 + 15, height/2 - 25, 2, ev, event_queue);
				if ((y[0] == '0' || y[0] == '1' || y[0] == '2' || y[0] == '3' || y[0] == '4' 
					|| y[0] == '5' || y[0] == '6' || y[0] == '7' || y[0] == '8' || y[0] == '9') && 
					(y[1] == '0' || y[1] == '1' || y[1] == '2' || y[1] == '3' || y[1] == '4' 
					|| y[1] == '5' || y[1] == '6' || y[1] == '7' || y[1] == '8' || y[1] == '9' || y[1] == '\0')) 
					sscanf(y, "%d", &yMap);
				else {
					al_draw_bitmap(input_line, wight/2 + 15, height/2 - 25, 0);
					al_draw_tinted_bitmap(input_line, al_map_rgba(255, 0, 0, 0.2), wight/2 + 15, height/2 - 25, 0);
					al_flip_display();
					yMap = 0;
					user_exit = false;
				}
				if (yMap>40) { 
					al_draw_bitmap(input_line, wight/2 + 15, height/2 - 25, 0);
					al_draw_tinted_bitmap(input_line, al_map_rgba(255, 0, 0, 0.2), wight/2 + 15, height/2 - 25, 0);
					al_flip_display();
					yMap = 0;
					user_exit = false;
				}
			}


		}

		if (xMap != 0 && yMap != 0) {
				buttonMenu[PLAY_MENU] = false;
				buttonMenu[GENERATE_MENU] = false;
				buttonMenu[GENERATE_GAME] = true;
				user_exit = true;
		}

	}
	strcpy(user_name, user_name_1);
	generate = false;
}


void generate_game(ALLEGRO_BITMAP *image, ALLEGRO_EVENT *ev, ALLEGRO_EVENT_QUEUE *event_queue){
	nullSuppField();
	bool done = false;
	ALLEGRO_BITMAP *fullCell, *emptyCell, *emptyCellClic0, *emptyDecideCell;
	ALLEGRO_BITMAP *emptyDecideCellClic0, *fullCellClic0, *crossedCell;
	al_init_font_addon();
	al_init_ttf_addon();
	ALLEGRO_FONT *font = al_load_font("arial.ttf", scale-2, 0);
	ALLEGRO_FONT *font_menu = al_load_font("japan.ttf", 30, 0);
	int i = 0, j = 0;
	ALLEGRO_BITMAP *user_name_field;
	ALLEGRO_BITMAP *button = al_load_bitmap("Resource/user_button.png");
	ALLEGRO_BITMAP *button_bw = al_load_bitmap("Resource/user_button_bw.png");
	ALLEGRO_FONT *font_nick;
	user_name_field = al_load_bitmap("Resource/user_name_field.png");
	font_nick = al_load_font("japan.ttf", 15, 0);

	generate = true;

	bool user_exit = false;
	bool draw_flag = false;
	switch (scale) {
		case 10:
			emptyCell = al_load_bitmap("Resource/empty_cell_10.png");
			emptyCellClic0 = al_load_bitmap("Resource/empty_cell_10_clic0.png");
			fullCell = al_load_bitmap("Resource/full_cell_10.png");
			emptyDecideCell = al_load_bitmap("Resource/empty_decide_cell_10.png");
			emptyDecideCellClic0 = al_load_bitmap("Resource/empty_decide_cell_10_clic0.png");
			fullCellClic0 = al_load_bitmap("Resource/full_cell_10_clic0.png");
			crossedCell = al_load_bitmap("Resource/crossed_cell_10.png");
		break;
		case 12:
			emptyCell = al_load_bitmap("Resource/empty_cell_12.png");
			emptyCellClic0 = al_load_bitmap("Resource/empty_cell_12_clic0.png");
			fullCell = al_load_bitmap("Resource/full_cell_12.png");
			emptyDecideCell = al_load_bitmap("Resource/empty_decide_cell_12.png");
			emptyDecideCellClic0 = al_load_bitmap("Resource/empty_decide_cell_12_clic0.png");
			fullCellClic0 = al_load_bitmap("Resource/full_cell_12_clic0.png");
			crossedCell = al_load_bitmap("Resource/crossed_cell_12.png");
		break;
		case 15:
			emptyCell = al_load_bitmap("Resource/empty_cell_15.png");
			emptyCellClic0 = al_load_bitmap("Resource/empty_cell_15_clic0.png");
			fullCell = al_load_bitmap("Resource/full_cell_15.png");
			emptyDecideCell = al_load_bitmap("Resource/empty_decide_cell_15.png");
			emptyDecideCellClic0 = al_load_bitmap("Resource/empty_decide_cell_15_clic0.png");
			fullCellClic0 = al_load_bitmap("Resource/full_cell_15_clic0.png");
			crossedCell = al_load_bitmap("Resource/crossed_cell_15.png");
		break;
		case 20:
			emptyCell = al_load_bitmap("Resource/empty_cell_20.png");
			emptyCellClic0 = al_load_bitmap("Resource/empty_cell_20_clic0.png");
			fullCell = al_load_bitmap("Resource/full_cell_20.png");
			emptyDecideCell = al_load_bitmap("Resource/empty_decide_cell_20.png");
			emptyDecideCellClic0 = al_load_bitmap("Resource/empty_decide_cell_20_clic0.png");
			fullCellClic0 = al_load_bitmap("Resource/full_cell_20_clic0.png");
			crossedCell = al_load_bitmap("Resource/crossed_cell_20.png");
		break;
	}

	int mouseSuppXPosX = 0, mouseSuppXPosY = 0, mouseSuppYPosX = 0, mouseSuppYPosY = 0; 
	int prevPosX = 0, prevPosY = 0;
	int prevCoordX = 0, prevCoordY = 0;

	while (!user_exit)
	{

		al_wait_for_event(event_queue, ev);
		
		if (ev->type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			for (int im = 0; im < 12; im++)
			buttonMenu[im] = false;
			buttonMenu[EXIT] = true;
			user_exit = true;
		}

		if (ev->type == ALLEGRO_EVENT_KEY_UP){
			if (ev->keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
					// button exit
					buttonMenu[PLAY_MENU] = true;
					buttonMenu[PLAY_GAME] = false;
					buttonMenu[GENERATE_GAME] = false;
					xMap = 0;
					yMap = 0;
					user_exit = true;
					generate = false;
			}
		}


		if (ev->type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
			if (ev->mouse.button == 1 && ev->mouse.x > 0 && ev->mouse.x < 150 && 
				ev->mouse.y > 30 && ev->mouse.y < 50 && done == false) {
					generateSupField (suppFieldX, suppFieldY, mainField, xMap, yMap);
					generate = true;
					done = true;
					al_draw_bitmap(image, 0,0,0);
					al_flip_display();
					drawBitmapMainField(suppFieldX, suppFieldY, mainField, xMap, yMap, fullCell, emptyCell, font);

			}
			if (ev->mouse.button == 1 && ev->mouse.x > 0 && ev->mouse.x < 150 && 
				ev->mouse.y > 55 && ev->mouse.y < 75) {
					// button exit
					buttonMenu[PLAY_MENU] = true;
					buttonMenu[PLAY_GAME] = false;
					buttonMenu[GENERATE_GAME] = false;
					xMap = 0;
					yMap = 0;
					user_exit = true;
					generate = false;
			}
		}


		if (ev->type == ALLEGRO_EVENT_KEY_UP && done == false){
			if (ev->keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
					user_exit = true;
					buttonMenu[PLAY_MENU] = true;
					buttonMenu[PLAY_GAME] = false;
					buttonMenu[GENERATE_GAME] = false;
					xMap = 0;
					yMap = 0;
					generate = false;
				}
			}
		

		if (scale != 0 && ev->mouse.x >= nullX && ev->mouse.x < nullX+xMap*scale 
			&& ev->mouse.y >= nullY && ev->mouse.y < nullY+yMap*scale && done == false) {
			mousePosX = (ev->mouse.x - nullX)/scale;
			mousePosY = (ev->mouse.y - nullY)/scale;


			if (ev->type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
				if (ev->mouse.button == 1) {
					if (mainField[mousePosY][mousePosX] == 0 || mainField[mousePosY][mousePosX] == 5) al_draw_bitmap(fullCell, nullX + mousePosX*scale, nullY+mousePosY*scale, 0);
					else if (mainField[mousePosY][mousePosX] == 1) al_draw_bitmap(emptyCell, nullX + mousePosX*scale, nullY+mousePosY*scale, 0);
					al_flip_display();
					draw_flag = true;
					if (mainField[mousePosY][mousePosX] == 0 || mainField[mousePosY][mousePosX] == 5) mainField[mousePosY][mousePosX] = 1;
					else if (mainField[mousePosY][mousePosX] == 1) mainField[mousePosY][mousePosX] = 0;
					//printMainField(mainField, xMap, yMap);
				}
				if (ev->mouse.button == 2) {
					if (mainField[mousePosY][mousePosX] == 0 || mainField[mousePosY][mousePosX] == 1) al_draw_bitmap(emptyDecideCell, nullX + mousePosX*scale, nullY+mousePosY*scale, 0);
					else if (mainField[mousePosY][mousePosX] == 5) al_draw_bitmap(emptyCell, nullX + mousePosX*scale, nullY+mousePosY*scale, 0);
					al_flip_display();
					draw_flag = true;
					if (mainField[mousePosY][mousePosX] == 0 || mainField[mousePosY][mousePosX] == 1) mainField[mousePosY][mousePosX] = 5;
					else if (mainField[mousePosY][mousePosX] == 5) mainField[mousePosY][mousePosX] = 0;
					//printMainField(mainField, xMap, yMap);
				}
			} 



			if ((prevMousePosX != mousePosX || prevMousePosY != mousePosY) 
				/*&& mousePosX >= 0 && mousePosY >= 0 && mousePosX < xMap && mousePosY < yMap*/)
			{	
 				if (mainField[mousePosY][mousePosX] == 0) al_draw_bitmap(emptyCellClic0, nullX + mousePosX*scale, nullY+mousePosY*scale, 0);
 				if (mainField[mousePosY][mousePosX] == 1) al_draw_bitmap(fullCellClic0, nullX + mousePosX*scale, nullY+mousePosY*scale, 0);
 				if (mainField[mousePosY][mousePosX] == 5) al_draw_bitmap(emptyDecideCellClic0, nullX + mousePosX*scale, nullY+mousePosY*scale, 0);
				al_flip_display();
				//draw_flag = false;
				//printf("+");
			}
			if ((prevMousePosX != mousePosX || prevMousePosY != mousePosY)  
			&& prevMousePosX >= 0 && prevMousePosY >= 0 && prevMousePosX < xMap && prevMousePosY < yMap) 
			{
				if (draw_flag == true){
					draw_flag = false;
				} else {
					if (mainField[prevMousePosY][prevMousePosX] == 0) al_draw_bitmap(emptyCell, nullX + prevMousePosX*scale, nullY+prevMousePosY*scale, 0);
					if (mainField[prevMousePosY][prevMousePosX] == 1) al_draw_bitmap(fullCell, nullX + prevMousePosX*scale, nullY+prevMousePosY*scale, 0);
					if (mainField[prevMousePosY][prevMousePosX] == 5) al_draw_bitmap(emptyDecideCell, nullX + prevMousePosX*scale, nullY+prevMousePosY*scale, 0);
					al_flip_display();
				}
			}
			prevMousePosX = mousePosX;
			prevMousePosY = mousePosY;
			
		}
	
	}			
	generate = false;
}

void draw_animation()
{
	int i = 0, j = 0;
	ALLEGRO_BITMAP *fullCell, *emptyCell, *emptyCellClic0, *emptyDecideCell;
	ALLEGRO_BITMAP *emptyDecideCellClic0, *fullCellClic0, *crossedCell;

	switch (scale) {
		case 10:
			emptyCell = al_load_bitmap("Resource/empty_cell_10.png");
			emptyCellClic0 = al_load_bitmap("Resource/empty_cell_10_clic0.png");
			fullCell = al_load_bitmap("Resource/full_cell_10.png");
			emptyDecideCell = al_load_bitmap("Resource/empty_decide_cell_10.png");
			emptyDecideCellClic0 = al_load_bitmap("Resource/empty_decide_cell_10_clic0.png");
			fullCellClic0 = al_load_bitmap("Resource/full_cell_10_clic0.png");
			crossedCell = al_load_bitmap("Resource/crossed_cell_10.png");
		break;
		case 12:
			emptyCell = al_load_bitmap("Resource/empty_cell_12.png");
			emptyCellClic0 = al_load_bitmap("Resource/empty_cell_12_clic0.png");
			fullCell = al_load_bitmap("Resource/full_cell_12.png");
			emptyDecideCell = al_load_bitmap("Resource/empty_decide_cell_12.png");
			emptyDecideCellClic0 = al_load_bitmap("Resource/empty_decide_cell_12_clic0.png");
			fullCellClic0 = al_load_bitmap("Resource/full_cell_12_clic0.png");
			crossedCell = al_load_bitmap("Resource/crossed_cell_12.png");
		break;
		case 15:
			emptyCell = al_load_bitmap("Resource/empty_cell_15.png");
			emptyCellClic0 = al_load_bitmap("Resource/empty_cell_15_clic0.png");
			fullCell = al_load_bitmap("Resource/full_cell_15.png");
			emptyDecideCell = al_load_bitmap("Resource/empty_decide_cell_15.png");
			emptyDecideCellClic0 = al_load_bitmap("Resource/empty_decide_cell_15_clic0.png");
			fullCellClic0 = al_load_bitmap("Resource/full_cell_15_clic0.png");
			crossedCell = al_load_bitmap("Resource/crossed_cell_15.png");
		break;
		case 20:
			emptyCell = al_load_bitmap("Resource/empty_cell_20.png");
			emptyCellClic0 = al_load_bitmap("Resource/empty_cell_20_clic0.png");
			fullCell = al_load_bitmap("Resource/full_cell_20.png");
			emptyDecideCell = al_load_bitmap("Resource/empty_decide_cell_20.png");
			emptyDecideCellClic0 = al_load_bitmap("Resource/empty_decide_cell_20_clic0.png");
			fullCellClic0 = al_load_bitmap("Resource/full_cell_20_clic0.png");
			crossedCell = al_load_bitmap("Resource/crossed_cell_20.png");
		break;
	}


	for (i = 0; i < xMap*scale; i=i+scale){
		for (j = 0; j < yMap*scale; j = j + scale){
			if (mainField[j/scale][i/scale] == 0) al_draw_bitmap(emptyCell, nullX + i, nullY + j, 0);
			if (mainField[j/scale][i/scale] == 1) al_draw_bitmap(fullCellClic0, nullX + i, nullY + j, 0);
			if (mainField[j/scale][i/scale] == 5) al_draw_bitmap(emptyDecideCellClic0, nullX + i, nullY + j, 0);
		}
	}

	al_flip_display();

	if (empty(mainField, xMap, yMap) == 1){
		for (i = 0; i < xMap*scale; i=i+scale){
			for (j = 0; j < yMap*scale; j = j + scale){
				if (mainField[j/scale][i/scale] == 0) al_draw_bitmap(emptyCell, nullX + i, nullY + j, 0);
				if (mainField[j/scale][i/scale] == 1) al_draw_bitmap(fullCell, nullX + i, nullY + j, 0);
				if (mainField[j/scale][i/scale] == 5) al_draw_bitmap(emptyDecideCell, nullX + i, nullY + j, 0);
			}
		}
	}

	al_flip_display();
}

void animation_decide(float time)
{
	
		prevToMain();
		checkPoint_100(suppFieldX, suppFieldY, mainField, xMap, yMap);
		if (check_to_changes() == 1) {
			draw_animation();
			al_rest(time);
		}

		prevToMain();
		drawEdgeField(suppFieldX, suppFieldY, mainField, xMap, yMap);
		if (check_to_changes() == 1) {
			draw_animation();
			al_rest(time);
		}

		prevToMain();
		checkFromEdgeField(suppFieldX, suppFieldY, mainField, xMap, yMap);
		if (check_to_changes() == 1) {
			draw_animation();
			al_rest(time);
		}

		prevToMain();
		checkEmptyFields(suppFieldX, suppFieldY, mainField, xMap, yMap);
		if (check_to_changes() == 1) {
			draw_animation();
			al_rest(time);
		}

		prevToMain();
		checkPoint_elements(suppFieldX, suppFieldY, mainField, xMap, yMap);
		if (check_to_changes() == 1) {
			draw_animation();
			al_rest(time);
		}

		prevToMain();
		drawByEmptyCells (suppFieldX, suppFieldY, mainField, xMap, yMap);
		if (check_to_changes() == 1) {
			draw_animation();
			al_rest(time);
		}

		prevToMain();
		drawCheckEdgeField (suppFieldX, suppFieldY, mainField, xMap, yMap);
		if (check_to_changes() == 1) {
			draw_animation();
			al_rest(time);
		}

}

void create_load_user_menu (ALLEGRO_BITMAP *image, ALLEGRO_EVENT *ev, ALLEGRO_EVENT_QUEUE *event_queue)
{
	ALLEGRO_BITMAP *name_line;
	ALLEGRO_BITMAP *back_namescan;
	bool user_exit = false;
	name_line = al_load_bitmap("Resource/name_line.png");
	back_namescan = al_load_bitmap("Resource/back_to_namescan.png");

	ALLEGRO_FONT *font_menu;
	font_menu = al_load_font("japan.ttf", 35, 0);


	al_draw_bitmap(image, 0, 0, 0);
	al_draw_bitmap(back_namescan, wight/2 - 220, height/2 - 80, 0);
	al_draw_bitmap(name_line, wight/2 - 165, height/2 - 25, 0);
	al_draw_text(font_menu, al_map_rgb(43,43,43), wight/2, height/2 - 65, ALLEGRO_ALIGN_CENTRE, "LOAD NICKNAME:");
	al_flip_display();
	
	while (!user_exit) {
		al_wait_for_event(event_queue, ev);

	if (ev->type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			for (int im = 0; im < 12; im++)
			buttonMenu[im] = false;
			buttonMenu[EXIT] = true;
			user_exit = true;
	}

	if (ev->type == ALLEGRO_EVENT_KEY_UP){
			if (ev->keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				mainMenu = true;
				user_exit = true;
				buttonMenu[PLAY_MENU] = false;
				buttonMenu[LOAD_USER_MENU] = false;
				strcpy(user_name, "\0");
				user_lvl = 0;
			}
		}


		if (ev->type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
			if (ev->mouse.button & 1 && ev->mouse.x > wight/2 - 165 && 
				ev->mouse.y > height/2 - 25 && ev->mouse.x < wight/2 + 165 && ev->mouse.y < height/2 + 25){
				scanf_text(user_name, name_line, font_menu, wight/2 - 165, height/2 - 25, 10, ev, event_queue);
				if (search_user_file() == 1) {
					user_exit = true;
					buttonMenu[PLAY_MENU] = true;
				}
				else {
					al_draw_bitmap(name_line, wight/2 - 165, height/2 - 25, 0);
					al_draw_tinted_bitmap(name_line, al_map_rgba(255, 0, 0, 0.2), wight/2 - 165, height/2 - 25, 0);
					al_flip_display();
					strcpy(user_name, "\0");
					user_exit = false;
				}
			}
		}
	}


}

void create_new_user_menu (ALLEGRO_BITMAP *image, ALLEGRO_EVENT *ev, ALLEGRO_EVENT_QUEUE *event_queue)
{
	ALLEGRO_BITMAP *name_line;
	ALLEGRO_BITMAP *back_namescan;
	bool user_exit = false;
	name_line = al_load_bitmap("Resource/name_line.png");
	back_namescan = al_load_bitmap("Resource/back_to_namescan.png");

	ALLEGRO_FONT *font_menu;
	font_menu = al_load_font("japan.ttf", 35, 0);


	al_draw_bitmap(image, 0, 0, 0);
	al_draw_bitmap(back_namescan, wight/2 - 220, height/2 - 80, 0);
	al_draw_bitmap(name_line, wight/2 - 165, height/2 - 25, 0);
	al_draw_text(font_menu, al_map_rgb(43,43,43), wight/2, height/2 - 65, ALLEGRO_ALIGN_CENTRE, "NEW NICKNAME:");
	al_flip_display();
	
	while (!user_exit) {
		al_wait_for_event(event_queue, ev);

	if (ev->type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			for (int im = 0; im < 12; im++)
			buttonMenu[im] = false;
			buttonMenu[EXIT] = true;
			user_exit = true;
	}

	if (ev->type == ALLEGRO_EVENT_KEY_UP){
			if (ev->keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				mainMenu = true;
				user_exit = true;
				buttonMenu[PLAY_MENU] = false;
				buttonMenu[NEW_USER_MENU] = false;
				strcpy(user_name, "\0");
				user_lvl = 0;
			}
		}

		if (ev->type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
			if (ev->mouse.button & 1 && ev->mouse.x > wight/2 - 165 && 
				ev->mouse.y > height/2 - 25 && ev->mouse.x < wight/2 + 165 && ev->mouse.y < height/2 + 25){
				scanf_text(user_name, name_line, font_menu, wight/2 - 165, height/2 - 25, 10, ev, event_queue);
				if (search_user_file() == 0) {
					user_exit = true;
					user_lvl = 1;
					create_new_user();
					buttonMenu[PLAY_MENU] = true;
					buttonMenu[NEW_USER_MENU] = false;
				}
				else {
					al_draw_bitmap(name_line, wight/2 - 165, height/2 - 25, 0);
					al_draw_tinted_bitmap(name_line, al_map_rgba(255, 0, 0, 0.2), wight/2 - 165, height/2 - 25, 0);
					al_flip_display();
					strcpy(user_name, "\0");
					user_exit = false;
				}
			}
		}
	}

}

void scanf_text (char buffer[512], ALLEGRO_BITMAP *background, ALLEGRO_FONT *font, int X, int Y, int SizeText, ALLEGRO_EVENT *ev, ALLEGRO_EVENT_QUEUE *event_queue)
{
	int bufptr = 0, quit = 0;
	char key;
	int count = 0;
	bool user_exit = false;
	strcpy(user_name, "\0");
	strcpy(buffer, "\0");

	al_draw_bitmap(background, X, Y, 0);
	al_draw_tinted_bitmap(background, al_map_rgba(0, 207, 149, 0.9), X, Y, 0);
	al_flip_display();

	ALLEGRO_EVENT ev1;
	 	 
	while(!quit)
	   {
		user_exit = false;
		key = readkey(ev, event_queue, X, Y, background);
		  if (key != NULL && count < SizeText && key != '[' && key != ']') {
			  buffer[count] = key;
			  count++;
			  buffer[count] = '\0';
		  }
		  if (key == ']') {
			  count--;
			  buffer[count] = '\0';
			  key = NULL;
		  }
		  if (key == '[') {
			  quit = 1;
			  key = NULL;
			  buffer[count] = '\0';
		  }

		  al_draw_bitmap(background, X, Y, 0);
		  al_draw_tinted_bitmap(background, al_map_rgba(0, 207, 149, 0.9), X, Y, 0);
		  al_draw_textf(font, al_map_rgb(43, 43, 43), X + al_get_bitmap_width(background) / 2, Y + al_get_bitmap_height(background) / 5, ALLEGRO_ALIGN_CENTRE, "%s", buffer);
		  al_flip_display();
		  key = NULL;

		  if (buffer[0] == NULL) quit = 0;
    	 }
	  al_draw_bitmap(background, X, Y, 0);
	  al_draw_textf(font, al_map_rgb(43, 43, 43), X + al_get_bitmap_width(background) / 2, Y + al_get_bitmap_height(background) / 5, ALLEGRO_ALIGN_CENTRE, "%s", buffer);
	  al_flip_display();
}

void create_level_menu (FILE *fmap, ALLEGRO_BITMAP *image, ALLEGRO_EVENT *ev, ALLEGRO_EVENT_QUEUE *event_queue)
{

	ALLEGRO_FONT *font_menu;
	ALLEGRO_BITMAP *button;
	ALLEGRO_BITMAP *button_bw;
	int i = 0, j = 0;
	int numberLevel = 0;
	bool user_exit = false;
	char user_name_1[10];
	strcpy(user_name_1, user_name);

	font_menu = al_load_font("japan.ttf", 25, 0);
	button = al_load_bitmap("Resource/level_button.png");
	button_bw = al_load_bitmap("Resource/level_button_bw.png");
	ALLEGRO_BITMAP *user_name_field;
	ALLEGRO_FONT *font_nick;
	user_name_field = al_load_bitmap("Resource/user_name_field.png");
	font_nick = al_load_font("japan.ttf", 15, 0);

	al_draw_bitmap(image, 0, 0, 0);
	al_draw_bitmap(user_name_field, 0, 0, 0);
	al_draw_textf(font_nick, al_map_rgb(43, 43, 43), 75, 3, ALLEGRO_ALIGN_CENTRE, "%s LV. %d", user_name, user_lvl);

	for (i = 40; i < 900; i = i + 200){
		for (j = 40; j < 500; j = j + 50){
			numberLevel++;
			printf("%d ", numberLevel);
			if (numberLevel <= user_lvl) {
				al_draw_bitmap(button, i, j, 0);
				buttonStruct.x[numberLevel] = i;
				buttonStruct.y[numberLevel] = j;
				buttonStruct.number[numberLevel] = numberLevel;
			} else {
				al_draw_bitmap(button_bw, i, j, 0);				
				buttonStruct.x[numberLevel] = i;
				buttonStruct.y[numberLevel] = j;
				buttonStruct.number[numberLevel] = numberLevel;
			}
			
				al_draw_textf(font_menu, al_map_rgb(43, 43, 43), i + 75, j + 10, ALLEGRO_ALIGN_CENTRE, "LEVEL %d", numberLevel);
		}
	}
	al_flip_display();
	strcpy(user_name, user_name_1);

	while (!user_exit) {
		al_wait_for_event(event_queue, ev);

		if (ev->type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			for (int im = 0; im < 12; im++)
			buttonMenu[im] = false;
			buttonMenu[EXIT] = true;
			user_exit = true;
		}

		if (ev->type == ALLEGRO_EVENT_KEY_UP){
			if (ev->keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				buttonMenu[PLAY_MENU] = true;
				buttonMenu[LEVEL_MENU] = false;
				user_exit = true;
			}
		}

		if (ev->type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
			if (ev->mouse.button & 1){
				for (i = 1; i <= 50; i++){
					if (ev->mouse.x > buttonStruct.x[i] && ev->mouse.x < buttonStruct.x[i] + 150 
						&& ev->mouse.y > buttonStruct.y[i] && ev->mouse.y < buttonStruct.y[i] + 40){
							if (user_lvl >= i) {
								buttonMenu[PLAY_GAME] = true;
								buttonMenu[PLAY_MENU] = false;
								
								//printf("%d %s \n", buttonStruct.number[i], user_name);
								currentLevel = buttonStruct.number[i];
								if (i == 50) currentLevel = 50;
								user_exit = true;
								break;
							}
					}
				}
			}
		}



	}
}
void create_play_menu (ALLEGRO_BITMAP *image, ALLEGRO_BITMAP *button, ALLEGRO_EVENT *ev, ALLEGRO_EVENT_QUEUE *event_queue)
{
	ALLEGRO_FONT *font_menu;
	font_menu = al_load_font("japan.ttf", 30, 0);
	bool user_exit = false;

	ALLEGRO_BITMAP *user_name_field;
	ALLEGRO_FONT *font_nick;
	user_name_field = al_load_bitmap("Resource/user_name_field.png");
	font_nick = al_load_font("japan.ttf", 15, 0);

	al_draw_bitmap(image, 0, 0, 0);
	al_draw_bitmap(user_name_field, 0, 0, 0);
	al_draw_textf(font_nick, al_map_rgb(43, 43, 43), 75, 3, ALLEGRO_ALIGN_CENTRE, "%s LV. %d", user_name, user_lvl);
	
	al_draw_bitmap(button, wight / 2 - 150, 170, 3);
	al_draw_text(font_menu, al_map_rgb(43, 43, 43), wight / 2, 190, ALLEGRO_ALIGN_CENTRE, "PLAY GAME");
	al_draw_bitmap(button, wight / 2 - 150, 230, 3);
	al_draw_text(font_menu, al_map_rgb(43, 43, 43), wight / 2, 250, ALLEGRO_ALIGN_CENTRE, "GENERATE IT...");
//	al_draw_bitmap(button, wight / 2 - 150, 290, 3);
//	al_draw_text(font_menu, al_map_rgb(43, 43, 43), wight / 2, 310, ALLEGRO_ALIGN_CENTRE, "DECIDE IT...");
	al_draw_bitmap(button, wight / 2 - 150, 290, 3);
	al_draw_text(font_menu, al_map_rgb(43, 43, 43), wight / 2, 310, ALLEGRO_ALIGN_CENTRE, "BACK TO MAIN");
	al_flip_display();

	while (!user_exit) {
		al_wait_for_event(event_queue, ev);

		if (ev->type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			for (int im = 0; im < 12; im++)
			buttonMenu[im] = false;
			buttonMenu[EXIT] = true;
			user_exit = true;
		}

		if (ev->type == ALLEGRO_EVENT_KEY_UP){
			if (ev->keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				mainMenu = true;
				user_exit = true;
				buttonMenu[PLAY_MENU] = false;
				buttonMenu[NEW_USER_MENU] = false;
				buttonMenu[LOAD_USER_MENU] = false;
			}
		}

		if (ev->type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
			if (ev->mouse.button & 1 && ev->mouse.x > wight/2 - 150 && 
				ev->mouse.y > 170 && ev->mouse.x < wight/2 + 150 && ev->mouse.y < 230){
				buttonMenu[LEVEL_MENU] = true; // кнопка плей гейм
				buttonMenu[PLAY_MENU] = false;
				user_exit = true;
			}
			if (ev->mouse.button & 1 && ev->mouse.x > wight/2 - 150 && 
				ev->mouse.y > 230 && ev->mouse.x < wight/2 + 150 && ev->mouse.y < 290){
				buttonMenu[GENERATE_MENU] = true; // generate menu
				buttonMenu[PLAY_MENU] = false;
				user_exit = true;
			}

			if (ev->mouse.button & 1 && ev->mouse.x > wight/2 - 150 && 
				ev->mouse.y > 290 && ev->mouse.x < wight/2 + 150 && ev->mouse.y < 350){
				strcpy(user_name, "/0");
				user_lvl = 0;
				mainMenu = true;
				user_exit = true;
				buttonMenu[PLAY_MENU] = false;
				buttonMenu[NEW_USER_MENU] = false;
				buttonMenu[LOAD_USER_MENU] = false;
			}
		}
	}
}

void gamePlay(ALLEGRO_EVENT *ev, ALLEGRO_EVENT_QUEUE *event_queue)
{
	ALLEGRO_BITMAP *fullCell, *emptyCell, *emptyCellClic0, *emptyDecideCell;
	ALLEGRO_BITMAP *emptyDecideCellClic0, *fullCellClic0, *crossedCell;
	al_init_font_addon();
	al_init_ttf_addon();
	ALLEGRO_FONT *font = al_load_font("arial.ttf", scale-2, 0);
	ALLEGRO_FONT *font_menu = al_load_font("japan.ttf", 30, 0);
	ALLEGRO_FONT *font_to_win = al_load_font("japan.ttf", 30, 0);

	int i = 0, j = 0;
	float g = 0.0;

	bool user_exit = false;
	bool draw_flag = false;
	switch (scale) {
		case 10:
			emptyCell = al_load_bitmap("Resource/empty_cell_10.png");
			emptyCellClic0 = al_load_bitmap("Resource/empty_cell_10_clic0.png");
			fullCell = al_load_bitmap("Resource/full_cell_10.png");
			emptyDecideCell = al_load_bitmap("Resource/empty_decide_cell_10.png");
			emptyDecideCellClic0 = al_load_bitmap("Resource/empty_decide_cell_10_clic0.png");
			fullCellClic0 = al_load_bitmap("Resource/full_cell_10_clic0.png");
			crossedCell = al_load_bitmap("Resource/crossed_cell_10.png");
		break;
		case 12:
			emptyCell = al_load_bitmap("Resource/empty_cell_12.png");
			emptyCellClic0 = al_load_bitmap("Resource/empty_cell_12_clic0.png");
			fullCell = al_load_bitmap("Resource/full_cell_12.png");
			emptyDecideCell = al_load_bitmap("Resource/empty_decide_cell_12.png");
			emptyDecideCellClic0 = al_load_bitmap("Resource/empty_decide_cell_12_clic0.png");
			fullCellClic0 = al_load_bitmap("Resource/full_cell_12_clic0.png");
			crossedCell = al_load_bitmap("Resource/crossed_cell_12.png");
		break;
		case 15:
			emptyCell = al_load_bitmap("Resource/empty_cell_15.png");
			emptyCellClic0 = al_load_bitmap("Resource/empty_cell_15_clic0.png");
			fullCell = al_load_bitmap("Resource/full_cell_15.png");
			emptyDecideCell = al_load_bitmap("Resource/empty_decide_cell_15.png");
			emptyDecideCellClic0 = al_load_bitmap("Resource/empty_decide_cell_15_clic0.png");
			fullCellClic0 = al_load_bitmap("Resource/full_cell_15_clic0.png");
			crossedCell = al_load_bitmap("Resource/crossed_cell_15.png");
		break;
		case 20:
			emptyCell = al_load_bitmap("Resource/empty_cell_20.png");
			emptyCellClic0 = al_load_bitmap("Resource/empty_cell_20_clic0.png");
			fullCell = al_load_bitmap("Resource/full_cell_20.png");
			emptyDecideCell = al_load_bitmap("Resource/empty_decide_cell_20.png");
			emptyDecideCellClic0 = al_load_bitmap("Resource/empty_decide_cell_20_clic0.png");
			fullCellClic0 = al_load_bitmap("Resource/full_cell_20_clic0.png");
			crossedCell = al_load_bitmap("Resource/crossed_cell_20.png");
		break;
	}

	int mouseSuppXPosX = 0, mouseSuppXPosY = 0, mouseSuppYPosX = 0, mouseSuppYPosY = 0; 
	int prevPosX = 0, prevPosY = 0;
	int prevCoordX = 0, prevCoordY = 0;

	while (!user_exit)
	{

		al_wait_for_event(event_queue, ev);
		
		if (ev->type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			for (int im = 0; im < 12; im++)
			buttonMenu[im] = false;
			buttonMenu[EXIT] = true;
			user_exit = true;
		}

		if (ev->type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
			if (ev->mouse.button == 1 && ev->mouse.x > 0 && ev->mouse.x < 150 && 
				ev->mouse.y > 30 && ev->mouse.y < 50 && currentLevel < user_lvl && checkNull() == 1) {
						g = 0.5;
				while (empty(mainField, xMap, yMap) != 1){
						g = g / 1.1;
						animation_decide(g);
					}
			}
			if (ev->mouse.button == 1 && ev->mouse.x > 0 && ev->mouse.x < 150 && 
				ev->mouse.y > 55 && ev->mouse.y < 75) {
					// CHECK IT
					if (check_it() == 1) {
						if (currentLevel == user_lvl) user_lvl++;
						nullMainField(mainField);
						while (empty(mainField, xMap, yMap) != 1){
							animation_decide(0.1);
						}
						for (i = 100; i < 170; i = i + 1){
							font_to_win = al_load_font("japan.ttf", i, 0);
							if (i % 2 == 1)
							al_draw_text(font_to_win, al_map_rgb(255,120,31), wight / 2, height / 2 - i/2, ALLEGRO_ALIGN_CENTRE, "B A N Z A I !");
							else
							al_draw_text(font_to_win, al_map_rgb(43,43,43), wight / 2, height / 2 - i/2, ALLEGRO_ALIGN_CENTRE, "B A N Z A I !");
							al_flip_display();
							al_rest(0.01);
						}
							al_rest(1);

						user_exit = true;
						buttonMenu[LEVEL_MENU] = true;
						buttonMenu[PLAY_GAME] = false;
						xMap = 0;
						yMap = 0;
						save_user();

						printf("GOOD JOB!");
					} else {
						printf("BAD JOB(");
					}
			}
		}


		if (ev->type == ALLEGRO_EVENT_KEY_UP){
			if (ev->keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
					user_exit = true;
					buttonMenu[LEVEL_MENU] = true;
					buttonMenu[PLAY_GAME] = false;
					xMap = 0;
					yMap = 0;

				}
			}
		

		if (scale != 0 && ev->mouse.x >= nullX && ev->mouse.x < nullX + xMap*scale 
			&& ev->mouse.y >= nullY - maxSuppX*scale && ev->mouse.y < nullY) {
			mouseSuppXPosX = (ev->mouse.x - nullX) / scale;
			mouseSuppXPosY = (ev->mouse.y - nullY) / scale;

			if (ev->type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
				if (ev->mouse.button == 1 && ev->mouse.x >= nullX && ev->mouse.x < nullX + xMap*scale 
					&& ev->mouse.y >= nullY - maxSuppX*scale && ev->mouse.y < nullY && suppFieldX[mouseSuppXPosX][-mouseSuppXPosY] != 0) {
					al_draw_bitmap(emptyCell, nullX + mouseSuppXPosX*scale, nullY + mouseSuppXPosY*scale - scale, 0);
					al_draw_textf(font, al_map_rgb(0, 0, 0), nullX + mouseSuppXPosX*scale+scale/2, nullY + mouseSuppXPosY*scale - scale, 
						ALLEGRO_ALIGN_CENTRE, "%d", suppFieldX[mouseSuppXPosX][-mouseSuppXPosY]);
					al_draw_bitmap(crossedCell, nullX + mouseSuppXPosX*scale, nullY + mouseSuppXPosY*scale - scale, 0);
					al_flip_display();
				}

				if (ev->mouse.button == 2 && ev->mouse.x >= nullX && ev->mouse.x < nullX + xMap*scale 
					&& ev->mouse.y >= nullY - maxSuppX*scale && ev->mouse.y < nullY && suppFieldX[mouseSuppXPosX][-mouseSuppXPosY] != 0) {
					al_draw_bitmap(emptyCell, nullX + mouseSuppXPosX*scale, nullY + mouseSuppXPosY*scale - scale, 0);
					al_draw_textf(font, al_map_rgb(0, 0, 0), nullX + mouseSuppXPosX*scale+scale/2, nullY + mouseSuppXPosY*scale - scale, 
						ALLEGRO_ALIGN_CENTRE, "%d", suppFieldX[mouseSuppXPosX][-mouseSuppXPosY]);
					al_flip_display();
				}

			}

		}


		if (scale != 0 && ev->mouse.x >= nullX - maxSuppY*scale && ev->mouse.x < nullX 
			&& ev->mouse.y >= nullY && ev->mouse.y < nullY + yMap*scale) {
			mouseSuppXPosX = (ev->mouse.x - nullX) / scale;
			mouseSuppXPosY = (ev->mouse.y - nullY) / scale;

			if (ev->type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
				if (ev->mouse.button == 1 && ev->mouse.x >= nullX - maxSuppY*scale && ev->mouse.x < nullX 
					&& ev->mouse.y >= nullY && ev->mouse.y < nullY + yMap*scale && suppFieldY[mouseSuppXPosY][-mouseSuppXPosX] != 0) {
					al_draw_bitmap(emptyCell, nullX + mouseSuppXPosX*scale - scale, nullY + mouseSuppXPosY*scale, 0);
					al_draw_textf(font, al_map_rgb(0, 0, 0), nullX + mouseSuppXPosX*scale - scale + scale/2, nullY + mouseSuppXPosY*scale, 
						ALLEGRO_ALIGN_CENTRE, "%d", suppFieldY[mouseSuppXPosY][-mouseSuppXPosX]);
					al_draw_bitmap(crossedCell, nullX + mouseSuppXPosX*scale - scale, nullY + mouseSuppXPosY*scale, 0);
					al_flip_display();
				}

				if (ev->mouse.button == 2 && ev->mouse.x >= nullX - maxSuppY*scale && ev->mouse.x < nullX 
					&& ev->mouse.y >= nullY && ev->mouse.y < nullY + yMap*scale && suppFieldY[mouseSuppXPosY][-mouseSuppXPosX] != 0) {
					al_draw_bitmap(emptyCell, nullX + mouseSuppXPosX*scale - scale, nullY + mouseSuppXPosY*scale, 0);
					al_draw_textf(font, al_map_rgb(0, 0, 0), nullX + mouseSuppXPosX*scale - scale + scale/2, nullY + mouseSuppXPosY*scale, 
						ALLEGRO_ALIGN_CENTRE, "%d", suppFieldY[mouseSuppXPosY][-mouseSuppXPosX]);
					al_flip_display();
				}

			}

		}



		if (scale != 0 && ev->mouse.x >= nullX && ev->mouse.x < nullX+xMap*scale 
			&& ev->mouse.y >= nullY && ev->mouse.y < nullY+yMap*scale) {
			mousePosX = (ev->mouse.x - nullX)/scale;
			mousePosY = (ev->mouse.y - nullY)/scale;


			if (ev->type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
				if (ev->mouse.button == 1) {
					if (mainField[mousePosY][mousePosX] == 0 || mainField[mousePosY][mousePosX] == 5) al_draw_bitmap(fullCell, nullX + mousePosX*scale, nullY+mousePosY*scale, 0);
					else if (mainField[mousePosY][mousePosX] == 1) al_draw_bitmap(emptyCell, nullX + mousePosX*scale, nullY+mousePosY*scale, 0);
					al_flip_display();
					draw_flag = true;
					if (mainField[mousePosY][mousePosX] == 0 || mainField[mousePosY][mousePosX] == 5) mainField[mousePosY][mousePosX] = 1;
					else if (mainField[mousePosY][mousePosX] == 1) mainField[mousePosY][mousePosX] = 0;
					//printMainField(mainField, xMap, yMap);
				}
				if (ev->mouse.button == 2) {
					if (mainField[mousePosY][mousePosX] == 0 || mainField[mousePosY][mousePosX] == 1) al_draw_bitmap(emptyDecideCell, nullX + mousePosX*scale, nullY+mousePosY*scale, 0);
					else if (mainField[mousePosY][mousePosX] == 5) al_draw_bitmap(emptyCell, nullX + mousePosX*scale, nullY+mousePosY*scale, 0);
					al_flip_display();
					draw_flag = true;
					if (mainField[mousePosY][mousePosX] == 0 || mainField[mousePosY][mousePosX] == 1) mainField[mousePosY][mousePosX] = 5;
					else if (mainField[mousePosY][mousePosX] == 5) mainField[mousePosY][mousePosX] = 0;
					//printMainField(mainField, xMap, yMap);
				}
			} 



			if ((prevMousePosX != mousePosX || prevMousePosY != mousePosY) 
				/*&& mousePosX >= 0 && mousePosY >= 0 && mousePosX < xMap && mousePosY < yMap*/)
			{	
 				if (mainField[mousePosY][mousePosX] == 0) al_draw_bitmap(emptyCellClic0, nullX + mousePosX*scale, nullY+mousePosY*scale, 0);
 				if (mainField[mousePosY][mousePosX] == 1) al_draw_bitmap(fullCellClic0, nullX + mousePosX*scale, nullY+mousePosY*scale, 0);
 				if (mainField[mousePosY][mousePosX] == 5) al_draw_bitmap(emptyDecideCellClic0, nullX + mousePosX*scale, nullY+mousePosY*scale, 0);
				al_flip_display();
				//draw_flag = false;
				//printf("+");
			}
			if ((prevMousePosX != mousePosX || prevMousePosY != mousePosY)  
			&& prevMousePosX >= 0 && prevMousePosY >= 0 && prevMousePosX < xMap && prevMousePosY < yMap) 
			{
				if (draw_flag == true){
					draw_flag = false;
				} else {
					if (mainField[prevMousePosY][prevMousePosX] == 0) al_draw_bitmap(emptyCell, nullX + prevMousePosX*scale, nullY+prevMousePosY*scale, 0);
					if (mainField[prevMousePosY][prevMousePosX] == 1) al_draw_bitmap(fullCell, nullX + prevMousePosX*scale, nullY+prevMousePosY*scale, 0);
					if (mainField[prevMousePosY][prevMousePosX] == 5) al_draw_bitmap(emptyDecideCell, nullX + prevMousePosX*scale, nullY+prevMousePosY*scale, 0);
					al_flip_display();
				}
			}
			prevMousePosX = mousePosX;
			prevMousePosY = mousePosY;
			
		}
	
	}			
}


void create_main_menu (ALLEGRO_BITMAP *image, ALLEGRO_BITMAP *button, ALLEGRO_EVENT *ev, ALLEGRO_EVENT_QUEUE *event_queue)
{
	ALLEGRO_FONT *font_menu;
	font_menu = al_load_font("japan.ttf", 30, 0);
	bool user_exit = false;


	al_draw_bitmap(image, 0, 0, 0);
	al_draw_bitmap(button, wight / 2 - 150, 170, 3);
	al_draw_text(font_menu, al_map_rgb(43, 43, 43), wight / 2, 190, ALLEGRO_ALIGN_CENTRE, "NEW GAME");
	al_draw_bitmap(button, wight / 2 - 150, 230, 3);
	al_draw_text(font_menu, al_map_rgb(43, 43, 43), wight / 2, 250, ALLEGRO_ALIGN_CENTRE, "LOAD PROFILE");
	al_draw_bitmap(button, wight / 2 - 150, 290, 3);
	al_draw_text(font_menu, al_map_rgb(43, 43, 43), wight / 2, 310, ALLEGRO_ALIGN_CENTRE, "SETTING");
	al_draw_bitmap(button, wight / 2 - 150, 350, 3);
	al_draw_text(font_menu, al_map_rgb(43, 43, 43), wight / 2, 370, ALLEGRO_ALIGN_CENTRE, "EXIT");
	al_flip_display();

	while (!user_exit)
	{
		al_wait_for_event(event_queue, ev);

		if (ev->type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			for (int im = 0; im < 12; im++)
			buttonMenu[im] = false;
			buttonMenu[EXIT] = true;
			user_exit = true;
		}

		if (ev->type == ALLEGRO_EVENT_KEY_UP){
			if (ev->keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				buttonMenu[EXIT] = true;
				user_exit = true;
			}
		}

		if (ev->type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
			if (ev->mouse.button & 1 && ev->mouse.x > wight/2 - 150 && 
				ev->mouse.y > 170 && ev->mouse.x < wight/2 + 150 && ev->mouse.y < 230){
				buttonMenu[NEW_USER_MENU] = true;
				user_exit = true;
			}
			if (ev->mouse.button & 1 && ev->mouse.x > wight/2 - 150 && 
				ev->mouse.y > 230 && ev->mouse.x < wight/2 + 150 && ev->mouse.y < 290){
				buttonMenu[LOAD_USER_MENU] = true;
				user_exit = true;
			}
			if (ev->mouse.button & 1 && ev->mouse.x > wight/2 - 150 && 
				ev->mouse.y > 290 && ev->mouse.x < wight/2 + 150 && ev->mouse.y < 350){
				buttonMenu[SETTING] = true;
				user_exit = true;
			}
			if (ev->mouse.button & 1 && ev->mouse.x > wight/2 - 150 && 
				ev->mouse.y > 350 && ev->mouse.x < wight/2 + 150 && ev->mouse.y < 410){
				buttonMenu[EXIT] = true;
				user_exit = true;
			}
		}

	}



}


void drawBitmapMainField(int suppFieldX[60][20], int suppFieldY[40][20], int mainField[40][60], int xMap, int yMap,
	ALLEGRO_BITMAP *fullCell, ALLEGRO_BITMAP *emptyCell, ALLEGRO_FONT *font10)
{
	int i = 0, j = 0;
	int count = 0;
	al_init_font_addon();
	al_init_ttf_addon();
	//ALLEGRO_FONT *font = al_load_font("arial.ttf", scale-2, 0);

	if (generate == false) nullMainField(mainField);
	for (i = 0; i < xMap; i++){
		count = 0;
		while (suppFieldX[i][count] != 0){
			count++;
			if (maxSuppX < count) maxSuppX = count;
		}
	}
	for (i = 0; i < yMap; i++){
		count = 0;
		while (suppFieldY[i][count] != 0){
			count++;
			if (maxSuppY < count) maxSuppY = count;
		}
	}

	if (yMap + maxSuppX > 50) {
		emptyCell = al_load_bitmap("Resource/empty_cell_10.png");
		fullCell = al_load_bitmap("Resource/full_cell_10.png");
		scale = 10;	
	}
	if (yMap + maxSuppX > 35 && yMap + maxSuppX <= 50) {
		emptyCell = al_load_bitmap("Resource/empty_cell_12.png");
		fullCell = al_load_bitmap("Resource/full_cell_12.png");
		scale = 12;	
	}
	if (yMap + maxSuppX > 25 && yMap + maxSuppX <= 35) {
		emptyCell = al_load_bitmap("Resource/empty_cell_15.png");
		fullCell = al_load_bitmap("Resource/full_cell_15.png");
		scale = 15;	
	}
	if ((yMap + maxSuppX > 0 && yMap + maxSuppX <= 25)) {
		if (xMap + maxSuppY < 50) {
		emptyCell = al_load_bitmap("Resource/empty_cell_20.png");
		fullCell = al_load_bitmap("Resource/full_cell_20.png");
		scale = 20;
		} else {
		emptyCell = al_load_bitmap("Resource/empty_cell_15.png");
		fullCell = al_load_bitmap("Resource/full_cell_15.png");
		scale = 15;	
		}
	}
	
	ALLEGRO_FONT *font = al_load_font("arial.ttf", scale-2, 0);

	ALLEGRO_BITMAP *user_name_field;
	ALLEGRO_BITMAP *button = al_load_bitmap("Resource/user_button.png");
	ALLEGRO_BITMAP *button_bw = al_load_bitmap("Resource/user_button_bw.png");
	ALLEGRO_FONT *font_nick;
	user_name_field = al_load_bitmap("Resource/user_name_field.png");
	font_nick = al_load_font("japan.ttf", 15, 0);



	al_draw_bitmap(user_name_field, 0, 0, 0);
	al_draw_textf(font_nick, al_map_rgb(43, 43, 43), 75, 3, ALLEGRO_ALIGN_CENTRE, "%s LV. %d", user_name, user_lvl);
	
	if (generate == false) {
		al_draw_bitmap(button, 0, 55, 0);
		if (user_lvl > currentLevel) {
			al_draw_bitmap(button, 0, 30, 0);
		} else {
			al_draw_bitmap(button_bw, 0, 30, 0);
		}
		al_draw_text(font_nick, al_map_rgb(43, 43, 43), 75, 33, ALLEGRO_ALIGN_CENTRE, "ANIMATION DECIDE");
		al_draw_text(font_nick, al_map_rgb(43, 43, 43), 75, 58, ALLEGRO_ALIGN_CENTRE, "CHECK IT");
	} else {
		al_draw_bitmap(button, 0, 30, 0);
		al_draw_bitmap(button, 0, 55, 0);
		al_draw_text(font_nick, al_map_rgb(43, 43, 43), 75, 33, ALLEGRO_ALIGN_CENTRE, "GENERATE FIELD");
		al_draw_text(font_nick, al_map_rgb(43, 43, 43), 75, 58, ALLEGRO_ALIGN_CENTRE, "EXIT");
	}
	al_flip_display();

	centerY = (xMap + maxSuppY) * scale / 2;
	centerX = (yMap + maxSuppX) * scale / 2;

	nullX = (wight / 2 - centerY) + maxSuppY*scale;
	nullY = (height / 2 - centerX) + maxSuppX*scale;

	// рисуем сетку
	for (i = 0; i < yMap*scale; i = i+scale) {
		al_draw_line(nullX - maxSuppY*scale, nullY + i, nullX+xMap*scale, nullY + i, al_map_rgb(60, 60, 60), 1);
	}
	for (i = 0; i < xMap*scale; i = i+scale){
		al_draw_line(nullX+i, nullY-maxSuppX*scale, nullX+i, nullY+yMap*scale, al_map_rgb(60, 60, 60), 1);
	}

	// рисуем рамку
	al_draw_line(nullX - maxSuppY*scale, nullY, nullX+xMap*scale, nullY, al_map_rgb(0, 0, 0), 1);
	for (i = 0; i < yMap*scale; i = i+scale*5) {
		al_draw_line(nullX - maxSuppY*scale, nullY + i, nullX+xMap*scale, nullY + i, al_map_rgb(0, 0, 0), 1);
	}
	al_draw_line(nullX - maxSuppY*scale, nullY+yMap*scale, nullX+xMap*scale, nullY+yMap*scale, al_map_rgb(0, 0, 0), 1);
	al_draw_line(nullX, nullY-maxSuppX*scale, nullX+xMap*scale, nullY-maxSuppX*scale, al_map_rgb(0, 0, 0), 1);

	al_draw_line(nullX, nullY-maxSuppX*scale, nullX, nullY+yMap*scale, al_map_rgb(0, 0, 0), 1);
	for (i = 0; i < xMap*scale; i = i+5*scale){
		al_draw_line(nullX+i, nullY-maxSuppX*scale, nullX+i, nullY+yMap*scale, al_map_rgb(0, 0, 0), 1);
	}
	al_draw_line(nullX + xMap*scale, nullY-maxSuppX*scale, nullX + xMap*scale, nullY+yMap*scale, al_map_rgb(0, 0, 0), 1);
	al_draw_line(nullX - maxSuppY*scale, nullY, nullX - maxSuppY*scale, nullY+yMap*scale, al_map_rgb(0, 0, 0), 1);
	al_flip_display();

	// рисуем suppFieldX, suppFieldY, mainField

	for (i = 0; i < xMap*scale; i=i+scale){
		for (j = 0; j < maxSuppX*scale; j = j + scale){
			al_draw_bitmap(emptyCell, nullX  + i, nullY - maxSuppX*scale + j, 0);
		}
	}
	al_flip_display();
	for (j = 0; j < maxSuppY*scale; j = j + scale){
		for (i = 0; i < yMap*scale; i=i+scale){
			al_draw_bitmap(emptyCell, nullX - maxSuppY*scale + j, nullY + i, 0);
		}
	}
	al_flip_display();
	for (i = 0; i < xMap*scale; i=i+scale){
		for (j = 0; j < yMap*scale; j = j + scale){
			/*if (mainField[j/scale][i/scale] == 0)*/ al_draw_bitmap(emptyCell, nullX + i, nullY + j, 0);
			if (generate == true) {
				if (mainField[j/scale][i/scale] == 0) al_draw_bitmap(emptyCell, nullX + i, nullY + j, 0);
				if (mainField[j/scale][i/scale] == 1) al_draw_bitmap(fullCell, nullX + i, nullY + j, 0);
			}
		}
	}
	al_flip_display();

	// заполняем цифрами SuppField

	for (i = 0; i < xMap*scale; i=i+scale){
		for (j = 0; j < maxSuppX*scale; j = j + scale){
			if (suppFieldX[i/scale][j/scale] >= 10){
				al_draw_textf(font, al_map_rgb(0, 0, 0), nullX + i + scale/2, nullY - j - scale, ALLEGRO_ALIGN_CENTRE, "%d", suppFieldX[i/scale][j/scale]);
			}
			if (suppFieldX[i/scale][j/scale] < 10 && suppFieldX[i/scale][j/scale] != 0){
				al_draw_textf(font, al_map_rgb(0, 0, 0), nullX + i + scale/2, nullY - j - scale, ALLEGRO_ALIGN_CENTRE, "%d", suppFieldX[i/scale][j/scale]);
			}
		}
	}
	al_flip_display();

	for (j = 0; j < maxSuppY*scale; j = j + scale){
		for (i = 0; i < yMap*scale; i=i+scale){
			if (suppFieldY[i/scale][j/scale] >= 10){
				al_draw_textf(font, al_map_rgb(0, 0, 0), nullX - j - scale + scale/2, nullY + i, ALLEGRO_ALIGN_CENTRE, "%d", suppFieldY[i/scale][j/scale]);
			}
			if (suppFieldY[i/scale][j/scale] < 10 && suppFieldY[i/scale][j/scale] != 0){
				al_draw_textf(font, al_map_rgb(0, 0, 0), nullX - j - scale + scale/2, nullY + i, ALLEGRO_ALIGN_CENTRE, "%d", suppFieldY[i/scale][j/scale]);
			}
		}
	}
	al_flip_display();

	al_destroy_font(font);

}


char readkey(ALLEGRO_EVENT *ev, ALLEGRO_EVENT_QUEUE *event_queue, int X, int Y, ALLEGRO_BITMAP *background)
{
	bool user_exit = false;
	int i= 0;

	while (!user_exit) {
		
		i++;
		al_draw_bitmap(background,i,0,0);
		al_flip_display();
		
		al_wait_for_event(event_queue, ev);
  		if (ev->type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
		  if (ev->mouse.button & 1  && (ev->mouse.y < Y  || ev->mouse.y > Y + al_get_bitmap_height(background))
			  || (ev->mouse.x < X || ev->mouse.x > X + al_get_bitmap_width(background))){
			  return '[';
		  } 
		}

		if (ev->type == ALLEGRO_EVENT_KEY_UP){
			switch (ev->keyboard.keycode) {
				case ALLEGRO_KEY_Q:
					return 'Q';
				break;
				case ALLEGRO_KEY_W:
					return 'W';
				break;
				case ALLEGRO_KEY_E:
					return 'E';
				break;
				case ALLEGRO_KEY_R:
					return 'R';
				break;
				case ALLEGRO_KEY_T:
					return 'T';
				break;
				case ALLEGRO_KEY_Y:
					return 'Y';
				break;
				case ALLEGRO_KEY_U:
					return 'U';
				break;
				case ALLEGRO_KEY_I:
					return 'I';
				break;
				case ALLEGRO_KEY_O:
					return 'O';
				break;
				case ALLEGRO_KEY_P:
					return 'P';
				break;
				case ALLEGRO_KEY_A:
					return 'A';
				break;
				case ALLEGRO_KEY_S:
					return 'S';
				break;
				case ALLEGRO_KEY_D:
					return 'D';
				break;
				case ALLEGRO_KEY_F:
					return 'F';
				break;
				case ALLEGRO_KEY_G:
					return 'G';
				break;
				case ALLEGRO_KEY_H:
					return 'H';
				break;
				case ALLEGRO_KEY_J:
					return 'J';
				break;
				case ALLEGRO_KEY_K:
					return 'K';
				break;
				case ALLEGRO_KEY_L:
					return 'L';
				break;
				case ALLEGRO_KEY_Z:
					return 'Z';
				break;
				case ALLEGRO_KEY_X:
					return 'X';
				break;
				case ALLEGRO_KEY_C:
					return 'C';
				break;
				case ALLEGRO_KEY_V:
					return 'V';
				break;
				case ALLEGRO_KEY_B:
					return 'B';
				break;
				case ALLEGRO_KEY_N:
					return 'N';
				break;
				case ALLEGRO_KEY_M:
					return 'M';
				break;
				case ALLEGRO_KEY_1:
					return '1';
				break;
				case ALLEGRO_KEY_2:
					return '2';
				break;
				case ALLEGRO_KEY_3:
					return '3';
				break;
				case ALLEGRO_KEY_4:
					return '4';
				break;
				case ALLEGRO_KEY_5:
					return '5';
				break;
				case ALLEGRO_KEY_6:
					return '6';
				break;
				case ALLEGRO_KEY_7:
					return '7';
				break;
				case ALLEGRO_KEY_8:
					return '8';
				break;
				case ALLEGRO_KEY_9:
					return '9';
				break;
				case ALLEGRO_KEY_0:
					return '0';
				break;
				case ALLEGRO_KEY_BACKSPACE:
					return ']';
				break;
				case ALLEGRO_KEY_ENTER:
					return '[';
				break;

				default:
					return 0;
					user_exit = true;
					break;
			}
		}
	}
}