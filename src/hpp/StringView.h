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
        std::cout << "string view adress " << (void*)view.data() << " substr addr: " << (void*)view.substr(5, 5).data() << " value of substring " << view.substr(5,5).data() << std::endl;
        std::cout << "string adress " << (void*)str.data() << " substr addr: " << (void*)str.substr(5, 5).data() << " value of substring " << str.substr(5, 5).data() << std::endl;
    }
    public:
    void operator()() { runnable(); };
};