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
#include <stack>
#include <cctype>

class RPN
{
  public:
    RPN();
    RPN(const RPN& original);
    RPN& operator=(const RPN& original);
    ~RPN();
    void  parser(const std::string& str);
    void  doOp(const std::string& str);
}
