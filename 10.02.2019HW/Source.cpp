#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<locale.h>

using namespace std;


void InvertDigits(int &K)
{
	int A = K, count = 0;
	int z = 10, e = 1;

	do
	{
		A = A / 10;
		count++;

	} while (A != 0);

	A = 0;

	int x = pow(10, count -1 );

	for (size_t i = 0; i < count; i++)
	{
		A = A + ((K % z)/e)*x;
		z = z * 10;
		x = x / 10;
		e = e * 10;
	}

	K = A;
}

void AddRightDigit(int D1, int D2, int &K)
{
	int count = 0, A, pow1 = 0, pow2 = 0, pow1a = 1,pow2a = 1;

	A = D1;
	do
	{
		A = A / 10;
		pow1++;

	} while (A != 0);

	for (size_t i = 0; i < pow1; i++)
	{
		pow1a = pow1a * 10;
	}

	K = K * pow1a;

	K = K + D1;
	
	cout << K << endl;

	A = D2;
	do
	{
		A = A / 10;
		pow2++;

	} while (A != 0);

	for (size_t i = 0; i < pow2; i++)
	{
		pow2a = pow2a * 10;
	}

	K = K * pow2a;

	K = K + D2;

}

void AddLeftDigit(int D1, int D2, int &K)
{
	int  pow1 = 0, B = K, powK = 0;
	int powKa = 1, pow1a = 1;

	do
	{
		B = B / 10;
		powK++;

	} while (B != 0);



	for (size_t i = 0; i < powK; i++)
	{
		powKa = powKa * 10;
	}



	K = float(((float)K / (float)powKa) + D1)*powKa;

	cout << K << endl;
	powKa = 1, powK = 0, B = K;


	do
	{
		B = B / 10;
		powK++;

	} while (B != 0);


	for (size_t i = 0; i < powK; i++)
	{
		powKa = powKa * 10;
	}


	K = float(((float)K / (float)powKa) + D2)*powKa;
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "");

	int flag = 0, task;

	do
	{
		cout << "Номер задачи:";
		cin >> task;

		switch (task)
		{
		case 1:
			int K;
			cin >> K;
			InvertDigits(K);
			cout << K;
		case 2:
			int D1, D2, P;
			cin >> D1 >> D2 >> P;
			AddRightDigit(D1, D2, P);
			cout << P << endl;
		case 3:
			int A1, A2, O;
			cin >> A1 >> A2 >> O;
			AddLeftDigit(A1, A2 , O);
			cout << O << endl;
		}

		cout << "Продолжить?1/0";
		cin >> flag;

	} while (flag == 1);
}