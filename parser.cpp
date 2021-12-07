#include <iostream>
#include <list>
#include<string> 

int currentstate = 1 ;
int NumbCount=0;
int NumbLoc=0;
int OpLoc=0;
int OpCount=0;

void parser(std::list<struct token_list_node> tokens){
  std::list<struct token_list_node>::iterator my_iterator;
my_iterator=tokens.begin();

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
    switch (my_iterator->OPERATOR){
      case ADD:{
        OpArr[OpLoc]=0;
        break;
      }case SUB:{
        OpArr[OpLoc]=1;
        break;
      }case MUL:{
        OpArr[OpLoc]=2;
        break;
      }case DIV:{
        OpArr[OpLoc]=3;
        if (my_iterator++->Number==0){
          //error
        }
        break;
      }case POW:{
        OpArr[OpLoc]=4;
        break;
      }
    }OpLoc++;
  }
  my_iterator++;
}my_iterator=tokens.begin();

}
