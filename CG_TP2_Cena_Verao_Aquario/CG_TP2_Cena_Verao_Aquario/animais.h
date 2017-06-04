/******************************************************************************/
/**                                                    ,---------------.     **/
/**    COMPUTACAO GRAFICA                              |        .-.    |     **/
/**    MIEEC - FCTUC                                   |        !o|    |     **/
/**                                                    |>-,   ,-' | ,-<|     **/
/**    AUTORES: - Filipe Cabeleira                     |  `---'   `-'  |     **/
/**             - Rui Xavier Costa                     `---------------'     **/
/******************************************************************************/
/* DESCRICAO: Texto que devera descrever o �mbito deste ficheiro de ........  */
/*            interface ....................................................  */
/*		      ..............................................................  */
/******************************************************************************/
//
//	Prote��o do ficheiro de interface /////////////////////////////////////////
//
#pragma once
//
//	Defini��es /////////////////////////////////////////////////////////////////
//
#include "modelos.h"
//
//	Fun��es ////////////////////////////////////////////////////////////////////
//

// Desenha o tubar�o
void desenhar_tubarao(float pos_x, float pos_y, float pos_z);

// Desenha o peixe dourado
void desenhar_goldfish(float pos_x, float pos_y, float pos_z);

// Desenha o objeto especificado
void desenhar_objeto(GLMmodel *objeto, float posicao[3], float rotacao[3]);
void desenhar_objeto_tex(GLMmodel *objeto, float posicao[3], float rotacao[3]);
void desenhar_objeto_mat(GLMmodel *objeto, float posicao[3], float rotacao[3], float mat_diffuse[4]);

//
//	Fim do ficheiro de interface ///////////////////////////////////////////////
//


