#include <iostream>
#include <vector>
#include <array>
#include <algorithm>    // std::sort
#include <string>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::sort;
using std::cerr;
using std::clog;







class StochasticModelFit
{
public:
	//Constructor
	StochasticModelFit()
	{
		aic = 0;
		bic = 0;
		modelName = "";
		param1 = 0;
		param2 = 0;
	}

	//copy constructor
	StochasticModelFit(const StochasticModelFit &rhs)
	{
		aic = rhs.aic;
		bic = rhs.bic;
		modelName = rhs.modelName;
		param1 = rhs.param1;
		param2 = rhs.param2;
	}

	//Destructor
	~StochasticModelFit()
	{
		//Nothing to do
	}

	string toString(void)
	{
		string strRepresentation = "Model Name: " + modelName + " param1:"
				+ std::to_string(param1) + " param2:" + std::to_string(param2)
				+ " bic:" + std::to_string(bic) + " aic:" + std::to_string(aic)
				+ " ";
		return (strRepresentation);
	}

	//copy operator
	const StochasticModelFit& operator=(const StochasticModelFit& rhs)
	{
		if (&rhs != this)
		{
			aic = rhs.aic;
			bic = rhs.bic;
			modelName = rhs.modelName;
			param1 = rhs.param1;
			param2 = rhs.param2;
		}
		else
		{
			cerr << "Error @  StochasticModelFit::operator=():"
					<< "Attempted assignment of a StochasticModelFit object to itself"
					<< endl;
			cerr << "Hint: StochasticModelFit = " << toString();
		}

		return (*this);
	}

	void print(void)
	{
		cout << "Model Name:" << modelName << " param1:" << param1 << " param2:"
				<< param2; // << endl;
		cout << "\tbic:" << bic << " aic:" << aic << endl;
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

private:
};



struct compareBic
{
    inline bool operator() (const StochasticModelFit& struct1, const StochasticModelFit& struct2)
    {
        return (struct1.bic < struct2.bic);
    }
};

struct compareAic
{
    inline bool operator() (const StochasticModelFit& struct1, const StochasticModelFit& struct2)
    {
        return (struct1.aic < struct2.aic);
    }
};

/*
int compareBic(const void* a, const void* b)
{

	if ((*(StochasticModelFit*) a).bic < (*(StochasticModelFit*) b).bic)
		return -1;
	if ((*(StochasticModelFit*) a).bic == (*(StochasticModelFit*) b).bic)
		return 0;
	if ((*(StochasticModelFit*) a).bic > (*(StochasticModelFit*) b).bic)
		return 1;

	return (0);
}

int compareAic(const void* a, const void* b)
{

	if ((*(StochasticModelFit*) a).aic < (*(StochasticModelFit*) b).aic)
		return -1;
	if ((*(StochasticModelFit*) a).aic == (*(StochasticModelFit*) b).aic)
		return 0;
	if ((*(StochasticModelFit*) a).aic > (*(StochasticModelFit*) b).aic)
		return 1;

	return (0);
}
*/


int main()
{
	vector<StochasticModelFit> v(4);

	v[0].bic = -1;
	v[2].bic = -30;
	v[1].bic = 8;
	v[3].bic = 177;

	  // using function as comp
	std::sort (v.begin(), v.end(), compareBic());



	for(int i = 0; i < v.size(); i++)
		v[i].print();



	return(0);
}
