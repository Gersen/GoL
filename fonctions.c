#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>



int Origin_Cells(int Size_Row,  int Size_col, int tab_cells[Size_Row][Size_col] ) {
	int i, j,NbrCell;
	for(i = 0; i < Size_Row; i++) {
		for(j = 0; j < Size_col; j++) {
			
			if( i == (Size_Row -1) ||i == 0 || j == 0 || j == (Size_col -1)) { /* on délimite les bordures du tableau */
				tab_cells[i][j] = -1;
			} else {

				tab_cells[i][j]= rand()% 2; /* utilisation modulo partie restante 0 ou 1 */

				if (tab_cells[i][j] == 1){ /* Si valeur 1 on augmente la population de 1 */
					NbrCell++;
				}
				
			}
			 
		}
	}
	return NbrCell;
}










	/*void Aleatoire_Tab (char tab[][Y], int Size_X, int Size_Y){
	int i,j;

	for (i = 0; i <  Size_X ; i++)  //Calcul taille du tableau par sizeof
	{
		for (j = 0; j < Size_Y; j++)
		{
			
			tab[i][j]= rand()% (1-0+1);
		}
	}
	}





void Affiche_Tab (char tab[][Y], int Size_X, int Size_Y){
	int i,j;

	for (i = 0; i <  Size_X ; i++)  
	{
		for (j = 0; j < Size_Y; j++)
		{
			
			printf("tableau index i : %d   | \t  index j: %d   | \t valeur: %d \n",i,j,tab[i][j] );
		}
	}
}

void Reset_tab (char tab[][Y],int Size_X, int Size_Y){ 

	int i,j;
	for (i = 0; i < Size_X ; i++)
	{
		for (j = 0; j < Size_Y ; j++)
		{
			tab[i][j]= 0;

			
		}
	}

}*/