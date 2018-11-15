/*
 *  Copyright (c) 2001-2002, Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  U.S. Patent Nos. 5,283,900  5,392,448
 */
/* "@(#) DSP/BIOS 4.42 02-12-01 (barracuda-h28)" */

/*
 *  ======== VOLUME.H ========
 *
 */

#ifndef __VOLUME_H
#define __VOLUME_H

#ifndef TRUE
#define TRUE 1
#endif

#define BUFSIZE 0x64			// 100.

#define FRAMESPERBUFFER 10

#define MINGAIN 1
#define MAXGAIN 10

#define MINCONTROL 0
#define MAXCONTROL 19

#define BASELOAD 1

struct PARMS {
	int Beta;
	int EchoPower;
	int ErrorPower;
	int Ratio;
	struct PARMS *Link;
};

#endif /* __VOLUME_H */
