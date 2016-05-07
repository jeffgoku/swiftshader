// Copyright 2016 The SwiftShader Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef D3D9_Direct3D9Ex_hpp
#define D3D9_Direct3D9Ex_hpp

#include "Direct3D9.hpp"

//#include <stdio.h>
#include <d3d9.h>

namespace D3D9
{
	class Direct3DDevice9;

	class Direct3D9Ex : public IDirect3D9Ex, public Direct3D9
	{
	public:
		Direct3D9Ex(int version, const HINSTANCE instance);

		virtual ~Direct3D9Ex();

		// IUnknown methods
		long __stdcall QueryInterface(const IID &iid, void **object);
		unsigned long __stdcall AddRef();
		unsigned long __stdcall Release();

		// IDirect3D9 methods
		long __stdcall RegisterSoftwareDevice(void *initializeFunction);
		unsigned int __stdcall GetAdapterCount();
		long __stdcall GetAdapterIdentifier(unsigned int adapter, unsigned long flags, D3DADAPTER_IDENTIFIER9 *identifier);
		unsigned int __stdcall GetAdapterModeCount(unsigned int adapter, D3DFORMAT format);
		long __stdcall EnumAdapterModes(unsigned int adapter, D3DFORMAT format, unsigned int index, D3DDISPLAYMODE *mode);
		long __stdcall GetAdapterDisplayMode(unsigned int adapter, D3DDISPLAYMODE *mode);
		long __stdcall CheckDeviceType(unsigned int adapter, D3DDEVTYPE checkType, D3DFORMAT displayFormat, D3DFORMAT backBufferFormat, int windowed);
		long __stdcall CheckDeviceFormat(unsigned int adapter, D3DDEVTYPE deviceType, D3DFORMAT adapterFormat, unsigned long usage, D3DRESOURCETYPE type, D3DFORMAT checkFormat);
		long __stdcall CheckDeviceMultiSampleType(unsigned int adapter, D3DDEVTYPE deviceType, D3DFORMAT surfaceFormat, int windowed, D3DMULTISAMPLE_TYPE multiSampleType, unsigned long *qualityLevels);
		long __stdcall CheckDepthStencilMatch(unsigned int adapter, D3DDEVTYPE deviceType, D3DFORMAT adapterFormat, D3DFORMAT renderTargetFormat, D3DFORMAT depthStencilFormat);
		long __stdcall CheckDeviceFormatConversion(unsigned int adapter, D3DDEVTYPE deviceType, D3DFORMAT sourceFormat, D3DFORMAT targetFormat);
		long __stdcall GetDeviceCaps(unsigned int adapter, D3DDEVTYPE deviceType, D3DCAPS9 *caps);
		HMONITOR __stdcall GetAdapterMonitor(unsigned int adapter);
		long __stdcall CreateDevice(unsigned int adapter, D3DDEVTYPE deviceType, HWND focusWindow, unsigned long behaviorFlags, D3DPRESENT_PARAMETERS *presentParameters, IDirect3DDevice9 **returnedDeviceInterface);

		// IDirect3D9Ex methods
		unsigned int __stdcall GetAdapterModeCountEx(unsigned int adapter, const D3DDISPLAYMODEFILTER *filter);
		long __stdcall EnumAdapterModesEx(unsigned int adapter, const D3DDISPLAYMODEFILTER *filter, unsigned int index, D3DDISPLAYMODEEX *mode);
		long __stdcall GetAdapterDisplayModeEx(unsigned int adapter, D3DDISPLAYMODEEX *mode, D3DDISPLAYROTATION *rotation);
		long __stdcall CreateDeviceEx(unsigned int adapter, D3DDEVTYPE deviceType, HWND focusWindow, DWORD behaviorFlags, D3DPRESENT_PARAMETERS *presentParameters, D3DDISPLAYMODEEX *fullscreenDisplayMode, IDirect3DDevice9Ex **returnedDeviceInterface);
		long __stdcall GetAdapterLUID(unsigned int adapter, LUID *luid);

	private:
		void loadSystemD3D9ex();

		// Real IDirect3D9Ex object
		IDirect3D9Ex *d3d9ex;
	};
}

#endif   // D3D9_Direct3D9Ex_hpp
