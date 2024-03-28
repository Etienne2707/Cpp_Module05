#include "Bureaucrat.hpp"
#include "AForm.hpp"


Bureaucrat::Bureaucrat()
{
    std::cout << yellow <<  "Default Bureaucrat Constructeur Call" << reset << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    std::cout << yellow << "Parametric Bureaucrat Contructeur Call" << reset << std::endl;
    try
    {
        if (this->_grade < 1)
            throw GradeTooHighException();
        else if (this->_grade > 150)
            throw GradeTooHighException();

    }
    catch(GradeTooHighException & e)
    {
        std::cout << e.what() << '\n' << reset;
        this->_grade = 1;
    }
    catch (GradeTooLowException & e)
    {
        std::cout << e.what() << '\n' << reset;
        this->_grade = 150;
    }

    
}

Bureaucrat::~Bureaucrat()
{
    std::cout << red << "Destructor Call" << reset << std::endl;
}

std::string Bureaucrat::getName( void )const
{
    return (this->_name);
}

int Bureaucrat::getGrade(void)const
{
    return (this->_grade);
}

void    Bureaucrat::Increment_Grade(void)
{
    try
    {
        if (this->_grade - 1 < 1)
            throw GradeTooHighException();
        else if (this->_grade - 1 > 150)
            throw GradeTooLowException();
        else
            this->_grade--;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void    Bureaucrat::Decrement_Grade(void)
{
    try
    {
        if (this->_grade + 1 < 1)
            throw GradeTooHighException();
        else if (this->_grade + 1 > 150)
            throw GradeTooLowException();
        else
            this->_grade++;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    


}

void    Bureaucrat::signForm(Form &f)const
{
    f.beSigned(*this);
    if (f.getSigned() == false)
    {
        std::cout << red << this->_name << "Couldn't make this form : " << f.getName() << "reseaon : To Low" << reset << std::endl;
    }
    else
    {
        std::cout << green << this->_name << " Make  this form : " << f.getName() << reset << std::endl;
    }

}

void Bureaucrat::executeForm(Form const & form)const
{
    if (form.execute(*this) == false)
    {
        std::cout << red << this->_name << "Couldn't make this form : " << form.getName() << "reseaon : To Low" << reset << std::endl;
    }
    else
    {
        std::cout << green << this->_name << " Make  this form : " << form.getName() << reset << std::endl;
    }

}

Bureaucrat::Bureaucrat( Bureaucrat const & src ){
    std::cout << "Bureaucrat Copy constructeur called" << std::endl;
    *this = src;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
    std::cout << "Bureaucrat Assignment operator called" << std::endl;
    this->_grade = rhs.getGrade();
    this->_name = rhs.getName();
    return *this;
}

const char * Bureaucrat::GradeTooHighException::what()const throw()
{
    std::cout << magenta;
    return ("Erreur Too Hight Your Grade Is Set To 1 ");
}

const char * Bureaucrat::GradeTooLowException::what()const throw()
{
    std::cout << red;
    return ("Erreur Too Low Your Grade Is Set To 150 ");
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & i)
{
    o << cyan <<  i.getName() << " bureaucrat grade :" << i.getGrade();
    return o;
}









