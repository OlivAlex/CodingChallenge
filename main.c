#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Coding Challenge made by:
//  Ayax Alexis Casarrubias - A01337426
//  Alejandro Olivares Arteaga - A01337525

struct node {
    int age;
    char * name;
    struct node *next;
};
typedef struct node node_t;

void iterateOver(node_t *list) {
  node_t * temp = list;
  
  printf("[");
  while(temp != NULL) {
    printf("%d %s,", temp->age, temp-> name);
    printf(" ");
    temp = temp->next;
  }
  printf("]\n");
}

void add(int age, char * name, node_t **list) {
  node_t *newNode = (node_t *) malloc(sizeof(node_t));
  newNode->age = age;
  newNode->name = name;
  newNode->next = NULL;

  if(*list == NULL) {
    *list = newNode;
  } else {
    node_t * temp = *list;
    // Iterate to the end of the list.
    while(temp->next != NULL) {
      temp = temp->next;
    }

    // Add the node to the end.
    temp->next = newNode;
  }
}

void push(int age, char * name, node_t **list) {
  node_t *listHead = (node_t *) malloc(sizeof(node_t));
  listHead->age = age;
  listHead->name = name;
  listHead->next = NULL;
  
  listHead->next = *list;
  *list = listHead;
  iterateOver(*list);
}

void popFirstFrom(node_t **list) { 
  node_t * temp = *list;

  if(temp != NULL) {
    *list = temp->next;
  }

  iterateOver(*list);
}

void popLastFrom(node_t **list) {
  node_t * temp = *list;

  while(temp->next->next != NULL) {
    temp = temp->next;
  }
  
  temp->next = NULL;
  iterateOver(*list);
}

void getSizeOf(node_t *list) {
  int i = 0;
  node_t * temp = list;
  while(temp != NULL) {
    i++;
    temp = temp->next;
  }
  printf("Size of the list is equal to: %d \n", i);
}

// Works by removing the node at the `.position`.
void removeSpecific(int  position, node_t **list) {
node_t * temp = *list;
  if(*list == NULL){ 
    return ;
  }
  for(int x =2;x<= position;x++){
    temp = temp->next;
  }
   
  node_t *next = temp->next->next;
  free(temp->next);
  temp -> next = next;
} 

// Works by retrieving the node at the `.position`.
void getNodeOf(node_t **list, int  poSee) {
node_t * temp = *list;
  if(*list == NULL){
    return ;
  }
  for(int x =0;x<= poSee;x++){
      if (x == poSee) {
        printf("[ %d %s", temp ->age, temp -> name);
        printf("] \n");
      }     
      temp = temp -> next;
  }
}

void clear(node_t **list) {
    node_t * temp;
    while((*list)->next != NULL) {
        temp = *list;
        *list = (*list)->next;
        free(temp);
    }
    // `.free()` does not set the value of the pointer to NULL, 
    // but the memory pointed to is no longer valid (does not contain a live node)
    // A good practice here is to set the node to NULL
    free(*list);
    *list = NULL; // Now everything is freed 😬
}


int main(void) {
  node_t * list = NULL;
  int  position, poSee;
  
  add(50, "Johnny", &list);
  add(25, "Giorgio", &list);
  add(45, "JOJO", &list);
  iterateOver(list);

  push(20, "Mia", &list);
  popLastFrom(&list);
  popFirstFrom(&list);
  getSizeOf(list);
  printf("Which node would you like to see? \n" );
  scanf("%d", &poSee);
  getNodeOf( &list, poSee);
  printf("Which node would you like to remove? \n" );
  scanf("%d", &position);
  removeSpecific(position, &list);
  clear(&list);
  getSizeOf(list);
  return 0;
}