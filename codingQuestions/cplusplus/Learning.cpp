#include <iostream>
#include <limits>
#include <ostream>

int main (int argc, char *argv[]) {
    

    std::cout << "Here is some text.";


    //these are some standard in functions in c++, changing limits and clearing.
    std::cin.clear(); //clear stdin
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignore anything but enter
    std::cin.get(); //grab a character

    //double colon is a "scope resolution operator"... basically the same as "x.y()" in Java
    //:: at start means look in global namespace, X:: means look in namespace of X for thing after.
    //no leading :: means "use our current namespace" within context of code.
    


    //wtf is this
    std::cout << "hello world" << std::endl;
    
    return 0;
}
