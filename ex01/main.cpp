#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{

    int grade;
    int form;

    while (-1)
    {
        std::cout << "What's grade you want test ?" << std::endl;
        std::cin >> grade;
        std::cout << "What Grade For the Form ? " << std::endl;
        std::cin >> form;
        Bureaucrat b("Eric",grade);
        Form f("Faire CACA",form,1);

        std::cout << b << std::endl;
        b.signForm(f);

        std::cout << f << std::endl;
    }

    return (1);
}