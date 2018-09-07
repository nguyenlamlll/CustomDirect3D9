#include "stdafx.h"
#include "D3D9Window.h"


D3D9Window::D3D9Window(UINT width, UINT height, std::wstring name) :
	DXBase(width, height, name)
{
}


D3D9Window::~D3D9Window()
{
}

void D3D9Window::OnInit()
{
	LoadPipeline();
	//LoadAssets();
}

void D3D9Window::LoadPipeline()
{
	D3DPRESENT_PARAMETERS d3dpp;    // create a struct to hold various device information
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = FALSE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;    // discard old frames
	d3dpp.hDeviceWindow = Win32Application::GetHwnd();    // set the window to be used by Direct3D
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;    // set the back buffer format to 32-bit
	d3dpp.BackBufferWidth = DXBase::GetWidth();    // set the width of the buffer
	d3dpp.BackBufferHeight = DXBase::GetHeight();    // set the height of the buffer

	// Create the Direct3D API device object and a corresponding context.
	Microsoft::WRL::ComPtr<IDirect3D9> direct3D9;
	direct3D9 = Direct3DCreate9(D3D_SDK_VERSION);

	ThrowIfFailed(direct3D9->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		Win32Application::GetHwnd(),
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		m_3dDevice.ReleaseAndGetAddressOf())
	);

	direct3D9.Reset();
}

// Update frame-based values.
void D3D9Window::OnUpdate()
{
	m_3dDevice->Clear(
		0, 
		NULL, 
		D3DCLEAR_TARGET, 
		D3DCOLOR_XRGB(255, 255, 255), 
		1.0f, 
		0);

	m_3dDevice->BeginScene();
	// ...
	m_3dDevice->EndScene();

	m_3dDevice->Present(
		NULL,
		NULL,
		NULL,
		NULL
	);
}

// Render the scene.
void D3D9Window::OnRender()
{

}

void D3D9Window::OnDestroy()
{
	m_3dDevice = nullptr;
}