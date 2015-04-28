/*
* Copyright (c) 2011 Sveriges Television AB <info@casparcg.com>
*
* This file is part of CasparCG (www.casparcg.com).
*
* CasparCG is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* CasparCG is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with CasparCG. If not, see <http://www.gnu.org/licenses/>.
*
* Author: Niklas P Andersson, niklas.p.andersson@svt.se
*/

#ifndef _PSDCHANNEL_H__
#define _PSDCHANNEL_H__

#pragma once

#include "util\bigendian_file_input_stream.h"
#include <memory>

namespace caspar { namespace psd {

struct channel
{
public:
	channel(short id1, unsigned long len) : id(id1), data_length(len) {}

	short id;
	unsigned long data_length;
};

}	//namespace psd
}	//namespace caspar

#endif	//_PSDCHANNEL_H__