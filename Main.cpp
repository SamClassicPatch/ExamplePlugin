/* Copyright (c) 2022 Dreamy Cecil
This program is free software; you can redistribute it and/or modify
it under the terms of version 2 of the GNU General Public License as published by
the Free Software Foundation


This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA. */

#include "StdH.h"

#include <CoreLib/Rendering/RenderFunctions.h>
#include <CoreLib/World/WorldFunctions.h>

// Define own pointer to the API
CCoreAPI *_pCoreAPI = NULL;

// Retrieve module information
MODULE_API void Module_GetInfo(CPluginAPI::PluginInfo *pInfo) {
  // Used API and utility
  pInfo->apiVer = CORE_API_VERSION;
  pInfo->ulFlags = CPluginAPI::PF_ENGINE | CPluginAPI::PF_GAME;

  // Metadata
  pInfo->strAuthor = "Dreamy Cecil";
  pInfo->strName = "Example Plugin";
  pInfo->strDescription = "This is an example plugin that comes with the source code for the Serious Sam Classics patch.";
  pInfo->ulVersion = CCoreAPI::MakeVersion(1, 0, 0);
};

// Module entry point
MODULE_API void Module_Startup(void) {
  // Hook pointer to the API
  HookSymbolAPI();
};

// Module cleanup
MODULE_API void Module_Shutdown(void) {
  InfoMessage("Example plugin shutdown!");
};

MODULE_API void Module_Step(void) {
  // Call every second
  if (ULONG(_pTimer->CurrentTick() / _pTimer->TickQuantum) % 20 != 0) {
    return;
  }

  CPlayerEntities cen;
  IWorld::GetLocalPlayers(cen);

  // Decrease health of each local player if it's higher than 50
  FOREACHINDYNAMICCONTAINER(cen, CPlayerEntity, iten) {
    CPlayerEntity *pen = iten;

    if (pen == NULL) continue;

    if (pen->GetHealth() > 50) {
      pen->SetHealth(pen->GetHealth() - 1);
    }
  }
};

MODULE_API void Module_PostDraw(CDrawPort *pdp) {
  // Display current simulation time
  const FLOAT fScaling = HEIGHT_SCALING(pdp);

  pdp->SetFont(_pfdDisplayFont);
  pdp->SetTextScaling(fScaling);

  CTString strTime;
  strTime.PrintF("Current time: %s", TimeToString(_pTimer->GetLerpedCurrentTick()));

  pdp->PutText(strTime, 16 * fScaling, 32 * fScaling, 0xFFFFFFFF);
};

MODULE_API void Module_Frame(CDrawPort *pdp) {
  // Display patch version in menu
  if (GetGameAPI()->IsGameOn()) return;

  const FLOAT fScaling = HEIGHT_SCALING(pdp);

  pdp->SetFont(_pfdDisplayFont);
  pdp->SetTextScaling(fScaling);

  CTString strVersion;
  strVersion.PrintF("^c00ff00Plugin runs on a %s patch!\n", GetAPI()->GetVersion());

  pdp->PutText(strVersion, 16 * fScaling, 32 * fScaling, 0xFFFFFFFF);
};
