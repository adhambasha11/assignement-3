#include <iostream>
#pragma once
using namespace std;
class person {
private:
	string name;
	string id;
	string age;
public:
	person(string="",string="",int=0);
	void setname(string name1);
	string getname();
    void setid(string id1);
	string getid();
	void setage(string age1);
	string getage();
	virtual void print();
	struct appointment {
		int hours;
		int mins;
	};
	
};



