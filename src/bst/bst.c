#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *left, *right;
};

struct node* insert(struct node* node, int value){
    if(node == NULL){
        struct node* temp= (struct node*)malloc(sizeof(struct node));
        temp->val = value;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    if(value < node->val){
        node->left = insert (node->left, value);
    }
    else{
        if(value > node->val){
            node->right= insert(node->right, value);
        }
    }
    return node;
    
}
void traversePrint(struct node* root){

   
    if(root!=NULL){
        printf("(");
        traversePrint(root->left);
        printf("%d", root->val);
        traversePrint(root->right);
        printf(")");

    } 
}
void freeNode(struct node* root){
    if(root!=NULL){ 
        freeNode(root->left);
        freeNode(root->right);
        free(root);
    } 
}

int search(struct node* root, int compare){
    if(root==NULL){
        return 0;
    }
    if(root->val == compare){
        return 1;
    } 
    if(compare<root->val){
        return search(root->left, compare);
    }
    else{
        return search(root->right, compare);
    }
   
    return 0;
}

struct node* findMax(struct node* node){
    struct node* ptr = node;
    while(ptr && ptr->right!=NULL){ 
        ptr = ptr->right;
    }
    return ptr;
}

struct node* delete(struct node* root, int deleteVal){
    if(root==NULL){
        return root;
    }
   
    if(deleteVal==root->val){
    
        if(root->left==NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else{
            if(root->right == NULL){
                struct node* temp = root->left;
                free(root);
                return temp;
            }
        }
        struct node* temp = findMax(root->left);
        root->val= temp->val;
        root->left = delete(root->left, temp->val);
    }
    else{
        if(deleteVal>root->val){
            root->right = delete(root->right, deleteVal);
        }
        else{
            if(deleteVal<root->val){
                root->left = delete(root->left, deleteVal);
            }
        }

    }
    return root;
}




int main(){
   struct node* root = NULL;
   char command;
   //traversePrint(root);
   while(scanf("%c", &command)==1){
        if(command == 'i'){
           int value;
           scanf("%d", &value);
           if(search(root, value)==0){
                if(root==NULL){
                     root = insert(root, value);
                }
                else{
                    insert(root, value);
                 }
                printf("inserted\n");
            }
            else{printf("not inserted\n");}
       }
      
       if(command == 's'){
           int check;
           scanf("%d", &check);
           int bool = search(root, check);
           if(bool==0) printf("absent\n");
           if(bool==1) printf("present\n");
       }
       if(command == 'd'){
           int value;
           scanf("%d", &value);
           if(search(root, value)==1){
                root = delete(root, value);
                printf("deleted\n");
           }
           else{
               printf("absent\n");
           }
       }
        if(command == 'p'){
           traversePrint(root);
           printf("\n");
       }  
   }
    freeNode(root);
    return 0;
}