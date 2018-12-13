花圓project <- 樹苗object <- 植物class.

05. State Machine. How many states? What States?
	//! object   ------->states. //isoSgl ->0, 1.------>state machine       ------------>condition table.
		//!      ------->signals                 ------>events              ------------>messages.
	//! signals -> events. signalsArray[SGINAL_IDx], eventsArray[EVENT_ID]. SetEvent(event, EVENT_ID, MESSAGE_ID). 
		//! input signals  ->events.  
		//! fault signals  ->events.
		//! process signals->events.
		//! state signals  ->events.
	//! events -> messages:    messageArray[MESSAGE_ID].   between modules, independence.
		//! CMD.
		/// enum {MSG_ISO_SET = 0, ..., MSG_LENGTH}
	
	//event, jump edge once, send to other module. //reset iso event, to interior light, to open cmd.
	if (signal)
	{
		isoSetMsgToIntLight = signal;
		isoSetMsgToOpnCmd   = signal;
	}
	else //can recover event.
	{
		isoResetMsgToIntLight = signal;
	}

	SetEvent(signal, SGINAL_IDx, EVENT_IDx)
	{
		if (signalsArray[SGINAL_IDx] != signal)
		{
			if (signal)
			{
				eventsArray[EVENT_IDx] = signal;
			}
			signalsArray[SGINAL_IDx] = signal;
		}
	}
	SetEvent((!isoSgl), SGINAL_IDx, EVENT_ISO_RESET_IDx);
	
	
	//! conditions: truth table.
	//! priority: priority table.
	switch, state no more 5. 
	
    if, else if  only use 1 condition. many conditons, use truth table.
	
	SetLightOnTruthTable    = (A && B && C && D);
	SetLightFlashTruthTable = (E && F && G && D);
	if (SetLightOnTruthTable)
	{	LightValue = ON;
	}
	else if (SetLightFlashTruthTable)
	{	LightValue = FLASH;
	}
	else
	{	LightValue = OF;
	}
	
	PriorityTable = (!A && !B && !C && D);
}
//1006.