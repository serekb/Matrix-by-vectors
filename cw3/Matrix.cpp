#include "Matrix.h"
Matrix::Matrix( int nSize, int mSize, double nElem )
{
    try{
        createMat( nSize, mSize );
    }
    catch( VectorException e )
    {
        cout << e.getReason() << endl;
    }
    for( int i = 0; i < getRowNo(); i++)
        m_pVect[i] = Vector( nSize, nElem );                     
}
Matrix::Matrix( const Matrix& m )
{
    mMDim = 0;
    //m_pVect = nullptr;
    m_pVect = new Vector[m.getColNo()];
    *this = m;
}
Matrix::~Matrix()
{
    //delete[] m_pVect;
}
Matrix& Matrix::operator = ( const Matrix& m )
{
    if( this->getColNo() != m.getColNo() )
    {
        //if( !m_pCoord) // nie trzeba bo delete jak napotka nulla to nic nie robi
        delete[] m_pVect;
        createMat( m.getColNo(), m.getRowNo() );
    }
    if( this->getRowNo() != m.getRowNo())
    {
        //if( !m_pCoord) // nie trzeba bo delete jak napotka nulla to nic nie robi
        delete[] m_pVect;
        createMat( m.getColNo(), m.getRowNo() );
    }
    copyMat(m);
    return *this;
}
istream& operator >> ( istream& in, Matrix& m )
{
    for( int i = 0; i < m.getRowNo(); i++ )
        in >> m.m_pVect[i];
    return in;
}
ostream& operator << ( ostream& out, const Matrix& m )
{
    for( int i = 0; i < m.getRowNo(); i++ )
    {
        out << m.m_pVect[i];
        if( i < m.getRowNo() - 1 )
        {
            out << ',';
            out << endl;
        }
    }
    return out;
}
bool operator == ( const Matrix& m1, const Matrix& m2 )
{
    return !( m1 != m2 );
}
bool operator != ( const Matrix& m1, const Matrix& m2 )
{
    if( ( m1.getColNo() != m2.getColNo() ) || (m1.getRowNo() != m2.getRowNo() ) )
        return 1;
    for( int i = 0; i < m1.getColNo(); i++)
        if( m1.m_pVect[i] != m1.m_pVect[i] )
            return 1;
    return 0;
}
const Matrix operator * ( const Matrix& m1, const Matrix& m2 )
{
    if( m1.getColNo() != m2.getRowNo() )
        throw VectorException{ VEC_INCOMPATIBLE_SIZES };
    Matrix res( m1.getRowNo(), m2.getColNo() );
    Vector tmp( m1.getColNo() );
    for( int j = 0; j < m2.getColNo(); j++ )
    {
        for( int k = 0; k< m1.getColNo(); k++ )
            tmp[k] = m2.m_pVect[k][j];
        for( int i =0; i< m1.getRowNo(); i++ )
            res.m_pVect[i][j] = m1.m_pVect[i] * tmp;
    }
    return res;
}
const Vector operator * ( const Matrix& m, const Vector& v )
{
    if( m.getColNo() != v.getDim() )
        throw VectorException{ VEC_INCOMPATIBLE_SIZES };
    Vector res = Vector( m.getRowNo() );
    for( int i=0; i<m.getColNo(); i++ )
        //for( int j=0; j<m.getRowNo(); j++ )
            res[i] = m[i] * v;
    return res;
}
// dodatkowo
//const Vector operator * ( const Vector& v, const Matrix& m )
//{
//    if( v.getDim() != m.getRowNo() )
//        throw VectorException{ VEC_INCOMPATIBLE_SIZES };
//    Vector res = Vector( m.getColNo() );
//    for( int i = 0; i < m.getColNo(); i++ )
//        for( int j = 0; j < m.getRowNo(); j++ )
//            res[i] += v[j] * m[j][i];
//    return res;
//}
    //if( m1.getColNo() != m2.getRowNo() )
    //    throw VectorException{ VEC_INCOMPATIBLE_SIZES };
    //Matrix res = Matrix( m2.getColNo(), m1.getRowNo() );
    //for( int i = 0; i < res.getRowNo(); i++ )
    //    res[i] = m1[i]*m2;
    //return res;