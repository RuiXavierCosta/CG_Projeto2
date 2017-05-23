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
//
//	Definições /////////////////////////////////////////////////////////////////
//
// Exemplo da definição de uma constante
#define PI    3.1415927
//
//	Funções ////////////////////////////////////////////////////////////////////
//
void display( void )
{
	// Limpa a janela
	glClear( GL_COLOR_BUFFER_BIT );
      
	// Desencadeia a geração da imagem (rendering)
	glFlush();
}

////////////////////////////////////////////////////////////////////////////////
//	Programa Principal /////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main (int argc, char** argv)
{
	// Inicializa o GLUT
	glutInit(&argc, argv);
 
	// Cria a janela GLUT de visualização
	glutCreateWindow( "Aquario" );

	// Obrigatório registar uma "callback function", neste caso de visualização
	glutDisplayFunc( display );

	// Esperando por eventos
	glutMainLoop();
					
    return EXIT_SUCCESS;
}