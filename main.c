/*==========================    Locação de Carros         =====================*
============================  Author: Gabriel Henrique    =====================*
============================ Professor: Rosemari Pavan    =====================*
============================ Camões Faculdades Integradas =====================*
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
#include "imprimirLista.c"
#include "menu.c"



int main(void) {
	
	carregarDados();
	
	sistemaPrincipal();
    

    return EXIT_SUCCESS; 
} 


