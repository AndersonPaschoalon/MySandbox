/*
 * Square.h
 *
 *  Created on: 13 de set de 2017
 *      Author: anderson
 */

#ifndef SQUARE_H_
#define SQUARE_H_

#include <iostream>
using namespace std;

class Square : public Shape {
  public:
    void draw() {
      cout << "square " << id_ << ": draw" << endl;
    }
};

#endif /* SQUARE_H_ */
