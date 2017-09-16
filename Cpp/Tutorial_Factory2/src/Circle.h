/*
 * Circle.h
 *
 *  Created on: 13 de set de 2017
 *      Author: anderson
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <iostream>
using namespace std;



class Circle : public Shape {
  public:
	~Circle(){}
    void draw() {
      cout << "circle " << id_ << ": draw" << endl;
    }
};


#endif /* CIRCLE_H_ */
