/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Excep.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:18:23 by mel-houd          #+#    #+#             */
/*   Updated: 2024/07/29 14:19:33 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Excep.hpp"

const char*	GradeTooHighException::what() const throw()
{
	return ("Grade too high !");
}

const char*	GradeTooLowException::what() const throw()
{
	return ("Grade too low !");
}
