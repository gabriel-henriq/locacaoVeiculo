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
#include "estruturaCarro.c"
#include "adicionar.c"
#include "alternaLista.c"
#include "ordenaLista.c"
#include "imprimeLista.c"
#include "menuSalvar.c"
#include "menu.c"
#include "salvarEstrutura.c"
#include "carregarDatabase.c"


int main(void) {
	
	
	carregarDatabase();
	
	sistemaPrincipal();
    

    return EXIT_SUCCESS; 
} 


