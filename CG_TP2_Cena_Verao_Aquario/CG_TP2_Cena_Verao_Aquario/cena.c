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

double light_blue[3] = { 0.4156862745098039,  0.7803921568627451, 0.9176470588235294 };
//
//	Funções ////////////////////////////////////////////////////////////////////
//

void desenha_topo_agua(double z, double diametro)
{

	glPushMatrix();			  // armazenamento da matriz de transformação actual

	glTranslatef(0.0, 0.0, z);				// colocação da esfera no local desejado

	glColor3f(light_blue[0], light_blue[0], light_blue[0]);			                              // amarelo
		
		
		DrawCircle(0.0, 0.0, diametro / 2, 200);
		
	glPopMatrix();			  // recuperação da matriz de transformação anterior

}

void desenha_sol(double x, double y, double z, double diametro)
{
	double numero_meridianos = 16;		       // numero de meridianos da esfera
	double numero_paralelos = 16;		       // numero de paralelos da esfera
	//double pos_luz[] = { x, y, z - diametro / 2, 0.4 };

	float mat_especular[] = { 1.0, 1.0, 0.0, 0.4 };
	float mat_brilho[] = { 0.01 };

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_especular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_brilho);

	glPushMatrix();			  // armazenamento da matriz de transformação actual

		glTranslatef(x, y, z);				// colocação da esfera no local desejado


		glColor3f(1.0, 1.0, 0.0);			                              // amarelo

		glutSolidSphere(diametro / 2,
			numero_meridianos, numero_paralelos);	            // desenho da esfera

		//glLightfv(GL_LIGHT0, GL_POSITION, pos_luz);

	glPopMatrix();			  // recuperação da matriz de transformação anteriors
}