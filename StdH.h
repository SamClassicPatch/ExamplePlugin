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

// This switch can be used to toggle direct linkage of the Core library and its features
#define LINK_CORE_LIB 1

#if LINK_CORE_LIB
  // Link the library for direct use
  #include <CoreLib/Core.h>

#else
  // Utilize the API without linking the library
  #include <CoreLib/API/CoreAPI.h>
#endif

// Common functions to use
#include <CoreLib/Interfaces/RenderFunctions.h>
#include <CoreLib/Interfaces/WorldFunctions.h>

#include <CoreLib/Networking/ExtPackets.h>
