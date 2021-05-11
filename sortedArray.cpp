#include "sortedArray.h"
#include <cstring>
#include <chrono>
#include <iostream>
using namespace std;

void sortedArray::insert(char* string)
{
  if(words==NULL && sum==NULL)//Basically this block of code runs only on the FIRST word given and allocates memory for the 2 arrays.
  {
    arr_size=last_word+5;//The array's size will increase by 5 every 5 words given.
    words = new char*[arr_size];
    sum= new int[arr_size];
    length = new int[arr_size];
    firstWord = true;//This will become false once the second word is given.
  }
  if(!wordExists(string,0,numOfWords))//If the word does not exist, we put it in the array.
  {
    numOfWords++;// +1 unique word
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
    sort();//sort the array
  }
  else//This means that the words exists, so the number that the word has appeared increases by 1. indx is the index of the found word after performing linear searching.
  {
    sum[indx]++;
  }
}






void sortedArray::sort()
{
  //bubble sort
  for(int t=2; t<=numOfWords; t++)
    {
      for(int h=numOfWords; h>=t; t--)
        {
          //sorting in ascending order
          if(strcmp(words[h-1],words[h])>0)
          {
            //swapping the words(with the help of the length array)
            tmp= new char[length[h-1]];
            strcpy(tmp,words[h-1]);

            words[h-1]= new char[length[h]];
            strcpy(words[h-1],words[h]);

            words[h]= new char[length[h-1]];
            strcpy(words[h],tmp);

            //Also, swapping the length array values
            tmp1=length[h-1];
            length[h-1]=length[h];
            length[h]=tmp1;
            
            //Finally, swapping the sum array values
            tmp1=sum[h-1];
            sum[h-1]=sum[h];
            sum[h]=tmp1;
          }
        }
    }
  delete tmp;
}



//PRIVATE, I NEED THIS IN ORDER TO KNOW IF THE ARRAYS SHOULD BE UPDATED OR NOT
bool sortedArray::wordExists(char* string, int low, int high)
{
  if(low>high)
    return false;
  else
  {
    mid=(low+high)/2;
    if(strcmp(string,words[mid])==0)
    {
      indx=mid;
      return true;
    }  
    else if(strcmp(string, words[mid])>0)
      return wordExists(string,mid+1,high);
    else if (strcmp(string, words[mid])<0)
      return wordExists(string,low,mid-1);
  }
}



void sortedArray::search(char* string, int low, int high)
{
  auto start= chrono::high_resolution_clock::now();
  if(wordExists(string, low, high))
  {
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration= std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout<<"String \""<<string<<"\" exists in the unsorted array "<<sum[indx]<<" time(s) (search time: "<<duration.count()<<" seconds)."<<endl;
  }
  else
  {
    auto stop = std::chrono::high_resolution_clock::now();
    return;
  }  
}



bool sortedArray::delete_word(char* string)
{
  if(unsortedArray::delete_word(string))
  {
    sort();
  }  
}


