#include <iostream>
#include <list>
#include<string> 
#include "parser.h"


int currentstate = 1 ;
int NumbCount=0;
int NumbLoc=0;
int OpLoc=0;
int OpCount=0;

void max_array(const int array[], int n,double &max,double &location){
  max=array[0];
  for (int i=1;i<n;i++){
    if (array[i]>max){
      max=array[i];
      location=i;
    }
  }
}

void parser(std::list<struct token_list_node> tokens){
  std::list<struct token_list_node>::iterator my_iterator;

my_iterator=tokens.begin();
double max,location;

while (my_iterator!=tokens.end()){

}

for (int i=0;i<tokens.length(); i++){
  if (my_iterator->is==NUMBER){
    NumbCount++;
  }else if(my_iterator->is==OPERATOR){
    OpCount++;
  }
  my_iterator++;//count how many numbers entered by user
}
my_iterator=tokens.begin();//reinitialize the iterator to the first token
int *NumbArr=new int[NumbCount];//initialize dynamic array for numbs
int *OpArr=new int[OpCount];//operators array
for (int i=0;i<tokens.length(); i++){
  if (my_iterator->is==NUMBER){
    NumbArr[NumbLoc]=my_iterator->NUMBER;
    NumbLoc++;
  }else if(my_iterator->is==OPERATOR){
    switch (my_iterator->OPERATOR)//find what operator is used and assign a number to the array
    {
      case ADD:{
        OpArr[OpLoc]=1;
        break;
      }case SUB:{
        OpArr[OpLoc]=2;
        break;
      }case MUL:{
        OpArr[OpLoc]=3;
        break;
      }case DIV:{
        OpArr[OpLoc]=4;
        if (my_iterator++->Number==0.0){
          //error
        }
        break;
      }case POW:{
        OpArr[OpLoc]=5;
        break;
      }
    }OpLoc++;
  }
  my_iterator++;
}my_iterator=tokens.begin();
//switch () operator array to find the case and act based on the number array
for (int i=0;i<OpLoc;i++){
max_array(OpArr,OpLoc,max,location);
}
delete []OpArr;
delete []NumbArr;
OpArr=nullptr;
NumbArr=nullptr;
}
