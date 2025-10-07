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
  std::cout << YELLOW << "\n";

	std::cout << YELLOW << "\n=== Creating a valid Bureaucrat with grade 150 ===\n"
    << RESET << std::endl;
  std::string tName = "Obi-wan";
  try
  {
    Bureaucrat t(tName, 1);

    std::cout << "\n" << t << "\n" << std::endl;
    t.decrementGrade();
    std::cout << "\n" << t << "\n" << std::endl;
    t.incrementGrade();
    std::cout << "\n" << t << "\n" << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
	
  std::string aName = "Gabriel";
  try
	{
		Bureaucrat a(aName, 150);
    std::cout << "\n" << a << "\n" << std::endl;
    a.decrementGrade();
    std::cout << "\n" << a << "\n" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

  std::cout << YELLOW << "\n=== Creating a valid Bureaucrat with grade 1 ===\n"
    << RESET << std::endl;

  std::string dName = "Fernando";
  try
  {
    Bureaucrat d(dName, 1);
    std::cout << "\n" << d << "\n" << std::endl;
    d.incrementGrade();
    std::cout << "\n" << d << "\n" << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

	std::cout << YELLOW << "\n=== Creating a Bureaucrat with high grade exception ===\n"
    << RESET << std::endl;

	std::string bName = "Leonardo";
	try
	{
		Bureaucrat b(bName, 0);
    std::cout << b << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << YELLOW << "\n=== Creating a Bureaucrat with low grade exception ===\n"
    << RESET << std::endl;

	std::string cName = "Vinicius";
	try
	{
		Bureaucrat c(cName, 151);
    std::cout << "\n" << c << "\n" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
