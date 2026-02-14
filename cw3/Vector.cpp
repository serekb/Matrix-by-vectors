#include "Vector.h"
Vector::Vector( int nSize, double nElem )
{
    createVec( nSize );
    for( int i =0; i<getDim(); i++ )
        m_pCoord[i] = nElem;
}
Vector::Vector( const Vector& v )
{
    mDim = 0;
    m_pCoord = nullptr;
    *this = v;
}
Vector::~Vector()
{
    delete [] m_pCoord;
}
Vector& Vector::operator = ( const Vector& v )
{
    if( this->getDim() != v.getDim() )
    {
        //if( !m_pCoord) // nie trzeba bo delete jak napotka nulla to nic nie robi
        delete [] m_pCoord;
        createVec( v.getDim() );
    }
    copyVec( v );
    return *this;
}
istream& operator >> ( istream& in, Vector& v )
{
    for( int i=0; i< v.getDim(); i++ )
        in >> v.m_pCoord[i];
    return in;
}
ostream& operator << ( ostream& out, const Vector& v )
{
    out << '[';
    for( int i = 0; i < v.getDim(); i++ )
    {
        out << v.m_pCoord[i];
        if( i < v.getDim()-1 )
            out << ',';
    }
    out << ']';
    return out;
}
const Vector operator + ( const Vector& v1, const Vector& v2 )
{
    Vector res( v1 );
    return res += v2;
}
const Vector operator + ( const Vector& v, double x )
{
    Vector res( v );
    return res += x;
}
const Vector operator + ( double x, const Vector& v )
{
    return v + x;
}
Vector& Vector::operator += ( const Vector& v )
{
    if( this->getDim() != v.getDim() )
        throw VectorException{ VEC_INCOMPATIBLE_SIZES };
    for( int i=0; i<getDim(); i++ )
        m_pCoord[i] += v.m_pCoord[i];

    return *this;
}
Vector& Vector::operator += ( double x )
{
    for( int i = 0; i<getDim(); i++ )
        m_pCoord[i] += x;
    return *this;
}
const Vector operator - ( const Vector& v1, const Vector& v2 )
{
    return v1 + (-v2);
}
const Vector operator - ( const Vector& v, double x )
{
    return v + (-x);
}
Vector& Vector::operator -= ( const Vector& v )
{
    if( this->getDim() != v.getDim() )
        throw VectorException{ VEC_INCOMPATIBLE_SIZES };
    for( int i = 0; i < getDim(); i++ )
        m_pCoord[i] -= v.m_pCoord[i];

    return *this;
}
Vector& Vector::operator -= ( double x )
{
    return *this += (-x);
}
const Vector operator - ( const Vector& v )
{
    Vector res(v);
    for( int i=0; i<v.getDim(); i++ )
        res.m_pCoord[i] = -res.m_pCoord[i];
    return res;
}
const Vector operator * ( const Vector& v, double x )
{
    Vector res(v);
    return res *= x;
}
const Vector operator * ( double x, const Vector& v )
{
    return v*x;
}
Vector& Vector::operator *= ( double x )
{
    for( int i = 0; i < getDim(); i++ )
        m_pCoord[i] *= x;
    return *this;
}

double operator * ( const Vector& v1, const Vector& v2 )
{
    if( v1.getDim() != v2.getDim() )
        throw VectorException{ VEC_INCOMPATIBLE_SIZES };
    double result = 0;
    for( int i=0; i<v1.getDim(); i++ )
        result += v1.m_pCoord[i] * v2.m_pCoord[i];
    return result;
}

bool operator == ( const Vector& v1, const Vector& v2 )
{
    return !(v1 != v2);
}
bool operator != ( const Vector& v1, const Vector& v2 )
{
    if( v1.getDim() != v2.getDim() )
        return 1;
    for( int i =0; i<v1.getDim(); i++)
        if( v1.m_pCoord[i] != v1.m_pCoord[i] )
            return 1;
    return 0;
}