void imprimirListaDeCarros(void);
void excluirVeiculo(void){ 
	
	int id, opcao, i, naoExiste = 0;
	
	limpaEspacos(0,0);
	imprimeCreditos();
	bordasMenu();
	gotoxy(28,3);
	printf("E x c l u i r  V e i c u l o");
	gotoxy(26,8);
	printf("Digite 99 para imprimir todos os items.");
	gotoxy(26,10);
	printf("Digite o ID que deseja excluir: ");
	scanf("%d", &id);
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
	for(i=0;i<NUM_ID;i++){
		if(nCarro[i].carroID == id){
			ARRAY_DEL[DEL_ID] = id;
			nCarro[i].deletado = 1;
			DEL_ID++;
			NUM_ID--;
		}
		else {
			naoExiste++;
		}
	}
	if(naoExiste == NUM_ID) {
		gotoxy(30,12);
		printf("Este ID nao existe.");
		excluirVeiculo();
	}
	
}
