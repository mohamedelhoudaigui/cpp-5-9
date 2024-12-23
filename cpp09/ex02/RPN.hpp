/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 22:58:43 by mel-houd          #+#    #+#             */
/*   Updated: 2024/12/22 23:17:44 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RNP_HPP
#define RNP_HPP

#include <string>
#include <stack>
#include <iostream>
#include <sstream>

class   RNP
{
	public:
		RNP();
		~RNP();
		RNP(const RNP & other);
		RNP & operator=(const RNP & other);

		void	Parse(const char* input);
		void	Execute();
		void	Alaram(const std::string error);

		const std::stack<int>&	GetInput() const;

	private:
		std::stack<int>	Input;

};


#endif