#include "Alien.h"
#include "Hero.h"
#include "Laser.h"
#include "Game.h"
#include "Utilities.h"
Alien::Alien(int row, int column) : Actor('&', 2, 1, row, column) {
	m_direction = 1;
	if (randInt(100) < 20) {
		m_isSpecial = true;
	}
	m_hitValue = 50;	//base score received per alien hit
	m_isSpecial = false;	//true when alien is special alien (15% chance)
}
Alien::~Alien() {
	//Error is thrownwhen I delete
	//delete this;
}
bool Alien::move(char key)
{
	int columnPosition = getPosition().column;
	int rowPosition = getPosition().row;
	if (key == 'd')
	{
		rowPosition++;
		setPosition(rowPosition, columnPosition);
	}
	else
	{
		if (columnPosition >= BOARD_WIDTH - 2 || columnPosition <= 1) {
			m_direction *= -1;
		}
		columnPosition += m_direction;
		setPosition(rowPosition, columnPosition);

	}
	return true;
}

void Alien::shootLaser(Game*game) {
	setHasShotAlready(true);
	game->addLaser(new Laser(this, false));
}

void Alien::collide(Hero* hero) {
	hero->setHP(0);
}
