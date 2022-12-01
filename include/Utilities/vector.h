/**
 *  @file   vector.c
 *  @author Harrison Parkes
 *  @date   24th of October 2022
 *  @brief  Vector datatype with algebraic functionality
*/

#ifndef VECTOR_H
#define VECTOR_H

#include <stdint.h>

typedef struct vector_s {
    int8_t x;
    int8_t y;
} vector_t;



/**
 * @brief Vector addition
 *
 * @param vec_a first vector for addition
 * @param vec_b second vector for addition
 * @return new `vector_t` for sum of `vec_a` and `vec_b`
 */
inline vector_t vector_sum(const vector_t vec_a, const vector_t vec_b)
{
    return (vector_t) {
        .x = vec_a.x + vec_b.x,
        .y = vec_a.y + vec_b.y
    };
}

/**
 * @brief Vector addition
 * *vec_a = *vec_a + vec_b
 *
 * @param vec_a vector to be changed
 * @param vec_b vector to be added to `vec_a`
 */
inline void vector_add(vector_t* const vec_a, const vector_t vec_b)
{
    vec_a->x += vec_b.x;
    vec_a->y += vec_b.y;
}


/**
 * @brief Vector subtraction
 *
 * @param vec_a vector to be subtracted from
 * @param vec_b other vector to be subtracted
 * @return difference of `vec_a` and `vec_b`
 */
inline vector_t vector_difference(const vector_t vec_a, const vector_t vec_b)
{
    return (vector_t) {
        .x = vec_a.x - vec_b.x,
        .y = vec_a.y - vec_b.y
    };
}

/**
 * @brief Vector subtraction
 * *vec_a = *vec_a - vec_b
 *
 * @param vec_a vector to be changed
 * @param vec_b vector to be subtracted from `vec_a`
 */
inline void vector_subtract(vector_t* const vec_a, const vector_t vec_b)
{
    vec_a->x -= vec_b.x;
    vec_a->y -= vec_b.y;
}


///**
// * @brief Calculates magnitude of vector
// *
// * @param vec Vector to calculate magnitude of
// * @return The integerised magnitude of `vec`
// */
//inline int vector_magnitude(vector_t vec)
//{
//}

#endif //VECTOR_H