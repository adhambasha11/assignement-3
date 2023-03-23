#include "mechanic.h"

mechanic::mechanic()
{
	counter = 0;
}

void mechanic::setcounter(int x)
{
	counter = x;
}

int mechanic::getcounter()
{
	return counter;
}

void mechanic::sethours(int x, int i)
{
	Mappointment[i].hours = x;
}

int mechanic::gethours(int i)
{
	return Mappointment[i].hours;
}

void mechanic::setmins(int x, int i)
{
	Mappointment[i].mins = x;
}

int mechanic::getmins(int i)
{
	return Mappointment[i].mins;
}

bool mechanic::isAvailable(int x, int y,int size)
{
	for (int j = 0; j < size; j++)
	{
		if (Mappointment[j].hours != x)
			return true;
		else if (Mappointment[j].hours == x && Mappointment[j].mins != y)
			return true;
		else
			return false;
	}

}





