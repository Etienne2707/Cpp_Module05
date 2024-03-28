#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
    std::cout << yellow << "Default Intern constructor call" << reset << std::endl;
}

Intern::~Intern()
{
    std::cout << red << "Default Destructor call" << reset << std::endl;
}

Intern::Intern( Intern const & src ){
    std::cout << "Intern Copy constructeur called" << std::endl;
    *this = src;
}

Intern & Intern::operator=(Intern const & rhs)
{
    std::cout << "Intern Assignment operator called" << std::endl;
    	if (this == &rhs)
		return *this;

	// nothing to copy here, since intern has no variables
	return *this;
}

static Form	*makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static Form	*makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static Form	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form	*Intern::makeForm(const std::string form, const std::string Bname)
{
    Form *(*all_forms[])(const std::string target) = {&makeShrubbery, &makeRobot, &makePresident};
    std::string string_form[] = {"ShrubberyCreationForm","RobotomyRequestForm","PresidentialPardonForm"};
    for (int i = 0; i < 3 ; i++)
    {
        if (string_form[i] == form)
        {
            std::cout << cyan <<  "Intern creates " << form << std::endl;
            return (all_forms[i](Bname));
        }
    }
    std::cout << red << "You ask an form who doesn't exist : " << form << std::endl;
    return (NULL);
}
