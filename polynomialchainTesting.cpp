/*
학번: 201524561
이름: 장석환
github id: jsh5879
문제: headnode가 있는 circular doubly linked list로 polynomial을 구성한다.
- headnode는 exp = -1로 정의한다.
- available list를 유지하며 list 반환과 사용에 getNode, retNode를 사용한다.
- template version으로 만들어야 한다.
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
			resultf = f.Evaluate(x);//iterator 사용
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