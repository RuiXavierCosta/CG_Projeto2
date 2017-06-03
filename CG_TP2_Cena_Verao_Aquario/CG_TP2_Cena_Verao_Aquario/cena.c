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
#include "shapes.h"
//
//	Definições /////////////////////////////////////////////////////////////////
//
// Exemplo da definição de uma constante
#define PI    3.1415927

const float light_blue[4] = { 0.4156862745098039,  0.7803921568627451, 0.9176470588235294, 0.3 };
const float sand_yellow[4] = { 0.831, 0.765, 0.416, 1.0 };
const float sun_yellow[4] = { 0.9607843137254902,  0.9941176470588235, 0.0196078431372549, 1.0 };
const float bubble_blue[4] = { 0.4, 0.4, 1.0, 0.1 };
const float black[4] = { 0.0, 0.0, 0.0, 1.0 };
const float white[4] = { 1.0, 1.0, 1.0, 1.0 };
const int baca[] = { 0 };
const int lisa[] = { 128 };
//
//	Funções ////////////////////////////////////////////////////////////////////
//

float randf(float min, float max)
{
	return min + (float)rand() / (float)(RAND_MAX / (max - min));
}

void desenha_topo_agua(double z)
{
	
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, light_blue);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialfv(GL_FRONT, GL_SHININESS, baca);

	desenha_plano(z, light_blue);
		
}

void desenha_areia(double z)
{

	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, sand_yellow);
	glMaterialfv(GL_FRONT, GL_SPECULAR, sand_yellow);
	glMaterialfv(GL_FRONT, GL_SHININESS, baca);

	desenha_plano(z, sand_yellow);

}

void desenha_sol(double x, double y, double z, double diametro)
{
	double numero_meridianos = 16;		       // numero de meridianos da esfera
	double numero_paralelos = 16;		       // numero de paralelos da esfera

	glPushMatrix();			  // armazenamento da matriz de transformação actual

		glTranslatef(x, y, z);				// colocação da esfera no local desejado
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, sun_yellow);
		glMaterialfv(GL_FRONT, GL_SPECULAR, black);
		glMaterialfv(GL_FRONT, GL_SHININESS, baca);

		glutSolidSphere(diametro / 2,
			numero_meridianos, numero_paralelos);	            // desenho da esfera

	glPopMatrix();			  // recuperação da matriz de transformação anteriors
}

void desenha_eixos(float comprimento_eixo)
{
	printf("Desenha eixos... ");
	glPushMatrix();
		glTranslatef(0.0, 0.0, 500.0);
		// desenha linhas (3 eixos positivos) //////////////////////////////////////

		glBegin(GL_LINES);
		glColor3f(1.0, 0.0, 0.0);					                 // vermelho
		glVertex2f(0.0, 0.0);						                 // eixo OX
		glVertex2f(comprimento_eixo, 0.0);

		glVertex2f(0.0, 0.0);						                 // eixo OY
		glVertex2f(0.0, comprimento_eixo);

		glVertex3f(0.0, 0.0, 0.0);					                 // eixo OZ
		glVertex3f(0.0, 0.0, comprimento_eixo);
		glEnd();

		// desenha linhas (3 eixos negativos) //////////////////////////////////////

		glBegin(GL_LINES);
		glVertex2f(0.0, 0.0);						          // eixo OX-
		glVertex2f(-comprimento_eixo, 0.0);

		glVertex2f(0.0, 0.0);						          // eixo OY-
		glVertex2f(0.0, -comprimento_eixo);

		glVertex3f(0.0, 0.0, 0.0);				 	          // eixo OZ-
		glVertex3f(0.0, 0.0, -comprimento_eixo);
		glEnd();
	glPopMatrix();
}

void desenha_bolha(double x, double y, double z, double diametro)
{
	double numero_meridianos = 16;		       // numero de meridianos da esfera
	double numero_paralelos = 16;		       // numero de paralelos da esfera

	glPushMatrix();			  // armazenamento da matriz de transformação actual

	glTranslatef(x, y, z);				// colocação da esfera no local desejado
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, bubble_blue);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialfv(GL_FRONT, GL_SHININESS, lisa);

	glutSolidSphere(diametro / 2,
		numero_meridianos, numero_paralelos);	            // desenho da esfera

	glPopMatrix();			  // recuperação da matriz de transformação anteriors

}

void desenha_cluster_bolhas(float array_x[], float array_y[], float array_z[], float base_bolhas, float array_diam[], int num_bolhas)
{

	for (int i = 0; i < num_bolhas; i++)
	{
		desenha_bolha(array_x[i], array_y[i], base_bolhas + array_z[i], array_diam[i]);
	}
}

void desenhar_parede(float vertices_parede[8][3], GLuint texture_id[1])
{
	glEnable(GL_TEXTURE_2D);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glLoadIdentity();
	glPushMatrix();
	glScaled(100.0, 100.0, 100.0);
	/*glRotatef(angulo, 1.0, 0.0, 0.0);
	glRotatef(angulo, 0.0, 1.0, 0.0);
	glRotatef(angulo, 0.0, 0.0, 1.0);*/

	// define qual das texturas usar
	glBindTexture(GL_TEXTURE_2D, texture_id[0]);

	/*
	-----
	*/
	// [0] canto superior direito frente
	// [1] canto superior direito tras
	// [2] canto superior esquerdo tras
	// [3] canto superior esquerdo frente
	// [4] canto inferior direito frente
	// [5] canto inferior direito tras
	// [6] canto inferior esquerdo tras
	// [7] canto inferior esquerdo frente

	glBegin(GL_QUADS);
	// Front Face
	glTexCoord2f(0.0f, 1.0f); glVertex3f(vertices_parede[7][0], vertices_parede[7][1], vertices_parede[7][2]);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(vertices_parede[3][0], vertices_parede[3][1], vertices_parede[3][2]);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(vertices_parede[0][0], vertices_parede[0][1], vertices_parede[0][2]);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(vertices_parede[4][0], vertices_parede[4][1], vertices_parede[4][2]);
	// Back Face
	glTexCoord2f(1.0f, 1.0f); glVertex3f(vertices_parede[6][0], vertices_parede[6][1], vertices_parede[6][2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(vertices_parede[5][0], vertices_parede[5][1], vertices_parede[5][2]);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(vertices_parede[1][0], vertices_parede[1][1], vertices_parede[1][2]);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(vertices_parede[2][0], vertices_parede[2][1], vertices_parede[2][2]);
	// Top Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(vertices_parede[2][0], vertices_parede[2][1], vertices_parede[2][2]);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(vertices_parede[1][0], vertices_parede[1][1], vertices_parede[1][2]);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(vertices_parede[0][0], vertices_parede[0][1], vertices_parede[0][2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(vertices_parede[3][0], vertices_parede[3][1], vertices_parede[3][2]);
	// Bottom Face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(vertices_parede[6][0], vertices_parede[6][1], vertices_parede[6][2]);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(vertices_parede[7][0], vertices_parede[7][1], vertices_parede[7][2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(vertices_parede[4][0], vertices_parede[4][1], vertices_parede[4][2]);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(vertices_parede[5][0], vertices_parede[5][1], vertices_parede[5][2]);
	// Right Face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(vertices_parede[5][0], vertices_parede[5][1], vertices_parede[5][2]);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(vertices_parede[4][0], vertices_parede[4][1], vertices_parede[4][2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(vertices_parede[0][0], vertices_parede[0][1], vertices_parede[0][2]);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(vertices_parede[1][0], vertices_parede[1][1], vertices_parede[1][2]);
	// Left Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(vertices_parede[6][0], vertices_parede[6][1], vertices_parede[6][2]);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(vertices_parede[2][0], vertices_parede[2][1], vertices_parede[2][2]);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(vertices_parede[3][0], vertices_parede[3][1], vertices_parede[3][2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(vertices_parede[7][0], vertices_parede[7][1], vertices_parede[7][2]);
	glEnd();

	glPopMatrix();

	glDisable(GL_TEXTURE_2D);

	glFlush();
}