/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:45:55 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/29 17:01:15 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <sstream>
#include <stack>
#include <cctype>
#include <cstdlib>

#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

class RPN
{
  public:
    RPN();
    RPN(const RPN& original);
    RPN& operator=(const RPN& original);
    ~RPN();
    void  parser(const std::string& str);
    void  doOp(const std::string& str);
};
