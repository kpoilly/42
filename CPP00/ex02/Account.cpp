/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 07:45:53 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/10 06:58:01 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void)
{
	this->_accountIndex = _nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_displayTimestamp();
	std::cout << "index:" << "\033[34m" << this->_accountIndex << "\033[0m;";
	std::cout << "amount:" << "\033[34m" << this->_amount << "\033[0m;";
	std::cout << "created" << std::endl;
	this->_nbAccounts++;
};
Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount += initial_deposit;
	this->_totalAmount += initial_deposit;
	this->_displayTimestamp();
	std::cout << "index:" << "\033[34m" << this->_accountIndex << "\033[0m;";
	std::cout << "amount:" << "\033[34m" << this->_amount << "\033[0m;";
	std::cout << "created" << std::endl;
	this->_nbAccounts++;
};
Account::~Account(void)
{
	this->_displayTimestamp();
	std::cout << "index:" << "\033[34m" << this->_accountIndex << "\033[0m;";
	std::cout << "amount:" << "\033[34m" << this->_amount << "\033[0m;";
	std::cout << "closed" << std::endl;
};

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
};

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
};

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
};

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
};

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << "\033[34m" << _nbAccounts << "\033[0m;";
	std::cout << "total:" << "\033[34m" << getTotalAmount() << "\033[0m;";
	std::cout << "deposits:" << "\033[34m" << getNbDeposits() << "\033[0m;";
	std::cout << "withdrawals:" << "\033[34m" << getNbWithdrawals() << "\033[0m" << std::endl;
};

void	Account::makeDeposit(int deposit)
{
	this->_displayTimestamp();
	std::cout << "index:" << "\033[34m" << this->_accountIndex << "\033[0m;";
	std::cout << "p_amount:" << "\033[34m" << this->_amount << "\033[0m;";
	std::cout << "deposits:" << "\033[34m" << deposit << "\033[0m;";
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_totalNbDeposits++;
	this->_nbDeposits++;
	std::cout << "amount:" << "\033[34m" << this->_amount << "\033[0m;";
	std::cout << "nb_deposits:" << "\033[34m" << this->_nbDeposits << "\033[0m" << std::endl;
};

bool	Account::makeWithdrawal(int withdrawal)
{
		
	this->_displayTimestamp();
	std::cout << "index:" << "\033[34m" << this->_accountIndex << "\033[0m;";
	std::cout << "p_amount:" << "\033[34m" << this->_amount << "\033[0m;";
	if (this->_amount - withdrawal < 0)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << "withdrawal:" << "\033[34m" << withdrawal << "\033[0m;";
	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	this->_totalNbWithdrawals++;
	this->_nbWithdrawals++;
	std::cout << "amount:" << "\033[34m" << this->_amount << "\033[0m;";
	std::cout << "nb_withdrawals:" << "\033[34m" << this->_nbWithdrawals << "\033[0m" << std::endl;
	return (true);
};

int		Account::checkAmount(void) const
{
	return (_amount);
};

void	Account::displayStatus(void) const
{
	this->_displayTimestamp();
	std::cout << "index:" << "\033[34m" << this->_accountIndex << "\033[0m;";
	std::cout << "amount:" << "\033[34m" << this->_amount << "\033[0m;";
	std::cout << "nb_deposits:" << "\033[34m" << this->_nbDeposits << "\033[0m;";
	std::cout << "withdrawals:" << "\033[34m" << this->_nbWithdrawals << "\033[0m" << std::endl;
};

void	Account::_displayTimestamp(void)
{
	std::time_t timestamp = std::time(NULL);
	struct tm *time = std::localtime(&timestamp);
	std::cout << "[" << time->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << time->tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << time->tm_mday << "_";
	std::cout << std::setfill('0') << std::setw(2) << time->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << time->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << time->tm_sec;
	std::cout << "] ";
	
	
};
