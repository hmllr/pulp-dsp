#!/usr/bin/env python3

import numpy as np


####################
# generate_stimuli #
####################


def generate_stimuli(arg, env):
    """
    Function to generate the stimuli

    Arguments
    ---------
    arg: Argument for which to generate stimuli (either Argument or ArrayArgument)
    env: Dict mapping the variable (SweepVariable or DynamicVariable) names to their value.
    """
    # name = arg.name
    # if name == "srcA":
    #     # generate and return stimuli for srcA
    # if name == "srcB":
    #     # generate and return stimuli for srcB
    # ...


##################
# compute_result #
##################


def compute_result(result_parameter, inputs, env, fix_point):
    """
    Funciton to generate the expected result of the testcase.

    Arguments
    ---------
    result_parameter: Either OutputArgument or ReturnValue (see pulp_dsp_test.py)
    inputs: Dict mapping name to the Argument, with arg.value, arg.ctype (and arg.length)
    env: Dict mapping the variable (SweepVariable or DynamicVariable) names to their value.
    fix_point: None (if no fixpoint is used) or decimal point
    """
    if result_parameter.ctype == 'float':
        # not necessary to make cast src from a vector to a matrix
        src = inputs['pSrc'].value.astype(np.float32)
        offset = np.float32(inputs['offset'].value)
        result = np.zeros((env['len'], ), dtype=np.float32)
        for i in range(env['len']):
            result[i] = np.float32(src[i] + offset)
    else:
        if result_parameter.ctype == 'int8_t':
            dtype = np.int8
        elif result_parameter.ctype == 'int16_t':
            dtype = np.int16
        elif result_parameter.ctype == 'int32_t':
            dtype = np.int32
        elif result_parameter.ctype == 'float':
            dtype = np.float32
        else:
            raise RuntimeError("Unrecognized result type: %s" % result_parameter.ctype)

        # not necessary to make cast src from a vector to a matrix
        src = inputs['pSrc'].value.astype(dtype)
        offset = dtype(inputs['offset'].value)
        result = np.zeros((env['len'], ), dtype=dtype)
        for i in range(env['len']):
            result[i] = dtype(src[i] + offset)

    return result


######################
# Fixpoint Functions #
######################


def q_sat(x):
    if x > 2**31 - 1:
        return x - 2**32
    elif x < -2**31:
        return x + 2**32
    else:
        return x


def q_add(a, b):
    return q_sat(a + b)


def q_sub(a, b):
    return q_sat(a - b)


def q_mul(a, b, p):
    return q_roundnorm(a * b, p)


def q_roundnorm(a, p):
    rounding = 1 << (p - 1)
    return q_sat((a + rounding) >> p)
