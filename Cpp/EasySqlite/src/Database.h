/*
 * Database.h
 *
 *  Created on: 28 de jul de 2017
 *      Author: anderson
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include <sqlite3.h>
#include <iostream>
#include <string>
#include <string.h>
#include <list>

/**
 * Mutex used to perform operations
 */
//std::mutex db_mutex;
/**
 * Used if the database operations was succeed
 */
const int DATABASE_SUCCSESS = 0;

/**
 * Used if the wasn't possible to open the database.
 * Eg.: access denied of file does not exist.
 */
const int DATABASE_CANT_OPEN = -1;

/**
 * Used if the data cant be read
 */
const int DATABASE_FAILED_FETCH_DATA = -2;

/**
 * Used if the data cant be read
 */
const int DATABASE_TABLE_NOT_FOUND = -3;

/**
 * Used if the data cant be read
 */
const int DATABASE_COLUMN_NOT_FOUND = -4;

/**
 * A thread safe sqlite3 C++ wrapper
 */
class Database
{
public:

	/**
	 * Constructor. Open the connection
	 */
	Database(std::string databaseFile);

	/**
	 * Destructor. Close the connection
	 */
	virtual ~Database();

	// string queries

	int get(std::string table, std::string thecolumn,
			std::list<std::string>& out_values);

	std::string max(std::string table, std::string thecolumn, std::string& value);

	int get_where(std::string table, std::string thecolumn,
			std::string where_constraint, std::list<std::string>& out_values);

	int join(std::string table1, std::string table2, std::string thecolumn,
			std::string on_constraint, std::list<std::string>& out_values);

	// double queries

	int get(std::string table, std::string thecolumn,
			std::list<double>& out_values);

	double max(std::string table, std::string thecolumn, double& value);

	int get_where(std::string table, std::string thecolumn,
			std::string where_constraint, std::list<double>& out_values);

	int join(std::string table1, std::string table2, std::string thecolumn,
			std::string on_constraint, std::list<double>& out_values);

	// int queries

	int get(std::string table, std::string thecolumn,
			std::list<int>& out_values);

	int max(std::string table, std::string thecolumn, int& value);

	int get_where(std::string table, std::string thecolumn,
			std::string where_constraint, std::list<int>& out_values);

	int join(std::string table1, std::string table2, std::string thecolumn,
			std::string on_constraint, std::list<int>& out_values);

	int query(std::string sql_query, std::list<std::string>& out_values);

private:

	// members

	/**
	 * Pointer to the database
	 */
	sqlite3 *m_db;

	// private methods

	/**
	 * @brief Convert a string list to a int list
	 * @param inlist
	 * @param outlist
	 */
	void string_to_int(std::list<std::string> inlist, std::list<int>& outlist);

	/**
	 * @brief Convert a string list to a double list
	 * @param inlist
	 * @param outlist
	 */
	void string_to_double(std::list<std::string> inlist,
			std::list<double>& outlist);

	/**
	 *
	 */
	void error_cant_open();

	/**
	 *
	 */
	void error_failed_to_fetch();

	/**
	 *
	 */
	void error_table_not_found();

	/**
	 *
	 */
	void error_column_not_found();

};

// Used for debug purposes
template<typename T>
void printList(std::list<T>& theList)
{
	std::cout << "[";
	for (typename std::list<T>::iterator it = theList.begin();
			it != theList.end(); it++)
	{
		std::cout << *it << ", ";
	}
	std::cout << "]" << std::endl;
}

#endif /* DATABASE_H_ */