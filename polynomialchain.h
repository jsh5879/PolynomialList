
using namespace std;
#include <iostream>
#include<string>
#include <assert.h>

template<class T> class Term {
public:
	//All members of Term are public by default
	T coef; //coefficient
	T exp; //exponent
	Term() { coef = 0; exp = 0; }
	Term(T c, T e) :coef(c), exp(e) {}
	Term Set(int c, int e) { coef = c; exp = e; return *this; };
};

template<class T> class CircularDoublyChain; //forward declaration
template<class T> class CircularDoublyChainIterator;


template<class T>
class DoublyChainNode {
	friend class CircularDoublyChain<T>;
	friend class CircularDoublyChainIterator<T>;
public:
	DoublyChainNode() {}
	DoublyChainNode(const T&);
private:
	T data;
	DoublyChainNode<T>* link;
};

template<class T> class CircularDoublyChain {
public:
	CircularDoublyChain() { first = 0; };
	void Delete(void); //delete the first element after first
	int Length();
	void Add(const T& element); //add a new node after first
	void Invert();
	void Concatenate(CircularDoublyChain<T> b);
	void InsertBack(const T& element);
	DoublyChainNode<T>* GetNode();
	void RetNode(DoublyChainNode<T>& x);
	//void Merge(CircularDoublyChain<T>& b);
	friend istream& operator>>(istream&, CircularDoublyChain&);
	friend ostream& operator<<(ostream&, CircularDoublyChain&);
	CircularDoublyChainIterator<T> begin() const { return CircularDoublyChainIterator<T>(first); }
	CircularDoublyChainIterator<T> end() const { return CircularDoublyChainIterator<T>(nullptr); }
private:	
	int n; //number of items
	static DoublyChainNode<T>* av;
	   DoublyChainNode<T>* first; //point to the last node
};

template<class T> class CircularDoublyChainIterator {
private:
	const CircularDoublyChain<T>* list; //refers to an existing list
	DoublyChainNode<T>* current; //points to a node in list
public:
	//CircularDoublyChainIterator<T>(const CircularDoublyChain<T> &l) :CircularDoublyChain(l), current(l.first) {};
	CircularDoublyChainIterator() {}
	CircularDoublyChainIterator(DoublyChainNode<T>* node) :current(node) {}
	//dereferencing operators
	T& operator *() const { return current->data; }
	T* operator->()const { return &current->data; }
	bool operator && (CircularDoublyChainIterator<T> iter)const {
		return current != NULL && iter.current != NULL;
	}
	bool isEmpty() const { return current == NULL; }
	//increment
	CircularDoublyChainIterator& operator ++(); //preincrement
	CircularDoublyChainIterator<T> operator ++(int); //post increment
	bool NotNull(); //check the current element in list is non-null
	bool NextNotNull(); //check the next element in list is non-null
	//T* First() { //return a pointer to the first element of list
	//	if (list->first) return &list->first->data;
	//	else return 0;
	//}
	T* Next();//return a pointer to the next element of list
};
/*
class Polynomial
*/
template<class T> class Polynomial {
public:
	Polynomial() {}
	Polynomial(CircularDoublyChain<Term<T> >* terms) :poly(terms) {}
	Polynomial<T> operator+(const Polynomial<T>& b) const;
	void add(T coef, T exponent);
	void addAll(Polynomial<T>* poly);
	void Delete();
//	void Displayav() { poly.displayav(); };
	T Evaluate(T&) const;//f(x)에 대하여 x에 대한 값을 구한다
	//polynomial<T> Multiply(Polynomial<T>&); //f(x) * g(x)
	Polynomial(const Polynomial& p); //copy constructor
	friend istream& operator>>(istream&, const Polynomial<T>&);//polynomial 입력
	friend ostream& operator<<(ostream&, const Polynomial<T>&);//polynomial 출력
	const Polynomial& operator=(const Polynomial&) const;
	~Polynomial();
	Polynomial operator-(const Polynomial&)const;
	Polynomial<T> operator+(Polynomial<T> b);
	Polynomial<T> operator*(Polynomial<T> b);


private:
	CircularDoublyChain<Term<T> > poly;
};

template <typename valType>
inline ostream& operator<< (ostream& os, const Polynomial<valType>& p) {
	CircularDoublyChainIterator<Term<valType>> iter = p.poly.begin();

	while (!iter.isEmpty())
	{
		os << iter->coef << "^" << iter->exp;
		iter++;
	}
	
	return os;
}


template <typename valType>
inline ostream& operator>> (istream& is, const Polynomial<valType>& p) {
	int n;
	cout << "항의갯수를 입력하세요 : ";
	is >> n;

	for (int i = 0; i < n; i++) {
		Term<T> temp;
		cout << "coef: ";
		is >> temp.coef;
		cout << "exp: ";
		is >> temp.exp;
		p.add(temp.coef, temp.exp);
	}
	
	return is;

}
template <class T>
DoublyChainNode<T>::DoublyChainNode(const T& element) {
	data = element;
	link = 0;
}

template <class T>
void CircularDoublyChain<T>::Delete(void) //delete the first element after first
{
	DoublyChainNode<T>* current, * next;
	next = first->link;
	if (first != nullptr) //non-empty list
	{
		DoublyChainNode<T>* temp = first;
		first = next;
		delete temp;
	}
	else cout << "Empty List: Not deleted" << endl;
}
template <class T>
void CircularDoublyChain<T>::Add(const T& element) //add a new node after first
{
	DoublyChainNode<T>* newnode = new DoublyChainNode<T>(element);
	if (!first) //insert into empty list
	{
		first = newnode;
		return;
	}
	//insert a new node after first
	newnode->link = first;
	first = newnode;
}
template <class T>
void CircularDoublyChain<T>::Invert() {
	DoublyChainNode<T>* p = first, * q = 0; //q trails p
	while (p) {
		DoublyChainNode<T>* r = q; q = p; //r trails q
		p = p->link; //p moves to next node
		q->link = r; //link q to preceding node
	}
	first = q;
}
template <class T>
void CircularDoublyChain<T>::Concatenate(CircularDoublyChain<T> b) {
	if (!first) { first = b.first; return; }
	if (b.first) {
		for (DoublyChainNode<T>* p = first; p->link; p = p->link) {
			p->link = b.first;
		}
	}
}
template <class T>
void CircularDoublyChain<T>::InsertBack(const T& element) {
	DoublyChainNode<T>* newnode = new DoublyChainNode<T>(element);
	if (!first) //insert into empty list
	{
		first = newnode;
		return;
	}
	DoublyChainNode<T>* curr = first;
	while (curr->link != NULL) {
		curr = curr->link;
	}
	curr->link = newnode;
}

template <class T>
DoublyChainNode<T>* CircularDoublyChain<T>::GetNode()
{ //provide a node for use
	DoublyChainNode<T>* x;
	if (av) { x = av, av = av->link; }
	else x = new DoublyChainNode<t>;
	return x;
}
template <class T>
void CircularDoublyChain<T>::RetNode(DoublyChainNode<T>& x)
{ //free the node pointed to by x
	x->link = av;
	av = x;
	x = 0;
}
/*
template <class T>
void Merge(CircularDoublyChain<T>& b)
{// a.Merge(b) produces list contains the merged result
 // coding한다.
}
*/
template <class T>
DoublyChainNode<T>* CircularDoublyChain<T>::av = 0;
//DoublyChainNode<T> CircularDoublyChain<T>::av = 0;//오류 발생
template <class T>
CircularDoublyChainIterator<T>& CircularDoublyChainIterator<T>::operator ++() //preincrement
{
	current = current->link;
	return *this;
}
template <class T>
CircularDoublyChainIterator<T> CircularDoublyChainIterator<T>::operator ++(int) //post increment
{
	CircularDoublyChainIterator<T> old = *this;
	current = current->link;
	return old;
}
template <class T>
bool CircularDoublyChainIterator<T>::NotNull() { //check the current element in list is non-null
	if (current) return 1;
	else return 0;
}
template <class T>
bool CircularDoublyChainIterator<T>::NextNotNull() { //check the next element in list is non-null
	if (current && current->link) return 1;
	else return 0;
}
template <class T>
T* CircularDoublyChainIterator<T>::Next() {//return a pointer to the next element of list
	if (current) {
		current = current->link;
		return &current->data;
	}
	else return 0;
}
template<class T>
void Polynomial<T>::add(T coef, T exponent) {
	Term<T>* newTerm = new Term<T>(coef, exponent);
	this->poly.Add(*newTerm);
}

template<class T> void Polynomial<T>::addAll(Polynomial<T>* b) {
	CircularDoublyChainIterator<Term<T>> iterB = b->poly.begin();

	while (iterB.NotNull()) {
		Term<T> dataB = *iterB;
		add(dataB.coef, dataB.exp);
		iterB.Next();
	}
}

template<class T>
inline T Polynomial<T>::Evaluate(T&) const
{
	return T();
}

template<class T>
inline Polynomial<T> Polynomial<T>::operator*(Polynomial<T> b)
{
	Term<T> temp;
	CircularDoublyChainIterator<Term<T>> ai = poly.begin(), bi = b.poly.begin();
	Polynomial<T> c;

	while (!ai.isEmpty())
	{
		while (!bi.isEmpty())
		{
			c.poly.InsertBack(temp.Set((ai->coef * bi->coef), (ai->exp + bi->exp)));
			bi++;
		}
		ai++;
	}

	while (ai && bi) {//current nodes are not null

		if (ai->exp == bi->exp) {
			int sum = ai->coef + bi->coef;
			if (sum) c.poly.InsertBack(temp.Set(sum, ai->exp));
			ai++, bi++; //advance to next term
		}
		else if (ai->exp < bi->exp) {
			c.poly.InsertBack(temp.Set(bi->coef, bi->exp));
			bi++;//next term of b
		}
	}

	while (!ai.isEmpty()) {//copy rest of a
		c.poly.InsertBack(temp.Set(ai->coef, ai->exp));
		ai++;
	}
	while (!bi.isEmpty()) {//copy rest of b
		c.poly.InsertBack(temp.Set(bi->coef, bi->exp));
		bi++;
	}
	return c;
}

/*
template<class T>
Polynomial<T> Polynomial<T>::operator+(const Polynomial<T>& b) const {
	Term<T> temp;
	CircularDoublyChainIterator<Term<T>> ai = poly.begin(), bi = b.poly.begin();
	Polynomial<T> c;

	while (ai && bi) {//current nodes are not null

		if (ai->exp == bi->exp) {
			int sum = ai->coef + bi->coef;
			if (sum) c.poly.InsertBack(temp.Set(sum, ai->exp));
			ai++, bi++; //advance to next term
		}
		else if (ai->exp < bi->exp) {
			c.poly.InsertBack(temp.Set(bi->coef, bi->exp));
			bi++;//next term of b
		}
	}

	while (!ai.isEmpty()) {//copy rest of a
		c.poly.InsertBack(temp.Set(ai->coef, ai->exp));
		ai++;
	}
	while (!bi.isEmpty()) {//copy rest of b
		c.poly.InsertBack(temp.Set(bi->coef, bi->exp));
		bi++;
	}
	return c;
}*/

template<class T>
Polynomial<T> Polynomial<T>::operator+(Polynomial<T> b)
{
	Term<T> temp;
	CircularDoublyChainIterator<Term<T>> ai = poly.begin(), bi = b.poly.begin();
	Polynomial<T> c;

	while (ai && bi) {//current nodes are not null

		if (ai->exp == bi->exp) {
			int sum = ai->coef + bi->coef;
			if (sum) c.poly.InsertBack(temp.Set(sum, ai->exp));
			ai++, bi++; //advance to next term
		}
		else if (ai->exp < bi->exp) {
			c.poly.InsertBack(temp.Set(bi->coef, bi->exp));
			bi++;//next term of b
		}
	}

	while (!ai.isEmpty()) {//copy rest of a
		c.poly.InsertBack(temp.Set(ai->coef, ai->exp));
		ai++;
	}
	while (!bi.isEmpty()) {//copy rest of b
		c.poly.InsertBack(temp.Set(bi->coef, bi->exp));
		bi++;
	}
	return c;
}
