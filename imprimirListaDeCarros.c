void imprimirListaDeCarros(void) {	
	int i = 0;
	gotoxy(18,22);
	printf("Total de items cadastrados: %d", NUM_ID);
	imprimeNomeDados("ID","MARCA","MODELO","COR","ANO");
    for(i = 0; i < NUM_ID; i++) {
    	gotoxy(20,i+6);
    	printf("%d", nCarro[i].carroID);
    	gotoxy(25,i+6);
    	printf("%s", nCarro[i].marca);
    	gotoxy(40,i+6);
    	printf("%s", nCarro[i].modelo);
    	gotoxy(53,i+6);
    	printf("%s", nCarro[i].cor);
    	gotoxy(65,i+6);
    	printf("%d", nCarro[i].ano);
	}
}
