/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:10:47 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/28 11:11:06 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
  BitcoinExchange bitcoin;
  std::ifstream infile;
  std::ifstream dataCsv;

  if (ac != 2)
  {
    std::cerr << RED << "Error: Usage: ./btc <filename>" << RESET << std::endl;
    return (1);
  }

  dataCsv.open("data.csv");
  if (!dataCsv.is_open())
  {
    std::cerr << RED << "Error: could not open data.csv" << RESET << std::endl;
    return (1);
  }

  infile.open(av[1]);
  if (!infile.is_open())
  {
    std::cerr << RED << "Error: could not open " << av[1] << RESET << std::endl;
    return (1);
  }

  try
  {
    bitcoin.extractData(dataCsv);
    bitcoin.parser(infile);
  }
  catch (const std::exception &e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
    return (1);
  }
  return (0);
}

