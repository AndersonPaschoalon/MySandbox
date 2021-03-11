//============================================================================
// Name        : Tutorial_StochasticFunctions.cpp
// Author      : Anderson Paschoalon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// weibull_distribution
#include <iostream>
#include <math.h>
#include <random>
#include <chrono>

#include <cmath>
#include <cfloat>
#include <armadillo>
#include <string>
#include <string.h>
#include <math.h>
#include <random>
#include <chrono>

const int nrolls = 1000; // number of experiments
const int nstars = 500; // maximum number of stars to distribute
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator(seed);
///std::ranlux24 generator(seed);

//std::knuth_b generator(seed);
//std::ranlux48 generator(seed);

void print_seed();
void print_weibull();
void print_exponential();
void print_normal();
void print_cauchy();
void print_pareto();

int main() {
	print_seed();
	print_weibull();
	print_exponential();
	print_normal();
	print_cauchy();
	print_pareto();

	return 0;
}

void print_weibull() {

	std::weibull_distribution<double> distribution(2.0, 4.0);

	int p[10] = { };

	for (int i = 0; i < nrolls; ++i) {
		double number = distribution(generator);
		if (number < 10)
			++p[int(number)];
	}

	std::cout << "weibull_distribution (2.0,4.0):" << std::endl;

	for (int i = 0; i < 10; ++i) {
		std::cout << i << "-" << (i + 1) << ": ";
		std::cout << std::string(p[i] * nstars / nrolls, '*') << std::endl;
	}

}

void print_seed() {
	std::cout << "seed sample:\n"
			<< std::chrono::system_clock::now().time_since_epoch().count()
			<< std::endl;
}

void print_exponential() {
	std::exponential_distribution<double> distribution(3.5);
	const int nintervals = 20; // number of intervals

	int p[nintervals] = { };

	for (int i = 0; i < nrolls; ++i) {
		double number = distribution(generator);
		if (number < 1.0)
			++p[int(nintervals * number)];
	}

	std::cout << "exponential_distribution (3.5):" << std::endl;
	std::cout << std::fixed;
	std::cout.precision(1);

	for (int i = 0; i < nintervals; ++i) {
		std::cout << float(i) / nintervals << "-" << float(i + 1) / nintervals
				<< ": ";
		std::cout << std::string(p[i] * nstars / nrolls, '*') << std::endl;
	}
}
void print_normal() {
	std::normal_distribution<double> distribution(5.0, 2.0);

	int p[10] = { };

	for (int i = 0; i < nrolls; ++i) {
		double number = distribution(generator);
		if ((number >= 0.0) && (number < 10.0))
			++p[int(number)];
	}

	std::cout << "normal_distribution (5.0,2.0):" << std::endl;

	for (int i = 0; i < 10; ++i) {
		std::cout << i << "-" << (i + 1) << ": ";
		std::cout << std::string(p[i] * nstars / nrolls, '*') << std::endl;
	}
}
void print_cauchy() {
	std::cauchy_distribution<double> distribution(5.0, 1.0);

	int p[10] = { };

	for (int i = 0; i < nrolls; ++i) {
		double number = distribution(generator);
		if ((number >= 0.0) && (number < 10.0))
			++p[int(number)];
	}

	std::cout << "cauchy_distribution (5.0,1.0):" << std::endl;

	for (int i = 0; i < 10; ++i) {
		std::cout << i << "-" << (i + 1) << ": ";
		std::cout << std::string(p[i] * nstars / nrolls, '*') << std::endl;
	}
}
void print_pareto() {
	//não tenho ctz que esta é a conversao correta...
	// https://en.wikipedia.org/wiki/Pareto_distribution
	// params: 0.1 3.5
	std::exponential_distribution<double> distribution(0.6);
	const int nintervals = 20; // number of intervals

	int p[nintervals] = { };

	for (int i = 0; i < nrolls; ++i) {
		double number = 0.1 * exp(distribution(generator));
		if (number < 1.0)
			++p[int(nintervals * number)];
	}

	std::cout << "pareto_distribution (0.1, 3.5):" << std::endl;
	std::cout << std::fixed;
	std::cout.precision(1);

	for (int i = 0; i < nintervals; ++i) {
		std::cout << float(i) / nintervals << "-" << float(i + 1) / nintervals
				<< ": ";
		std::cout << std::string(p[i] * nstars / nrolls, '*') << std::endl;
	}

}
