void alterarVeiculo() {
	int numValido, id, opcao, i, naoExiste = 0;
	do{
		numValido = 1;
		fflush(stdin);
		gotoxy(26,10);
		printf("Digite o ID que deseja alterar: ");
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
				}
				alterarVeiculo();
			}
			fflush(stdin);
			for(i=18;i<70;i++) {	
			gotoxy(i,10);
			printf(" ");
			}
		}
		else {
			numValido == 1;
			for(i=18;i<70;i++) {	
			gotoxy(i,13);
			printf(" ");
			}
		}
	}while(numValido == 0);
	
	for (i = 0; i < NUM_ID; i++) {
		if(nCarro[i].deletado == 1 && nCarro[i].carroID == id) {
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
				limpaTela();
				estruturaBasica();
				gotoxy(40,3);
				printf("Alterar");
				alterarVeiculo();
				gotoxy(60,22);
				printf("VOLTAR [ESC]");
				apertarESC();
				alterarVeiculo();
			}
			fflush(stdin);
			for(i=18;i<70;i++) {	
			gotoxy(i,10);
			printf(" ");
			}
		}
		else 
			if(id == nCarro[i].carroID && nCarro[i].deletado != 1) {
				limpaTela();
				estruturaBasica();
				gotoxy(40,3);
				printf("Alterar");
				coletarPalavra(nCarro[i].marca, 15,"Novo nome para marca: ");
				coletarPalavra(nCarro[i].modelo, 11,"Novo nome para modelo: ");
				coletarPalavra(nCarro[i].cor, 11,"Novo nome para cor: ");      
				leAno(nCarro[i].ano,"Novo ano: ");
				
				FILE *database;
				database = fopen("database.txt", "w");
				int j;
				for (j=0; j < NUM_ID; j++) {
					fwrite(&nCarro[j], sizeof(struct tipoCarro), 1, database);
				}
				fclose(database);
			}
			else {
				naoExiste++;
			}
	}
	if(naoExiste == NUM_ID) {
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
			limpaTela();
			estruturaBasica();
			gotoxy(40,3);
			printf("Alterar");
			alterarVeiculo();
			gotoxy(60,22);
			printf("VOLTAR [ESC]");
			apertarESC();
			alterarVeiculo();
		}
		fflush(stdin);
		for(i=18;i<70;i++) {	
		gotoxy(i,10);
		printf(" ");
		}
	}
}
