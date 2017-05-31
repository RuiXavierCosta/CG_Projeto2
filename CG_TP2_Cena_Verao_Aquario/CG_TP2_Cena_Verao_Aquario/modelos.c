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
	glmUnitize(goldfish);
	glmFacetNormals(goldfish);
	glmVertexNormals(goldfish, 90.0);

	manatee = glmReadOBJ("models/manatee/MANATEE1.OBJ");
	glmUnitize(manatee);
	glmFacetNormals(manatee);
	glmVertexNormals(manatee, 90.0);

	orca = glmReadOBJ("models/orca/ORCA.OBJ");
	glmUnitize(goldfish);
	glmFacetNormals(goldfish);
	glmVertexNormals(goldfish, 90.0);

	salmon = glmReadOBJ("models/salmon/SALMON.OBJ");
	glmUnitize(salmon);
	glmFacetNormals(salmon);
	glmVertexNormals(salmon, 90.0);

	shark = glmReadOBJ("models/shark/Shark.obj");
	glmUnitize(shark);
	glmFacetNormals(shark);
	glmVertexNormals(shark, 90.0);

	tiger_shark = glmReadOBJ("models/tiger_shark/TGRSHARK.OBJ");
	glmUnitize(tiger_shark);
	glmFacetNormals(tiger_shark);
	glmVertexNormals(tiger_shark, 90.0);

	trout = glmReadOBJ("models/trout/RB_TROUT.OBJ");
	glmUnitize(trout);
	glmFacetNormals(trout);
	glmVertexNormals(trout, 90.0);

	tuna = glmReadOBJ("models/tuna/TUNA.OBJ");
	glmUnitize(tuna);
	glmFacetNormals(tuna);
	glmVertexNormals(tuna, 90.0);
}