

#include "unsortedArray.h"
#include <iostream>
#include <cstring>
#include <chrono>
using namespace std;

unsortedArray::unsortedArray()
{
  last_word=0;
  words=NULL;
  sum=NULL;
}

unsortedArray::~unsortedArray()
{
  delete words;
  delete sum;
  delete tempWords;//i think i dont need to do this
  delete tempSum;//i think that i dont need to do this x2
}

void unsortedArray::insert(char* string)
{
  if(words==NULL && sum==NULL)//basically this block of code runs only on the FIRST word given and allocates memory for the 2 arrays
  {
    words = new char*[last_word+1];
    sum= new int[last_word+1];
    firstWord = true;
  }
  if(!wordExists(string))
  {
    if(firstWord==false)
      last_word++;

    int len = strlen(string) + 1;

    words[last_word] = new char[len];
    strcpy(words[last_word], string);

    sum[last_word]=1;

    char **tempWords=new char*[last_word+1];
    int *tempSum=new int[last_word+1];

    for(i=0; i<=last_word; i++)
    {
      strcpy(tempWords[last_word], words[last_word]);
      tempSum[last_word]=sum[last_word];
    }

    delete words;
    words = tempWords;
    delete sum;
    sum= tempSum;

    firstWord=false;
  }
  else//this means that the words exists, so the number that the word has appeared grows
  {
    sum[indx]++;
  }
}


//PRIVATE, I NEED THIS IN ORDER TO KNOW IF I SHOULD UPDATE THE ARRAYS OR NOT.
bool unsortedArray::wordExists(char* string)
{
  bool flag=false;
  while(indx<=last_word && flag==false)
  {
    if(strcmp(string,words[last_word])==0)
    {
        flag=true;
    }
    else
    {
      indx++;
    }
  }
  return flag;
}



void unsortedArray::search(char* string)
{
  bool flag=false;
  auto stop= chrono::high_resolution_clock::now();//COPYPASTAAAAAAA, to prosthesa epidi to prostheses XDDD
  while(indx<=last_word && flag==false)
  {
    if(strcmp(string,words[last_word])==0)
    {
        flag=true;
    }
    else
    {
      indx++;
    }
    if(flag)
    {
      cout<<"String \""<<string<<"\" exists in the unsorted array "<<sum[indx]<<" time(s) (search time: "<<duration.count()<<" seconds)."<<endl;//copypasta, den exo polikatalavi to duration :')
    }
    else
    {
      return;
    }
  }
}


bool unsortedArray::delete_word(char * string)
{
  if(!wordExists(string))
  {
    return false;
  }
  else
  {
    delete words[indx];
  }
}

//NOT DONE AT ALL
