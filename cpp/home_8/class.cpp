#include <iostream>
using namespace std;

template<typename type>
struct elem{
	type val;
	elem<type> *next;
	
	elem(elem<type> *n = nullptr) : next(n) {}
};

template<typename type>
class List{
	elem<type> *base, *current;
	
	void clear()
	{
		elem<type> *curr = base->next;
		while(curr != base)
		{
			elem<type> *nextElem = curr->next;
			delete curr;
			curr = nextElem;
		}
		delete base;
	}
	
	public:
	
	List()
	{
		base = new(nothrow) elem<type>();
		if (!base) {cout << "error memory" << endl; exit(1);}
		
		base->next = base;
		current = base;
	}
	
	~List() {clear();}
	
	bool AtBeg() {return current == base;}
	
	bool Insert(type val)
	{
		elem<type> *newElem = new(nothrow) elem<type>(current->next);
		if (!newElem) return 1;
		
		newElem->val = val;
		current->next = newElem;
		
		return 0;
	}
	
	bool Delete()
	{
		if (current->next == base)	return 1;
		
		elem<type> *del = current->next;
		current->next = del->next;
		
		delete del;
		return 0;
	}
	
	bool Get(type *val)
	{
		if (AtBeg()) return 1;
		
		*val = current->val;
		
		return 0;
	}
	
	bool Set(type val)
	{
		if (AtBeg()) return 1;
		
		current->val = val;
		
		return 0;
	}
	
	bool StepForward()
	{
		if (current->next == base) return 1;
		
		current = current->next;
		
		return 0;
	}
	
	void GotoBeg()	{current = base;}
	
	bool IsEmpty()	{return base->next == base;}
	
	void show()
	{
		if (IsEmpty()) {cout << "is empty" << endl; return;}
		
		elem<type> *curr = base->next;
		while(curr != base)
		{
			cout << curr->val;
			if (curr == current) cout << "<- current";
			cout << endl;
			
			curr = curr->next;
		}
		cout << endl << endl;
	}
};
