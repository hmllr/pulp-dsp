/* =====================================================================
 * Project:      PULP DSP Library
 * Title:        plp_mat_mult_stride_q16s_xpulpv2.c
 * Description:  parallel 16-bit fix-point strided matrix multiplication for XPULPV2
 *
 * $Date:        14. July 2020
 * $Revision:    V0
 *
 * Target Processor: PULP cores
 * ===================================================================== */
/*
 * Copyright (C) 2020 ETH Zurich and University of Bologna.
 *
 * Author: Tibor Schneider, ETH Zurich
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "plp_math.h"

/**
  @ingroup groupMatrixStride BasicMatMultStride
 */

/**
  @addtogroup BasicMatMultStrideKernels
  @{
 */

/**
  @brief Matrix multiplication of 16-bit integer matrices kernel for XPULPV2 extension.
  @param[in]  pSrcA     points to the first input matrix
  @param[in]  pSrcB     points to the second input matrix
  @param[in]  M         height of the first input matrix
  @param[in]  N         width of the first input matrix and hight of the second
  @param[in]  O         width of the second input matrix
  @param[in]  strideA   Stride of matrix A (elements between each row)
  @param[in]  strideB   Stride of matrix B (elements between each row)
  @param[in]  strideC   Stride of output matrix (elements between each row)
  @param[in]  shift     Amount to shift the result of each multiplication.
  @param[out] pDstC     points to the output matrix
  @return        none

  @par Fix-Point and Shifting
  The result will be shifted by the parameter `shift` to the right (multiplied
  by 2^-shift). Assume that matrix A is represented as pSrcA * 2^-x, and matrix
  B as pSrcB * 2^-y (in other words, A has it's x last digits after the binary
  point). Then, the output is represented as pDstC * 2^-(x + y - shift).

  The output of the strided matrix multiplication will also be stored as an 16-bit
  array. Set the `shift` parameter such that no overflow ocurrs.
 */

void plp_mat_mult_stride_q16s_xpulpv2(const int16_t *__restrict__ pSrcA,
                                      const int16_t *__restrict__ pSrcB,
                                      uint32_t M,
                                      uint32_t N,
                                      uint32_t O,
                                      uint32_t strideA,
                                      uint32_t strideB,
                                      uint32_t strideC,
                                      uint32_t shift,
                                      int16_t *__restrict__ pDstC) {

#define BASIC_VERSION // if used don't forget to also use the undefine at end of file
#ifdef BASIC_VERSION

    uint32_t m; // loop counter
    uint32_t n; // loop counter
    uint32_t o; // loop counter

    for (m = 0; m < M; m++) {
        for (o = 0; o < O; o++) {
            int32_t sum = 0;
            for (n = 0; n < N; n++) {
                int32_t valA = (int32_t)pSrcA[m * strideA + n];
                int32_t valB = (int32_t)pSrcB[n * strideB + o];
                sum += __ROUNDNORM_REG(valA * valB, shift);
            }
            pDstC[m * strideC + o] = (int16_t)sum;
        }
    }

#else

    // TODO hackathon

#endif
#undef BASIC_VERSION
}

/**
   @} end of BasicMatMultStrideKernels group
*/
