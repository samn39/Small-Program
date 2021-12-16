#include <stdio.h>
#include <ctype.h>
#include <string.h>

void upperCase(char *str){
	int length = strlen(str);
	for(int i=0; i<length; ++i){
		str[i]=toupper(str[i]);
		printf("%c", str[i]);
	}
}
int main (int argc, char *argv[]) {
   if(argc <= 1){
		printf("%s", "");
    }
   else{
		for(int i=1; i<argc; ++i){
			if(strlen(argv[i])>0){
		 		upperCase(argv[i]);
				 if(i==(argc-1)){
			 		printf("!!\n");
		 		}
		 		else{
			 		printf(" ");
				}
		 	}
        } 
    }
   return 0;
}
