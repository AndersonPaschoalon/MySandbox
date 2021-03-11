/*
 * CircleShape.h
 *
 *  Created on: 27/08/2015
 *      Author: anderson
 */

#ifndef CIRCLESHAPE_H_
#define CIRCLESHAPE_H_

#include "DrawingAPI.h"
#include "Shape.h"

class CircleShape: public Shape {
	public:
		CircleShape(double x, double y, double radius, DrawingAPI *drawingAPI);
		virtual ~CircleShape();
		void draw();
		void resizeByPercentace(double percentage);

	private:
		double m_x, m_y, m_radius;
		DrawingAPI *m_drawingAPI;
};

#endif /* CIRCLESHAPE_H_ */
