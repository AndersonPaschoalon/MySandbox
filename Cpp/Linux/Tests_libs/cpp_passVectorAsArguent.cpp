#include <iostream>
#include <vector>
#include <array>


using std::vector;
using std::cout;
using std::cin;
using std::endl;



class testClass{
public:
	testClass(){
		a = 0;
		b = 0;
		c = 0;
	}
	testClass(const testClass &rhs){
		a = rhs.a;
		b = rhs.b;
		c = rhs.c;
	}
	const testClass& operator= (const testClass &rhs)
	{
		if(&rhs != this)
		{
		a = rhs.a;
		b = rhs.b;
		c = rhs.c;
		}
		else{
			cout << "attempt of self assignment" << endl;
		}

		return(*this);
	}


	void print_obj(void){
		cout << "a:" << a << " b:" << b << " c:" << c << endl;
		return;
	}

	int a;
	int b;
	float c;

private:
};

class anotherTest{

public:
	vector<testClass> v;


	anotherTest(vector<testClass>&  inputV){
		v = inputV;
	}

	void setV( vector<testClass>&  inputV )
	{
		v = inputV;
	}

	void print()
	{
		for(int i = 0; i < v.size(); i++)
		{
			v[i].print_obj();
		}

	}
private:
};


vector<testClass> ret_test(int val)
{
	
	vector<testClass> v(val);

	if (val == 1)
	{
		testClass t1;
		t1.a = 1;
		v[0] = t1;

	}
	else if (val == 2)
	{

		testClass t1;
		t1.a = 1;
		testClass t2;
		t2.b = 2;
		v[0] = t1;
		v[1] = t2; 


	}
	else if( val == 3)
	{
		testClass t1;
		t1.a = 1;
		testClass t2;
		t2.b = 2;
		testClass t3;
		t3.c = 3.0;
		vector<testClass> v(3);
		v[0] = t1;
		v[1] = t2; 
		v[2] = t3;

	}
	else {
		testClass t1;
		t1.a = 4;
		testClass t2;
		t2.b = 4;
		testClass t3;
		t3.c = 5.5;
		v[0] = t1;
		v[1] = t2; 
		v[2] = t3;
	}


	return(v);

}


int main()
{
	vector<testClass> va = ret_test(1);
	vector<testClass> vb = ret_test(4);

	cout << endl << "va[]" << endl;
	va[0].print_obj();
	cout << endl << "vb[]" << endl;
	vb[0].print_obj();
	vb[1].print_obj();
	vb[2].print_obj();
	vb[3].print_obj();

	cout << "va.size() = " << va.size() << endl;
	cout << "vb.size() = " << vb.size() << endl;


	anotherTest pp = anotherTest(va);
	anotherTest qq = anotherTest(vb);

	cout << endl;
	cout << "pp: \n";
	pp.print();
	cout << "qq: \n";
	qq.print();



	pp = anotherTest(vb);
	qq = anotherTest(va);

	cout << endl;
	cout << "pp: \n";
	pp.print();
	cout << "qq: \n";
	qq.print();

	cout << endl;

	vector<testClass> m;

	m = va;

	va[0].a = 666; 
	va[0].b = 666;
	va[0].c = 666;

	cout << "va = ";
	va[0].print_obj();
	cout << "m = ";
	m[0].print_obj();



}