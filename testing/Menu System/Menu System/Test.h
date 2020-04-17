#pragma once
#include<iostream>

class Test
{
public:
	std::string name = "Kale";
	std::string operator<<(const Test& test);
};

