#pragma once

#include <algorithm>
#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#define ERROR_SCRIPT_FILE_NOT_EXIT     "(script call) Script file does not exist!"
#define ERROR_SCRIPT_POPEN_CALL        "(script call) error executing _popen() fucntion call"
#define ERROR_SCRIPT_POPEN_CALL        "(script call) error executing fgets() fucntion call"
// 
#define RETURN_SUCCESS                  0
#define RETURN_SCRIPT_FILE_NOT_EXIT    -1
#define RETURN_SCRIPT_POPEN_CALL       -2
#define RETURN_SCRIPT_FGETS_CALL       -3

#define SHELL_BATCH                           "batch"
#define SHELL_SHELL_SCRIPT                    "shellscript"
#define SHELL_POWER_SHELL                     "powershell"
#define SHELL_PYTHON                          "python"

/// <summary>
/// This class is responsible for managing the execution of script files, and collect its 
/// standard output into strings
/// </summary>
class ScriptCmd
{
public:

	/// <summary>
	/// Types of scripts
	/// </summary>
	enum class ShellType
	{
		BATCH = 0,
		SHELL_SCRIPT = 1,
		POWER_SHELL = 2,
		PYTHON = 3
	};

	static ShellType strToShellType(const char*);

	///////////////////////////////////////////////////////////////////////////
	// Class methods
	///////////////////////////////////////////////////////////////////////////

	/// <summary>
	/// Default constructor.
	/// </summary>
	ScriptCmd();

	/// <summary>
	/// Parameterized constructor.
	/// </summary>
	/// <param name="script"></param>
	/// <param name="params"></param>
	/// <param name="shelltype"></param>
	ScriptCmd(const char* script, const char* params = "", ScriptCmd::ShellType shelltype = ScriptCmd::ShellType::BATCH);

	/// <summary>
	/// Destructor.
	/// </summary>
	~ScriptCmd();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="obj"></param>
	ScriptCmd(const ScriptCmd& obj);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="rhs"></param>
	/// <returns></returns>
	ScriptCmd& operator=(const ScriptCmd& rhs);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	std::string toString();

	///////////////////////////////////////////////////////////////////////////
	// Getters and setters
	///////////////////////////////////////////////////////////////////////////

	/// <summary>
	/// Sets an script to be executed. just fill member variables, but do not perform any check.
	/// </summary>
	/// <param name="script"></param>
	/// <param name="params"></param>
	/// <param name="shelltype"></param>
	void setScriptCmd(const char* script, const char* params = "", ScriptCmd::ShellType shelltype = ScriptCmd::ShellType::BATCH);

	/// <summary>
	/// Setts the generad files, to keep track of the files the script is suposed to create.
	/// </summary>
	/// <param name="listGeneratedFiles"></param>
	void setGeneratedFiles(std::vector<std::string> listGeneratedFiles);

	/// <summary>
	/// Returns the list of files this script is soposed to generate.
	/// </summary>
	/// <returns></returns>
	std::vector<std::string> getGeneratedFiles();

	/// <summary>
	/// Optional setter, sets a name for for the standard output if is is saved into a file.
	/// If this parameter is not set, it will use a default value: the script file name.
	/// </summary>
	void setStdoutFilename(const char* filename);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	std::string getStdoutFilename();

	///////////////////////////////////////////////////////////////////////////
	// Script routines
	///////////////////////////////////////////////////////////////////////////

	/// <summary>
	/// Execute an script in a supported shell, and collocts its standard output into an std::string.
	/// </summary>
	/// <param name="outVal"></param>
	/// <returns></returns>
	int exec(std::string& outVal);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="savedFileName"></param>
	/// <returns></returns>
	int execAndSave();

private:

	/// <summary>
	/// 
	/// </summary>
	std::string scriptFile;

	/// <summary>
	/// 
	/// </summary>
	ScriptCmd::ShellType shell;

	/// <summary>
	/// 
	/// </summary>
	std::string scriptOpts;

	/// <summary>
	/// 
	/// </summary>
	std::string stdoutFileName;

	/// <summary>
	/// 
	/// </summary>
	std::vector<std::string> listGeneratedFiles;


	/// <summary>
	/// Build a command to execute the script in the propper shell.
	/// </summary>
	/// <returns></returns>
	std::string buildCmd();

	/// <summary>
	/// check if a given file exist or not.
	/// </summary>
	/// <param name="fileName"></param>
	/// <returns></returns>
	bool fileExist(const char* fileName);

	/// <summary>
	/// 
	/// </summary>
	/// <param name=""></param>
	/// <param name="maxSize"></param>
	/// <param name="showElipsis"></param>
	/// <returns></returns>
	static std::string truncate(std::string, size_t maxSize, bool showElipsis = true);
};

