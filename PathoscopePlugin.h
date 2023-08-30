#ifndef PATHOSCOPEPLUGIN_H
#define PATHOSCOPEPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>

class PathoscopePlugin : public Plugin
{
public: 
 std::string toString() {return "Pathoscope";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::map<std::string, std::string> parameters;

};

#endif
