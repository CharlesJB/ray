/*
 *  Ray -- Parallel genome assemblies for parallel DNA sequencing
    Copyright (C) 2010, 2011, 2012, 2013 Sébastien Boisvert

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

#ifdef CONFIG_HAVE_LIBBZ2

#include "FastqBz2Loader.h"
#include "BzReader.h"

#include <stdlib.h>
#include <fstream>
using namespace std;

int FastqBz2Loader::getSize(){
	return m_size;
}

int FastqBz2Loader::open(string file){
	return openWithPeriod(file,4);
}

int FastqBz2Loader::openWithPeriod(string file,int period){
	m_reader.open(file.c_str());
	char buffer[4096];
	m_loaded=0;
	m_size=0;

	int rotatingVariable=0;
	while(NULL!=m_reader.readLine(buffer,4096)){
		if(rotatingVariable==1){
			m_size++;
		}
		rotatingVariable++;
		if(rotatingVariable==period){
			rotatingVariable=0;
		}
	}
	m_reader.close();

	m_reader.open(file.c_str());
	return EXIT_SUCCESS;
}

void FastqBz2Loader::load(int maxToLoad,ArrayOfReads*reads,MyAllocator*seqMyAllocator){
	loadWithPeriod(maxToLoad,reads,seqMyAllocator,4);
}

// a very simple and compact fastq.gz reader
void FastqBz2Loader::loadWithPeriod(int maxToLoad,ArrayOfReads*reads,MyAllocator*seqMyAllocator,int period){
	char buffer[RAY_MAXIMUM_READ_LENGTH];
	int rotatingVariable=0;
	int loadedSequences=0;
	while(loadedSequences<maxToLoad&&NULL!=m_reader.readLine(buffer,RAY_MAXIMUM_READ_LENGTH)){
		if(rotatingVariable==1){
			Read t;
			t.constructor(buffer,seqMyAllocator,true);
			reads->push_back(&t);
		}

		rotatingVariable++;

		// a period is reached for each sequence.
		if(rotatingVariable==period){
			rotatingVariable=0;
			m_loaded++;
			loadedSequences++;
		}
	}
	if(m_loaded==m_size){
		m_reader.close();
	}
}

void FastqBz2Loader::close(){
}

#endif
