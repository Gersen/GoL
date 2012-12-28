#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define X 15
#define Y 45


/************** Variables globales ****************
*                                                  *
***************************************************/


int rdtsc(){
	__asm__ __volatile__("rdtsc"); /*base rdtsc sur la frequence du CPU (time stamp)*/

}
int Origin_Cells[X][Y];
int buffer[X][Y];


/***************** PROTOTYPES***********************
*                                                  *
***************************************************/


void Random_Cells(int Size_Row,  int Size_Col, int Origin_Cells[Size_Row][Size_Col]  );
void Affichage_Tab(int Size_Row, int Size_Col, int Origin_Cells[Size_Row][Size_Col] );
void GenerationCells (int Size_Row, int Size_Col, int Origin_Cells[Size_Row][Size_Col]);
int CountNeigh(int a, int b, int Size_Row,int Size_Col, int CurrentCell[Size_Row][Size_Col]);


/************** DECLARATION DU MAIN****************
*                                                  *
***************************************************/

int main(void)
{
	int i,j;
	
	 Random_Cells(X,Y,Origin_Cells);
	 Affichage_Tab(X,Y,Origin_Cells);
	 
	 for(i=0;i<15;i++){
	 	sleep(2);
	 	GenerationCells(X,Y,Origin_Cells);
	 	Affichage_Tab(X,Y,Origin_Cells);
	 }
	
	return 0;
}


/*********************FIN DU MAIN*******************
*                                                  *
***************************************************/

/* Fonction de mise en place du tableau de façon aléatoire, qui renvoit à Origin_Cells en variable globale */

void Random_Cells(int Size_Row,  int Size_Col, int Origin_Cells[Size_Row][Size_Col] ) {
	int i, j;
	for(i = 0; i < Size_Row; i++) {
		for(j = 0; j < Size_Col; j++) {
			
			if( i == (Size_Row -1) ||i == 0 || j == 0 || j == (Size_Col -1)) { /* on délimite les bordures du tableau */
				Origin_Cells[i][j] = -1;
			} else {
				srand(rdtsc()); /*fonction srand basé sur la fréquence du processeur*/
				Origin_Cells[i][j]= rand()% 2; /* utilisation modulo partie restante 0 ou 1 */
				
			}
			 
		}
	}
	
}
	
/********************Fonction d'affichage*************************/

void Affichage_Tab(int Size_Row, int Size_Col, int Origin_Cells[Size_Row][Size_Col]){
	int i,j;
	system("clear");
		for(i=0; i< Size_Row; i++){
			for (j = 0; j < Size_Col; j++)
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

/******************************Generation des cellules*************************************************************************/
/* 
* objectif : il faut vérifier les voisins en fonctions de la cellule courante (CurrentCell)
	déterminer si une cellule qui est morte (donc = 0) si elle a au moins 3 voisins NeighCell (pour Neighbor Cell)
	alors elle devient vivante.
	et si une cellule qui est en vie il faut déterminer si elle reste en vie ou si elle meurt 
		reste en vie (CurrentCell =1) si a au moins deux ou trois voisins au dela ou en deça elle meurt de surpopulation ou d'isolement.
		******************************************************************************************************************************/

void GenerationCells (int Size_Row, int Size_Col, int Origin_Cells[Size_Row][Size_Col]){

	int i,j, NeighCell;

	for (i = 0; i < Size_Row ; i++){

		for ( j = 0; j < Size_Col; j++)
		{
			if (Origin_Cells[i][j]== -1) continue; /*permet de reboucler directement.*/
			NeighCell = CountNeigh(i,j,Size_Row,Size_Col,Origin_Cells);
			if ((Origin_Cells[i][j] == 1) && (NeighCell<2 || NeighCell >3 )){
				buffer[i][j]= 0;
				}else if(Origin_Cells [i][j]== 0 && NeighCell==3){
					buffer[i][j]= 1;
				}
			
		}
	}
for (i = 0; i < Size_Row ; i++)
	{
		for ( j = 0; j < Size_Col; j++)
		{
			if (Origin_Cells[i][j]== -1) continue; /*permet de reboucler directement.*/
			Origin_Cells[i][j]= buffer[i][j];
			
		}
	}
}
/* Difficulté comment trouver les voisins ??
	exemple avec i=1 et j=1 sur un tableau de 3/3
			j=0 j=1 j=2
		i=0 [ ] [ ] [ ]
		i=1 [ ] [X] [ ]
		i=2 [ ] [ ] [ ]

		Dans ce cas il faut analyser i et j -1 et i et j +1.
	Donc à partir de la cellule courante Origin_Cells verfier toutes les -1 et +1 cellules et les comptabiliser
	il faut donc envoyer la taille de note tableau initial à la fonction
*/
int CountNeigh(int a, int b, int Size_Row,int Size_Col, int CurrentCell[Size_Row][Size_Col]){
	int i,j, k=0;

	for (i = a-1; i <= a+1; i++)  /* a-1 pour commencer aux cellules inf jusqu à a+1 pour les cellules sup*/
	{
		for (j = b-1 ; j <= b+1 ; j++)
		{	
			if (i== a && j == b ) continue;
			if(CurrentCell[i][j]==1){
				k++;
			}
		}
	}
	
	return k;
}




		


