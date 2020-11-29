/*==========================    Loca��o de Carros         =====================*
============================  Author: Gabriel Henrique    =====================*
============================ Professor: Rosemari Pavan    =====================*
============================ Cam�es Faculdades Integradas =====================*
*/
//============================================
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <windows.h>
#include <conio.h>
//============================================
#include "globais.c"
#include "utilitarias.c"
#include "estruturarCarro.c"
#include "carregarDados.c"
#include "adicionar.c"
#include "imprimirListaDeCarros.c"
#include "menu.c"
#include "menuPesquisar.c"
#include "relatorioMarca.c"
#include "relatorioModelo.c"
#include "relatorioCor.c"
#include "relatorioAno.c"
#include "menuRelatorioFiltro.c"
#include "pesquisaID.c"

int main(void) {

	carregarDados();
	
	sistemaPrincipal();
    

    return EXIT_SUCCESS; 
} 


