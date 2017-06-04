/******************************************************************************/
/**                                                    ,---------------.     **/
/**    COMPUTACAO GRAFICA                              |        .-.    |     **/
/**    MIEEC - FCTUC                                   |        !o|    |     **/
/**                                                    |>-,   ,-' | ,-<|     **/
/**    AUTORES: - Filipe Cabeleira                     |  `---'   `-'  |     **/
/**             - Rui Xavier Costa                     `---------------'     **/
/******************************************************************************/
/* DESCRICAO: Texto que devera descrever o âmbito deste ficheiro de ........  */
/*            interface ....................................................  */
/*		      ..............................................................  */
/******************************************************************************/
//
//	Proteção do ficheiro de interface /////////////////////////////////////////
//
#pragma once
//
//	Definições /////////////////////////////////////////////////////////////////
//
#include "modelos.h"
//
//	Funções ////////////////////////////////////////////////////////////////////
//

void desenhar_objeto_mat(GLMmodel *objeto, float posicao[3], float rotacao[3], float mat_diffuse[4]);

void abana_animal(float rotacao_animal[3], float velocidade_animal[4], float orientacao_animal[4]);
void move_animal(float posicao_animal[3], float velocidade_animal[4], float orientacao_animal[4]);

//
//	Fim do ficheiro de interface ///////////////////////////////////////////////
//


