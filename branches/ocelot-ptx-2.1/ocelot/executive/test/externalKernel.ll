; ModuleID = 'testExternalKernel'

%Dimension = type { i16, i16, i16 }
%LLVMContext = type { %Dimension, %Dimension, %Dimension, %Dimension, i8*, i8*, i8*, i8*, i64, i64, i64, i64, i8* }

declare float @__ocelot_atom_f32(%LLVMContext*, i32, i32, i64, float) align 1

declare i64 @__ocelot_atom_b64(%LLVMContext*, i32, i32, i64, i64) align 1

declare i64 @__ocelot_atomcas_b64(%LLVMContext*, i32, i32, i64, i64, i64) align 1

declare i32 @__ocelot_atomcas_b32(%LLVMContext*, i32, i32, i64, i32, i32) align 1

declare i32 @__ocelot_atom_s32(%LLVMContext*, i32, i32, i64, i32) align 1

declare i32 @__ocelot_atom_b32(%LLVMContext*, i32, i32, i64, i32) align 1

declare void @__ocelot_tex_3d_fs(float*, %LLVMContext*, i32, i32, i32, i32, i32) align 1

declare void @__ocelot_tex_3d_fu(float*, %LLVMContext*, i32, i32, i32, i32, i32) align 1

declare void @__ocelot_tex_3d_ff(float*, %LLVMContext*, i32, float, float, float, float) align 1

declare void @__ocelot_tex_3d_sf(i32*, %LLVMContext*, i32, float, float, float, float) align 1

declare void @__ocelot_tex_3d_uf(i32*, %LLVMContext*, i32, float, float, float, float) align 1

declare void @__ocelot_tex_3d_ss(i32*, %LLVMContext*, i32, i32, i32, i32, i32) align 1

declare void @__ocelot_tex_3d_su(i32*, %LLVMContext*, i32, i32, i32, i32, i32) align 1

declare void @__ocelot_tex_3d_us(i32*, %LLVMContext*, i32, i32, i32, i32, i32) align 1

declare void @__ocelot_tex_3d_uu(i32*, %LLVMContext*, i32, i32, i32, i32, i32) align 1

declare void @__ocelot_tex_2d_fs(float*, %LLVMContext*, i32, i32, i32) align 1

declare void @__ocelot_tex_2d_fu(float*, %LLVMContext*, i32, i32, i32) align 1

declare void @__ocelot_tex_2d_ff(float*, %LLVMContext*, i32, float, float) align 1

declare void @__ocelot_tex_2d_sf(i32*, %LLVMContext*, i32, float, float) align 1

declare void @__ocelot_tex_2d_uf(i32*, %LLVMContext*, i32, float, float) align 1

declare void @__ocelot_tex_2d_ss(i32*, %LLVMContext*, i32, i32, i32) align 1

declare void @__ocelot_tex_2d_su(i32*, %LLVMContext*, i32, i32, i32) align 1

declare void @__ocelot_tex_2d_us(i32*, %LLVMContext*, i32, i32, i32) align 1

declare void @__ocelot_tex_2d_uu(i32*, %LLVMContext*, i32, i32, i32) align 1

declare void @__ocelot_tex_1d_fs(float*, %LLVMContext*, i32, i32) align 1

declare void @__ocelot_tex_1d_fu(float*, %LLVMContext*, i32, i32) align 1

declare void @__ocelot_tex_1d_ff(float*, %LLVMContext*, i32, float) align 1

declare void @__ocelot_tex_1d_sf(i32*, %LLVMContext*, i32, float) align 1

declare void @__ocelot_tex_1d_uf(i32*, %LLVMContext*, i32, float) align 1

declare void @__ocelot_tex_1d_ss(i32*, %LLVMContext*, i32, i32) align 1

declare void @__ocelot_tex_1d_su(i32*, %LLVMContext*, i32, i32) align 1

declare void @__ocelot_tex_1d_us(i32*, %LLVMContext*, i32, i32) align 1

declare void @__ocelot_tex_1d_uu(i32*, %LLVMContext*, i32, i32) align 1

declare i1 @__ocelot_vote(i1, i32, i1) align 1

declare i32 @__ocelot_clock(%LLVMContext*) align 1

declare void @setRoundingMode(i32) align 1

declare float @__ocelot_rsqrtFtz(float) align 1

declare float @__ocelot_rsqrt(float) align 1

declare double @__ocelot_sqrt(double) align 1

declare float @__ocelot_sqrtFtz(float) align 1

declare float @__ocelot_sqrtf(float) align 1

declare float @__ocelot_log2Ftz(float) align 1

declare float @__ocelot_log2f(float) align 1

declare float @__ocelot_ex2Ftz(float) align 1

declare float @__ocelot_ex2(float) align 1

declare float @__ocelot_sinFtz(float) align 1

declare float @__ocelot_sinf(float) align 1

declare float @__ocelot_cosFtz(float) align 1

declare float @__ocelot_cosf(float) align 1

define i32 @_Z_ocelotTranslated_testExternalKernel(%LLVMContext* %__ctaContext) nounwind align 1 {
BB_1_1:
  %rt0 = getelementptr %LLVMContext* %__ctaContext, i32 0, i32 2, i32 0 ; <i16*> [#uses=1]
  %rt1 = load i16* %rt0                           ; <i16> [#uses=1]
  %r0 = bitcast i16 %rt1 to i16                   ; <i16> [#uses=1]
  %rt2 = getelementptr %LLVMContext* %__ctaContext, i32 0, i32 1, i32 0 ; <i16*> [#uses=1]
  %rt3 = load i16* %rt2                           ; <i16> [#uses=1]
  %r1 = bitcast i16 %rt3 to i16                   ; <i16> [#uses=1]
  %rt4 = zext i16 %r0 to i32                      ; <i32> [#uses=1]
  %rt5 = zext i16 %r1 to i32                      ; <i32> [#uses=1]
  %r2 = mul i32 %rt4, %rt5                        ; <i32> [#uses=1]
  %rt6 = getelementptr %LLVMContext* %__ctaContext, i32 0, i32 0, i32 0 ; <i16*> [#uses=1]
  %rt7 = load i16* %rt6                           ; <i16> [#uses=1]
  %r3 = zext i16 %rt7 to i32                      ; <i32> [#uses=1]
  %r4 = add i32 %r3, %r2                          ; <i32> [#uses=2]
  %rt9 = getelementptr %LLVMContext* %__ctaContext, i32 0, i32 7 ; <i8**> [#uses=1]
  %rt10 = load i8** %rt9                          ; <i8*> [#uses=1]
  %rt8 = getelementptr i8* %rt10, i32 8           ; <i8*> [#uses=1]
  %rt11 = bitcast i8* %rt8 to i32*                ; <i32*> [#uses=1]
  %r5 = load i32* %rt11, align 4                  ; <i32> [#uses=1]
  %r6 = icmp sle i32 %r5, %r4                     ; <i1> [#uses=1]
  br i1 %r6, label %BB_1_3, label %BB_1_2

BB_1_2:                                           ; preds = %BB_1_1
  %r7 = phi i32 [ %r4, %BB_1_1 ]                  ; <i32> [#uses=2]

  %r8 = mul i32 %r7, 4                            ; Ocelot - modified line

  %rt12 = getelementptr %LLVMContext* %__ctaContext, i32 0, i32 7 ; <i8**> [#uses=1]
  %rt13 = load i8** %rt12                         ; <i8*> [#uses=1]
  %rt14 = bitcast i8* %rt13 to i64*               ; <i64*> [#uses=1]
  %r9 = load i64* %rt14, align 8                  ; <i64> [#uses=1]
  %r10 = sext i32 %r7 to i64                      ; <i64> [#uses=1]
  %r11 = mul i64 %r10, 4                          ; <i64> [#uses=1]
  %r12 = add i64 %r9, %r11                        ; <i64> [#uses=1]
  %rt15 = inttoptr i64 %r12 to i32*               ; <i32*> [#uses=1]
  store i32 %r8, i32* %rt15, align 4
  br label %BB_1_3

BB_1_3:                                           ; preds = %BB_1_2, %BB_1_1
  ret i32 0
                                                  ; No predecessors!
  br label %exit

exit:                                             ; preds = %0
  ret i32 0
}

