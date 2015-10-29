#include <iostream>
#include <sstream> 
#include <string> 
using namespace std;

string stringify(int number)
{    
    ostringstream ostr; 
    ostr << number; 
    string theNumberString = ostr.str(); 
    return theNumberString;
}

class Vehicle
{
    
    public:
	virtual const string getDesc() =0;
	//virtual const string &getLicense()=0;
	//virtual const int getYear()=0;
};


class Car : public Vehicle 
{
	string license;
	int year;
	string style;
    public:
	Car( const string & myLicense , const int myYear , const string & myStyle )
        	: license(myLicense) , year(myYear) , style ( myStyle ) {}
    const string getDesc () 
 		{ return stringify ( year )  + " "+ style + ": " + license ;}
 	const string &getLicense() const {return license;}
 	const int getYear() const {return year;}
 	const string & getStyle () { return style ;}
};


class Truck : public Vehicle 
{
	string license;
	int year;
	string model;
    public:
	Truck( const string & myLicense , const int myYear , const string & myModel )
		: license(myLicense) , year(myYear) , model ( myModel ) {}
	const string getDesc () 
		{ return stringify ( year ) + " "+ model + ": " + license ;}
 	const string &getLicense() const {return license;}
 	const int getYear() const {return year;}
	const string & getModel () { return model ;}
};

int main()
{
	Car c("TH3456", 2003, "VANITY");
	Vehicle *vc = &c;
	cout<<vc->getDesc()<<"\n";
	Truck t("GH7890", 1987, "VALTRA");
	Vehicle *vt = &t;
	cout<<vt->getDesc()<<"\n";
}
