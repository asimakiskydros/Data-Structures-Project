#ifndef unsortedArray_h
#define unsortedArray_h


class unsortedArray
{
  protected:
  //PARALLEL ARRAYS
  char **words;//array that stores the unique words dynamically
  int *sum;//array that stores the number of times each unique has appeared
  char **tempWords;//helps me increase the size of the words array
  int *tempSum;//helps me increase the size of the sum array
  
  int *length;//holds the length of each unique word, I need this in order to increase the size of the words array and for possible sorting in the future
  int *tempLength;//helps me increase the size of the length array
  
  int indx;//index of the found word after performing linear searching.
  
  int arr_size; //holds the size of the array and grows it by 5 whenever needed
  int last_word;//holds the index of the last word in the array
  int i;//helps me with loops

  virtual bool wordExists(char *);//Looks for the word with linear search, returns true or false depending on if the word is found or not.

  bool firstWord;//I need this to control the value of last_word, basically if I dont use this, last_word's value might increase without getting a new word.
 

  public:
  unsortedArray();//initializes the pointers to null and some helpful variables to 0
  ~unsortedArray();//destroys the array
  virtual void insert(char *);//Inserts the unique words in the array, if the given word already exists, nothing is inserted and only the sum array is updated
  void search(char *);//Looks for the word with linear search, shows the times the word has appeared(if it exists) plus the searching time
  virtual bool delete_word(char *);//Deletes a specific word in the array and returns true, if the word isn't found returns false


  
};
#endif




//O destructor pistevis oti einai sostos tora? Diavasa to comment sou kai elpizo na katalava afto pou ennois ;-;    //asimakis:swsto fainetai, an kai pali fas segfault pes na to doume
//ekana update to insert, isos ine ligo kalitero tora me vasi afta pou mou protines, ty bro. ise 5head

//an dis kati pou den sou aresi, afise sxolio xD
