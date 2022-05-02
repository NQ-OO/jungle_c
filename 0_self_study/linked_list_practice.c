#include <stdio.h>
#include <stdlib.h>

void ll_input(), ll_print(), ll_update(), ll_delete();

typedef struct NODE{
  int ID;
  int value;
  struct NODE * next;
}NODE;

NODE *head, *tail, *ptr;

int main(){
  head = NULL;
  int index, flag = 0;
  while(flag == 0){
    printf("Enter (1)Input, (2)Print, (3)Update, (4)Delete, (5)Exit\n");
    scanf("%d", &index);
    if (index == 1){ll_input();}
    else if (index == 2){ll_print();}
    else if (index == 3){ll_update();}
    else if (index == 4){ll_delete();}
    else if (index == 5){printf("Exit this program"); flag = 1;}
    else {printf("Enter between 1 - 5");}
  }
}

void ll_input(){
  int in_ID, in_value;
  printf("\tID, Value:"); scanf("%d%d", &in_ID, &in_value);
  ptr = (NODE*)malloc(sizeof(NODE));
  if (head==NULL){head = ptr;} else{tail->next = ptr;}
  ptr->ID = in_ID;
  ptr->value = in_value;
  ptr->next = NULL;
  tail = ptr;
  ll_print();
}

void ll_print(){
  ptr = head;
  printf("(ID, Values): ");
  while(ptr != NULL){
    printf("(%d, %d)", ptr->ID, ptr->value);
    ptr = ptr -> next;
  }
  printf("\n");
}

void ll_update(){
  int update_ID, update_value;
  printf("\ttype in the ID you would like to update : "); scanf("%d", &update_ID); // 여기서 왜 주소로 받는거지?
  ptr = head;
  while (ptr != NULL){
    if (ptr -> ID == update_ID ){
      printf("\ttype in the value for this ID : ");
      scanf("%d", &update_value); 
      ptr -> value = update_value;
      ll_print();
      return;
    }
    ptr = ptr -> next;
  }
}

void ll_delete(){
  int delete_ID;
  printf("\ttype in the ID you would like to delete : "); scanf("%d", &delete_ID);
  ptr = head;
  if(ptr->ID == delete_ID){
    head = ptr -> next;
    free(ptr);
    ll_print();
    return;
  }
  NODE *temp;
  while(ptr != NULL){
    tail = ptr;
    ptr = ptr -> next;
    if(ptr -> ID == delete_ID){
      tail -> next = ptr -> next ;
      temp = tail;
      free(ptr);
      while(tail -> next != NULL){
        tail = temp; 
        temp = temp->next;
      }
      ll_print();
      return;
    }
  }
}


