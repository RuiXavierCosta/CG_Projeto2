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
//	Fun��es ////////////////////////////////////////////////////////////////////
//

//  Fun��o para importar os modelos a usar na cena a partir dos respetivos ficheiros OBJ
void importar_modelos(void);

//	Fun��o para preparar os modelos para uso
void preparar_modelos(void);

//
//	Fim do ficheiro de interface ///////////////////////////////////////////////
//


