#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <array>
#include <list>
#include <fstream>
#include <assert.h>
#include <errno.h>
using namespace std;
using std::array;
using std::list;
using std::ifstream;


// classes
class testargs;
class dataT;
class abacate;
class std_tests;

// tests
void tests_str();
void test_listAllocator();
void test_copyConstructor();
void test_sprintf();
void test_fname();
void test_constTest();
void test_if();
void test_getDestIp();
void test_getnext();
void test_getHostIpMac();
void test_testargs();
void test_defaultArgs();


// functions
list<abacate>* allocate_list(int size);
char** str_split(char* a_str, const char a_delim);
int getHostIP(int& counter, const char* filename, char* ipAddr);
bool isFileEmpty(std::ifstream& pFile);
int getHostIpMac(int& counter, const char* filename, char* ipAddr,
		char* MacAddr);
void defaultArgs(int a1, int a2, int a3);
void defaultArgs(char* s1, int a2, int a3);
void defaultArgs2();

int main() {

	bool t1 = false;
	bool t2 = false;
	bool t3 = false;
	bool t4 = false;
	bool t5 = false;
	bool t6 = false;
	bool t7 = false;
	bool t8 = false;
	bool t9 = false;
	bool t10 = false;
	bool t11 = true;
	bool t12 = true;

	if (t1)
		tests_str();
	if (t2)
		test_listAllocator();
	if (t3)
		test_copyConstructor();
	if (t4)
		test_sprintf();
	if (t5)
		test_fname();
	if (t6)
		test_constTest();
	if (t7)
		test_if();
	if (t8)
		test_getDestIp();
	if (t9)
		test_getHostIpMac();
	if (t10)
		test_getnext();
	if (t11)
		test_testargs();
	if(t12)
		test_defaultArgs();

	return 0;
}


class testargs{
public:
	void set(string s1, string s2, int i1, double i2){
		str1 = s1;
		str2 = s2;
		val1 = i1;
		val2 = i2;
	}

	void get(string& s1, string& s2, int& i1, double& i2){
		s1 = str1;
		s2 = str2;
		i1 = val1;
		i2 = val2;
	}

	void print(){
			cout << str1 << "::" << str2 << "::" << val1 << "::" << val2 << endl;
	}
private:
	string str1;
	string str2;
	int val1;
	double val2;
};

class abacate {
public:
	abacate() {
		m_cor = "verde";
		m_estado = "verde";
		m_n = 0;
	}
	abacate(const string& s) {
		m_estado = s;
		m_cor = "verde";
		m_n = 0;
	}
	abacate(int kkk) {
		m_cor = "verde";
		m_estado = "verde";
		m_n = kkk;
	}
	string cor();
	string estado();
	void print() {
		cout << "abacate: " << m_cor << ", " << m_estado << ", " << m_n << endl;
	}

private:
	string m_cor;
	string m_estado;
	int m_n;
};

class std_tests {
public:
	void swap(int &x, int &y) {
		int temp;
		temp = x;
		x = y;
		y = temp;
		cout << "reference" << endl;
	}

	void swap(int *x, int *y) {
		int temp;
		temp = *x;
		*x = *y;
		*y = temp;
		cout << "pointer" << endl;
	}

	void test_reference_pointer1() {
		int a = 5;
		int b = 8;

		cout << "a:" << a << " b:" << b << endl;
		swap(a, b);
		cout << "a:" << a << " b:" << b << endl;
		swap(&a, &b);
		cout << "a:" << a << " b:" << b << endl;
	}

	void test_reference_pointer2() {
		int *a = NULL;
		int *b = NULL;

		a = new int(5);
		b = new int(8);

		cout << "a:" << *a << " b:" << *b << endl;
		swap(*a, *b);
		cout << "a:" << *a << " b:" << *b << endl;
		swap(a, b);
		cout << "a:" << *a << " b:" << *b << endl;

		delete a;
		delete b;
	}

	void int_to_ascii(int val, char* c) {
		string str = std::to_string(val);
		const char* cstr = str.c_str();
		strcpy(c, cstr);

	}

private:

};

void tests_str() {
	string test_name = "int_to_ascii";
	std_tests t;

	if (test_name == "test_reference_pointer1") {
		t.test_reference_pointer1();
	} else if (test_name == "test_reference_pointer2") {
		t.test_reference_pointer2();
	} else if (test_name == "int_to_ascii") {
		char c[30];
		t.int_to_ascii(10, c);
		cout << c << endl;
	} else {
	}
}

void test_listAllocator() {
	list<abacate>* aa = allocate_list(7);

	for (list<abacate>::iterator it = aa->begin(); it != aa->end(); it++) {
		it->print();

	}

	delete aa;

	aa = allocate_list(12);

	for (list<abacate>::iterator it = aa->begin(); it != aa->end(); it++) {
		it->print();
	}

}

list<abacate>* allocate_list(int size) {
	abacate a = abacate();

	list<abacate>* aList = new list<abacate>();

	for (int i = 0; i < size; i++) {
		a = abacate(i);
		aList->push_back(a);
	}

	return (aList);

}

class c1 {
public:
	c1(int k) {
		var = k;
	}
	int getVar() {
		return (var);
	}

	c1(const c1& other) {
		cout << "copy-constructor-called\n";
		var = other.var;
	}

	c1& operator=(const c1& other) noexcept
	{
		cout << "operator= called\n";
		if (this != &other) {
			var = other.var;

		} else {
			cerr
					<< "Attempted assignment of a StochasticModelFit object to itself"
					<< endl;
		}

		return (*this);
	}
private:
	int var;

};

void test_copyConstructor() {
	cout << "test2_copyConstructor\n";
	c1 k(1);
	c1 kk(3);

	k = kk;
	//k(kk);

}

void test_sprintf() {

	char str[] = "abcdefg";
	string cppStr = "ola";
	double d = 3.14;
	int i = 42;

	char v1[20];
	char v2[20];
	char v3[20];

	sprintf(v1, "%s", str);
	sprintf(v2, "%f", d);
	sprintf(v3, "%d", i);

	cout << "v1: " << v1 << endl;
	cout << "v2: " << v2 << endl;
	cout << "v3: " << v3 << endl;

}

void test_fname() {
	cout << __PRETTY_FUNCTION__ << endl;

}

void test_constTest() {
	const int aa = 3 * 4;
	cout << aa << endl;
}

void test_if() {
	int a = 1;
	int b = 2;
	bool k = true;
	bool f = false;
	string aa = "aa";
	string bb = "bb";

	if ((a == 2) || (b == 1) || (k == false) || (aa == "aaa")) {

		std::cout << "(a == 1)||(b == 1)||(k == false)||(aa == \"aaa\")"
				<< std::endl;
	} else if ((a == 2) || (b == 3)) {
		cout << "(a == 2)||(b == 2)" << endl;
	} else if ((a == 2) || (b == 3) || (bb == "ccc")) {
		cout << "(a == 2)||(b == 3)||(bb == \"ccc\")" << endl;
	} else if ((a == 2) || (b == 3)) {
		cout << "(a == 1)||(b == 2)" << endl;
	}

}

void test_getDestIp() {
	int counter = 0;
	int i = 0;
	char ipAddr[30];
	char iphostfile[] = "hostIpList.txt";

	for (i = 0; i < 30; i++) {
		getHostIP(counter, iphostfile, ipAddr);
		cout << i << ": " << ipAddr << endl;
	}

}

int getHostIP(int& counter, const char* filename, char* ipAddr) {
	int filePosition = 0;

	if (counter == 0)
		counter = 1;

	//ifstream hostIpList("hostIpList.txt", ios::in);
	ifstream hostIpList(filename, ios::in);
	if (!hostIpList || isFileEmpty(hostIpList)) {
		printf(
				"*Warning*: hostIpList.txt file is empty or do not exist.\nUsing default IP address 127.0.0.1\n");
		strcpy(ipAddr, "127.0.0.1");
		return (-1);
	} else { //no empty file

		hostIpList >> ipAddr;
		filePosition++;

		while (!hostIpList.eof()) {
			if (filePosition < counter) {
				hostIpList >> ipAddr;
				filePosition++;
			} else {
				(counter)++;
				break;
			}
		}
		if (hostIpList.eof()) {
			//EOF reached
			hostIpList >> ipAddr;
			hostIpList.clear();
			hostIpList.seekg(0);
			//hostIpList >> ipAddr;
			counter = 1;
		}
	}

	return (0);
}

bool isFileEmpty(std::ifstream& pFile) {
	return pFile.peek() == std::ifstream::traits_type::eof();
}

char** str_split(char* a_str, const char a_delim) {
	char** result = 0;
	size_t count = 0;
	char* tmp = a_str;
	char* last_comma = 0;
	char delim[2];
	delim[0] = a_delim;
	delim[1] = 0;

	/* Count how many elements will be extracted. */
	while (*tmp) {
		if (a_delim == *tmp) {
			count++;
			last_comma = tmp;
		}
		tmp++;
	}

	/* Add space for trailing token. */
	count += last_comma < (a_str + strlen(a_str) - 1);

	/* Add space for terminating null string so caller
	 knows where the list of returned strings ends. */
	count++;

	result = (char**) malloc(sizeof(char*) * count);
	if (result == NULL) {
		errno = ENOMEM;
		perror("*Error*: Memory allocation failed @ str_split()");
		exit(-1);
	}

	if (result) {
		size_t idx = 0;
		char* token = strtok(a_str, delim);

		while (token) {
			assert(idx < count);
			*(result + idx++) = strdup(token);
			token = strtok(0, delim);
		}
		assert(idx == count - 1);
		*(result + idx) = 0;
	}

	return result;
}

int getHostIpMac(int& counter, const char* filename, char* ipAddr,
		char* MacAddr) {
	int filePosition = 0;
	char strLine[50];
	char** tokens = NULL;
	if (counter == 0)
		counter = 1;

	//ifstream hostIpList("hostIpList.txt", ios::in);
	ifstream hostIpList(filename, ios::in);
	if (!hostIpList || isFileEmpty(hostIpList)) {
		fprintf(stderr,
				"*Warning*: hostIpList.txt file is empty or do not exist.\nUsing default IP address 127.0.0.1\n");
		strcpy(ipAddr, "127.0.0.1");
		return (-1);
	} else { //no empty file

		hostIpList >> strLine;
		filePosition++;

		while (!hostIpList.eof()) {
			if (filePosition < counter) {
				hostIpList >> strLine;
				filePosition++;
			} else {
				(counter)++;
				break;
			}
		}
		if (hostIpList.eof()) {
			//EOF reached
			hostIpList >> strLine;
			hostIpList.clear();
			hostIpList.seekg(0);
			//hostIpList >> ipAddr;
			counter = 1;
		}
	}

	tokens = str_split(strLine, '@');
	if (tokens) {
		int i;
		for (i = 0; *(tokens + i); i++) {
			if (i == 0) {
				strcpy(ipAddr, *(tokens + i));
			} else if (i == 1) {
				strcpy(MacAddr, *(tokens + i));
			}
			free(*(tokens + i));
		}
		free(tokens);
	} else {
		fprintf(stderr, "*Error*: failed to break string into tokens");
		return (-2);
	}

	return (0);
}

void test_getHostIpMac() {
	int counter = 0;
	int i = 0;
	char ipAddr[30];
	char macAddr[30];
	char iphostfile[] = "hostIpMacList.txt";

	for (i = 0; i < 30; i++) {
		getHostIpMac(counter, iphostfile, ipAddr, macAddr);
		cout << i << ": " << ipAddr << "->" << macAddr << endl;
	}

}

class dataT {
private:
	std::vector<int> v;
	std::vector<int> w;
	std::vector<char> data;
	uint posConterv = -1;
	uint posConterw = -1;

public:
	dataT() {
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		w.push_back(1);
		w.push_back(2);
		w.push_back(3);
		w.push_back(4);
		data.push_back('a');
		data.push_back('b');
		data.push_back('c');
		data.push_back('d');
		data.push_back('e');
		data.push_back('f');

	}
	int get_next_w() {
		posConterw++;
		if (posConterw >= w.size()) {
			posConterw = -1;
			return (0);
		}
		return (w.at(posConterw));
	}
	int get_next_v() {
		posConterv++;
		if (posConterv >= v.size()) {
			posConterv = 0;
		}
		return (v.at(posConterv));
	}
	char get_vdata() {
		return (data.at(posConterv));
	}
};

void test_getnext() {
	dataT tt;
	for (int i = 0; i < 20; i++) {
		cout << i << ": " << tt.get_next_v();
		cout << "::" << tt.get_vdata() << "::" << tt.get_next_w() << endl;
	}
}


void test_testargs(){
	testargs t1;
	string s1;
	string s2;
	int i1;
	double d1;

	t1.set("aa", "bb", 1, 3.14);
	t1.print();
	t1.get(s1, s2, i1, d1);
	cout << s1 << "::" << s2 << "::" << i1 << "::"  << d1 << endl;
	s1 = "abacate";
	s2 = "talmude";
	i1 = 12;
	d1 = 12.4;
	t1.print();
	cout << s1 << "::" << s2 << "::" << i1 << "::"  << d1 << endl;


}

void defaultArgs(int a1, int a2=2, int a3=3){
	cout << "a1="<< a1 << ", a2=" << a2 << ", a3=" << a3 << endl;
}

void defaultArgs(char* s1, int a2=2, int a3=3){
	cout << "a1="<< s1 << ", a2=" << a2 << ", a3=" << a3 << endl;
}
void defaultArgs2(char* s1, const char* s2 = "Defaultchar", int a3=3){
	cout << "s1="<< s1 << ", s2=" << s2 << ", a3=" << a3 << endl;
}
void test_defaultArgs(){

	defaultArgs(12);
	defaultArgs("a-char-vector");
	defaultArgs2("kkk");
}


