#include "unsortedArray.h"
#include <iostream>
#include <cstring>
#include <chrono>
using namespace std;

unsortedArray::unsortedArray()
{
  //initializing integers to 0 and pointers to NULL
  last_word=0;
  words=NULL;
  sum=NULL;
  length=NULL;
}

unsortedArray::~unsortedArray()
{
  //If the pointers are pointing to memory, we delete them, otherwise we don't.
  if(words!=NULL)
    delete words;
  if(sum!=NULL)  
    delete sum;
  if(tempWords!=NULL)
    delete tempWords;
  if(tempSum!=NULL)
    delete tempSum;
}


void unsortedArray::insert(char* string)
{
  if(words==NULL && sum==NULL)//Basically this block of code runs only on the FIRST word given and allocates memory for the 2 arrays.
  {
    arr_size=last_word+5;//The array's size will increase by 5 every 5 words given.
    words = new char*[arr_size];
    sum= new int[arr_size];
    length = new int[arr_size];
    firstWord = true;//This will become false once the second word is given.
  }
  if(!wordExists(string))//If the word does not exist, we put it in the array.
  {
    //We need this in order to make sure that the value of last_word won't increase if a new word is not given
    if(firstWord==false)
      last_word++;

    if(last_word>arr_size-1)//If the array is full its size will increase by 5.
    {
      arr_size+=5;

      //Creating temporary pointers that point to the new, bigger arrays.  
      char **tempWords=new char*[arr_size];
      int *tempSum=new int[arr_size];
      int *tempLength= new int[arr_size];
      
      //Copying the old array's contents to the new arrays.
      for(i=0; i<=last_word; i++)
      {
        tempWords[last_word]=new char[length[last_word]];
        strcpy(tempWords[last_word], words[last_word]);
        tempSum[last_word]=sum[last_word];
        tempLength[last_word]= length[last_word];
      }
      
      //Pointing the old pointers to the new arrays and deleting the temporary pointers.
      delete words;
      words = tempWords;
      delete sum;
      sum= tempSum;
    }

    int len = strlen(string) + 1; //Holds the length of the given word
    length[last_word]=len; //Stores the length of the word in an array, will need this array to increase the size of the words[] array and for possible sorting
    words[last_word] = new char[len]; //Allocating the required memory of the given word with the help of len
    strcpy(words[last_word], string);//Copying the word into the array.
    sum[last_word]=1;//Updating the parallel array, the new word has obviously only appeared once.
    firstWord=false; //The first word is already placed in the array.
  }
  else//This means that the words exists, so the number that the word has appeared increases by 1. indx is the index of the found word after performing linear searching.
  {
    sum[indx]++;
  }
}

//PRIVATE, I NEED THIS IN ORDER TO KNOW IF I SHOULD UPDATE THE ARRAYS OR NOT.
bool unsortedArray::wordExists(char* string)
{
  indx=0;
  bool flag=false;//If the word is found, flag will become true.
  while(indx<=last_word && flag==false)
  {
    if(strcmp(string,words[indx])==0)//checks if the given word is the same word as words[indx]
    {
        flag=true;//The word is found!
    }
    else
    {
      indx++; //Checking the next word.
    }
  }
  return flag;
}



void unsortedArray::search(char* string)
{
  //The following lines of code searches if the word exists in the array, just like the linear searching we did above
  auto start= chrono::high_resolution_clock::now();
  if(wordExists(string))
  {
    //The word is found, so we will print how many times the word has appeared and the execution time.
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration= std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout<<"String \""<<string<<"\" exists in the unsorted array "<<sum[indx]<<" time(s) (search time: "<<duration.count()<<" seconds)."<<endl;
  }//asimakis: otan kaneis testing pes m ligo an doulevei gia sena auto to setup me to high resolution clock. emena m evgaze 0 se ola lol. to exw allaksei ligo sto tree alla sinexizei na min einai kai poli kalo
  else
  {
    //The word is not found
    auto stop = std::chrono::high_resolution_clock::now();
    return;
  }
}


bool unsortedArray::delete_word(char * string)
{
  if(!wordExists(string))
  {
    return false; //The given word does not exist in the array
  }
  else
  {
    delete words[indx];// The given word exists in the array, so we delete it by using the indx we got from linear searching
    return true;
  }
}
