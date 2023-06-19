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

// Define networking events for the plugin

INDEX _ctPacketsReceived = 0;

BOOL INetworkEvents::OnServerPacket(CNetworkMessage &nmMessage, const ULONG ulType)
{
  return FALSE;
};

BOOL INetworkEvents::OnClientPacket(CNetworkMessage &nmMessage, const ULONG ulType)
{
  // Count packets sent by the server
  _ctPacketsReceived++;

  return FALSE;
};

void INetworkEvents::OnAddPlayer(CPlayerTarget &plt, BOOL bLocal)
{
  // Executed each time a new client joins the game and adds their player entities
  // 'bLocal' is TRUE only if it's a player of a local (connecting) client
};

void INetworkEvents::OnRemovePlayer(CPlayerTarget &plt, BOOL bLocal)
{
  // Executed each time a client leaves the game and removes their player entities
  // 'bLocal' is TRUE only if it's a player of a local (disconnecting) client
};
