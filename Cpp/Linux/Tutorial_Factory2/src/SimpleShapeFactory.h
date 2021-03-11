/*
 * SimpleShapeFactory.h
 *
 *  Created on: 14 de set de 2017
 *      Author: anderson
 */

#ifndef SIMPLESHAPEFACTORY_H_
#define SIMPLESHAPEFACTORY_H_

#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "Factory.h"
using namespace std;


class SimpleShapeFactory : public Factory {
  public:
    Shape* createCurvedInstance() {
      return new Circle;
    }
    Shape* createStraightInstance() {
      return new Square;
    }
};

#endif /* SIMPLESHAPEFACTORY_H_ */
