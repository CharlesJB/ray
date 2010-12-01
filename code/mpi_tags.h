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
    along with this program (COPYING).  
	see <http://www.gnu.org/licenses/>


 	Funding:

Sébastien Boisvert has a scholarship from the Canadian Institutes of Health Research (Master's award: 200910MDR-215249-172830 and Doctoral award: 200902CGM-204212-172830).

*/




#ifndef _mpi_tags
#define _mpi_tags

// tags
// these are the message types used by Ray
// Ray instances like to communicate a lots!
//

enum {
TAG_WELCOME,
TAG_SEND_SEQUENCE,
TAG_SEQUENCES_READY,
TAG_MASTER_IS_DONE_SENDING_ITS_SEQUENCES_TO_OTHERS,
TAG_VERTICES_DATA,
TAG_VERTICES_DISTRIBUTED,
TAG_VERTEX_PTR_REQUEST,
TAG_OUT_EDGE_DATA_WITH_PTR,
TAG_OUT_EDGES_DATA,
TAG_SHOW_VERTICES,
TAG_START_VERTICES_DISTRIBUTION,
TAG_EDGES_DISTRIBUTED,
TAG_IN_EDGES_DATA,
TAG_IN_EDGE_DATA_WITH_PTR,
TAG_START_EDGES_DISTRIBUTION,
TAG_START_EDGES_DISTRIBUTION_ASK,
TAG_START_EDGES_DISTRIBUTION_ANSWER,
TAG_PREPARE_COVERAGE_DISTRIBUTION_QUESTION,
TAG_PREPARE_COVERAGE_DISTRIBUTION_ANSWER,
TAG_PREPARE_COVERAGE_DISTRIBUTION,
TAG_COVERAGE_DATA,
TAG_COVERAGE_END,
TAG_SEND_COVERAGE_VALUES,
TAG_READY_TO_SEED,
TAG_START_SEEDING,
TAG_REQUEST_VERTEX_COVERAGE,
TAG_REQUEST_VERTEX_COVERAGE_REPLY,
TAG_REQUEST_VERTEX_KEY_AND_COVERAGE,
TAG_REQUEST_VERTEX_KEY_AND_COVERAGE_REPLY,
TAG_REQUEST_VERTEX_OUTGOING_EDGES,
TAG_REQUEST_VERTEX_OUTGOING_EDGES_REPLY,
TAG_SEEDING_IS_OVER,
TAG_GOOD_JOB_SEE_YOU_SOON,
TAG_I_GO_NOW,
TAG_SET_WORD_SIZE,
TAG_MASTER_IS_DONE_ATTACHING_READS,
TAG_MASTER_IS_DONE_ATTACHING_READS_REPLY,
TAG_FORWARD_TO_ATTACH_SEQUENCE_POINTER,
TAG_FORWARD_TO_ATTACH_SEQUENCE_POINTER_REPLY,
TAG_REQUEST_VERTEX_INGOING_EDGES,
TAG_REQUEST_VERTEX_INGOING_EDGES_REPLY,
TAG_EXTENSION_IS_DONE,
TAG_ASK_EXTENSION,
TAG_ASK_IS_ASSEMBLED,
TAG_ASK_REVERSE_COMPLEMENT,
TAG_REQUEST_VERTEX_POINTER,
TAG_ASK_IS_ASSEMBLED_REPLY,
TAG_MARK_AS_ASSEMBLED,
TAG_ASK_EXTENSION_DATA,
TAG_EXTENSION_DATA,
TAG_EXTENSION_END,
TAG_EXTENSION_DATA_END,
TAG_ATTACH_SEQUENCE,
TAG_REQUEST_READS,
TAG_REQUEST_READS_REPLY,
TAG_ASK_READ_VERTEX_AT_POSITION,
TAG_ASK_READ_VERTEX_AT_POSITION_REPLY,
TAG_ASK_READ_LENGTH,
TAG_ASK_READ_LENGTH_REPLY,
TAG_SAVE_WAVE_PROGRESSION,
TAG_COPY_DIRECTIONS,
TAG_ASSEMBLE_WAVES,
TAG_SAVE_WAVE_PROGRESSION_REVERSE,
TAG_ASSEMBLE_WAVES_DONE,
TAG_START_FUSION,
TAG_FUSION_DONE,
TAG_ASK_VERTEX_PATHS_SIZE,
TAG_ASK_VERTEX_PATHS_SIZE_REPLY,
TAG_GET_PATH_LENGTH,
TAG_GET_PATH_LENGTH_REPLY,
TAG_CALIBRATION_MESSAGE,
TAG_BEGIN_CALIBRATION,
TAG_END_CALIBRATION,
TAG_COMMUNICATION_STABILITY_MESSAGE,
TAG_ASK_VERTEX_PATH,
TAG_ASK_VERTEX_PATH_REPLY,
TAG_INDEX_PAIRED_SEQUENCE,
TAG_HAS_PAIRED_READ,
TAG_HAS_PAIRED_READ_REPLY,
TAG_GET_PAIRED_READ,
TAG_GET_PAIRED_READ_REPLY,
TAG_CLEAR_DIRECTIONS,
TAG_CLEAR_DIRECTIONS_REPLY,
TAG_FINISH_FUSIONS,
TAG_FINISH_FUSIONS_FINISHED,
TAG_DISTRIBUTE_FUSIONS,
TAG_DISTRIBUTE_FUSIONS_FINISHED,
TAG_EXTENSION_START,
TAG_ELIMINATE_PATH,
TAG_GET_PATH_VERTEX,
TAG_GET_PATH_VERTEX_REPLY,
TAG_SET_COLOR_MODE,
TAG_AUTOMATIC_DISTANCE_DETECTION,
TAG_AUTOMATIC_DISTANCE_DETECTION_IS_DONE,
TAG_LIBRARY_DISTANCE,
TAG_ASK_LIBRARY_DISTANCES,
TAG_ASK_LIBRARY_DISTANCES_FINISHED,
TAG_UPDATE_LIBRARY_INFORMATION,
TAG_RECEIVED_COVERAGE_INFORMATION,
TAG_REQUEST_READ_SEQUENCE,
TAG_REQUEST_READ_SEQUENCE_REPLY,
TAG_SEND_SEQUENCE_REPLY,
TAG_SAVE_WAVE_PROGRESSION_REPLY,
TAG_SEND_SEQUENCE_REGULATOR,
TAG_START_INDEXING_SEQUENCES,
TAG_VERTICES_DATA_REPLY,
TAG_IN_EDGES_DATA_REPLY,
TAG_OUT_EDGES_DATA_REPLY,
TAG_INDEX_PAIRED_SEQUENCE_REPLY,
TAG_EXTENSION_DATA_REPLY,
TAG_BARRIER,
TAG_SHOW_SEQUENCES,
TAG_LIBRARY_DISTANCE_REPLY,
TAG_RECEIVED_MESSAGES,
TAG_RECEIVED_MESSAGES_REPLY,
TAG_DISTRIBUTE_FUSIONS_FINISHED_REPLY,
TAG_DISTRIBUTE_FUSIONS_FINISHED_REPLY_REPLY,
TAG_SAVE_WAVE_PROGRESSION_WITH_REPLY,
TAG_ASK_IS_ASSEMBLED_REPLY_END

};


#endif
