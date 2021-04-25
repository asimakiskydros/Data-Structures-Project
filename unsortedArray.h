#ifndef unsortedArray_h
#define unsortedArray_h


class unsortedArray
{
  protected:
  // parallel arrays
  char **words;//array that stores the unique words dynamically
  int *sum;//array that stores the number of times each unique has appeared
  char **tempWords;//helps me grow the size of the words array
  int *tempSum;//helps me grow the size of the sum array
  
  int indx;//index of the found word, after performing searching.
  
  int last_word;//holds the index of the last word in the array
  int i;//helps me with loops

  bool wordExists(char *);//Looks for the word with linear search, returns true or false depending on if the word is found or not.

  bool firstWord;// I need this to control the value of last_word, basically if I dont use this, last_word's value might increase without getting a new word.

  public:
  unsortedArray();//initializes array ptr to null
  ~unsortedArray();//destroys the array
  virtual void insert(char *);//Inserts the unique words in the array, if the given word already exists, nothing is inserted and only the sum array is updated
  virtual void search(char *);//Looks for the word with linear search, shows the times the word has appeared(if it exists) plus the searching time
  virtual bool delete_word(char *);//Deletes a specific word in the array and returns true, if the word isn't found returns false


  
};
#endif



//tha valo parapano comments, apla niotho oti den ine sosta akoma...

//efxome to char **words na ine sosto....

//to anevazo tora stis 11:50 alla tha to ksananevaso simera pali updated 

//ASIMAKI SAMA an lipi kati lend me some of your precious knowledge ukno what im sayin

//den vrika poli xrono na doulepso aftes tis meres coz my aunt broke her leg (sad life..) 
//kai tha prospathiso na kano kai ego speedrun

//LOGIKA EXO LATHI.... AN DIS KATI TRAGIKO PES MOU APEFTHIAS. TY. GOODNIGHT AN TO VLEPIS TORA XD
