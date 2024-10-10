/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Funcs.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 00:03:34 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/10 08:20:56 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCS_HPP
#define FUNCS_HPP

#include <iostream>
#include <string>


//class Test {

//};

template<typename T>
void swap(T& var1, T& var2) {
    T tmp = var1;
    var1 = var2;
    var2 = tmp;
}

template<typename T>
T&	min(T& var1, T& var2) {
	if (var1 < var2)
		return var1;
	return var2;
}

template<typename T>
T&	max(T& var1, T& var2) {
	if (var1 > var2)
		return var1;
	return var2;
}

#endif