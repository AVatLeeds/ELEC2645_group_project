#include <iostream>
#include <list>
#include<string> 
#include "parser.h"
#include "cmath"

int NumbCount=0;
int NumbLoc=0;
int OpLoc=0;
int OpCount=0;
double out;
double a,b;

void max_array(const int array[], int n,int &max,int &location){
  max=array[0];
  for (int i=1;i<n;i++){
    if (array[i]>max){
      max=array[i];
      location=i;
    }
  }
}

double parser(std::list<struct token_list_node> tokens){
  std::list<struct token_list_node>::iterator my_iterator;

my_iterator=tokens.begin();
int max,location;

while (my_iterator!=tokens.end()){
  if (my_iterator->is==NUMBER){
    NumbCount++;
  }else if(my_iterator->is==OPERATOR){
    OpCount++;
  }
  my_iterator++;//count how many numbers entered by user
}
my_iterator=tokens.begin();//reinitialize the iterator to the first token
if(OpCount++!=NumbCount){
  return 0;
  //error
  //checks that there is always one operator less than there are numbers
}
int *NumbArr=new int[NumbCount];//initialize dynamic array for numbs
int *OpArr=new int[OpCount++];//operators array with an extra place for the last number which is always 1
OpArr[OpCount++]=1;
while (my_iterator!=tokens.end()){
  if (my_iterator->is==NUMBER){
    NumbArr[NumbLoc]=my_iterator->NUMBER;
    NumbLoc++;
  }else if(my_iterator->is==OPERATOR){
    switch (my_iterator->OPERATOR)//find what operator is used and assign a number to the array
    {
      case ADD:{
        OpArr[OpLoc]=2;
        break;
      }case SUB:{
        OpArr[OpLoc]=3;
        break;
      }case MUL:{
        OpArr[OpLoc]=4;
        break;
      }case DIV:{
        OpArr[OpLoc]=5;
        if (my_iterator++->Number==0.0){
          //error
        }
        break;
      }case POW:{
        OpArr[OpLoc]=6;
        break;
      }
    }OpLoc++;
  }
  my_iterator++;
}my_iterator=tokens.begin();
//find out the numbers the operation is applied to
for (int i=0;i<OpLoc;i++){
  max_array(OpArr,OpLoc,max,location);
  a = NumbArr[location];
  OpArr[location]=0;
  if(max!=1 && OpArr[location++]!=0.0){
    b=NumbArr[location++];
    }else if(max==1){
      b=0;
      }else{
      while(OpArr[location++]==0.0){
        location++;
        } b=NumbArr[location++];
        }
     

  //switch () operator array to find the case and act 
  switch(max){
    case 6:{
      out=pow(a,b);
      NumbArr[location++]=out;
      break;
    }
    case 5:{
      out=a/b;
      NumbArr[location++]=out;
      break;
    }case 4:{
      out=a*b;
      NumbArr[location++]=out;
      break;
    }case 3:{
      out=a-b;
      NumbArr[location++]=out;
      break;
    }case 2:{
      out=a+b;
      NumbArr[location++]=out;
      break;
    }case 1:{
      return a;
      break;
    }

  }
}
delete []OpArr;
delete []NumbArr;
OpArr=nullptr;
NumbArr=nullptr;
}
