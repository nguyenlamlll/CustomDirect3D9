#include "stdafx.h"
#include "DXBase.h"


DXBase::DXBase(UINT width, UINT height, std::wstring name) :
	m_width (width),
	m_height (height),
	m_title (name)
{
	m_aspectRatio = static_cast<float>(width) / static_cast<float>(height);
}


DXBase::~DXBase()
{
}

HRESULT DXBase::CreateDeviceResources(HWND hWnd)
{
	//HRESULT hr = S_OK;

	//// Create the Direct3D API device object and a corresponding context.
	//Microsoft::WRL::ComPtr<IDirect3D9> direct3D9;

	//direct3D9->CreateDevice(
	//	D3DADAPTER_DEFAULT,
	//	D3DDEVTYPE_HAL,
	//	hWnd,
	//	D3DCREATE_SOFTWARE_VERTEXPROCESSING,
	//	NULL,
	//	m_p3dDevice.ReleaseAndGetAddressOf());

	return E_NOTIMPL;
}

HRESULT DXBase::CreateDeviceResources()
{
	return E_NOTIMPL;
}

HRESULT DXBase::CreateWindowResources(HWND hWnd)
{
	return E_NOTIMPL;
}

HRESULT DXBase::ConfigureBackBuffer()
{
	return E_NOTIMPL;
}

HRESULT DXBase::ReleaseBackBuffer()
{
	return E_NOTIMPL;
}

HRESULT DXBase::GoFullScreen()
{
	return E_NOTIMPL;
}

HRESULT DXBase::GoWindowed()
{
	return E_NOTIMPL;
}

float DXBase::GetAspectRatio()
{
	return 0.0f;
}
