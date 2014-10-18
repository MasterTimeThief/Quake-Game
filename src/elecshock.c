#include "g_local.h"
 
 
void elecshock(edict_t *ent)
{
	int i;
 
	ent->client->elec_shock_framenum-=1; // subtracts 1 from elec_shock_framenum
	if (ent->client->elec_shock_framenum>0)  // in case I screwed up and this gets called without the person being shocked.
	{
		ent->s.effects |= EF_COLOR_SHELL;
		ent->s.renderfx |= RF_SHELL_BLUE;  // these two lines add a blue shell to the person.
		for (i=0 ; i<3 ; i++)
		{
			 ent->client->kick_origin[i] = crandom() * 0.35;
			 ent->client->kick_angles[i] = crandom() * 0.7;             // make the screen shake increase the multiplier fo the angles for a greater shaking effect
		}
			// unfortunatly you have to add the blueness to thier screen elsewhere (in p_view.c)
	}
	else
	{
	// the last frame will clean up all the effects
		ent->s.effects &= ~EF_COLOR_SHELL;
		ent->s.renderfx &= ~RF_SHELL_BLUE;
	}
}