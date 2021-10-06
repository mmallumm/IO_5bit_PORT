#include "PortIO.h"
#include <iostream>
#include <bitset>

PortIO::PortIO( unsigned char *port,  unsigned char *ddr)
{
	PORT = port;
	DDR =  ddr;
	*PORT = 0b00000;
	*DDR = 0b00000;
}

void PortIO::SET_DDR_DEFAULT()
{
	*DDR = 0b00000;
}

void PortIO::SET_PORT_DEFAULT()
{
	*PORT = 0b00000;
}

void PortIO::SET_PIN_INPUT(const unsigned char option) {
	*DDR &= ~option;
}

void PortIO::SET_PIN_OUTPUT(const unsigned char option) {
	*DDR |= option;
}

void PortIO::SET_POWER_ON(const unsigned char option) {
	*PORT |= option;
}

void PortIO::SET_POWER_OFF(const unsigned char option) {
	*PORT &= ~option;
}

bool PortIO::READ_PIN_DIRECTION(const unsigned char option) {
	if (*DDR & option) return 1;
	return 0;
}

bool PortIO::READ_PIN_POWER(const unsigned char option) {
	if (*PORT & option) return 1;
	return 0;
}


void PortIO::GIVE_DDR() {
	std::cout << std::bitset <5>(*DDR) << std::endl;
}

void PortIO::GIVE_PORT() {
	std::cout << std::bitset <5>(*PORT) << std::endl;
}



