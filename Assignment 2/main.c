/* COP 3502C Assignment 2
This program is written by: Asma Ahmed */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Given the (x, y) positions of 2ntreehouse, of all possible ways to create n pairs of distinct trees, find the minimum possible sum of distances between each tree in the pairs.

int tree[10][2]; //2d array for coordinates- take 2 parameters 
int pair[10]; //1D array for pairs
int n; //number of test cases
float size; 

//declare files
FILE* inputFile;
FILE* outputFile;

//calculate distance 
void calcDist(){

  //declare variables
  float distance=0;
  int insidesquare;
  int i;

  //calulate within pairs
  for(int i=1; i<=2*n; i++){
    //calculation: sqrt (xi-xj)^2 + (yi-yj)^2 
    //math inside the square root
    insidesquare = (tree[i][0] - tree[pair[i]][0]) * (tree[i][0] - tree[pair[i]][0]) + (tree[i][1] - tree[pair[i]][1]) * (tree[i][1] - tree[pair[i]][1]);
    
    //square the math
    distance+=sqrt((float)insidesquare);
  }

  //divide by 2 (number of trees per pair)
  distance=distance/(float)2;
  
  //make it fit
  if(size > distance) 
    size=distance;
} //end calcDist

//permutation to find all possible pairs
void perm(){
  int i=0;
  
  //check pairs, break if not pairs
  for(i=1; i<=2*n; i++){
    if(pair[i]==0) 
    break;
  }

  if(i > 2*n){
    //check answer for the combination
    calcDist();
    return;
  }

  //pair the unpair tree
  for(int j=1; j<=2*n; j++){
    if(j!=i && pair[j]==0){
     pair[i]=j;
     pair[j]=i;

    //recurse
     perm();
    }
  }
} //end perm

//main
int main(void){

  int test;
  int i;

  //open files
  inputFile = fopen("in.txt", "r");
  outputFile = fopen("out.txt", "w");

  //scan for number of test cases
  fscanf(inputFile,"%d", &test);

  //iterate through test cases
  while(test--){
    
    size=1e4; //big number very big (10000 ≤ xi, yi ≤ 10000)

    //scan for n
    fscanf(inputFile,"%d",&n);

    //scan for coordinates
    for(int i=1;i<=2*n;i++){
      fscanf(inputFile,"%d%d",&tree[i][0],&tree[i][1]);
    }

    perm(); //call permutation function

    printf("%0.3f\n", size); //print to console
    fprintf(outputFile,"%0.3f\n", size); //print to file
  }

  //close files
  fclose(inputFile);
  fclose(outputFile);

  return 0;
} //end main