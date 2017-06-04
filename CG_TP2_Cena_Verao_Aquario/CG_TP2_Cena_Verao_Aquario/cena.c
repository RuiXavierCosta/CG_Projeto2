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
#include "animais.h"
#include "modelos.h"
//
//	Definições /////////////////////////////////////////////////////////////////
//
// Exemplo da definição de uma constante
#define PI    3.1415927

const float light_blue[4] = { 0.4156862745098039,  0.7803921568627451, 0.9176470588235294, 0.6 };
const float sand_yellow[4] = { 0.831, 0.765, 0.416, 1.0 };
const float transparent_glass[4] = { 0.7,  0.7, 0.7, 0.2 };
const float concrete[4] = { 0.2,  0.2, 0.2, 1.0 };
const float sun_yellow[4] = { 0.9607843137254902,  0.9941176470588235, 0.0196078431372549, 1.0 };
const float bubble_blue[4] = { 0.4, 0.4, 1.0, 0.1 };
const float black[4] = { 0.0, 0.0, 0.0, 1.0 };
const float white[4] = { 1.0, 1.0, 1.0, 1.0 };
const int baca[] = { 0 };
const int lisa[] = { 128 };

// parede betao direita
float vertices_betao1[8][3] = { // imaginando um cubo virado para a camara
	{ -50.0, 100, 20.0 }, // canto superior direito frente
	{ -50.1, 100, 20.0 }, // canto superior direito tras
	{ -50.1, 120, 20.0 }, // canto superior esquerdo tras
	{ -50.0, 120, 20.0 }, // canto superior esquerdo frente
	{ -50.0, 100, 0.0 }, // canto inferior direito frente
	{ -50.1, 100, 0.0 }, // canto inferior direito tras
	{ -50.1, 120, 0.0 }, // canto inferior esquerdo tras
	{ -50.0, 120, 0.0 }, // canto inferior esquerdo frente
};

//parede betao esquerda
float vertices_betao2[8][3] = { // imaginando um cubo virado para a camara
	{ 50.0, 100, 20.0 }, // canto superior direito frente
	{ 50.1, 100, 20.0 }, // canto superior direito tras
	{ 50.1, 120, 20.0 }, // canto superior esquerdo tras
	{ 50.0, 120, 20.0 }, // canto superior esquerdo frente
	{ 50.0, 100, 0.0 }, // canto inferior direito frente
	{ 50.1, 100, 0.0 }, // canto inferior direito tras
	{ 50.1, 120, 0.0 }, // canto inferior esquerdo tras
	{ 50.0, 120, 0.0 }, // canto inferior esquerdo frente
};

// parede betao tras
float vertices_betao3[8][3] = { // imaginando um cubo virado para a camara
	{ 50.0, 120, 20.0 }, // canto superior direito frente
	{ 50.0, 120.1, 20.0 }, // canto superior direito tras
	{ -50.0, 120.1, 20.0 }, // canto superior esquerdo tras
	{ -50.0, 120, 20.0 }, // canto superior esquerdo frente
	{ 50.0, 120, 0.0 }, // canto inferior direito frente
	{ 50.0, 120.1, 0.0 }, // canto inferior direito tras
	{ -50.0, 120.1, 0.0 }, // canto inferior esquerdo tras
	{ -50.0, 120, 0.0 }, // canto inferior esquerdo frente
};

// parede betao baixo
float vertices_betao4[8][3] = { // imaginando um cubo virado para a camara
	{ 50.0, 100, 0.0 }, // canto superior direito frente
	{ 50, 120, 0.0 }, // canto superior direito tras
	{ -50, 120, 0.0 }, // canto superior esquerdo tras
	{ -50, 100, 0.0 }, // canto superior esquerdo frente
	{ 50, 100, -0.1 }, // canto inferior direito frente
	{ 50, 120, -0.1 }, // canto inferior direito tras
	{ -50, 120, -0.1 }, // canto inferior esquerdo tras
	{ -50, 100, -0.1 }, // canto inferior esquerdo frente
};

//parede betao topo
float vertices_betao5[8][3] = { // imaginando um cubo virado para a camara
	{ 50.0, 100, 20.0 }, // canto superior direito frente
	{ 50, 120, 20.0 }, // canto superior direito tras
	{ -50, 120, 20.0 }, // canto superior esquerdo tras
	{ -50, 100, 20.0 }, // canto superior esquerdo frente
	{ 50, 100, 20.1 }, // canto inferior direito frente
	{ 50, 120, 20.1 }, // canto inferior direito tras
	{ -50, 120, 20.1 }, // canto inferior esquerdo tras
	{ -50, 100, 20.1 }, // canto inferior esquerdo frente
};

float posicao_salmon[] = { 0.0f, 300.0f, 3000.0f };
float posicao_manatee[] = { 1000.0f, 9000.0f, 600.0f };
float posicao_orca[] = { -1000.0f, 9000.0f, 3600.0f };
float posicao_tiger_shark[] = { 2000.0f, 9000.0f, 500.0f };
float posicao_trout[] = { -2000.0f, 9000.0f, 300.0f };
float posicao_tuna[] = { 3000.0f, 9000.0f, 2500.0f };
float posicao_shark[] = { -3000.0f, 9000.0f, 3800.0f };
float posicao_goldfish[] = { 4000.0f, 9000.0f, 600.0f };
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

void desenhar_parede(float vertices_parede[8][3], GLuint texture_id[], int id)
{
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialfv(GL_FRONT, GL_SHININESS, baca);

	glEnable(GL_TEXTURE_2D);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glLoadIdentity();
	glPushMatrix();
	glScaled(100.0, 100.0, 100.0);
	/*glRotatef(angulo, 1.0, 0.0, 0.0);
	glRotatef(angulo, 0.0, 1.0, 0.0);
	glRotatef(angulo, 0.0, 0.0, 1.0);*/

	// define qual das texturas usar
	glBindTexture(GL_TEXTURE_2D, texture_id[id]);

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

//	Desenha parede 2D
//	* vertices[6]
//	* 0: 
//	* 1: 
//	* 2: 
//	* 3: 
//	* 4: 
//	* 5: 
//void desenha_parede_2d(float vertices[6], GLuint texture_id[], int id)
//{
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, texture_id[id]);
//	glBegin(GL_POLYGON);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(143, 0, 223);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(3000, 0, 223);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(3000, 0, 1500);
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(143, 0, 1500);
//	glEnd();
//	glDisable(GL_TEXTURE_2D);
//}

void desenha_vidro(float vertices_parede[8][3])//, GLuint texture_id[], int id)
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, transparent_glass);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, lisa);

	glEnable(GL_TEXTURE_2D);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glLoadIdentity();
	glPushMatrix();
	glScaled(100.0, 100.0, 100.0);

	// define qual das texturas usar
	//glBindTexture(GL_TEXTURE_2D, texture_id[id]);

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
	// glTexCoord2f(0.0f, 1.0f); 
	glVertex3f(vertices_parede[7][0], vertices_parede[7][1], vertices_parede[7][2]);
	// glTexCoord2f(0.0f, 0.0f); 
	glVertex3f(vertices_parede[3][0], vertices_parede[3][1], vertices_parede[3][2]);
	// glTexCoord2f(1.0f, 0.0f); 
	glVertex3f(vertices_parede[0][0], vertices_parede[0][1], vertices_parede[0][2]);
	// glTexCoord2f(1.0f, 1.0f); 
	glVertex3f(vertices_parede[4][0], vertices_parede[4][1], vertices_parede[4][2]);

	// Back Face
	// glTexCoord2f(1.0f, 1.0f); 
	glVertex3f(vertices_parede[6][0], vertices_parede[6][1], vertices_parede[6][2]);
	// glTexCoord2f(0.0f, 1.0f); 
	glVertex3f(vertices_parede[5][0], vertices_parede[5][1], vertices_parede[5][2]);
	// glTexCoord2f(0.0f, 0.0f); 
	glVertex3f(vertices_parede[1][0], vertices_parede[1][1], vertices_parede[1][2]);
	// glTexCoord2f(1.0f, 0.0f); 
	glVertex3f(vertices_parede[2][0], vertices_parede[2][1], vertices_parede[2][2]);

	// Top Face
	// glTexCoord2f(0.0f, 0.0f); 
	glVertex3f(vertices_parede[2][0], vertices_parede[2][1], vertices_parede[2][2]);
	// glTexCoord2f(1.0f, 0.0f); 
	glVertex3f(vertices_parede[1][0], vertices_parede[1][1], vertices_parede[1][2]);
	// glTexCoord2f(1.0f, 1.0f); 
	glVertex3f(vertices_parede[0][0], vertices_parede[0][1], vertices_parede[0][2]);
	// glTexCoord2f(0.0f, 1.0f); 
	glVertex3f(vertices_parede[3][0], vertices_parede[3][1], vertices_parede[3][2]);

	// Bottom Face
	// glTexCoord2f(1.0f, 0.0f);
	glVertex3f(vertices_parede[6][0], vertices_parede[6][1], vertices_parede[6][2]);
	// glTexCoord2f(1.0f, 1.0f); 
	glVertex3f(vertices_parede[7][0], vertices_parede[7][1], vertices_parede[7][2]);
	// glTexCoord2f(0.0f, 1.0f); 
	glVertex3f(vertices_parede[4][0], vertices_parede[4][1], vertices_parede[4][2]);
	// glTexCoord2f(0.0f, 0.0f); 
	glVertex3f(vertices_parede[5][0], vertices_parede[5][1], vertices_parede[5][2]);

	// Right Face
	// glTexCoord2f(1.0f, 0.0f); 
	glVertex3f(vertices_parede[5][0], vertices_parede[5][1], vertices_parede[5][2]);
	// glTexCoord2f(1.0f, 1.0f);
	glVertex3f(vertices_parede[4][0], vertices_parede[4][1], vertices_parede[4][2]);
	// glTexCoord2f(0.0f, 1.0f); 
	glVertex3f(vertices_parede[0][0], vertices_parede[0][1], vertices_parede[0][2]);
	// glTexCoord2f(0.0f, 0.0f); 
	glVertex3f(vertices_parede[1][0], vertices_parede[1][1], vertices_parede[1][2]);

	// Left Face
	// glTexCoord2f(0.0f, 0.0f); 
	glVertex3f(vertices_parede[6][0], vertices_parede[6][1], vertices_parede[6][2]);
	// glTexCoord2f(1.0f, 0.0f); 
	glVertex3f(vertices_parede[2][0], vertices_parede[2][1], vertices_parede[2][2]);
	// glTexCoord2f(1.0f, 1.0f); 
	glVertex3f(vertices_parede[3][0], vertices_parede[3][1], vertices_parede[3][2]);
	// glTexCoord2f(0.0f, 1.0f); 
	glVertex3f(vertices_parede[7][0], vertices_parede[7][1], vertices_parede[7][2]);
	glEnd();

	glPopMatrix();

	//glDisable(GL_TEXTURE_2D);

	glFlush();
}

void desenha_betao(float vertices_parede[8][3])//, GLuint texture_id[], int id)
{
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, concrete);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, concrete);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialfv(GL_FRONT, GL_SHININESS, baca);

	//glEnable(GL_TEXTURE_2D);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glLoadIdentity();
	glPushMatrix();
	glScaled(100.0, 100.0, 100.0);

	// define qual das texturas usar
	//glBindTexture(GL_TEXTURE_2D, texture_id[id]);

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
	// glTexCoord2f(0.0f, 1.0f); 
	glVertex3f(vertices_parede[7][0], vertices_parede[7][1], vertices_parede[7][2]);
	// glTexCoord2f(0.0f, 0.0f); 
	glVertex3f(vertices_parede[3][0], vertices_parede[3][1], vertices_parede[3][2]);
	// glTexCoord2f(1.0f, 0.0f); 
	glVertex3f(vertices_parede[0][0], vertices_parede[0][1], vertices_parede[0][2]);
	// glTexCoord2f(1.0f, 1.0f); 
	glVertex3f(vertices_parede[4][0], vertices_parede[4][1], vertices_parede[4][2]);

	// Back Face
	// glTexCoord2f(1.0f, 1.0f); 
	glVertex3f(vertices_parede[6][0], vertices_parede[6][1], vertices_parede[6][2]);
	// glTexCoord2f(0.0f, 1.0f); 
	glVertex3f(vertices_parede[5][0], vertices_parede[5][1], vertices_parede[5][2]);
	// glTexCoord2f(0.0f, 0.0f); 
	glVertex3f(vertices_parede[1][0], vertices_parede[1][1], vertices_parede[1][2]);
	// glTexCoord2f(1.0f, 0.0f); 
	glVertex3f(vertices_parede[2][0], vertices_parede[2][1], vertices_parede[2][2]);

	// Top Face
	// glTexCoord2f(0.0f, 0.0f); 
	glVertex3f(vertices_parede[2][0], vertices_parede[2][1], vertices_parede[2][2]);
	// glTexCoord2f(1.0f, 0.0f); 
	glVertex3f(vertices_parede[1][0], vertices_parede[1][1], vertices_parede[1][2]);
	// glTexCoord2f(1.0f, 1.0f); 
	glVertex3f(vertices_parede[0][0], vertices_parede[0][1], vertices_parede[0][2]);
	// glTexCoord2f(0.0f, 1.0f); 
	glVertex3f(vertices_parede[3][0], vertices_parede[3][1], vertices_parede[3][2]);

	// Bottom Face
	// glTexCoord2f(1.0f, 0.0f);
	glVertex3f(vertices_parede[6][0], vertices_parede[6][1], vertices_parede[6][2]);
	// glTexCoord2f(1.0f, 1.0f); 
	glVertex3f(vertices_parede[7][0], vertices_parede[7][1], vertices_parede[7][2]);
	// glTexCoord2f(0.0f, 1.0f); 
	glVertex3f(vertices_parede[4][0], vertices_parede[4][1], vertices_parede[4][2]);
	// glTexCoord2f(0.0f, 0.0f); 
	glVertex3f(vertices_parede[5][0], vertices_parede[5][1], vertices_parede[5][2]);

	// Right Face
	// glTexCoord2f(1.0f, 0.0f); 
	glVertex3f(vertices_parede[5][0], vertices_parede[5][1], vertices_parede[5][2]);
	// glTexCoord2f(1.0f, 1.0f);
	glVertex3f(vertices_parede[4][0], vertices_parede[4][1], vertices_parede[4][2]);
	// glTexCoord2f(0.0f, 1.0f); 
	glVertex3f(vertices_parede[0][0], vertices_parede[0][1], vertices_parede[0][2]);
	// glTexCoord2f(0.0f, 0.0f); 
	glVertex3f(vertices_parede[1][0], vertices_parede[1][1], vertices_parede[1][2]);

	// Left Face
	// glTexCoord2f(0.0f, 0.0f); 
	glVertex3f(vertices_parede[6][0], vertices_parede[6][1], vertices_parede[6][2]);
	// glTexCoord2f(1.0f, 0.0f); 
	glVertex3f(vertices_parede[2][0], vertices_parede[2][1], vertices_parede[2][2]);
	// glTexCoord2f(1.0f, 1.0f); 
	glVertex3f(vertices_parede[3][0], vertices_parede[3][1], vertices_parede[3][2]);
	// glTexCoord2f(0.0f, 1.0f); 
	glVertex3f(vertices_parede[7][0], vertices_parede[7][1], vertices_parede[7][2]);
	glEnd();

	glPopMatrix();

	//glDisable(GL_TEXTURE_2D);

	glFlush();
}

void desenha_sala()
{
	desenha_betao(vertices_betao1);
	desenha_betao(vertices_betao2);
	desenha_betao(vertices_betao3);
	desenha_betao(vertices_betao4);
	desenha_betao(vertices_betao5);
}

void desenha_peixes()
{
	// Desenho de circulo (para ajuda ao posicionamento) e dos animais em si
	/*desenhar_circulo(20);
	desenhar_tubarao(1000, 9000, 200.0);
	desenhar_goldfish(-1000, 9000, 200.0);*/

	abana_animal(salmon_rotation, salmon_speed, salmon_orientation);
	abana_animal(manatee_rotation, manatee_speed, manatee_orientation);
	abana_animal(orca_rotation, orca_speed, orca_orientation);
	abana_animal(tiger_shark_rotation, tiger_shark_speed, tiger_shark_orientation);
	abana_animal(trout_rotation, trout_speed, trout_orientation);
	abana_animal(tuna_rotation, tuna_speed, tuna_orientation);
	abana_animal(shark_rotation, shark_speed, shark_orientation);
	abana_animal(goldfish_rotation, goldfish_speed, goldfish_orientation);

	move_animal(posicao_salmon, salmon_speed, salmon_orientation);
	move_animal(posicao_manatee, manatee_speed, manatee_orientation);
	move_animal(posicao_orca, orca_speed, orca_orientation);
	move_animal(posicao_tiger_shark, tiger_shark_speed, tiger_shark_orientation);
	move_animal(posicao_trout, trout_speed, trout_orientation);
	move_animal(posicao_tuna, tuna_speed, tuna_orientation);
	move_animal(posicao_shark, shark_speed, shark_orientation);
	move_animal(posicao_goldfish, goldfish_speed, goldfish_orientation);

	desenhar_objeto_mat(salmon, posicao_salmon, salmon_rotation, salmon_color);
	desenhar_objeto_mat(manatee, posicao_manatee, manatee_rotation, manatee_color);
	desenhar_objeto_mat(orca, posicao_orca, orca_rotation, orca_color);
	desenhar_objeto_mat(tiger_shark, posicao_tiger_shark, tiger_shark_rotation, tiger_shark_color);
	desenhar_objeto_mat(trout, posicao_trout, trout_rotation, trout_color);
	desenhar_objeto_mat(tuna, posicao_tuna, tuna_rotation, tuna_color);
	desenhar_objeto_mat(shark, posicao_shark, shark_rotation, shark_color);
	desenhar_objeto_mat(goldfish, posicao_goldfish, goldfish_rotation, goldfish_color);

}