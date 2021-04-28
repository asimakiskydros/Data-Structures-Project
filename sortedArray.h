#include "unsortedArray.h"
#ifndef sortedarr_h
#def sortedarr_h

class sortedArray: public unsortedArray
{
  private:
  //i will add sum stuff here .
  
  public:
  sortedArray();
  ~sortedArray();//will probably delete the array// !!!!!!!****
  void sort();//sorts the array
  bool search(char *)//Looks for the word with binary search, returns true or false depending on if the word is found or not. 
  bool delete_word(char *);//Deletes a specific word in the array and returns true, if the word isn't found returns false
  void insert(char *);//Inserts the unique words in the array, then the array gets sorted and if the given word already exists(after binary searching), nothing is inserted and only the sum array is updated
};

#endif




//ASIMAKI SAMA, HALP IF WHEREVER HALP IS NEEDED, THENK U!
//to exo psilosnobari to unsorted array, tha to doulepso me to pou nioso oti teliosa kapos to sorted array..

//Asimakis:
//****!!!: min kaneis destructor ama i klasi klironomei apo to unsorted, tha fas megalo goal apo ton compiler. Ousiastika ta paidia twn klasewn xrisimopoioun ton destructor tis
//base klasis opote ama to kaneis tha ta diagrapsei 2 fores kai tha fas SegFault error i DoubleFree.
//Episis, opws se volevei kane ti douleia sou profanws, apla prosexe ama einai na doulepseis prwta to paidi-class kai meta ton patera gia profaneis logous
