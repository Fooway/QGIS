/***************************************************************************
  qgsvector3d.h
  --------------------------------------
  Date                 : November 2017
  Copyright            : (C) 2017 by Martin Dobias
  Email                : wonder dot sk at gmail dot com
 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSVECTOR3D_H
#define QGSVECTOR3D_H

#include "qgis_core.h"
#include "qgis.h"

/**
 * \ingroup 3d
 * Class for storage of 3D vectors similar to QVector3D, with the difference that it uses double precision
 * instead of single precision floating point numbers.
 *
 * \since QGIS 3.0
 */
class CORE_EXPORT QgsVector3D
{
  public:
    //! Constructs a null vector
    QgsVector3D() = default;

    //! Constructs a vector from given coordinates
    QgsVector3D( double x, double y, double z )
      : mX( x ), mY( y ), mZ( z ) {}

    //! Returns true if all three coordinates are zero
    bool isNull() const { return mX == 0 && mY == 0 && mZ == 0; }

    //! Returns X coordinate
    double x() const { return mX; }
    //! Returns Y coordinate
    double y() const { return mY; }
    //! Returns Z coordinate
    double z() const { return mZ; }

    //! Sets vector coordinates
    void set( double x, double y, double z )
    {
      mX = x;
      mY = y;
      mZ = z;
    }

    bool operator==( const QgsVector3D &other ) const
    {
      return mX == other.mX && mY == other.mY && mZ == other.mZ;
    }
    bool operator!=( const QgsVector3D &other ) const
    {
      return !operator==( other );
    }

    //! Returns sum of two vectors
    QgsVector3D operator+( const QgsVector3D &other ) const
    {
      return QgsVector3D( mX + other.mX, mY + other.mY, mZ + other.mZ );
    }

    //! Returns difference of two vectors
    QgsVector3D operator-( const QgsVector3D &other ) const
    {
      return QgsVector3D( mX - other.mX, mY - other.mY, mZ - other.mZ );
    }

    //! Returns a new vector multiplied by scalar
    QgsVector3D operator *( const double factor ) const
    {

      return QgsVector3D( mX * factor, mY * factor, mZ * factor );
    }

    //! Returns a new vector divided by scalar
    QgsVector3D operator /( const double factor ) const
    {
      return QgsVector3D( mX / factor, mY / factor, mZ / factor );
    }

    //! Returns the dot product of two vectors
    static double dotProduct( const QgsVector3D &v1, const QgsVector3D &v2 )
    {
      return v1.x() * v2.x() + v1.y() * v2.y() + v1.z() * v2.z();
    }

    //! Returns the cross product of two vectors
    static QgsVector3D crossProduct( const QgsVector3D &v1, const QgsVector3D &v2 )
    {
      return QgsVector3D( v1.y() * v2.z() - v1.z() * v2.y(),
                          v1.z() * v2.x() - v1.x() * v2.z(),
                          v1.x() * v2.y() - v1.y() * v2.x() );
    }

    //! Returns the length of the vector
    double length() const
    {
      return sqrt( mX * mX + mY * mY + mZ * mZ );
    }

    //! Normalizes the current vector in place.
    void normalize()
    {
      double len = length();
      if ( !qgsDoubleNear( len, 0.0 ) )
      {
        mX /= len;
        mY /= len;
        mZ /= len;
      }
    }


  private:
    double mX = 0, mY = 0, mZ = 0;
};

#endif // QGSVECTOR3D_H
