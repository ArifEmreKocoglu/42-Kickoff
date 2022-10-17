/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:05:07 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/01 17:05:08 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void)
{
	cout << name << ": BraiiiiiiinnnzzzZ..." << endl;
}

void	Zombie::set_name(string str)
{
	name = str;
}

string	Zombie::get_name(void)
{
	return (name);
}

Zombie::Zombie(){};

Zombie::Zombie(string name)
{
	this->name = name;
};

Zombie::~Zombie()
{
	cout << name << " destroyed" << endl;
};