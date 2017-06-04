/******************************************************************************/
/**                                                    ,---------------.     **/
/**    COMPUTACAO GRAFICA                              |        .-.    |     **/
/**    MIEEC - FCTUC                                   |        !o|    |     **/
/**                                                    |>-,   ,-' | ,-<|     **/
/**    AUTORES: - Filipe Cabeleira                     |  `---'   `-'  |     **/
/**             - Rui Xavier Costa                     `---------------'     **/
/******************************************************************************/
/* DESCRICAO: Texto que devera descrever os objectivos e os resultados .....  */
/*            do programa. .................................................  */
/*		      ..............................................................  */
/******************************************************************************/
// 
//	Bibliotecas a incluir //////////////////////////////////////////////////////
//
#include <stdio.h>
#include <stdlib.h>
#include <glut.h>
#include "cena.h"
//
//	Definições /////////////////////////////////////////////////////////////////
//
// Exemplo da definição de uma constante
#define PI    3.1415927
//
//	Funções ////////////////////////////////////////////////////////////////////
//

void desenha_plano(float z, float cor[4])
{

	glColor4f(cor[0], cor[1], cor[2], cor[3]);

	glPushMatrix();						      // armazenamento da matriz de
											  // transformação actual

	glScalef(20000, 20000, 1000);		      // definição do tamanho 

	glTranslatef(0, 0, z);			      // translação para 0,0,-0.51

	glutSolidCube(1);					 		 // desenho de um cubo de lado 1
												 // (é-lhe aplicada a transform.
												 // de mudança de escala)

	glPopMatrix();						         // recuperação da matriz de
												 // transformação anterior
}
