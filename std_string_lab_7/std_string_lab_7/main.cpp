#include "header.h"


int main()
{
    try
    {
        std::string input;
        InputString(input);

        std::string result = ResultString(input);
        std::cout << "Result: " << result << '\n';
    }
    catch (std::invalid_argument& e) { std::cout << e.what(); }
    system("pause");
    return 0;
}

