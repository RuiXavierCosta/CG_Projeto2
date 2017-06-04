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

extern const float light_blue[4];
extern const float sand_yellow[4];
extern const float sun_yellow[4];
extern const float bubble_blue[4];
extern const float black[4];
extern const float white[4];
extern const float baca[];
//
//	Funções ////////////////////////////////////////////////////////////////////
//
//<funcoes, divididas por grupos funcionais>
void desenha_sol(double x, double y, double z, double diametro);

void desenha_topo_agua(double z);

void desenha_eixos(float comprimento_eixo);

void desenha_areia(double z);

void desenha_bolha(double x, double y, double z, double diametro);

void desenha_cluster_bolhas(float array_x[], float array_y[], float array_z[], float base_bolhas, float array_diam[], int num_bolhas);

float randf(float min, float max);

void desenhar_parede(float vertices_parede[8][3], GLuint texture_id[1], int id);

void desenha_vidro(float vertices_parede[8][3]);

void desenha_betao(float vertices_parede[8][3]);

void desenha_sala();

void desenha_peixes();
//
//	Fim do ficheiro de interface ///////////////////////////////////////////////
//
#endif