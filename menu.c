void menuPesquisar(void);
void imprimirLista(void);
void sistemaPrincipal(void) {
	int opcao = 0;
	do {
		int teclaPressionada;
		opcao = 0;
		int posicaoDaLinha = 7, posicaoDaColuna = 7, posicaoDaSeta = 7; // Manipula a localização do ponteiro na tela.
		inicio: // Saída do comando 'goto', para voltar ao início do menu.
		limpaTela();
		bordasMenu();
		gotoxy(28,3);
		printf("P a i n e l  D e  C o n t r o l e ");
		gotoxy(40,7);
		printf("Adicionar");
		gotoxy(40,10);
		printf("Excluir");
		gotoxy(40,13);
		printf("Alterar");
		gotoxy(40,16);
		printf("Pesquisar");
		gotoxy(40,19);
		printf("Sair");
		imprimeCreditos();
		gotoxy(15, 27);
		do {
			gotoxy(35,posicaoDaLinha);
			printf("  -%c",16); // Desenha uma seta para selecionar as opções do menu.
			gotoxy(1,22);
			teclaPressionada = getch();
			if(teclaPressionada == TECLA_SETA_BAIXO) {
				posicaoDaColuna = posicaoDaLinha;
				posicaoDaLinha += 3 ;
				posicaoDaSeta += 3;
				if(posicaoDaSeta > 19) {// Se posição da seta para baixo ultrapassar "Sair" (posição 16), retorna para a posição 7 (Jogar).
					posicaoDaSeta = 7;
					posicaoDaLinha = 7;
				}
			}
			if(teclaPressionada == TECLA_SETA_CIMA) {
				posicaoDaColuna = posicaoDaLinha;
				posicaoDaLinha -= 3;
				posicaoDaSeta -= 3;
				if(posicaoDaSeta < 7) {	// Se a posição da seta para cima ultrapassar "Jogar" (posição 7), retorna para a posição 16 (Sair).
					posicaoDaSeta = 19;
					posicaoDaLinha = 19;
				}
			}
			if(posicaoDaLinha != posicaoDaColuna) { // Limpa as setas (quando movimentadas).
				gotoxy(35,posicaoDaColuna);
				printf("     ");
				posicaoDaColuna = posicaoDaLinha;
			}
			if(teclaPressionada == TECLA_ENTER) {
				opcao = posicaoDaSeta;
			}
		} while(opcao == 0);
		switch(opcao) {
			case 7:
				adicionarCarro();
				break;
			case 10:
				limpaTela();
				imprimeCreditos();
				bordasMenu();
				gotoxy(40,3);
				printf("Excluir");
				
				gotoxy(60,22);
				printf("VOLTAR [ESC]");
				apertarESC();
				break;
			case 13:
				limpaTela();
				imprimeCreditos();
				bordasMenu();
				gotoxy(40,3);
				printf("Alterar");
				
				gotoxy(60,22);
				printf("VOLTAR [ESC]");
				apertarESC();
				break;
			case 16:
				limpaTela();
				imprimeCreditos();
				bordasMenu();
				gotoxy(40,2);
				printf("Pesquisar");
				menuPesquisar();
				gotoxy(60,22);
				printf("VOLTAR [ESC]");
				apertarESC();
				break;
			case 19:
				limpaTela();
				imprimeCreditos();
				bordasMenu();
				gotoxy(39,12);
				printf("Saindo");
				int i;
				for(i = 0; i < 3; i++) {
					printf(".");
					Sleep(300);
				}
				gotoxy(36,12);
				printf("Ate a proxima!");
				gotoxy(0,24);
				exit(0);				
				break;
			default:
				printf("Você deve escolher uma opção válida\n");
				printf("Precione qualquer tecla para voltar ao menu.\n");
				getch();
				goto inicio;
		}
	} while(opcao != 4);
}
