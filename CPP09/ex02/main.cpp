/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:00:12 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/31 15:07:35 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
  if (ac < 2)
  {
    std::cerr << RED << "Error: Usage: ./PmergeMe \"n1\" \"n2\" ..."
      << RESET << std::endl;
    return (1);
  }

  try
  {
    PmergeMe merge;
    for (int i = 1; i < ac; i++)
      merge.parser(av[i]);
    merge.printVector();
    //merge.sort();
  }
  catch (const std::exception& e)
  {
    std:: cerr << RED << "Error: " << e.what() << RESET << std::endl;
  }
}
