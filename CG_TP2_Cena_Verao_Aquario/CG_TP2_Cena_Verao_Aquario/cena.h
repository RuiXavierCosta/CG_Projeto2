/******************************************************************************/
/**                                                    ,---------------.     **/
/**    COMPUTACAO GRAFICA                              |        .-.    |     **/
/**    MIEEC - FCTUC                                   |        !o|    |     **/
/**                                                    |>-,   ,-' | ,-<|     **/
/**    AUTORES: - ...................                  |  `---'   `-'  |     **/
/**             - ...................                  `---------------'     **/
/******************************************************************************/
/* DESCRICAO: Texto que devera descrever o âmbito deste ficheiro de ........  */
/*            interface ....................................................  */
/*		      ..............................................................  */
/******************************************************************************/
//
//	Proteção do ficheiro de interface /////////////////////////////////////////
//
#ifndef CENA
#define CENA
//
//	Definições /////////////////////////////////////////////////////////////////
//
//<incluir as definicoes necessarias>
#include <math.h>

const float light_blue[4];
const float sand_yellow[4];
const float sun_yellow[4];
const float bubble_blue[4];
const float black[4];
const float white[4];
const float baca[];
//
//	Funções ////////////////////////////////////////////////////////////////////
//
//<funcoes, divididas por grupos funcionais>
void desenha_sol(double x, double y, double z, double diametro);

void desenha_topo_agua(double z);

void desenha_eixos(float comprimento_eixo);

void desenha_areia(double z);

void desenha_bolha(double x, double y, double z, double diametro);
//
//	Fim do ficheiro de interface ///////////////////////////////////////////////
//
#endif