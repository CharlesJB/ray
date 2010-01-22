/*
 	Ray
    Copyright (C) 2010  Sébastien Boisvert

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





#ifndef _Message
#define _Message

#include<mpi.h>
class Message{
	void*m_buffer;
	int m_count;
	MPI_Datatype m_datatype;
	int m_dest;
	int m_tag;
	int m_source;
public:
	Message();
	Message(void*b,int c,MPI_Datatype d,int dest,int tag,int source);
	void*getBuffer();
	int getCount();
	MPI_Datatype getMPIDatatype();
	int getDestination();
	int getTag();
	int getSource();
};

#endif
