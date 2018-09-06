#pragma once

#include <d3d9.h>
#include <wrl.h>

template <typename T>
class DesktopWindow : public CWindowImpl<DesktopWindow<T>, CWindow, CWinTraits<WS_OVERLAPPEDWINDOW | WS_VISIBLE>>
{
public:
	DesktopWindow();
	~DesktopWindow();
	DECLARE_WND_CLASS_EX(nullptr, CS_HREDRAW | CS_VREDRAW, -1);
	void Run();

protected:

private:
	Microsoft::WRL::ComPtr<IDirect3D9> m_direct3D9;

};

