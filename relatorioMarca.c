void relatorioMarca(void) {	
	int i = 1, j = 0, k = 0;
	gotoxy(18,22);
	printf("Total de items cadastrados: %d", NUM_ID - DEL_ID);
	imprimeNomeDados("MARCA"," ","ID"," "," ");
	
	struct tipoCarro tempCarro[16];
	struct tipoCarro tempCarro1;
	memcpy(tempCarro,nCarro, sizeof(struct tipoCarro) * NUM_ID);
	
	while(i < NUM_ID) {
		j = i;
		while (j>0 && tempCarro[j-1].marca[0] > tempCarro[j].marca[0]) {
			tempCarro1 = tempCarro[j-1];
			tempCarro[j-1] = tempCarro[j];
			tempCarro[j] = tempCarro1;
			j--;
		}
		i++;
	}
	j = 0;
    for(i = 0; i < NUM_ID; i++) {
    	if(tempCarro[i].deletado == 1) {
    		j++;
		}
    	if(tempCarro[i].deletado != 1 && tempCarro[i].carroID != 0) {	
	    	gotoxy(20,i+6-j);
	    	printf("%s", tempCarro[i].marca);
	    	gotoxy(40,i+6-j);
	    	printf("%d", tempCarro[i].carroID);
	    }
	}
}
