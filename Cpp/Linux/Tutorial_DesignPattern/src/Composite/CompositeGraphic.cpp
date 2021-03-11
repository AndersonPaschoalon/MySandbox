/*
 * CompositeGraphic.cpp
 *
 *  Created on: 27/08/2015
 *      Author: anderson
 */

#include "CompositeGraphic.h"

CompositeGraphic::CompositeGraphic() {
}

CompositeGraphic::~CompositeGraphic() {
}

void CompositeGraphic::print() const {
	//for each element in the graphicList_, call the print member function
	for_each(graphicList_.begin(), graphicList_.end(), mem_fun(&Graphic::print));
}

void CompositeGraphic::add(Graphic* aGraphic) {
	graphicList_.push_back(aGraphic);
}


