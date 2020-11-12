int length() {
   int length = 0;
   struct tipoCarro *current;
	
   for(current = head; current != NULL; current = current->proximo) {
      length++;
   }
	
   return length;
}

void ordenaLista(void) {

   int i, j, k, tempKey;
   struct tipoCarro *current;
   struct tipoCarro *next;
	
   int size = length();
   k = size ;
	
   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current = head;
      next = head->proximo;
		
      for ( j = 1 ; j < k ; j++ ) {   

         if ( current->carroID > next->carroID ) {

            tempKey = current->carroID;
            current->carroID = next->carroID;
            next->carroID = tempKey;
         }
			
         current = current->proximo;
         next = next->proximo;
      }
   }   
}
