/***************************************************************************
 *   Copyright (C) 2006 by Arnaud Desaedeleer                              *
 *   arnaud@desaedeleer.com                                                *
 *                                                                         *
 *   This file is part of OpenOMR                                          *                                                      
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


package openomr.openomr;

import openomr.gui.GUI;
import org.sintef.jarduino.comm.Serial4JArduino;

public class SheetMusic
{
	public static void main(String[] args)
	{
                               String serialPort;               //This code is for the JArduino
                               if (args.length == 1) {          //
                                         serialPort = args[0];  //
                               } else {                         // This code is for the JArduino
                                         serialPort = Serial4JArduino.selectSerialPort();  //
        }
				GUI myGui = new GUI();
				myGui.setVisible(true);
	}
}
