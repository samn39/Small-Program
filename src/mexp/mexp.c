#include <stdio.h>
#include <stdlib.h>
 

void print(int** input, int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            printf("%d", input[i][j]);
            if(j!=size-1){
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    FILE *fp;
    fp = fopen(argv[1], "r");
   int size;
   fscanf(fp, "%d", &size);
   

   int** inputM = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++){
        inputM[i] = (int*)malloc(size * sizeof(int));
    }
   int** result = (int**)malloc(size * sizeof(int*));
   for (int i = 0; i < size; i++){
       result[i] = (int*)malloc(size * sizeof(int));
   }
   int** temp = (int**)malloc(size * sizeof(int*));
   for (int i = 0; i < size; i++){
       temp[i] = (int*)malloc(size * sizeof(int));
   }
    
   for(int i=0; i<size; i++){
       for(int j=0; j<size; j++){
           fscanf(fp, "%d", &inputM[i][j]);
           temp[i][j]=inputM[i][j];
       }
   }
   int power;
   fscanf(fp,"%d", &power);

   if(power==0){
       for(int r=0; r<size; r++ ){
           for(int c=0; c<size; c++){
               if(r==c){
                   printf("%d", 1);
                   if(c!=size-1){
                       printf(" ");
                   }
               }
               else{
                   printf("%d", 0);
                   if(c!=size-1){
                       printf(" ");
                   }
               }
           }
           printf("\n");
       }
       for (int i = 0; i < size; i++){
        free(result[i]);
        free(inputM[i]);
        free(temp[i]);
   }
    free(result);
    free(temp);
    free(inputM);
       return 0;
   }
   
   if(power==1){
       print(inputM,size);
       for (int i = 0; i < size; i++){
        free(result[i]);
        free(inputM[i]);
        free(temp[i]);
   }
    free(result);
    free(temp);
    free(inputM);
       return 0;
   }
   


   for(int p=1;p<power; p++){
       for(int i=0; i<size; i++){
           for(int j=0; j<size; j++){
               result[i][j]=0;
               for(int k=0; k<size; k++){
                   result[i][j]+= inputM[i][k]*temp[k][j];
               }
           }
       }
       for(int i=0; i<size; i++){
           for(int j=0; j<size; j++){
               temp[i][j]=result[i][j];
           }
       }
   }
   print(result, size);
 
  for (int i = 0; i < size; i++){
        free(result[i]);
        free(inputM[i]);
        free(temp[i]);
   }
    free(result);
    free(temp);
    free(inputM);

   return 0;
}
