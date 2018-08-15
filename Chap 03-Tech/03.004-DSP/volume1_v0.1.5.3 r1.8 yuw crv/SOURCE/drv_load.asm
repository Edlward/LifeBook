;*
;*  Copyright (c) 2001-2002, Texas Instruments Incorporated.
;*  All rights reserved. Property of Texas Instruments Incorporated.
;*  Restricted rights to use, duplicate or disclose this code are
;*  granted through contract.
;*

FP	.set	AR2
	
	.sect	".text"
	.global	_load

;***************************************************************
;* FNAME: _load                         FR SIZE:   1           *
;*                                                             *
;* FUNCTION ENVIRONMENT                                        *
;*                                                             *
;* FUNCTION PROPERTIES                                         *
;*                            0 Parameter,  1 Auto,  0 SOE     *
;***************************************************************

_load:
        ADDB      SP,#1
        CMPB      AL,#0                 ; |3| 
        MOV       *-SP[1],AL            ; |2| 
        B         L2,EQ                 ; |3| 
        ; branch occurs ; |3| 
L1:    
        DEC       *-SP[1]               ; |4| 
        MOV       AL,*-SP[1]            ; |4| 
        B         L1,NEQ                ; |4| 
        ; branch occurs ; |4| 
L2:    
        SUBB      SP,#1
        LRETR
        ; return occurs


