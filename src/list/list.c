#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
  int item, key;
  struct node *next;
};
struct node *head =NULL;
struct current *current = NULL;

int length(){
  struct node *ptr = head;
  int size = 0;;
  while(ptr != NULL){
    size++;
    ptr = ptr->next;
  }
  return size;
}

void print(){
  struct node *ptr = head;
  if(head!=NULL){
        printf(" ");
    }
  while(ptr != NULL){
    printf("%d", ptr->item);
    if(ptr->next!=NULL){
        printf(" ");
    }
    ptr = ptr->next;
  }
  printf("\n");
}

int contain(int num){
  struct node *ptr = head;
  while(ptr != NULL){
    if(ptr->item==num){
      return 1;
    }
    ptr = ptr->next;
  }
  return 0;
}

int getPosition(int num){
  int pos=1;
  struct node *ptr = head;
  while(ptr != NULL){
    if(ptr->item==num){
      break;
    }
    ptr = ptr->next;
    pos++;
  }
  return pos;
}

void insert(int input){
  struct node *newNode = (struct node*) malloc(sizeof(struct node));
  newNode->item = input;
  newNode->next = head;
  head = newNode;
}

struct node* delete(int numDel){
  struct node* current = head;
  struct node* previous = NULL;

   if(head == NULL) {
      return NULL;
   }
   while(current->item != numDel) {
      if(current->next == NULL) {
         return NULL;
      } else {
         previous = current;
         current = current->next;
      }
   }

   if(current == head) {
      head = head->next;
   } else {
      previous->next = current->next;
   }
   free(current);
   return current;    
}

void sort() {
   int i, j, k, tempData;
   struct node *current;
   struct node *next;
   int size = length();
   k = size ;
   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current = head;
      next = head->next;
      for ( j = 1 ; j < k ; j++ ) {   
         if ( current->item > next->item ) {
            tempData = current->item;
            current->item = next->item;
            next->item = tempData;
         }
         current = current->next;
         next = next->next;
      }
   }   
}

int main()
{
    struct node* list = head;
    int data;
    char insertDelete;
    while(scanf("%c", &insertDelete)==1){
      scanf("%d", &data);
      if(insertDelete=='i'){
        if(contain(data)==0){
          insert(data);
          printf("%d :", length());
          sort();
          print(list);
          continue;
        }
        
        printf("%d :", length());
        print(list); 
      }
      if(insertDelete=='d'){
        if(contain(data)==1){
          delete(data);
          printf("%d :", length());
          sort();
          print(list);
          continue;
        }
        printf("%d :", length());
        print(list);
      }
    }
    return 0;
}