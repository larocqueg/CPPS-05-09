/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:41:35 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/14 17:59:50 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

class Base
{
  public:
    virtual ~Base();
};
