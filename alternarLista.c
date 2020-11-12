void alternaLista(struct tipoCarro** head_ref) { 
    struct tipoCarro* anterior = NULL; 
    struct tipoCarro* atual = *head_ref; 
    struct tipoCarro* proximo;
	 
    while (atual != NULL) { 
        proximo = atual->proximo; 
        atual->proximo = anterior; 
        anterior = atual;
        atual = proximo; 
    } 
    *head_ref = anterior; 
}
