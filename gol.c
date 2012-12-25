#include <stdio.h>
#include <stdlib.h>

#define X 15
#define Y 40
/*=================================================
*				Protypes						  *
*=================================================*/
void Aleatoire_Tab (int tab[][Y], int Size_X, int Size_Y);
void Reset_tab (int tab[][Y],int Size_X, int Size_Y);
void Affiche_Tab (int tab[][Y], int Size_X, int Size_Y);


/************** DECLARATION DU MAIN****************
*                                                  *
***************************************************/

int main(int argc, char **argv)
{
	int Origin_tab[X][Y];
	char c =' '; 

	//for (i = 0; i <  sizeof(Origin_tab) / sizeof(Origin_tab[0]); i++)  //Calcul taille du tableau par sizeof
	Aleatoire_Tab(Origin_tab,X,Y);
	Affiche_Tab(Origin_tab,X,Y);
	sleep(10);
	

	puts ("Voullez vous remettre le tableau à zero ? O ou N ");
	scanf("%c", &c);
	if (c == 'O'){
			Reset_tab(Origin_tab,X,Y);

			Affiche_Tab(Origin_tab,X,Y);
	}



	return 0;
}

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

	for (i = 0; i <  Size_X ; i++)  //Calcul taille du tableau par sizeof
	{
		for (j = 0; j < Size_Y; j++)
		{
			
			printf("tableau index i : %d   | \t  index j: %d   | \t valeur: %d \n",i,j,tab[i][j] );
		}
	}
}

void Reset_tab (int tab[][Y],int Size_X, int Size_Y){  //Fonction de remise à zero

	int i,j;
	for (i = 0; i < Size_X ; i++)
	{
		for (j = 0; j < Size_Y ; j++)
		{
			tab[i][j]= 0;

			
		}
	}

}
