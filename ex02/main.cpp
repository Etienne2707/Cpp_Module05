#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{

    int grade;
    int form;

    while (-1)
    {
        std::cout << "What's grade you want test ?" << std::endl;
        std::cin >> grade;
        std::cout << "What Grade For the Shruberry Form ? " << std::endl;
        std::cin >> form;
        Bureaucrat b("Eric",grade);
        ShrubberyCreationForm Sf("Target");

        std::cout << b << std::endl;

    }

    return (1);
}