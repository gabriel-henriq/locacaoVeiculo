void carregarDados(void) {
	FILE *entradaArquivo; 
    entradaArquivo = fopen("database.txt", "r");
    while(fread(&nCarro[NUM_ID], sizeof(struct tipoCarro), 1, entradaArquivo)) {
    	NUM_ID++;
	}	
	fclose(entradaArquivo);
	
	int i;
	for(i = 0; i < NUM_ID; i++) {
		if(nCarro[i].deletado == 1) {
			ARRAY_DEL[DEL_ID] = nCarro[i].carroID;
			DEL_ID++;
		}
	}
}
