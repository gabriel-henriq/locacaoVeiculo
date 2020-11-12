void menuSalvar(void);

void adicionarCarro(void) {
	limpaTela();
	imprimeCreditos();
	bordasMenu();
	gotoxy(40,3);
	printf("Adicionar");
	
	char tmpName[26];
	int tmpNum, opcao;
	
	
	nCarro = (struct tipoCarro*) malloc(sizeof(struct tipoCarro));
	
	
	gotoxy(30,10);
	printf("Digite um ID para o carro: ");
	scanf("%d",&tmpNum);
	nCarro->carroID = tmpNum;
	fflush(stdin);
	
	
	
	gotoxy(30,10);
	printf("                                ");
	gotoxy(30,10);
	printf("Digite o nome da marca: ");
	fgets(tmpName, 25, stdin);
	strcpy(nCarro->marca,tmpName);
	fflush(stdin);
	
	
	/*gotoxy(30,10);
	printf("Digite o nome do modelo: ");
	fgets(tmpName, 25,stdin);
	strcpy(nCarro->modelo,tmpName);
	fflush(stdin);	

	
	gotoxy(30,10);
	printf("Digite o nome da cor: ");
	fgets(tmpName,20,stdin);
	strcpy(nCarro->cor,tmpName);
	fflush(stdin);
	
	gotoxy(30,10);
	printf("Digite o nome do ano: ");
	scanf("%d", &tmpNum);	
	nCarro->ano = tmpNum;
	fflush(stdin);	
	*/
	

	
	menuSalvar();	
}
