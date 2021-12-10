#include <iostream>
#include <list>
#include<string> 
#include "parser.h"
#include <cmath>
#include "tokenizer.h"

void max_array(const double array[], int n,int &max,int &location)
{
  max=array[0];
  location=0;
  for (int i=1;i<=n;i++)
  {
    if (array[i]>max)
    {
      max=array[i];
      location=i;
    }
  }
}

double parser(std::list<struct token_list_node> tokens)
{
	int NumbCount=0;
	int NumbLoc=0;
	int OpLoc=0;
	int OpCount=0;
	double out;
	double a,b;

  std::list<struct token_list_node>::iterator my_iterator;

my_iterator=tokens.begin();
int max,location;

while (my_iterator!=tokens.end())
{
  if (my_iterator->is==NUMBER)
  {
    NumbCount++;
  }else if(my_iterator->is==OPERATOR)
  {
    OpCount++;
  }
  my_iterator++;//count how many numbers entered by user
}
my_iterator=tokens.begin();//reinitialize the iterator to the first token
if(OpCount+1!=NumbCount)
 {
 return 0;
 }
  //error
  //checks that there is always one operator less than there are numbers

double *NumbArr=new double[NumbCount];//initialize dynamic array for numbs
double *OpArr=new double[NumbCount];//operators array with an extra place for the last number which is always 1
while (my_iterator!=tokens.end())
{
  if (my_iterator->is==NUMBER)
  {
    NumbArr[NumbLoc]=my_iterator->number;
    NumbLoc++;
  }else if(my_iterator->is==OPERATOR)
  {
    switch (my_iterator->op)//find what operator is used and assign a number to the array
    {
      case ADD:
        OpArr[OpLoc]=2;
        break;
      case SUB:
        OpArr[OpLoc]=3;
        break;
      case MUL:
        OpArr[OpLoc]=4;
        break;
      case DIV:
        OpArr[OpLoc]=5;
        break;
      case POW:
        OpArr[OpLoc]=6;
        break;
      
    }OpLoc++;
  }
  my_iterator++;
  
}
my_iterator=tokens.begin();
OpArr[OpCount]=1;
for (int i=0;i<NumbCount;i++){
}
//find out the numbers the operation is applied to
for (int i=0;i<=OpLoc;i++)
{
  max_array(OpArr,OpLoc,max,location);
  a = NumbArr[location];
  OpArr[location]=0;
  if(max!=1 && OpArr[location+1]!=0.0)
  {
    b=NumbArr[location+1];
  }else if(max==1)
    {
     b=0;
    }else
     {
      while(OpArr[location+1]==0.0)
      {std::cout<<"err";
        location++;
      } b=NumbArr[location+1];
     }
     
  //switch () operator array to find the case and act 
  switch(max)
  {
    case 6:
      out=pow(a,b);
      NumbArr[location+1]=out;
      break;
    
    case 5:
      if(b==0)
      {
        return 0;
        //error
      }else
      {
       out=a/b;
       NumbArr[location+1]=out;
      }
      
      break;
    case 4:
      out=a*b;
      NumbArr[location+1]=out;
      break;
    case 3:
      out=a-b;
      NumbArr[location+1]=out;
      break;
    case 2:
      out=a+b;
      NumbArr[location+1]=out;
      break;
    case 1:
      break;
    

  }

}
return a;
delete []OpArr;
delete []NumbArr;
OpArr=nullptr;
NumbArr=nullptr;
}
