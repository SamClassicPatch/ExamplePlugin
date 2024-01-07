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

#if !LINK_CORE_LIB
  // Define own pointer to the API
  CCoreAPI *_pCoreAPI = NULL;
#endif

// Plugin event handlers
static IProcessingEvents _evProcessing;
static IRenderingEvents _evRendering;
static INetworkEvents _evNetworking;
static IGameEvents _evGame;
static IGameEvents _evDemo;
static IWorldEvents _evWorldEvents;
static IListenerEvents _evListeners;

// Dummy chat command
static void DummyChatCommand(CTString &strResult, const CTString &strArguments) {
  strResult.PrintF("Dummy command arguments: '%s'", strArguments);
};

// Retrieve module information
MODULE_API void Module_GetInfo(CPluginInfo &info) {
  // Utility flags
  info.SetUtility(PLF_ENGINE | PLF_GAME);

  // Metadata
  info.strAuthor = "Dreamy Cecil";
  info.strName = "Example Plugin";
  info.strDescription = "This is an example plugin that comes with the source code for Serious Sam Classics Patch.";
  info.ulVersion = CCoreAPI::MakeVersion(1, 0, 0);
};

// Module entry point
MODULE_API void Module_Startup(void) {
  // Hook pointer to the API
  HookSymbolAPI();
  
  // Register plugin events
  _evProcessing.Register();
  _evRendering.Register();
  _evNetworking.Register();
  _evGame.Register();
  _evDemo.Register();
  _evWorldEvents.Register();
  _evListeners.Register();

  // Add custom chat command
  GetPluginAPI()->RegisterChatCommand("dummy", &DummyChatCommand);
};

// Module cleanup
MODULE_API void Module_Shutdown(void) {
  // Remove custom chat command
  GetPluginAPI()->UnregisterChatCommand("dummy");

  // Unregister plugin events
  _evProcessing.Unregister();
  _evRendering.Unregister();
  _evNetworking.Unregister();
  _evGame.Unregister();
  _evDemo.Unregister();
  _evWorldEvents.Unregister();
  _evListeners.Unregister();
};
