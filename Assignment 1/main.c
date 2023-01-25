/* COP 3502C Assignment 1
This program is written by: Asma Ahmed */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leak_detector_c.h"  

#define MAXSTRLEN 21

//declare file pointers as global variables
FILE* inputFile;
FILE* outputFile;

//required structs | do not modify
//stores  one  component  of  a  smoothie  recipe
typedef struct item {    
  int itemID; //represents ingredient  number (I)      
  int numParts; //represents number of parts ingredient (R)
} item;

//stores one smoothie recipe
typedef struct recipe {     
  int numItems; //stores number  of  different  ingredients  
  item* itemList; // DMA array |  each  slot  stores 1  ingredient 
  int totalParts; //sum of numParts of each ingredient in smoothie
} recipe;

/* READ INGREDIENTS FUNCTION
Pre-condition: reference to a variable to store number of ingredients. (numIngredients)
Post-condition: Reads in numIngredients and that number of strings from the inputFiles, allocates an array of strings to store the inputFile, and sizes each individual string dynamically to be the proper size (string length plus 1), and returns a pointer to the array.
*/                             
char** readIngredients(int *numIngredients){
  //array for names of ingredients + index
  char ingredient[MAXSTRLEN];
  int i;

  //array of pointers
  char** ingredientList;
  fscanf(inputFile, "%d", numIngredients); //reads in numIngredients 

  ingredientList = (char**) malloc(*numIngredients * (sizeof(char*)));
  for(int i=0; i <*numIngredients; i++){
    fscanf(inputFile, "%s", ingredient); //scan for strings
    int ingLength = strlen(ingredient)+1; //size each string to string length + 1

    ingredientList[i] = (char*) malloc (ingLength*sizeof(char));

    strcpy(ingredientList[i], ingredient);
  }
  
  return ingredientList; //return pointer to array
}

/* READ RECIPE FUNCTION
Reads in details of a recipe such as numItems Dynamically allocates space for a single recipe, dynamically allocates an array of item of the proper size, updates the numItems field of the struct, fills the array of items appropriately based on the inputFile and returns a pointer to the struct dynamically allocated.
*/            
recipe* readRecipe(){
  //readRecipe is called in readAllRecipes
  recipe* oneRecipe;
  item* itemList;

  int ratio;
  int temp;
  int n;

  fscanf(inputFile, "%d", &temp);

  //dynamically allocates space for a single recipe
  oneRecipe = (recipe*) calloc (n, temp * sizeof(recipe));
  oneRecipe->numItems = temp; //points to struct
  oneRecipe->totalParts = 0;

  //allocates an array of item
  itemList = (item*) malloc (oneRecipe->numItems * sizeof(item*)); 

  //read itemID and numParts
  for(ratio = 0; ratio < oneRecipe->numItems; ratio++){
    fscanf(inputFile, "%d %d", &itemList[ratio].itemID, &itemList[ratio].numParts);
    oneRecipe->totalParts += itemList[ratio].numParts;
  }
  oneRecipe->itemList = itemList;

  return oneRecipe; //return pointer to struct
}

/* READ ALL RECIPES FUNCTION
Read number of recipes. Dynamically allocates an array of pointers to recipes of size numRecipes, reads numRecipes number of recipes from standard input, creates structs to store each recipe and has the pointers point to each struct, in the order information was read in. 
*/
recipe** readAllRecipes(int *numRecipes){

  recipe** smoothieList;
  smoothieList = (recipe**) malloc(*numRecipes * sizeof(recipe*));
  int i;

  //call readRecipe in a loop
  for(int i=0; i < *numRecipes; i++){
    smoothieList[i] = readRecipe();
  }

  return smoothieList;
}

/* CALCULATE ORDER
Pre-condition: 0 < numSmoothies <= 100000, recipeList points to list of all smoothie recipes and numIngredients equals the number of total ingredients (already read it in first line of inputFile).
Post-condition: Reads in information from standard input about numSmoothies number of smoothie orders and dynamically allocates an array of doubles of size numIngredients such that index i stores the # of pounds of ingredient i needed to fulfill all smoothie orders and returns a pointer to the array.
*/
double* calculateOrder(int ingredientCount, int numSmoothies, recipe** recipeList){

  int storeMenu; //smoothie recipes
  int smoothie; //s
  int weight; //w
  int i, s, t; 

  //numIngredients = ingredientCount
  double *orderList = (double*) malloc (ingredientCount * sizeof(double*));

  for(int i=0; i<ingredientCount; i++){
    orderList[i]=0;
  }

  //read from standard input
  fscanf(inputFile, "%d", &storeMenu);
  for(int s=0; s<storeMenu; s++){
    fscanf(inputFile,"%d", &smoothie);
    fscanf(inputFile,"%d", &weight);

    //calculation in loop
    for(int t=0; t<recipeList[smoothie]->numItems; t++){
      orderList[recipeList[smoothie]->itemList[t].itemID] += (recipeList[smoothie]->itemList[t].numParts) * (((double)weight) / (recipeList[smoothie]->totalParts));
    }
  }

  return orderList; //return pointer to array
}

/* PRINT ORDER FUNCTION
Pre-conditions: ingredientNames store the names of each ingredient and orderList stores the amount to order for each ingredient, and both arrays are of size numIngredients.
Post-condition: Prints out a list, in ingredient order, of each ingredient, a space and the amount of that ingredient to order rounded to 6 decimal places. One ingredient per line.
*/
void printOrder(char** ingredientNames, double* orderList, int numIngredients){
  int i;

  //print loop
  for(int i=0; i < numIngredients; i++){
    if(orderList[i] !=0){
      printf("%s %.6f\n", ingredientNames[i], orderList[i]);
      fprintf(outputFile,"%s %.6f\n", ingredientNames[i], orderList[i]);
    }
  }

  free(orderList);
}

//FREE INGREDIENTS
void freeIngredients(char** ingredientList, int numIngredients){
  int i;

  for(int i=0; i<numIngredients; i++){
    free(ingredientList[i]);
  }
  free(ingredientList);
}

//FREE RECIPES
void freeRecipes(recipe** allRecipes, int numRecipes){
  int i;

    for(int i=0; i<numRecipes; i++){
      free(allRecipes[i]->itemList);
      free(allRecipes[i]);
    }
  free(allRecipes);
}

//MAIN FUNCTION
int main() {
  atexit(report_mem_leak);   //leak detector

  //declare variables
  int numIngredients;
  int numRecipes; 
  int numStores;
  int i;

  //files
  inputFile = fopen("in.txt", "r");
  outputFile = fopen("out.txt", "w");

  //read file
  fscanf(inputFile, "%d", &numIngredients);
  char **ingredients = readIngredients(&numIngredients);

  fscanf(inputFile, "%d", &numRecipes);
  recipe **smoothieList = readAllRecipes(&numRecipes);

  fscanf(inputFile, "%d", &numStores);

  //write files/ print
  for (int i=0; i <numStores; i++)
  {
    printf("Store #%d:\n", (i+1));
    fprintf(outputFile, "Store #%d:\n", (i+1));

    //call functions
    double* amtOfEachItem = calculateOrder(numIngredients, numRecipes, smoothieList);
    printOrder(ingredients, amtOfEachItem, numIngredients);

    printf("\n");
    fprintf(outputFile, "\n");
  }

  freeIngredients(ingredients, numIngredients);
  freeRecipes(smoothieList, numRecipes);

  fclose(inputFile);
  fclose(outputFile);
  
  return 0;
}