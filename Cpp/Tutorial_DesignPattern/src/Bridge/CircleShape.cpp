/*
 * CircleShape.cpp
 *
 *  Created on: 27/08/2015
 *      Author: anderson
 */

#include "CircleShape.h"


CircleShape::~CircleShape() {
	// TODO Auto-generated destructor stub
}

CircleShape::CircleShape(double x, double y, double radius,
		DrawingAPI* drawingAPI):
		m_x(x), m_y(y), m_radius(radius), m_drawingAPI(drawingAPI){
}

void CircleShape::draw() {
	m_drawingAPI->drawCircle(m_x, m_y, m_radius);
}

void CircleShape::resizeByPercentace(double percentage) {
	m_radius *= percentage;
}



