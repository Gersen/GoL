#include <stdio.h>
#include <stdlib.h>

#define X 15
#define Y 40



	void Aleatoire_Tab (int tab[][Y], int Size_X, int Size_Y){
	int i,j;

	for (i = 0; i <  Size_X ; i++)  //Calcul taille du tableau par sizeof
	{
		for (j = 0; j < Size_Y; j++)
		{
			
			tab[i][j]= rand()% (1-0+1);
		}
	}
	}


	


void Affiche_Tab (int tab[][Y], int Size_X, int Size_Y){
	int i,j;

	for (i = 0; i <  Size_X ; i++)  
	{
		for (j = 0; j < Size_Y; j++)
		{
			
			printf("tableau index i : %d   | \t  index j: %d   | \t valeur: %d \n",i,j,tab[i][j] );
		}
	}
}

void Reset_tab (int tab[][Y],int Size_X, int Size_Y){ 

	int i,j;
	for (i = 0; i < Size_X ; i++)
	{
		for (j = 0; j < Size_Y ; j++)
		{
			tab[i][j]= 0;

			
		}
	}

}