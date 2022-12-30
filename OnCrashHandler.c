/*************************************************************************
    > File Name: OnCrashHandler.c
    > Author: Jintao Yang
    > Mail: 18608842770@163.com 
    > Created Time: 2020年12月11日 星期五 14时25分09秒
 ************************************************************************/

/*
	A crash handler for C/C++ on Windows and Linux.
	Copyright (C) 2022 joker2770

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

#include "OnCrashHandler.h"
#include <string.h>
#include <memory.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#ifdef __linux
#include <execinfo.h>
#endif // __linux

const int MAX_STACK_FRAMES = 32;

void OnCrashHandler(int signum)
{
	FILE *f = fopen("crash.txt", "at");
	if (NULL == f)
	{
		exit(1);
		return;
	}

	char szLine[512] = "\0";
	memset(szLine, 0, sizeof(szLine));
	time_t t = time(NULL);
	struct tm *now = localtime(&t);
	int nLen1 = sprintf(szLine, "#########################################################\n[%04d-%02d-%02d %02d:%02d:%02d][crash signal number:%d]\n", now->tm_year + 1900, now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec, signum);

	fwrite(szLine, 1, strlen(szLine), f);

#ifdef __linux
	void *array[MAX_STACK_FRAMES];
	size_t size = 0;
	char **strings = NULL;
	size_t i, j;

	signal(signum, SIG_DFL);
	size = backtrace(array, MAX_STACK_FRAMES);
	strings = (char **)backtrace_symbols(array, size);
	// fprintf(stderr, "oncrash;\n");

	for (i = 0; i < size; ++i)
	{
#if 0
			std::string symbol(strings[i]);
			std::string::size_type pos1 = symbol.find_first_of("[");
			std::string::size_type pos2 = symbol.find_last_of("]");
			std::string address = symbo.substr(pos1 + 1, pos2 - pos1 -1);
			char cmd[128] = {0, };
			sprintf(cmd, "addr2line -e gameserver %p", address.c_str());
			system(cmd);
#endif
		char szLine[512] = {
			0,
		};
		sprintf(szLine, "%lu %s\n", i, strings[i]);
		fwrite(szLine, 1, strlen(szLine), f);
		// fprintf(stderr, "%d %s\n",i, strings[i]);
	}
	free(strings);
#endif // __linux

	fflush(f);
	fclose(f);
	f = NULL;

	exit(1);
}

void EnableCrashHandler(void)
{
#ifdef __linux
	signal(SIGSEGV, OnCrashHandler);
	signal(SIGABRT, OnCrashHandler);
#endif // __linux
}
