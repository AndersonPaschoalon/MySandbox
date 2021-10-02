#include "ScriptCmd.h"

ScriptCmd::ShellType ScriptCmd::strToShellType(const char* val)
{
	std::string str = val;
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	if (str == SHELL_BATCH)
	{
		return ScriptCmd::ShellType::BATCH;
	}
	else if (str == SHELL_POWER_SHELL)
	{
		return ScriptCmd::ShellType::POWER_SHELL;
	}
	else if (str == SHELL_PYTHON)
	{
		return ScriptCmd::ShellType::PYTHON;
	}
	else if (str == SHELL_SHELL_SCRIPT)
	{
		return ScriptCmd::ShellType::SHELL_SCRIPT;
	}
	// default
	return ScriptCmd::ShellType::BATCH;
}

ScriptCmd::ScriptCmd()
{
	this->setScriptCmd("", "", ScriptCmd::ShellType::BATCH);
}

ScriptCmd::ScriptCmd(const char* script, const char* params, ScriptCmd::ShellType shell)
{
	this->setScriptCmd(script, params, shell);
}

ScriptCmd::~ScriptCmd()
{
}

ScriptCmd::ScriptCmd(const ScriptCmd& obj)
{
	this->listGeneratedFiles = obj.listGeneratedFiles;
	this->scriptFile = obj.scriptFile;
	this->scriptOpts = obj.scriptOpts;
	this->shell = obj.shell;
	this->stdoutFileName = obj.stdoutFileName;
}

ScriptCmd& ScriptCmd::operator=(const ScriptCmd& rhs)
{
	if (this != &rhs)
	{
		this->listGeneratedFiles = rhs.listGeneratedFiles;
		this->scriptFile = rhs.scriptFile;
		this->scriptOpts = rhs.scriptOpts;
		this->shell = rhs.shell;
		this->stdoutFileName = rhs.stdoutFileName;
	}
	return *this;
}

std::string ScriptCmd::toString()
{
	std::string str;
	std::string listFiles;
	int listLen = this->listGeneratedFiles.size();
	for (int i = 0; i < listLen; i++)
	{
		if (i == 0)
		{
			listFiles = this->listGeneratedFiles[0];
		}
		else
		{
			listFiles += ", " + this->listGeneratedFiles[i];
		}
	}
	str.clear();
	str = "{scriptFile:" + this->scriptFile + ", scriptOpts:" + this->scriptOpts + ", shell:" + \
		std::to_string((int)this->shell) + ", stdoutFileName:" + this->stdoutFileName + \
		", generatedFiles:[" + listFiles + "]";
	return str;
}

void ScriptCmd::setScriptCmd(const char* script, const char* params, ScriptCmd::ShellType scriptType)
{
	this->scriptFile = script;
	this->scriptOpts = params;
	this->shell = scriptType;
	this->setStdoutFilename(script);
}

void ScriptCmd::setGeneratedFiles(std::vector<std::string> genFiles)
{
	this->listGeneratedFiles = genFiles;
}

std::vector<std::string> ScriptCmd::getGeneratedFiles()
{
	return this->listGeneratedFiles;
}

void ScriptCmd::setStdoutFilename(const char* filename)
{
	if (strcmp(filename, "") == 0)
	{
		this->stdoutFileName = "script.stdout";
	}
	else
	{
		this->stdoutFileName = filename;
		this->stdoutFileName.append(".stdout");
	}
}

std::string ScriptCmd::getStdoutFilename()
{
	return std::string();
}

int ScriptCmd::exec(std::string& outVal)
{
	char buffer[1024];
	outVal.clear();
	std::string cmd = this->buildCmd();
	if (!this->fileExist(this->scriptFile.c_str()))
	{
		outVal = ERROR_SCRIPT_FILE_NOT_EXIT;
		return RETURN_SCRIPT_FILE_NOT_EXIT;
	}
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	FILE* pipe = _popen(cmd.c_str(), "r");
#else
	FILE* pipe = popen(cmd, "r");
#endif
	if (!pipe)
	{
		outVal = ERROR_SCRIPT_POPEN_CALL;
		return RETURN_SCRIPT_POPEN_CALL;
	}
	else
	{
		try
		{
			while (fgets(buffer, sizeof buffer, pipe) != NULL) {
				outVal += buffer;
			}
		}
		catch (const std::exception& exc)
		{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
			_pclose(pipe);
#else
			pclose(pipe);
#endif
			// displays the exception information and the fgets error.
			outVal += "\n\n";
			outVal += "\t******************************************************************************\n";
			outVal += "\t* EXCEPTION CAUGHT";
			outVal += "\t******************************************************************************\n";
			outVal += exc.what();
			outVal += "\n\n";
			outVal += ERROR_SCRIPT_POPEN_CALL;
			outVal += "\n";
			return RETURN_SCRIPT_FGETS_CALL;
		}
		// close the output cmd in an usual way
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
		_pclose(pipe);
#else
		pclose(pipe);
#endif
		return RETURN_SUCCESS;
	}

	return 0;
}

int ScriptCmd::execAndSave()
{
	std::string outVal;
	outVal.clear();
	int ret = this->exec(outVal);
	std::ofstream out(this->stdoutFileName);
	out << outVal;
	out.close();
	return ret;
}

std::string ScriptCmd::buildCmd()
{
	std::string cmdBase = std::string(this->scriptFile + " " + this->scriptOpts);
	// bat
	switch (this->shell)
	{
		case ScriptCmd::ShellType::BATCH :
		{
			return cmdBase;
			break;
		}
		case ScriptCmd::ShellType::POWER_SHELL :
		{
			return "powershell -ExecutionPolicy Bypass -F  " + cmdBase;
			break;
		}
		case ScriptCmd::ShellType::SHELL_SCRIPT:
		{
			// not supported yet
			return cmdBase;
			break;
		}
		case ScriptCmd::ShellType::PYTHON:
		{
			return "python  " + cmdBase;
			break;
		}
		default:
		{
			return cmdBase;
		}
	}

	return std::string(this->scriptFile + " " + this->scriptOpts);
}

bool ScriptCmd::fileExist(const char* fileName)
{
	std::ifstream f(fileName);
	return f.good();
}

std::string ScriptCmd::truncate(std::string str, size_t maxSize, bool showElipsis)
{
	if (str.length() > maxSize)
	{
		if (showElipsis)
		{
			return str.substr(0, maxSize) + "...";
		}
		else
		{
			return str.substr(0, maxSize);
		}
	}
	return str;
}
