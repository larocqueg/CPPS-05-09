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
  std::srand(std::time(NULL));
  
  std::cout << CYAN << "\n=== Testing low grade to sign Bureaucrat ShrubberyCreationForm ===" << RESET << std::endl;
  try
  {
    Bureaucrat bureaucrat("Vinicius", 146);
    ShrubberyCreationForm tree("tree.txt");

    std::cout << "\n" << tree << std::endl;
    bureaucrat.signAForm(tree);
    tree.execute(bureaucrat);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  std::cout << CYAN << "\n=== Testing low grade to execute grade Bureaucrat ShrubberyCreationForm ===" << RESET << std::endl;
  try
  {
    Bureaucrat bureaucrat("Leonardo", 145);
    ShrubberyCreationForm tree("Tree.txt");

    std::cout << "\n" << tree << std::endl;
    bureaucrat.signAForm(tree);
    tree.execute(bureaucrat);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  std::cout << CYAN << "\n=== Testing high grade to sign && execute Bureaucrat ShrubberyCreationForm ===" << RESET << std::endl;
  try
  {
    Bureaucrat  bureaucrat("Gabriel", 130);
    ShrubberyCreationForm tree("tree.txt");

    std::cout << "\n" << tree << std::endl;
    bureaucrat.signAForm(tree);
    tree.execute(bureaucrat);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << std::endl;
  }

  std::cout << CYAN << "\n=== Testing low grade to sign Bureaucrat RobotomyRequestForm ===" << RESET << std::endl;
  try
  {
    Bureaucrat bureaucrat("Fernando", 73);
    RobotomyRequestForm robot("Cortana");

    std::cout << "\n" << robot << std::endl;
    bureaucrat.signAForm(robot);
    robot.execute(bureaucrat);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  std::cout << CYAN << "\n=== Testing low grade to execute grade Bureaucrat RobotomyRequestForm ===" << RESET << std::endl;
  try
  {
    Bureaucrat bureaucrat("Leonardo", 46);
    RobotomyRequestForm robot("Cortana");

    std::cout << "\n" << robot << std::endl;
    bureaucrat.signAForm(robot);
    robot.execute(bureaucrat);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  std::cout << CYAN << "\n=== Testing high grade to sign && execute Bureaucrat RobotomyRequestForm ===" << RESET << std::endl;
  try
  {
    Bureaucrat  bureaucrat("Gabriel", 45);
    RobotomyRequestForm robot("Cortana");

    std::cout << "\n" << robot << std::endl;
    bureaucrat.signAForm(robot);
    robot.execute(bureaucrat);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << std::endl;
  }
  
  std::cout << CYAN << "\n=== Testing low grade to sign Bureaucrat PresidentialPardonForm ===" << RESET << std::endl;
  try
  {
    Bureaucrat bureaucrat("Fernando", 26);
    PresidentialPardonForm president("Bolsonaro");

    std::cout << "\n" << president << std::endl;
    bureaucrat.signAForm(president);
    president.execute(bureaucrat);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  std::cout << CYAN << "\n=== Testing low grade to execute grade Bureaucrat PresidentialPardonForm ===" << RESET << std::endl;
  try
  {
    Bureaucrat bureaucrat("Leonardo", 25);
    PresidentialPardonForm president("tree.txt");

    std::cout << "\n" << president << std::endl;
    bureaucrat.signAForm(president);
    president.execute(bureaucrat);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  std::cout << CYAN << "\n=== Testing high grade to sign && execute Bureaucrat PresidentialPardonForm ===" << RESET << std::endl;
  try
  {
    Bureaucrat  bureaucrat("Gabriel", 1);
    PresidentialPardonForm president("gde-la-r");

    std::cout << "\n" << president << std::endl;
    bureaucrat.signAForm(president);
    president.execute(bureaucrat);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << std::endl;
  }

  std::cout << std::endl;
	return (0);
}
