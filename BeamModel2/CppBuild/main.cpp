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
    unsigned int cntr = 0;
    for (unsigned int i = 0; i < 3; i++){
        for (unsigned int j = 0; j < 3; j++){
            for (unsigned int k = 0; k < 3; k++){
                for (unsigned int l = 0; l < 3; l++){
                    for (unsigned int m = 0; m < 3; m++){
                            cntr += 1;
                            m4(i,j,k,l,m) = 1.0*cntr;
                    }
                }
            }
        }
    }

    cout << m4(2,1,1,2,1) << endl;
    cout << m4 << endl;
    cout << sizeof(m4) << endl;
	return 0;
}
