//
//  constants.h
//  test_engine
//
//  Created by Marinus J.G. van de Molengraft on 10/12/2021.
//

#ifndef constants_h
#define constants_h

#define MAXFRAME	16384       // maximum number of samples in frame
#define MAXSAMP		1*MAXFRAME  // maximum number of samples in buffer
#define MAXFRAMES   5           // number of frames in ringbuffer

/* QadScope can handle 4 QAD/AQI/MicroGiant devices...
 * see also qs_defines.m for MAXDEVS definition!!! */
#define MAXCHAN		2*4

#endif /* constants_h */
