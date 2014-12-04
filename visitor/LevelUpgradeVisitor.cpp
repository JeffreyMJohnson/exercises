#include "StdAfx.h"
#include "LevelUpgradeVisitor.h"
#include "Modifiable.h"
#include "Player.h"
#include "Shotgun.h"
#include "MagicWand.h"
#include <iostream>

LevelUpgradeVisitor::LevelUpgradeVisitor(void)
{
}


LevelUpgradeVisitor::~LevelUpgradeVisitor(void)
{
}

void LevelUpgradeVisitor::visit(Modifiable* visitable)
{
	// determine what visitable is and then pass to the correct upgrade function
	// hint: dynamic_cast
	if (dynamic_cast<Player*>(visitable) != 0)
	{
		upgrade(*(dynamic_cast<Player*>(visitable)));
	}
	if (dynamic_cast<Shotgun*>(visitable) != 0)
	{
		upgrade(*(dynamic_cast<Shotgun*>(visitable)));
	}
	if (dynamic_cast<MagicWand*>(visitable) != 0)
	{
		upgrade(*(dynamic_cast<MagicWand*>(visitable)));
	}
}

void LevelUpgradeVisitor::upgrade(Player& p) 
{
	//given level clearance bonus pts
	p.setPoints(p.getPoints() + 100);
}

void LevelUpgradeVisitor::upgrade(Shotgun& s)
{
	//secondary attack enabled
	s.setDualShotgunEnabled(true);
}

void LevelUpgradeVisitor::upgrade(MagicWand& w)
{
	//power level increased by 2 points
	w.setPowerLevel(w.getPowerLevel() + 2);
}
