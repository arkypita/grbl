/*
  beep_beep.c - beep beep control methods
  Part of Grbl

  Copyright (c) 2012-2015 Sungeun K. Jeon

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/  

#include "grbl.h"


void beep_beep_init()
{
  #ifdef BEEP_BEEP
	beep_beep_stop();
	BEEP_BEEP_DDR |= (1 << BEEP_BEEP_BIT);
  #endif
}


void beep_beep_and_wait()
{
  #ifdef BEEP_BEEP 

	_delay_ms(1);
	beep_beep_elapsed++;
	
	if (beep_beep_elapsed < 100)
		BEEP_BEEP_PORT &= ~(1 << BEEP_BEEP_BIT);
	else if (beep_beep_elapsed < 400)
		BEEP_BEEP_PORT |= (1 << BEEP_BEEP_BIT);
	else if (beep_beep_elapsed < 500)
		BEEP_BEEP_PORT &= ~(1 << BEEP_BEEP_BIT);
	else if (beep_beep_elapsed < 800)
		BEEP_BEEP_PORT |= (1 << BEEP_BEEP_BIT);
	else if (beep_beep_elapsed < 900)
		BEEP_BEEP_PORT &= ~(1 << BEEP_BEEP_BIT);
	else if (beep_beep_elapsed < 1200)
	{
		done_one_cycle = true;
		BEEP_BEEP_PORT |= (1 << BEEP_BEEP_BIT);
	}
	else if (beep_beep_elapsed > 3200)
		beep_beep_elapsed = 0;

  #endif
}

bool beep_beep_done()
{return done_one_cycle;}

void beep_beep_stop()
{
  #ifdef BEEP_BEEP
	BEEP_BEEP_PORT |= (1 << BEEP_BEEP_BIT);
	beep_beep_elapsed = 0;
	done_one_cycle = false;
  #endif  
}
