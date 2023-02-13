/**
* @file    AntiRanSomware user mode engine
* @brief
* @ref
* @author  Yonhgwhan, Roh (fixbrain@gmail.com)
* @date    2017/01/21 created.
* @copyright All rights reserved by Yonghwan, Roh.
**/
#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

//
// std
//
#include <sstream>
#include <list>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>



// 
// boost
//
#define BOOST_LIB_DIAGNOSTIC


//
// windows headers
//

#include <WinSock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>

#include <Windows.h>
#include <VersionHelpers.h>
#include <crtdbg.h>
#include <stdint.h>
#include <strsafe.h>
#include <winioctl.h>
#include <dontuse.h>

#include <conio.h>
#include <winioctl.h>
//#include <winnt.h>


//
// _my_lib
// 
