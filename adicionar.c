void sistemaPrincipal(void);
int ehLetraOuEspaco(char* palavra) { // Verifica se a palavra possui espa�o ou letras (isalpha) e retorna 0 caso tenha outro tipo de caractere.
	int i;
	for(i=0; i<strlen(palavra); i++) {
		if(palavra[i] != ' ' && !isalpha(palavra[i])) {
			return 0;
		}
	}
	return 1;
}
void lerStringSeguramente(char* palavra, int tamanho) { // Remove o \n da palavra.
	fflush(stdin);
	if(fgets(palavra, tamanho, stdin) != NULL) {
		/* Remove a nova linha (\n), caso ela tenha sido lida pelo scanf */
		int indiceUltimoCaractere = strlen(palavra) - 1;
		if(palavra[indiceUltimoCaractere] == '\n') {
			palavra[indiceUltimoCaractere] = '\0';
		}
		fflush(stdin);
	}
}
int contarLetras(char* palavra) { //Conta quantas letras com a fun��o isalpha existem na palavra e retorna a quantidade de letras.
	int i, quantidadeLetras=0;
	for(i=0; i<strlen(palavra); i++) {
		if(isalpha(palavra[i])) {
			quantidadeLetras++;
		}
	}
	return quantidadeLetras;
}
void paraMaiusculo(char* palavraParaMudar) { // Passa a palavra para mai�sculo.
	int i;
	for(i = 0; i < strlen(palavraParaMudar); i++) {
		palavraParaMudar[i] = toupper(palavraParaMudar[i]);
	}
}
void coletarPalavra(char* palavra, int qtdLetras, char *string) {
	int palavraSecretaValida;
	do {
		gotoxy(30,10);
		printf("%s", string);
		gotoxy(30+strlen(string),10);
		lerStringSeguramente(palavra, qtdLetras);
		if(string == "Nome do modelo: " || string == "Novo nome para modelo: "|| ehLetraOuEspaco(palavra)) { //Verifica se a palavra tem espa�o e letra, sen�o informa o erro.
			if (contarLetras(palavra) > qtdLetras) { // Limita a quantidade m�xima de letras que a palavra pode ter.
				limpaEspacos(1,1);
				gotoxy(30,12);
				printf("Nao ultrapasse %d letras!", qtdLetras);
				palavraSecretaValida = 0;
			}
			else
				if(contarLetras(palavra) < 2 && string != "Nome do modelo: " && string != "Novo nome para modelo: ") { // Limita a quantidade m�nima de letras que a palavra pode ter.
						limpaEspacos(1,1);
						gotoxy(30,12);
						printf("No m%cnimo duas letras!", 161);
						palavraSecretaValida = 0;
				}
				else { // Informa que a palavra foi salva com sucesso.
					limpaEspacos(1,1);
					gotoxy(30,12);
					printf("Salvo com sucesso!");
					palavraSecretaValida = 1;
				}
		}
		else { // Informa que a palavra n�o pode ter caracteres especiais.
			limpaEspacos(1,1);
			gotoxy(30,12);
			printf("Digite somente letras sem acentos!");
			palavraSecretaValida = 0;
		}
	} while(!palavraSecretaValida);
	paraMaiusculo(palavra);
}
int contaDigitos(char* digitos){ // Conta quantidade de n�meros no array e verifica se s�o n�meros.
	int i, quantidadeDigitos=0;
	for(i=0; i<strlen(digitos); i++) {
		if(isdigit(digitos[i])) {
			quantidadeDigitos++;
		}
	}
	return quantidadeDigitos;
}
void leAno(char* ano, char *string) {
	int repeat;
	do {
		repeat = 0;
		gotoxy(30,10);
		printf("%s", string);
		fgets(ano,5,stdin);
		
		if(contaDigitos(ano) != 4) {
				limpaEspacos(1,0);
				gotoxy(30,12);
				printf("Formato invalido.");
				repeat = 1;
			}
		fflush(stdin);
	} while(repeat == 1);	
}
void adicionarCarro(void) {
	estruturaBasica();
	char ano[5];
	int i, lotado = 0, j = 0, opcao = 0, tmpNum = 0;
	gotoxy(40,3);
	printf("Adicionar");
		
	while(NUM_ID < 16) {
		// Declara��o para adicionar ve�culos na estrutura do sistema.
		nCarro[NUM_ID].carroID = NUM_ID+1;
		coletarPalavra(nCarro[NUM_ID].marca, 15,"Nome da marca: ");
		coletarPalavra(nCarro[NUM_ID].modelo, 11,"Nome do modelo: ");
		coletarPalavra(nCarro[NUM_ID].cor, 11,"Nome da cor: ");      
		leAno(ano,"Nome do ano: ");
		nCarro[NUM_ID].ano = atoi (ano);
		NUM_ID++;
		// Fornece op��es para o usu�rio sair com dados em mem�ria ou salvar os dados em um arquivo.txt.
		limpaEspacos(1,1);
		gotoxy(30,10);
		printf("                                       ");
		gotoxy(40,10);
		printf("Sair [ESC]");
		gotoxy(36,12);
		printf("Salvar e Sair [S]");
		gotoxy(33,14);
		printf("Continuar [Enter]");
		opcao = getch();
		if(opcao == 83 || opcao == 115) {
			FILE *database;
			database = fopen("database.txt", "w");
			int j;
			for (j=0; j < NUM_ID; j++) {
				fwrite(&nCarro[j], sizeof(struct tipoCarro), 1, database);
			}
			fclose(database);
			break;		
		}
		else
			if(opcao == 27){
				break;
			}
		limpaEspacos(1,1);
	}
		
	if(NUM_ID > 15) {
		for(i = 0; i < NUM_ID; i++) {
			if(ARRAY_DEL[j] == nCarro[i].carroID && nCarro[j].deletado == 1) {
				coletarPalavra(nCarro[i].marca, 15,"Nome da marca: ");
				coletarPalavra(nCarro[i].modelo, 11,"Nome do modelo: ");
				coletarPalavra(nCarro[i].cor, 11,"Nome da cor: ");      
				leAno(ano,"Nome do ano: ");
				nCarro[i].ano = atoi (ano);
				nCarro[i].deletado = 0;
				j++;
			}
			else {
				lotado++;
			}
		}
		if(lotado == 16) {	
			do{ // Caso o n�mero de ID seja excedido, o sistema fornece op��es para salvar ou simplesmente sair com dados em mem�ria.
				gotoxy(18,7);
				printf("Voce atingiu o nivel maximo de armazenamento de dados.");
				gotoxy(21,9);
				printf("Exclua algum dado para adicionar um novo.");
				gotoxy(22,15);
				printf("Apenas sair e manter dados em memoria. [ESC]");
				gotoxy(22,17);
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
	}
}
