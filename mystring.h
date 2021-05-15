#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
using namespace std;

class mystring{
	private:
		char *data;
	public:
		mystring();
		~mystring();
		mystring & fix();
		char * getData();
		void print(const mystring &);
		mystring &operator=(char *);
		mystring &operator=(const mystring &);
		friend ostream &operator<<(ostream &,const mystring &);
		friend istream &operator>>(istream &,mystring &);
};

#endif //MYSTRING_H

//Apo edw kai pera ola ta files aforoun tin main. Xrisimopoieisai ta an thes gia na testareis ta dika s pragmata, apla tha proteina na min ta enswmatwseis stin ylopoihsh twn domwn
//giati pote den ksereis ti mporei na paei strava kai den xriazetai na ta periplekoume toso
