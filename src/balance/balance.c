#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    char *stackArr;
    int head;
    int maxSize;
};

struct stack* stackBalance (int size){
    struct stack *ptr = (struct stack*)malloc(sizeof(struct stack));
    ptr->maxSize = size;
    ptr->head = -1;
    ptr->stackArr = (char*)malloc(sizeof(int)*size);
    return ptr;
}

int isEmpty(struct stack *ptr){
    return ptr->head ==-1; 
}

void push(struct stack *ptr, char open){
    //maybe check if it's full
    ptr->head++;
    ptr->stackArr[ptr->head] = open;
}
char pop(struct stack *ptr){
    
    if(isEmpty(ptr)){
        exit(EXIT_FAILURE);
    } 
    return ptr->stackArr[ptr->head--];
}

int size(struct stack *ptr){
    return ptr->head +1;
}

int main(int argc, char **argv) {
   // printf() displays the string inside quotation
   int length = strlen(argv[1]);
   struct stack *balance = stackBalance(length+1);
   
   for(int i=0; i<length; ++i){
       if(argv[1][i]=='(' || argv[1][i]=='[' || argv[1][i]=='{'){
           push(balance, argv[1][i]);
           continue;
       }
       else{
           if(isEmpty(balance)==1){
               if(argv[1][i]==')' || argv[1][i]==']' || argv[1][i]=='}'){
                    printf("%d: %c\n", i, argv[1][i]);
                    free(balance->stackArr);
                    free(balance);
                    return EXIT_FAILURE;
               }
            }
            if(argv[1][i]==')'){
                if(pop(balance)=='('){
                   continue;
                }
                else{
                
                    printf("%d: %c\n", i, argv[1][i]);
                    free(balance->stackArr);
                    free(balance);
                    return EXIT_FAILURE;
                }
            }
            if(argv[1][i]==']'){
                if(pop(balance)=='['){
                    continue;
                }
                else{
                    printf("%d: %c\n", i, argv[1][i]);
                    free(balance->stackArr);
                    free(balance);
                    return EXIT_FAILURE;
                }
            }
            if(argv[1][i]=='}'){
                if(pop(balance)=='{'){
                    continue;
                }
                else{
                    printf("%d: %c\n", i, argv[1][i]);
                    free(balance->stackArr);
                    free(balance);
                    return EXIT_FAILURE;
                }
            }   
        }
    }
    //when there're leftover open delimeters
    if(isEmpty(balance)==0){
        printf("open: ");
        for(int j=size(balance)-1; j>=0; j--){
            char test = pop(balance);
            if(test=='('){
                printf(")");
                continue;
            }
            if(test=='{'){
                printf("}");
                continue;
            }
            if(test=='['){
                printf("]");
                continue;
            }  
        }
        printf("\n");
        free(balance->stackArr);
        free(balance);
        return EXIT_FAILURE;
    }
    //when everything is balance
    if(isEmpty(balance)==1){
        free(balance->stackArr);
        free(balance);
        return EXIT_SUCCESS;
    }
   return 0;
}