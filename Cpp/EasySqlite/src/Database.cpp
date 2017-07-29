/*
 * Database.cpp
 *
 *  Created on: 28 de jul de 2017
 *      Author: anderson
 */

#include "Database.h"

Database::Database(std::string databaseFile)
{
	if (sqlite3_open(databaseFile.c_str(), &m_db) != SQLITE_OK)
	{
		error_cant_open();
	}
}

Database::~Database()
{
	sqlite3_close(m_db);
}

int Database::query(std::string sql_query, std::list<std::string>& out_values)
{
	//database handler
	sqlite3_stmt *res;

	//create SQL statement definition
	if (sqlite3_prepare_v2(m_db, sql_query.c_str(), -1, &res, 0) != SQLITE_OK)
	{
		error_failed_to_fetch();
	}

	//capture values until the table finishes
	while (true)
	{
		if (sqlite3_step(res) != SQLITE_ROW)
		{
			break;
		}
		out_values.push_back((const char*) sqlite3_column_text(res, 0));
	}

	sqlite3_finalize(res);
	return (DATABASE_SUCCSESS);
}

int Database::get(std::string table, std::string thecolumn,
		std::list<std::string>& out_values)
{
	std::string sql_query = "SELECT " + thecolumn + " FROM " + table + ";";

	query(sql_query, out_values);

	return (DATABASE_SUCCSESS);
}

std::string Database::max(std::string table, std::string thecolumn,
		std::string& value)
{
	//std::list<std::string> out_values;
	//TODO
	return "";
}

int Database::get_where(std::string table, std::string thecolumn,
		std::string where_constraint, std::list<std::string>& out_values)
{
	std::string sql_query = "SELECT " + thecolumn + " FROM " + table + " WHERE "
			+ where_constraint + ";";

	query(sql_query, out_values);

	return (DATABASE_SUCCSESS);
}

int Database::join(std::string table1, std::string table2,
		std::string thecolumn, std::string on_constraint,
		std::list<std::string>& out_values)
{
	out_values.push_back("1");
	out_values.push_back("2");
	out_values.push_back("3");
	out_values.push_back("4");
	out_values.push_back("5");
	out_values.push_back("6");
	out_values.push_back("7");
	out_values.push_back("8");
	out_values.push_back("8");
	out_values.push_back("10");
	out_values.push_back("1");
	out_values.push_back("2");
	out_values.push_back("3");
	out_values.push_back("4");
	out_values.push_back("5");
	out_values.push_back("6");
	out_values.push_back("7");
	out_values.push_back("8");
	out_values.push_back("8");
	out_values.push_back("10");

	return (DATABASE_SUCCSESS);
}

int Database::get(std::string table, std::string thecolumn,
		std::list<double>& out_values)
{
	std::list<std::string> out_str;

	get(table, thecolumn, out_str);
	string_to_double(out_str, out_values);

	return (DATABASE_SUCCSESS);
}

int Database::get_where(std::string table, std::string thecolumn,
		std::string where_constraint, std::list<double>& out_values)
{
	std::list<std::string> out_str;

	get_where(table, thecolumn, where_constraint, out_str);
	string_to_double(out_str, out_values);

	return (DATABASE_SUCCSESS);
}

int Database::join(std::string table1, std::string table2,
		std::string thecolumn, std::string on_constraint,
		std::list<double>& out_values)
{
	std::list<std::string> out_str;

	join(table1, table2, thecolumn, on_constraint, out_str);
	string_to_double(out_str, out_values);

	return (DATABASE_SUCCSESS);
}

double Database::max(std::string table, std::string thecolumn, double& value)
{
	std::string out_str;

	max(table, thecolumn, out_str);

	return (std::stof(out_str));
}

int Database::get(std::string table, std::string thecolumn,
		std::list<int>& out_values)
{
	std::list<std::string> out_str;

	get(table, thecolumn, out_str);
	string_to_int(out_str, out_values);

	return (DATABASE_SUCCSESS);
}

int Database::get_where(std::string table, std::string thecolumn,
		std::string where_constraint, std::list<int>& out_values)
{
	std::list<std::string> out_str;

	get_where(table, thecolumn, where_constraint, out_str);
	string_to_int(out_str, out_values);

	return (DATABASE_SUCCSESS);
}

int Database::join(std::string table1, std::string table2,
		std::string thecolumn, std::string on_constraint,
		std::list<int>& out_values)
{
	std::list<std::string> out_str;

	join(table1, table2, thecolumn, on_constraint, out_str);
	string_to_int(out_str, out_values);

	return (DATABASE_SUCCSESS);
}

int Database::max(std::string table, std::string thecolumn, int& value)
{
	std::string out_str;

	max(table, thecolumn, out_str);

	return (std::stoi(out_str));
}

void Database::string_to_int(std::list<std::string> inlist,
		std::list<int>& outlist)
{

	for (std::list<std::string>::iterator it = inlist.begin();
			it != inlist.end(); it++)
	{
		outlist.push_back(std::stoi(*it));
	}
}

void Database::string_to_double(std::list<std::string> inlist,
		std::list<double>& outlist)
{
	for (std::list<std::string>::iterator it = inlist.begin();
			it != inlist.end(); it++)
	{
		outlist.push_back(std::stof(*it));
	}
}

void Database::error_cant_open()
{
	fprintf(stderr, "DatabaseSqlite3 Error: Can't open database: %s\n",
			sqlite3_errmsg(m_db));
	sqlite3_close(m_db);
	exit(DATABASE_CANT_OPEN);
}

void Database::error_failed_to_fetch()
{
	fprintf(stderr, "DatabaseSqlite3 Error: Failed to fetch data: %s\n",
			sqlite3_errmsg(m_db));
	sqlite3_close(m_db);
	exit(DATABASE_FAILED_FETCH_DATA);
}

void Database::error_table_not_found()
{
	fprintf(stderr, "DatabaseSqlite3 Error: Table not found: %s\n",
			sqlite3_errmsg(m_db));
	sqlite3_close(m_db);
	exit(DATABASE_TABLE_NOT_FOUND);
}

void Database::error_column_not_found()
{
	fprintf(stderr, "DatabaseSqlite3 Error: Column not found: %s\n",
			sqlite3_errmsg(m_db));
	sqlite3_close(m_db);
	exit(DATABASE_COLUMN_NOT_FOUND);
}
