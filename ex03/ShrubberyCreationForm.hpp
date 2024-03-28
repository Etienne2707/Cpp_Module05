#ifndef SHRUBERRYCREATIONFORM_H
#define SHRUBERRYCREATIONFORM_H

#include "AForm.hpp"


class ShrubberyCreationForm : public Form
{
private :
    std::string _target;
    bool _signed;
    int _sgrade;
    int _egrade;
    bool _executed;
    
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm ( ShrubberyCreationForm const & src );
    ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);
    void    beSigned(const Bureaucrat & b);
    std::string getTarget()const;
    int getSGrade()const;
    int getEGrade()const;
    bool getSigned(void)const;
    bool execute(Bureaucrat const & executor)const;
    void print_asciiTrees(std::ofstream &Ofile);
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
    class NotSignedException : public  std::exception
    {
        public :
            NotSignedException() throw() {};
            virtual const char* what() const throw();
            virtual ~NotSignedException() throw(){};
    };
    

};

std::ostream & operator<<( std::ostream & o, ShrubberyCreationForm const & i);

#endif