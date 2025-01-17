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

#ifndef WM4DISTLINE3BOX3_H
#define WM4DISTLINE3BOX3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Distance.h"
#include "Wm4Line3.h"
#include "Wm4Box3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM DistLine3Box3 : public Distance<Real,Vector3<Real> >
{
public:
    DistLine3Box3 (const Line3<Real>& rkLine, const Box3<Real>& rkBox);

    // object access
    const Line3<Real>& GetLine () const;
    const Box3<Real>& GetBox () const;

    // static distance queries
    virtual Real Get ();
    virtual Real GetSquared ();

    // function calculations for dynamic distance queries
    virtual Real Get (Real fT, const Vector3<Real>& rkVelocity0,
        const Vector3<Real>& rkVelocity1);
    virtual Real GetSquared (Real fT, const Vector3<Real>& rkVelocity0,
        const Vector3<Real>& rkVelocity1);

    // Access to the line parameter for the closest point.  This is used by
    // the ray-box and segment-box distance calculators.
    Real GetLineParameter () const;

private:
    using Distance<Real,Vector3<Real> >::m_kClosestPoint0;
    using Distance<Real,Vector3<Real> >::m_kClosestPoint1;

    void Face (int i0, int i1, int i2, Vector3<Real>& rkPnt,
        const Vector3<Real>& rkDir, const Vector3<Real>& rkPmE,
        Real& rfSqrDistance);

    void CaseNoZeros (Vector3<Real>& rkPnt, const Vector3<Real>& rkDir,
        Real& rfSqrDistance);

    void Case0 (int i0, int i1, int i2, Vector3<Real>& rkPnt,
        const Vector3<Real>& rkDir, Real& rfSqrDistance);

    void Case00 (int i0, int i1, int i2, Vector3<Real>& rkPnt,
        const Vector3<Real>& rkDir, Real& rfSqrDistance);

    void Case000 (Vector3<Real>& rkPnt, Real& rfSqrDistance);

    const Line3<Real>& m_rkLine;
    const Box3<Real>& m_rkBox;
    Real m_fLParam;
};

typedef DistLine3Box3<float> DistLine3Box3f;
typedef DistLine3Box3<double> DistLine3Box3d;

}

#endif
