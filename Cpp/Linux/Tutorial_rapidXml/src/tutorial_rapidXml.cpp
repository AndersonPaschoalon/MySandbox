#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_print.hpp>
#include <rapidxml/rapidxml_iterators.hpp>
#include <rapidxml/rapidxml_utils.hpp>

#include "cfunctions.h"

//#include "rapidxml-1.13/rapidxml.hpp"

using namespace rapidxml;
using std::string;
using std::cout;
using std::cerr;
using std::clog;
using std::cin;
using std::endl;
using namespace std;

void tutorial_read();
void tutorial_write();
bool read_trace();
bool write_trace(int nFlows);
bool allocateFlow(xml_node<> *trace, xml_document<> &doc, xml_node<> *flow);
void tutorial_real_trace();
bool test_char2type();

int main(void) {

	bool t1 = false;
	bool t2 = false;
	bool t3 = false;
	bool t4 = false;
	bool t5 = false;
	bool t6 = true;
	bool t7 = false;
	bool t8 = false;

	if (t1)
		tutorial_read();
	if (t2)
		tutorial_write();
	if (t3)
		read_trace();
	if (t4)
		write_trace(10);
	if (t5)
		write_trace(5);
	if (t6)
		tutorial_real_trace();
	if (t7)
		cout << "test_char2type(): " << test_charvet2type();
	if (t8)
		cout << "test_delimiter(): " << test_delimiter();

	return (0);

}

void tutorial_real_trace() {

	string strBuffer;
	unsigned int intBuffer;
	unsigned long int lintBuffer;
	double doubleBuffer;

	unsigned int nFlows = 0;

	cout << "Parsing trace..." << endl;
	xml_document<> doc;
	xml_node<> * root_node;

	// Read the xml file into a vector
	ifstream theFile("kkk.xml");
	vector<char> buffer((istreambuf_iterator<char>(theFile)),
			istreambuf_iterator<char>());
	buffer.push_back('\0');

	// Parse the buffer using the xml file parsing library into doc
	doc.parse<0>(&buffer[0]);

	// Find our root node
	root_node = doc.first_node("trace");
	//root_node->first_attribute("info_tracename")->value();

	printf(
			"Trace: info_tracename=%s, trafficGenEngine=%s, info_captureDate=%s, info_commentaries=%s, n_flows=%s\n ",
			root_node->first_attribute("info_tracename")->value(),
			root_node->first_attribute("trafficGenEngine")->value(),
			root_node->first_attribute("info_captureDate")->value(),
			root_node->first_attribute("info_commentaries")->value(),
			root_node->first_attribute("n_flows")->value());

	charvet2type(root_node->first_attribute("n_flows")->value(), nFlows);

	for (xml_node<> * flow_node = root_node->first_node("flow"); flow_node;
			flow_node = flow_node->next_sibling()) {

		//Flow
		printf(
				"\tFlow: start_delay=%s, duration=%s, ds_byte=%s, n_kbytes=%s, n_packets=%s\n",
				flow_node->first_attribute("start_delay")->value(),
				flow_node->first_attribute("duration")->value(),
				flow_node->first_attribute("ds_byte")->value(),
				flow_node->first_attribute("n_kbytes")->value(),
				flow_node->first_attribute("n_packets")->value());

		//Link layer
		xml_node<> * link_node = flow_node->first_node("link_layer");
		printf("\t\tlink_layer: Protocol=%s\n", link_node->value());

		//Network layer
		xml_node<> * network_node = flow_node->first_node("network_layer");
		printf("\t\tnetwork_node: Protocol=%s, src_ip=%s, dst_ip=%s, ttl=%s\n",
				network_node->value(),
				network_node->first_attribute("src_ip")->value(),
				network_node->first_attribute("dst_ip")->value(),
				network_node->first_attribute("ttl")->value());

		//Transport layer
		xml_node<> * transport_node = flow_node->first_node("transport_layer");
		printf("\t\ttransport_layer: Protocol=%s, src_port=%s, dst_port=%s\n",
				transport_node->value(),
				transport_node->first_attribute("src_port")->value(),
				transport_node->first_attribute("dst_port")->value());

		//Application
		xml_node<> * application_node = flow_node->first_node(
				"application_layer");
		printf("\t\tapplication_layer: Protocol=%s\n",
				application_node->value());

		//Inter packet times
		xml_node<> * interpacket_node = flow_node->first_node(
				"inter_packet_times");

		printf("\t\tinter_packet_times:\n");
		for (xml_node<> * model_node = interpacket_node->first_node(
				"stochastic_model"); model_node;
				model_node = model_node->next_sibling()) {

			printf(
					"\t\t\tstochastic_model: Name=%s, param1=%s, param2=%s, aic=%s, bic=%s\n",
					model_node->first_attribute("name")->value(),
					model_node->first_attribute("param1")->value(),
					model_node->first_attribute("param2")->value(),
					model_node->first_attribute("aic")->value(),
					model_node->first_attribute("bic")->value());
		}


		//Inter packet times
		xml_node<> * packetsizes_nodes = flow_node->first_node("packet_sizes");

		printf("\t\tpacketSizes: n_packets=%s, n_kbytes=%s\n",
				packetsizes_nodes->first_attribute("n_packets")->value(),
				packetsizes_nodes->first_attribute("n_kbytes")->value());

		xml_node<> * psmode1_node = packetsizes_nodes->first_node("ps_mode1");
		printf("\t\t\tps_mode1: n_packets=%s, n_kbytes=%s\n",
				psmode1_node->first_attribute("n_packets")->value(),
				psmode1_node->first_attribute("n_kbytes")->value());

		for (xml_node<> * model_node = psmode1_node->first_node(
				"stochastic_model"); model_node;
				model_node = model_node->next_sibling()) {
			printf(
					"\t\t\t\tstochastic_model: Name=%s, param1=%s, param2=%s, aic=%s, bic=%s\n",
					model_node->first_attribute("name")->value(),
					model_node->first_attribute("param1")->value(),
					model_node->first_attribute("param2")->value(),
					model_node->first_attribute("aic")->value(),
					model_node->first_attribute("bic")->value());

		}

		xml_node<> * psmode2_node = packetsizes_nodes->first_node("ps_mode2");
		printf("\t\t\tps_mode2: n_packets=%s, n_kbytes=%s\n",
				psmode2_node->first_attribute("n_packets")->value(),
				psmode2_node->first_attribute("n_kbytes")->value());

		for (xml_node<> * model_node = psmode2_node->first_node(
				"stochastic_model"); model_node;
				model_node = model_node->next_sibling()) {
			printf(
					"\t\t\t\tstochastic_model: Name=%s, param1=%s, param2=%s, aic=%s, bic=%s\n",
					model_node->first_attribute("name")->value(),
					model_node->first_attribute("param1")->value(),
					model_node->first_attribute("param2")->value(),
					model_node->first_attribute("aic")->value(),
					model_node->first_attribute("bic")->value());

		}

	}

// Iterate over the brewerys

}

void tutorial_read() {
	cout << "Parsing my beer journal..." << endl;
	xml_document<> doc;
	xml_node<> * root_node;
// Read the xml file into a vector
	ifstream theFile("beerJournal.xml");
	vector<char> buffer((istreambuf_iterator<char>(theFile)),
			istreambuf_iterator<char>());
	buffer.push_back('\0');
// Parse the buffer using the xml file parsing library into doc
	doc.parse<0>(&buffer[0]);
// Find our root node
	root_node = doc.first_node("MyBeerJournal");
// Iterate over the brewerys
	for (xml_node<> * brewery_node = root_node->first_node("Brewery");
			brewery_node; brewery_node = brewery_node->next_sibling()) {
		printf("I have visited %s in %s. ",
				brewery_node->first_attribute("name")->value(),
				brewery_node->first_attribute("location")->value());
		// Interate over the beers
		for (xml_node<> * beer_node = brewery_node->first_node("Beer");
				beer_node; beer_node = beer_node->next_sibling()) {
			printf("On %s, I tried their %s which is a %s. ",
					beer_node->first_attribute("dateSampled")->value(),
					beer_node->first_attribute("name")->value(),
					beer_node->first_attribute("description")->value());
			printf("I gave it the following review: %s", beer_node->value());
		}
		cout << endl;
	}
}

void tutorial_write() {
// Write xml file =================================

	xml_document<> doc;
	xml_node<>* decl = doc.allocate_node(node_declaration);
	decl->append_attribute(doc.allocate_attribute("version", "1.0"));
	decl->append_attribute(doc.allocate_attribute("encoding", "utf-8"));
	doc.append_node(decl);

	xml_node<>* root = doc.allocate_node(node_element, "rootnode");
	root->append_attribute(doc.allocate_attribute("version", "1.0"));
	root->append_attribute(doc.allocate_attribute("type", "example"));
	doc.append_node(root);

	xml_node<>* child = doc.allocate_node(node_element, "childnode");
	root->append_node(child);

	child->value("Any value here");
	child->append_attribute(doc.allocate_attribute("valor", "string-valor"));

// Convert doc to string if needed
	std::string xml_as_string;
	rapidxml::print(std::back_inserter(xml_as_string), doc);

// Save to file
	std::ofstream file_stored("file_stored.xml");
	file_stored << doc;
	file_stored.close();
	doc.clear();
}

bool read_trace() {

	return (true);
}

bool write_trace(int nFlows) {

	xml_document<> doc;
	xml_node<>* decl = doc.allocate_node(node_declaration);
	decl->append_attribute(doc.allocate_attribute("version", "1.0"));
	decl->append_attribute(doc.allocate_attribute("encoding", "utf-8"));
	doc.append_node(decl);

//---------------------------------------
//Trace data

	string info_tracename = "Wombat-trace";
	string trafficGenEngine = "ditg";
	string info_captureDate = "24/02/2017";
	string info_commentaries = "any comment here";
	char dd[] = "D-ITG";

//---------------------------------------

//Create Network trace
	xml_node<>* trace = doc.allocate_node(node_element, "network_trace");
	trace->append_attribute(
			doc.allocate_attribute("info_tracename", "Wombat-trace"));
	trace->append_attribute(doc.allocate_attribute("trafficGenEngine", dd));
	trace->append_attribute(
			doc.allocate_attribute("info_captureDate", "24/02/2017"));
	trace->append_attribute(
			doc.allocate_attribute("info_commentaries", "any comment here"));
	doc.append_node(trace);

	for (int i = 0; i < nFlows; i++) {

		xml_node<>* flow = doc.allocate_node(node_element, "childnode");

		//allocateFlow(trace, doc, flow );

		xml_node<>* link_layer = doc.allocate_node(node_element, "link_layer");
		flow->append_node(link_layer);

		xml_node<>* network_layer = doc.allocate_node(node_element,
				"network_layer");
		flow->append_node(network_layer);

		xml_node<>* transport_layer = doc.allocate_node(node_element,
				"transport_layer");
		flow->append_node(transport_layer);

		xml_node<>* application_layer = doc.allocate_node(node_element,
				"application_layer");
		flow->append_node(application_layer);

		xml_node<>* interArrivalvet = doc.allocate_node(node_element,
				"interArrivalvet");
		flow->append_node(interArrivalvet);

		int nModels = 7;

		if (nModels == 7) {
			xml_node<>* StochasticModelFit1 = doc.allocate_node(node_element,
					"StochasticModelFit1");
			interArrivalvet->append_node(StochasticModelFit1);

			xml_node<>* StochasticModelFit2 = doc.allocate_node(node_element,
					"StochasticModelFit2");
			interArrivalvet->append_node(StochasticModelFit2);

			xml_node<>* StochasticModelFit3 = doc.allocate_node(node_element,
					"StochasticModelFit3");
			interArrivalvet->append_node(StochasticModelFit3);

			xml_node<>* StochasticModelFit4 = doc.allocate_node(node_element,
					"StochasticModelFit4");
			interArrivalvet->append_node(StochasticModelFit4);

			xml_node<>* StochasticModelFit5 = doc.allocate_node(node_element,
					"StochasticModelFit5");
			interArrivalvet->append_node(StochasticModelFit5);

			xml_node<>* StochasticModelFit6 = doc.allocate_node(node_element,
					"StochasticModelFit6");
			interArrivalvet->append_node(StochasticModelFit6);

			xml_node<>* StochasticModelFit7 = doc.allocate_node(node_element,
					"StochasticModelFit7");
			interArrivalvet->append_node(StochasticModelFit7);

		} else {

		}

		xml_node<>* interFileModel = doc.allocate_node(node_element,
				"interFileModel");
		flow->append_node(interFileModel);

		xml_node<>* StochasticModelFitA = doc.allocate_node(node_element,
				"StochasticModelFitA");
		interFileModel->append_node(StochasticModelFitA);

		xml_node<>* sessionOnOffTimes = doc.allocate_node(node_element,
				"sessionOnOffTimes");
		flow->append_node(sessionOnOffTimes);

		xml_node<>* psMode1 = doc.allocate_node(node_element, "psMode1");
		flow->append_node(psMode1);

		xml_node<>* psMode2 = doc.allocate_node(node_element, "psMode2");
		flow->append_node(psMode2);

		trace->append_node(flow);
	}

// Convert doc to string if needed
	std::string xml_as_string;
	rapidxml::print(std::back_inserter(xml_as_string), doc);

// Save to file
	std::ofstream file_stored("compact_trace_descriptor.xml");
	file_stored << doc;
	file_stored.close();
	doc.clear();

	return (true);
}

bool allocateFlow1(xml_node<> *trace) {
	return (true);
}

//bool allocateStochasticModel()

bool allocateFlow(xml_node<> *trace, xml_document<> &doc, xml_node<> *flow) {

	xml_node<>* link_layer = doc.allocate_node(node_element, "link_layer");
	flow->append_node(link_layer);

	xml_node<>* network_layer = doc.allocate_node(node_element,
			"network_layer");
	flow->append_node(network_layer);

	xml_node<>* transport_layer = doc.allocate_node(node_element,
			"transport_layer");
	flow->append_node(transport_layer);

	xml_node<>* application_layer = doc.allocate_node(node_element,
			"application_layer");
	flow->append_node(application_layer);

	xml_node<>* interArrivalvet = doc.allocate_node(node_element,
			"interArrivalvet");
	flow->append_node(interArrivalvet);

	xml_node<>* StochasticModelFit1 = doc.allocate_node(node_element,
			"StochasticModelFit1");
	interArrivalvet->append_node(StochasticModelFit1);

	xml_node<>* StochasticModelFit2 = doc.allocate_node(node_element,
			"StochasticModelFit2");
	interArrivalvet->append_node(StochasticModelFit2);

	xml_node<>* StochasticModelFit3 = doc.allocate_node(node_element,
			"StochasticModelFit3");
	interArrivalvet->append_node(StochasticModelFit3);

	xml_node<>* StochasticModelFit4 = doc.allocate_node(node_element,
			"StochasticModelFit4");
	interArrivalvet->append_node(StochasticModelFit4);

	xml_node<>* StochasticModelFit5 = doc.allocate_node(node_element,
			"StochasticModelFit5");
	interArrivalvet->append_node(StochasticModelFit5);

	xml_node<>* StochasticModelFit6 = doc.allocate_node(node_element,
			"StochasticModelFit6");
	interArrivalvet->append_node(StochasticModelFit6);

	xml_node<>* StochasticModelFit7 = doc.allocate_node(node_element,
			"StochasticModelFit7");
	interArrivalvet->append_node(StochasticModelFit7);

	xml_node<>* interFileModel = doc.allocate_node(node_element,
			"interFileModel");
	flow->append_node(interFileModel);

	xml_node<>* StochasticModelFitA = doc.allocate_node(node_element,
			"StochasticModelFitA");
	interFileModel->append_node(StochasticModelFitA);

	xml_node<>* sessionOnOffTimes = doc.allocate_node(node_element,
			"sessionOnOffTimes");
	flow->append_node(sessionOnOffTimes);

	xml_node<>* sessionOnTimes = doc.allocate_node(node_element,
			"sessionOnTimes");
	sessionOnOffTimes->append_node(sessionOnTimes);

	xml_node<>* sessionOffTimes = doc.allocate_node(node_element,
			"sessionOffTimes");
	sessionOnOffTimes->append_node(sessionOffTimes);

	xml_node<>* psMode1 = doc.allocate_node(node_element, "psMode1");
	flow->append_node(psMode1);

	xml_node<>* StochasticModelFit_a = doc.allocate_node(node_element,
			"StochasticModelFit_a");
	psMode1->append_node(StochasticModelFit_a);

	xml_node<>* StochasticModelFit_b = doc.allocate_node(node_element,
			"StochasticModelFit_b");
	psMode1->append_node(StochasticModelFit_b);

	xml_node<>* StochasticModelFit_c = doc.allocate_node(node_element,
			"StochasticModelFit_c");
	psMode1->append_node(StochasticModelFit_c);

	xml_node<>* psMode2 = doc.allocate_node(node_element, "psMode2");
	flow->append_node(psMode2);

	xml_node<>* StochasticModelFit_aa = doc.allocate_node(node_element,
			"StochasticModelFit_aa");
	psMode2->append_node(StochasticModelFit_aa);

	xml_node<>* StochasticModelFit_bb = doc.allocate_node(node_element,
			"StochasticModelFit_bb");
	psMode2->append_node(StochasticModelFit_bb);

	xml_node<>* StochasticModelFit_cc = doc.allocate_node(node_element,
			"StochasticModelFit_cc");
	psMode2->append_node(StochasticModelFit_cc);

	return (true);
}

