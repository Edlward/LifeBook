/*
 *  Copyright (c) 2001-2002, Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  U.S. Patent Nos. 5,283,900  5,392,448
 */
/* "@(#) DSP/BIOS 4.42 02-12-01 (barracuda-h28)" */
/***************************************************************************/
/*                                                                         */
/*     V O L U M E . C                                                     */
/*                                                                         */
/*     Audio gain processing in a main loop                                */
/*                                                                         */
/***************************************************************************/

#include <stdio.h>

#include "appl_volume.h"

/* Global declarations */
int inp_buffer[BUFSIZE];       /* processing data buffers */
int out_buffer[BUFSIZE];

int gain = MINGAIN;                      /* volume control variable */
unsigned int processingLoad = BASELOAD;  /* processing routine load value */

struct PARMS str =
{
    2934,
    9432,
    213,
    9432,
    &str
};

/* Functions */
void Appl_Volume(void);

extern void load(unsigned int loadValue);

static int processing(int *input, int *output);
static void dataIO(void);


/*
 * //======== main ========
 * ======== Appl_Volume ========
 */
void Appl_Volume(void)
{
    int *input = &inp_buffer[0];
    int *output = &out_buffer[0];

    puts("volume example started\n");

    /* loop forever */
    while(TRUE)
    {       
        /* 
         *  Read input data using a probe-point connected to a host file. 
         *  Write output data to a graph connected through a probe-point.
         */
        dataIO();

        #ifdef FILEIO
        puts("begin processing")        /* deliberate syntax error */
        #endif
        
        /* apply gain */
        processing(input, output);
    }
}

/*
 *  ======== processing ========
 *
 * FUNCTION: apply signal processing transform to input signal.
 *
 * PARAMETERS: address of input and output buffers.
 *
 * RETURN VALUE: TRUE.
 */
static int processing(int *input, int *output)
{
    int size = BUFSIZE;

    while(size--){
        *output++ = (*input++) * gain;
    }
        
    /* additional processing load */
    load(processingLoad);
    
    return(TRUE);
}

/*
 *  ======== dataIO ========
 *
 * FUNCTION: read input signal and write processed output signal.
 *
 * PARAMETERS: none.
 *
 * RETURN VALUE: none.
 */
static void dataIO()
{
    /* do data I/O */

    return;
}

