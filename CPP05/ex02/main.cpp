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
  std::cout << CYAN << "=== Testing high grade Bureaucrat with PresidentialPardonForm ===\n" << std::endl;
  try
  {
    Bureaucrat  a("Gabriel", 1);
    PresidentialPardonForm president("Lula");

    president.signAForm(a);
    president.execute(a);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << std::endl;
  }

  std::cout << CYAN << "\n=== Testing low grade Bureaucrat with PresidentialPardonForm ===\n" << std::endl;
  try
  {
    Bureaucrat a("Fernando", 26);
    PresidentialPardonForm president("Bolsonaro");

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
