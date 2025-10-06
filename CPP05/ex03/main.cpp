/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 10:47:35 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/06 10:48:06 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main(void)
{
  std::srand(std::time(NULL));
  Intern *souless = new Intern();
  AForm *one = NULL;
  AForm *two = NULL;
  AForm *three = NULL;
  AForm *four = NULL;
  Bureaucrat a("Gabriel", 1);

  std::cout << CYAN << "\n=== Testing invalid Form name via Intern ===\n" << RESET << std::endl;
  try
  {
    one = souless->makeForm("42", "Norminette");
    one->signAForm(a);
    one->execute(a);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  std::cout << CYAN << "\n=== Testing ShrubberyCreationForm via Intern ===\n" << RESET << std::endl;
  try
  {
    two = souless->makeForm("ShrubberyCreationForm", "Tree.txt");
    two->signAForm(a);
    two->execute(a);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  std::cout << CYAN << "\n=== Testing PresidentialPardonForm via Intern ===\n" << RESET << std::endl;
  try
  {
    three = souless->makeForm("PresidentialPardonForm", "Lula");
    three->signAForm(a);
    three->execute(a);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  std::cout << CYAN << "\n=== Testing RobotomyRequestForm via Intern ===\n" << RESET << std::endl;
  try
  {
    four = souless->makeForm("RobotomyRequestForm", "Cortana");
    four->signAForm(a);
    four->execute(a);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }
  std::cout << std::endl;
  
  delete one;
  delete two;
  delete three;
  delete four;
  delete souless;

  return (0);
}
