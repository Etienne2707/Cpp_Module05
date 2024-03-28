#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
    std::cout << yellow << "Default RobotomyRequestForm constructor call" << reset << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : _target(target)
{
    std::cout << yellow << "Parametric RobotomyRequestForm constructor call" << reset << std::endl;
    this->_signed = false;
    this->_sgrade = 72;
    this ->_egrade = 45;
    this->_executed = false;
    
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << red << "Default Destructor call" << reset << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ){
    std::cout << "RobotomyRequestForm Copy constructeur called" << std::endl;
    *this = src;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
    std::cout << "RobotomyRequestForm Assignment operator called" << std::endl;
    if (this == &rhs)
        return *this;
    this->_target = rhs.getTarget();
    this->_sgrade = rhs.getSGrade();
    this->_egrade = rhs.getEGrade();
    this->_signed = rhs._signed;
    this->_executed = rhs._executed;
    return *this;
}

std::string RobotomyRequestForm::getTarget(void)const
{
    return (this->_target);
}

int RobotomyRequestForm::getEGrade(void)const
{
    return (this->_egrade);
}

int RobotomyRequestForm::getSGrade(void)const
{
    return (this->_sgrade);
}

bool RobotomyRequestForm::getSigned(void)const
{
    return (this->_signed);
}

void    RobotomyRequestForm::beSigned(Bureaucrat const &b)
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

bool    RobotomyRequestForm::execute(Bureaucrat const &b)const
{
    int i;
    srand (time(NULL));

    std::string file = this->_target + "_shruberry";
    try
    {
        if (b.getGrade() > this->_egrade)
            throw GradeTooLowException();
        if (this->_signed == false)
            throw NotSignedException();
        else
        {
            i = rand() % 2 + 1;
            if ( i == 2)
            {
                std::cout << this->_target << " has been robotomized succesfully !" << std::endl;
                return true;
            }
            return false;
                
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

const char * RobotomyRequestForm::NotSignedException::what()const throw()
{
    std::cout << magenta;
    return ("Erreur RobotomyRequestForm not signed");
}

const char * RobotomyRequestForm::GradeTooHighException::what()const throw()
{
    std::cout << magenta;
    return ("Erreur RobotomyRequestForm Too Hight");
}

const char * RobotomyRequestForm::GradeTooLowException::what()const throw()
{
    std::cout << red;
    return ("Erreur RobotomyRequestForm Too Low");
}

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & i)
{
    o << cyan <<  i.getName() << " RobotomyRequestForm grade :" << i.getSGrade();
    return o;
}