void gotoxy(int X,int Y) { // Declara��o do comando gotoxy para pode manipular a localiza��o das letras e desenhos na tela.
	COORD c;
	c.X = X;
	c.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void limpaEspacos(int aviso, int continuar) { // Faz a limpeza em determinados espa�os na tela, utilizando dois parametros.
	int i;
	for(i=18;i<70;i++) {
		gotoxy(i,10);
		printf(" ");			
		if(aviso == 1) {
			gotoxy(i,12);
			printf(" ");			
		}
		if(continuar == 1) {
			gotoxy(i,14);
			printf(" ");			
		}	
	}	
}
void limpaTela(void) {
	system("cls");
}
void bordasMenu(void) {
	int i;
	for(i = 2; i < 23; i++) { // Imprime as bordas laterais.
		gotoxy(16,i);
		printf("%c",186);
		gotoxy(72,i);
		printf("%c",186);
		gotoxy(72,1);
		printf("%c",187);
		gotoxy(16,1);
		printf("%c",201);
	}
	for(i = 17; i < 72; i++) { // Imprime as bordas superiores e inferiores.
		gotoxy(i, 1);
		printf("%c",205);
		gotoxy(i,23);
		printf("%c",205);
		gotoxy(72,23);
		printf("%c",188);
		gotoxy(16,23);
		printf("%c",200);
	}
}
void imprimeCreditos(void) { // Imprime creditos.
	gotoxy(75,3);
	printf("Faculdades Integradas Camoes.");
	gotoxy(75,5);
	printf("An%clise e Desenvolvimento de Sistemas.", 160);
	gotoxy(75,7);
	printf("Disciplina %c Programacao Avan%cada.", 196, 135);
	gotoxy(75,9);
	printf("Professora: Rosemari Rattmann.");
}
void apertarESC() {
	while(getch() != 27);
}
void estruturaBasica(void) {
	limpaTela();
	imprimeCreditos();
	bordasMenu();
}
// Permite o usu�rio digitar 5 palavras para serem desenhadas em determinadas posi��es na tela.
void imprimeNomeDados(char *s1, char *s2, char *s3, char *s4, char *s5) { 
	gotoxy(20,4);
	printf("%s", s1);
	gotoxy(26,4);
	printf("%s", s2);
	gotoxy(40,4);
	printf("%s", s3);
	gotoxy(53,4);
	printf("%s", s4);
	gotoxy(65,4);
	printf("%s", s5);
}
