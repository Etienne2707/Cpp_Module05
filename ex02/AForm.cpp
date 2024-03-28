#include "AForm.hpp"
#include "Bureaucrat.hpp"

Form::Form()
{
    std::cout << yellow << "Default Form constructor call" << reset << std::endl;
}

Form::Form(std::string name,int sgrade,int egrade) : _name(name), _sgrade(sgrade),_egrade(egrade)
{
    std::cout << yellow << "Parametric Form constructor call" << reset << std::endl;
    this->_signed = false;
    try
    {
        if (sgrade < 1 || egrade < 1)
            throw GradeTooHighException();
        else if (sgrade > 150 || egrade > 150)
            throw GradeTooLowException();
    }
    catch(GradeTooHighException & e)
    {
        std::cout << e.what() << '\n';
        std::cout << "Form Set To 1\n";
        if (this->_egrade < 1)
            this->_egrade = 1;
        else if (this->_sgrade < 1)
            this->_sgrade = 1;
    }
    catch(GradeTooLowException & e)
    {
        std::cout << e.what() << '\n';
        std::cout << "Form Set To 150\n";
        if (this->_egrade > 150)
            this->_egrade = 150;
        else if (this->_sgrade > 150)
            this->_sgrade = 150;
    }
    
    
}

Form::~Form()
{
    std::cout << red << "Default Destructor call" << reset << std::endl;
}

Form::Form( Form const & src ){
    std::cout << "Form Copy constructeur called" << std::endl;
    *this = src;
}

Form & Form::operator=(Form const & rhs)
{
    std::cout << "Form Assignment operator called" << std::endl;
    this->_name = rhs.getName();
    this->_sgrade = rhs.getSGrade();
    this->_egrade = rhs.getEGrade();
    this->_signed = rhs._signed;
    return *this;
}

std::string Form::getName(void)const
{
    return (this->_name);
}

int Form::getEGrade(void)const
{
    return (this->_egrade);
}

int Form::getSGrade(void)const
{
    return (this->_sgrade);
}

bool Form::getSigned(void)const
{
    return (this->_signed);
}

void    Form::beSigned(Bureaucrat const &b)
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
        std::cout << e.what() << '\n';
    }
    
}
const char * Form::GradeTooHighException::what()const throw()
{
    std::cout << magenta;
    return ("Erreur Form Too Hight");
}

const char * Form::GradeTooLowException::what()const throw()
{
    std::cout << red;
    return ("Erreur Form Too Low");
}

std::ostream & operator<<(std::ostream & o, Form const & i)
{
    o << cyan <<  i.getName() << " Form grade :" << i.getSGrade();
    return o;
}