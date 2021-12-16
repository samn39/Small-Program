#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
   if(strlen(argv[1])<1){
         return 0;
   }
   if(argc<=2){
      for(int i=0; i<strlen(argv[1]); ++i){
         if(isdigit(argv[1][i])!=0){
            printf("error\n");
            return 0;
         }
      }
      int occurence=1;
      int memloc =0;
      int maxSize = strlen(argv[1]);
      char *mem = (char*) malloc(((maxSize*2)+1)*sizeof(char));
     
      for(int i= 0; i<maxSize; ++i){
         if((argv[1][i]==argv[1][i+1])==1){
            occurence++;
            continue; 
         }
         int a =snprintf(mem+memloc, maxSize,  "%c", argv[1][i]);
         int addedCharSize = snprintf(mem+memloc+1, maxSize,  "%d", occurence);
         memloc = memloc+addedCharSize+a;
         occurence=1;   
      }
      if(memloc>maxSize){
         puts(argv[1]);
      }
      else{
         puts(mem);
      }
      free(mem);
      
  }
   return 0;
}