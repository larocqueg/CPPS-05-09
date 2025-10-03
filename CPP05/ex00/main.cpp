/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 19:12:40 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/03 19:12:41 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << YELLOW << "=== Creating a valid Bureaucrat with grade 150 ==="
    << RESET << std::endl;
	
  std::string aName = "Gabriel";
  try
	{
		Bureaucrat a(aName, 150);
		std::cout << CYAN << "Bureaucrat " << a.getName() << " grade is " << a.getGrade()
      << RESET << std::endl;
    a.decrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

  std::cout << YELLOW << "\n=== Creating a valid Bureaucrat with grade 1 ==="
    << RESET << std::endl;

  std::string dName = "Fernando";
  try
  {
    Bureaucrat d(dName, 1);
    std::cout << CYAN << "Bureaucrat " << d.getName() << " grade is " << d.getGrade()
      << RESET << std::endl;
    d.incrementGrade();
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

	std::cout << YELLOW << "\n=== Creating a Bureaucrat with high grade exception ==="
    << RESET << std::endl;

	std::string bName = "Leonardo";
	try
	{
		Bureaucrat b(bName, 0);
		std::cout << CYAN << "Bureaucrat " << b.getName() << " grade is " << b.getGrade()
      << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << YELLOW << "\n=== Creating a Bureaucrat with low grade exception ==="
    << RESET << std::endl;

	std::string cName = "Vinicius";
	try
	{
		Bureaucrat c(cName, 151);
		std::cout << CYAN << "Bureaucrat " << c.getName() << " grade is " << c.getGrade()
      << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
