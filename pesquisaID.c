void pesquisaID(void) {
	int id, i, naoExiste = 0, numValido, opcao;
	do{
		numValido = 1;
		fflush(stdin);
		gotoxy(26,10);
		printf("Digite o ID que deseja pesquisar: ");
		scanf("%d", &id);
		if(id == 0) {
			gotoxy(30,12);
			printf("Este ID nao existe.");
			gotoxy(26,17);
			printf("Voltar[ESC]");
			gotoxy(40,17);
			printf("Tentar outro ID[Enter]");
			opcao = getch();
			if(opcao == 27) {
				sistemaPrincipal();
			}
			else{
				for(i=18;i<70;i++) {
					gotoxy(i,17);
					printf(" ");
					gotoxy(i,12);
					printf(" ");
					gotoxy(i,10);
					printf(" ");
				}
				naoExiste = 0;
				pesquisaID();
			}	
		}
		else {
			numValido == 1;
		}
		
	}while(numValido == 0);
	//Imprime a busca caso seja passível da condição.
	for(i=0;i<NUM_ID;i++){
		if(nCarro[i].carroID == id && nCarro[i].deletado != 1){
			estruturaBasica();
			gotoxy(35,2);
			printf("Pesquisa por ID");
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
			printf("%d", nCarro[i].ano);
		}
		else {
			naoExiste++;
		}
	}
	if(naoExiste == NUM_ID) {
		gotoxy(35,2);
		printf("Pesquisa por ID");
	}	
}
