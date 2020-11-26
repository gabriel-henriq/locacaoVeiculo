void pesquisaID(void);
void menuRelatorioFiltro(void);
void menuPesquisar(void) {
	int opcao = 0;
	do {
		int teclaPressionada;
		opcao = 0;
		int posicaoDaLinha = 7, posicaoDaColuna = 7, posicaoDaSeta = 7; // Manipula a localização do ponteiro na tela.
		inicio: // Saída do comando 'goto', para voltar ao início do menu.
		limpaTela();
		bordasMenu();
		gotoxy(28,3);
		printf("M e n u     P e s q u i s a r");
		gotoxy(32,7);
		printf("Gerar Relatorio");
		gotoxy(32,10);
		printf("Pesquisar por ID");
		gotoxy(32,13);
		printf("Imprimir todos os items");
		gotoxy(32,16);
		printf("Relatorio com filtro");
		gotoxy(32,19);
		printf("Voltar");
		imprimeCreditos();
		gotoxy(15, 27);
		do {
			gotoxy(27,posicaoDaLinha);
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
				gotoxy(26,posicaoDaColuna);
				printf("     ");
				posicaoDaColuna = posicaoDaLinha;
			}
			if(teclaPressionada == TECLA_ENTER) {
				opcao = posicaoDaSeta;
			}
		} while(opcao == 0);
		switch(opcao) {
			case 7:
				estruturaBasica();
				gotoxy(35,2);
				printf("Gerar Relatorio");
				
				gotoxy(60,22);
				printf("VOLTAR [ESC]");
				apertarESC();				
				break;
			case 10:
				estruturaBasica();
				gotoxy(35,2);
				printf("Pesquisar por ID");
				pesquisaID();
				gotoxy(60,22);
				printf("VOLTAR [ESC]");
				apertarESC();
				break;
			case 13:
				estruturaBasica();
				gotoxy(32,2);
				printf("Imprimir todos os items");
				imprimirListaDeCarros();
				gotoxy(60,22);
				printf("VOLTAR [ESC]");
				apertarESC();
				break;
			case 16:
				estruturaBasica();
				gotoxy(35,2);
				printf("Relatorio com filtro");
				menuRelatorioFiltro();
				gotoxy(60,22);
				printf("VOLTAR [ESC]");
				apertarESC();
				break;
			case 19:
				sistemaPrincipal();
			default:
				printf("Você deve escolher uma opção válida\n");
				printf("Precione qualquer tecla para voltar ao menu.\n");
				getch();
				goto inicio;
		}
	} while(opcao != 4);
}
