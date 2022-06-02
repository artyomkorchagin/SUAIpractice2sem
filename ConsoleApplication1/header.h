#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include <windows.h>

using namespace std;

string* SeparateWords(string text);

string* CombSort(string* wordArr, double &Time);

void CreateOutput(string* textArr, string first_text, double Time);