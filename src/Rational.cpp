/*
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

#include "Rational.h"

#include "jutils-details.hpp"

using namespace jni;

CJNIRational::CJNIRational() : CJNIBase("android/util/Rational")
{
  m_object = new_object(GetClassName(),
    "<init>", "()V");
}

CJNIRational::CJNIRational(int numerator, int denominator) : CJNIBase("android/util/Rational")
{
  m_object = new_object(GetClassName(),
    "<init>", "(II)V", numerator, denominator);
}

bool CJNIRational::equals(const CJNIRational& other)
{
  return call_method<jboolean>(m_object,
    "equals", "(Ljava/lang/Object;)Z", other.get_raw());
}

std::string CJNIRational::toString() const
{
  return jcast<std::string>(call_method<jhstring>(m_object,
    "toString", "()Ljava/lang/String;"));
}
