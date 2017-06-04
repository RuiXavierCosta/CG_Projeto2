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
float goldfish_color[4];
float goldfish_speed[4];
float goldfish_rotation[3];
float goldfish_orientation[4];

GLMmodel* manatee;
float manatee_color[4];
float manatee_speed[4];
float manatee_rotation[3];
float manatee_orientation[4];

GLMmodel* orca;
float orca_color[4];
float orca_speed[4];
float orca_rotation[3];
float orca_orientation[4];

GLMmodel* salmon;
float salmon_color[4];
float salmon_speed[4];
float salmon_rotation[3];
float salmon_orientation[4];

GLMmodel* shark;
float shark_color[4];
float shark_speed[4];
float shark_rotation[3];
float shark_orientation[4];

GLMmodel* tiger_shark;
float tiger_shark_color[4];
float tiger_shark_speed[4];
float tiger_shark_rotation[3];
float tiger_shark_orientation[4];

GLMmodel* trout;
float trout_color[4];
float trout_speed[4];
float trout_rotation[3];
float trout_orientation[4];

GLMmodel* tuna;
float tuna_color[4];
float tuna_speed[4];
float tuna_rotation[3];
float tuna_orientation[4];
//
//	Funções ////////////////////////////////////////////////////////////////////
//

//  Função para importar os modelos a usar na cena a partir dos respetivos ficheiros OBJ
void importar_modelos(void);

//	Função para preparar os modelos para uso
void preparar_modelos(void);

//
//	Fim do ficheiro de interface ///////////////////////////////////////////////
//


