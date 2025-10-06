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

  std::cout << CYAN << "\n=== Testing low grade to sign Bureaucrat ShrubberyCreationForm ===" << RESET << std::endl;
  try
  {
    Bureaucrat a("Vinicius", 146);
    ShrubberyCreationForm three("Three.txt");

    three.signAForm(a);
    three.execute(a);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  std::cout << CYAN << "\n=== Testing low grade to execute grade Bureaucrat ShrubberyCreationForm ===" << RESET << std::endl;
  try
  {
    Bureaucrat a("Leonardo", 145);
    ShrubberyCreationForm three("Three.txt");

    three.signAForm(a);
    three.execute(a);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  std::cout << CYAN << "\n=== Testing high grade to sign && execute Bureaucrat ShrubberyCreationForm ===" << RESET << std::endl;
  try
  {
    Bureaucrat  a("Gabriel", 130);
    ShrubberyCreationForm three("Three.txt");

    three.signAForm(a);
    three.execute(a);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << std::endl;
  }

  std::cout << CYAN << "\n=== Testing low grade to sign Bureaucrat RobotomyRequestForm ===" << RESET << std::endl;
  try
  {
    Bureaucrat a("Fernando", 73);
    RobotomyRequestForm robot("Cortana");

    robot.signAForm(a);
    robot.execute(a);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  std::cout << CYAN << "\n=== Testing low grade to execute grade Bureaucrat RobotomyRequestForm ===" << RESET << std::endl;
  try
  {
    Bureaucrat a("Leonardo", 46);
    RobotomyRequestForm robot("Cortana");

    robot.signAForm(a);
    robot.execute(a);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  std::cout << CYAN << "\n=== Testing high grade to sign && execute Bureaucrat RobotomyRequestForm ===" << RESET << std::endl;
  try
  {
    Bureaucrat  a("Gabriel", 45);
    RobotomyRequestForm robot("Cortana");

    robot.signAForm(a);
    robot.execute(a);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << std::endl;
  }
  
  std::cout << CYAN << "\n=== Testing low grade to sign Bureaucrat PresidentialPardonForm ===" << RESET << std::endl;
  try
  {
    Bureaucrat a("Fernando", 26);
    PresidentialPardonForm president("Bolsonaro");

    president.signAForm(a);
    president.execute(a);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  std::cout << CYAN << "\n=== Testing low grade to execute grade Bureaucrat PresidentialPardonForm ===" << RESET << std::endl;
  try
  {
    Bureaucrat a("Leonardo", 25);
    PresidentialPardonForm president("three.txt");

    president.signAForm(a);
    president.execute(a);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  std::cout << CYAN << "\n=== Testing high grade to sign && execute Bureaucrat PresidentialPardonForm ===" << RESET << std::endl;
  try
  {
    Bureaucrat  a("Gabriel", 1);
    PresidentialPardonForm president("gde-la-r");

    president.signAForm(a);
    president.execute(a);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << std::endl;
  }

  std::cout << std::endl;
	return (0);
}
