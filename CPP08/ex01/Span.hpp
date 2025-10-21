/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:29:46 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/21 21:43:07 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Span
{
  private:
    Span();
    unsigned int  _N;
    std::vector<unsigned int> _values;
  public:
    Span(const Span& original);
    Span&         operator=(const Span& original);
    void          addNumber(unsigned int n);
    unsigned int  shortestSpan();
    unsigned int  longestSpan();
};
