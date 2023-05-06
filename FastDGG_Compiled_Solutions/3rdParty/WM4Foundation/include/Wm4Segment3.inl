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

//----------------------------------------------------------------------------
template <class Real>
Segment3<Real>::Segment3 ()
{
    // uninitialized
}
//----------------------------------------------------------------------------
template <class Real>
Segment3<Real>::Segment3 (const Vector3<Real>& rkOrigin,
    const Vector3<Real>& rkDirection, Real fExtent)
    :
    Origin(rkOrigin),
    Direction(rkDirection),
    Extent(fExtent)
{
}
//----------------------------------------------------------------------------
template <class Real>
Vector3<Real> Segment3<Real>::GetPosEnd () const
{
    return Origin + Extent*Direction;
}
//----------------------------------------------------------------------------
template <class Real>
Vector3<Real> Segment3<Real>::GetNegEnd () const
{
    return Origin - Extent*Direction;
}
//----------------------------------------------------------------------------
