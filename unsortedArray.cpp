

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
}//Asimakis: giati na min xriazetai? rwtaw giati an ta diagrafeis kapou allou kai mpoun ston destructor kena tha fas SegFault (speaking from experience xdd)
//Sigourepse oti kouvaloun desmeumeni mnimi otan mpainoun ston destructor kai meta na ta kaneis delete - kata t'alla delete xriazontai ola, nai


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
}//Asimakis: etsi opws ta vlepw dn mporw na vrw kapoio fanero lathos - char ** xrisimopoiousa ki egw stis askiseis tou lentza me ta strings opote eimai arketa confident oti
//doulevei. To mono pou tha sou protina einai an thes na auksaneis to megethos tou array kata 5-10 kathe fora pou exeis ftasei sto limit kai oxi kata 1 kathe fora pou kaneis insert
//Kanei ton kwdika pio grigoro - kai den se xalaei ama telika den xrisimopoihthoun kapoies theseis giati max 4-9 theseis tha minoun kenes se olo to programma kai exoume na kanoume
//me keimeno 10000+ leksewn xd


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
  }//Asimakis: min nomizeis oti egw ktlvenw ti kanw me ta high resolution clock xd, ki egw copy pasta ta ekana. Dn ta exeis parei ola omws, sou dinw to arthro p diavasa
}//gia na ktlveis pos prepei na ta valeis ston kwdika: https://www.geeksforgeeks.org/measure-execution-time-function-cpp/


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
