#include "person.h"
person::person(string x,string y,int z) {
	name = x;
	id = y;
	age = z;
}
void person:: setname(string name1) {
	name = name1;
}
string person::getname() {
	return name;
}
void person::setid(string id1) {
	id = id1;
}
string person::getid() {
	return id;
}
void person::setage(string age1) {
	age = age1;
}
string person::getage() {
	return age;
}

void person::print()
{
	cout << " The person's name is " << getname() << ", his id is " << getid() << " and he is " << getage() << " years old.\n";
}


