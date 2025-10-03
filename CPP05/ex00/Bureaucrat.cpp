#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("Default")
{
  std::cout << CYAN << "Bureaucrat default constructor called!"
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
	std::cout << CYAN << "Bureaucrat " << _name << " parameterized constructor called!"
    << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& original) : _name(original._name)
{
	_grade = original._grade;
	std::cout << CYAN << "Bureaucrat " << _name << " copy constructor called!"
    << RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& original)
{
	if (this != &original)
		_grade = original._grade;
	std::cout << CYAN << "Bureaucrat " << _name << " copy assignment operator called!"
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
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw cannotDecrementException();
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
