/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:18:30 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/22 19:07:24 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <vector>


template<typename T>
typename T::iterator easyfind(T& container, int num)
{
	T::iterator res = find(container.begin(), container.end(), num);
	if (res = container.end())
		throw std::runtime_error("value not found");
	return (res);
}


#endif