
В самолете n рядов и по три кресла слева и справа в каждом ряду. Крайние кресла (A и F) находятся у окна, центральные (C и D) – у прохода. 
На регистрацию приходят группы из одного, двух или трех пассажиров. Они желают сидеть рядом, то есть на одном ряду и на одной стороне: 
левой или правой. Например, группа из двух пассажиров может сесть на кресла B и C, но не может сесть на кресла C и D, потому что они разделены проходом, 
а также не может сесть на кресла A и C, потому что тогда они окажутся не рядом. Кроме того, один из пассажиров каждой группы очень требовательный – 
он хочет сесть либо у окна, либо у прохода. Конечно же, каждая группа из пассажиров хочет занять места в ряду с как можно меньшим номером, 
ведь тогда они скорее выйдут из самолета после посадки. Для каждой группы пассажиров определите, есть ли места в самолете, подходящие для них.
#include <iostream>
using namespace std;
int main()
{   
    char k;
    bool flag = false;
    string side, position;
    int a,num;
	int n = 0;
    char** A = NULL;
	cin >> n;
    char B[] = "ABCDEF";
    A = new char* [n];
	for (int i = 0; i < n; i++) {
		A[i] = new char[7];
	}	
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {   
            cin >> k;
            A[i][j] = k;            
        }        
    }
    cin >> a;
    for (int i = 0; i < a; i++) {
        flag = false;
        cin >> num >> side >> position;

        if (position == "aisle" && side == "left") {
            for (int j = 0; j < n; j++) {
                for (int b = 2; b >= 2-num+1; b--) {
                    if (A[j][b] != '.') {
                        flag = false;
                        break;
                    }
                    else {
                        flag = true;                        
                    }
                }
                if (flag == true) {
                    cout << "Passengers can take seats:";
                    for (int b = 2-num+1; b <=2; b++) {
                        cout << " ";
                        cout << j+1 << B[b];
                        A[j][b] = 'X';
                    }
                    
                    cout << endl;
                    for (int i = 0; i < n; ++i)
                    {
                        for (int j = 0; j < 7; ++j)
                        {
                            cout << A[i][j];

                        }
                        cout << endl;
                    }
                    for (int b = 2; b >= 2 - num + 1; b--) {
                        A[j][b] = '#';
                    }
                    break;                    
                }
            }
            if (flag == false) {
                cout << "Cannot fulfill passengers requirements"<<endl;
            }

        }
        if (position == "aisle" && side == "right") {
            for (int j = 0; j < n; j++) {
                for (int b = 4; b <=3+num; b++) {
                    if (A[j][b] != '.') {
                        flag = false;
                        break;
                    }
                    else {
                        flag = true;
                    }
                }
                if (flag == true) {
                    cout << "Passengers can take seats:";
                    for (int b = 4; b <= 3+num; b++) {
                        cout << " ";
                        cout << j + 1 << B[b-1];
                        A[j][b] = 'X';
                    }
                    cout << endl;
                    for (int i = 0; i < n; ++i)
                    {
                        for (int j = 0; j < 7; ++j)
                        {
                            cout << A[i][j];

                        }
                        cout << endl;
                    }
                    for (int b = 4; b <= 3+num; b++) {
                        A[j][b] = '#';
                    }
                    break;
                }
            }
            if (flag == false) {
                cout << "Cannot fulfill passengers requirements"<<endl;
            }

        }
        if (position == "window" && side == "right") {
            for (int j = 0; j < n; j++) {
                for (int b = 6; b >= 7-num; b--) {
                    if (A[j][b] != '.') {
                        flag = false;
                        break;
                    }
                    else {
                        flag = true;
                    }
                }
                if (flag == true) {
                    cout << "Passengers can take seats:";
                    for (int b = 7-num; b <=6; b++) {
                        cout << " ";
                        cout << j + 1 << B[b-1];
                        A[j][b] = 'X';
                    }
                    cout << endl;
                    for (int i = 0; i < n; ++i)
                    {
                        for (int j = 0; j < 7; ++j)
                        {
                            cout << A[i][j];

                        }
                        cout << endl;
                    }
                    for (int b = 6; b >= 7 - num; b--) {
                        A[j][b] = '#';
                    }
                    break;
                }
            }
            if (flag == false) {
                cout << "Cannot fulfill passengers requirements"<<endl;                
            }
        }
        if (position == "window" && side == "left") {
            for (int j = 0; j < n; j++) {
                for (int b = 0; b <=num-1; b++) {
                    if (A[j][b] != '.') {
                        flag = false;
                        break;
                    }
                    else {
                        flag = true;
                    }
                }
                if (flag == true) {
                    cout << "Passengers can take seats:";
                    for (int b = 0; b <= num - 1; b++) {
                        cout << " ";
                        cout << j + 1 << B[b];
                        A[j][b] = 'X';
                    }
                    cout << endl;
                    for (int i = 0; i < n; ++i)
                    {
                        for (int j = 0; j < 7; ++j)
                        {
                            cout << A[i][j];
                        }
                        cout << endl;
                    }
                    for (int b = 0; b <= num - 1; b++) {
                        A[j][b] = '#';
                    }
                    break;
                }
            }
            if (flag == false) {
                cout << "Cannot fulfill passengers requirements"<<endl;
            }
        }
        
    }
    
}

