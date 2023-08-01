/* Copyright (c) 2023 Dreamy Cecil
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

#include <CoreLib/Objects/PropertyPtr.h>

// Define game events for the plugin

void IGameEvents::OnGameStart(void)
{
  // Find all beheads and replace them with kamikazes
  CEntities cenHeadmen;
  IWorld::FindClassesByID(IWorld::GetWorld()->wo_cenEntities, cenHeadmen, 303); // CHeadman_ClassID

  FOREACHINDYNAMICCONTAINER(cenHeadmen, CEntity, iten) {
    CEntity *pen = iten;

    // Find property offset within CHeadman class by name
    static CPropertyPtr pptrType(pen);

    if (pptrType.ByName(CEntityProperty::EPT_ENUM, "Type"))
    {
      ENTITYPROPERTY(pen, pptrType.Offset(), INDEX) = 3;
      iten->Reinitialize();
    }
  }
};

void IGameEvents::OnChangeLevel(void)
{
};

void IGameEvents::OnGameStop(void)
{
};

void IGameEvents::OnGameSave(const CTFileName &fnmSave)
{
};

void IGameEvents::OnGameLoad(const CTFileName &fnmSave)
{
};
