#include "header.h"

void checkFromEdgeField (int suppFieldX[60][20], int suppFieldY[40][20], int mainField[40][60], int xMap, int yMap)
{
	int i = 0, j = 0, g = 0, m = 0, sum9 = 0, sumLine = 0, count = 0, countFullCell = 0, countLastCell = 0;
	int helpMainField[40][60] = {NULL};
	bool flag = false, flag0 = false;

	// +++++++++++++++ Парсинг по Х +++++++++++++++++++++++
		for (i = 0; i < yMap; i++){
			countLastCell = 0;
			countFullCell = 0;
			m = 0;
			for (j = xMap-1; j >=0; j--){
				if (mainField[i][j] != 0) m++;
				if (mainField[i][j] == 0) {
					if (mainField[i][xMap - m-1] == 5) break;
					// рахуємо кількість блоків заповнених клітинок
						for (j = xMap - 1; j >= xMap - m; j--){
							if ((j == xMap - 1) && (mainField[i][j] == 1)) countFullCell++;
							if ((j != xMap - 1) && (mainField[i][j+1] == 5) && (mainField[i][j] == 1)) countFullCell++;
						}
						g = m;
						if (countFullCell == 0) break;
					// рахуємо кількість заповнених клітинок у осанньому блоці
						while ((mainField[i][xMap - m] != 5)){
							m--;
							if (m < 0) break;
							countLastCell++;
						}
						if (suppFieldY[i][countFullCell-1] == countLastCell) mainField[i][xMap - g-1] = 5;
						break;
				}
			}
		}

		for (i = 0; i < yMap; i++){
			countLastCell = 0;
			countFullCell = 0;
			m = 0;
			count = 0;
			while (suppFieldY[i][count] != 0) count++;
			for (j = 0; j < xMap; j++){
				if (mainField[i][j] != 0) m++;
				if (mainField[i][j] == 0) {
					if (mainField[i][m] == 5) break;
					// рахуємо кількість блоків заповнених клітинок
						for (j = 0; j < m; j++){
							if ((j == 0) && (mainField[i][j] == 1)) countFullCell++;
							if ((j != 0) && (mainField[i][j-1] == 5) && (mainField[i][j] == 1)) countFullCell++;
						}
						g = m;
						if (countFullCell == 0) break;
					// рахуємо кількість заповнених клітинок у осанньому блоці
						while ((mainField[i][m] != 5)){
							m--;
							countLastCell++;
							if (m < 0) break;
						}
						if (suppFieldY[i][count - countFullCell] == countLastCell-1) mainField[i][g] = 5;
						break;
				}
			}
		}


	// ++++++ END +++++++++ Парсинг по Х +++++++++++++++++++++++

	// +++++++++++++++ Парсинг по Y +++++++++++++++++++++++
		for (i = 0; i < xMap; i++){
			countLastCell = 0;
			countFullCell = 0;
			m = 0;
			for (j = yMap-1; j >=0; j--){
				if (mainField[j][i] != 0) m++;
				if (mainField[j][i] == 0) {
					if (mainField[yMap - m-1][i] == 5) break;
					// рахуємо кількість блоків заповнених клітинок
						for (j = yMap - 1; j >= yMap - m; j--){
							if ((j == yMap - 1) && (mainField[j][i] == 1)) countFullCell++;
							if ((j != yMap - 1) && (mainField[j+1][i] == 5) && (mainField[j][i] == 1)) countFullCell++;
						}
						g = m;
						if (countFullCell == 0) break;
					// рахуємо кількість заповнених клітинок у осанньому блоці
						while ((mainField[yMap - m][i] != 5)){
							m--;
							if (m < 0) break;
							countLastCell++;
						}
						if (suppFieldX[i][countFullCell-1] == countLastCell) mainField[yMap - g-1][i] = 5;
						break;
				}
			}
		}

		for (i = 0; i < xMap; i++){
			countLastCell = 0;
			countFullCell = 0;
			m = 0;
			count = 0;
			while (suppFieldX[i][count] != 0) count++;
			for (j = 0; j < yMap; j++){
				if (mainField[j][i] != 0) m++;
				if (mainField[j][i] == 0) {
					if (mainField[m][i] == 5) break;
					// рахуємо кількість блоків заповнених клітинок
						for (j = 0; j < m; j++){
							if ((j == 0) && (mainField[j][i] == 1)) countFullCell++;
							if ((j != 0) && (mainField[j-1][i] == 5) && (mainField[j][i] == 1)) countFullCell++;
						}
						g = m;
						if (countFullCell == 0) break;
					// рахуємо кількість заповнених клітинок у осанньому блоці
						while ((mainField[m][i] != 5)){
							m--;
							countLastCell++;
							if (m < 0) break;
						}
						if (suppFieldX[i][count - countFullCell] == countLastCell-1) mainField[g][i] = 5;
						break;
				}
			}
		}
		
		// ++++++ END +++++++++ Парсинг по Y +++++++++++++++++++++++


}

void checkEmptyFields(int suppFieldX[60][20], int suppFieldY[40][20], int mainField[40][60], int xMap, int yMap)
{
	int i = 0, j = 0, g = 0, m = 0, sum9 = 0, sumLine = 0, count = 0;
	int helpMainField[40][60] = {NULL};
	int ii = 0, jj = 0;
	int max = 0, min = 100;

	for (i = 0; i < yMap; i++)
		for (j = 0; j < xMap; j++)
			if (mainField[i][j] == 5) helpMainField[i][j] = 55;
	j = 0;
		
	//++++++++++++++++++ парсим по Х +++++++++++++++++++++++++
	for (i = 0; i < yMap; i++) {
	while (suppFieldY[i][j] != 0) {				// знаходимо найменше значення доп. поля
		if (min > suppFieldY[i][j]) min = suppFieldY[i][j];
		j++;
	}
	//printf("MinSuppFieldY[%d][%d] = %d\n", i, j, min);


	for (g = xMap-1; g >= 0; g--){
			if (helpMainField[i][g] == 0) {		//знайшло перший 0
				count = 0;
				while (helpMainField[i][g-count] != 55) {	// порахувало скільки пустих клітинок
					count++;
					if (g-count < 0) break;
				}
				if (min > count) {
					count = 0;
					while (helpMainField[i][g-count] != 55){
						if (g-count < 0) break;
						helpMainField[i][g-count] = 55;
						if (mainField[i][g-count] == 0) mainField[i][g-count] = 5;
						count++;
					} 
				} else g = g-count;
			}
	}

	count = 0; g = 0; j = 0; min = 100;



	}
	//+++++++ END +++++++++++ парсим по Х +++++++++++++++++++++++++
	
	//++++++++++++++++++ парсим по Y +++++++++++++++++++++++++
	for (i = 0; i < xMap; i++) {
	while (suppFieldX[i][j] != 0) {				// знаходимо найменше значення доп. поля
		if (min > suppFieldX[i][j]) min = suppFieldX[i][j];
		j++;
	}
	//printf("MinSuppFieldY[%d][%d] = %d\n", i, j, min);


	for (g = yMap-1; g >= 0; g--){
			if (helpMainField[g][i] == 0) {		//знайшло перший 0
				count = 0;
				while (helpMainField[g-count][i] != 55) {	// порахувало скільки пустих клітинок
					count++;
					if (g-count < 0) break;
				}
				if (min > count) {
					count = 0;
					while (helpMainField[g-count][i] != 55){
						if (g-count < 0) break;
						helpMainField[g-count][i] = 55;
						if (mainField[g-count][i] == 0) mainField[g-count][i] = 5;
						count++;
					} 
				} else g = g-count;
			}
	}
	/*for (ii = 0; ii < yMap; ii++){
			for (jj = 0; jj < xMap; jj++){
				printf("%d ", helpMainField[ii][jj]);
			}
			printf("\n");
		}
	getchar();*/
	count = 0; g = 0; j = 0; min = 100;
	}	
	//++++++ END ++++++++++++ парсим по Y +++++++++++++++++++++++++


}

void checkPoint_elements (int suppFieldX[60][20], int suppFieldY[40][20], int mainField[40][60], int xMap, int yMap)
{
	int i = 0, j = 0, g = 0, m = 0, sum9 = 0, sumLine = 0, count = 0;
	int helpMainField[40][60] = {NULL};
	int ii = 0, jj = 0;
	bool flag = false, flag99 = false;
	int count99 = 0, count98 = 0;
	

	//+++++++++ Чек по елементам по X +++++++++++++++
	for (i = 0; i < yMap; i++)
	{

	while (suppFieldY[i][sumLine] != 0) {		// узнаем какое количество цифр в циферном поле
		sumLine++;
	}

	for (j = xMap; j >= 0; j--)			// узнем сколько зарисованых, отдельно-стоящих блоков в нашей линии
	{
		if ((mainField[i][j] == 1) && (j == xMap-1)) sum9++; 
		if ((mainField[i][j] == 1) && ((mainField[i][j+1] == 0) || (mainField[i][j+1] == 5)) && (j<xMap-1)) sum9++;
		
	}
//	printf("sum9 = %d, sumLine = %d\n", sum9, sumLine);
//	getchar();
	if (sumLine == sum9) {				// зарисовываем вспомагательные поля 9
		for (j = xMap-1; j >= 0; j--){

			if ((mainField[i][j] == 1) && (j == xMap-1)) {
				for (g = 0; g < suppFieldY[i][m]; g++) {
					if ((j-g >= 0) && (j-g < xMap) && (mainField[i][j-g] != 5)) helpMainField[i][j-g] = 99;
					if (mainField[i][j-g] == 5) g = 100;
				}
				if (suppFieldY[i][m] == 1) m++;

			}
			if ((mainField[i][j] == 1) && (j == 0)) {
				for (g = 0; g < suppFieldY[i][m]; g++) {
					if ((j+g >= 0) && (j+g < xMap) && (mainField[i][j+g] != 5)) helpMainField[i][j+g] = 99;
					if (mainField[i][j+g] == 5) g = 100;
				}
			}
			if ((mainField[i][j] == 1) && ((mainField[i][j+1] == 0) || (mainField[i][j+1] == 5)) && (j!=0) && (j!=xMap-1)) {
				for (g = 0; g < suppFieldY[i][m]; g++) {
					if ((j-g >= 0) && (j-g < xMap) && (mainField[i][j-g] != 5)) helpMainField[i][j-g] = 99;
					if (mainField[i][j-g] == 5) g = 100;
				}
			}

			if ((mainField[i][j] == 1) && ((mainField[i][j-1] == 0) || (mainField[i][j-1] == 5)) &&
				((mainField[i][j+1] == 0) || (mainField[i][j+1] == 5)) && (j!=0) && (j!=xMap-1)) {
				for (g = 0; g < suppFieldY[i][m]; g++) {
					if ((j+g >= 0) && (j+g < xMap) && (mainField[i][j+g] != 5)) helpMainField[i][j+g] = 99;
					if (mainField[i][j+g] == 5) g = 100;
				}
				for (g = 0; g < suppFieldY[i][m]; g++) {
					if ((j-g >= 0) && (j-g < xMap) && (mainField[i][j-g] != 5)) helpMainField[i][j-g] = 99;
					if (mainField[i][j-g] == 5) g = 100;
				}
				if (suppFieldY[i][m+1]!= 0) m++;
				flag = true;
			}


			if ((mainField[i][j] == 1) && ((mainField[i][j-1] == 0) || (mainField[i][j-1] == 5)) 
				&& (j!=0) && (j!=xMap-1) && (flag == false)) {
				for (g = 0; g < suppFieldY[i][m]; g++) {
					if ((j+g >= 0) && (j+g < xMap) && (mainField[i][j+g] != 5)) {
						helpMainField[i][j+g] = 99;
					}
					if (mainField[i][j+g] == 5) g = 100;
				}
			if (suppFieldY[i][m+1]!= 0){
				m++;
				count99 = 0;
				for (g = 0; g < xMap; g++) count99 = count99+helpMainField[i][g];
			}

			}


			flag = false;

		}

		count98 = 0;
		for (g = 0; g < xMap; g++) count98 = count98 + helpMainField[i][g];
		if (count99 == count98) continue;

		flag99 = true;
		for (g = 0; g < xMap; g++) {
			if (mainField[i][g] == 1)
				if (helpMainField[i][g] != 99) flag99 = false;
		}

		if (flag99 == false) continue;

		sum9 = 0;
			for (j = xMap-1; j >= 0; j--)			// узнем сколько зарисованых, отдельно-стоящих блоков в нашей линии
			{
				if ((helpMainField[i][j] == 99) && (j == xMap-1)) sum9++;
				if ((helpMainField[i][j] == 99) && (helpMainField[i][j+1] == 0) && (j<xMap-1)) sum9++;
			}
		if (sum9 == sumLine){					// зарисовываем наверника пустые ячейки
			for (j = 0; j < xMap; j++){
				if ((helpMainField[i][j] == 0) && (mainField[i][j] == 0)) mainField[i][j] = 5;
			}
		}
	} 
	sum9 = 0;
	sumLine = 0;
	m = 0;

	if (error(mainField, helphelpField, xMap, yMap) == 0) {
		printf("ERROR X m = %d\n", m);
		printf("suppFieldY[%d][%d] = %d\n",i, m, suppFieldY[i][m]);
		printf("count99 = %d", count99);
	for (ii = 0; ii < yMap; ii++){
			for (jj = 0; jj < xMap; jj++){
				if (helpMainField[ii][jj] == 99) printf("X ");
				else printf("%d ", helpMainField[ii][jj]);
			}
			printf("\n");
		}
	getchar();
	}


	}
	// END +++++++++ Чек по елементам по X +++++++++++++++


	// обнуляем вспомагательный Главному масиву масив
	for (i = 0; i < yMap; i++)
		for (j = 0; j < xMap; j++)
			helpMainField[i][j] = 0;
	//END обнуляем вспомагательный Главному масиву масив
	j = 0;
	//+++++++++ Чек по елементам по Y +++++++++++++++
	for (i = 0; i < xMap; i++)
	{
//	printf("sum9 = %d, sumLine = %d", sum9, sumLine);
//	getchar();

/*	for (ii = 0; ii < yMap; ii++){
			for (jj = 0; jj < xMap; jj++){
				printf("%d ", mainField[ii][jj]);
			}
			printf("\n");
		}
	getchar();
*/
	while (suppFieldX[i][sumLine] != 0) {		// узнаем какое количество цифр в циферном поле
		sumLine++;
	}

	for (j = yMap-1; j >= 0; j--)			// узнем сколько зарисованых, отдельно-стоящих блоков в нашем столбце
	{
		if ((mainField[j][i] == 1) && (j == yMap-1)) sum9++;
		if ((mainField[j][i] == 1) && ((mainField[j+1][i] == 0) || (mainField[j+1][i] == 5)) && (j>=0) && (j < yMap-1)) sum9++;
	}

	//printf("sum9 = %d, sumLine = %d", sum9, sumLine);
	//getchar();
	if (sumLine == sum9) {				// зарисовываем вспомагательные поля 9
		for (j = yMap-1; j >= 0; j--){

			if ((mainField[j][i] == 1) && (j == yMap-1)) {
				for (g = 0; g < suppFieldX[i][m]; g++) {
					if ((j-g >= 0) && (j-g < yMap) && (mainField[j-g][i] != 5)) helpMainField[j-g][i] = 99;
					if (mainField[j-g][i] == 5) g = 100;
				}
				if (suppFieldX[i][m] == 1) m++;
			}
			if ((mainField[j][i] == 1) && (j == 0)) {
				for (g = 0; g < suppFieldX[i][m]; g++) {
					if ((j+g >= 0) && (j+g < yMap) && (mainField[j+g][i] != 5)) helpMainField[j+g][i] = 99;
					if (mainField[j+g][i] == 5) g = 100;
				}
			}
			if ((mainField[j][i] == 1) && ((mainField[j+1][i] == 0) || (mainField[j+1][i] == 5)) && (j!=0) && (j!=yMap-1)) {
				for (g = 0; g < suppFieldX[i][m]; g++) {
					if ((j-g >= 0) && (j-g < yMap) && (mainField[j-g][i] != 5)) helpMainField[j-g][i] = 99;
					if (mainField[j-g][i] == 5) g = 100;
				}
			}


			if ((mainField[j][i] == 1) && ((mainField[j-1][i] == 0) || (mainField[j-1][i] == 5)) &&
				((mainField[j+1][i] == 0) || (mainField[j+1][i] == 5)) && (j!=0) && (j!=yMap-1)) {
				for (g = 0; g < suppFieldX[i][m]; g++) {
					if ((j+g >= 0) && (j+g < yMap) && (mainField[j+g][i] != 5)) helpMainField[j+g][i] = 99;
					if (mainField[j+g][i] == 5) g = 100;
				}
				for (g = 0; g < suppFieldX[i][m]; g++) {
					if ((j-g >= 0) && (j-g < yMap) && (mainField[j-g][i] != 5)) helpMainField[j-g][i] = 99;
					if (mainField[j-g][i] == 5) g = 100;
				}
				if (suppFieldX[i][m+1]!= 0) m++;

				flag = true;
			}

			if ((mainField[j][i] == 1) && ((mainField[j-1][i] == 0) || (mainField[j-1][i] == 5)) 
				&& (j!=0) && (j!=yMap-1) && (flag == false)) {
				for (g = 0; g < suppFieldX[i][m]; g++) {
					if ((j+g >= 0) && (j+g < yMap) && (mainField[j+g][i] != 5)) {
						helpMainField[j+g][i] = 99;
					}
					if (mainField[j+g][i] == 5) g = 100;
				}
			if (suppFieldX[i][m+1]!= 0) {
				m++;
				count99 = 0;
				for (g = 0; g < yMap; g++) count99 = count99+helpMainField[g][i];
			}
			}

			flag = false;
/*	if ((i == 9) && (error(mainField, helphelpField, xMap, yMap) == 0)) {
		printf("m = %d\n", m);
		printf("suppFieldX[%d][%d] = %d\n",i, m, suppFieldX[i][m]);
	for (ii = 0; ii < yMap; ii++){
			for (jj = 0; jj < xMap; jj++){
				if (helpMainField[ii][jj] == 99) printf("X ");
				else printf("%d ", helpMainField[ii][jj]);
			}
			printf("\n");
		}
	getchar();
	}*/

		}

		count98 = 0;
		for (g = 0; g < yMap; g++) count98 = count98 + helpMainField[g][i];
		if (count99 == count98) continue;

		flag99 = true;
		for (g = 0; g < yMap; g++) {
			if (mainField[g][i] == 1)
				if (helpMainField[g][i] != 99) flag99 = false;
		}

		if (flag99 == false) continue;

		sum9 = 0;
			for (j = yMap; j >= 0; j--)			// узнем сколько зарисованых, отдельно-стоящих блоков в нашей линии
			{
				if ((helpMainField[j][i] == 99) && (j == yMap-1)) sum9++;
				if ((helpMainField[j][i] == 99) && (helpMainField[j+1][i] == 0) && (j<yMap-1)) sum9++;
			}
		if (sum9 == sumLine){					// зарисовываем наверника пустые ячейки
			for (j = 0; j < yMap; j++){
				if ((helpMainField[j][i] == 0) && (mainField[j][i] == 0)) mainField[j][i] = 5;
			}
		}
	} 

	if (error(mainField, helphelpField, xMap, yMap) == 0) {
		printf("ERROR Y m = %d\n", m);
		printf("suppFieldX[%d][%d] = %d\n",i, m, suppFieldX[i][m]);
	for (ii = 0; ii < yMap; ii++){
			for (jj = 0; jj < xMap; jj++){
				if (helpMainField[ii][jj] == 99) printf("X ");
				else printf("%d ", helpMainField[ii][jj]);
			}
			printf("\n");
		}
	getchar();
	}

	sum9 = 0;
	sumLine = 0;
	m = 0;
	}
	// END +++++++++ Чек по елементам по Y +++++++++++++++
}

void checkPoint_100 (int suppFieldX[60][20], int suppFieldY[40][20], int mainField[40][60], int xMap, int yMap)
{
	int i = 0, j = 0, g = 0, m = 0, sum9 = 0, sumLine = 0, count = 0;

	// +++++++ Чек на 100% по Х ++++++++
	for (i = 0; i < yMap; i++) {
			while (suppFieldY[i][g] != 0) {
				sumLine = sumLine + suppFieldY[i][g];
				g++;
			}
			for (m = 0; m < xMap; m++){
				if (mainField[i][m] == 1) sum9++;
			}
			if (sumLine == sum9) {
				for (m = 0; m < xMap; m++) {
					if (mainField[i][m] == 0) mainField[i][m] = 5;
				}

			}
	sumLine = 0; 
	sum9 = 0;
	g = 0;
	}	
	// END +++++++ Чек на 100% по Х ++++++++

	// +++++++ Чек на 100% по У ++++++++
	for (i = 0; i < xMap; i++) {
			while (suppFieldX[i][g] != 0) {
				sumLine = sumLine + suppFieldX[i][g];
				g++;
			}
			for (m = 0; m < yMap; m++){
				if (mainField[m][i] == 1) sum9++;
			}
			if (sumLine == sum9) {
				for (m = 0; m < yMap; m++) {
					if (mainField[m][i] == 0) mainField[m][i] = 5;
				}

			}
	sumLine = 0; 
	sum9 = 0;
	g = 0;
	}	
	// END +++++++ Чек на 100% по У ++++++++

}
