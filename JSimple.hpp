#ifndef JSimple
#define JSimple
#pragma once

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <random>
#include <sstream>
using namespace std;

void Print(string String);

string GetInput();

string CreateInput(const string& prompt);

vector<string> ReadFileToList(const string& filepath);

string ReadFileToString(const string& filepath);

template <typename T>
void WriteToFile(const string& filepath, const T& data);

string ListToString(vector<string> stringList);

vector<char> StringToListChars(string Input);

vector<string> StringToListWords(string Input);

float RandomFloat(float min, float max);

int RandomInt(int min, int max);

string ToLowerCase(string string);

string ToUpperCase(string string);

float CompareStringByChar(const string& string1, const string& string2); // Broken: Always returns 100.0

float CompareStringByWord(const string& string1, const string& string2); // Broken: Always returns 100.0

string ReverseString(string Input);

wstring ToWideString(string Input);

bool IsPrime(int Number);

#endif
