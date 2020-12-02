void pesquisaID(void) {
	int id, i, naoExiste = 0;
	
	gotoxy(30,12);
	printf("Digite o ID: ");
	scanf("%d", &id);
	
	estruturaBasica();
	//Imprime a busca caso seja passível da condição.
	for(i=0;i<NUM_ID;i++){
		if(nCarro[i].carroID == id && nCarro[i].deletado != 1){
			estruturaBasica();
	    	imprimeNomeDados("ID","MARCA","MODELO","COR","ANO");
	    	gotoxy(20,6);
			printf("%d", nCarro[i].carroID);
			gotoxy(25,6);
			printf("%s", nCarro[i].marca);
			gotoxy(40,6);
			printf("%s", nCarro[i].modelo);
			gotoxy(53,6);
			printf("%s", nCarro[i].cor);
			gotoxy(65,6);
			printf("%s", nCarro[i].ano);
		}
		else {
			naoExiste++;
		}
	}
	if(naoExiste == NUM_ID) {
		gotoxy(35,12);
		printf("Este ID nao existe.");
		
	}	
}
