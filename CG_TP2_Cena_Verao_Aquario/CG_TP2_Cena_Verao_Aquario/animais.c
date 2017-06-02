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
#include "animais.h"

//
//	Definições /////////////////////////////////////////////////////////////////
//

//
//	Funções ////////////////////////////////////////////////////////////////////
//

void desenhar_tubarao(float pos_x, float pos_y, float pos_z)
{
	glPushMatrix();
	glTranslatef(pos_x, pos_y, pos_z);
	glRotated(90.0, 1.0, 0.0, 0.0);
	glmDraw(shark, GLM_SMOOTH | GLM_MATERIAL);
	glPopMatrix();
}

void desenhar_goldfish(float pos_x, float pos_y, float pos_z)
{
	glPushMatrix();
	// Posicionamento
	glTranslatef(pos_x, pos_y, pos_z);
	glRotated(90.0, 1.0, 0.0, 0.0);

	// Material
	float diff[] = { 243.0 / 255.0, 134.0 / 255.0, 48.0 / 255.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);

	// Desenho
	glmDraw(goldfish, GLM_SMOOTH);
	glPopMatrix();
}
