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
extern float goldfish_color[4];
extern float goldfish_speed[4];
extern float goldfish_rotation[3];
extern float goldfish_orientation[4];

GLMmodel* manatee;
extern float manatee_color[4];
extern float manatee_speed[4];
extern float manatee_rotation[3];
extern float manatee_orientation[4];

GLMmodel* orca;
extern float orca_color[4];
extern float orca_speed[4];
extern float orca_rotation[3];
extern float orca_orientation[4];

GLMmodel* salmon;
extern float salmon_color[4];
extern float salmon_speed[4];
extern float salmon_rotation[3];
extern float salmon_orientation[4];

GLMmodel* shark;
extern float shark_color[4];
extern float shark_speed[4];
extern float shark_rotation[3];
extern float shark_orientation[4];

GLMmodel* tiger_shark;
extern float tiger_shark_color[4];
extern float tiger_shark_speed[4];
extern float tiger_shark_rotation[3];
extern float tiger_shark_orientation[4];

GLMmodel* trout;
extern float trout_color[4];
extern float trout_speed[4];
extern float trout_rotation[3];
extern float trout_orientation[4];

GLMmodel* tuna;
extern float tuna_color[4];
extern float tuna_speed[4];
extern float tuna_rotation[3];
extern float tuna_orientation[4];
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


