#pragma once
#include <string>
#include <string_view>
#include <iostream>

class StringViewExample 
{
    //string view holds pointer to beggining of the char array and array itself
    //it is most beneficial when you want to display substring
    static void runnable() {
        std::string str = "string longer than the one being hold on stack by most compilers";
        std::string_view view = str;
        std::cout << "Asd" << std::endl;
    }
    public:
    void operator()() { runnable(); };
};