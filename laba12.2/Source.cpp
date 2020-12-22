#include <iostream>
using namespace std;
typedef int faq;
struct Emal
{
	Emal* link;
	 faq d;

};
void power(Emal*& p, faq i)
{
	Emal* tmp = new Emal;
	tmp->d = i;
	tmp->link = p;
	p = tmp;

}
faq pop(Emal*& p)
{
	Emal* tmp = p->link;
	faq value = p->d;
	delete p;
	p = tmp;
	return value;
}
void swap(Emal*& p)
{
	while (p != NULL && p->link != NULL)
	{
		if (p != NULL)
		{
			Emal* tmp = new Emal;
			faq val = p->link->d;
			tmp->d = val;
			tmp->link = new Emal;
			faq val1 = p->d;
			tmp->link->d = val1;

			tmp->link->link = p->link->link;
			p = tmp;

			return swap(p = p->link->link);
		}
		else
			return swap(p = p->link);
	}
}
void swap1(Emal*& p)
{
	while (p != NULL && p->link != NULL) {
		
		if (p->link->d==5)
		{
			Emal* tmp = new Emal; // 1
			tmp->d = 2; // 2
			tmp->link = p->link; // 3
			p->link = tmp;
			p = p->link;
		}
		p = p->link;
	}
	
}

int main()
{
	Emal* p= NULL;

	for (int i =2; i < 21; i++)
		power(p, i);

	 swap(p);
	while (p != NULL) 
	{
		cout << pop(p) << "  ";
	}

	return 0;
}