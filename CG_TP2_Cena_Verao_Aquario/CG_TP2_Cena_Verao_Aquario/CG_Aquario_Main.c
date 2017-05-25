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
#include "glm.h"
#include "cena.h"
//
//	Definições /////////////////////////////////////////////////////////////////
//
// Exemplo da definição de uma constante
#define PI    3.1415927

double ocean_blue[3] = { 0.0117647058823529, 0.4431372549019608, 0.6117647058823529 };
int largura = 1024;					  // largura da nossa janela de visualização
int altura = 768;					   // altura da nossa janela de visualização

double razao_aspeto = 1;		   // razão de aspecto da janela de visualização

double limite_z_anterior = 1;			            // plano de recorte anterior
double limite_z_posterior = 20000;		           // plano de recorte posterior

double camara_x = 1500;					                // posição da câmara (x)
double camara_y = 1500;					                // posição da câmara (y)
double camara_z = 750;					                // posição da câmara (z)

double mira_x = 0;				        // direção de visualização da câmara (x)
double mira_y = 0;				        // direção de visualização da câmara (y)
double mira_z = 2;				        // direção de visualização da câmara (z)

double teta_x = 0;				                         // orientação da câmara
double teta_z = 0;				                         // orientação da câmara
double campo_visao_y = 50;		                          // campo de visão em y

														  // Posição da fonte de iluminação na origem
const float pos_luz[] = { 0.0, 0.0, 1.0, 1.0 };

					  // Fator de atenuação da luz
float const_at = 1.0;
//
//	Funções ////////////////////////////////////////////////////////////////////
//

//
//	Função de inicialização das diversas configurações do GLUT
//

void display(void)
{
	printf("Desenha...\n");						                // para controlo

																// posicionamento da câmara virtual com transformações elementares
	glLoadIdentity();
	glTranslatef(-camara_x, -camara_y, -camara_z);
	glRotatef(teta_x, 1, 0, 0);
	glRotatef(teta_z, 0, 0, 1);
	glScalef(1, 1, 1);

	// Posicionamento da luz
	glPushMatrix();
	glTranslatef(0.0, 0.0, 3000);
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, const_at);
	glLightfv(GL_LIGHT0, GL_POSITION, pos_luz);
	glDisable(GL_LIGHTING);

	glEnable(GL_LIGHTING);
	glPopMatrix();


	// posicionamento da câmara virtual com função gluLookAt
	glLoadIdentity();
	gluLookAt(camara_x, camara_y, camara_z, mira_x, mira_y, mira_z, 0, 0, 1);


	desenha_sol(0, 0, 3000, 100);
	desenha_topo_agua(2);
	desenha_areia(-2);
	desenha_eixos(6000);
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
void teclado(int tecla, int x, int y)
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

	glMatrixMode(GL_MODELVIEW);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
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

	// Obrigatório registar uma "callback function", neste caso de visualização
	glutDisplayFunc( display );

	// posicionamento da câmara virtual com função gluLookAt
	glLoadIdentity();
	// Esperando por eventos
	glutMainLoop();
					
    return EXIT_SUCCESS;
}