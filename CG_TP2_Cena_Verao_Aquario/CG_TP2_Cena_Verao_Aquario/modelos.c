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

float goldfish_color[4] = { 251.0 / 255.0 ,137.0 / 255.0 ,2.0 / 255.0, 1.0 };
float manatee_color[4] = { 194.0 / 255.0, 181.0 / 255.0, 182.0 / 255.0, 1.0 };
float orca_color[4] = { 18.0 / 255.0, 21.0 / 255.0, 26.0 / 255.0, 1.0 };
float salmon_color[4] = { 202.0 / 255.0, 217.0 / 255.0, 185.0 / 255.0, 1.0 };
float shark_color[4] = { 81.0 / 255.0, 98.0 / 255.0, 106.0 / 255.0, 1.0 };
float tiger_shark_color[4] = { 93.0 / 255.0, 88.0 / 255.0, 69.0 / 255.0, 1.0 };
float trout_color[4] = { 164.0 / 255.0, 120.0 / 255.0, 75.0 / 255.0, 1.0 };
float tuna_color[4] = { 51.0 / 255.0, 126.0 / 255.0, 223.0 / 255.0, 1.0 };

float goldfish_speed[4] = {10.0, 10.0, 10.0, 0.0};
float manatee_speed[4] = {2.0, 2.0, 2.0, 1.0 };
float orca_speed[4] = {11.0, 11.0, 8.0, 1.0 };
float salmon_speed[4] = {13.0, 13.0, 13.0, 0.0 };
float shark_speed[4] = { 4.0, 4.0, 4.0, 0.0 };
float tiger_shark_speed[4] = { 3.0, 3.0, 1.0, 0.0 };
float trout_speed[4] = {12.0, 12.0, 12.0, 0.0 };
float tuna_speed[4] = {8.0, 8.0, 5.0, 0.0 };

float goldfish_rotation[3];
float manatee_rotation[3];
float orca_rotation[3];
float salmon_rotation[3];
float shark_rotation[3];
float tiger_shark_rotation[3];
float trout_rotation[3];
float tuna_rotation[3];

float goldfish_orientation[4] = { 90.0, 80.0, 0.0, 0 };
float manatee_orientation[4] = { 90.0, 30.0, 0.0, 0 };
float orca_orientation[4] = { 90.0, 73.0, 0.0, 0 };
float salmon_orientation[4] = { 90.0, 23.0, 0.0, 0 };
float shark_orientation[4] = { 90.0, 42.0, 0.0, 0 };
float tiger_shark_orientation[4] = { 90.0, 71.0, 0.0, 0 };
float trout_orientation[4] = { 90.0, 220.0, 0.0, 0 };
float tuna_orientation[4] = { 90.0, 78.0, 0.0, 0 };
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
	glmUnitize(orca);
	glmFacetNormals(orca);
	glmVertexNormals(orca, 90.0);

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

void preparar_modelos()
{
	for (int i = 0; i < 3; i++)
	{
		goldfish_rotation[i] = goldfish_orientation[i];
		manatee_rotation[i] = manatee_orientation[i];
		orca_rotation[i] = orca_orientation[i];
		salmon_rotation[i] = salmon_orientation[i];
		shark_rotation[i] = shark_orientation[i];
		tiger_shark_rotation[i] = tiger_shark_orientation[i];
		trout_rotation[i] = trout_orientation[i];
		tuna_rotation[i] = tuna_orientation[i];
	}

	importar_modelos();
	glmScale(goldfish, 80.0f);
	glmScale(manatee, 700.0f);
	glmScale(orca, 1500.0f);
	glmScale(salmon, 100.0f);
	glmScale(shark, 800.0f);
	glmScale(tiger_shark, 600.0f);
	glmScale(trout, 100.0f);
	glmScale(tuna, 250.0f);
}
