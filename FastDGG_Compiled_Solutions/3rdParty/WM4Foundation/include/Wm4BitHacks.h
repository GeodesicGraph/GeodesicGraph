// Wild Magic Source Code
// David Eberly
// http://www.geometrictools.com
// Copyright (c) 1998-2007
//
// This library is free software; you can redistribute it and/or modify it
// under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation; either version 2.1 of the License, or (at
// your option) any later version.  The license is available for reading at
// either of the locations:
//     http://www.gnu.org/copyleft/lgpl.html
//     http://www.geometrictools.com/License/WildMagicLicense.pdf
// The license applies to versions 0 through 4 of Wild Magic.
//
// Version: 4.0.0 (2006/06/28)

// Bit hacks are available at
//     http://graphics.stanford.edu/~seander/bithacks.html

#ifndef WM4BITHACKS_H
#define WM4BITHACKS_H

namespace Wm4
{

bool IsPowerOfTwo (int iValue);
unsigned int Log2OfPowerOfTwo (unsigned int uiPowerOfTwo);

#include "Wm4BitHacks.inl"

}

#endif
