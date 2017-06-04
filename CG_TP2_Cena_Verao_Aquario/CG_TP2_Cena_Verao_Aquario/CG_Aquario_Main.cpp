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
#include "tgaload.h"
extern "C" {
#include "glm.h"
#include "cena.h"
#include "modelos.h"
#include "animais.h"
}
//
//	Definições /////////////////////////////////////////////////////////////////
//
// Exemplo da definição de uma constante
#define PI    3.1415927
#define ESCAPE 27

double ocean_blue[3] = { 0.0117647058823529, 0.4431372549019608, 0.6117647058823529 };

float diffuse_default[] = { 0.8f, 0.8f, 0.8f, 1.0f };
float branco[] = { 1.0f, 1.0f, 1.0f, 1.0f };

int largura = 1024;					  // largura da nossa janela de visualização
int altura = 768;					   // altura da nossa janela de visualização

double razao_aspeto = 1;		   // razão de aspecto da janela de visualização

double limite_z_anterior = 1;			            // plano de recorte anterior
double limite_z_posterior = 25000;		           // plano de recorte posterior

double camara_x = 0;					                // posição da câmara (x)
double camara_y = 11000;					                // posição da câmara (y)
double camara_z = 400;					                // posição da câmara (z)

double mira_x = 0;				        // direção de visualização da câmara (x)
double mira_y = 0;				        // direção de visualização da câmara (y)
double mira_z = 2000;				        // direção de visualização da câmara (z)

double teta_x = 0;				                         // orientação da câmara
double teta_z = 0;				                         // orientação da câmara
double campo_visao_y = 50;		                          // campo de visão em y
double map_border = 2000.0;

														  // Posição da fonte de iluminação na origem
const float pos_luz0[] = { 0.0, 0.0, 0.0, 1.0 };
const float pos_luz1[] = { 0.0, 0.0, 0.0, 1.0 };
float base_bolhas1 = 4001.0;
float base_bolhas2 = 4001.0;
float base_bolhas3 = 4001.0;
float base_bolhas4 = 4001.0;
float base_bolhas5 = 4001.0;
float base_bolhas6 = 4001.0;
float base_bolhas7 = 4001.0;
					  // Fator de atenuação da luz
float const_at = 3.0;
float const_at1 = 1.0;

const float pos_bolhas_x[7] = { 0.0, 3000.0, -1000.0, 1000.0, 3000.0, -1000.0, 1000.0 };
const float pos_bolhas_y[7] = { 0.0, -3000.0, 100.0, 100.0, 0.0, -3000.0, 100.0 };

int numero_bolhas = 100;
float *array_x1;
float *array_y1;
float *array_z1;
float *array_diam1;

float *array_x2;
float *array_y2;
float *array_z2;
float *array_diam2;

float *array_x3;
float *array_y3;
float *array_z3;
float *array_diam3;

float *array_x4;
float *array_y4;
float *array_z4;
float *array_diam4;

float *array_x5;
float *array_y5;
float *array_z5;
float *array_diam5;

float *array_x6;
float *array_y6;
float *array_z6;
float *array_diam6;

float *array_x7;
float *array_y7;
float *array_z7;
float *array_diam7;

float vertices_parede1[8][3] = { // imaginando um cubo virado para a camara
	{ 99.0, -99, 35.0 }, // canto superior direito frente
	{ 99, -100, 35.0 }, // canto superior direito tras
	{ -99, -100, 35.0 }, // canto superior esquerdo tras
	{ -99, -99, 35.0 }, // canto superior esquerdo frente
	{ 99, -99, 0.0 }, // canto inferior direito frente
	{ 99, -100, 0.0 }, // canto inferior direito tras
	{ -99, -100, 0.0 }, // canto inferior esquerdo tras
	{ -99, -99, 0.0 }, // canto inferior esquerdo frente
};

float vertices_parede2[8][3] = { // imaginando um cubo virado para a camara
	{ 99.0, -100.0, 35.0 }, // canto superior direito frente
	{ 100.0, -100.0, 35.0 }, // canto superior direito tras
	{ 99, 100, 35.0 }, // canto superior esquerdo tras
	{ 100, 100, 35.0 }, // canto superior esquerdo frente
	{ 99, -100, 0.0 }, // canto inferior direito frente
	{ 100, -100, 0.0 }, // canto inferior direito tras
	{ 99, 100, 0.0 }, // canto inferior esquerdo tras
	{ 100, 100, 0.0 }, // canto inferior esquerdo frente
};

float vertices_parede3[8][3] = { // imaginando um cubo virado para a camara
	{ -99.0, 100.0, 35.0 }, // canto superior direito frente
	{ -100.0, 100.0, 35.0 }, // canto superior direito tras
	{ -100, -100, 35.0 }, // canto superior esquerdo tras
	{ -99, -100, 35.0 }, // canto superior esquerdo frente
	{ -99, 100, 0.0 }, // canto inferior direito frente
	{ -100, 100, 0.0 }, // canto inferior direito tras
	{ -100, -100, 0.0 }, // canto inferior esquerdo tras
	{ -99, -100, 0.0 }, // canto inferior esquerdo frente
};

float vertices_areia[8][3] = { // imaginando um cubo virado para a camara
	{ -100.0, 100.0, 0.0 }, // canto superior direito frente
	{ -100.0, -100.0, 0.0 }, // canto superior direito tras
	{ 100.0, -100.0, 0.0 }, // canto superior esquerdo tras
	{ 100.0, 100.0, 0.0 }, // canto superior esquerdo frente
	{ -100, 100, -1.0 }, // canto inferior direito frente
	{ -100, -100, -1.0 }, // canto inferior direito tras
	{ 100, -100, -1.0 }, // canto inferior esquerdo tras
	{ 100, 100, -1.0 }, // canto inferior esquerdo frente
};

float vertices_vidro[8][3] = { // imaginando um cubo virado para a camara
	{ 99.0, 100, 35.0 }, // canto superior direito frente
	{ 99, 99, 35.0 }, // canto superior direito tras
	{ -99, 99, 35.0 }, // canto superior esquerdo tras
	{ -99, 100, 35.0 }, // canto superior esquerdo frente
	{ 99, 100, 0.0 }, // canto inferior direito frente
	{ 99, 99, 0.0 }, // canto inferior direito tras
	{ -99, 99, 0.0 }, // canto inferior esquerdo tras
	{ -99, 100, 0.0 }, // canto inferior esquerdo frente
};

// Quantidade máxima de texturas a serem usadas no programa
#define MAX_NO_TEXTURES 2

// Vetor com os números das texturas
GLuint texture_id[MAX_NO_TEXTURES];

//
//	Funções ////////////////////////////////////////////////////////////////////
//

//
//	Função de inicialização das diversas configurações do GLUT
//
void gera_valores_bolhas() 
{

	if (base_bolhas1 == 4001.0 )
	{
		base_bolhas1 = 3000.0 + -40.0*(float)numero_bolhas;

		base_bolhas2 = 6000.0 + -40.0*(float)numero_bolhas;

		base_bolhas3 = 1000.0 + -40.0*(float)numero_bolhas;
		
		base_bolhas4 = 300.0 + -40.0*(float)numero_bolhas;

		base_bolhas5 = 1400.0 + -40.0*(float)numero_bolhas;

		base_bolhas6 = 1800.0 + -40.0*(float)numero_bolhas;

		base_bolhas7 = 4000.0 + -40.0*(float)numero_bolhas;
	}


	if (base_bolhas1 == 4000.0 )
	{
		base_bolhas1 = -40.0*(float)numero_bolhas;
	}


	if (base_bolhas2 == 4000.0)
	{
		base_bolhas2 = -40.0*(float)numero_bolhas;
	}


	if (base_bolhas3 == 4000.0)
	{
		base_bolhas3 = -40.0*(float)numero_bolhas;
	}


	if (base_bolhas4 == 4000.0)
	{
		base_bolhas4 = -40.0*(float)numero_bolhas;
	}


	if (base_bolhas5 == 4000.0)
	{
		base_bolhas5 = -40.0*(float)numero_bolhas;
	}

	if (base_bolhas6 == 4000.0)
	{
		base_bolhas6 = -40.0*(float)numero_bolhas;
	}

	if (base_bolhas7 == 4000.0)
	{
		base_bolhas7 = -40.0*(float)numero_bolhas;
	}


	if (base_bolhas1 == -40.0*(float)numero_bolhas)
	{

		for (int i = 0; i < numero_bolhas; i++)
		{
			array_x1[i] = pos_bolhas_x[0] + randf(50.0, 100.0);
			array_y1[i] = pos_bolhas_y[0] + randf(50.0, 100.0);
			array_z1[i] = randf(20.0, 40.0*(float)numero_bolhas);
			array_diam1[i] = randf(25.0, 65.0);
		}
	}

	if (base_bolhas2 == -40.0*(float)numero_bolhas)
	{

		for (int i = 0; i < numero_bolhas; i++)
		{

			array_x2[i] = pos_bolhas_x[1] + randf(50.0, 100.0);
			array_y2[i] = pos_bolhas_y[1] + randf(50.0, 100.0);
			array_z2[i] = randf(20.0, 40.0*(float)numero_bolhas);
			array_diam2[i] = randf(25.0, 65.0);

		}
	}

	if (base_bolhas3 == -40.0*(float)numero_bolhas)
	{

		for (int i = 0; i < numero_bolhas; i++)
		{
			array_x3[i] = pos_bolhas_x[2] + randf(50.0, 100.0);
			array_y3[i] = pos_bolhas_y[2] + randf(50.0, 100.0);
			array_z3[i] = randf(20.0, 40.0*(float)numero_bolhas);
			array_diam3[i] = randf(25.0, 65.0);

		}
	}

	if (base_bolhas4 == -40.0*(float)numero_bolhas)
	{

		for (int i = 0; i < numero_bolhas; i++)
		{
			array_x4[i] = pos_bolhas_x[3] + randf(50.0, 100.0);
			array_y4[i] = pos_bolhas_y[3] + randf(50.0, 100.0);
			array_z4[i] = randf(20.0, 40.0*(float)numero_bolhas);
			array_diam4[i] = randf(25.0, 65.0);

		}
	}

	if (base_bolhas5 == -40.0*(float)numero_bolhas)
	{

		for (int i = 0; i < numero_bolhas; i++)
		{
			array_x5[i] = pos_bolhas_x[4] + randf(50.0, 100.0);
			array_y5[i] = pos_bolhas_y[4] + randf(50.0, 100.0);
			array_z5[i] = randf(20.0, 40.0*(float)numero_bolhas);
			array_diam5[i] = randf(25.0, 65.0);

		}
	}

	if (base_bolhas6 == -40.0*(float)numero_bolhas)
	{

		for (int i = 0; i < numero_bolhas; i++)
		{
			array_x6[i] = pos_bolhas_x[5] + randf(50.0, 100.0);
			array_y6[i] = pos_bolhas_y[5] + randf(50.0, 100.0);
			array_z6[i] = randf(20.0, 40.0*(float)numero_bolhas);
			array_diam6[i] = randf(25.0, 65.0);

		}
	}

	if (base_bolhas7 == -40.0*(float)numero_bolhas)
	{

		for (int i = 0; i < numero_bolhas; i++)
		{
			array_x7[i] = pos_bolhas_x[6] + randf(50.0, 100.0);
			array_y7[i] = pos_bolhas_y[6] + randf(50.0, 100.0);
			array_z7[i] = randf(20.0, 40.0*(float)numero_bolhas);
			array_diam7[i] = randf(25.0, 65.0);
		}
	}

	base_bolhas1+=4;
	base_bolhas2 += 4;
	base_bolhas3 += 4;
	base_bolhas4 += 4;
	base_bolhas5 += 4;
	base_bolhas6 += 4;
	base_bolhas7 += 4;

	desenha_cluster_bolhas(array_x1, array_y1, array_z1, base_bolhas1, array_diam1, numero_bolhas);

	desenha_cluster_bolhas(array_x2, array_y2, array_z2, base_bolhas2, array_diam2, numero_bolhas);

	desenha_cluster_bolhas(array_x3, array_y3, array_z3, base_bolhas3, array_diam3, numero_bolhas);

	desenha_cluster_bolhas(array_x4, array_y4, array_z4, base_bolhas4, array_diam4, numero_bolhas);

	desenha_cluster_bolhas(array_x5, array_y5, array_z5, base_bolhas5, array_diam5, numero_bolhas);

	desenha_cluster_bolhas(array_x6, array_y6, array_z6, base_bolhas6, array_diam6, numero_bolhas);

	desenha_cluster_bolhas(array_x7, array_y7, array_z7, base_bolhas7, array_diam7, numero_bolhas);

}

void preparar_bolhas() {

	array_x1 = (float*)malloc(numero_bolhas * sizeof(float));
	array_y1 = (float*)malloc(numero_bolhas * sizeof(float));
	array_z1 = (float*)malloc(numero_bolhas * sizeof(float));
	array_diam1 = (float*)malloc(numero_bolhas * sizeof(float));

	array_x2 = (float*)malloc(numero_bolhas * sizeof(float));
	array_y2 = (float*)malloc(numero_bolhas * sizeof(float));
	array_z2 = (float*)malloc(numero_bolhas * sizeof(float));
	array_diam2 = (float*)malloc(numero_bolhas * sizeof(float));

	array_x3 = (float*)malloc(numero_bolhas * sizeof(float));
	array_y3 = (float*)malloc(numero_bolhas * sizeof(float));
	array_z3 = (float*)malloc(numero_bolhas * sizeof(float));
	array_diam3 = (float*)malloc(numero_bolhas * sizeof(float));

	array_x4 = (float*)malloc(numero_bolhas * sizeof(float));
	array_y4 = (float*)malloc(numero_bolhas * sizeof(float));
	array_z4 = (float*)malloc(numero_bolhas * sizeof(float));
	array_diam4 = (float*)malloc(numero_bolhas * sizeof(float));

	array_x5 = (float*)malloc(numero_bolhas * sizeof(float));
	array_y5 = (float*)malloc(numero_bolhas * sizeof(float));
	array_z5 = (float*)malloc(numero_bolhas * sizeof(float));
	array_diam5 = (float*)malloc(numero_bolhas * sizeof(float));

	array_x6 = (float*)malloc(numero_bolhas * sizeof(float));
	array_y6 = (float*)malloc(numero_bolhas * sizeof(float));
	array_z6 = (float*)malloc(numero_bolhas * sizeof(float));
	array_diam6 = (float*)malloc(numero_bolhas * sizeof(float));

	array_x7 = (float*)malloc(numero_bolhas * sizeof(float));
	array_y7 = (float*)malloc(numero_bolhas * sizeof(float));
	array_z7 = (float*)malloc(numero_bolhas * sizeof(float));
	array_diam7 = (float*)malloc(numero_bolhas * sizeof(float));

}

void desenhar_circulo(int radius)
{
	float diff[] = { 1.0, 0.0, 0.0, 1.0 };
	float spec[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diff);
	glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
	glPushMatrix();
	glTranslated(800.0, 800.0, 2600.0);
	glutSolidSphere(radius, 36, 36);
	glPopMatrix();
}

void display(void)
{
	printf("Desenha...\n");						                // para controlo

	
	glLightf(GL_LIGHT0, GL_AMBIENT, const_at);

	// Posicionamento da luz
	glPushMatrix();
		glTranslatef(0.0, 0.0, 5000.0);
		glLightfv(GL_LIGHT0, GL_POSITION, pos_luz0);
	glPopMatrix();

	glLightf(GL_LIGHT1, GL_AMBIENT, const_at1);

	glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		glLightfv(GL_LIGHT1, GL_POSITION, pos_luz1);
		glutSolidSphere(100.0 / 2,
			16, 16);
	glPopMatrix();


	// posicionamento da câmara virtual com função gluLookAt
	glLoadIdentity();
	gluLookAt(camara_x, camara_y, camara_z, mira_x, mira_y, mira_z, 0, 0, 1);

	desenha_sol(0, 0, 10000, 400);
	desenha_topo_agua(4);
	//desenha_areia(0);
	desenha_eixos(6000);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, branco);
	desenhar_parede(vertices_parede1, texture_id, 0);
	desenhar_parede(vertices_parede2, texture_id, 0);
	desenhar_parede(vertices_parede3, texture_id, 0);
	desenhar_parede(vertices_areia, texture_id, 1);
	desenha_vidro(vertices_vidro);
	desenha_sala();

	gera_valores_bolhas();

	// Desenho de circulo (para ajuda ao posicionamento) e dos animais em si
	desenhar_circulo(20);
	desenhar_tubarao(800.0, 800.0, 2500.0);
	desenhar_goldfish(800.0, 800.0, 2400.0);
	
	float posicao_salmon[] = { 0.0f, 0.0f, 2400.0f };
	float rotacao_salmon[] = { 90.0f, 0.0f, 0.0f };
	float material_salmon[] = { 0.8f, 0.0f, 0.0f, 1.0f };
	desenhar_objeto_mat(salmon, posicao_salmon, rotacao_salmon, material_salmon);

	float posicao_goldfish[] = { 0.0f, 0.0f, 2300.0f };
	float rotacao_goldfish[] = { 90.0f, 0.0f, 0.0f };
	float material_goldfish[] = { 0.0f, 0.0f, 0.6f, 1.0f };
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture_id[1]);
	//desenhar_objeto_tex(goldfish, posicao_goldfish, rotacao_goldfish);
	glDisable(GL_TEXTURE_2D);

	glutSwapBuffers();
}

void tecla_especial_premida(int tecla, int x, int y)
{
	double k = 60;					        // o que a janela aumenta ou desloca

	double nx = mira_x - camara_x;		   // vector de orientação da câmara (x)
	double ny = mira_y - camara_y;		   // vector de orientação da câmara (y)
	double nz = mira_z - camara_z;		   // vector de orientação da câmara (z)

	double n = sqrt(nx*nx + ny*ny + nz*nz);	                      // norma do vector

	double x_mira = mira_x;
	double y_mira = mira_y;
	double xc = camara_x;
	double yc = camara_y;
	double teta = k / 180 * 3.14159265 / 10;

	nx /= n;						                                 // normalização
	ny /= n;
	nz /= n;

	switch (tecla)
	{
	case GLUT_KEY_UP:			    	                              // olhar para cima
		mira_z += k;
		break;

	case GLUT_KEY_DOWN:			           // olhar para baixo
		mira_z -= k;
		break;

	case GLUT_KEY_LEFT:			  	                        // olhar para a esquerda
		mira_x = cos(teta)*(x_mira - xc) - sin(teta)*(y_mira - yc) + xc;
		mira_y = sin(teta)*(x_mira - xc) + cos(teta)*(y_mira - yc) + yc;
		break;

	case GLUT_KEY_RIGHT:				  	                         // olhar para a direita
		mira_x = cos(-teta)*(x_mira - xc) - sin(-teta)*(y_mira - yc) + xc;
		mira_y = sin(-teta)*(x_mira - xc) + cos(-teta)*(y_mira - yc) + yc;
		break;

	default:				             // por defeito, não há nenhuma ação
		break;
	}
}

//
//	Função para controlo das ações nas teclas normais
//	tecla  - tecla premida
//	x,y	   - posição do cursor a tecla do rato e premida
//
void tecla_premida(unsigned char tecla, int x, int y)
{
	double k = 60;					        // o que a janela aumenta ou desloca

	double nx = mira_x - camara_x;		   // vector de orientação da câmara (x)
	double ny = mira_y - camara_y;		   // vector de orientação da câmara (y)
	double nz = mira_z - camara_z;		   // vector de orientação da câmara (z)

	double n = sqrt(nx*nx + ny*ny + nz*nz);	                      // norma do vector

	double x_mira = mira_x;
	double y_mira = mira_y;
	double xc = camara_x;
	double yc = camara_y;
	double teta = k / 180 * 3.14159265 / 10;

	nx /= n;						                                 // normalização
	ny /= n;
	nz /= n;

	switch (tecla)
	{
	case ESCAPE:			     // tecla de escape, para saída da aplicação
		exit(0);
		break;

	case 'w':			  	                              // andar em frente
			camara_x += nx*k;
			mira_x += nx*k;
			camara_y += ny*k;
			mira_y += ny*k;
			camara_z += nz*k;
			mira_z += nz*k;
		break;

	case 's':			  	                              // andar para trás
			camara_x -= nx*k;
			mira_x -= nx*k;
			camara_y -= ny*k;
			mira_y -= ny*k;
			camara_z -= nz*k;
			mira_z -= nz*k;
		break;

	default:			  	             // por defeito, não há nenhuma ação
		break;
	}
}


void redesenha_cena()
{
	glClearColor(ocean_blue[0], ocean_blue[1], ocean_blue[2], 1.0);   // definição da cor de limpeza da janela

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	  // limpeza dos buffers

	//glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);	  // definição do modelo
														  // de iluminação	
	display();						                      // desenho
}

//
//	Função de redimensionamento da janela
//
void redimensiona_janela(int param_largura, int param_altura)
{
	printf("Redimensiona_janela...\n");		      // para controlo (facultativo)

	if (param_altura == 0)					// teste se a janela está minimizada
	{
		return;
	}

	glViewport(0, 0, param_largura, param_altura);

	razao_aspeto = (double)param_largura / (double)param_altura;

	largura = param_largura;				// armazenamento da nova largura
	altura = param_altura;					// armazenamento da nova altura

	glMatrixMode(GL_PROJECTION);			// definição, como matriz activa,
											// da matriz de projecção

	glLoadIdentity();						// reset à matriz activa

	gluPerspective(campo_visao_y, razao_aspeto, limite_z_anterior,
		limite_z_posterior);

	glMatrixMode(GL_MODELVIEW);
}

//
//	Função para apresentar a Cena na janela de visualização
//
void mostra_cena(void)
{
	redesenha_cena();
}


//
//  Função de teclado
//
void teclado(unsigned char tecla, int x, int y)
{
	switch (tecla)
	{
	case 27:
		exit(0);
		break;

	default:
		break;
	}
}

void InitGLUT()
{

	// definição do modo inicial de visualização
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	// definição do tamanho inicial da janela de visualização
	glutInitWindowSize(largura, altura);

	// definição da posição inicial da janela
	glutInitWindowPosition(100, 100);

	// criação da janela de visualização
	glutCreateWindow("Aquario");

	// chamada da função de redimensionamento
	glutReshapeFunc(redimensiona_janela);

	// redesenho a cena
	glutDisplayFunc(redesenha_cena);

	// função de teclado
	glutKeyboardFunc(teclado);

	// ação quando uma tecla especial e premida
	glutSpecialFunc(tecla_especial_premida);

	// ação quando uma tecla e premida
	glutKeyboardFunc(tecla_premida);

	// função para ir mostrando a cena
	glutIdleFunc(mostra_cena);
}

void InitGL()
{
	// definição da cor do fundo da janela de visualização (azul celeste)
	glClearColor(0.7f, 0.7f, 1.0f, 0.0f);

	// parâmetros de profundidade
	// definição do valor de limpeza do buffer de profundidade
	glClearDepth(1.0);
	// definição da função de comparação de profundidade
	glDepthFunc(GL_LEQUAL);
	// activação do teste de profundidade
	glEnable(GL_DEPTH_TEST);

	glShadeModel(GL_SMOOTH);

	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	// modo de preenchimento de polígonos

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white);

	glEnable(GL_LIGHT1);

	glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT1, GL_SPECULAR, white);

	glMatrixMode(GL_MODELVIEW);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
}


// Define a textura a ser usada
void preparar_textura(void)
{
	// Habilita o uso de textura 
	//glEnable(GL_TEXTURE_2D);

	// Define a forma de armazenamento dos pixels na textura
	// (1 = alinhamento por byte)
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	// Define quantas texturas serão usadas no programa 
	glGenTextures(2, texture_id);  // 1 = uma textura;
								   // texture_id = vetor que guardas os números das texturas

								   // Define o número da textura do cubo.
	texture_id[0] = 1001;

	// Define que tipo de textura será usada
	// GL_TEXTURE_2D ==> define que será usada uma textura 2D (bitmaps)
	// texture_id[0]  ==> define o número da textura 
	glBindTexture(GL_TEXTURE_2D, texture_id[0]);
	// carrega a uma imagem TGA 
	image_t temp_image1;
	tgaLoad("aquario.tga", &temp_image1, TGA_FREE | TGA_LOW_QUALITY);


	texture_id[1] = 1002;
	glBindTexture(GL_TEXTURE_2D, texture_id[1]);
	image_t temp_image2;
	tgaLoad("areia.tga", &temp_image2, TGA_FREE | TGA_LOW_QUALITY);
}


////////////////////////////////////////////////////////////////////////////////
//	Programa Principal /////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main (int argc, char** argv)
{
	// Inicializa o GLUT
	glutInit(&argc, argv);

	InitGLUT();

	InitGL();

	preparar_modelos();
	preparar_bolhas();
	preparar_textura();

	// Obrigatório registar uma "callback function", neste caso de visualização
	glutDisplayFunc( display );

	// posicionamento da câmara virtual com função gluLookAt
	glLoadIdentity();

	// Esperando por eventos
	glutMainLoop();
					
    return EXIT_SUCCESS;
}
