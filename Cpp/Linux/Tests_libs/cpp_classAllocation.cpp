#include <stdio.h>
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

class StochasticModelFit
{
public:
	StochasticModelFit()
	{
		aic = 0;
		bic = 0;
		modelName = "";
		param1 = 0;
		param2 = 0;
		size = 0;
	}

	void print(void)
	{
		cout << "Model Name:" << modelName << " param1:" << param1 << " param2:"
				<< param2 << endl;
		cout << "\tbic:" << bic << " aic:" << aic << " size:" << size << endl;
	}

	//AIC criterion value for the model
	double aic;

	//BIC criterion value for the model
	double bic;

	//String with a human-readable name of the current model
	string modelName;

	//first parameter (in alphabetical order) of the model
	double param1;

	//second parameter (in alphabetical order) of the model
	double param2;

	//Number of models setted by the method DataProcessor::fitModels()
	unsigned int size;

private:
};

StochasticModelFit* op1(int a)
{

	StochasticModelFit* vec = NULL;
	vec = new StochasticModelFit[5];


	if(a == 1)
	{
		vec[0].modelName = "zero";
		vec[0].aic = 1212.12;
		vec[1].bic = 13;
		vec[1].modelName = "1st"; 
		vec[2].modelName = "segundo";
		vec[3].modelName = "terceiro";
		vec[4].modelName = "quarto";
		vec[3].param1 = 44 ;
		vec[0].modelName = "zero";
		vec[3].modelName = "kkkkkkkkk";
	}
	else
	{
		vec = new StochasticModelFit[3];
	}



	return vec;
}



int main()
{
	StochasticModelFit* a;
	StochasticModelFit* b;

	b = op1(0);
	a = op1(1);

	a[0].print();
	a[1].print();
	a[2].print();
	a[3].print();
	a[4].print();

	b[0].print();
	b[1].print();
	b[2].print();

	delete[] a;
	delete[] b;

	return(0);
}






