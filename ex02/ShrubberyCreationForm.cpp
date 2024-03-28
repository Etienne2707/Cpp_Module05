#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
    std::cout << yellow << "Default ShrubberyCreationForm constructor call" << reset << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : _target(target)
{
    std::cout << yellow << "Parametric ShrubberyCreationForm constructor call" << reset << std::endl;
    this->_signed = false;
    this->_sgrade = 145;
    this ->_egrade = 137;
    this->_executed = false;
    
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << red << "Default Destructor call" << reset << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ){
    std::cout << "ShrubberyCreationForm Copy constructeur called" << std::endl;
    *this = src;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
    std::cout << "ShrubberyCreationForm Assignment operator called" << std::endl;
    if (this == &rhs)
        return *this;
    this->_target = rhs.getTarget();
    this->_sgrade = rhs.getSGrade();
    this->_egrade = rhs.getEGrade();
    this->_signed = rhs._signed;
    this->_executed = rhs._executed;
    return *this;
}

std::string ShrubberyCreationForm::getTarget(void)const
{
    return (this->_target);
}

int ShrubberyCreationForm::getEGrade(void)const
{
    return (this->_egrade);
}

int ShrubberyCreationForm::getSGrade(void)const
{
    return (this->_sgrade);
}

bool ShrubberyCreationForm::getSigned(void)const
{
    return (this->_signed);
}

void    ShrubberyCreationForm::beSigned(Bureaucrat const &b)
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

bool    ShrubberyCreationForm::execute(Bureaucrat const &b)const
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
            std::ofstream Ofile((_target + "_shruberry").c_str());
            if (!Ofile.is_open())
            {
                std::cout << red << "Opem FiLe Error" << reset << std::endl;
                return false;
            }
                Ofile << "    ^    " << std::endl;
                Ofile << "   / \\   " << std::endl;
                Ofile << "  /   \\  " << std::endl;
                Ofile << " /     \\ " << std::endl;
                Ofile << "/       \\" << std::endl;
                Ofile << "   |||   " << std::endl;
                return (true);
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

const char * ShrubberyCreationForm::NotSignedException::what()const throw()
{
    std::cout << magenta;
    return ("Erreur ShrubberyCreationForm not signed");
}

const char * ShrubberyCreationForm::GradeTooHighException::what()const throw()
{
    std::cout << magenta;
    return ("Erreur ShrubberyCreationForm Too Hight");
}

const char * ShrubberyCreationForm::GradeTooLowException::what()const throw()
{
    std::cout << red;
    return ("Erreur ShrubberyCreationForm Too Low");
}

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & i)
{
    o << cyan <<  i.getName() << " ShrubberyCreationForm grade :" << i.getSGrade();
    return o;
}