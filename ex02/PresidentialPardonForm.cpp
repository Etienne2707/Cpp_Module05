#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
    std::cout << yellow << "Default PresidentialPardonForm constructor call" << reset << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : _target(target)
{
    std::cout << yellow << "Parametric PresidentialPardonForm constructor call" << reset << std::endl;
    this->_signed = false;
    this->_sgrade = 25;
    this ->_egrade = 5;
    this->_executed = false;
    
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << red << "Default Destructor call" << reset << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ){
    std::cout << "PresidentialPardonForm Copy constructeur called" << std::endl;
    *this = src;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
    std::cout << "PresidentialPardonForm Assignment operator called" << std::endl;
    this->_target = rhs.getTarget();
    this->_sgrade = rhs.getSGrade();
    this->_egrade = rhs.getEGrade();
    this->_signed = rhs._signed;
    this->_executed = rhs._executed;
    return *this;
}

std::string PresidentialPardonForm::getTarget(void)const
{
    return (this->_target);
}

int PresidentialPardonForm::getEGrade(void)const
{
    return (this->_egrade);
}

int PresidentialPardonForm::getSGrade(void)const
{
    return (this->_sgrade);
}

bool PresidentialPardonForm::getSigned(void)const
{
    return (this->_signed);
}

void    PresidentialPardonForm::beSigned(Bureaucrat const &b)
{
    try
    {
        if (b.getGrade() > this->_sgrade)
            throw GradeTooLowException();
        else
            this->_signed = true;
    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << reset << '\n';
    }
}

bool    PresidentialPardonForm::execute(Bureaucrat const &b)const
{
    std::string file = this->_target + "_shruberry";
    try
    {
        if (b.getGrade() > this->_egrade)
            throw GradeTooLowException();
        if (this->_signed == false)
            throw NotSignedException();
        else
        {
            std::cout << cyan << this->_target << "has been pardoned by Zahpod Beevlebrox" << std::endl;
            return true;
        }

    }
    catch(GradeTooLowException & e)
    {
        std::cout << e.what() << reset << '\n';
        return false;
    }
    catch(NotSignedException & e)
    {
        std::cout << e.what() << reset << '\n';
        return true;
    }
    
}

const char * PresidentialPardonForm::NotSignedException::what()const throw()
{
    std::cout << magenta;
    return ("Erreur PresidentialPardonForm not signed");
}

const char * PresidentialPardonForm::GradeTooHighException::what()const throw()
{
    std::cout << magenta;
    return ("Erreur PresidentialPardonForm Too Hight");
}

const char * PresidentialPardonForm::GradeTooLowException::what()const throw()
{
    std::cout << red;
    return ("Erreur PresidentialPardonForm Too Low");
}

std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & i)
{
    o << cyan <<  i.getName() << " PresidentialPardonForm grade :" << i.getSGrade();
    return o;
}