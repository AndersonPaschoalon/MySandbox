/*
 * libxml.h
 *
 *  Created on: 07/06/2019
 *      Author: anderson
 */

#ifndef LIBXML_H_
#define LIBXML_H_


#include <stdio.h>
#include <libxml/xmlreader.h>
#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <iostream>

using namespace std;


// testes
void printHeader(const char* msg);
void reader1_1();
void reader1_2();
void tutorial_Parsing_the_file();
void tutorial_xpath();


void streamFile(const char *filename);
void processNode(xmlTextReaderPtr reader);
xmlDocPtr getdoc (const char *docname);
xmlXPathObjectPtr getnodeset (xmlDocPtr doc, xmlChar *xpath);

#endif /* LIBXML_H_ */
