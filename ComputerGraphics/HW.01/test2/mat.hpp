/*
  학변 : 20160182
  이름 : 이로제
*/

#ifndef KMUVCL_GRAPHICS_MAT_HPP
#define KMUVCL_GRAPHICS_MAT_HPP

#include <iostream>
#include <cstring>
#include <cstdarg>

namespace kmuvcl {
  namespace math {

    template <unsigned int M, unsigned int N, typename T>
    class mat
    {
    public:
      mat()
      {
        set_to_zero();
      }

      mat(const T elem)
      {
        std::fill(val, val + M*N, elem);
      }

      T& operator()(unsigned int r, unsigned int c)
      {
        // Notice: The matrix is column major
        return  val[M*c + r];
      }

      const T& operator()(unsigned int r, unsigned int c) const
      {
        // Notice: The matrix is column major
        return  val[M*c + r];   
      }

      // type casting operators
      operator const T* () const
      {
        return  val;
      }

      operator T* ()
      {
        return  val;
      }

      void set_to_zero()
      {
        for(int i=0; i<M*N; ++i)
          val[i] = 0;
      }


      // val = [idx0, idx1, idx2, idx3, idx4, idx5, idx6, idx7, idx8, ,,, ]
      //            r
      //            0 [idx0, idx3, idx6]                     
      // 3x3 행렬 = 1 [idx1, idx4, idx7]  -->    M x N 행렬   
      //            2 [idx2, idx5, idx8]                    
      //            c :  0     1     2

      void get_ith_column(unsigned int i, vec<M, T>& col) const
      {
        // j는 row
        for(int j=0; j<N; ++j)
          col(j) = val[N*i+j];
      }

      void set_ith_column(unsigned int i, const vec<M, T>& col)
      {
        // j는 row
        for(int j=0; j<N; ++j)
          val[N*i+j] = col(j);
      }

      
      void get_ith_row(unsigned int i, vec<N, T>& row) const
      {
        // j는 col
        for(int j=0; j<M; ++j)
          row(j) = val[M*j+i];
      }

      void set_ith_row(unsigned int i, const vec<N, T>& row)
      {
        // j는 col
        for(int j=0; j<M; ++j)
          val[M*j+i] = row(j);
      }

      mat<N, M, T> transpose() const
      { 
        mat<N, M, T>  trans;
        // M개의 row를 담을 temp 선언
        vec<N , T> temp;

        for(int i=0; i<N; ++i)
        {
          // temp에 col값을 넣어주고
          get_ith_column(i, temp);
          // trans의 row에 넣어줌
          trans.set_ith_row(i, temp);
        }
          
        return  trans;
      }

    protected:
      T val[M*N];   // column major
    };

    typedef mat<3, 3, float>    mat3x3f;
    typedef mat<3, 3, double>   mat3x3d;

    typedef mat<4, 4, float>    mat4x4f;
    typedef mat<4, 4, double>   mat4x4d;

  } // math
} // kmuvcl

#include "operator.hpp"

#endif // #ifndef KMUVCL_GRAPHICS_MAT_HPP