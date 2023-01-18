/* Copyright (c) 2022-2023 Dreamy Cecil
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

#include <CoreLib/Interfaces/RenderFunctions.h>
#include <CoreLib/Interfaces/WorldFunctions.h>

// Define processing events for the plugin

void IProcessingEvents::OnStep(void)
{
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

void IProcessingEvents::OnFrame(CDrawPort *pdp)
{
  // Display patch version in menu
  if (GetGameAPI()->IsGameOn()) return;

  const FLOAT fScaling = HEIGHT_SCALING(pdp);

  pdp->SetFont(_pfdDisplayFont);
  pdp->SetTextScaling(fScaling);

  CTString strVersion;
  strVersion.PrintF("^c00ff00Plugin runs on a %s patch!\n", GetAPI()->GetVersion());

  pdp->PutText(strVersion, 16 * fScaling, 32 * fScaling, 0xFFFFFFFF);
};
