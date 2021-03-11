/*
 * Ellipse.h
 *
 *  Created on: 13 de set de 2017
 *      Author: anderson
 */
#include <iostream>
using namespace std;

#ifndef ELLIPSE_H_
#define ELLIPSE_H_

class Ellipse : public Shape {
  public:
    void draw() {
      cout << "ellipse " << id_ << ": draw" << endl;
    }
};


#endif /* ELLIPSE_H_ */
