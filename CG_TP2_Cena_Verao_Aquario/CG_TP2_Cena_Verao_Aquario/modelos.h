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
#include "glm.h"

GLMmodel* goldfish;
GLMmodel* manatee;
GLMmodel* orca;
GLMmodel* salmon;
GLMmodel* shark;
GLMmodel* tiger_shark;
GLMmodel* trout;
GLMmodel* tuna;
//
//	Funções ////////////////////////////////////////////////////////////////////
//

//  Função para importar os modelos a usar na cena a partir dos respetivos ficheiros OBJ
void importar_modelos(void);

//
//	Fim do ficheiro de interface ///////////////////////////////////////////////
//


