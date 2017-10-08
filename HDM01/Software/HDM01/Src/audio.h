//
//						Filename: audio.h
//						Header file for audio.c - digital audio processing library code
//
//
//--------------------------------------------------------------------------------------------------------------------------

#ifndef __AUDIO_H_
#define __AUDIO_H_

#include <stdint.h>

// Definitions
#define AUDIO_16_BITS 		1						// 16-bit digital audio
#define AUDIO_24_BITS 		2						// 24-bit digital audio

// Function prototypes
//---------------------
void SetWordSize(unsigned char WS);
unsigned char GetWordSize(void);
void GetSamples(uint32_t *LEFT, uint32_t *RIGHT);
void InitAudioIF(void);

#endif /* AUDIO_H_ */
