void imprimirLista(void);
void menuPesquisar(void);
void menuRelatorioFiltro(void) {
	int opcao = 0;
	do {
		int teclaPressionada;
		opcao = 0;
		int posicaoDaLinha = 7, posicaoDaColuna = 7, posicaoDaSeta = 7; // Manipula a localização do ponteiro na tela.
		inicio: // Saída do comando 'goto', para voltar ao início do menu.
		limpaTela();
		bordasMenu();
		gotoxy(28,3);
		printf("M e n u   R e l a t o r i o");
		gotoxy(18,5);
		printf("Painel de Controle > Menu Pesquisar > Relatorio");
		gotoxy(40,7);
		printf("Marca");
		gotoxy(40,10);
		printf("Modelo");
		gotoxy(40,13);
		printf("Cor");
		gotoxy(40,16);
		printf("Ano");
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
				limpaTela();
				imprimeCreditos();
				bordasMenu();
				gotoxy(36,2);
				printf("Relatorio por Marca");
				relatorioMarca();
				gotoxy(60,22);
				printf("VOLTAR [ESC]");
				apertarESC();
				break;
				break;
			case 10:
				limpaTela();
				imprimeCreditos();
				bordasMenu();
				gotoxy(36,2);
				printf("Relatorio por Modelo");
				relatorioModelo();
				gotoxy(60,22);
				printf("VOLTAR [ESC]");
				apertarESC();
				break;
			case 13:
				limpaTela();
				imprimeCreditos();
				bordasMenu();
				gotoxy(36,2);
				printf("Relatorio por Cor");
				relatorioCor();
				gotoxy(60,22);
				printf("VOLTAR [ESC]");
				apertarESC();
				break;
			case 16:
				limpaTela();
				imprimeCreditos();
				bordasMenu();
				gotoxy(36,2);
				printf("Relatorio por Ano");
				
				gotoxy(60,22);
				printf("VOLTAR [ESC]");
				apertarESC();
				break;
			case 19:
				menuPesquisar();
				break;
			default:
				printf("Você deve escolher uma opção válida\n");
				printf("Precione qualquer tecla para voltar ao menu.\n");
				getch();
				goto inicio;
		}
	} while(opcao != 4);
}
