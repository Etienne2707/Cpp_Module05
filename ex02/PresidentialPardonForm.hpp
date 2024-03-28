#ifndef PRESIDENTIALPARDONFORM_HG
# define PRESIDENTIALPARDONFORM_HG

#include "AForm.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class PresidentialPardonForm : public Form
{
private :
    std::string _target;
    bool _signed;
    int _sgrade;
    int _egrade;
    bool _executed;
    
public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    virtual ~PresidentialPardonForm();
    PresidentialPardonForm ( PresidentialPardonForm const & src );
    PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);
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

std::ostream & operator<<( std::ostream & o, PresidentialPardonForm const & i);

#endif