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

#include "Form.hpp"

int main(void)
{
  std::cout << CYAN << "=== Testing Bureaucrat with 75 grade, Form with 80 grade ===\n" << std::endl;
  try
  {
    Bureaucrat  a("Gabriel", 75);
    Form        b("Form1", 80, 80);

    b.signForm(a);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << std::endl;
  }
 
  std::cout << CYAN << "\n===  Testing Bureaucrat with 80 grade, Form with 60 grade ===\n" << std::endl;
  try
  {
    Bureaucrat  c("Leonardo", 80);
    Form        d("Form2", 60, 60);
    
    d.signForm(c);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  std::cout << CYAN << "\n===  Testing grade to low Form ===\n";
  try
  {
    Form  e("Form3", 151, 151);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << std::endl;
  }

  std::cout << CYAN << "\n===  Testing grade to high Form ===\n" << std::endl;
  try
  {
    Form  f("Form4", 0, 0);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }
	return (0);
}
