/*
 * Shape.h
 *
 *  Created on: 13 de set de 2017
 *      Author: anderson
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include <iostream>

class Shape {
public:
	Shape() {
		id_ = total_++;
	}
	virtual ~Shape() {
	}
	virtual void draw() = 0;
protected:
	int id_;
	static int total_;
};

int Shape::total_ = 0;

#endif /* SHAPE_H_ */
