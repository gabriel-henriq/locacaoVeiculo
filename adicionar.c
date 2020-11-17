void sistemaPrincipal(void);
void adicionarCarro(void) {
	
	estruturaBasica();
	
	gotoxy(40,3);
	printf("Adicionar");
	
	char tmpName[26];
	int tmpNum;
	
	while(tmpNum != 27) {
		
		if(NUM_ID > 15) {
			do{
				gotoxy(18,7);
				printf("Voce atingiu o nivel maximo de armazenamento de dados.");
				gotoxy(20,9);
				printf("Exclua algum dado para adicionar um novo.");
				gotoxy(22,20);
				printf("Apenas sair e manter dados em memoria. [ESC]");
				gotoxy(20,22);
				printf("Salvar e Sair [S]");
				tmpNum = getch();
				if(tmpNum == 27) {
					sistemaPrincipal();
				}
				else if(tmpNum == 83 || tmpNum == 115) {
					FILE *database;
					database = fopen("database.txt", "w");
					int j;
					for (j=0; j < NUM_ID; j++) {
						fwrite(&nCarro[j], sizeof(struct tipoCarro), 1, database);
					}
					fclose(database);
					sistemaPrincipal();		
				}				
			} while(1);
		}
		
		nCarro[NUM_ID].carroID = NUM_ID;
		
		
		gotoxy(30,10);
		printf("Digite o nome da marca: ");
		fgets(tmpName, 25, stdin);
		strcpy(nCarro[NUM_ID].marca,tmpName);
		fflush(stdin);
		
		
		gotoxy(30,10);
		printf("                                       ");
		gotoxy(30,10);
		printf("Digite o nome do modelo: ");
		fgets(tmpName, 25,stdin);
		strcpy(nCarro[NUM_ID].modelo,tmpName);
		fflush(stdin);	
	
		
		gotoxy(30,10);
		printf("                                        ");
		gotoxy(30,10);
		printf("Digite o nome da cor: ");
		fgets(tmpName,20,stdin);
		strcpy(nCarro[NUM_ID].cor,tmpName);
		fflush(stdin);
		
		gotoxy(30,10);
		printf("                                       ");
		gotoxy(30,10);
		printf("Digite o nome do ano: ");
		scanf("%d", &tmpNum);	
		nCarro[NUM_ID].ano = tmpNum;
		fflush(stdin);	
		NUM_ID++;
		
		gotoxy(30,10);
		printf("                                       ");
		gotoxy(40,10);
		printf("Sair [ESC]");
		gotoxy(36,12);
		printf("Salvar e Sair [S]");
		gotoxy(33,14);
		printf("Continuar [Qualquer tecla]");
		tmpNum = getch();
		if(tmpNum == 83 || tmpNum == 115) {
			FILE *database;
			database = fopen("database.txt", "w");
			int j;
			for (j=0; j < NUM_ID; j++) {
				fwrite(&nCarro[j], sizeof(struct tipoCarro), 1, database);
			}
			fclose(database);
			break;		
		}
		gotoxy(36,12);
		printf("                               ");
		gotoxy(33,14);
		printf("                               ");
		
	}
}
