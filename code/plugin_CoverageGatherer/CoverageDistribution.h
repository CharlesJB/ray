/*
 	Ray
    Copyright (C)  2010, 2011, 2012 Sébastien Boisvert

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

#ifndef _CoverageDistribution
#define _CoverageDistribution

#include <code/plugin_Mock/constants.h>

#include <RayPlatform/core/types.h>

#include <map>
#include <string>
#include <vector>
#include <stdint.h>
using namespace std;

/*
 *
 * Given a distribution of coverage, CoverageDistribution computes 
 * the minimum coverage, and the peak coverage.
 * \author Sébastien Boisvert
 */
class CoverageDistribution{
	int m_minimumCoverage;
	int m_peakCoverage;
	int m_repeatCoverage;

	void findPeak(vector<int>*x,vector<LargeCount>*y,vector<LargeCount>*rawValues);

	vector<uint64_t> smoothData(vector<uint64_t>*a);
public:
	CoverageDistribution(map<CoverageDepth,LargeCount>*distributionOfCoverage,string*file);
	int getMinimumCoverage();
	int getPeakCoverage();
	int getRepeatCoverage();
};

#endif
