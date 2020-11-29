void relatorioCor(void) {	
	int i = 1, j = 0, k = 0;
	gotoxy(18,22);
	printf("Total de items cadastrados: %d", NUM_ID);
	imprimeNomeDados("COR"," ","ID"," "," ");
	
	struct tipoCarro tempCarro[16];
	struct tipoCarro tempCarro1;
	memcpy(tempCarro,nCarro, sizeof(struct tipoCarro) * NUM_ID);
	
	while(i < NUM_ID) {
		j = i;
		while (j>0 && tempCarro[j-1].cor[0] > tempCarro[j].cor[0]) {
			tempCarro1 = tempCarro[j-1];
			tempCarro[j-1] = tempCarro[j];
			tempCarro[j] = tempCarro1;
			j--;
		}
		i++;
	}
	
    for(i = 0; i < NUM_ID; i++) {
    	gotoxy(20,i+6);
    	printf("%s", tempCarro[i].cor);
    	gotoxy(40,i+6);
    	printf("%d", tempCarro[i].carroID);	
	}
}
