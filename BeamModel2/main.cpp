#include <iostream>
#include <quaternion.h>
#include <Eigen/Dense>
#include <unsupported/Eigen/CXX11/Tensor>
using namespace std;
using namespace Eigen;

int main() {
	cout << "Hello, world!" << endl;
	Quat<double> q1(1.0,1.1,2.0,3.0);
	Quat<double> q2 = 2*q1;
	Vector3d kappa = 2*q2.Getv();
    cout << kappa[0] << " " << kappa[1] << " " << kappa[2] << endl;

    Vector3d m1;
    m1 << 1.0, 2.0, 3.0;
    Matrix3d m2;
    m2 << 1, 2, 3,
        4,5,6,
        7,8,10;
    m2 = m2*10.0;
    Vector3d m3;
    m3 << 1,1,1;
    for (int i=0; i<10000; i++){
        m3 = m2.partialPivLu().solve(m3);
    }

    Eigen::Tensor<double,5> m4(3,3,3,3,3);
    m4.setZero();
    m4(0,1,2,0,1) = 1.0;
    m4(2,1,0,2,1) = 2.0;
    m1.cross(m3);

    cout << m3.rows() << endl;
    cout << m4 << endl;
	return 0;
}
