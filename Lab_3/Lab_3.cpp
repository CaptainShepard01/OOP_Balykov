#include "Header.h"
#include <iostream>
#include <string>

int main() {
    using verex::verex;

    // Create an example of how to test for correctly formed URLs
    verex expr = verex()
        .search_one_line()
        .start_of_line()
        .then("http")
        .maybe("s")
        .then("://")
        .maybe("www.")
        .anything_but(" ")
        .then(".com")
        .end_of_line();

    std::cout << (expr.test("https://www.github.com") ? "Matches!" : "Doesn't match!") << std::endl;

    // Ouputs the actual expression used
    std::cout << expr << std::endl << std::endl;


    // Create a test string
    std::string replaceMe = "I am trying to test replacement function";

    std::cout << replaceMe << std::endl;

    // Create an expression that seeks for word "function"
    verex expr2 = verex().find("function");
    // Execute the expression
    std::cout << expr2.replace(replaceMe, "functionality") << std::endl << std::endl;

    // Shorthand string replace
    std::cout << verex().find("short").replace("I wrote a short text", "long") << std::endl;

    verex expr3 = verex().find("This").anything().word().then(" the ").word().then(" interesting test!");
    std::cout << expr3 << std::endl;

    std::cout << (expr3.test("This is the most interesting test!") ? "Matches!" : "Doesn't match!") << std::endl;

    return 0;
}