/*
 *      Copyright (C) 2017 Christian Browet
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "PictureInPictureParams.h"
#include "jutils-details.hpp"

using namespace jni;

static std::string s_builderclassName = "android/app/PictureInPictureParams$Builder";

CJNIPictureInPictureParamsBuilder::CJNIPictureInPictureParamsBuilder()
  : CJNIBase(s_builderclassName)
{
  m_object = new_object(s_builderclassName);
  m_object.setGlobal();
}

CJNIPictureInPictureParamsBuilder CJNIPictureInPictureParamsBuilder::setAspectRatio(const CJNIRational &aspectRatio)
{
  return (CJNIPictureInPictureParamsBuilder)call_method<jhobject>(m_object,
                                                         "setAspectRatio", "(Landroid/util/Rational;)Landroid/app/PictureInPictureParams$Builder;",
														 aspectRatio.get_raw());
}

CJNIPictureInPictureParams CJNIPictureInPictureParamsBuilder::build()
{
  return (CJNIPictureInPictureParams)call_method<jhobject>(m_object,
                                                         "build", "()Landroid/app/PictureInPictureParams;");
}
