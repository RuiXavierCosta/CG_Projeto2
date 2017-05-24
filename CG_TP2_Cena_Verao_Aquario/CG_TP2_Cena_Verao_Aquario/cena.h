/******************************************************************************/
/**                                                    ,---------------.     **/
/**    COMPUTACAO GRAFICA                              |        .-.    |     **/
/**    MIEEC - FCTUC                                   |        !o|    |     **/
/**                                                    |>-,   ,-' | ,-<|     **/
/**    AUTORES: - ...................                  |  `---'   `-'  |     **/
/**             - ...................                  `---------------'     **/
/******************************************************************************/
/* DESCRICAO: Texto que devera descrever o �mbito deste ficheiro de ........  */
/*            interface ....................................................  */
/*		      ..............................................................  */
/******************************************************************************/
//
//	Prote��o do ficheiro de interface /////////////////////////////////////////
//
#ifndef CENA
#define CENA
//
//	Defini��es /////////////////////////////////////////////////////////////////
//
//<incluir as definicoes necessarias>
//
//	Fun��es ////////////////////////////////////////////////////////////////////
//
//<funcoes, divididas por grupos funcionais>
void desenha_sol(double x, double y, double z, double diametro);

void desenha_topo_agua(double z);

void desenha_eixos(float comprimento_eixo);

void desenha_areia(double z);
//
//	Fim do ficheiro de interface ///////////////////////////////////////////////
//
#endif