void carregarDatabase(void) {
	FILE *entradaArquivo; 
    int i = 0;
    entradaArquivo = fopen("database.txt", "r");
    while(fread(&nCarro[i], sizeof(struct tipoCarro), 1, entradaArquivo)) {
    	i++;
	}	
	fclose(entradaArquivo);
}
