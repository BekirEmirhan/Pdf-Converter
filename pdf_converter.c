#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argv,char **args){
	if(strcmp(args[1],"-d")==0){
		for(int i=2;i<argv;i++){
			char *command = (char*)malloc(sizeof(char)*100);
			sprintf(command,"libreoffice --headless --convert-to \"pdf\" %s > /dev/null 2>&1",args[i]);
			system(command);

		}
	}
	else if(args[1],"-info"){
		printf("SYNTAX:\n\n./pdfc.out [params] [filenames]\n---------\nPARAMETERS\n\n:-info bilgi almak için\n-d ayrı ayrı pdf yapmak için\n-all tüm dosyaları tek pdf yapmak için\n");
	}
	else if(strcmp(args[1],"-all")==0){
		char *tmp = (char*)malloc(sizeof(char)*200);
		for(int i=2;i<argv;i++){
			strcat(tmp,args[i]);
			strcat(tmp," ");
		}
		char *command = (char*)malloc(sizeof(char)*100);	
		sprintf(command,"libreoffice --headless --convert-to \"pdf\" %s> /dev/null 2>&1",tmp);
		system(command);
		strcpy(tmp,"");
		for(int i=2;i<argv;i++){
			char *temp = (char*)malloc(sizeof(char)*20);
			char *ptr = args[i];
			int i=0;
			while (*ptr != '\0' && *ptr != '.'){
				temp[i++] = *ptr;
				ptr++;
			}
			temp[i] = '\0';
			strcat(tmp,temp);
			strcat(tmp,".pdf ");
		}
		sprintf(command,"pdftk %s cat output new.pdf",tmp);
		system(command);
		sprintf(command,"rm %s",tmp);
		system(command);
	}
	else printf("ERROR!!! Invalid argument!\n");

return 0;
}
