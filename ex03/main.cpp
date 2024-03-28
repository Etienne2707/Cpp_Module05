#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{

    int grade;
    while (-1)
    {
        std::cout << "What's grade you want test ?" << std::endl;
        std::cin >> grade;
        Bureaucrat b("Eric",grade);
        ShrubberyCreationForm Sf("Target");
        RobotomyRequestForm RRf("TargetRRF");
        Intern esclave;


        /*std::cout << b << std::endl;
        Sf.beSigned(b);
        b.executeForm(Sf);*/
        //RRf.beSigned(b);
        //b.executeForm(RRf);
        esclave.makeForm("RobotomyRequestForm", "Alex");



    }

    return (1);
}