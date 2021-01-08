/*
 * Comm.hpp
 *
 *  Created on: Feb 8, 2019
 *      Author: root
 */

#ifndef X86UTILS_COMM_HPP_
#define X86UTILS_COMM_HPP_


#define ArrayT 1000U
#include <string>
#include <iostream>
#include <vector>
#include <iostream>

class Comm  {
 private:

  enum CommEnums {  // enumerate of the commands in menu
    eQuit = 1,
    eLoad,
	eHelp,
	eResize,
	eSave,
	eBlur,
    Error
  };

 public:
   Comm() {}
   CommEnums toswitch(std::string const &inString) {
    if (inString == "q") return eQuit;
    if (inString == "quit") return eQuit;
    if (inString == "exit") return eQuit;
    if (inString == "ld") return eLoad;
    if (inString == "load") return eLoad;
    if (inString == "help") return eHelp;
    if (inString == "h") return eHelp;
    if (inString == "resize") return eResize;
    if (inString == "rs") return eResize;
    if (inString == "s") return eSave;
    if (inString == "store") return eSave;
    if (inString == "blur") return eBlur;
    if (inString == "bl") return eBlur;
    return (Error);
  }
  void Help();

  void TerminalCommander();

  void Quit();
};

#endif /* X86UTILS_COMM_HPP_ */
