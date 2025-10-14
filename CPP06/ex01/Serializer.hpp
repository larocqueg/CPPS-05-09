/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 17:57:19 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/11 18:03:43 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <stdint.h>

#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

class Serializer
{
  private:
    Serializer();
    Serializer(const Serializer& original);
    Serializer& operator=(const Serializer& original);
    ~Serializer();
  public:
    static uintptr_t serialize(Data* ptr);
    static Data*     deserialize(uintptr_t raw);
};
