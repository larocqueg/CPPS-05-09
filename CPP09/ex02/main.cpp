/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:57:26 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/11/05 14:59:27 by gde-la-r         ###   ########.fr       */
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
    merge.sorting();
  }
  catch (const std::exception& e)
  {
    std:: cerr << RED << "Error: " << e.what() << RESET << std::endl;
  }
}
