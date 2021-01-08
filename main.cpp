/*
 * main.cpp
 *
 *  Created on: 4 янв. 2021 г.
 *      Author: user
 */
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

#include "ImageOpers.hpp"
#include "Comm.hpp"
Comm comm;
// "/Users/user/Pictures/9879934.jpg";

void Terminal(){
	comm.TerminalCommander();
};
int main(int argc, char *argv[]) {
	Terminal();
	return 0;
}

