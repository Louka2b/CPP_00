/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka <louka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:25:42 by louka             #+#    #+#             */
/*   Updated: 2026/06/09 12:07:42 by louka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

static  char *put_in_maj(char *str)
{
    int i = 0;

    while(str[i])
    {
        if(str[i] >= 97 && str[i] <= 122)
            str[i] = str[i] - 32;
        i++;
    }
    return(str);
}

int main(int ac, char **av)
{
    int i = 1;
    std::string str = "";

    if(ac < 2)
        return(0);
    while(i < ac)
    {
        str = str + " " + put_in_maj(av[i]);
        i++;
    }
    std::cout << str << '\n';
}
