#include <iostream>
using namespace std;
#include "Vector.h"
#include "Matrix.h"

int main()
{
    //Vector v1;
    //cout << "v1 = " << v1 << endl;
    Vector v2( 3, 3 );
    //cout << "v2 = " << v2 << endl;
    //Vector v3( 4,2 );
    //Vector v4( v3 ); // albo Vector v4 = v3 to samo
    //cout << "v4 = " << v4 << endl;

    //v2 = v4;
    //cout << "v2 = " << v2 << endl;

    //v1 = v2 + v3;
    //cout << "v1(v2 + v3) = " << v1 << endl;

    //cout << "Podaj wspolrzedne wektora o rozmiarze " << v2.getDim() << " : ";
    //cin >> v2;
    //cout << "v2 = " << v2 << endl;

    //v1  = v2 + v4 - 3;
    ////v1 = v1 + (-3);
    //cout << "v1(v2 + v4 -3) = " << v1 << endl;

    //v1[1] = -v1[2] * 2;
    //cout << "v1[1] = -v1[2] * 2 = " << v1 << endl;
    //cout << "v1*v2 = " << v1*v2 << endl;
    try {
    Matrix m1;
    cout << "m1 = \n" << m1 << endl;
    Matrix m2( 3, 2 );
    cout << "\nm2 = \n" << m2 << endl;
    cout << "\nPodaj " << m2.getRowNo() << " wektory o rozmiarze " << m2.getColNo() << " : ";
    cin >> m2;
    cout << "\nm2 = \n" << m2 << endl;
    Matrix m3( 2, 3 );
    cout << "\nPodaj " << m3.getRowNo() << " wektory o rozmiarze " << m3.getColNo() << " : ";
    cin >> m3;
    cout << "\nm3 = \n" << m3 << endl;
    Matrix m4( m2 ); // macierz m4 = m2
    cout << "\nm4 = \n" << m4 << endl;
    m1 = m4;
    cout << "\nm1 = \n" << m1 << endl;
    m1 = m2 * m3;
    cout << "\nm1 = (m2 * m3) = \n" << m1 << endl;
    //m1 = m2 * m4;
    //cout << "m1 = m2 * m4 = \n" << m1 << endl;
    //v1 = v1 + (-3);
    //cout << "v1(v2 + v4 -3) = " << m1 << endl;

    m1[1] = -m1[0] * 2;
    cout << "\nm1[1] = -m1[0] * 2 = \n" << m1[1] << endl;
    cout << "\nm1 = \n" << m1 << endl;
    //cout << "v1[1] = -v1[2] * 2 = " << v1 << endl;
    //cout << "v1*v2 = " << v1 * v2 << endl;
    }
    catch( VectorException vException )
    {
        cout << vException.getReason() << endl;
    }
    return 0;
}
