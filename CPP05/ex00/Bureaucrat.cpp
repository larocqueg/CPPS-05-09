/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 19:05:43 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/03 19:05:44 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("Default")
{
  std::cout << GREEN << "Bureaucrat default constructor called!"
    << RESET << std::endl;
  _grade = 150;
}

Bureaucrat::Bureaucrat(std::string& name, unsigned int grade) : _name(name)
{
	if (grade < 1)
		throw gradeTooHighException();
	if (grade > 150)
		throw gradeTooLowException();
	_grade = grade;
	std::cout << GREEN << "Bureaucrat " << _name << " parameterized constructor called!"
    << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& original) : _name(original._name)
{
	_grade = original._grade;
	std::cout << GREEN << "Bureaucrat " << _name << " copy constructor called!"
    << RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& original)
{
	if (this != &original)
		_grade = original._grade;
	std::cout << GREEN << "Bureaucrat " << _name << " copy assignment operator called!"
    << RESET << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Bureaucrat " << _name << " destructor called!"
    << RESET << std::endl;
}

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw cannotIncrementException();
  std::cout << GREEN << "Bureaucrat " << this->_name << " grade was incremented by 1!"
  << RESET << std::endl;
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw cannotDecrementException();
  std::cout << GREEN << "Bureaucrat " << this->_name << " grade was decremented by 1!"
  << RESET << std::endl;
	_grade++;
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (_grade);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
  os << bureaucrat.getName() << ", bureacrat grade " << bureaucrat.getGrade();
  return (os);
}
