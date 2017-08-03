#pragma once
#include <iostream>
#include <windows.h>

inline std::ostream& light_blue(std::ostream &s) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFFF0;
    SetConsoleTextAttribute(hStdout, ColorAttrs | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    return s;
}

inline std::ostream& light_red(std::ostream &s) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFFF0 | FOREGROUND_RED | FOREGROUND_INTENSITY;
    SetConsoleTextAttribute(hStdout, ColorAttrs);
    return s;
}

inline std::ostream& light_green(std::ostream &s) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFFF0;
    SetConsoleTextAttribute(hStdout, ColorAttrs | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    return s;
}

inline std::ostream& light_cyan(std::ostream &s) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFFF0;
	SetConsoleTextAttribute(hStdout, ColorAttrs | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	return s;
}

inline std::ostream& light_magenta(std::ostream &s) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFFF0;
	SetConsoleTextAttribute(hStdout, ColorAttrs | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	return s;
}

inline std::ostream& light_yellow(std::ostream &s) {

	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFFF0;
    SetConsoleTextAttribute(hStdout, ColorAttrs | FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
    return s;
}

inline std::ostream& white(std::ostream &s) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFFF0;
    SetConsoleTextAttribute(hStdout, ColorAttrs | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    return s;
}

inline std::ostream& black(std::ostream &s) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFFF0;
	SetConsoleTextAttribute(hStdout, ColorAttrs);
	return s;
}

inline std::ostream& blue(std::ostream &s) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFFF0;
	SetConsoleTextAttribute(hStdout, ColorAttrs | FOREGROUND_BLUE);
	return s;
}

inline std::ostream& red(std::ostream &s) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFFF0;
	SetConsoleTextAttribute(hStdout, ColorAttrs | FOREGROUND_RED );
	return s;
}

inline std::ostream& green(std::ostream &s) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFFF0;
	SetConsoleTextAttribute(hStdout, ColorAttrs | FOREGROUND_GREEN);
	return s;
}

inline std::ostream& cyan(std::ostream &s) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFFF0;
	SetConsoleTextAttribute(hStdout, ColorAttrs | FOREGROUND_GREEN | FOREGROUND_BLUE);
	return s;
}

inline std::ostream& magenta(std::ostream &s) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFFF0;
	SetConsoleTextAttribute(hStdout, ColorAttrs | FOREGROUND_BLUE | FOREGROUND_RED);
	return s;
}

inline std::ostream& yellow(std::ostream &s) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFFF0;
	SetConsoleTextAttribute(hStdout, ColorAttrs | FOREGROUND_GREEN | FOREGROUND_RED);
	return s;
}

inline std::ostream& grey(std::ostream &s) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFFF0;
	SetConsoleTextAttribute(hStdout, ColorAttrs | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	return s;
}

inline std::ostream& on_light_blue(std::ostream &s) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFF0F;
	SetConsoleTextAttribute(hStdout, ColorAttrs | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	return s;
}

inline std::ostream& on_light_red(std::ostream &s) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFF0F;
	SetConsoleTextAttribute(hStdout, ColorAttrs | BACKGROUND_RED | BACKGROUND_INTENSITY);
	return s;
}

inline std::ostream& on_light_green(std::ostream &s) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFF0F;
	SetConsoleTextAttribute(hStdout, ColorAttrs | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	return s;
}

inline std::ostream& on_light_cyan(std::ostream &s) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFF0F;
	SetConsoleTextAttribute(hStdout, ColorAttrs | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	return s;
}

inline std::ostream& on_light_magenta(std::ostream &s) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFF0F;
	SetConsoleTextAttribute(hStdout, ColorAttrs | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY);
	return s;
}

inline std::ostream& on_light_yellow(std::ostream &s) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFF0F;
	SetConsoleTextAttribute(hStdout, ColorAttrs | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	return s;
}

inline std::ostream& on_white(std::ostream &s) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFF0F;
	SetConsoleTextAttribute(hStdout, ColorAttrs | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	return s;
}

inline std::ostream& on_blue(std::ostream &s) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFF0F | BACKGROUND_BLUE;
	SetConsoleTextAttribute(hStdout, ColorAttrs);
	return s;
}

inline std::ostream& on_red(std::ostream &s) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFF0F;
	SetConsoleTextAttribute(hStdout, ColorAttrs | BACKGROUND_RED);
	return s;
}

inline std::ostream& on_green(std::ostream &s) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFF0F;
	SetConsoleTextAttribute(hStdout, ColorAttrs | BACKGROUND_GREEN);
	return s;
}

inline std::ostream& on_cyan(std::ostream &s) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFF0F;
	SetConsoleTextAttribute(hStdout, ColorAttrs | BACKGROUND_GREEN | BACKGROUND_BLUE);
	return s;
}

inline std::ostream& on_magenta(std::ostream &s) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFF0F;
	SetConsoleTextAttribute(hStdout, ColorAttrs | BACKGROUND_BLUE | BACKGROUND_RED);
	return s;
}

inline std::ostream& on_yellow(std::ostream &s) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFF0F;
	SetConsoleTextAttribute(hStdout, ColorAttrs | BACKGROUND_GREEN | BACKGROUND_RED);
	return s;
}

inline std::ostream& on_grey(std::ostream &s) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFF0F;
	SetConsoleTextAttribute(hStdout, ColorAttrs | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	return s;
}

inline std::ostream& on_black(std::ostream &s) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	WORD ColorAttrs = csbiInfo.wAttributes & 0xFF0F;
	SetConsoleTextAttribute(hStdout, ColorAttrs);
	return s;
}
///////////////////////////////////
struct color {
    color(WORD attribute):m_color(attribute){};
    WORD m_color;
};

template <class _Elem, class _Traits>
std::basic_ostream<_Elem,_Traits>& operator<<(std::basic_ostream<_Elem,_Traits>& i, color& c) {
    HANDLE hStdout=GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(hStdout,c.m_color);
    return i;
}