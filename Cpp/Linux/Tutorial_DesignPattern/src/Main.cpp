#include <iostream>
#include <string>

#include "Bridge/CircleShape.h"
#include "Bridge/DrawingAPI1.h"
#include "Bridge/DrawingAPI2.h"
#include "Builder/Cook.h"
#include "Builder/Pizza.h"
#include "Builder/PizzaBuilder.h"
#include "Builder/HawaiianPizzaBuilder.h"
#include "Builder/SpicyPizzaBuilder.h"
#include "Composite/CompositeGraphic.h"
#include "Composite/Ellipse.h"
#include "Decorator/CarDecorator.h"
#include "Prototype/RecordType.h"
#include "Prototype/Record.h"
#include "Prototype/RecordFactory.h"

using namespace std;

void bridge() {

	CircleShape circle1(1, 2, 3, new DrawingAPI1());
	CircleShape circle2(5, 7, 11, new DrawingAPI1());

	circle1.resizeByPercentace(2.5);
	circle2.resizeByPercentace(2.5);

	circle1.draw();
	circle2.draw();

}

void builder() {
	/*objects*/
	Cook oven;
	//builders
	PizzaBuilder* hawaiianCooker = new HawaiianPizzaBuilder;
	PizzaBuilder* spicyCooker = new SpicyPizzaBuilder;
	//pizzas vazias
	Pizza* hawaiian;
	Pizza* spicy;

	oven.setPizzaBuilder(hawaiianCooker);
	oven.constructPizza();
	hawaiian = oven.getPizza();

	oven.setPizzaBuilder(spicyCooker);
	oven.constructPizza();
	spicy = oven.getPizza();

	hawaiian->open();
	spicy->open();

	delete spicy;
	delete hawaiian;
	delete hawaiianCooker;
	delete spicyCooker;

}
void compositer() {
	//initializa four ellipses
	const auto_ptr<Ellipse> ellipse1(new Ellipse());
	const auto_ptr<Ellipse> ellipse2(new Ellipse());
	const auto_ptr<Ellipse> ellipse3(new Ellipse());
	const auto_ptr<Ellipse> ellipse4(new Ellipse());

	//initialize three composite graphics
	const auto_ptr<CompositeGraphic> graphic(new CompositeGraphic());
	const auto_ptr<CompositeGraphic> graphic1(new CompositeGraphic());
	const auto_ptr<CompositeGraphic> graphic2(new CompositeGraphic());

	//composes the graphics
	graphic->add(ellipse1.get());
	graphic->add(ellipse2.get());
	graphic->add(ellipse3.get());

	graphic2->add(ellipse4.get());

	graphic->add(graphic1.get());
	graphic->add(graphic2.get());

	//prints the complete graphic
	graphic->print();
}
void decorator() {
	CarDecorator exemple;
	exemple.run();
}
void factory() {

}
void factory2() {
}

void factory3() {

}
void prototype() {
	RecordFactory* factory = new RecordFactory();
	Record* recordTemplate;

	recordTemplate = factory->createRecord(CAR);
	recordTemplate->print();

	delete recordTemplate;
	delete factory;
}

int main() {

	string tutorial_to_run = "prototype";

	if (tutorial_to_run == "bridge") {
		bridge();
	} else if (tutorial_to_run == "builder") {
		builder();
	} else if (tutorial_to_run == "compositer") {
		compositer();
	} else if (tutorial_to_run == "decorator") {
		decorator();
	} else if (tutorial_to_run == "factory") {
		factory();
	} else if (tutorial_to_run == "factory2") {
		factory2();
	} else if (tutorial_to_run == "factory3") {
		factory2();
	} else if (tutorial_to_run == "prototype") {
		prototype();
	} else {
	}

	return 0;
}
