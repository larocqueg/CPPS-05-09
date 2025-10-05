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

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
  std::cout << CYAN << "=== Testing Bureaucrat with 75 grade, AForm with 80 grade ===\n" << std::endl;
  try
  {
    Bureaucrat  a("Gabriel", 75);
    AForm        b("AForm1", 80, 80);

    b.signAForm(a);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << std::endl;
  }
 
  std::cout << CYAN << "\n===  Testing Bureaucrat with 80 grade, AForm with 60 grade ===\n" << std::endl;
  try
  {
    Bureaucrat  c("Leonardo", 80);
    AForm        d("AForm2", 60, 60);
    
    d.signAForm(c);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  std::cout << CYAN << "\n===  Testing grade to low AForm ===\n";
  try
  {
    AForm  e("AForm3", 151, 151);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << std::endl;
  }

  std::cout << CYAN << "\n===  Testing grade to high AForm ===\n" << std::endl;
  try
  {
    AForm  f("AForm4", 0, 0);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }
  std::cout << std::endl;
	return (0);
}
