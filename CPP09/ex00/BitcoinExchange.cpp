/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:14:36 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/28 11:14:41 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& original)
{
  *this = original;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& original)
{
  if (*this != original)
  {
    this->_data = original._data;
  }
  return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::extractData(std::ifstream dataCsv)
{
}

void BitcoinExchange::parser(std::ifstream infile)
{
}
