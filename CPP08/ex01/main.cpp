/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:48:39 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/22 14:49:26 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(int ac, char **av)
{
  Span sp = Span(5);
  
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  
  std::cout << YELLOW << "\nPrinting vector" << RESET << std::endl;
  sp.printVector();
  std::cout << std::endl;

  std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
  std::cout << "longestSpan = " << sp.longestSpan() << std::endl;
  std::cout << std::endl;

  std::cout << YELLOW << "\n\nTrying to add number bigger than INT_MAX" << RESET << std::endl;
  try
  {
    sp.addNumber(2147483648);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  std::cout << YELLOW << "\n\nCreating Span of size 10 and trying to give a range > than 10" << RESET << std::endl;
  try
  {
    Span test = Span(10);
    sp.addNumber(0, 10);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  if (ac == 2)
  {
    int range = std::atoi(av[1]);
    std::cout << YELLOW << "\n\nCreating a new Span and adding numbers with the addNumber with 2 params" << RESET << std::endl;
    Span sp2 = Span(range);
    try
    {
      sp2.addNumber(0, range - 1);
      sp2.printVector();
      std::cout << YELLOW << "\n\nTrying to add a number to a full Span" << RESET << std::endl;
      sp2.addNumber(10);
    }
    catch (const std::exception& e)
    {
       std::cerr << RED << e.what() << RESET << std::endl;
    }
  }
  return (0);
}
