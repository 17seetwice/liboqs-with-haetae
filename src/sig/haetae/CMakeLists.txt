# SPDX-License-Identifier: MIT

# This file was generated by
# scripts/copy_from_upstream/copy_from_upstream.py

set(_HAETAE_OBJS "")

if(OQS_ENABLE_SIG_haetae_2)
    add_library(haetae_2_ref OBJECT sig_haetae_2.c haetae_2_ref/decompose.c haetae_2_ref/encoding.c haetae_2_ref/fft.c haetae_2_ref/fixpoint.c haetae_2_ref/ntt.c haetae_2_ref/packing.c haetae_2_ref/poly.c haetae_2_ref/polyfix.c haetae_2_ref/polymat.c haetae_2_ref/polyvec.c haetae_2_ref/reduce.c haetae_2_ref/sampler.c haetae_2_ref/sign.c haetae_2_ref/symmetric-shake.c)
    target_compile_options(haetae_2_ref PUBLIC -DHAETAE_MODE=2 -DHAETAE_RANDOMIZED_SIGNING)
    target_include_directories(haetae_2_ref PRIVATE ${CMAKE_CURRENT_LIST_DIR}/haetae_2_ref)
    target_include_directories(haetae_2_ref PRIVATE ${PROJECT_SOURCE_DIR}/src/common/pqclean_shims)
    target_compile_options(haetae_2_ref PUBLIC -DHAETAE_MODE=2 -DHAETAE_RANDOMIZED_SIGNING)
    set(_HAETAE_OBJS ${_HAETAE_OBJS} $<TARGET_OBJECTS:haetae_2_ref>)
endif()

if(OQS_ENABLE_SIG_haetae_3)
    add_library(haetae_3_ref OBJECT sig_haetae_3.c haetae_3_ref/decompose.c haetae_3_ref/encoding.c haetae_3_ref/fft.c haetae_3_ref/fixpoint.c haetae_3_ref/ntt.c haetae_3_ref/packing.c haetae_3_ref/poly.c haetae_3_ref/polyfix.c haetae_3_ref/polymat.c haetae_3_ref/polyvec.c haetae_3_ref/reduce.c haetae_3_ref/sampler.c haetae_3_ref/sign.c haetae_3_ref/symmetric-shake.c)
    target_compile_options(haetae_3_ref PUBLIC -DHAETAE_MODE=3 -DHAETAE_RANDOMIZED_SIGNING)
    target_include_directories(haetae_3_ref PRIVATE ${CMAKE_CURRENT_LIST_DIR}/haetae_3_ref)
    target_include_directories(haetae_3_ref PRIVATE ${PROJECT_SOURCE_DIR}/src/common/pqclean_shims)
    target_compile_options(haetae_3_ref PUBLIC -DHAETAE_MODE=3 -DHAETAE_RANDOMIZED_SIGNING)
    set(_HAETAE_OBJS ${_HAETAE_OBJS} $<TARGET_OBJECTS:haetae_3_ref>)
endif()

if(OQS_ENABLE_SIG_haetae_5)
    add_library(haetae_5_ref OBJECT sig_haetae_5.c haetae_5_ref/decompose.c haetae_5_ref/encoding.c haetae_5_ref/fft.c haetae_5_ref/fixpoint.c haetae_5_ref/ntt.c haetae_5_ref/packing.c haetae_5_ref/poly.c haetae_5_ref/polyfix.c haetae_5_ref/polymat.c haetae_5_ref/polyvec.c haetae_5_ref/reduce.c haetae_5_ref/sampler.c haetae_5_ref/sign.c haetae_5_ref/symmetric-shake.c)
    target_compile_options(haetae_5_ref PUBLIC -DHAETAE_MODE=5 -DHAETAE_RANDOMIZED_SIGNING)
    target_include_directories(haetae_5_ref PRIVATE ${CMAKE_CURRENT_LIST_DIR}/haetae_5_ref)
    target_include_directories(haetae_5_ref PRIVATE ${PROJECT_SOURCE_DIR}/src/common/pqclean_shims)
    target_compile_options(haetae_5_ref PUBLIC -DHAETAE_MODE=5 -DHAETAE_RANDOMIZED_SIGNING)
    set(_HAETAE_OBJS ${_HAETAE_OBJS} $<TARGET_OBJECTS:haetae_5_ref>)
endif()

set(HAETAE_OBJS ${_HAETAE_OBJS} PARENT_SCOPE)
