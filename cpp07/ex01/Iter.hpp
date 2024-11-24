/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:23:21 by mel-houd          #+#    #+#             */
/*   Updated: 2024/11/23 01:06:24 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template<typename T, typename F>
void	iter(T* ArrAdrr, int ArrSize, void (*Func)(F&))
{
	if (!ArrAdrr || !Func)
		return ;
	for (int i = 0; i < ArrSize; i++)
	{
		Func(ArrAdrr[i]); 
	}
}

#endif