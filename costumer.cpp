#include "customer.h"
customer::customer(string x)
{
	mechanicid = x;
}

void customer::setMid(string id1)
{
	mechanicid = id1;
}
string customer::getMid()
{
	return mechanicid;
}

void customer::sethours(int x)
{
	if (x > 24 || x < 0)
		cout << "incorrect value/n";
	else
	 appointment.hours = x;
}

int customer::gethours()
{
	return appointment.hours;
}

void customer::setmins(int y)
{
	if (y > 60 || y < 0)
		cout << "incorrect value/n";
	else
		appointment.mins = y;
}

int customer::getmins()
{
	return appointment.mins;
}
bool customer::operator<(customer& x) {
	if (this->appointment.hours < x.appointment.hours)
		return true;
	else
		if (this->appointment.mins < x.appointment.mins)
			return true;
		else return false;

}

bool customer::operator>(customer& x)
{
		if (this->appointment.hours > x.appointment.hours)
			return true;
		else
			if (this->appointment.hours == x.appointment.hours) {
				if (this->appointment.mins > x.appointment.mins)
					return true;
			}
				else return false;
}
bool customer::operator==(customer& x) 
{	
	if (this->appointment.hours == x.appointment.hours && this->appointment.mins == x.appointment.mins)
		return true;
	else
		return false;
	
}
