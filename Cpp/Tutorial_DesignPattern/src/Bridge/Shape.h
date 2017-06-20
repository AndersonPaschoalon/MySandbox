/*
 * Shape.h
 *
 *  Created on: 27/08/2015
 *      Author: anderson
 */

#ifndef SHAPE_H_
#define SHAPE_H_

class Shape {
	public:
		Shape();
		virtual ~Shape();
		virtual void draw() = 0;
		virtual void resizeByPercentace(double percentage) = 0;
};

#endif /* SHAPE_H_ */
