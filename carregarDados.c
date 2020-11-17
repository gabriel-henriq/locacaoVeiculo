void carregarDados(void) {
	FILE *entradaArquivo; 
    entradaArquivo = fopen("database.txt", "r");
    while(fread(&nCarro[NUM_ID], sizeof(struct tipoCarro), 1, entradaArquivo)) {
    	NUM_ID++;
	}	
	fclose(entradaArquivo);
}
