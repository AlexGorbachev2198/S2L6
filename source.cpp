#include <iostream>
using namespace std;
class Complex
{
	double Actual, Imaginary;
public:
	Complex();
	Complex(double r);
	Complex(double r, double i);
	~Complex();
	double Get_Actual()
	{
		return Actual;
	}
	double Get_Imaginary()
	{
		return Imaginary;
	}
	Complex * Summ(Complex *first, Complex * second);
	Complex * Sub(Complex *first, Complex * second);
	Complex * Mult(Complex *first, int K);
	Complex * Div(Complex *first, int K);
	void Print();
	void mult_complex(Complex * first);
};
Complex::Complex()
{}
Complex::Complex(double a)
{
	Actual = a;
	Imaginary = 0;
}
Complex::Complex(double a, double i)
{
	Actual = a;
	Imaginary = i;
}
Complex * Complex::Summ(Complex *first, Complex * second)
{
	Complex * buff = new Complex(first->Get_Actual() + second->Get_Actual(), first->Get_Imaginary() + second->Get_Imaginary());
	return buff;
}
Complex * Complex::Sub(Complex *first, Complex * second)
{
	Complex * buff = new Complex(first->Get_Actual() - second->Get_Actual(), first->Get_Imaginary() - second->Get_Imaginary());
	return buff;
}
Complex * Complex::Mult(Complex *first, int K)
{
	Complex * buff = new Complex(first->Get_Actual() * K, first->Get_Imaginary() * K);
	return buff;
}
Complex * Complex::Div(Complex *first, int K)
{
	try {
		if (K == 0) throw true;
		Complex * buff = new Complex(first->Get_Actual() / K, first->Get_Imaginary() / K);
		return buff;
	}
	catch (bool i)
	{
		cout << "Error!" << endl;
	}
	return nullptr;
}

void Complex::mult_complex(Complex * first)
{
	double Actual1 = this->Actual*first->Get_Actual() - this->Imaginary*first->Get_Imaginary();
	double Imaginary1 = this->Actual*first->Get_Imaginary() + this->Imaginary*first->Get_Actual();
	this->Actual = Actual1;
	this->Imaginary = Imaginary1;
}
 
void Complex::Print()
{
	if (this->Get_Actual() == 0 && this->Get_Imaginary() == 0) cout << "There is no complex!" << endl;
	else if (this->Get_Actual() != 0 && this->Get_Imaginary() == 0) cout << Actual << endl;
	else if (this->Get_Actual() == 0 && this->Get_Imaginary() != 0) cout << Imaginary << "i" << endl;
	else if (this->Get_Imaginary() > 0)cout << this->Get_Actual() << " + " << Imaginary << "i" << endl;
	else if (this->Get_Imaginary() < 0) cout << this->Get_Actual() << " - " << -Imaginary << "i" << endl;
}
Complex::~Complex()
{
}
int main()
{
	double A1, I1, A2, I2;
	int K1, K2 =0;
	cout << "Actual 1" << endl;
	cin >> A1;
	cout << "Actual 2" << endl;
	cin >> A2;
	cout << "Imaginery 1" << endl;
	cin >> I1;
	cout << "Imaginery 2" << endl;
	cin >> I2;
	cout << "K" << endl;
	cin >> K1;
	Complex * C1 = new Complex(A1, I1);
	Complex * C2 = new Complex(A2, I2);
	Complex * buff = new Complex();
	C1->Print();
	C2->Print();
	C1->mult_complex(C2);
	C1->Print();
	buff = buff->Summ(C1, C2);
	buff->Print();
	buff = buff->Sub(C1, C2);
	buff->Print();
	buff = buff->Mult(C1, K1);
	buff->Print(); 
	buff = buff->Div(C1, K1);
	buff->Print();
	buff = buff->Div(C1, 0);
	system("pause");
	return 0;
}
