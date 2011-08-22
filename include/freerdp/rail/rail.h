/**
 * FreeRDP: A Remote Desktop Protocol Client
 * Remote Applications Integrated Locally (RAIL)
 *
 * Copyright 2011 Marc-Andre Moreau <marcandre.moreau@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __RAIL_H
#define __RAIL_H

#include <freerdp/api.h>
#include <freerdp/rail.h>
#include <freerdp/types.h>
#include <freerdp/update.h>
#include <freerdp/gdi/color.h>
#include <freerdp/utils/stream.h>

typedef struct rdp_rail rdpRail;

#include <freerdp/rail/icon.h>
#include <freerdp/rail/window.h>
#include <freerdp/rail/window_list.h>

typedef void (*railCreateWindow)(rdpRail* rail, rdpWindow* window);
typedef void (*railDestroyWindow)(rdpRail* rail, rdpWindow* window);
typedef void (*railMoveWindow)(rdpRail* rail, rdpWindow* window);
typedef void (*railSetWindowText)(rdpRail* rail, rdpWindow* window);
typedef void (*railSetWindowIcon)(rdpRail* rail, rdpWindow* window, rdpIcon* icon);

struct rdp_rail
{
	void* extra;
	UNICONV* uniconv;
	CLRCONV* clrconv;
	rdpIconCache* cache;
	rdpWindowList* list;
	rdpSettings* settings;
	railCreateWindow CreateWindow;
	railDestroyWindow DestroyWindow;
	railMoveWindow MoveWindow;
	railSetWindowText SetWindowText;
	railSetWindowIcon SetWindowIcon;
};

FREERDP_API void rail_register_update_callbacks(rdpRail* rail, rdpUpdate* update);

FREERDP_API rdpRail* rail_new(rdpSettings* settings);
FREERDP_API void rail_free(rdpRail* rail);

#endif /* __RAIL_H */
