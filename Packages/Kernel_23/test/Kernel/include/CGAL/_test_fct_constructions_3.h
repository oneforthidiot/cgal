// Copyright (c) 1999  Utrecht University (The Netherlands),
// ETH Zurich (Switzerland), Freie Universitaet Berlin (Germany),
// INRIA Sophia-Antipolis (France), Martin-Luther-University Halle-Wittenberg
// (Germany), Max-Planck-Institute Saarbruecken (Germany), RISC Linz (Austria),
// and Tel-Aviv University (Israel).  All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; version 2.1 of the License.
// See the file LICENSE.LGPL distributed with CGAL.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $Source$
// $Revision$ $Date$
// $Name$
//
// Author(s)     : Stefan Schirra
 

#ifndef CGAL__TEST_FCT_CONSTRUCTIONS_3_H
#define CGAL__TEST_FCT_CONSTRUCTIONS_3_H

template <class R>
bool
_test_fct_constructions_3(const R&)
{
  typedef typename R::RT             RT;
  typedef typename R::Point_3        Point;
  typedef typename R::Segment_3      Segment;
  typedef typename R::Plane_3        Plane;
  typedef typename R::Vector_3       Vector;
  typedef typename R::Triangle_3     Triangle;
  typedef typename R::Tetrahedron_3  Tetrahedron;

  RT RT0(0);
  RT RT1(1);
  RT RT2(2);
  RT RT4(4);
  RT RT8(8);

  Point p( RT4, RT8, -RT2, RT2);   // ( 2, 4, -1)
  Point p111 = p + Vector( RT1, RT1, RT1 );
  Point p011 = p + Vector(-RT1, RT1, RT1 );
  Point p101 = p + Vector( RT1,-RT1, RT1 );
  Point p001 = p + Vector(-RT1,-RT1, RT1 );
  Point p000 = p + Vector(-RT1,-RT1,-RT1 );
  Point p100 = p + Vector( RT1,-RT1,-RT1 );
  Point p110 = p + Vector( RT1, RT1,-RT1 );
  Point p010 = p + Vector(-RT1, RT1,-RT1 );

  Point p2   = p + Vector(-RT1, RT0, RT0 );
  Point p3   = p + Vector( RT1, RT0, RT0 );
  Point p4   = p + Vector( RT0, RT1, RT0 );

  // midpoint
  assert( CGAL::midpoint( p111, p000) == p);
  assert( CGAL::midpoint( p110, p001) == p);
  assert( CGAL::midpoint( p010, p101) == p);
  assert( CGAL::midpoint( p100, p011) == p);

  // circumcenter
  assert( CGAL::circumcenter( p111, p001, p010, p000) == p);
  assert( CGAL::circumcenter( p101, p001, p010, p100) == p);
  assert( CGAL::circumcenter( p001, p000, p110, p100) == p);
  assert( CGAL::circumcenter( Tetrahedron(p111, p001, p010, p000) ) == p);
  assert( CGAL::circumcenter( Tetrahedron(p101, p001, p010, p100) ) == p);
  assert( CGAL::circumcenter( Tetrahedron(p001, p000, p110, p100) ) == p);

  assert( CGAL::circumcenter( p2, p3, p4 ) == p);
  assert( CGAL::circumcenter( Triangle(p2, p3, p4) ) == p);

  // centroid
  Point p_11 = p + Vector(RT0, RT1, RT1);
  assert( CGAL::centroid( p111, p010, p101, p000) == p);
  assert( CGAL::centroid( p111, p_11, p011 ) == p_11);

  // orthogonal_vector
  Point p0(RT0, RT0, RT0), px1(RT1, RT0, RT0), py1(RT0, RT1, RT0);
  Vector vz1(RT0, RT0, RT1);
  Vector orth = orthogonal_vector(p0, px1, py1);
  assert( (vz1 * orth) > 0 );
  assert( parallel(Segment(p0, p0+orth), Segment(p0, p0+vz1)) );

  orth = orthogonal_vector(Plane(p0, px1, py1));
  assert( (vz1 * orth) > 0 );
  assert( parallel(Segment(p0, p0+orth), Segment(p0, p0+vz1)) );

  // projection onto a plane

  return true;
}

#endif // CGAL__TEST_FCT_CONSTRUCTIONS_3_H
