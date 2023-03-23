#include "person.h"
#include "customer.h"
#include "mechanic.h"
#include <queue>
void setmechanic(mechanic*,int&);
void setcustomer(customer*, int&);
void assignmech(mechanic*, customer*, int&, int&);
void arrange(customer*,mechanic*,int&,int&,queue<customer>);
int main() {
	mechanic* m;
	customer* c;
	queue<customer> q;
	int x,y;
	string n, i,a;
	cout << "how many mechanics are available in the workshop? ";
	cin >> x;
	m = new mechanic[x];
	cout << "how many customers are visiting the workshop today? ";
	cin >> y;
	c = new customer[y];
	setmechanic(m, x);
	setcustomer(c, y);	
	assignmech(m, c, x, y);
	arrange(c, m,y,x,q);
	
	
	return 0;
}
void setmechanic(mechanic* m1, int& x) {
	string n, i, a;
	for (int j = 0; j < x; j++)
	{
		cout << " enter the name,id and age of " << j + 1 << " mechanic\n ";
		cout << "name:";
		cin >> n;
		cout << "id:";
		cin >> i;
		cout << "age:";
		cin >> a;
		m1[j].setname(n);
		m1[j].setage(a);
		m1[j].setid(i);

	}
}
void setcustomer(customer* c1, int& y) {
	string n, i, a;
		int h,m;
	for (int j = 0; j < y; j++)
	{
		cout << " enter the name,age and appointment time of " << j + 1 << " customer\n ";
		cout << "name:";
		cin >> n;
		cout << "age:";
		cin >> a;
		c1[j].setname(n);
		c1[j].setage(a);
		cout << "appointment time in 24 hrs: ";
		cin >> h; cout << ":"; cin >> m;
		c1[j].sethours(h);
		c1[j].setmins(m);
		
	}
}
void assignmech(mechanic* m, customer* c, int& x, int& y)
{
	for (int i = 0; i < y; i++) {
		
		if (i < x) {
			c[i].setid(m[i].getid());
			m[i].sethours(c[i].gethours(), i);
			m[i].setmins(c[i].getmins(), i);
			cout << c[i].getname() << " is assigned to " << m[i].getname() << " at " << c[i].gethours() <<":"<< c[i].getmins() << endl;
		}
		else {
			for (int j = 0; j < x; j++)
			{
				if (m[j].isAvailable(c[i].gethours(), c[i].getmins(), x) == true)
				{
					c[i].setid(m[j].getid());
					m[j].sethours(c[i].gethours(), i);
					m[j].setmins(c[i].getmins(), i);
					cout << c[i].getname() << " should be assigned to " << m[j].getname() << " at " << c[i].gethours() << ":" << c[i].getmins() << endl;
				}
			}
		} 

		
		

	}
}

void arrange(customer* c,mechanic* m,int& y,int&g,queue<customer> q) {
	for (int z = 0; z < y-1; z++) {
		customer x;
		for (int i = 0; i < y - 1; i++)
		{

			int j = 1;
			if (c[i].gethours() < c[j].gethours()) {
				x = c[i];
				c[i].sethours(24);
				c[i].setmins(60);
			}
			else {
				if (c[j].gethours() < c[i].gethours())
				{
					x = c[j];
					c[j].sethours(24);
					c[j].setmins(60);

				}
				else {
					if (c[i].getmins() < c[j].getmins()) {
						x = c[i];
						c[i].sethours(24);
						c[i].setmins(60);
					}

					else {
						if (c[j].getmins() < c[i].getmins())
						{
							x = c[j];
							c[j].sethours(24);
							c[j].setmins(60);
						}
						else
							x = c[i];
					}
				}
			}
			j++;


		}
		q.push(x);
		customer f = q.front();
		cout << f.getname() << " is assigned to "<<m[z%g].getname()<<" at "<<f.gethours()<<":"<<f.getmins();
		q.pop();
	}
	
}

