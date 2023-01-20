#include <stdio.h>
#include <math.h>

void print(double mat[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%.2f ", mat[i][j]);
        }
        printf("\n");
    }
}

void multiply(double a[4][4], double b[4][4], double result[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
void homogeneous_transformation(double theta1, double theta2, double theta3, double theta4, double theta5, double theta6,
                                double a1, double a2, double a3, double a4, double a5, double a6,
                                double alpha1, double alpha2, double alpha3, double alpha4, double alpha5, double alpha6,
                                double d1, double d2, double d3, double d4, double d5, double d6, double result[4][4]) {

    double T1[4][4] = {{cos(theta1), -sin(theta1)*cos(alpha1), sin(theta1)*sin(alpha1), a1*cos(theta1)},
                       {sin(theta1), cos(theta1)*cos(alpha1), -cos(theta1)*sin(alpha1), a1*sin(theta1)},
                       {0, sin(alpha1), cos(alpha1), d1},
                       {0, 0, 0, 1}};
    double T2[4][4] = {{cos(theta2), -sin(theta2)*cos(alpha2), sin(theta2)*sin(alpha2), a2*cos(theta2)},
                       {sin(theta2), cos(theta2)*cos(alpha2), -cos(theta2)*sin(alpha2), a2*sin(theta2)},
  {0, sin(alpha2), cos(alpha2), d2},
                       {0, 0, 0, 1}};
    double T3[4][4] = {{cos(theta3), -sin(theta3)*cos(alpha3), sin(theta3)*sin(alpha3), a3*cos(theta3)},
                       {sin(theta3), cos(theta3)*cos(alpha3), -cos(theta3)*sin(alpha3), a3*sin(theta3)},
                       {0, sin(alpha3), cos(alpha3), d3},
                       {0, 0, 0, 1}};
    double T4[4][4] = {{cos(theta4), -sin(theta4)*cos(alpha4), sin(theta4)*sin(alpha4), a4*cos(theta4)},
                       {sin(theta4), cos(theta4)*cos(alpha4), -cos(theta4)*sin(alpha4), a4*sin(theta4)},
                       {0, sin(alpha4), cos(alpha4), d4},
                       {0, 0, 0, 1}};
    double T5[4][4] = {{cos(theta5), -sin(theta5)*cos(alpha5), sin(theta5)*sin(alpha5), a5*cos(theta5)},
                       {sin(theta5), cos(theta5)*cos(alpha5), -cos(theta5)*sin(alpha5), a5*sin(theta5)},
                       {0, sin(alpha5), cos(alpha5), d5},
                       {0, 0, 0, 1}};
    double T6[4][4] = {{cos(theta6), -sin(theta6)*cos(alpha6), sin(theta6)*sin(alpha6), a6*cos(theta6)},
                       {sin(theta6), cos(theta6)*cos(alpha6), -cos(theta6)*sin(alpha6), a6*sin(theta6)},
                       {0, sin(alpha6), cos(alpha6), d6},
                       {0, 0, 0, 1}};
    double T234[4][4], T567[4][4];
    multiply(T2, T3, T234);
    multiply(T4, T5, T567);
    multiply(T234, T6, T234);
    multiply(T1, T234, result);
}
int main() {
    //configure dh table parameters here
    double theta1 = M_PI / 2;
    double theta2 = M_PI / 2;
    double theta3 = M_PI / 3;
    double theta4 = M_PI / 6;
    double theta5 = M_PI / 3;
    double theta6 = M_PI / 2;
    double a1 = 1.55;
    double a2 = 1.25;
    double a3 = 1;
    double a4 = 1;
    double a5 = 2;
    double a6 = 2;
    double alpha1 = 0;
    double alpha2 = 0;
    double alpha3 = 0;
    double alpha4 = 0;
    double alpha5 = 0;
    double alpha6 = 0;
    double d1 = 2;
    double d2 = 3;
    double d3 = 0.5;
    double d4 = 2;
    double d5 = 0.5;
    double d6 = 0.5;
    double result[4][4];
    //calculate and print the transformation matrix
    homogeneous_transformation(theta1, theta2, theta3, theta4, theta5, theta6, a1, a2, a3, a4, a5, a6, alpha1, alpha2, alpha3, alpha4, alpha5, alpha6, d1, d2, d3, d4, d5, d6, result);
    printf("homogenous transformation matrix is:\n");
    print(result);
    return 0;
}