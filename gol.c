#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Row 7
#define Col 8


/************** Variables globales ****************
*                                                  *
***************************************************/


int rdtsc(){
	__asm__ __volatile__("rdtsc"); /*base rdtsc sur la frequence du CPU (time stamp)*/

}
int init[Row][Col];
int buffer[Row][Col];


/***************** PROTOTYPES***********************
*                                                  *
***************************************************/


void beginGame(int init[Row][Col]);
void Affichage_Tab(int init[Row][Col] );
void GenerationCells (int init[Row][Col]);
int CountNeigh(int a, int b,int CurrentCell[Row][Col]);
void Random_Cells(int Origin_Cells[Row][Col] );

/************** DECLARATION DU MAIN****************
*                                                  *
***************************************************/

int main(void)
{
	int i,j;
	init[2][2]= 1;
	init[2][3]= 1;
	init[2][4]= 1;
	init[3][2]= 1;
	init[4][2]= 1;
	init[3][4]= 1;
	init[4][4]= 1;

	
	
	beginGame(init);
	 Affichage_Tab(init);
	 
	 for(i=0;i<100;i++){
	 	sleep(2);
	 	GenerationCells(init);
	 	Affichage_Tab(init);
	 }
	
	return 0;
}


/*********************FIN DU MAIN*******************
*                                                  *
***************************************************/

void beginGame(int init[Row][Col]){
	int i, j;
	for(i = 0; i < Row; i++) {
		for(j = 0; j < Col; j++) {
			
			if( i == (Row -1) ||i == 0 || j == 0 || j == (Col -1)) { /* on délimite les bordures du tableau */
				init[i][j] = -1;
			} 	 
		}
	}

}

/* Fonction de mise en place du tableau de façon aléatoire, qui renvoit à init en variable globale */

void Random_Cells(int init[Row][Col] ) {
	int i, j;
	for(i = 0; i < Row; i++) {
		for(j = 0; j < Col; j++) {
			
			if( i == (Row -1) ||i == 0 || j == 0 || j == (Col -1)) { /* on délimite les bordures du tableau */
				init[i][j] = -1;
			} else {
				srand(rdtsc()); /*fonction srand basé sur la fréquence du processeur*/
				init[i][j]= rand()% 2; /* utilisation modulo partie restante 0 ou 1 */
			}	 
		}
	}	
}
	
/********************Fonction d'affichage*************************/

void Affichage_Tab(int init[Row][Col]){
	int i,j;
	system("clear");
		for(i=0; i< Row; i++){
			for (j = 0; j < Col; j++)
			{
				switch(init[i][j]){ /* utilisation de putchar pour afficher en stdout */

					case -1 : putchar('*');
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

void GenerationCells (int init[Row][Col]){
	int i,j, NeighCell; /* variable NeighCell contenant le nombre de voisins */
	for (i = 0; i < Row ; i++){
		for ( j = 0; j < Col; j++){
			if (init[i][j]== -1) continue; /* continue : permet de reboucler directement.*/
			NeighCell = CountNeigh(i,j,init);
			/*printf("======GenerationCells======== \n" );
			printf("Row :%d Col%d nombre: %d \n",i,j,NeighCell );*/
			if (init[i][j] == 1 && NeighCell<2 || NeighCell>3  ){
				buffer[i][j]= 0;
			}else if(init[i][j] == 1 && (NeighCell==2||NeighCell==3 )){ /* correction du bug*/
				buffer[i][j]= 1;
			}
			if(init [i][j]== 0 && NeighCell==3){
					buffer[i][j]= 1;
				}		
		}
	}

for (i = 0; i < Row ; i++)
	{
		for ( j = 0; j < Col; j++)
		{
			if (init[i][j]== -1) continue; /*permet de reboucler directement.*/
			init[i][j]= buffer[i][j];
			
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
	Donc à partir de la cellule courante init verfier toutes les -1 et +1 cellules et les comptabiliser
	il faut donc envoyer la taille de note tableau initial à la fonction
*/
int CountNeigh(int a, int b,int CurrentCell[Row][Col]){
	int i,j, k=0;

	for (i = (a-1); i <(a+2); i++)  /* a-1 pour commencer aux cellules inf jusqu à a+1 pour les cellules sup*/
	{
		for (j = (b-1) ; j < (b+2); j++)
		{	
			if (i== a && j == b )continue;
			 if(CurrentCell[i][j]!=-1){
				k+=CurrentCell[i][j];
				
				
			}

		}
	}
	
	return k;
}




		


