void carregarDatabase(void) {
	
	
	FILE *arquivoEntrada = fopen("database.txt", "r");
	
	struct tipoCarro ptr;
	
	if(arquivoEntrada != NULL) {
			
		fread(&ptr, sizeof(struct tipoCarro),1,arquivoEntrada);
			
		//ptr = ptr->proximo;	
	}
	
	fclose(arquivoEntrada);
}
