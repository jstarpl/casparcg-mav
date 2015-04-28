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


#include "../StdAfx.h"

#include "geometry.h"

namespace caspar { namespace core {

struct frame_geometry::impl
{
	impl(frame_geometry::geometry_type t, std::vector<float> d) : type_(t), data_(std::move(d)) {}
	
	frame_geometry::geometry_type type_;
	std::vector<float> data_;
};

frame_geometry::frame_geometry() {}
frame_geometry::frame_geometry(geometry_type t, std::vector<float> d) : impl_(new impl(t, std::move(d))) {}

frame_geometry::geometry_type frame_geometry::type() const { return impl_ ? impl_->type_ : geometry_type::none; }
const std::vector<float>& frame_geometry::data() const
{
	if (impl_)
		return impl_->data_;
	else
		CASPAR_THROW_EXCEPTION(invalid_operation());
}
	
const frame_geometry& frame_geometry::get_default()
{
	const float d[] = {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f};
	static frame_geometry g(frame_geometry::geometry_type::quad, std::vector<float>(std::begin(d), std::end(d)));

	return g;
}

}}
