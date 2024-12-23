/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 22:58:43 by mel-houd          #+#    #+#             */
/*   Updated: 2024/12/23 05:08:59 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <stdlib.h>


class   RPN
{
	public:
		RPN();
		~RPN();
		RPN(const RPN & other);
		RPN & operator=(const RPN & other);

		void	Parse(const char* input);
		void	Execute();
		void	Alaram(const std::string error);

		const std::stack<int>&	GetInput() const;

	private:
		std::stack<int>	Input;

};


#endif