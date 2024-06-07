/* Copyright (c) 2022-2024 Dreamy Cecil
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

// Define plugin
CLASSICSPATCH_DEFINE_PLUGIN(k_EPluginFlagEngine | k_EPluginFlagGame, MakeVersion(1, 0, 0),
  "Dreamy Cecil", "Example Plugin", "This is an example plugin that comes with the source code for Serious Sam Classics Patch.");

// Plugin event handlers
static IProcessingEvents _evProcessing;
static IRenderingEvents _evRendering;
static INetworkEvents _evNetworking;
static IPacketEvents _evPackets;
static IGameEvents _evGame;
static IGameEvents _evDemo;
static IWorldEvents _evWorldEvents;
static IListenerEvents _evListeners;
static ITimerEvents _evTimerEvents;

// Dummy chat command
static BOOL DummyChatCommand(CTString &strResult, INDEX iClient, const CTString &strArguments) {
  strResult.PrintF("Dummy command arguments: '%s'", strArguments);
  return TRUE;
};

// Module entry point
CLASSICSPATCH_PLUGIN_STARTUP(void)
{
  // Register plugin events
  _evProcessing.Register();
  _evRendering.Register();
  _evNetworking.Register();
  _evPackets.Register();
  _evGame.Register();
  _evDemo.Register();
  _evWorldEvents.Register();
  _evListeners.Register();
  _evTimerEvents.Register();

  // Add custom chat command
  ClassicsChat_RegisterCommand("dummy", &DummyChatCommand);
};

// Module cleanup
CLASSICSPATCH_PLUGIN_SHUTDOWN(void)
{
  // Remove custom chat command
  ClassicsChat_UnregisterCommand("dummy");

  // Unregister plugin events
  _evProcessing.Unregister();
  _evRendering.Unregister();
  _evNetworking.Unregister();
  _evPackets.Unregister();
  _evGame.Unregister();
  _evDemo.Unregister();
  _evWorldEvents.Unregister();
  _evListeners.Unregister();
  _evTimerEvents.Unregister();
};
