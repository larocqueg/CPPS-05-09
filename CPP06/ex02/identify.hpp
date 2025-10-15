/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:04:12 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/14 18:05:40 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ctime>
#include <string>
#include <cstdlib>
#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base  *generate(void);
void  identify(Base* p);
void  identify(Base& p);
