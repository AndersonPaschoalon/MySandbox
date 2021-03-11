//============================================================================
// Name        : Tests_StochasticFit.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <armadillo>
#include <string>
#include <vector>
#include <array>
#include <list>

using namespace std;
using namespace arma;

typedef enum stochastic_functions_enum {
	WEIBULL,                      //!< WEIBULL
	NORMAL,                       //!< NORMAL
	EXPONENTIAL,                  //!< EXPONENTIAL
	EXPONENTIAL_MEAN,             //!< EXPONENTIAL_MEAN
	EXPONENTIAL_LINEAR_REGRESSION,            //!< EXPONENTIAL_LINEAR_REGRESSION
	PARETO,                       //!< PARETO
	PARETO_LINEAR_REGRESSION,     //!< PARETO_LINEAR_REGRESSION
	PARETO_MAXIMUM_LIKEHOOD,      //!< PARETO_MAXIMUM_LIKEHOOD
	CAUCHY,                       //!< CAUCHY
	CONSTANT,                     //!< CONSTANT
	SINGLE_PACKET,                //!< SINGLE_PACKET
	NO_MODEL                      //!< NO_MODEL
} stochastic_functions;

typedef enum information_criterion_enum {
	AIC, BIC
} information_criterion;

class StochasticModelFit {
public:

	StochasticModelFit() {
		m_modelName = NO_MODEL;
		m_param1 = 0;
		m_param2 = 0;
		m_aic = datum::nan;
		m_bic = datum::nan;
	}

	double aic() const {
		return (m_aic);
	}
	double bic() const {
		return (m_bic);
	}
	string strModelName() const {
		string strRet;

		if (m_modelName == WEIBULL)
			strRet = "weibull";
		if (m_modelName == NORMAL)
			strRet = "normal";
		if (m_modelName == EXPONENTIAL)
			strRet = "exponentiaL";
		if (m_modelName == EXPONENTIAL_LINEAR_REGRESSION)
			strRet = "exponential-lr";
		if (m_modelName == EXPONENTIAL_MEAN)
			strRet = "exponential-me";
		if (m_modelName == PARETO)
			strRet = "pareto";
		if (m_modelName == PARETO_LINEAR_REGRESSION)
			strRet = "pareto-lt";
		if (m_modelName == PARETO_MAXIMUM_LIKEHOOD)
			strRet = "pareto-ml";
		if (m_modelName == CAUCHY)
			strRet = "cauchy";
		if (m_modelName == CONSTANT)
			strRet = "constant";
		if (m_modelName == SINGLE_PACKET)
			strRet = "single-packet";
		if (m_modelName == NO_MODEL)
			strRet = "no-model-selected";

		return (strRet);
	}
	stochastic_functions modelName() const {
		return (m_modelName);
	}

	double param1() const {
		return (m_param1);
	}

	double param2() const {
		return (m_param2);
	}

	void set(stochastic_functions sf, double param1, double param2, double aic,
			double bic) {
		m_modelName = sf;
		m_param1 = param1;
		m_param2 = param2;
		m_aic = aic;
		m_bic = bic;
	}

	void setInforCriterion(information_criterion infoCrit) {
		m_infoCrit = infoCrit;
	}

	bool operator <(const StochasticModelFit& smf) const {
		if (m_infoCrit == AIC) {
			return (m_aic < smf.aic());
		} else {
			return (m_bic < smf.bic());
		}
	}

	bool operator >(const StochasticModelFit& smf) const {
		if (m_infoCrit == AIC) {
			return (m_aic > smf.aic());
		} else {
			return (m_bic > smf.bic());
		}
	}

	StochasticModelFit(const StochasticModelFit& other) {
		m_modelName = other.modelName();
		m_param1 = other.param1();
		m_param2 = other.param2();
		m_aic = other.aic();
		m_bic = other.bic();
	}
	StochasticModelFit& operator=(const StochasticModelFit& other) noexcept
	{
		if (this != &other) {
			m_modelName = other.modelName();
			m_param1 = other.param1();
			m_param2 = other.param2();
			m_aic = other.aic();
			m_bic = other.bic();
		} else {
			cerr
					<< "Attempted assignment of a StochasticModelFit object to itself"
					<< endl;
		}

		return (*this);
	}

	void print() {
		cout << strModelName() << "(" << m_param1 << ", " << m_param1 << ") "
				<< "aic=" << m_aic << ", bic=" << m_bic << endl;
	}

private:
	double m_aic;
	double m_bic;
	stochastic_functions m_modelName = NO_MODEL;
	double m_param1;
	double m_param2;
	information_criterion m_infoCrit = AIC;
};

int main() {

	StochasticModelFit f = StochasticModelFit();
	StochasticModelFit g = StochasticModelFit();
	f.set(WEIBULL, 1, 2, -5, -5);
	g.set(PARETO, 1, 2, 4, 3);

	list<StochasticModelFit> k;
	StochasticModelFit s = StochasticModelFit();
	for(int i = 0; i < 5; i++)
	{
		s.set(WEIBULL, 1, 2, -i, -i);
		k.push_back(s);
	}

	k.sort();
	std::list<StochasticModelFit>::iterator it;
	for (it=k.begin(); it!=k.end(); ++it)
	{
		it->print();
	}





	cout << "(f < g):" << (f < g) << endl;
	cout << "(g < f):" << (g < f) << endl;

	return 0;
}
