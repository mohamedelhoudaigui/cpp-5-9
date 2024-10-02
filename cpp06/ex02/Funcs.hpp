/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Funcs.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:47:41 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/02 19:07:14 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCS_HPP
#define FUNCS_HPP

#include "Base.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif