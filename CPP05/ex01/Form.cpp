/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 11:17:06 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/05 11:24:31 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() 
    : _name("Default"), _signGrade(150), _execGrade(150), _signed(false)
{
    std::cout << YELLOW << "Form " << this->_name << " constructor called!" << RESET << std::endl;
}

Form::Form(const std::string& name, unsigned int toSign, unsigned int toExec) 
    : _name(name), _signGrade(toSign), _execGrade(toExec), _signed(false)
{
    std::cout << YELLOW << "Form " << this->_name << " parameterized constructor called!" << RESET << std::endl;

    if (name.empty())
        std::cerr << RED << "Form: no name given!" << std::endl;
    else if (toSign > 150 || toExec > 150)
        throw Form::gradeTooLowException("Form: grade is too low!");
    else if (toSign < 1 || toExec < 1)
        throw Form::gradeTooHighException("Form: grade is too high!");
}

Form::Form(const Form& original) 
    : _name(original._name), _signGrade(original._signGrade), _execGrade(original._execGrade), _signed(original._signed)
{
    std::cout << YELLOW << "Form " << this->_name << " copy constructor called!" << RESET << std::endl;
}

Form& Form::operator=(const Form& original)
{
    if (this != &original)
        this->_signed = original._signed;
    return (*this);
}

Form::~Form()
{
    std::cout << RED << "Form " << this->_name << " destructor called!" << RESET << std::endl;
}

void Form::signForm(const Bureaucrat& b)
{
    if (this->_signed)
    {
        std::cerr << "Form: is already signed!" << std::endl;
    }
    else if (b.getGrade() > this->_signGrade)
    {
        throw Form::gradeTooLowException(
            "Bureaucrat " + b.getName() + " couldn't sign " + this->_name + " because grade is too low!"
        );
    }
    else
    {
        std::cout << GREEN << b.getName() << " successfully signed " << this->_name << std::endl;
        this->_signed = true;
    }
}

unsigned int Form::getGrade() const
{
    return (_signGrade);
}

unsigned int Form::getEGrade() const
{
  return (_execGrade);
}

const std::string& Form::getName() const
{
    return (_name);
}

bool  Form::isSigned() const
{
  return (_signed);
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << YELLOW "Form name: " <<  RESET << form.getName() << std::endl 
       << YELLOW "Signed: " << RESET << (form.isSigned() ? "true" : "false" ) << std::endl
       << YELLOW "Grade to sign: " << RESET << form.getGrade() << std::endl
       << YELLOW "Grade to execute: " << RESET << form.getEGrade() << std::endl;
    return (os);
}
