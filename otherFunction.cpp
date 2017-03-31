#include "header.h"

void changeSet (){
	FILE *set;
	set = fopen("setting.txt", "w");
	fprintf(set, "%d %d", set_im, set_music);
	fclose(set);
}

void readSetMusic (ALLEGRO_SAMPLE_INSTANCE *songInstance)
{
	FILE *set;
	set = fopen("setting.txt", "r");
	fscanf(set, "%d %d", &set_im, &set_music);

/*	sound = al_load_sample("Resource/11.wav");
	songInstance = al_create_sample_instance(sound); 
	al_set_sample_instance_playmode(songInstance, ALLEGRO_PLAYMODE_LOOP); 
	al_attach_sample_instance_to_mixer(songInstance, al_get_default_mixer());
*/

	if (set_music == 0) {
		al_stop_sample_instance(songInstance);
	}
	if (set_music == 1) {
		al_play_sample_instance(songInstance);
	}

}

void readSetImage (){
	FILE *set;
	set = fopen("setting.txt", "r");
	fscanf(set, "%d %d", &set_im, &set_music);

	if (set_im == 0) {
		image = al_load_bitmap("Resource/background.png");
	}
	if (set_im == 1) {
		image = al_load_bitmap("Resource/background1.png");
	}
	if (set_im == 2) {
		image = al_load_bitmap("Resource/background2.png");
	}
	if (set_im == 3) {
		image = al_load_bitmap("Resource/background3.png");
	}
	if (set_im == 4) {
		image = al_load_bitmap("Resource/background4.png");
	}
	fclose(set);
}

void prevToMain()
{
	int i = 0, j = 0;
	for (i = 0; i < yMap; i++){
		for (j = 0; j < xMap; j++){
			prevMainField[i][j] = mainField[i][j];
		}
	}
}

int check_to_changes(){
	int i = 0, j = 0;

	for (i = 0; i < yMap; i++){
		for (j = 0; j < xMap; j++){
			if (prevMainField[i][j] != mainField[i][j]) {
				return 1;
			}
		}
	}

	return 0;
}


int check_it(){
	int i = 0, j = 0;

	for (i = 0; i < yMap; i++){
		for (j = 0; j < xMap; j++){
			if (mainField[i][j] == 1) {
				if (helphelpField[i][j] != 1) return 0;
			}
			if (mainField[i][j] == 0 || mainField[i][j] == 5) {
				if (helphelpField[i][j] != 0) return 0;
			}
		}
	}

	return 1;
}

void save_user()
{
	FILE *users;
	users = fopen("users.txt", "r+b");
	fseek(users, byteNumb-4, 1);
	fwrite(&user_lvl, sizeof(user_lvl), 1, users);

	fclose(users);
}

void create_new_user ()
{
	FILE *users;
	int a = 45;
	users = fopen("users.txt", "ab");
	fwrite(user_name, sizeof(user_name), 1, users);
	fwrite(&user_lvl, sizeof(user_lvl), 1, users);
	byteNumb = ftell(users);
	printf("\n byte %d", byteNumb);

	//fwrite("POPADIYK", sizeof(user_name), 1, users);
	//fwrite(&a, sizeof(user_lvl), 1, users);

	fclose(users);
}

int search_user_file ()
{
	FILE *users;
	bool user_exit;
	users = fopen("users.txt", "rb");
	char name_in_file[10];
	fseek(users, 0, 0);
	while (!user_exit) {
		fread(name_in_file, sizeof(name_in_file), 1, users);
		fread(&user_lvl, sizeof(user_lvl), 1, users);
		if (feof(users)) user_exit = true;
		byteNumb = ftell(users);
		printf("\n%s %d", name_in_file, user_lvl);
		printf("\n byte %d", byteNumb);
		if (strcmp(user_name, name_in_file) == 0) return 1;
	}
	return 0;
	fclose(users);
}

void generateSupField (int suppFieldX[60][20], int suppFieldY[40][20], int mainField[40][60], int xMap, int yMap)
{
	int i = 0, j = 0, g = 0;
	int count = 0;
	bool flagCount = false;
	// парсимо по рядкам з права на ліво та записуємо у допоміжне поле suppFieldY
	for (j = 0; j < yMap; j++) {
	for (i = xMap; i >= 0; i--) {
		if (((mainField[j][i] == 1) && (flagCount == true)) || ((mainField[j][i] == 1) && (flagCount == false) && (count == 0))) {
			count++;
			flagCount = true;
		} else {
			if (count>0) {
				suppFieldY[j][g] = count;
				g++;
			}
			flagCount = false;
			count = 0;
		}
		
		if ((i == 0) && (count != 0)) {
			suppFieldY[j][g] = count;		
			flagCount = false;
			count = 0;
		}

	}
		g = 0;
	}

	// парсимо по стовпчиках з низу до верху та записуємо у допоміжне поле suppFieldX
	for (j = 0; j < xMap; j++) {
	for (i = yMap; i >= 0; i--) {
		if (((mainField[i][j] == 1) && (flagCount == true)) || ((mainField[i][j] == 1) && (flagCount == false) && (count == 0))) {
			count++;
			flagCount = true;
		} else {
			if (count>0) {
				suppFieldX[j][g] = count;
				g++;
			}
			flagCount = false;
			count = 0;
		}
		
		if ((i == 0) && (count != 0)) {
			suppFieldX[j][g] = count;		
			flagCount = false;
			count = 0;
		}

	}
		g = 0;
	}


	for (j = 0; j < yMap; j++) {
		printf("\nNumbers of line %d: ", j);
		for (i = 0; i < 20; i++) printf("%d ", suppFieldY[j][i]);
	}
	printf("\n");
	for (j = 0; j < xMap; j++) {
		printf("\nNumbers of column %d: ", j);
		for (i = 0; i < 20; i++) printf("%d ", suppFieldX[j][i]);
	}

}

void readMapSuppField(FILE *fmap, int x, int y, int suppFieldX[60][20], int suppFieldY[40][20])
{
	int i1 = 0, i2 = 0;
	int count = 0;
	int g1 = 0, g2 = 0;
	char str[100] = {NULL};
	while (fscanf(fmap, "%s", str) != EOF) {
		if (count < x) {
				sscanf(str, "%d", suppFieldX[g1]);
				printf("%d = suppFieldX[%d][%d]\n", suppFieldX[g1][i1], g1, i1);
			g1++;
		} else {
				sscanf(str, "%d", suppFieldY[g2]);
				printf("%d = suppFieldX[%d][%d]\n", suppFieldY[g2][i2], g2, i2);
			g2++;
		}
		count++;
	}
	if (count > x+y) printf("ERROR X/Y");
}

void readMapTxt(FILE *fmap, int *x, int *y, int mainField[40][60])
{
	nullMainField(helphelpField);
	int i= 0, j = 0;
	int XX = 0;
	int d;
	char str[100] = {NULL};
	while (fscanf(fmap, "%s", str) != EOF) {
		(*y)++;
		while (str[i]!='\0') {
			sscanf(&str[i], "%1d", &mainField[(*y)-1][i]);
			(int)mainField[(*y)-1][i];
			XX++;
			if ((XX>60) || (*y > 40)) { 
				printf("ERROR: Map*s size so great!");
				(*x) = 0;
				(*y) = 0;
				break;
			}
			i++;
		}

		if ((*x == 0) && (*y == 0)) break;
		if (*y == 1) *x = XX;
		if (XX != (*x)) {
				printf("ERROR: Map*s size not coorect! XX(%d) != (*x)(%d) ", XX, *x);
				(*x) = 0;
				(*y) = 0;
				break;
		}

		
		XX = 0;
		i = 0;
	}

	for (i = 0; i < 40; i++)
		for (j = 0; j < 60; j++)
			helphelpField[i][j] = mainField[i][j];

}

void nullMainField (int Field[40][60])
{
	int i = 0, j = 0;
	for (i = 0; i < 40; i++)
		for (j = 0; j < 60; j++)
			Field[i][j] = 0;
}


void nullSuppField ()
{
	int i = 0, j = 0;
	for (i = 0; i < 60; i++)
		for (j = 0; j < 20; j++)
			suppFieldX[i][j] = 0;
	for (i = 0; i < 40; i++)
		for (j = 0; j < 20; j++)
			suppFieldY[i][j] = 0;
	maxSuppX = 0;
	maxSuppY = 0;
}

void printMainField (int mainField[40][60], int xMap, int yMap)
{
	int i = 0, j = 0;
	for (i = 0; i < yMap; i++){
		for (j = 0; j < xMap; j++){
			if (mainField[i][j] == 0 ) printf("%c", 250);
			if (mainField[i][j] == 1 ) printf("%c", 220);
			if (mainField[i][j] == 5 ) printf("%c", 229);
		}
	printf("\n");
	}
}

int empty (int mainField[40][60], int xMap, int yMap)
{
	int i = 0, j = 0;
	for (i = 0; i < yMap; i++){
		for (j = 0; j < xMap; j++){
			if (mainField[i][j] == 0) return 0;
		}
	}
	return 1;

}

int checkNull()
{
	int i, j;

	for (i = 0; i < yMap; i++)
		for (j = 0; j < xMap; j++){
			if (mainField[i][j] != 0) return 0;
		}

	return 1;
}

int error (int mainField[40][60], int helphelpField[40][60], int xMap, int yMap)
{
/*	int i, j;

	for (i = 0; i < yMap; i++)
		for (j = 0; j < xMap; j++)
			if (mainField[i][j] != helphelpField[i][j] && mainField[i][j] == 5 && helphelpField[i][j] == 1) {
				printf("ERROR in this function! element[%d][%d]!", i, j);
				getchar();
				return 0;
			}*/
	return 1;
}

void readLevel (int currentLevel){
	FILE *fmap;
	nullSuppField();
	nullMainField(mainField);
	switch (currentLevel) {
	case 1:
		fmap = fopen("map1.txt", "r");
		break;
	case 2:
		fmap = fopen("map2.txt", "r");
		break;
	case 3:
		fmap = fopen("map3.txt", "r");
		break;
	case 4:
		fmap = fopen("map4.txt", "r");
		break;
	case 5:
		fmap = fopen("map5.txt", "r");
		break;
	case 6:
		fmap = fopen("map6.txt", "r");
		break;
	case 7:
		fmap = fopen("map7.txt", "r");
		break;
	case 8:
		fmap = fopen("map8.txt", "r");
		break;
	case 9:
		fmap = fopen("map9.txt", "r");
		break;
	case 10:
		fmap = fopen("map10.txt", "r");
		break;
	case 11:
		fmap = fopen("map11.txt", "r");
		break;
	case 12:
		fmap = fopen("map12.txt", "r");
		break;
	case 13:
		fmap = fopen("map13.txt", "r");
		break;
	case 14:
		fmap = fopen("map14.txt", "r");
		break;
	case 15:
		fmap = fopen("map15.txt", "r");
		break;
	case 16:
		fmap = fopen("map16.txt", "r");
		break;
	case 17:
		fmap = fopen("map17.txt", "r");
		break;
	case 18:
		fmap = fopen("map18.txt", "r");
		break;
	case 19:
		fmap = fopen("map19.txt", "r");
		break;
	case 20:
		fmap = fopen("map20.txt", "r");
		break;
	case 21:
		fmap = fopen("map21.txt", "r");
		break;
	case 22:
		fmap = fopen("map22.txt", "r");
		break;
	case 23:
		fmap = fopen("map23.txt", "r");
		break;
	case 24:
		fmap = fopen("map24.txt", "r");
		break;
	case 25:
		fmap = fopen("map25.txt", "r");
		break;
	case 26:
		fmap = fopen("map26.txt", "r");
		break;
	case 27:
		fmap = fopen("map27.txt", "r");
		break;
	case 28:
		fmap = fopen("map28.txt", "r");
		break;
	case 29:
		fmap = fopen("map29.txt", "r");
		break;
	case 30:
		fmap = fopen("map30.txt", "r");
		break;
	case 31:
		fmap = fopen("map31.txt", "r");
		break;
	case 32:
		fmap = fopen("map32.txt", "r");
		break;
	case 33:
		fmap = fopen("map33.txt", "r");
		break;
	case 34:
		fmap = fopen("map34.txt", "r");
		break;
	case 35:
		fmap = fopen("map35.txt", "r");
		break;
	case 36:
		fmap = fopen("map36.txt", "r");
		break;
	case 37:
		fmap = fopen("map37.txt", "r");
		break;
	case 38:
		fmap = fopen("map38.txt", "r");
		break;
	case 39:
		fmap = fopen("map39.txt", "r");
		break;
	case 40:
		fmap = fopen("map40.txt", "r");
		break;
	case 41:
		fmap = fopen("map41.txt", "r");
		break;
	case 42:
		fmap = fopen("map42.txt", "r");
		break;
	case 43:
		fmap = fopen("map43.txt", "r");
		break;
	case 44:
		fmap = fopen("map44.txt", "r");
		break;
	case 45:
		fmap = fopen("map45.txt", "r");
		break;
	case 46:
		fmap = fopen("map46.txt", "r");
		break;
	case 47:
		fmap = fopen("map47.txt", "r");
		break;
	case 48:
		fmap = fopen("map48.txt", "r");
		break;
	case 49:
		fmap = fopen("map49.txt", "r");
		break;
	case 50:
		fmap = fopen("map50.txt", "r");
		break;
	case 51:
		fmap = fopen("map51.txt", "r");
		break;
}
	readMapTxt(fmap, &xMap, &yMap, mainField);
	generateSupField (suppFieldX, suppFieldY, mainField, xMap, yMap);
	fclose(fmap);
}


