#define ALLEGRO_STATICLINK

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_acodec.h>
#include <allegro5\allegro_audio.h>

void readMapTxt(FILE *fmap, int *x, int *y, int mainField[40][60]);
void generateSupField (int suppFieldX[60][20], int suppFieldY[40][20], int mainField[40][60], int xMap, int yMap);
void nullMainField (int mainField[40][60]);
void printMainField (int mainField[40][60], int xMap, int yMap);
int empty (int mainField[40][60], int xMap, int yMap);
int error (int mainField[40][60], int helphelpField[40][60], int xMap, int yMap);
void readMapSuppField(FILE *fmap, int x, int y, int suppFieldX[60][20], int suppFieldY[40][20]);
void drawBitmapMainField(int suppFieldX[60][20], int suppFieldY[40][20], int mainField[40][60], int xMap, int yMap,
	ALLEGRO_BITMAP *fullCell, ALLEGRO_BITMAP *emptyCell, ALLEGRO_FONT *font10);
void create_main_menu (ALLEGRO_BITMAP *image, ALLEGRO_BITMAP *button, ALLEGRO_EVENT *ev, ALLEGRO_EVENT_QUEUE *event_queue);
void gamePlay(ALLEGRO_EVENT *ev, ALLEGRO_EVENT_QUEUE *event_queue);
void create_play_menu (ALLEGRO_BITMAP *image, ALLEGRO_BITMAP *button, ALLEGRO_EVENT *ev, ALLEGRO_EVENT_QUEUE *event_queue);
void create_level_menu (FILE *fmap, ALLEGRO_BITMAP *image, ALLEGRO_EVENT *ev, ALLEGRO_EVENT_QUEUE *event_queue);
char readkey(ALLEGRO_EVENT *ev, ALLEGRO_EVENT_QUEUE *event_queue, int X, int Y, ALLEGRO_BITMAP *background);
void scanf_text(char buffer[512], ALLEGRO_BITMAP *background, ALLEGRO_FONT *font, int X, int Y, int SizeText, ALLEGRO_EVENT *ev, ALLEGRO_EVENT_QUEUE *event_queue);
void create_new_user_menu (ALLEGRO_BITMAP *image, ALLEGRO_EVENT *ev, ALLEGRO_EVENT_QUEUE *event_queue);
int search_user_file ();
void create_new_user ();
void nullSuppField ();
void create_load_user_menu (ALLEGRO_BITMAP *image, ALLEGRO_EVENT *ev, ALLEGRO_EVENT_QUEUE *event_queue);
void readLevel (int currentLevel);
int check_it();
void save_user();
void draw_animation();
int check_to_changes();
void prevToMain();
void animation_decide(float time);
void generate_game(ALLEGRO_BITMAP *image, ALLEGRO_EVENT *ev, ALLEGRO_EVENT_QUEUE *event_queue);
void create_generate_menu(ALLEGRO_BITMAP *image, ALLEGRO_EVENT *ev, ALLEGRO_EVENT_QUEUE *event_queue);
int checkNull();
void create_setting_menu (ALLEGRO_EVENT *ev, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_SAMPLE_INSTANCE *songInstance);
void readSetImage();
void changeSet ();
void readSetMusic(ALLEGRO_SAMPLE_INSTANCE *songInstance);


void firstDrawDecide (int suppFieldX[60][20], int suppFieldY[40][20], int mainField[40][60], int xMap, int yMap);
void drawByEmptyCells (int suppFieldX[60][20], int suppFieldY[40][20], int mainField[40][60], int xMap, int yMap);
void drawEdgeField (int suppFieldX[60][20], int suppFieldY[40][20], int mainField[40][60], int xMap, int yMap);
void drawCheckEdgeField (int suppFieldX[60][20], int suppFieldY[40][20], int mainField[40][60], int xMap, int yMap);


void checkPoint_100 (int suppFieldX[60][20], int suppFieldY[40][20], int mainField[40][60], int xMap, int yMap);
void checkPoint_elements (int suppFieldX[60][20], int suppFieldY[40][20], int mainField[40][60], int xMap, int yMap);
void checkEmptyFields(int suppFieldX[60][20], int suppFieldY[40][20], int mainField[40][60], int xMap, int yMap);
void checkFromEdgeField (int suppFieldX[60][20], int suppFieldY[40][20], int mainField[40][60], int xMap, int yMap);

extern int maxSuppX, maxSuppY;
extern int mainField[40][60];
extern int suppFieldX[60][20], suppFieldY[40][20];
extern int helphelpField[40][60];
extern int prevMainField[40][60];
extern int wight;
extern int height;
extern int centerX;
extern int centerY;
extern int nullX;
extern int nullY;
extern int scale;
extern bool redraw;
extern int xMap, yMap;
extern int mousePosX, mousePosY, prevMousePosX, prevMousePosY;
extern enum MENU{NEW_GAME, LOAD_GAME, SETTING, EXIT, NEW_USER_MENU, LOAD_USER_MENU, PLAY_MENU, LEVEL_MENU, PLAY_GAME, GENERATE_MENU, GENERATE_GAME};
extern bool buttonMenu[12];
extern bool mainMenu;
extern char user_name[10];
extern int user_lvl;
extern FILE *users;
extern int byteNumb;
extern struct button_level {
		int x[50];
		int y[50];
		int number[50];
	};
extern struct button_level buttonStruct;
extern int currentLevel;
extern bool generate;
extern ALLEGRO_BITMAP *image;
extern int set_im, set_music;
extern ALLEGRO_SAMPLE *sound;
//extern ALLEGRO_SAMPLE_INSTANCE *songInstance;
