#include "Games.h"

void Games::setName(const string na) {
	this->name = na;
}

string Games::getName() {
	return this->name;
}

Games::Games(const string na) {
	this->plWin = 0;
	this->pcWin = 0;
	this->name = na;
}

int Games::getPcWin() {
	return this->pcWin;
}

int Games::getPlWin()
{
	return this->plWin;
}

int Games::getTotal()
{
	return this->total;
}

void Games::setTotal(int total)
{
	this->total = total;
}

void Games::setPcWin(int pc)
{
	this->pcWin = pc;
}

void Games::setPlWin(int pl)
{
	this->plWin = pl;
}


