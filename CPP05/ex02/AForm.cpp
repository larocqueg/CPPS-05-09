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
    std::cout << YELLOW << "AForm " << this->_name << " constructor called!" << RESET << std::endl;
}

AForm::AForm(const std::string& name, unsigned int toSign, unsigned int toExec) 
    : _name(name), _signGrade(toSign), _execGrade(toExec), _signed(false)
{
    std::cout << YELLOW << "AForm " << this->_name << " parameterized constructor called!" << RESET << std::endl;

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
    std::cout << YELLOW << "AForm " << this->_name << " copy constructor called!" << RESET << std::endl;
}

AForm& AForm::operator=(const AForm& original)
{
    if (this != &original)
        this->_signed = original._signed;
    return (*this);
}

AForm::~AForm()
{
    std::cout << RED << "AForm " << this->_name << " destructor called!" << RESET << std::endl;
}

void AForm::signAForm(const Bureaucrat& b)
{
    if (this->_signed)
    {
        std::cerr << "AForm: is already signed!" << std::endl;
    }
    else if (b.getGrade() > this->_signGrade)
    {
        throw AForm::gradeTooLowException(
            "Bureaucrat " + b.getName() + " couldn't sign " + this->_name + " because grade is too low!"
        );
    }
    else
    {
        std::cout << GREEN << b.getName() << " successfully signed !" this->_name << std::endl;
        this->_signed = true;
    }
}

unsigned int AForm::getGrade() const
{
    return (_signGrade);
}

const std::string& AForm::getName() const
{
    return (_name);
}
