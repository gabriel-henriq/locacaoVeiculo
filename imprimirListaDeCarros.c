void imprimirListaDeCarros(void) {	
	int i = 0;
	gotoxy(20,5);
	printf("ID");
	gotoxy(25,5);
	printf("MARCA");
	gotoxy(40,5);
	printf("MODELO");
	gotoxy(53,5);
	printf("COR");
	gotoxy(65,5);
	printf("ANO");
    for(i = 0; i < NUM_ID; i++) {
    	gotoxy(20,i+7);
    	printf("%d", nCarro[i].carroID);
    	gotoxy(25,i+7);
    	printf("%s", nCarro[i].marca);
    	gotoxy(40,i+7);
    	printf("%s", nCarro[i].modelo);
    	gotoxy(53,i+7);
    	printf("%s", nCarro[i].cor);
    	gotoxy(65,i+7);
    	printf("%d", nCarro[i].ano);
	}
}
