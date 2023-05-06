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

#ifndef WM4INTRRAY3CYLINDER3_H
#define WM4INTRRAY3CYLINDER3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Intersector.h"
#include "Wm4Ray3.h"
#include "Wm4Cylinder3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntrRay3Cylinder3
    : public Intersector<Real,Vector3<Real> >
{
public:
    IntrRay3Cylinder3 (const Ray3<Real>& rkRay,
        const Cylinder3<Real>& rkCylinder);

    // object access
    const Ray3<Real>& GetRay () const;
    const Cylinder3<Real>& GetCylinder () const;

    // static intersection query
    virtual bool Find ();

    int GetQuantity () const;
    const Vector3<Real>& GetPoint (int i) const;

private:
    using Intersector<Real,Vector3<Real> >::IT_EMPTY;
    using Intersector<Real,Vector3<Real> >::IT_POINT;
    using Intersector<Real,Vector3<Real> >::IT_SEGMENT;
    using Intersector<Real,Vector3<Real> >::m_iIntersectionType;

    // the objects to intersect
    const Ray3<Real>& m_rkRay;
    const Cylinder3<Real>& m_rkCylinder;

    // information about the intersection set
    int m_iQuantity;
    Vector3<Real> m_akPoint[2];
};

typedef IntrRay3Cylinder3<float> IntrRay3Cylinder3f;
typedef IntrRay3Cylinder3<double> IntrRay3Cylinder3d;

}

#endif