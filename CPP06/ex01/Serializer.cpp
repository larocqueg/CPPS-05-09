/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:52:42 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/14 14:57:44 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer& original)
{
  (void)original;
}

Serializer& Serializer::operator=(const Serializer& original)
{
  (void)original;
  return (*this);
}

Serializer::~Serializer()
{
}

uintptr_t  Serializer::serialize(Data* ptr)
{
  return (reinterpret_cast<uintptr_t>(ptr));
}

Data*  Serializer::deserialize(uintptr_t raw)
{
  return (reinterpret_cast<Data*>(raw));
}
