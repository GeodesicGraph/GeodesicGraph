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

#ifndef WM4DISTRAY3TRIANGLE3_H
#define WM4DISTRAY3TRIANGLE3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Distance.h"
#include "Wm4Ray3.h"
#include "Wm4Triangle3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM DistRay3Triangle3
    : public Distance<Real,Vector3<Real> >
{
public:
    DistRay3Triangle3 (const Ray3<Real>& rkRay,
        const Triangle3<Real>& rkTriangle);

    // object access
    const Ray3<Real>& GetRay () const;
    const Triangle3<Real>& GetTriangle () const;

    // static distance queries
    virtual Real Get ();
    virtual Real GetSquared ();

    // function calculations for dynamic distance queries
    virtual Real Get (Real fT, const Vector3<Real>& rkVelocity0,
        const Vector3<Real>& rkVelocity1);
    virtual Real GetSquared (Real fT, const Vector3<Real>& rkVelocity0,
        const Vector3<Real>& rkVelocity1);

    // Information about the closest points.
    Real GetRayParameter () const;
    Real GetTriangleBary (int i) const;

private:
    using Distance<Real,Vector3<Real> >::m_kClosestPoint0;
    using Distance<Real,Vector3<Real> >::m_kClosestPoint1;

    const Ray3<Real>& m_rkRay;
    const Triangle3<Real>& m_rkTriangle;

    // Information about the closest points.
    Real m_fRayParameter;  // closest0 = ray.origin+param*ray.direction
    Real m_afTriangleBary[3];  // closest1 = sum_{i=0}^2 bary[i]*tri.vertex[i]
};

typedef DistRay3Triangle3<float> DistRay3Triangle3f;
typedef DistRay3Triangle3<double> DistRay3Triangle3d;

}

#endif
