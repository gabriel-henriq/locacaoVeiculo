void imprimirListaDeCarros(void);
void excluirVeiculo(void){ 
	
	int id = 0, opcao, i, naoExiste = 0, numValido;
	
	limpaEspacos(0,0);
	imprimeCreditos();
	bordasMenu();
	gotoxy(28,3);
	printf("E x c l u i r  V e i c u l o");
	gotoxy(26,8);
	printf("Digite 99 para imprimir todos os items.");
	// Valida se o ID digitado � um n�mero e oferece a op��o de voltar ao menu ou tentar outro ID
	do{
		numValido = 1;
		fflush(stdin);
		gotoxy(26,10);
		printf("Digite o ID que deseja excluir: ");
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
			excluirVeiculo();
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
	// Caso o usu�rio digite o valor 99, a fun��o imprime todos os ve�culos cadastrados no sistema.
	if(id == 99) {
		limpaTela();
		estruturaBasica();
		imprimirListaDeCarros();
		gotoxy(60,22);
		printf("VOLTAR [ESC]");
		opcao = getch();	
		if (opcao == 27) {
			limpaTela();
			excluirVeiculo();
		}
	}
	// Inativa o ve�culo do sistema alterando o valor da vari�vel deletado para 1.
	for(i=0;i<NUM_ID;i++){
		// Verifica se o id digitado � igual ao valor do id da estrutura �ndice i e se o valor deletado � diferente de 1.
		if(nCarro[i].carroID == id && nCarro[i].deletado != 1){ 
		// Salva o ID no array de ve�culos deletados.
			ARRAY_DEL[DEL_ID] = id;
			nCarro[i].deletado = 1;
			DEL_ID++;
			gotoxy(20,12);
			printf("O veiculo do ID igual a %d foi inativado do sistema!", id);
			
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
	if(naoExiste == NUM_ID && nCarro[NUM_ID].carroID != id)  {
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
			excluirVeiculo();
		}
		
	}
	
}
