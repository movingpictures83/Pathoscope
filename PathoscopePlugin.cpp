#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "PathoscopePlugin.h"

void PathoscopePlugin::input(std::string file) {
  inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 std::cout << file << std::endl;
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   if (key.length() == 0) break;
   ifile >> value;
   if (value.length() == 0) break;
   parameters[key] = value;
 }


}

void PathoscopePlugin::run() {}

void PathoscopePlugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";
 myCommand += "pathoscope ID -alignFile "+std::string(PluginManager::prefix())+"/"+parameters["samfile"]+" -fileType sam -outDir "+outputfile+" -thetaPrior "+parameters["thetaPrior"];
std::cout << myCommand << std::endl;
system(myCommand.c_str());
}

PluginProxy<PathoscopePlugin> PathoscopePluginProxy = PluginProxy<PathoscopePlugin>("Pathoscope", PluginManager::getInstance());

