#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
#include <string>

const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

class Form;

class Bureaucrat
{
private:
    std::string _name;
    int _grade;
public:

    //Constructeur
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    //Destructeur
    ~Bureaucrat();    
    Bureaucrat( Bureaucrat const & src );
    Bureaucrat & operator=(Bureaucrat const & rhs);
    //Fonction membres
    std::string getName( void )const;
    int getGrade(void)const;
    void    signForm(Form &f)const;
    void executeForm(Form const & form)const;

    class GradeTooHighException : public  std::exception
    {
        public :
            GradeTooHighException() throw() {};
            virtual const char* what() const throw();
            virtual ~GradeTooHighException() throw(){};
    };
    class GradeTooLowException : public  std::exception
    {
        public :
            GradeTooLowException() throw() {};
            virtual const char* what() const throw();
            virtual ~GradeTooLowException() throw(){};
    };
    void    Increment_Grade(void);
    void    Decrement_Grade(void) ;
};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & i);

#endif