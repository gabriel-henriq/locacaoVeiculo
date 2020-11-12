struct tipoCarro *procuraLista(struct tipoCarro *head, int procuraID) {
		
	struct tipoCarro *anterior, *atual;
	anterior = head;
	atual = head->proximo;
	
	/* Procura até o ID >= ID procurado */
	
	while ((atual != NULL) && (atual->carroID < procuraID)) {
		anterior = atual;
		atual = atual->proximo;
	}
	
	return anterior;
}
