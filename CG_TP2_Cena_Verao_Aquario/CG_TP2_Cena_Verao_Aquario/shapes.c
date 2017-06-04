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
//	Defini��es /////////////////////////////////////////////////////////////////
//
// Exemplo da defini��o de uma constante
#define PI    3.1415927
//
//	Fun��es ////////////////////////////////////////////////////////////////////
//

void desenha_plano(float z, float cor[4])
{

	glColor4f(cor[0], cor[1], cor[2], cor[3]);

	glPushMatrix();						      // armazenamento da matriz de
											  // transforma��o actual

	glScalef(20000, 20000, 1000);		      // defini��o do tamanho 

	glTranslatef(0, 0, z);			      // transla��o para 0,0,-0.51

	glutSolidCube(1);					 		 // desenho de um cubo de lado 1
												 // (�-lhe aplicada a transform.
												 // de mudan�a de escala)

	glPopMatrix();						         // recupera��o da matriz de
												 // transforma��o anterior
}
