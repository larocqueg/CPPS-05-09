/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 11:17:06 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/05 11:24:31 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() 
    : _name("Default"), _signGrade(150), _execGrade(150), _signed(false)
{
}

AForm::AForm(const std::string& name, unsigned int toSign, unsigned int toExec) 
    : _name(name), _signGrade(toSign), _execGrade(toExec), _signed(false)
{

    if (name.empty())
        std::cerr << RED << "AForm: no name given!" << std::endl;
    else if (toSign > 150 || toExec > 150)
        throw AForm::gradeTooLowException("AForm: grade is too low!");
    else if (toSign < 1 || toExec < 1)
        throw AForm::gradeTooHighException("AForm: grade is too high!");
}

AForm::AForm(const AForm& original) 
    : _name(original._name), _signGrade(original._signGrade), _execGrade(original._execGrade), _signed(original._signed)
{
}

AForm& AForm::operator=(const AForm& original)
{
    if (this != &original)
        this->_signed = original._signed;
    return (*this);
}

AForm::~AForm()
{
}

void AForm::beSigned(const Bureaucrat& b)
{
    if (this->_signed)
    {
        std::cerr << "AForm: is already signed!" << std::endl;
    }
    else if (b.getGrade() > this->_signGrade)
    {
        throw AForm::gradeTooLowException(
            "Bureaucrat " + b.getName() + " couldn't sign " + this->_name + ", grade is too low!");
    }
    else
    {
        std::cout << GREEN << b.getName() << " successfully signed " << this->_name << std::endl;
        this->_signed = true;
    }
}


void  AForm::execute(const Bureaucrat& b) const
{
  if (b.getGrade() > this->_execGrade)
  {
    throw AForm::gradeTooLowException(
        "Bureaucrat " + b.getName() + " couldn't execute " + this->_name + ", grade is to low!");
  }
  else if (!this->_signed)
  {
    throw AForm::formNotSignedException(
        "Bureaucrat " + b.getName() + " couldn't execute " + this->_name + " because the Form is not signed!");
  }
  else
    std::cout << "Form " << this->_name << " was executed by " << b.getName() << std::endl;
}

unsigned int AForm::getSignGrade() const
{
    return (this->_signGrade);
}

unsigned int  AForm::getExecGrade() const
{
  return (this->_execGrade);
}

const std::string& AForm::getName() const
{
    return (this->_name);
}

bool  AForm::getSign() const
{
  return (this->_signed);
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << YELLOW "AForm name: " <<  RESET << form.getName() << std::endl 
       << YELLOW "Signed: " << RESET << (form.getSign() ? "true" : "false" ) << std::endl
       << YELLOW "Grade to sign: " << RESET << form.getSignGrade() << std::endl
       << YELLOW "Grade to execute: " << RESET << form.getExecGrade() << std::endl;
    return (os);
}
