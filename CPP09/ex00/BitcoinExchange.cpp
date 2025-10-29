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
  if (this != &original)
    this->_data = original._data;
  return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

static int dateChecker(std::string line)
{
  time_t t;
  struct tm date = {};
  int day = 0, month = 0, year = 0;

  if (sscanf(line.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
    return (0);
  if (year < 1901 || month < 1 || month > 12 || day < 1 || day > 31)
    return (0);

  date.tm_year = year - 1900;
  date.tm_mon = month - 1;
  date.tm_mday = day;
  date.tm_hour = 12;
  date.tm_min = 30;
  date.tm_sec = 1;
  date.tm_isdst = -1;
  
  t = mktime(&date);

  if (t == -1 || date.tm_year != year - 1900
      || date.tm_mon != month - 1 || date.tm_mday != day)
    return (0);
  return (1);
}

void BitcoinExchange::extractData(std::ifstream& dataCsv)
{
  std::string line;
  std::getline(dataCsv, line);

  if (line != "date,exchange_rate")
    throw std::runtime_error("Invalid data.csv");
  while (std::getline(dataCsv, line))
  {
    std::stringstream ss(line);
    std::string date;
    double rate;

    if (!std::getline(ss, date, ','))
      continue ;
    if (!(ss >> rate))
      continue ;

    _data[date] = rate;
  }
}

void BitcoinExchange::parser(std::ifstream& infile)
{
  std::string line;
  std::getline(infile, line);

  if (line != "date | value")
    throw std::runtime_error("Invalid format");
  if (_data.empty()) 
    throw std::runtime_error("Error: database is empty");

  while (std::getline(infile, line))
  {
    try
    {
      int year, month, day;
      float val;

      if (sscanf(line.c_str(), "%d-%d-%d | %f", &year, &month, &day, &val) != 4)
        throw std::runtime_error("Bad input: " + line);
      if (val < 0.0 || val > 2147483647.0)
        throw std::runtime_error("Invalid value");

      std::string date_str = line.substr(0, 10);
      if (!dateChecker(date_str))
        throw std::runtime_error("Invalid date: " + date_str);

      std::map<std::string, float>::iterator it = _data.lower_bound(date_str);
      if (it == _data.begin() && it->first != date_str)
        throw std::runtime_error("Error: no earlier date in database");

      if (it == _data.end() || it->first != date_str)
        --it;

      float result = val * it->second;
      std::cout << date_str << " => " << val << " = " << result << std::endl;
      }
      catch (const std::exception& e)
      {
        std::cerr << RED << e.what() << RESET << std::endl;
      }
    }
}
