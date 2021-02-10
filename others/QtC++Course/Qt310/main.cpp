/*#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    // [capture list] (parameter list) {function body}
    //lambda func
    auto func = [](){
        cout << "Hello world" << endl;
    };

    func();


    return 0;
}*/

#include <iostream>

int main()
{
    // lambda func: [capture list] (paramater list) -> return type {function body}(argument list);

    auto func = [](int a, int b)->int{
        return a + b;
    }(7, 3);

    std::cout << func << std::endl;

    int a = 7;
    int b = 3;

    auto func1 = [&a, &b](){
       std::cout << a << " " << b << "\n";
    };

    for(int count = 1; count < 5; ++count){
        std::cout << a++ << " " << b++ << "\n";
        func1();
    }

    auto func2 = [&](){
        a; // capture everything, I can use a in this scope too. = means by value, & means by reference I want to capture
    };


    return 0;
}
