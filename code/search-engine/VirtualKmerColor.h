/*
 	Ray
    Copyright (C) 2010, 2011, 2012  Sébastien Boisvert

	http://DeNovoAssembler.SourceForge.Net/

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, version 3 of the License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You have received a copy of the GNU General Public License
    along with this program (gpl-3.0.txt).  
	see <http://www.gnu.org/licenses/>

*/


#ifndef _VirtualKmerColor_h
#define _VirtualKmerColor_h

#include <stdint.h>
#include <vector>
using namespace std;

typedef uint32_t PhysicalKmerColor;

class VirtualKmerColor{
	uint64_t m_references;
	vector<PhysicalKmerColor> m_colors;
public:
	VirtualKmerColor();

	void addPhysicalColor(PhysicalKmerColor color);

	void incrementReferences();
	void decrementReferences();

	uint64_t getReferences();
};

#endif
