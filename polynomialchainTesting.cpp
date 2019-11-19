/*
�й�: 201524561
�̸�: �弮ȯ
github id: jsh5879
����: headnode�� �ִ� circular doubly linked list�� polynomial�� �����Ѵ�.
- headnode�� exp = -1�� �����Ѵ�.
- available list�� �����ϸ� list ��ȯ�� ��뿡 getNode, retNode�� ����Ѵ�.
- template version���� ������ �Ѵ�.
*/
#include "polynomialchain.h"
using namespace std;

int main(void) {
	char select = '0';
	Polynomial<int> f, g, h, t;
	int x, resultf, resultg, resulth, resultt;

	do
	{
		cout << endl << "Select command: a: Add_f, b: Add_g, c: Add_h, d:Delete All, e: Evaluate, p: Print All, t: h + f * g, v: Display av list, q: exit" << endl;
		cin >> select;

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
		case 't':
			t = h + f * g;
			cout << "h + f * g = " << t;
			break;
		case 'd':
		{
			cout << "Delete All chains" << endl;
			f.Delete();
			g.Delete();
			h.Delete();
			t.Delete();
			break;
		}
		case 'e':
			cout << "enter evaluete val = " << endl;
			cin >> x;
			resultf = f.Evaluate(x);//iterator ���
			resultg = g.Evaluate(x);
			resulth = h.Evaluate(x);
			cout << "f(" << x << ") = " << resultf << endl;
			cout << "g(" << x << ") = " << resultg << endl;
			cout << "h(" << x << ") = " << resulth << endl;
			break;
		case 'p':
		{
			cout << "display all: " << endl;
			cout << f;
			cout << g;
			cout << h;
			break;
		}
		case 'v':
			cout << "av list : ";
			//f.Displayav();
			break;
		default:
			cout << "WRONG INPUT  " << endl;
			cout << "Re-Enter" << endl;
		}
	} while (select != 'q');
	system("pause");
	return 0;
}