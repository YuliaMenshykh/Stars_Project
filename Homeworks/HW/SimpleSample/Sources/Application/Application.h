#pragma once

#include "Drawable/Drawable.h"
#include "Sprite/Sprite.h"

class Application final
{
public:
	// default {ctor} and {dtor}
	//
	Application();
	~Application();

	// lock copy and assigment
	//
	Application( const Application& other ) = delete;
	Application& operator=( const Application& other ) = delete;

	// initing window and ogl context
	//
	void Init();

	// mouse callback
	//
	void Mouse( float x, float y );
	void MouseClick( bool isLeft );

	// keyboard callback
	//
	void Key( unsigned char key, bool bIsPressed );

	// frame app
	//
	void Frame();

	// draw callback from ogl
	//
	void Draw();

	// draw callback from ogl
	//
	void Clean(Sprite& spr);

	// start of window's entry point here
	//
	void EntryPoint();
protected:
	// making window
	//
	void _MakeWindow( std::string sTitle, unsigned int uiWidth, unsigned int uiHeight );
public:
	// windows proc
	// exception for window proc call
	//
	LRESULT WindowProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );

protected:
	// create ogl context and surface
	//
	void _InitOGL();

protected:
	// window handle
	//
	HWND _hwnd;

	/// EGL context
	//
	EGLContext eglContext;

	/// EGL display
	//
	EGLDisplay eglDisplay;
	EGLSurface eglSurface;

	// drawable primitive
	// 
	Drawable _drawable;

	// sprite to draw
	
	std::vector<Sprite> _sprite;
	//unsigned int _uiSprites;

	// for primitive timer
	//
	ULONGLONG _lastTime;
	ULONGLONG _curTime;

	// max RGB value
	const float MaxColValue = 255.0;
};