#pragma once
#include "Vector.h"
class Matrix
{
private:
    Vector* m_pVect;
    int mMDim;
public:
    Matrix( int nSize=2, int mSize=2, double nElem=0 );
    Matrix( const Matrix& m );
    virtual ~Matrix();
public:
// gettery
    int getRowNo() const;
    int getColNo() const;
// assignment
    Matrix& operator = ( const Matrix& v );
// we/wy
    friend istream& operator >> ( istream& in, Matrix& m );
    friend ostream& operator << ( ostream& out, const Matrix& m );
// indexation
    Vector& operator [] ( int rowNo );
    const Vector& operator [] ( int rowNo ) const;
// cast to Vector*
    explicit operator Vector* () const { return m_pVect; }
// comparison
    friend bool operator == ( const Matrix& m1, const Matrix& m2 );
    friend bool operator != ( const Matrix& m1, const Matrix& m2 );
// functions
    friend const Matrix operator * ( const Matrix& m1, const Matrix& m2 );
    friend const Vector operator * ( const Matrix& m, const Vector& v );
    //dodatkowo
    //friend const Vector operator * ( const Vector& v, const Matrix& m );
private:
    void createMat( int nSize, int mSize );
    void copyMat( const Matrix& m );
};
// INLINE FUNCTIONS
inline int Matrix::getColNo() const
{
    return m_pVect[0].getDim();
}
inline int Matrix::getRowNo() const
{
    return mMDim;
}
inline void Matrix::createMat( int nSize, int mSize )
{
    if( nSize < 2 )
    {
        nSize = 2;
        cerr << "ERROR: Incorrect number of Columns!\n";
    }
    if( mSize < 2)
    {
        mSize = 2;
        cerr << "ERROR: Incorrect number of Rows!\n";
    }
    mMDim = mSize;
    m_pVect = new Vector[mSize]; // ?
}
inline void Matrix::copyMat( const Matrix& m )
{
    memcpy( this->m_pVect, m.m_pVect, getColNo() * sizeof(Vector));
}
inline Vector& Matrix::operator [] ( int rowNo )
{
    if( rowNo <0 || rowNo>getRowNo() )
    {
        cerr << "ERROR: Index out of range!\n";
        return m_pVect[0]; //niefajne ale kompilator sie nie czepia
    }
    return this->m_pVect[rowNo];
}
inline const Vector& Matrix::operator [] ( int rowNo ) const
{
    if( rowNo <0 || rowNo>getRowNo() )
    {
        cerr << "ERROR: Index out of range!\n";
        return m_pVect[0]; //niefajne ale kompilator sie nie czepia
    }
    return this->m_pVect[rowNo];
}
