#pragma once
#include <iostream>
using namespace std;

#define VEC_OTHER_ERROR 0xFF
#define VEC_ALLOC_ERROR 0x01
#define VEC_SIZE_ERROR 0x02
#define VEC_INDEX_OUT_OF_RANGE 0x04
#define VEC_INCOMPATIBLE_SIZES 0x08
typedef short int USHORT;
class VectorException
{
public:
    VectorException( USHORT errCode = VEC_OTHER_ERROR ) { mErrCode = errCode; }
    const char* getReason();
private:
    USHORT mErrCode;
};
inline const char* VectorException::getReason()
{
    switch( mErrCode )
    {
    case VEC_OTHER_ERROR: return "ERROR: other ERROR\n";
    case VEC_ALLOC_ERROR: return "ERROR: allocating memory error\n";
    case VEC_SIZE_ERROR: return "ERROR: improper vector size\n";
    case VEC_INDEX_OUT_OF_RANGE: return "ERROR: index out of bounds\n";
    case VEC_INCOMPATIBLE_SIZES:return "ERROR: improper vector sizes\n";
    default: return "Other ERROR than other ERROR\n";
    }
}

class Vector
{
private:
    double* m_pCoord;
    int mDim;
public:
    explicit Vector( int nSize=2, double nElem = 0 ); //explicit - wyrzuci blad jesli bedzie musial cos zrzutowac niejawnie
    Vector( const Vector& v );
    virtual ~Vector();

    int getDim() const;
//assignment
    Vector& operator = ( const Vector& v ); //v1 = v2 === v1.operator = (v2)
// we/wy
    friend istream& operator >> ( istream& in, Vector& v );
    friend ostream& operator << ( ostream& out, const Vector& v );

// addition
    // v1 + v2 // --- funkcja globalna a nie wywolywana na wektorze
    friend const Vector operator + ( const Vector& v1, const Vector& v2 ); 
    friend const Vector operator + ( const Vector& v, double x );     // v1 + 4
    friend const Vector operator + ( double x, const Vector& v );    // 4 + v1
    Vector& operator += ( const Vector& v );    // v1 += v2 ---- edycja v1
    Vector& operator += ( double x );    // v += 4
// substraction
    friend const Vector operator - ( const Vector& v1, const Vector& v2 );
    friend const Vector operator - ( const Vector& v, double x );
    Vector& operator -= ( const Vector& v );
    Vector& operator -= ( double x );
//unary minus (-v)
    friend const Vector operator - ( const Vector& v );
// multiplication
    friend const Vector operator * ( const Vector& v, double x );// v * 4
    friend const Vector operator * ( double x, const Vector& v );// 4 * v
    Vector& operator *= ( double x );// v *= 4

// scalar multiplication
    friend double operator * ( const Vector& v1, const Vector& v2 );

// comparison
    friend bool operator == ( const Vector& v1, const Vector& v2 );
    friend bool operator != ( const Vector& v1, const Vector& v2 );

//cast to double*
    explicit operator double* () const { return m_pCoord; }
// indexation
    double& operator [] ( int ix );
    const double& operator [] ( int ix ) const;

private:
    void createVec( int nSize );
    void copyVec( const Vector& v );
};

inline int Vector::getDim() const
{
    return mDim;
}
inline void Vector::createVec( int nSize )
{
    if( nSize < 2 )
    {
        nSize = 2;
        throw VectorException{VEC_ALLOC_ERROR}; // nie zwracamy
    }
    mDim = nSize;
    m_pCoord = new double[mDim];
}
inline void Vector::copyVec( const Vector& v )
{
    memcpy( this->m_pCoord, v.m_pCoord, getDim()*sizeof( double ));
}
inline double& Vector::operator [] ( int ix )
{
    if( ix <0 || ix>getDim() )
        throw VectorException{VEC_INDEX_OUT_OF_RANGE};
    return this->m_pCoord[ix];
}
inline const double& Vector::operator [] ( int ix ) const
{
    if( ix <0 || ix>getDim() )
        throw VectorException{ VEC_INDEX_OUT_OF_RANGE };
    return this->m_pCoord[ix];
}
// Jakie struktury danych reprezentuj¹ce obiekt klasy
// Konstrukcja obiektów
// Destrukcja (zwykle gdy s¹ struktury dynamiczne, albo gdy chcemy w klasie mieæ wirtualn¹ funkcjê)
// settery, gettery
// operator podstawienia (na pewno gdy sk³adowa dynamiczna) - wywo³any z konstruktora kopiuj¹cego
// mo¿na dodaæ operatory we/wy
// inne operatory (jeœli s¹ potrzebne)
// pozosta³e metody publiczne do manipulacji obiektami tej klasy
// jak trzeba to metody prywatne

