/*
 * Graphic.h
 *
 *  Created on: 27/08/2015
 *      Author: anderson
 */

#ifndef GRAPHIC_H_
#define GRAPHIC_H_

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <functional>
using namespace std;

class Graphic {
	public:
		Graphic();
		virtual ~Graphic();
		virtual void print() const = 0;
};

#endif /* GRAPHIC_H_ */
