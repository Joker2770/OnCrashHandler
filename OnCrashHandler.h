/*************************************************************************
    > File Name: OnCrashHandler.h
    > Author: Jintao Yang
    > Mail: 18608842770@163.com 
    > Created Time: 2020年12月11日 星期五 14时24分31秒
 ************************************************************************/

/*
	A crash handler for C/C++ on Windows and Linux.
	Copyright (C) 2022-2023 joker2770

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License along
	with this program; if not, write to the Free Software Foundation, Inc.,
	51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#ifndef __ON_CRASH_HANDLER_H__
#define __ON_CRASH_HANDLER_H__

#ifdef __cplusplus
extern "C"
{
#endif

    void OnCrashHandler(int signum);
    void EnableCrashHandler(void);

#ifdef __cplusplus
}
#endif

#endif
