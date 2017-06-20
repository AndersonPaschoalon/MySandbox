/*
 * CompositeGraphic.h
 *
 *  Created on: 27/08/2015
 *      Author: anderson
 */

#ifndef COMPOSITEGRAPHIC_H_
#define COMPOSITEGRAPHIC_H_

#include "Graphic.h"

class CompositeGraphic: public Graphic {
	public:
		CompositeGraphic();
		virtual ~CompositeGraphic();
		void print() const;
		void add(Graphic* aGraphic);

	private:
		vector<Graphic*> graphicList_;
};

#endif /* COMPOSITEGRAPHIC_H_ */
