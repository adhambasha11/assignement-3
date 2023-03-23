
#include "person.h"

class customer :public person {
	private:
		string mechanicid;
		struct appointment appointment;
	public:
		customer(string = "");
		void setMid(string id1);
		string getMid();
		void sethours(int x);
		int gethours();
		void setmins(int y);
		int getmins();
		bool operator<(customer& x);
		bool operator>(customer& x);
		bool operator==(customer& x);
};

