void limpaTela(void) {
	system("cls");
}
void gotoxy(int X,int Y) { // Declaração do comando gotoxy.
	COORD c;
	c.X = X;
	c.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
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
void imprimeCreditos(void) {
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
