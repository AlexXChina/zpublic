// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#define  _CRT_SECURE_NO_WARNINGS

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include "def.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "detours/src/detver.h"
#include "detours/src/detours.h"

#include "z_lua_bind/z_lua_bind.h"
