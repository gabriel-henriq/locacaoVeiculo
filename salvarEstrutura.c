void salvarEstrutura(void) {
	
	struct tipoCarro *ptr = head;
	
	FILE *arquivoSaida = fopen("database.txt", "a+");
	
	if(arquivoSaida != NULL) {
		
		while(ptr != NULL) {
			
			
			fwrite(&head, sizeof(struct tipoCarro),2,arquivoSaida);
						
		}
		
	}
	fclose(arquivoSaida);
}
