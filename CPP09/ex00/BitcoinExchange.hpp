/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:14:46 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/28 11:15:07 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <iostream>
#include <ifstream>
#include <ctype.h>
#include <climits>

#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

class BitcoinExchange
{
  private:
    std::map<std::string, float> _data;
  public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& original);
    BitcoinExchange& operator=(const BitcoinExchange& original);
    ~BitcoinExchange();
    void extractData(std::ifstream dataCsv);
    void parser(std::ifstream infile);
}
