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

  std::cout << YELLOW << "\n\nCreating Span with ranged addNumber" << RESET;
  try
  {
    Span sp2 = Span(11);
    sp2.addNumber(-5, 5);
    sp2.printVector();
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }
  if (ac >= 2)
  {
    int num;
    for (int i = 1; i < ac; i++)
    {
      num = std::atoi(av[i]);
      
      if (num != 0)
      {
        std::cout << YELLOW << "\n\nSpan with argv[" << i
          << "] range" << RESET << std::endl;
      }
      else
      {
        std::cerr << RED << "\nInvalid range for argv[" << i
          << "]: It needs to be != 0" << RESET << std::endl;
      }
      Span sav = Span(abs(num));
      try
      {
        sav.addNumber(0, num);
        sav.printVector();
      }
      catch(const std::exception& e)
      {
        std::cerr << RED << e.what() << RESET << std::endl;
      }
    }
  }
  return (0);
}
