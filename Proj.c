#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE * file1 = fopen("Stock.txt","r+");
  
  //Check how many lines are in txt file to get proper array length
  char *line = NULL;
  size_t line_size = 0;
  int size = 0;
  while(getline(&line, &line_size, file1) != -1){
    size++;
  }
  int quantity[size];
  char items[size][20];

  FILE * file2 = fopen("Stock.txt","r+");
  for(int i = 0; i < size; i++){
    char str[10];
    char comma[1];
    int num = 0;
    //Get string and add to array items
    fscanf(file2, "%[^,]", str);
    strcpy(items[i], str);
    //Discard comma
    fscanf(file2, "%[,]", comma);
    //Get number and add to array quantity
    fscanf(file2, "%d", &num);
    quantity[i] = num;
    //Discard new line
    fscanf(file2, "%[\n]", comma);
  }
  //input for items to remove from stock
  char item_str[1000];
  printf("Enter items(seperated by only a comma and all lowercase): ");
  fgets(item_str, 1000, stdin);
  int counter = 0;
  //get number of items entered
  for(int i = 0; i < strlen(item_str); i++){
    if(item_str[i] == ','){
      counter++;
    }
  }
  //add extra index to array due to no comma on last item
  if(strlen(item_str) > 0){
    counter++;
  }
  //take items from item_str  and put them in an array
  int index = 0;
  char toRemove[counter][20];
  for(int i = 0; i < counter; i++){
    for(int j = 0; j < 20; j++){
      int endex = 0;
      if(item_str[index] != ',' && item_str[index] != '\n'){
	toRemove[i][j] = item_str[index];
	endex = j;
      } else {
	//sets string length correctly
	toRemove[i][j] = '\0';
      }
      if(endex == j){
	index++;
      } 
    }
    index++;
  }
  //Decrement original array values in quantity
  for(int i = 0; i < counter; i++){
    for(int j = 0; j < size; j++){
      if(memcmp(toRemove[i], items[j], strlen(toRemove[i])) == 0){
	quantity[j]--;
      }
    }
  }

  //replace quantities with new ones in Stock file
  //if item is at 0 add it to the toOrderlist
  FILE * replace = fopen("Stock.txt","w+");
  FILE * toOrder = fopen("toOrderList.txt","a+");
  for(int i = 0; i < size; i++){
    if(quantity[i] != 0){
      fprintf(replace, "%s, %d\n", items[i], quantity[i]);
    } else {
      fprintf(toOrder, "%s\n", items[i]);
    }
  }
  //close files
  fclose(file1);
  fclose(file2);
  fclose(replace);
  fclose(toOrder);
}
