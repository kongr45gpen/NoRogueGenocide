// NoRogueGenocide.cpp : Defines the entry point for the DLL application.
//

#include <iostream>
#include "bzfsAPI.h"
#include "plugin_utils.h"

class NoRogueGenocide : public bz_Plugin
{
public:
  virtual const char* Name (){return "No Rogue Genocide";}
  virtual void Init ( const char* config);

  virtual void Event ( bz_EventData *  eventData );

  bool silentMode;
  bool seamlessMode;
};

BZ_PLUGIN(NoRogueGenocide)

void NoRogueGenocide::Init ( const char* commandLine )
{
  bz_debugMessage(4,"NoRogueGenocide plugin loaded");

  std::string param = bz_tolower(commandLine);

  silentMode = (param == "silent" || param == "quiet");
  seamlessMode = (param == "seamless" || param == "hidden");

  Register(bz_eFlagGrabbedEvent);
  Register(bz_eShotFiredEvent);
}

void NoRogueGenocide::Event ( bz_EventData * eventData )
{
  std::string geno = "G";

  switch (eventData->eventType) {
    case bz_eFlagGrabbedEvent: {
      bz_FlagGrabbedEventData_V1	*grabData = (bz_FlagGrabbedEventData_V1*)eventData;

      std::string flagType = bz_getFlagName(grabData->flagID).c_str();

      // Do nothing if we are on seamless mode
      if (seamlessMode) return;

      // Do nothing if the flag isn't Genocide
      if (flagType != geno) return;

      // Do nothing if the player is not a rogue
      if (bz_getPlayerTeam(grabData->playerID) != eRogueTeam) return;

      if (!silentMode) bz_sendTextMessage(BZ_SERVER, grabData->playerID, "You can't pick up Genocide if you are a rogue!");

      bz_removePlayerFlag(grabData->playerID);

    } break;

    case bz_eShotFiredEvent: {
      bz_ShotFiredEventData_V1	*shotData = (bz_ShotFiredEventData_V1*)eventData;

      std::string shotType = shotData->type.c_str();

      // Do nothing if the shot doesn't originate from a geno flag
      if (shotType != geno) return;

      // Do nothing if the player is not a rogue
      if (bz_getPlayerTeam(shotData->playerID) != eRogueTeam) return;

      // Convert the shot to a regular one
      shotData->type = "G";
      shotData->changed = true;

    } break;

    default:
    return;
  }
}

// Local Variables: ***
// mode:C++ ***
// tab-width: 8 ***
// c-basic-offset: 2 ***
// indent-tabs-mode: t ***
// End: ***
// ex: shiftwidth=2 tabstop=8

