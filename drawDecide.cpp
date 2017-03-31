#include "header.h"

void drawCheckEdgeField (int suppFieldX[60][20], int suppFieldY[40][20], int mainField[40][60], int xMap, int yMap)
{
	int i = 0, j = 0, g = 0, m = 0, sum9 = 0, sumLine = 0, count = 0, iCount = 0;
	int helpMainField[40][60] = {NULL};
	bool flag = false;
	bool flag0 = false;

	// +++++++++++++++ Парсинг по Х +++++++++++++++++++++++
	for (j = 0; j < yMap; j++)
	{
	while (suppFieldY[j][count] != 0) {
		count++;
	}
		flag = false;
		flag0 = false;
		iCount = 1;
		for (i = 0; i < xMap; i++){
			if ((mainField[j][i] == 0) || (mainField[j][i] == 1)) flag = true;
			if ((mainField[j][i] == 0) && (flag == true)) flag0 = true;
			if ((mainField[j][i] == 5) && ((mainField[j][i+1] == 0) || (mainField[j][i+1] == 1)) && (flag0 == false) && (flag == true)){
				flag0 = false;
				m = 0;
				flag = false;
				iCount++;
			}
			if ((mainField[j][i] == 5) && (flag == true) && (flag0 == true)) break;
			if (flag == true) m++;
		}
		flag = false;
		g = i - m;

		for (i = g; i < xMap; i++){
			if (mainField[j][i] == 1) flag = true;
			if (mainField[j][i+1] == 5) break;
		}

		if (((m == suppFieldY[j][count-iCount]) && (flag == true)) || ((m > suppFieldY[j][count - iCount]) && (mainField[j][g] == 1))) {
			for (i = g; i < g+suppFieldY[j][count-iCount]; i++)
			if ((mainField[j][i] == 0) || (mainField[j][i] == 1)) mainField[j][i] = 1;
			if ((mainField[j][i] == 0) || (mainField[j][i] == 5)) mainField[j][i] = 5;
			
		}


		g = 0;
		m = 0;
		flag = false;
		count = 0;
		iCount = 1;


	}

}

void drawEdgeField (int suppFieldX[60][20], int suppFieldY[40][20], int mainField[40][60], int xMap, int yMap)
{
	int i = 0, j = 0;
	bool flag = false;
	int g = 0, g1 = 0, m = 0, h = 0, countFullCell = 0, ii = 0, jj = 0, count = 0;
	int helpMainField[40][60] = {NULL};

	// +++++++++++++++ Парсинг по Х +++++++++++++++++++++++

		for (i = 0; i < yMap; i++){
				flag = false;
				m = 0;
				countFullCell = 0;
				g = 0;
			for(j = xMap - 1; j >= 0; j--){
				// рахуємо кількість клітинок до першого нуля
				if (mainField[i][j] != 0) m++;

				if (mainField[i][j] == 0) {
						for (j = xMap - 1; j >= xMap - m; j--){
							if (mainField[i][j] == 5) g = xMap - j; 
							if ((mainField[i][j-1] == 5) && (mainField[i][j] == 1)) {
								countFullCell++;
							}
						}
					for (j = xMap-g; j >= xMap - g - suppFieldY[i][countFullCell]; j--){
						if (mainField[i][j] == 1) flag = true;
						if (flag == true) mainField[i][j] = 1;
					}
					break;
			}
		}
	}
	
		for (i = yMap - 1; i >= 0; i--){
				flag = false;
				m = 0;
				countFullCell = 0;
				g = 0;
				count = 0;
				while (suppFieldY[i][count] != 0) count++;

			for(j = 0; j < xMap; j++){
				// рахуємо кількість клітинок до першого нуля
				if (mainField[i][j] != 0) m++;
				if (mainField[i][j] == 0) {
						//printf("m[%d] = %d; j = %d; mainField[%d][%d] = %d; ",i, m, j, i, j, mainField[i][j]);
						for (j = 0; j < m; j++){
							if (mainField[i][j] == 5) g = j+1; 
							if ((j != 0) && (mainField[i][j] == 5) && (mainField[i][j-1] == 1)) {
								countFullCell++;
							}
						}
						//printf("g = %d, countFullCell = %d, count = %d\n ", g, countFullCell, count);
						if (g+suppFieldY[i][count - countFullCell - 1] > xMap) break;
					for (j = g; j < g + suppFieldY[i][count - countFullCell - 1]; j++){
						if (mainField[i][j-1] == 1) flag = true;
						if (flag == true) mainField[i][j] = 1;
					}
					break;
			}
		}
	}


	// ++++++ END +++++++++ Парсинг по Х +++++++++++++++++++++++

	// +++++++++++++++ Парсинг по Y +++++++++++++++++++++++
		for (i = 0; i < xMap; i++){
				flag = false;
				m = 0;
				countFullCell = 0;
				g = 0;
			for(j = yMap - 1; j >= 0; j--){
				// рахуємо кількість клітинок до першого нуля
				if (mainField[j][i] != 0) m++;
				if (mainField[j][i] == 0) {
						for (j = yMap - 1; j >= yMap - m; j--){
							if (mainField[j][i] == 5) g = yMap - j; 
							if ((mainField[j-1][i] == 5) && (mainField[j][i] == 1)){
								countFullCell++;
							}
						}

					for (j = yMap-g; j >= yMap - g - suppFieldX[i][countFullCell]; j--){
						if (mainField[j][i] == 1) flag = true;
						if (flag == true) mainField[j][i] = 1;
					}
					break;
			}
		}
	}

		for (i = xMap - 1; i >= 0; i--){
				flag = false;
				m = 0;
				countFullCell = 0;
				g = 0;
				count = 0;
				while (suppFieldX[i][count] != 0) count++;

			for(j = 0; j < yMap; j++){
				// рахуємо кількість клітинок до першого нуля
				if (mainField[j][i] != 0) m++;
				if (mainField[j][i] == 0) {
						//printf("m[%d] = %d; j = %d; mainField[%d][%d] = %d; ",i, m, j, i, j, mainField[i][j]);
						for (j = 0; j < m; j++){
							if (mainField[j][i] == 5) g = j+1; 
							if ((j != 0) && (mainField[j][i] == 5) && (mainField[j-1][i] == 1)) {
								countFullCell++;
							}
						}
						//printf("g = %d, countFullCell = %d, count = %d\n ", g, countFullCell, count);
						if (g+suppFieldX[i][count - countFullCell - 1] > xMap) break;
					for (j = g; j < g + suppFieldX[i][count - countFullCell - 1]; j++){
						if (mainField[j-1][i] == 1) flag = true;
						if (flag == true) mainField[j][i] = 1;
					}
					break;
			}
		}
	}
		
		// ++++++ END +++++++++ Парсинг по Y +++++++++++++++++++++++
}

void drawByEmptyCells (int suppFieldX[60][20], int suppFieldY[40][20], int mainField[40][60], int xMap, int yMap)
{
	int i = 0, j = 0;
	int g = 0, g1 = 0, m = 0, h = 0, count = 0, ii = 0,jj = 0;
	int helpMainField[40][60] = {NULL};

	// +++++++++++++++++++++++++++++++++++++++++++++++ Парсинг по Х +++++++++++++++++

	for (i = 0; i < yMap; i++)						// переносим 5 на вспомагатнльное поле
		for (j = 0; j < xMap; j++)
			if (mainField[i][j] == 5) helpMainField[i][j] = 55;
	
	j = 0;


	for (i = 0; i < yMap; i++)
	{


		for (g = xMap-1; g >= 0; g--){
			if (helpMainField[i][g] == 0) {				//знайшло перший 0
				while (helpMainField[i][g-count] != 55) {	// порахувало скільки пустих клітинок
					count++;
					if (g-count < 0) break;
				}
			}
				if (count >= suppFieldY[i][j]){			// якщо пустих більше ніж число в доп. полі замальовуємо
					g1 = g;
					for (g; g > (g1 - suppFieldY[i][j]); g--) {
						helpMainField[i][g] = j+1;

					}
					if (suppFieldY[i][j+1] != 0) j++; else break;
					count = 0;
				}
				
			
		}


	count = 0;

		for (g = 0; g < xMap; g++){
			if (helpMainField[i][g] != 55) {				//знайшло перший 0
				while (helpMainField[i][g+count] != 55) {	// порахувало скільки пустих клітинок
					count++;
					if (g+count > xMap-1) break;
				}
			}
				if (count >= suppFieldY[i][j]){			// якщо пустих більше ніж число в доп. полі замальовуємо
					g1 = g;
					for (g; g < (g1 + suppFieldY[i][j]); g++) {
						if (helpMainField[i][g] == j+1) helpMainField[i][g] = 99;
					}
					count = 0;
					if (j > 0) j--; else break;
				}
		}
	j = 0;
	g = 0; g1 = 0; m = 0; h = 0; count = 0;


	}

/*	for (ii = 0; ii < yMap; ii++){
		for (jj = 0; jj < xMap; jj++){
			printf("%d ", helpMainField[ii][jj]);
		}
		printf("\n");
	}*/
	
	for (i = 0; i < yMap; i++){					// перевод с вспомагательного поля в главное
		for (j = 0; j < xMap; j++) {
			if ((helpMainField[i][j] == 99) && (mainField[i][j] == 0)) mainField[i][j] = 1;
		}
	}


	for (i = 0; i < yMap; i++)					// обнуляем вспомагательного поля
		for (j = 0; j < xMap; j++) 
			helpMainField[i][j] = 0;
	
	// ++++++++++++++++++++++++++ END +++++++++++++++++++++ Парсинг по Х +++++++++++++++++

	j = 0;
	g = 0; g1 = 0; m = 0; h = 0; count = 0;
	for (i = 0; i < yMap; i++)						// переносим 5 на вспомагатнльное поле
		for (j = 0; j < xMap; j++)
			if (mainField[i][j] == 5) helpMainField[i][j] = 55;


	// +++++++++++++++++++++++++++++++++++++++++++++++ Парсинг по Y +++++++++++++++++
	j = 0;
	
	for (i = 0; i < xMap; i++)
	{
		for (g = yMap-1; g >= 0; g--){
			if (helpMainField[g][i] == 0) {				//знайшло перший 0
				while (helpMainField[g-count][i] != 55) {	// порахувало скільки пустих клітинок
					count++;
					if (g-count < 0) break;
				}

			}
				if (count >= suppFieldX[i][j]){			// якщо пустих більше ніж число в доп. полі замальовуємо
					g1 = g;
					for (g; g > (g1 - suppFieldX[i][j]); g--) {
						helpMainField[g][i] = j+1;
					}
					if (suppFieldX[i][j+1] != 0) j++; else break;
					count = 0;
				}
				
			
		}


	count = 0;
		for (g = 0; g < yMap; g++){
			if (helpMainField[g][i] != 55) {				//знайшло перший 0
				while (helpMainField[g+count][i] != 55) {	// порахувало скільки пустих клітинок
					count++;
					if (g+count > yMap-1) break;
				}
			}
				if (count >= suppFieldX[i][j]){			// якщо пустих більше ніж число в доп. полі замальовуємо
					g1 = g;
					for (g; g < (g1 + suppFieldX[i][j]); g++) {
						if (helpMainField[g][i] == j+1) helpMainField[g][i] = 99;
					}
					count = 0;
					if (j > 0) j--; else break;
				}
		}
	j = 0;
	g = 0; g1 = 0; m = 0; h = 0; count = 0;
	}
	
	for (i = 0; i < yMap; i++){					// перевод с вспомагательного поля в главное
		for (j = 0; j < xMap; j++) {
			if ((helpMainField[i][j] == 99) && (mainField[i][j] == 0)) mainField[i][j] = 1;
		}
	}


	for (i = 0; i < yMap; i++)					// обнуляем вспомагательного поля
		for (j = 0; j < xMap; j++) 
			helpMainField[i][j] = 0;


	// ++++++++++++++++++++++++++ END +++++++++++++++++++++ Парсинг по Y +++++++++++++++++

	
}

void firstDrawDecide (int suppFieldX[60][20], int suppFieldY[40][20], int mainField[40][60], int xMap, int yMap)
{
	int i = 0, j = 0;
	int g = 0, m = 0, h = 0, count = xMap-1;;
	int helpMainField[40][60] = {NULL};
	for (h = 0; h<yMap; h++){
		count = xMap-1;
		j = 0; i = 0; m = 0; g = 0;
	for (i = 0; i<xMap; i++){

		while (suppFieldY[h][j] != 0) {
			
			for (g = 0; g < suppFieldY[h][j]; g++) {
				helpMainField[h][count] = j+1;
				count--;
			}
			j++;
			count--;
		}
		count = 0;
		for (g = j-1; g >= 0; g--){

			for (m = 0; m < suppFieldY[h][g]; m++) {
				
				if (helpMainField[h][count] == g+1) helpMainField[h][count] = 99;
				count++;
			}
			count ++;
		}
	}
	}
	getchar();

	//++++++++++++++++++++++++++++ проверка на 9-ки+++++++
	for (i = 0; i < yMap; i++)
		for (j = 0; j < xMap; j++)
			if ((helpMainField[i][j] == 99) && (mainField[i][j] == 0)) {
				mainField[i][j] = 1; 
				helpMainField[i][j] = 0;
			} else helpMainField[i][j] = 0;
	// END ++++++++++++++++++++++++ проверка на 9-ки


	for (h = 0; h<xMap; h++){
		count = yMap-1;
		j = 0; i = 0; m = 0; g = 0;
	for (i = 0; i<yMap; i++){

		while (suppFieldX[h][j] != 0) {
			
			for (g = 0; g < suppFieldX[h][j]; g++) {
				helpMainField[count][h] = j+1;
				count--;
			}
			j++;
			count--;
		}
		count = 0;
		for (g = j-1; g >= 0; g--){

			for (m = 0; m < suppFieldX[h][g]; m++) {
				
				if (helpMainField[count][h] == g+1) helpMainField[count][h] = 99;
				count++;
			}
			count ++;
		}
	}
	}

	//++++++++++++++++++++++++++++ проверка на 9-ки+++++++
	for (i = 0; i < yMap; i++)
		for (j = 0; j < xMap; j++)
			if ((helpMainField[i][j] == 99) && (mainField[i][j] == 0)) mainField[i][j] = 1; else helpMainField[i][j] = 0;
	// END ++++++++++++++++++++++++ проверка на 9-ки
	
}
