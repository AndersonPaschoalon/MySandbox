/*
 * RobustShapeFactory.h
 *
 *  Created on: 14 de set de 2017
 *      Author: anderson
 */

#ifndef ROBUSTSHAPEFACTORY_H_
#define ROBUSTSHAPEFACTORY_H_

#include <iostream>
#include "Shape.h"
#include "Ellipse.h"
#include "Rectangle.h"
#include "Factory.h"
using namespace std;

class RobustShapeFactory : public Factory {
  public:
    Shape* createCurvedInstance()   {
      return new Ellipse;
    }
    Shape* createStraightInstance() {
      return new Rectangle;
    }
};

#endif /* ROBUSTSHAPEFACTORY_H_ */
