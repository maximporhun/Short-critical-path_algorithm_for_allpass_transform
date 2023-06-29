#ifndef WAVE_LIB_H
#define	WAVE_LIB_H

#include <iostream>
#include <fstream>
#include <string.h>

typedef struct WAVHeader {
	// the RIFF chunk descriptor
	int   ChunkID;
	int   ChunkSize;
	int   Format;

	//fmt sub-chunk
	int   Subchunk1ID;
	int   Subchunk1Size;
	short AudioFormat;
	short NumChannels;
	int   SampleRate;
	int   ByteRate;
	short BlockAlign;
	short BitsPerSample;

	//data sub-chunk
	int   SubChunk2ID;
	int   Subchunk2Size;

}wavheader;

typedef struct WAVInfo {
	
	WAVHeader		Header;
	unsigned int	NumberOfSamples;	
}wavinfo;

// Functions
int* wavread(char * filename, WAVInfo &info);
int wavwrite(char * filename, WAVInfo &info, int *data);

#endif