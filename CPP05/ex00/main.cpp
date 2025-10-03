/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.cpp										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gde-la-r <gde-la-r@student.42porto.com>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/10/03 12:19:16 by gde-la-r		  #+#	#+#			 */
/*   Updated: 2025/10/03 12:26:37 by gde-la-r		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << YELLOW << "=== Creating a valid Bureaucrat ==="
    << RESET << std::endl;
	
  std::string aName = "Gabriel";
  try
	{
		Bureaucrat a(aName, 150);
		std::cout << GREEN << "Bureaucrat " << a.getName() << " grade is " << a.getGrade()
      << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << YELLOW << "=== Creating a Bureaucrat with high grade exception ==="
    << RESET << std::endl;

	std::string bName = "Leonardo";
	try
	{
		Bureaucrat b(bName, 0);
		std::cout << GREEN << "Bureaucrat " << b.getName() << " grade is " << b.getGrade()
      << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << YELLOW << "=== Creating a Bureaucrat with low grade exception ==="
    << RESET << std::endl;

	std::string cName = "Vinicius";
	try
	{
		Bureaucrat c(cName, 151);
		std::cout << GREEN << "Bureaucrat " << c.getName() << " grade is " << c.getGrade()
      << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
