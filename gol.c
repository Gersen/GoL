#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define X 15
#define Y 40


/************** Variables globales ****************
*                                                  *
***************************************************/

int NbrCell = 0;

int rdtsc(){
	__asm__ __volatile__("rdtsc");
}



void Origin_Cells(int Size_Row,  int Size_col, int tab_cells[Size_Row][Size_col]  );


/************** DECLARATION DU MAIN****************
*                                                  *
***************************************************/

int main(void)
{
	
	int Origin_tab[X][Y];
	Origin_Cells(X,Y,Origin_tab);
	
	printf("%d \n", NbrCell  );
	
	

	return 0;
}


void Origin_Cells(int Size_Row,  int Size_col, int tab_cells[Size_Row][Size_col] ) {
	int i, j;
	for(i = 0; i < Size_Row; i++) {
		for(j = 0; j < Size_col; j++) {
			
			if( i == (Size_Row -1) ||i == 0 || j == 0 || j == (Size_col -1)) { /* on délimite les bordures du tableau */
				tab_cells[i][j] = -1;
			} else {
				srand(rdtsc()); /*fonction srand basé sur la fréquence du processeur*/
				tab_cells[i][j]= rand()% 2; /* utilisation modulo partie restante 0 ou 1 */

				if (tab_cells[i][j] == 1){ /* Si valeur 1 on augmente la population de 1 */
					NbrCell++;
				}
				
			}
			 
		}
	}
	
}
	



