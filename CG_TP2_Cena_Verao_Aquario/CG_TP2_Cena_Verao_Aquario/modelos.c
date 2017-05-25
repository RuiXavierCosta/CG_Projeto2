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
#include "modelos.h"

//
//	Definições /////////////////////////////////////////////////////////////////
//
// Exemplo da definição de uma constante
#define PI    3.1415927
//
//	Funções ////////////////////////////////////////////////////////////////////
//
void importar_modelos(void)
{
	goldfish = glmReadOBJ("models/goldfish/GOLDFISH.OBJ");
	manatee = glmReadOBJ("models/manatee/MANATEE1.OBJ");
	orca = glmReadOBJ("models/orca/ORCA.OBJ");
	salmon = glmReadOBJ("models/salmon/SALMON.OBJ");
	shark = glmReadOBJ("models/shark/Shark.obj");
	tiger_shark = glmReadOBJ("models/tiger_shark/TGRSHARK.OBJ");
	trout = glmReadOBJ("models/trout/RB_TROUT.OBJ");
	tuna = glmReadOBJ("models/tuna/TUNA.OBJ");
}