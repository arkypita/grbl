/*
  beep_beep.h - beep beep control methods
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

#ifndef beep_beep_h
#define beep_beep_h 
	uint16_t beep_beep_elapsed;
	bool done_one_cycle;
	
	void beep_beep_init();
	void beep_beep_and_wait();
	void beep_beep_stop();
	bool beep_beep_done();
#endif
