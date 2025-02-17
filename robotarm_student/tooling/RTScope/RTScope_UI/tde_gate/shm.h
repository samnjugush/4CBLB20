
#include "../engine/engine.h"

typedef struct tag_tde_shm
	{
		int stop_server;
		int cmd_id;
		int cmd_status;
		double argin1;
		double argin2;
		double argin3;
		double argin4;
		double argin5;
		double argin6;
		double retval;
/*
		double data[MAXSAMP*MAXCHAN*2];
*/
		double maxchan;
		double maxframe;
		double clip[MAXCHAN];
		double stat;
		double offset;
		double maxfreq;
		double amp;
		double freq;
		double offs;
		double type;
		double onoff;
		double holdorder;
		double allstat[2*MAXCHAN];
	} tde_shm, *ptde_shm;
