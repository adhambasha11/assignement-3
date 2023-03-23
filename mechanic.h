#include "person.h"
class mechanic : public person {
private:
	int counter;
	struct appointment Mappointment[24];
public:
	mechanic();
	void setcounter(int x);
	int getcounter();
	void sethours(int x, int i=0);
	int gethours(int i);
	void setmins(int x, int i = 0);
	int getmins(int i);
	bool isAvailable(int x, int y, int size);

};
