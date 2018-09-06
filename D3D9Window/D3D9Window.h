#pragma once

#include "DXBase.h"

using Microsoft::WRL::ComPtr;

class D3D9Window : public DXBase
{
public:
	D3D9Window(UINT width, UINT height, std::wstring name);
	~D3D9Window();

	virtual void OnInit();
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnDestroy();

private:
	ComPtr<IDirect3DDevice9> m_3dDevice;

	void LoadPipeline();
};

