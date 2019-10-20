#pragma once
#include <variant>
#include <iostream>

/*
class template std::variant is a type safe union 
(compiler will let You know if you mess up the types)
it cannot allocate dynamic memmory so no references. arrays or void
use std::variant<std::monostate> instead of empty variant
*/

template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...)->overloaded<Ts...>;

class Visitor1 {};

class Visitor2 {};

class Variant
{
public:
	Variant() {};
	~Variant() = default;

	void exampleSimple() 
	{
		std::variant<int, float> varInt, varFloat;
		varInt = 12;
		auto temp = std::get<int>(varInt);
		std::cout << temp << std::endl;
		//thats why we should use visitor
		try {
			float tempFloat = std::get<float>(varFloat);
		}
		catch (std::bad_variant_access& e) 
		{
			std::cout << e.what() << std::endl;
		}
	}

	void exampleVisitor() 
	{
		std::variant<Visitor1, Visitor2> variant_obj = Visitor2();
		std::visit(overloaded{
		[](Visitor1) {std::cout << "functor1" << std::endl; },
		[](Visitor2) {std::cout << "functor2" << std::endl; }
			}, variant_obj);
	}
};


