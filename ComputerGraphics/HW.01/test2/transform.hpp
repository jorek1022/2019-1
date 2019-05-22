/* 
    학번 : 20160182
    이로제
*/


#ifndef KMUCS_GRAPHICS_TRANSFORM_HPP
#define KMUCS_GRAPHICS_TRANSFORM_HPP

#include <cmath>
#include "vec.hpp"
#include "mat.hpp"
#include "operator.hpp"

namespace kmuvcl
{
    namespace math
    {
#ifndef M_PI
        const float M_PI = 3.14159265358979323846f;
#endif

        template <typename T>
        mat<4, 4, T> translate(T dx, T dy, T dz)
        {
            mat<4, 4, T> translateMat;
            
            //                  [1 0 0 dx]
            // 이동변환 행렬 =   [0 1 0 dy]
            //                  [0 0 1 dz]
            //                  [0 0 0  1]


            // 방법 1
            /*
            translateMat(0, 0) = 1;   translateMat(0, 1) = 0;   translateMat(0, 2) = 0;   translateMat(0, 3) = dx;
            translateMat(1, 0) = 0;   translateMat(1, 1) = 1;   translateMat(1, 2) = 0;   translateMat(1, 3) = dy;
            translateMat(2, 0) = 0;   translateMat(2, 1) = 0;   translateMat(2, 2) = 1;   translateMat(2, 3) = dz;
            translateMat(3, 0) = 0;   translateMat(3, 1) = 0;   translateMat(3, 2) = 0;   translateMat(3, 3) = 1;
            */

            // 방법 2
            translateMat(0, 0) = 1;   translateMat(0, 3) = dx;
            translateMat(1, 1) = 1;   translateMat(1, 3) = dy;
            translateMat(2, 2) = 1;   translateMat(2, 3) = dz;
            translateMat(3, 3) = 1;


            return translateMat;
        }




        template <typename T>
        mat<4, 4, T> rotate(T angle, T x, T y, T z)
        {
            mat<4, 4, T> rotateMat;

            // angle로부터 radian 구하기 
            T rad = angle * M_PI / 180;

            // 벡터 u의 크기
            T length = sqrt( powf(x, 2) + powf(y, 2) + powf(z, 2) );

            // ux, uy, uz 구하기
            T ux = x / length;
            T uy = y / length;
            T uz = z / length;

            
            rotateMat(0,0) = cos(rad) + powf(ux,2)*(1-cos(rad));    rotateMat(0,1) = ux*uy*(1-cos(rad)) - uz*sin(rad);    rotateMat(0,2) = ux*uz*(1-cos(rad)) + uy*sin(rad);    rotateMat(0,3) = 0;
            rotateMat(1,0) = uy*ux*(1-cos(rad)) + uz*sin(rad);      rotateMat(1,1) = cos(rad) + powf(uy,2)*(1-cos(rad));  rotateMat(1,2) = uy*uz*(1-cos(rad)) - ux*sin(rad);    rotateMat(1,3) = 0;
            rotateMat(2,0) = uz*ux*(1-cos(rad)) - uy*sin(rad);      rotateMat(2,1) = uz*uy*(1-cos(rad)) + ux*sin(rad);    rotateMat(2,2) = cos(rad) + powf(uz,2)*(1-cos(rad));  rotateMat(2,3) = 0;
            rotateMat(3,0) = 0;                                     rotateMat(3,1) = 0;                                   rotateMat(3,2) = 0;                                   rotateMat(3,3) = 1;

            return rotateMat;
        }




        template<typename T>
        mat<4, 4, T> scale(T sx, T sy, T sz)
        {
            mat<4, 4, T> scaleMat;

            /*                            [sx    0   0   0]   
                                          [0     sy  0   0]
                확대축소(scaling) 행렬  =  [0     0   sz  0]
                                          [0     0   0   1]
            */
            scaleMat(0, 0) = sx;
            scaleMat(1, 1) = sy;
            scaleMat(2, 2) = sz;
            scaleMat(3, 3) = 1;

            return scaleMat;
        }




        template<typename T>
        mat<4, 4, T> lookAt(T eyeX, T eyeY, T eyeZ, T centerX, T centerY, T centerZ, T upX, T upY, T upZ)
        {
            /*

                                [cam-x-axisX    cam-x-axisY     cam-x-axisZ     0]
                cam_xyz_axis =  [cam-x-axisX    cam-x-axisY     cam-x-axisZ     0]
                                [cam-x-axisX    cam-x-axisY     cam-x-axisZ     0]
                                [     0              0               0          1]

                                [1  0   0   -cam-posX]
                cam_pos      =  [0  1   0   -cam-posY]
                                [0  0   1   -cam-posZ]
                                [0  0   0       1    ]


                viewMat = cam_xyz_axis X cam_pos

            */


            //++++++++++++++++++++++++++ 변수 선언 ++++++++++++++++++++++++++++
            mat<4, 4, T> viewMat;
            // viewMat  = camp_xyz_axis * cam_pos
            mat<4, 4, T> cam_xyz_axis;
            mat<4, 4, T> cam_pos;

            // 수식 계산시 x,y,z값을 담을 임시 변수 tempX,Y,Z  , 벡터 temp의 크기 length
            T tempX, tempY, tempZ;
            T length;

            //+++++++++++++++++++++++++ cam-pos +++++++++++++++++++++++++++++++
            // translate()를 이용하여 값 넣어 주기
            cam_pos = translate((-1)*eyeX, (-1)*eyeY, (-1)*eyeZ);

            //++++++++++++++++++++++++ cam-z-axis +++++++++++++++++++++++++++++
            // (centerX, centerY, centerZ)와 (eyeX, eyeY, eyeZ)의 차
            tempX = eyeX - centerX;
            tempY = eyeY - centerY;
            tempZ = eyeZ - centerZ;

            // temp 벡터의 크기
            length = sqrt( powf(tempX,2) + powf(tempY,2) + powf(tempZ,2) );

            // cam-z-axis(단위벡터화)
            T cam_z_axisX = tempX / length;
            T cam_z_axisY = tempY / length;
            T cam_z_axisZ = tempZ / length;

            vec<4, T> cam_z_axis(cam_z_axisX, cam_z_axisY, cam_z_axisZ, 0);


            // ++++++++++++++++++++++++ cam-x-axis ++++++++++++++++++++++++++++++
            // (upX, upY, upZ) 와 cam-z-axis의 외적
           // temp 벡터에 외적 값을 저장
            tempX = upY * cam_z_axisZ - upZ * cam_z_axisY;
            tempY = upZ * cam_z_axisX - upX * cam_z_axisZ;
            tempZ = upX * cam_z_axisY - upY * cam_z_axisX;
            // temp 벡터의 크기
            length = sqrt( powf(tempX,2) + powf(tempY,2) + powf(tempZ,2) );

            // cam_x_axis(단위벡터화)
            T cam_x_axisX = tempX / length;
            T cam_x_axisY = tempY / length;
            T cam_x_axisZ = tempZ / length;
            
            vec<4, T> cam_x_axis(cam_x_axisX, cam_x_axisY, cam_x_axisZ, 0);


            //+++++++++++++++++++++++++ cam-y-axis ++++++++++++++++++++++++++++++++
            // cam_z_axis 와 cam_x_axis 외적
            tempX = cam_z_axisY * cam_x_axisZ - cam_z_axisZ * cam_x_axisY;
            tempY = cam_z_axisZ * cam_x_axisX - cam_z_axisX * cam_x_axisZ;
            tempZ = cam_z_axisX * cam_x_axisY - cam_z_axisY * cam_x_axisX;

            // temp 벡터의 크기
            length = sqrt( powf(tempX,2) + powf(tempY,2) + powf(tempZ,2) );

            // cam_y_axis(단위벡터화)
            T cam_y_axisX = tempX / length;
            T cam_y_axisY = tempY / length;
            T cam_y_axisZ = tempZ / length;

            vec<4, T> cam_y_axis(cam_y_axisX, cam_y_axisY, cam_y_axisZ, 0);

            //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            
            cam_xyz_axis.set_ith_row(0, cam_x_axis);
            cam_xyz_axis.set_ith_row(1, cam_y_axis);
            cam_xyz_axis.set_ith_row(2, cam_z_axis);
            cam_xyz_axis(3, 3) = 1;

            viewMat = cam_xyz_axis * cam_pos;


            return viewMat;
        }




        template<typename T>
        mat<4, 4, T> ortho(T left, T right, T bottom, T top, T nearVal, T farVal)
        {
            mat<4, 4, T> orthoMat;
            // 이니셜을 딴 변수
            T l = left;     T r = right;    T b = bottom;
            T t = top;      T n = nearVal;  T f = farVal;
            
            // 행렬 orthoMat에 값 넣어주기

            // 방법 1
            /* 
            orthoMat(0, 0) = 2 / (r-l);    orthoMat(0, 1) = 0;              orthoMat(0, 2) = 0;                 orthoMat(0, 3) = (-1) * (r+l) / (r-l);
            orthoMat(1, 0) = 0;            orthoMat(1, 1) = 2 / (t-b);      orthoMat(1, 2) = 0;                 orthoMat(1, 3) = (-1) * (t+b) / (t-b);
            orthoMat(2, 0) = 0;            orthoMat(2, 1) = 0;              orthoMat(2, 2) = (-1) * 2 / (f-n);  orthoMat(2, 3) = (-1) * (f+n) / (f-n);
            orthoMat(3, 0) = 0;            orthoMat(3, 1) = 0;              orthoMat(3, 2) = 0;                 orthoMat(3, 3) = 1;
            */

            // 방법 2 : traslate 하고 값 넣기
            /*
            orthoMat = translate( (-1)*(r+l)/(r-l), (-1)*(t+b)/(t-b), (-1)*(f+n)/(f-n) );
            orthoMat(0, 0) = 2 / (r-l);
            orthoMat(1, 1) = 2 / (t-b);
            orthoMat(2, 2) = (-1) * 2 / (f-n);
            */
            
            // 방법 3 : scale 하고 값 넣기
            orthoMat = scale( 2/(r-l), 2/(t-b), (-2)/(f-n) );
            orthoMat(0, 3) = (-1) * (r+l) / (r-l);
            orthoMat(1, 3) = (-1) * (t+b) / (t-b);
            orthoMat(2, 3) = (-1) * (f+n) / (f-n);
            
            return orthoMat;
        }




        template<typename T>
        mat<4, 4, T> frustum(T left, T right, T bottom, T top, T nearVal, T farVal)
        {
            // 원근투영 행렬
            mat<4, 4, T> frustumMat;

            // 이니셜을 딴 변수 선언
            T l = left;     T r = right;    T b = bottom;
            T t = top;      T n = nearVal;  T f = farVal;

            // 행렬 frustumMat에 값 넣어주기
            frustumMat(0, 0) = 2*n / (r-l);     frustumMat(0, 1) = 0;               frustumMat(0, 2) = (r+l) / (r-l);       frustumMat(0, 3) = 0;
            frustumMat(1, 0) = 0;               frustumMat(1, 1) = 2*n / (t-b);     frustumMat(1, 2) = (t+b) / (t-b);       frustumMat(1, 3) = 0;
            frustumMat(2, 0) = 0;               frustumMat(2, 1) = 0;               frustumMat(2, 2) = (-1)*(f+n) / (f-n);  frustumMat(2, 3) = (-1)*2*f*n / (f-n);
            frustumMat(3, 0) = 0;               frustumMat(3, 1) = 0;               frustumMat(3, 2) = -1;                  frustumMat(3, 3) = 0;

            return frustumMat;
        }

        template<typename T>
        mat<4, 4, T> perspective(T fovy, T aspect, T zNear, T zFar)
        {
            T  right = 0;
            T  top = 0;

            top = zNear * tan( (fovy * M_PI / 180) / 2 );
            right = top * aspect;

            return frustum(-right, right, -top, top, zNear, zFar);
        }
    }
}
#endif