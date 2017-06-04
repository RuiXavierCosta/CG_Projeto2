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

void desenhar_objeto_mat(GLMmodel *objeto, float posicao[3], float rotacao[3], float mat_diffuse[4]);

void abana_animal(float rotacao_animal[3], float velocidade_animal[4], float orientacao_animal[4]);
void move_animal(float posicao_animal[3], float velocidade_animal[4], float orientacao_animal[4]);

//
//	Fim do ficheiro de interface ///////////////////////////////////////////////
//


