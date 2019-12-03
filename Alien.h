#ifndef ALIEN_H
#define ALIEN_H

#include "Actor.h"

class Hero;
class Game;

class Alien : public Actor {
public:
	Alien(int row, int column);
	virtual ~Alien();
	void collide(Hero* hero);
	bool move(char key);
	void shootLaser(Game*game);
	int getHitValue() const { return m_hitValue; }
	bool isSpecial() { return m_isSpecial; }
private:
	int m_direction;
	int m_hitValue;	//base score received per alien hit
	bool m_isSpecial;	//true when alien is special alien (15% chance)
};

#endif // ALIEN_H