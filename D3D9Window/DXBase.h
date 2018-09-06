#pragma once

#include "DXHelper.h"
#include "Win32Application.h"

class DXBase
{
public:
	DXBase(UINT width, UINT height, std::wstring name);
	virtual ~DXBase();

	virtual void OnInit() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnRender() = 0;
	virtual void OnDestroy() = 0;

	// Samples override the event handlers to handle specific messages.
	virtual void OnKeyDown(UINT8 /*key*/) {}
	virtual void OnKeyUp(UINT8 /*key*/) {}

	HRESULT CreateDeviceResources(HWND hWnd);
	HRESULT CreateDeviceResources();
	HRESULT CreateWindowResources(HWND hWnd);

	HRESULT ConfigureBackBuffer();
	HRESULT ReleaseBackBuffer();
	HRESULT GoFullScreen();
	HRESULT GoWindowed();

	float GetAspectRatio();

	//IDirect3DDevice9* GetDevice()
	//{
	//	return m_p3dDevice.Get();
	//}

	// Accessors.
	UINT GetWidth() const { return m_width; }
	UINT GetHeight() const { return m_height; }
	const WCHAR* GetTitle() const { return m_title.c_str(); }

protected:
	//Microsoft::WRL::ComPtr<IDirect3DDevice9> m_p3dDevice;

	// Viewport dimensions.
	UINT m_width;
	UINT m_height;
	float m_aspectRatio;

private:
	// Root assets path.
	std::wstring m_assetsPath;

	// Window title.
	std::wstring m_title;

};

