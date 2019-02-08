#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <linkedList.h>
#include <ctype.h>

void load(node_t **list) {
  FILE * stream = fopen("dataC.csv", "r");
  char line[1024];

  while (fgets(line, 1024, stream)) {
    char *name = (char *) malloc(10 * sizeof(char));
    strcpy(name, strtok(line, ","));
    int age = 0;
    age = atoi(strtok(NULL, ""));
    add(age, name, list);
  }
  free(stream);
} 

void printNamesWithGiven(node_t *list) {
  char letter;
  printf("Which letter would you like to use?\n");
  scanf("%s", &letter);

  node_t * temp = list;
  
  printf("[");
  while(temp != NULL) {
    char *name = temp->name;
    
    if(tolower(letter) == tolower(name[0])) {
      printf("%s\n", name);
    }

    temp = temp->next;
  }
  printf("]\n");
}

void getOldest(node_t **list){
		node_t * temp = *list;
		int max = 0;
		node_t *ans = *list;
    int size = getSizeOf(*list);
		for(int i = 0; i < size; i++){
      //printf("new Min test");
				if (temp->age < max)
				{
					max = temp->age;
					ans = temp;
				}
        temp = temp->next;
		}
		printf("Oldest: %d %s \n",ans->age,ans->name );
}

void getYoungest(node_t **list){
		node_t * temp = *list;
		int min = 10000;
		node_t *ans = *list;
    int size = getSizeOf(*list);
		for(int i = 0; i < size; i++){
      //printf("new Min test");
				if (temp->age < min)
				{
					min  = temp->age;
					ans = temp;
				}
        temp = temp->next;
		}
		printf("Youngest: %d %s \n",ans->age,ans->name );
}

void getAverage(node_t ** theList){
  node_t *one = (node_t *)malloc(sizeof(node_t));
  one = *theList;  
  int sum = 0;
  int size = getSizeOf(*theList);
  for(int x=0; x < size;x++){
    sum=sum + one -> age;
    one = one -> next;
  }
  sum= sum/ size;
  printf("The average of ages is %d \n",sum);
}

int main(void) {
  node_t *list = NULL;
  load(&list);
  
  int choice;
  do {
    printf("Menu\n\n");
    printf("0. Print the linked list\n");
    printf("1. Print the oldest person\n");
    printf("2. Print the youngest person\n");
    printf("3. Print the average of all ages\n");
    printf("4. Print all names that start with a given letter\n");
    printf("5. Exit\n");
    scanf("%d",&choice);
    switch(choice) {
      case 0: 
        iterateOver(list);
        break;
      case 1: 
        getOldest(&list);
        break;
      case 2: 
        getYoungest(&list);
        break;
      case 3: 
        getAverage(&list);
        break;
      case 4:
        printNamesWithGiven(list);
        break;
      case 5:
        printf("Goodbye");
        break;
    }
  } while (choice != 5);

  return 0;
}