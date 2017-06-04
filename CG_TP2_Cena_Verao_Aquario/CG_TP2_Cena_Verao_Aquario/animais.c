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

#define PI    3.1415927
//
//	Funções ////////////////////////////////////////////////////////////////////
//
void desenhar_objeto_mat(GLMmodel *objeto, float posicao[3], float rotacao[3], float mat_diffuse[4])
{
	glPushMatrix();
	// Posicionamento
	glTranslated(posicao[0], posicao[1], posicao[2]);
	glRotatef(rotacao[0], 1.0, 0.0, 0.0);
	glRotatef(rotacao[1], 0.0, 1.0, 0.0);
	glRotatef(rotacao[2], 1.0, 0.0, 1.0);

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
	float amplitude = 10.0;
	float const_att = 10.0;

	int i = 1;
	if (velocidade_animal[3] == 1.0) {
		amplitude = 10.0;
		const_att = 30.0;
	}

	if (orientacao_animal[3] == 0.0) {
		if (rotacao_animal[i] <= orientacao_animal[i] + amplitude) {
			rotacao_animal[i] += velocidade_animal[i] / const_att;
		}
		else {
			orientacao_animal[3] = 1.0;
		}
	}

	if (orientacao_animal[3] == 1.0) {
		if (rotacao_animal[i] >= orientacao_animal[i] - amplitude) {
			rotacao_animal[i] -= velocidade_animal[i] / const_att;
		}
		else {
			orientacao_animal[3] = 0.0;
		}
	}

}

void move_animal(float posicao_animal[3], float velocidade_animal[4], float orientacao_animal[4])
{	
	float rad = 2 * PI / 360;
	float inc_x = velocidade_animal[0] * cos((orientacao_animal[1]  -90)*rad);
	float inc_y = velocidade_animal[1] * sin((orientacao_animal[1] - 90)*rad);
	float inc_z = velocidade_animal[2] * (orientacao_animal[2]) / 360.0;

	if (posicao_animal[0] + inc_x > 9000 || posicao_animal[0] + inc_x < -9000)
	{
		orientacao_animal[1] = -orientacao_animal[1];
		inc_x = velocidade_animal[0] * cos((orientacao_animal[1] - 90)*rad);
	}

	if (posicao_animal[1] + inc_y > 9000 || posicao_animal[1] + inc_y < -9000)
	{
		orientacao_animal[1] += 180;
		inc_y = velocidade_animal[1] * sin((orientacao_animal[1] - 90)*rad);
	}

	if (posicao_animal[2] + inc_z > 4000 || posicao_animal[2] + inc_x < 100)
	{
		orientacao_animal[2] = -orientacao_animal[2];
		inc_z = velocidade_animal[2] * (orientacao_animal[2]) / 360.0;
	}

	posicao_animal[0] += inc_x;
	posicao_animal[1] += inc_y;
	//posicao_animal[2] += inc_z;
}