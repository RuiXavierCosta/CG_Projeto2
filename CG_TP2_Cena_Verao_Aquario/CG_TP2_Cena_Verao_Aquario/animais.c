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
#include "cena.h"
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

void desenhar_objeto(GLMmodel *objeto, float posicao[3], float rotacao[3])
{
	glPushMatrix();
	// Posicionamento
	glTranslatef(posicao[0], posicao[1], posicao[2]);
	glRotatef(rotacao[0], 1.0, 0.0, 0.0);
	glRotatef(rotacao[1], 0.0, 1.0, 0.0);
	glRotatef(rotacao[2], 0.0, 0.0, 1.0);
	
	// Desenho
	glmDraw(objeto, GLM_SMOOTH | GLM_MATERIAL);
	glPopMatrix();
}

void desenhar_objeto_tex(GLMmodel *objeto, float posicao[3], float rotacao[3])
{
	glPushMatrix();
	// Posicionamento
	glTranslatef(posicao[0], posicao[1], posicao[2]);
	glRotatef(rotacao[0], 1.0, 0.0, 0.0);
	glRotatef(rotacao[1], 0.0, 1.0, 0.0);
	glRotatef(rotacao[2], 0.0, 0.0, 1.0);

	// Desenho
	glmDraw(objeto, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
	glPopMatrix();
}

void desenhar_objeto_mat(GLMmodel *objeto, float posicao[3], float rotacao[3], float mat_diffuse[4])
{
	glPushMatrix();
	// Posicionamento
	glTranslated(posicao[0], posicao[1], posicao[2]);
	glRotatef(rotacao[0], 1.0, 0.0, 0.0);
	glRotatef(rotacao[1], 0.0, 1.0, 0.0);
	glRotatef(rotacao[2], 0.0, 0.0, 1.0);

	// Material
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, black);
	glMaterialfv(GL_FRONT, GL_SHININESS, lisa);

	// Desenho
	glmDraw(objeto, GLM_SMOOTH);
	glPopMatrix();
}

void abana_animal(float rotacao_animal[3], float velocidade_animal[4], float orientacao_animal[4])
{
	
	int i = 0;
	if (velocidade_animal[3] == 0.0) {
		i = 1;
	}
	else {
		i = 1;
	}

	if (orientacao_animal[3] == 0.0) {
		if (rotacao_animal[i] <= orientacao_animal[i] + 15.0) {
			rotacao_animal[i] += velocidade_animal[i] / 10.0;
		}
		else {
			orientacao_animal[3] = 1.0;
		}
	}

	if (orientacao_animal[3] == 1.0) {
		if (rotacao_animal[i] >= orientacao_animal[i] - 15.0) {
			rotacao_animal[i] -= velocidade_animal[i] / 10.0;
		}
		else {
			orientacao_animal[3] = 0.0;
		}
	}

}