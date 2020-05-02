#pragma once
#include<iostream>

class Test
{
public:
	std::string name = "Kale";
	friend std::ostream& operator<<(std::ostream& os, const Test& test);
	bool operator==(const Test& test);
	void speak();
};

