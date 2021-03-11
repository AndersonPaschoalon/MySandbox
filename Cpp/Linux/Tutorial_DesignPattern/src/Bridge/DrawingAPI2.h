/*
 * DrawingAPI2.h
 *
 *  Created on: 27/08/2015
 *      Author: anderson
 */

#ifndef DRAWINGAPI2_H_
#define DRAWINGAPI2_H_

#include "DrawingAPI.h"

class DrawingAPI2: public DrawingAPI {
	public:
		DrawingAPI2();
		virtual ~DrawingAPI2();
		virtual void drawCircle(double x, double y, double radius);
};

#endif /* DRAWINGAPI2_H_ */
