/*
 	Ray
    Copyright (C) 2010, 2011  Sébastien Boisvert

	http://DeNovoAssembler.SourceForge.Net/

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, version 3 of the License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You have received a copy of the GNU General Public License
    along with this program (COPYING).  
	see <http://www.gnu.org/licenses/>

*/

// TYPE: ALGORITHM

#ifndef _SeedExtender
#define _SeedExtender

class FusionData;
class DepthFirstSearchData;

#include <common_functions.h>
#include <Message.h>
#include <vector>
#include <ExtensionData.h>
#include <Parameters.h>
#include <RingAllocator.h>
#include <MyAllocator.h>
#include <ReadFetcher.h>
#include <FusionData.h>
#include <BubbleData.h>
#include <DepthFirstSearchData.h>
#include <BubbleTool.h>
#include <OpenAssemblerChooser.h>
#include <EarlyStoppingTechnology.h>
#include <GridTable.h>

using namespace std;

class SeedExtender{
	SplayTree<uint64_t,Read>m_cacheForRepeatedReads;

	int m_repeatLength;
	StaticVector*m_inbox;

	DepthFirstSearchData*m_dfsData;
	bool m_removedUnfitLibraries;
	map<uint64_t,int>*m_cache;
	vector<Direction>m_receivedDirections;
	GridTable*m_subgraph;
	EarlyStoppingTechnology m_earlyStoppingTechnology;
	bool m_skippedASeed;
	Parameters*m_parameters;
	BubbleTool m_bubbleTool;
	ExtensionData*m_ed;
	MyAllocator*m_directionsAllocator;
	MyAllocator m_cacheAllocator;

	set<uint64_t> m_eliminatedSeeds;
	map<int,vector<uint64_t> >m_expiredReads;

	void inspect(ExtensionData*ed,uint64_t*currentVertex);

	void removeUnfitLibraries();

	void setFreeUnmatedPairedReads();

	void showReadsInRange();

public:
	bool m_sequenceReceived;
	bool m_sequenceRequested;
	string m_receivedString;
	int m_sequenceIndexToCache;

	SeedExtender();

	void enumerateChoices(bool*edgesRequested,ExtensionData*ed,bool*edgesReceived,RingAllocator*outboxAllocator,
		int*outgoingEdgeIndex,StaticVector*outbox,
uint64_t*currentVertex,int theRank,bool*vertexCoverageRequested,vector<uint64_t>*receivedOutgoingEdges,
bool*vertexCoverageReceived,int size,int*receivedVertexCoverage,Chooser*chooser,
int wordSize);

	void checkIfCurrentVertexIsAssembled(ExtensionData*ed,StaticVector*outbox,RingAllocator*outboxAllocator,
	 int*outgoingEdgeIndex,int*last_value,uint64_t*currentVertex,int theRank,bool*vertexCoverageRequested,
	int wordSize,bool*colorSpaceMode,int size,vector<vector<uint64_t> >*seeds);

	void markCurrentVertexAsAssembled(uint64_t*currentVertex,RingAllocator*outboxAllocator,int*outgoingEdgeIndex,
 StaticVector*outbox,int size,int theRank,ExtensionData*ed,bool*vertexCoverageRequested,
		bool*vertexCoverageReceived,int*receivedVertexCoverage,int*repeatedLength,int*maxCoverage,
	bool*edgesRequested,
vector<uint64_t>*receivedOutgoingEdges,Chooser*chooser,
BubbleData*bubbleData,int minimumCoverage,OpenAssemblerChooser*oa,bool*colorSpaceMode,int wordSize,vector<vector<uint64_t> >*seeds);

	void extendSeeds(vector<vector<uint64_t> >*seeds,ExtensionData*ed,int theRank,StaticVector*outbox,uint64_t*currentVertex,
	FusionData*fusionData,RingAllocator*outboxAllocator,bool*edgesRequested,int*outgoingEdgeIndex,
int*last_value,bool*vertexCoverageRequested,int wordSize,bool*colorSpaceMode,int size,bool*vertexCoverageReceived,
int*receivedVertexCoverage,int*repeatedLength,int*maxCoverage,vector<uint64_t>*receivedOutgoingEdges,Chooser*chooser,
BubbleData*bubbleData,
int minimumCoverage,OpenAssemblerChooser*oa,bool*edgesReceived,int*m_mode);

	void doChoice(RingAllocator*outboxAllocator,int*outgoingEdgeIndex,StaticVector*outbox,uint64_t*currentVertex,
BubbleData*bubbleData,int theRank,int wordSize,
ExtensionData*ed,int minimumCoverage,int maxCoverage,OpenAssemblerChooser*oa,Chooser*chooser,bool*colorSpaceMode,
	vector<vector<uint64_t> >*seeds,
bool*edgesRequested,bool*vertexCoverageRequested,bool*vertexCoverageReceived,int size,
int*receivedVertexCoverage,bool*edgesReceived,vector<uint64_t>*receivedOutgoingEdges);

	vector<Direction>*getDirections();

	void storeExtensionAndGetNextOne(ExtensionData*ed,int theRank,vector<vector<uint64_t> >*seeds,uint64_t*currentVertex,
		BubbleData*bubbleData);

	set<uint64_t>*getEliminatedSeeds();

	void constructor(Parameters*parameters,MyAllocator*m_directionsAllocator,ExtensionData*ed,GridTable*table,StaticVector*inbox);
};

#endif

