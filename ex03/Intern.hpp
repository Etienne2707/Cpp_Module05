#ifndef INTERN_H
# define INTERN_H


#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
public:
    Intern();
    ~Intern();
    Intern & operator=(Intern const & rhs);
    Intern( Intern const & src );
    Form* makeForm(const std::string form, const std::string Bname);



};

#endif