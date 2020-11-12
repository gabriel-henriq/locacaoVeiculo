void imprimirLista(void) {
	struct tipoCarro *ptr = head;
	
	gotoxy(21,6);
	printf("ID");
	gotoxy(28,6);
	printf("Marca");
	gotoxy(45,6);
	printf("Modelo");
	gotoxy(55,6);
	printf("Cor");
	gotoxy(65,6);
	printf("Ano");
	
	int i = 8;
	int j = 8;
	
	while(ptr != NULL){
		
		gotoxy(21,i++);
		printf("%d", ptr->carroID);
		gotoxy(28,j++);
		printf("%s", ptr->marca);
		ptr = ptr->proximo;
	}
}
