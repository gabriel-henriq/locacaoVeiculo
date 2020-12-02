void imprimirListaDeCarros(void) {	
	int i = 0, j = 0;
	gotoxy(18,22);
	printf("Total de items cadastrados: %d", NUM_ID - DEL_ID);
	imprimeNomeDados("ID","MARCA","MODELO","COR","ANO");
    for(i = 0; i < NUM_ID; i++) {
    	if(nCarro[i].deletado == 1) {
    		j++;
		}
		/* Para cada iteração do for declarado, abre-se uma condição
		 para verificar se o carro foi inativado ou se o id é diferente 0 para imprimir*/
    	if(nCarro[i].deletado != 1 && nCarro[i].carroID != 0) {
	    	gotoxy(20,i+6-j);
	    	printf("%d", nCarro[i].carroID);
	    	gotoxy(25,i+6-j);
	    	printf("%s", nCarro[i].marca);
	    	gotoxy(40,i+6-j);
	    	printf("%s", nCarro[i].modelo);
	    	gotoxy(53,i+6-j);
	    	printf("%s", nCarro[i].cor);
	    	gotoxy(65,i+6-j);
	    	printf("%s", nCarro[i].ano);	
		}
	}
}
