/*
 * DrawingAPI.h
 *
 *  Created on: 27/08/2015
 *      Author: anderson
 */

#ifndef DRAWINGAPI_H_
#define DRAWINGAPI_H_

#include <iostream>
#include <string>
using namespace std;

class DrawingAPI {
	public:
		DrawingAPI();
		virtual ~DrawingAPI();
		virtual void drawCircle(double x, double y, double radius) = 0;
};

#endif /* DRAWINGAPI_H_ */
