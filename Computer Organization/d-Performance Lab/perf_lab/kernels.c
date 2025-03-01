/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
/*
 * Please fill in the following team_t struct
 */
team_t team = {

        "e244860",      /* First student ID */
        "ÖMER KILINÇ",       /* First student name */

};


/********************
 * NORMALIZATION KERNEL
 ********************/

/****************************************************************
 * Your different versions of the normalization functions go here
 ***************************************************************/

/*
 * naive_normalize - The naive baseline version of convolution
 */
char naive_normalize_descr[] = "naive_normalize: Naive baseline implementation";
void naive_normalize(int dim, float *src, float *dst) {
    float min, max;
    min = src[0];
    max = src[0];

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
	
            if (src[RIDX(i, j, dim)] < min) {
                min = src[RIDX(i, j, dim)];
            }
            if (src[RIDX(i, j, dim)] > max) {
                max = src[RIDX(i, j, dim)];
            }
        }
    }

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            dst[RIDX(i, j, dim)] = (src[RIDX(i, j, dim)] - min) / (max - min);
        }
    }
}

/*
 * normalize - Your current working version of normalization
 * IMPORTANT: This is the version you will be graded on
 */
char normalize_descr[] = "Normalize: Current working version";
void normalize(int dim, float *src, float *dst)
{
    float min = src[0], max = src[0];
    int cond = dim * dim;
    for (int i = 0; i < cond; i+=32 ) {

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;

        min = (src[++i] < min) ? src[i] : min;
        max = (src[i] > max) ? src[i] : max;
    }

    float range = max - min;
    
    
    float factor = 1.0/range;

    
    for (int i = 0; i < cond; ) {

        dst[i] = (src[i] - min) * factor; ++i;
        dst[i] = (src[i] - min) * factor; ++i;
        dst[i] = (src[i] - min) * factor; ++i;
        dst[i] = (src[i] - min) * factor; ++i;

        dst[i] = (src[i] - min) * factor; ++i;
        dst[i] = (src[i] - min) * factor; ++i;
        dst[i] = (src[i] - min) * factor; ++i;
        dst[i] = (src[i] - min) * factor; ++i;

        dst[i] = (src[i] - min) * factor; ++i;
        dst[i] = (src[i] - min) * factor; ++i;
        dst[i] = (src[i] - min) * factor; ++i;
        dst[i] = (src[i] - min) * factor; ++i;

        dst[i] = (src[i] - min) * factor; ++i;
        dst[i] = (src[i] - min) * factor; ++i;
        dst[i] = (src[i] - min) * factor; ++i;
        dst[i] = (src[i] - min) * factor; ++i;

        dst[i] = (src[i] - min) * factor; ++i;
        dst[i] = (src[i] - min) * factor; ++i;
        dst[i] = (src[i] - min) * factor; ++i;
        dst[i] = (src[i] - min) * factor; ++i;

        dst[i] = (src[i] - min) * factor; ++i;
        dst[i] = (src[i] - min) * factor; ++i;
        dst[i] = (src[i] - min) * factor; ++i;
        dst[i] = (src[i] - min) * factor; ++i;

        dst[i] = (src[i] - min) * factor; ++i;
        dst[i] = (src[i] - min) * factor; ++i;
        dst[i] = (src[i] - min) * factor; ++i;
        dst[i] = (src[i] - min) * factor; ++i;

        dst[i] = (src[i] - min) * factor; ++i;
        dst[i] = (src[i] - min) * factor; ++i;
        dst[i] = (src[i] - min) * factor; ++i;
        dst[i] = (src[i] - min) * factor; ++i;
        
    }


}

/*********************************************************************
 * register_normalize_functions - Register all of your different versions
 *     of the normalization functions  with the driver by calling the
 *     add_normalize_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 *********************************************************************/

void register_normalize_functions() {
    add_normalize_function(&naive_normalize, naive_normalize_descr);
    add_normalize_function(&normalize, normalize_descr);
    /* ... Register additional test functions here */
}




/************************
 * KRONECKER PRODUCT KERNEL
 ************************/

/********************************************************************
 * Your different versions of the kronecker product functions go here
 *******************************************************************/

/*
 * naive_kronecker_product - The naive baseline version of k-hop neighbours
 */
char naive_kronecker_product_descr[] = "Naive Kronecker Product: Naive baseline implementation";
void naive_kronecker_product(int dim1, int dim2, float *mat1, float *mat2, float *prod) {
    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim1; j++) {
            for (int k = 0; k < dim2; k++) {
                for (int l = 0; l < dim2; l++) {
                    prod[RIDX(i, k, dim2) * (dim1 * dim2) + RIDX(j, l, dim2)] = mat1[RIDX(i, j, dim1)] * mat2[RIDX(k, l, dim2)];
                }
            }
        }
    }
}



/*
 * kronecker_product - Your current working version of kronecker_product
 * IMPORTANT: This is the version you will be graded on
 */
char kronecker_product_descr[] = "Kronecker Product: Current working version";



void kronecker_product(int dim1, int dim2, float *mat1, float *mat2, float *prod)
{

    int matSize = dim1 * dim2; 
    float valA = 0;
    float *matA = mat1;
    float *matB = mat2;
    float *matC = prod;
    int rows1=0;
    int rows2=0;
    int index=0;

    for (int i = 0; i < dim1; i++) {
        rows1 = i*dim1;
        rows2 = (i * dim2) * matSize;
        for (int j = 0; j < dim1; j++) {

            matA = mat1 + rows1 + j;
            valA = (*matA);

            matB = mat2;

            index  = rows2 + (j * dim2);
            matC = prod + index;

            for (int k = 0; k < dim2; k++) {
            
                for (int l = 0; l < dim2;) { 
            
                    matC[l] = valA * matB[l];l++;
                    matC[l] = valA * matB[l];l++;
                    matC[l] = valA * matB[l];l++;
                    matC[l] = valA * matB[l];l++;

                }
                matB += dim2;
                matC += matSize;
            }
        }
    }
}





/******************************************************************************
 * register_kronecker_product_functions - Register all of your different versions
 *     of the kronecker_product with the driver by calling the
 *     add_kronecker_product_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 ******************************************************************************/

void register_kronecker_product_functions() {
    add_kronecker_product_function(&naive_kronecker_product, naive_kronecker_product_descr);
    add_kronecker_product_function(&kronecker_product, kronecker_product_descr);
    /* ... Register additional test functions here */
}

