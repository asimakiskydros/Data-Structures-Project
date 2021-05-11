#include "unsortedArray.h"
#ifndef sortedarr_h
#define sortedarr_h

class sortedArray: public unsortedArray
{
  protected:
  bool wordExists(char *, int, int);//Looks for the word with binary search, returns true or false depending on if the word is found or not.
  
  int numOfWords=0; //The number of unique words. I need it in the sorting process

  char *tmp;//helps me swap the words in the sorting process
  int tmp1;//helps me swap the sum and length values in the sorting process

  int mid;//helps me with the searching process
  
  public:
  void sort();//sorts the arrays with bubble sort
  void search(char *, int, int);//Looks for the word with binary search, shows the times the word has appeared(if it exists) plus the searching time
  bool delete_word(char *);//Deletes a specific word in the array and returns true, if the word isn't found returns false

  void insert(char *);//Inserts the unique words in the array while the array is getting sorted. If the given word already exists, nothing is inserted and only the sum array is updated
};

#endif



//same kai edo... an dis kati pou den sou aresi, comment xD
