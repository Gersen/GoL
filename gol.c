#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "header.h"


/*=================================================
*				Protypes						  *
*=================================================*/




/************** DECLARATION DU MAIN****************
*                                                  *
***************************************************/

int main(void)
{
	int Origin_tab[X][Y];
	char c =' '; 

	Aleatoire_Tab(Origin_tab,X,Y);
	Affiche_Tab(Origin_tab,X,Y);
	sleep(10);/* pour utiliser sleep inclure <unistd.h>*/
	
	

	puts ("Voullez vous remettre le tableau à zero ? O ou N ");
	scanf("%c", &c);
	if (c == 'O'){
			Reset_tab(Origin_tab,X,Y);

			Affiche_Tab(Origin_tab,X,Y);
	}

	return 0;
}


