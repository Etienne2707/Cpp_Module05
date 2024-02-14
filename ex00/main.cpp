#include "Bureaucrat.hpp"

int main(void)
{

    int grade;

    while (-1)
    {
        std::cout << "What's grade you want test ?" << std::endl;
        std::cin >> grade;
        Bureaucrat b("Eric",grade);

        std::cout << b << std::endl;
        b.Increment_Grade();
        std::cout << b << std::endl;
        b.Decrement_Grade();
        b.Decrement_Grade();

        std::cout << b  << std::endl;
    }

    return (1);
}