#include "rt/rt_api.h"
#include "stdio.h"
#include "plp_math.h"

#include "common.h"
#include "data_t0.h"
#include "data_t1.h"
#include "data_t2.h"
#include "data_t3.h"
#include "data_t4.h"

static int t0__do_bench(rt_perf_t *perf, int events, int do_check) {
    // setup variables (like resetting InplaceArguments)


    // start the performance counters
    rt_perf_conf(perf, events);
    rt_perf_reset(perf);
    rt_perf_start(perf);

    // call the function-under-test
    plp_mat_scale_f32(t0__pSrc, t0__scaleFactor.f, t0__pDst, t0__blockSize);

    rt_perf_stop(perf);

    // check the result
    int passed = 1;
    if (do_check) {
        for (int i = 0; i < 1; i++) {
            float __tol = ABS(1.000000E-05 * (float)t0__pDst__reference[i] + 0.0001);
            if (!(t0__pDst[i] >= (float)(t0__pDst__reference[i] - __tol) &&
                  t0__pDst[i] <= (float)(t0__pDst__reference[i] + __tol))) {            
                passed = 0;
                printf("\n#@# mismatch pDst[%d]: acq=%.10f, exp=%.10f\n",
                       i, t0__pDst[i], t0__pDst__reference[i]);
            }
        }

    }
    return passed;
}

static int t1__do_bench(rt_perf_t *perf, int events, int do_check) {
    // setup variables (like resetting InplaceArguments)


    // start the performance counters
    rt_perf_conf(perf, events);
    rt_perf_reset(perf);
    rt_perf_start(perf);

    // call the function-under-test
    plp_mat_scale_f32(t1__pSrc, t1__scaleFactor.f, t1__pDst, t1__blockSize);

    rt_perf_stop(perf);

    // check the result
    int passed = 1;
    if (do_check) {
        for (int i = 0; i < 24; i++) {
            float __tol = ABS(1.000000E-05 * (float)t1__pDst__reference[i] + 0.0001);
            if (!(t1__pDst[i] >= (float)(t1__pDst__reference[i] - __tol) &&
                  t1__pDst[i] <= (float)(t1__pDst__reference[i] + __tol))) {            
                passed = 0;
                printf("\n#@# mismatch pDst[%d]: acq=%.10f, exp=%.10f\n",
                       i, t1__pDst[i], t1__pDst__reference[i]);
            }
        }

    }
    return passed;
}

static int t2__do_bench(rt_perf_t *perf, int events, int do_check) {
    // setup variables (like resetting InplaceArguments)


    // start the performance counters
    rt_perf_conf(perf, events);
    rt_perf_reset(perf);
    rt_perf_start(perf);

    // call the function-under-test
    plp_mat_scale_f32(t2__pSrc, t2__scaleFactor.f, t2__pDst, t2__blockSize);

    rt_perf_stop(perf);

    // check the result
    int passed = 1;
    if (do_check) {
        for (int i = 0; i < 25; i++) {
            float __tol = ABS(1.000000E-05 * (float)t2__pDst__reference[i] + 0.0001);
            if (!(t2__pDst[i] >= (float)(t2__pDst__reference[i] - __tol) &&
                  t2__pDst[i] <= (float)(t2__pDst__reference[i] + __tol))) {            
                passed = 0;
                printf("\n#@# mismatch pDst[%d]: acq=%.10f, exp=%.10f\n",
                       i, t2__pDst[i], t2__pDst__reference[i]);
            }
        }

    }
    return passed;
}

static int t3__do_bench(rt_perf_t *perf, int events, int do_check) {
    // setup variables (like resetting InplaceArguments)


    // start the performance counters
    rt_perf_conf(perf, events);
    rt_perf_reset(perf);
    rt_perf_start(perf);

    // call the function-under-test
    plp_mat_scale_f32(t3__pSrc, t3__scaleFactor.f, t3__pDst, t3__blockSize);

    rt_perf_stop(perf);

    // check the result
    int passed = 1;
    if (do_check) {
        for (int i = 0; i < 26; i++) {
            float __tol = ABS(1.000000E-05 * (float)t3__pDst__reference[i] + 0.0001);
            if (!(t3__pDst[i] >= (float)(t3__pDst__reference[i] - __tol) &&
                  t3__pDst[i] <= (float)(t3__pDst__reference[i] + __tol))) {            
                passed = 0;
                printf("\n#@# mismatch pDst[%d]: acq=%.10f, exp=%.10f\n",
                       i, t3__pDst[i], t3__pDst__reference[i]);
            }
        }

    }
    return passed;
}

static int t4__do_bench(rt_perf_t *perf, int events, int do_check) {
    // setup variables (like resetting InplaceArguments)


    // start the performance counters
    rt_perf_conf(perf, events);
    rt_perf_reset(perf);
    rt_perf_start(perf);

    // call the function-under-test
    plp_mat_scale_f32(t4__pSrc, t4__scaleFactor.f, t4__pDst, t4__blockSize);

    rt_perf_stop(perf);

    // check the result
    int passed = 1;
    if (do_check) {
        for (int i = 0; i < 27; i++) {
            float __tol = ABS(1.000000E-05 * (float)t4__pDst__reference[i] + 0.0001);
            if (!(t4__pDst[i] >= (float)(t4__pDst__reference[i] - __tol) &&
                  t4__pDst[i] <= (float)(t4__pDst__reference[i] + __tol))) {            
                passed = 0;
                printf("\n#@# mismatch pDst[%d]: acq=%.10f, exp=%.10f\n",
                       i, t4__pDst[i], t4__pDst__reference[i]);
            }
        }

    }
    return passed;
}


static void t0__run_test(void) {
    printf("\n#@# testcase 0 {\n");

    // setup the test
    rt_dma_copy_t copy;

    t0__pSrc = rt_alloc(RT_ALLOC_CL_DATA, sizeof(float) * 1);
    rt_dma_memcpy((unsigned int)t0__pSrc__l2,
                  (unsigned int)t0__pSrc,
                  sizeof(float) * 1,
                  RT_DMA_DIR_EXT2LOC, 0, &copy);
    rt_dma_wait(&copy);

    t0__pDst = rt_alloc(RT_ALLOC_CL_DATA, sizeof(float) * 1);
    rt_dma_memcpy((unsigned int)t0__pDst__l2,
                  (unsigned int)t0__pDst,
                  sizeof(float) * 1,
                  RT_DMA_DIR_EXT2LOC, 0, &copy);
    rt_dma_wait(&copy);


    // setup performance counter
    rt_perf_t perf;
    rt_perf_init(&perf);

    // run 1: check result and get numebr of cycles / instructions
    int passed = t0__do_bench(&perf, (1<<RT_PERF_CYCLES) | (1<<RT_PERF_INSTR), 1);
    printf("\n#@# passed: %d\n", passed);
    printf("#@# cycles: %d\n", rt_perf_read(RT_PERF_CYCLES));
    printf("#@# instructions: %d\n", rt_perf_read(RT_PERF_INSTR));

    // run 2: count load stalls
    t0__do_bench(&perf, 1<<RT_PERF_LD_STALL, 0);
    printf("\n#@# load_stalls: %d\n", rt_perf_read(RT_PERF_LD_STALL));

    // run 3: count instruction cache misses
    t0__do_bench(&perf, 1<<RT_PERF_IMISS, 0);
    printf("\n#@# icache_miss: %d\n", rt_perf_read(RT_PERF_IMISS));

    // run 4: count TCDM contentions
    printf("\n#@# output start\n");
    t0__do_bench(&perf, 1<<RT_PERF_TCDM_CONT, 0);
    printf("\n#@# output end\n");
    printf("#@# tcdm_cont: %d\n", rt_perf_read(RT_PERF_TCDM_CONT));

    // free up all memory
    rt_free(RT_ALLOC_CL_DATA, t0__pSrc, sizeof(float) * 1);
    rt_free(RT_ALLOC_CL_DATA, t0__pDst, sizeof(float) * 1);


    printf("\n#@# }\n");
}

static void t1__run_test(void) {
    printf("\n#@# testcase 1 {\n");

    // setup the test
    rt_dma_copy_t copy;

    t1__pSrc = rt_alloc(RT_ALLOC_CL_DATA, sizeof(float) * 24);
    rt_dma_memcpy((unsigned int)t1__pSrc__l2,
                  (unsigned int)t1__pSrc,
                  sizeof(float) * 24,
                  RT_DMA_DIR_EXT2LOC, 0, &copy);
    rt_dma_wait(&copy);

    t1__pDst = rt_alloc(RT_ALLOC_CL_DATA, sizeof(float) * 24);
    rt_dma_memcpy((unsigned int)t1__pDst__l2,
                  (unsigned int)t1__pDst,
                  sizeof(float) * 24,
                  RT_DMA_DIR_EXT2LOC, 0, &copy);
    rt_dma_wait(&copy);


    // setup performance counter
    rt_perf_t perf;
    rt_perf_init(&perf);

    // run 1: check result and get numebr of cycles / instructions
    int passed = t1__do_bench(&perf, (1<<RT_PERF_CYCLES) | (1<<RT_PERF_INSTR), 1);
    printf("\n#@# passed: %d\n", passed);
    printf("#@# cycles: %d\n", rt_perf_read(RT_PERF_CYCLES));
    printf("#@# instructions: %d\n", rt_perf_read(RT_PERF_INSTR));

    // run 2: count load stalls
    t1__do_bench(&perf, 1<<RT_PERF_LD_STALL, 0);
    printf("\n#@# load_stalls: %d\n", rt_perf_read(RT_PERF_LD_STALL));

    // run 3: count instruction cache misses
    t1__do_bench(&perf, 1<<RT_PERF_IMISS, 0);
    printf("\n#@# icache_miss: %d\n", rt_perf_read(RT_PERF_IMISS));

    // run 4: count TCDM contentions
    printf("\n#@# output start\n");
    t1__do_bench(&perf, 1<<RT_PERF_TCDM_CONT, 0);
    printf("\n#@# output end\n");
    printf("#@# tcdm_cont: %d\n", rt_perf_read(RT_PERF_TCDM_CONT));

    // free up all memory
    rt_free(RT_ALLOC_CL_DATA, t1__pSrc, sizeof(float) * 24);
    rt_free(RT_ALLOC_CL_DATA, t1__pDst, sizeof(float) * 24);


    printf("\n#@# }\n");
}

static void t2__run_test(void) {
    printf("\n#@# testcase 2 {\n");

    // setup the test
    rt_dma_copy_t copy;

    t2__pSrc = rt_alloc(RT_ALLOC_CL_DATA, sizeof(float) * 25);
    rt_dma_memcpy((unsigned int)t2__pSrc__l2,
                  (unsigned int)t2__pSrc,
                  sizeof(float) * 25,
                  RT_DMA_DIR_EXT2LOC, 0, &copy);
    rt_dma_wait(&copy);

    t2__pDst = rt_alloc(RT_ALLOC_CL_DATA, sizeof(float) * 25);
    rt_dma_memcpy((unsigned int)t2__pDst__l2,
                  (unsigned int)t2__pDst,
                  sizeof(float) * 25,
                  RT_DMA_DIR_EXT2LOC, 0, &copy);
    rt_dma_wait(&copy);


    // setup performance counter
    rt_perf_t perf;
    rt_perf_init(&perf);

    // run 1: check result and get numebr of cycles / instructions
    int passed = t2__do_bench(&perf, (1<<RT_PERF_CYCLES) | (1<<RT_PERF_INSTR), 1);
    printf("\n#@# passed: %d\n", passed);
    printf("#@# cycles: %d\n", rt_perf_read(RT_PERF_CYCLES));
    printf("#@# instructions: %d\n", rt_perf_read(RT_PERF_INSTR));

    // run 2: count load stalls
    t2__do_bench(&perf, 1<<RT_PERF_LD_STALL, 0);
    printf("\n#@# load_stalls: %d\n", rt_perf_read(RT_PERF_LD_STALL));

    // run 3: count instruction cache misses
    t2__do_bench(&perf, 1<<RT_PERF_IMISS, 0);
    printf("\n#@# icache_miss: %d\n", rt_perf_read(RT_PERF_IMISS));

    // run 4: count TCDM contentions
    printf("\n#@# output start\n");
    t2__do_bench(&perf, 1<<RT_PERF_TCDM_CONT, 0);
    printf("\n#@# output end\n");
    printf("#@# tcdm_cont: %d\n", rt_perf_read(RT_PERF_TCDM_CONT));

    // free up all memory
    rt_free(RT_ALLOC_CL_DATA, t2__pSrc, sizeof(float) * 25);
    rt_free(RT_ALLOC_CL_DATA, t2__pDst, sizeof(float) * 25);


    printf("\n#@# }\n");
}

static void t3__run_test(void) {
    printf("\n#@# testcase 3 {\n");

    // setup the test
    rt_dma_copy_t copy;

    t3__pSrc = rt_alloc(RT_ALLOC_CL_DATA, sizeof(float) * 26);
    rt_dma_memcpy((unsigned int)t3__pSrc__l2,
                  (unsigned int)t3__pSrc,
                  sizeof(float) * 26,
                  RT_DMA_DIR_EXT2LOC, 0, &copy);
    rt_dma_wait(&copy);

    t3__pDst = rt_alloc(RT_ALLOC_CL_DATA, sizeof(float) * 26);
    rt_dma_memcpy((unsigned int)t3__pDst__l2,
                  (unsigned int)t3__pDst,
                  sizeof(float) * 26,
                  RT_DMA_DIR_EXT2LOC, 0, &copy);
    rt_dma_wait(&copy);


    // setup performance counter
    rt_perf_t perf;
    rt_perf_init(&perf);

    // run 1: check result and get numebr of cycles / instructions
    int passed = t3__do_bench(&perf, (1<<RT_PERF_CYCLES) | (1<<RT_PERF_INSTR), 1);
    printf("\n#@# passed: %d\n", passed);
    printf("#@# cycles: %d\n", rt_perf_read(RT_PERF_CYCLES));
    printf("#@# instructions: %d\n", rt_perf_read(RT_PERF_INSTR));

    // run 2: count load stalls
    t3__do_bench(&perf, 1<<RT_PERF_LD_STALL, 0);
    printf("\n#@# load_stalls: %d\n", rt_perf_read(RT_PERF_LD_STALL));

    // run 3: count instruction cache misses
    t3__do_bench(&perf, 1<<RT_PERF_IMISS, 0);
    printf("\n#@# icache_miss: %d\n", rt_perf_read(RT_PERF_IMISS));

    // run 4: count TCDM contentions
    printf("\n#@# output start\n");
    t3__do_bench(&perf, 1<<RT_PERF_TCDM_CONT, 0);
    printf("\n#@# output end\n");
    printf("#@# tcdm_cont: %d\n", rt_perf_read(RT_PERF_TCDM_CONT));

    // free up all memory
    rt_free(RT_ALLOC_CL_DATA, t3__pSrc, sizeof(float) * 26);
    rt_free(RT_ALLOC_CL_DATA, t3__pDst, sizeof(float) * 26);


    printf("\n#@# }\n");
}

static void t4__run_test(void) {
    printf("\n#@# testcase 4 {\n");

    // setup the test
    rt_dma_copy_t copy;

    t4__pSrc = rt_alloc(RT_ALLOC_CL_DATA, sizeof(float) * 27);
    rt_dma_memcpy((unsigned int)t4__pSrc__l2,
                  (unsigned int)t4__pSrc,
                  sizeof(float) * 27,
                  RT_DMA_DIR_EXT2LOC, 0, &copy);
    rt_dma_wait(&copy);

    t4__pDst = rt_alloc(RT_ALLOC_CL_DATA, sizeof(float) * 27);
    rt_dma_memcpy((unsigned int)t4__pDst__l2,
                  (unsigned int)t4__pDst,
                  sizeof(float) * 27,
                  RT_DMA_DIR_EXT2LOC, 0, &copy);
    rt_dma_wait(&copy);


    // setup performance counter
    rt_perf_t perf;
    rt_perf_init(&perf);

    // run 1: check result and get numebr of cycles / instructions
    int passed = t4__do_bench(&perf, (1<<RT_PERF_CYCLES) | (1<<RT_PERF_INSTR), 1);
    printf("\n#@# passed: %d\n", passed);
    printf("#@# cycles: %d\n", rt_perf_read(RT_PERF_CYCLES));
    printf("#@# instructions: %d\n", rt_perf_read(RT_PERF_INSTR));

    // run 2: count load stalls
    t4__do_bench(&perf, 1<<RT_PERF_LD_STALL, 0);
    printf("\n#@# load_stalls: %d\n", rt_perf_read(RT_PERF_LD_STALL));

    // run 3: count instruction cache misses
    t4__do_bench(&perf, 1<<RT_PERF_IMISS, 0);
    printf("\n#@# icache_miss: %d\n", rt_perf_read(RT_PERF_IMISS));

    // run 4: count TCDM contentions
    printf("\n#@# output start\n");
    t4__do_bench(&perf, 1<<RT_PERF_TCDM_CONT, 0);
    printf("\n#@# output end\n");
    printf("#@# tcdm_cont: %d\n", rt_perf_read(RT_PERF_TCDM_CONT));

    // free up all memory
    rt_free(RT_ALLOC_CL_DATA, t4__pSrc, sizeof(float) * 27);
    rt_free(RT_ALLOC_CL_DATA, t4__pDst, sizeof(float) * 27);


    printf("\n#@# }\n");
}


void test_entry(void) {
    t0__run_test();
    t1__run_test();
    t2__run_test();
    t3__run_test();
    t4__run_test();
}


void cluster_entry(void* args) {
    test_entry();
}
