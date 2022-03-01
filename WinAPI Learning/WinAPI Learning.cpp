// WinAPI Learning.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include <Windows.h>
#include "WinAPI Learning.h"
#include "tchar.h"


#ifdef _UNICODE
#define _tcslen wcslen 
#else 
#define _tcslen strlen 
#endif /* _UNICODE */

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
// LRESULT - Возвращаемое значение является результатом обработки сообщения и зависит от отправленного сообщения.
// CALLBACK - функция обратного вызова. Определения порядка размещения параметров, передаваемых при вызове функций 
// и возврате в вызывающую программу, в стеке и извлечения из стека.
// 
// HWND - дескриптор (handle - 32-битное беззнаковое число - нужен для идентификации программой того или иного объекта) главного окна программы

TCHAR gWinMain[] = _T("MainFrame");
int APIENTRY wWinMain(HINSTANCE This, HINSTANCE Prev, LPTSTR cmd, int mode)

// APIENTRY либо WINAPI - функция входа.
// (HINSTANCE This) либо (HINSTANCE hInstance) - дескриптор текущего приложения.
// (HINSTANCE Prev) либо HINSTANCE (hPrevInstance) - экз. предыдущего приложения. В соверменных ОС равен 0.
// LPTSTR cmd либо LPTSTR lpCmdLine - указатель на начало командной строки. 
// (int mode) либо (int nCmdShow) - режим отображения окна (прим. свернутый, развернутый).

{
	HWND hWnd;
	//struct MSG 
	//{
	//	HWND hWnd; // дескриптор окна.
	//	UINT message; // номер сообщения.
	//	WPARAM wParam; // Доп. параметры сообщения. 32-разрядные целые.
	//	LPARAM lParam; // ...
	//	DWORD time; // Время посылки сообщения в мс.
	//	POINT pt; // координаты куроса (x,y)
	//};

	MSG msg;
	WNDCLASS wc; // Класс окна
// Определение класса окна 
	wc.hInstance = This; 
	wc.lpszClassName = gWinMain; // Имя класса окна; lpsz - Указывает на строку с символом нуля в конце, которая является текстом окна.
	wc.lpfnWndProc = WndProc; // Адрес функции обработки сообщений; lpfn - Указатель на функцию-обработчик событий диалогового окна.
	wc.style = CS_HREDRAW | CS_VREDRAW; // CS_HREDRAW - перерисовывает все окно, если перемещение или регулировка размера изменяют ширину рабочей области.
	// CS_VREDRAW - Перерисовывает все окно, если перемещение или регулировка размера изменяют высоту рабочей области.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); // Стандаратная иконка.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); // Стандартный курсор.
	wc.lpszMenuName = NULL;
	wc.cbClsExtra = 0; // Допоплнительные данные класса.
	wc.cbWndExtra = 0; // Дополнительные данные окна. 
// Заполнение окна белым цветом 
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	if (!RegisterClass(&wc)) return 0; // Если регистрация класса окна не удалась.
// Создание окна 
	hWnd = CreateWindow(gWinMain, _T("Каркас Win-приложения"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, HWND_DESKTOP, NULL, This, NULL);
	// В скобках параметры создваемого окна ctrl + shift + space описание параметров.
	// WS_OVERLAPPED - Создает перекрывающее окно. Перекрывающее окно имеет заголовок и рамку.
	ShowWindow(hWnd, mode); // Отображаем окно.
// Цикл обработки сообщений 
	while (GetMessage(&msg, 0, NULL, NULL))
	{
		TranslateMessage(&msg); // Переводит сообщения виртуальных клавиш в символьные сообщения.
		DispatchMessage(&msg); // Посылает сообщение фукнции WndProc();
	}
	return 0;
}
// Оконная функция вызывается ОС и получает сообщение из очереди для данного приложения.
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) 
{
	// Обработчик сообщений
	switch (message)
	{
	case WM_DESTROY: 
		PostQuitMessage(0);
		break;
	// Обработчик сообщений по умолчанию
	default: return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}






