/*
�й�:
�̸�:
github id:
����: headnode�� �ִ� circular doubly linked list�� polynomial�� �����Ѵ�.
- headnode�� exp = -1�� �����Ѵ�.
- available list�� �����ϸ� list ��ȯ�� ��뿡 getNode, retNode�� ����Ѵ�.
- template version���� ������ �Ѵ�.
*/
#include "polynomialchain.h"
using namespace std;



int main(void) {
	char select;
	Term<int>* tempTerm;
	ChainNode<Term<int>> cn;
	Chain<Term<int>> f, g, h, k;
	ChainIterator<Term<int>> iter;
	int c, e;

	cout << endl << "Select command: a: Add_f, b: Add_g, c: Add_h, p: h + f * g, d: DisplayAll, e: Eval, q: exit" << endl;
	cin >> select;
	while (select != 'q')
	{
		switch (select)
		{
		case 'a':
			cout << "Add a new polynomial: " << endl;
			cin >> f;
			break;
		case 'b':
			cout << "Add a new polynomial: " << endl;
			cin >> g;
			break;
		case 'c':
			cout << "Add a new polynomial: " << endl;
			cin >> h;
			break;
		case 'p': //a+b
			cout << "h = f + g: ";
			{Chain<Term<int>> t;
			t = f * g;
			h = t + h;
			}
			//cout << sum;
			break;
		case 'd':
			cout << "display all: " << endl;
			cout<< f;
			cout << g;
			cout << h;
			break;
		case 'e':
			cout << "evaluete: " << endl;
			resultf = f.evaluate(coef, exp);//iterator ���
			resultg = g.evaluate(coef, exp);
			resulth = h.evaluate(coef, exp);
			break;
		default:
			cout << "WRONG INPUT  " << endl;
			cout << "Re-Enter" << endl;
		}
		cout << endl << "Select command: a: Add_f, b: Add_g, c: Add_h, p: h + f * g, d: DisplayAll, e: Eval, q: exit" << endl;
		cin >> select;
	}
	system("pause");
	return 0;
}
