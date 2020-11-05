#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
/*==========================    Locação de Carros         =====================*
============================  Author: Gabriel Henrique    =====================*
============================ Professor: Rosemari Pavan    =====================*
============================ Camões Faculdades Integradas =====================*
*/
typedef struct {
	char brand[20];
	char model[20];
	char color[15];
	int year;
	int price;
	int stock;
	double sellMonth;
} CAR;
void readFile() {
	
}
int main(void) {
	
	
	
	CAR car[2];
	
	FILE *database;

	int getCharFile;
	int startLinePosition = 0, lineSize = 0;
	char lineContent[lineSize];
	database = fopen("database.txt", "r+");
	do {
		getCharFile = fgetc(database);
		if(feof(database)) {
			break;
		}
		lineSize++;
		if(getCharFile == '|') {
			fseek(database, startLinePosition, SEEK_SET);
			fgets(lineContent, lineSize, database);
			startLinePosition += lineSize;
			fseek(database, startLinePosition, SEEK_SET);
			lineSize = 0;
		}
	}while(1);
	
	
	
	fclose(database);
	    	            
	return 0;
}
