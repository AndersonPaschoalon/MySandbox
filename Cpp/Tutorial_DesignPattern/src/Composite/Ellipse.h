/*
 * Ellipse.h
 *
 *  Created on: 27/08/2015
 *      Author: anderson
 */

#ifndef ELLIPSE_H_
#define ELLIPSE_H_

#include "Graphic.h"

class Ellipse: public Graphic {
	public:
		Ellipse();
		virtual ~Ellipse();
		void print() const {
			cout << "Ellipse \n";
		}
};

#endif /* ELLIPSE_H_ */
