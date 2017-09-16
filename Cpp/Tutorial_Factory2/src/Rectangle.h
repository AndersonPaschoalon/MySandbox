/*
 * Rectangle.h
 *
 *  Created on: 14 de set de 2017
 *      Author: anderson
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include <iostream>
using namespace std;

class Rectangle : public Shape {
  public:
    void draw() {
      cout << "rectangle " << id_ << ": draw" << endl;
    }
};

#endif /* RECTANGLE_H_ */
