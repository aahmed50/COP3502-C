## Project 1 | Dynamic Memory Allocation

Problem Description: Making Smoothies
<br>

A smoothie is a blended drink concoction, with several ingredients. Each different type of smoothie has a different ratio of its ingredients. This program will read in information about several smoothie recipes and several stores expected sales for the week, and determine what raw ingredients (and how much of each) each store should order.
<br>

Given a list of possible smoothie ingredients, a list of smoothie recipes, and lists of sales from several stores, determine how much of each ingredient each store must order.
<br>

### Components: 

READ INGREDIENTS FUNCTION </br>
Pre-condition: reference to a variable to store number of ingredients. (numIngredients)
Post-condition: Reads in numIngredients and that number of strings from the inputFiles, allocates an array of strings to store the inputFile, and sizes each individual string dynamically to be the proper size (string length plus 1), and returns a pointer to the array.

READ RECIPE FUNCTION </br>
Reads in details of a recipe such as numItems Dynamically allocates space for a single recipe, dynamically allocates an array of item of the proper size, updates the numItems field of the struct, fills the array of items appropriately based on the inputFile and returns a pointer to the struct dynamically allocated.

READ ALL RECIPES FUNCTION </br>
Read number of recipes. Dynamically allocates an array of pointers to recipes of size numRecipes, reads numRecipes number of recipes from standard input, creates structs to store each recipe and has the pointers point to each struct, in the order information was read in. 

CALCULATE ORDER FUNCTION </br>
Pre-condition: 0 < numSmoothies <= 100000, recipeList points to list of all smoothie recipes and numIngredients equals the number of total ingredients (already read it in first line of inputFile).
Post-condition: Reads in information from standard input about numSmoothies number of smoothie orders and dynamically allocates an array of doubles of size numIngredients such that index i stores the # of pounds of ingredient i needed to fulfill all smoothie orders and returns a pointer to the array.

PRINT ORDER FUNCTION </br>
Pre-conditions: ingredientNames store the names of each ingredient and orderList stores the amount to order for each ingredient, and both arrays are of size numIngredients.
Post-condition: Prints out a list, in ingredient order, of each ingredient, a space and the amount of that ingredient to order rounded to 6 decimal places. One ingredient per line.
