void relatorioModelo(void) {	
	int i = 1, j = 0, k = 0;
	gotoxy(18,22);
	printf("Total de items cadastrados: %d", NUM_ID - DEL_ID);
	imprimeNomeDados("MODELO"," ","ID"," "," ");
	
	struct tipoCarro tempCarro[16];
	struct tipoCarro tempCarro1;
	memcpy(tempCarro,nCarro, sizeof(struct tipoCarro) * NUM_ID); // Copia a estrutura de nCarro para a estrutura tempor�ria tempCarro.
	
	/* Fun��o de ordena��o Insertion Sort (Utilizado pelo fato de existir
	um n�mero finito e pequeno no sistema para armazenamento de dados 16 posi��es).*/
	while(i < NUM_ID) {
		j = i;
		while (j>0 && tempCarro[j-1].modelo[0] > tempCarro[j].modelo[0]) {
			tempCarro1 = tempCarro[j-1];
			tempCarro[j-1] = tempCarro[j];
			tempCarro[j] = tempCarro1;
			j--;
		}
		i++;
	}
	// Imprime os dados do relat�rio com duas condi��e (ID n�o inativado e ID diferente de 0).
	j=0;
    for(i = 0; i < NUM_ID; i++) {
    	if(tempCarro[i].deletado == 1) {
    		j++;
		}
    	if(tempCarro[i].deletado != 1 && tempCarro[i].carroID != 0) {	
	    	gotoxy(20,i+6-j);
	    	printf("%s", tempCarro[i].modelo);
	    	gotoxy(40,i+6-j);
	    	printf("%d", tempCarro[i].carroID);
	    }
	}
}
