void sistemaPrincipal(void);
void adicionarCarro(void);
void salvarEstrutura(void);
void menuSalvar(void) {
	int opcao = 0;
	do {
		int teclaPressionada;
		opcao = 0;
		int posicaoDaLinha = 7, posicaoDaColuna = 7, posicaoDaSeta = 7; // Manipula a localiza��o do ponteiro na tela.
		inicio: // Sa�da do comando 'goto', para voltar ao in�cio do menu.
		limpaTela();
		bordasMenu();
		
		gotoxy(40,7);
		printf("Continuar Adicionando");
		gotoxy(40,10);
		printf("Salvar");
		gotoxy(40,13);
		printf("Sair");
		do {
			gotoxy(35,posicaoDaLinha);
			printf("  -%c",16); // Desenha uma seta para selecionar as op��es do menu.
			gotoxy(1,22);
			teclaPressionada = getch();
			if(teclaPressionada == TECLA_SETA_BAIXO) {
				posicaoDaColuna = posicaoDaLinha;
				posicaoDaLinha += 3 ;
				posicaoDaSeta += 3;
				if(posicaoDaSeta > 13) {// Se posi��o da seta para baixo ultrapassar "Sair" (posi��o 13), retorna para a posi��o 7 (Jogar).
					posicaoDaSeta = 7;
					posicaoDaLinha = 7;
				}
			}
			if(teclaPressionada == TECLA_SETA_CIMA) {
				posicaoDaColuna = posicaoDaLinha;
				posicaoDaLinha -= 3;
				posicaoDaSeta -= 3;
				if(posicaoDaSeta < 7) {	// Se a posi��o da seta para cima ultrapassar "Jogar" (posi��o 7), retorna para a posi��o 16 (Sair).
					posicaoDaSeta = 13;
					posicaoDaLinha = 13;
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
				salvarEstrutura();
				break;
			case 13:
				sistemaPrincipal();
			default:
				printf("Voc� deve escolher uma op��o v�lida\n");
				printf("Precione qualquer tecla para voltar ao menu.\n");
				getch();
				goto inicio;
		}
	} while(opcao != 4);
	
}
