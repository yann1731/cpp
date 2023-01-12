#include "Account.hpp"
using std::cout;
using std::endl;

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

Account::Account()
{
}

Account::Account(int initial_deposit):  _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	//[19920104_091532] index:0;amount:42;created
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	cout << " index:" << _accountIndex << ";amount:" << initial_deposit << ";created" << endl;
}

Account::~Account()
{
	//[19920104_091532] index:0;amount:47;closed
	_displayTimestamp();
	cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << endl;
}

void Account::makeDeposit(int deposit)
{
	//[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
	_totalAmount += deposit;
	_totalNbDeposits++;
	_displayTimestamp();
	cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
	_amount += deposit;
	_nbDeposits++;
	std::cout << ";amount:" << _amount << ":nb_deposits:" << _nbDeposits << endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	//[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
	if (withdrawal <= _amount)
	{
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		_displayTimestamp();
		cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal;
		_amount -= withdrawal;
		_nbWithdrawals++;
		std::cout << ";amount:" << _amount << ":nb_withdrawals:" << _nbWithdrawals << endl;
		return true;
	}
	else
	{
		_displayTimestamp();
		cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << endl;
		//[19920104_091532] index:0;p_amount:47;withdrawal:refused
		return false;
	}
}

int Account::checkAmount(void) const
{
	return _amount;
}

void Account::displayStatus(void) const
{
	//[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
	_displayTimestamp();
	cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << endl;
}

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
	_displayTimestamp();
	cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << endl;
}

void Account::_displayTimestamp(void)
{
	cout << "[19920104_091532]";
}