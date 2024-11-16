/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:26:51 by jlara-na          #+#    #+#             */
/*   Updated: 2024/11/05 21:35:23 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string	capitalizer(std::string	str)
{
	for (size_t i = 0; i < str.length(); i++)
        str[i] = std::toupper(str[i]);
	return (str);
}

int	main(int	ac, char	**av)
{
	if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i = 1; av[i]; i++)
    {
        std::string str = av[i];
		std::cout << capitalizer(str);
    }
	std::cout << std::endl;
    return (0);
}