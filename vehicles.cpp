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
    protected:
	string license;
	int year;
    public:
	Vehicle(const string &myLicense , const int myYear)
		: license(myLicense) , year(myYear) {}
	virtual const string getDesc() const
		{return license + " from " + stringify( year );}
	const string &getLicense() const {return license;}
	const int getYear() const {return year;}
};


class Car : public Vehicle 
{
	string style;
    public:
	Car( const string & myLicense , const int myYear , const string & myStyle )
        	: Vehicle ( myLicense , myYear ), style ( myStyle ) {}
    const string getDesc () 
 		{ return stringify ( year )  + style + ": " + license ;}
	const string & getStyle () { return style ;}
};


class Truck : public Vehicle 
{
	string model;
    public:
	Truck( const string & myLicense , const int myYear , const string & myModel )
		: Vehicle ( myLicense , myYear ), model ( myModel ) {}
	const string getDesc () 
		{ return stringify ( year ) +  model + ": " + license ;}
	const string & getModel () { return model ;}
};

int main()
{
	Car c("TH3456", 2003, "VANITY");
	Vehicle *vPtr = &c;
	cout<<vPtr->getDesc()<<"\n";
	Truck t("GH7890", 1987, "VALTRA");
	Vehicle *vPt = &t;
	cout<<vPt->getDesc()<<"\n";
}
