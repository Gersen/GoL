#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define X 10
#define Y 45


/************** Variables globales ****************
*                                                  *
***************************************************/


int rdtsc(){
	__asm__ __volatile__("rdtsc"); /*base rdtsc sur la frequence du CPU (time stamp)*/

}
int Origin_Cells[X][Y];


/***************** PROTOTYPES***********************
*                                                  *
***************************************************/


void Random_Cells(int Size_Row,  int Size_col, int Origin_Cells[Size_Row][Size_col]  );
void Affichage_Tab(int Size_Row, int Size_col, int Origin_Cells[Size_Row][Size_col] );


/************** DECLARATION DU MAIN****************
*                                                  *
***************************************************/

int main(void)
{
	int i,j;
	
	 Random_Cells(X,Y,Origin_Cells);

	 Affichage_Tab(X,Y,Origin_Cells);
	
	
	

	return 0;
}

/* Fonction de mise en place du tableau de façon aléatoire, qui renvoit à Origin_Cells en variable globale */

void Random_Cells(int Size_Row,  int Size_col, int Origin_Cells[Size_Row][Size_col] ) {
	int i, j;
	for(i = 0; i < Size_Row; i++) {
		for(j = 0; j < Size_col; j++) {
			
			if( i == (Size_Row -1) ||i == 0 || j == 0 || j == (Size_col -1)) { /* on délimite les bordures du tableau */
				Origin_Cells[i][j] = -1;
			} else {
				srand(rdtsc()); /*fonction srand basé sur la fréquence du processeur*/
				Origin_Cells[i][j]= rand()% 2; /* utilisation modulo partie restante 0 ou 1 */
				
			}
			 
		}
	}
	
}
	
/********************Fonction d'affichage*************************/

void Affichage_Tab(int Size_Row, int Size_col, int Origin_Cells[Size_Row][Size_col]){
	int i,j;

		for(i=0; i< Size_Row; i++){
			for (j = 0; j < Size_col; j++)
			{
				switch(Origin_Cells[i][j]){ /* utilisation de putchar pour afficher en stdout */

					case -1 : putchar('#');
					break;
					case 0 : putchar(' ');
					break;
					case 1 : putchar('+');
					break;

					default: break;
				}
			}
			putchar('\n'); /*permet de sauter à la ligne a la fin de chq itération*/
		}

}


