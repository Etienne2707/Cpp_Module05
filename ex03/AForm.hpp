#ifndef AFORM_H
# define AFORM_H

#include <fstream>
#include "Bureaucrat.hpp"

class Form : public Bureaucrat
{
private :
    std::string _name;
    bool _signed;
    int _sgrade;
    int _egrade;
protected :
    Form();
    Form(std::string name,int sgrade,int egrade);
public:
    virtual ~Form();
    Form ( Form const & src );
    Form & operator=(Form const & rhs);
    void    beSigned(const Bureaucrat & b);
    std::string getName()const;
    int getSGrade()const;
    int getEGrade()const;
    bool getSigned(void)const;
    virtual bool execute(Bureaucrat const & executor) const = 0;
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
    

};

std::ostream & operator<<( std::ostream & o, Form const & i);

#endif