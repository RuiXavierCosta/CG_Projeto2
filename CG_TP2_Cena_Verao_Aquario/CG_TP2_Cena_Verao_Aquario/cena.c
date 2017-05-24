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
const float sand_yellow[4] = { 0.9607843137254902,  0.8941176470588235, 0.6196078431372549, 1.0 };
const float sun_yellow[4] = { 0.9607843137254902,  0.9941176470588235, 0.0196078431372549, 1.0 };
const float black[4] = { 0.0, 0.0, 0.0, 1.0 };
const float white[4] = { 1.0, 1.0, 1.0, 1.0 };
const float baca[] = { 0.0 };
//
//	Funções ////////////////////////////////////////////////////////////////////
//

void desenha_topo_agua(double z)
{

	float mat_especular[] = { 1.0, 1.0, 0.0, 0.4 };
	float mat_brilho[] = { 1.0 };
	
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, light_blue);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialfv(GL_FRONT, GL_SHININESS, baca);

	desenha_plano(z, light_blue);
		
}

void desenha_areia(double z)
{

	float mat_especular[] = { 1.0, 1.0, 0.0, 0.3 };
	float mat_brilho[] = { 1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, sand_yellow);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialfv(GL_FRONT, GL_SHININESS, baca);

	desenha_plano(z, sand_yellow);

}

void desenha_sol(double x, double y, double z, double diametro)
{
	double numero_meridianos = 16;		       // numero de meridianos da esfera
	double numero_paralelos = 16;		       // numero de paralelos da esfera
	//double pos_luz[] = { x, y, z - diametro / 2, 0.4 };

	float mat_especular[] = { 1.0, 1.0, 0.0, 0.4 };
	float mat_brilho[] = { 0.01 };

	glPushMatrix();			  // armazenamento da matriz de transformação actual

		glTranslatef(x, y, z);				// colocação da esfera no local desejado
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, sun_yellow);
		glMaterialfv(GL_FRONT, GL_SPECULAR, black);
		glMaterialfv(GL_FRONT, GL_SHININESS, baca);


		glColor3f(1.0, 1.0, 0.0);			                              // amarelo

		glutSolidSphere(diametro / 2,
			numero_meridianos, numero_paralelos);	            // desenho da esfera

		//glLightfv(GL_LIGHT0, GL_POSITION, pos_luz);

	glPopMatrix();			  // recuperação da matriz de transformação anteriors
}

void desenha_eixos(float comprimento_eixo)
{
	printf("Desenha eixos... ");

	// desenha linhas (3 eixos positivos) //////////////////////////////////////

	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);					                 // vermelho
	glVertex2f(0.0, 0.0);						                 // eixo OX
	glVertex2f(comprimento_eixo, 0.0);

	glColor3f(0.0, 1.0, 0.0);					                 // verde
	glVertex2f(0.0, 0.0);						                 // eixo OY
	glVertex2f(0.0, comprimento_eixo);

	glColor3f(0.0, 0.0, 1.0);					                 // azul
	glVertex3f(0.0, 0.0, 0.0);					                 // eixo OZ
	glVertex3f(0.0, 0.0, comprimento_eixo);
	glEnd();

	// desenha linhas (3 eixos negativos) //////////////////////////////////////

	glBegin(GL_LINES);
	glColor3f(0.7, 0.0, 0.0);					          // vermelho escuro
	glVertex2f(0.0, 0.0);						          // eixo OX-
	glVertex2f(-comprimento_eixo, 0.0);

	glColor3f(0.0, 0.7, 0.0);					          // verde escuro
	glVertex2f(0.0, 0.0);						          // eixo OY-
	glVertex2f(0.0, -comprimento_eixo);

	glColor3f(0.0, 0.0, 0.7);				 	          // azul escuro
	glVertex3f(0.0, 0.0, 0.0);				 	          // eixo OZ-
	glVertex3f(0.0, 0.0, -comprimento_eixo);
	glEnd();
}
