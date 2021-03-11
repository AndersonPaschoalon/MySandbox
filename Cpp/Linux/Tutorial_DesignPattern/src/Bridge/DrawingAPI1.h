/*
 * DrawingAPI1.h
 *
 *  Created on: 27/08/2015
 *      Author: anderson
 */

#ifndef DRAWINGAPI1_H_
#define DRAWINGAPI1_H_

#include "DrawingAPI.h"

class DrawingAPI1: public DrawingAPI {
	public:
		DrawingAPI1();
		virtual ~DrawingAPI1();
		virtual void drawCircle(double x, double y, double radius);
};

#endif /* DRAWINGAPI1_H_ */
