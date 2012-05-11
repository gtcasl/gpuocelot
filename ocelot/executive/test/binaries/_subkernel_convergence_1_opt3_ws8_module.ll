; ModuleID = '<string>'

%LLVMContext = type { %Dimension, %Dimension, %Dimension, %Dimension, i8*, i8*, i8*, i8*, i8*, i8*, i32, i8* }
%Dimension = type { i32, i32, i32 }

declare i32 @__ocelot_get_extent(%LLVMContext*, i32) align 1

declare float @llvm.exp2.f32(float) nounwind readonly align 1

declare float @llvm.log2.f32(float) nounwind readonly align 1

declare float @llvm.sin.f32(float) nounwind readonly align 1

declare float @llvm.cos.f32(float) nounwind readonly align 1

declare double @llvm.sqrt.f64(double) nounwind readonly align 1

declare float @llvm.sqrt.f32(float) nounwind readonly align 1

declare i64 @llvm.readcyclecounter() nounwind align 1

declare i64 @llvm.ctpop.i64(i64) nounwind readnone align 1

declare i32 @llvm.ctpop.i32(i32) nounwind readnone align 1

declare i16 @llvm.ctpop.i16(i16) nounwind readnone align 1

declare i8 @llvm.ctpop.i8(i8) nounwind readnone align 1

declare i64 @llvm.atomic.cmp.swap.i64.p0i64(i64*, i64, i64) align 1

declare i32 @llvm.atomic.cmp.swap.i32.p0i32(i32*, i32, i32) align 1

declare float @llvm.atomic.swap.f32.p0f32(i64*, float) align 1

declare i64 @llvm.atomic.swap.i64.p0i64(i64*, i64) align 1

declare i64 @llvm.atomic.load.umax.i64.p0i64(i64*, i64) align 1

declare i64 @llvm.atomic.load.max.i64.p0i64(i64*, i64) align 1

declare i64 @llvm.atomic.load.umin.i64.p0i64(i64*, i64) align 1

declare i64 @llvm.atomic.load.min.i64.p0i64(i64*, i64) align 1

declare i64 @llvm.atomic.load.xor.i64.p0i64(i64*, i64) align 1

declare i64 @llvm.atomic.load.or.i64.p0i64(i64*, i64) align 1

declare i64 @llvm.atomic.load.and.i64.p0i64(i64*, i64) align 1

declare i64 @llvm.atomic.load.add.i64.p0i64(i64*, i64) align 1

declare i32 @llvm.atomic.swap.i32.p0i32(i32*, i32) align 1

declare i32 @llvm.atomic.load.umax.i32.p0i32(i32*, i32) align 1

declare i32 @llvm.atomic.load.max.i32.p0i32(i32*, i32) align 1

declare i32 @llvm.atomic.load.umin.i32.p0i32(i32*, i32) align 1

declare i32 @llvm.atomic.load.min.i32.p0i32(i32*, i32) align 1

declare i32 @llvm.atomic.load.xor.i32.p0i32(i32*, i32) align 1

declare i32 @llvm.atomic.load.or.i32.p0i32(i32*, i32) align 1

declare i32 @llvm.atomic.load.and.i32.p0i32(i32*, i32) align 1

declare i32 @llvm.atomic.load.add.i32.p0i32(i32*, i32) align 1

declare float @nearbyintf(float) align 1

declare float @truncf(float) align 1

declare float @ceilf(float) align 1

declare float @floorf(float) align 1

declare double @nearbyint(double) align 1

declare double @trunc(double) align 1

declare double @ceil(double) align 1

declare double @floor(double) align 1

declare i64 @__ocelot_mul_hi_s64(i64, i64) align 1

declare i64 @__ocelot_mul_hi_u64(i64, i64) align 1

declare i32* @__ocelot_txq(%LLVMContext*, i32, i32) align 1

declare i32 @__ocelot_atomic_dec_32(i64, i32) align 1

declare i32 @__ocelot_atomic_inc_32(i64, i32) align 1

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

declare i32 @__ocelot_prmt_rc16(i32, i32, i32) align 1

declare i32 @__ocelot_prmt_ecr(i32, i32, i32) align 1

declare i32 @__ocelot_prmt_ecl(i32, i32, i32) align 1

declare i32 @__ocelot_prmt_rc8(i32, i32, i32) align 1

declare i32 @__ocelot_prmt_b4e(i32, i32, i32) align 1

declare i32 @__ocelot_prmt_f4e(i32, i32, i32) align 1

declare i32 @__ocelot_prmt(i32, i32, i32) align 1

declare i32 @__ocelot_bfind_b64(i64, i1) align 1

declare i32 @__ocelot_bfind_b32(i32, i1) align 1

declare i64 @__ocelot_bfi_b64(i64, i64, i32, i32) align 1

declare i32 @__ocelot_bfi_b32(i32, i32, i32, i32) align 1

declare i64 @__ocelot_brev_b64(i64) align 1

declare i32 @__ocelot_brev_b32(i32) align 1

define void @_Z_ocelotTranslated__subkernel_convergence_1(%LLVMContext* %__ctaContext) nounwind align 1 {
"$BB_1_0002":
  %rt0 = getelementptr %LLVMContext* %__ctaContext, i32 0, i32 8
  %rt1 = load i8** %rt0
  %rt2 = bitcast i8* %rt1 to i64*
  %r0 = load i64* %rt2, align 8
  %r1 = bitcast i64 %r0 to i64
  %rt3 = getelementptr %LLVMContext* %__ctaContext, i32 0, i32 0, i32 0
  %rt4 = load i32* %rt3
  %r2 = bitcast i32 %rt4 to i32
  %r3 = sitofp i32 %r2 to float
  %r4 = fadd float %r3, %r3
  %r5 = fadd float %r4, 1.000000e+00
  %rt5 = sext i32 %r2 to i64
  %r6 = mul i64 %rt5, 4
  %r7 = add i64 %r1, %r6
  %rt6 = inttoptr i64 %r7 to float*
  store float %r5, float* %rt6, align 4
  br label %"$BB_1_0002_thread_exit"

"$BB_1_0002_thread_exit":                         ; preds = %"$BB_1_0002"
  %r8 = bitcast i32 4 to i32
  %rt7 = zext i32 %r8 to i64
  %rt8 = getelementptr %LLVMContext* %__ctaContext, i32 0, i32 4
  %rt9 = load i8** %rt8
  %rt10 = ptrtoint i8* %rt9 to i64
  %rt11 = add i64 %rt7, %rt10
  %rt12 = inttoptr i64 %rt11 to i32*
  store i32 6, i32* %rt12, align 4
  br label %exit
                                                  ; No predecessors!
  ret void

exit:                                             ; preds = %"$BB_1_0002_thread_exit"
  ret void
}

declare i64 @llvm.ctlz.i64(i64, i1) nounwind readnone

declare i32 @llvm.ctlz.i32(i32, i1) nounwind readnone

declare i16 @llvm.ctlz.i16(i16, i1) nounwind readnone

declare i8 @llvm.ctlz.i8(i8, i1) nounwind readnone

define void @_subkernel_convergence_1_opt3_ws8(%LLVMContext* %__ctaContext) nounwind align 1 {
exit:
  %0 = bitcast %LLVMContext* %__ctaContext to i32*
  %threadId.x.t0 = load i32* %0, align 4
  %localPtrPtr.t0 = getelementptr %LLVMContext* %__ctaContext, i64 0, i32 4
  %localPtr.t0 = load i8** %localPtrPtr.t0, align 8
  %localPtrPtr.t1 = getelementptr %LLVMContext* %__ctaContext, i64 1, i32 4
  %localPtr.t1 = load i8** %localPtrPtr.t1, align 8
  %localPtrPtr.t2 = getelementptr %LLVMContext* %__ctaContext, i64 2, i32 4
  %localPtr.t2 = load i8** %localPtrPtr.t2, align 8
  %localPtrPtr.t3 = getelementptr %LLVMContext* %__ctaContext, i64 3, i32 4
  %localPtr.t3 = load i8** %localPtrPtr.t3, align 8
  %localPtrPtr.t4 = getelementptr %LLVMContext* %__ctaContext, i64 4, i32 4
  %localPtr.t4 = load i8** %localPtrPtr.t4, align 8
  %localPtrPtr.t5 = getelementptr %LLVMContext* %__ctaContext, i64 5, i32 4
  %localPtr.t5 = load i8** %localPtrPtr.t5, align 8
  %localPtrPtr.t6 = getelementptr %LLVMContext* %__ctaContext, i64 6, i32 4
  %localPtr.t6 = load i8** %localPtrPtr.t6, align 8
  %localPtrPtr.t7 = getelementptr %LLVMContext* %__ctaContext, i64 7, i32 4
  %localPtr.t7 = load i8** %localPtrPtr.t7, align 8
  %1 = getelementptr %LLVMContext* %__ctaContext, i64 1, i32 0, i32 0
  %insert.threadId.x.t0.vec = insertelement <8 x i32> undef, i32 %threadId.x.t0, i32 0
  %2 = getelementptr %LLVMContext* %__ctaContext, i64 2, i32 0, i32 0
  %threadId.x.t1 = load i32* %1, align 4
  %insert.threadId.x.t1.vec = insertelement <8 x i32> %insert.threadId.x.t0.vec, i32 %threadId.x.t1, i32 1
  %3 = getelementptr %LLVMContext* %__ctaContext, i64 3, i32 0, i32 0
  %threadId.x.t2 = load i32* %2, align 4
  %insert.threadId.x.t2.vec = insertelement <8 x i32> %insert.threadId.x.t1.vec, i32 %threadId.x.t2, i32 2
  %4 = getelementptr %LLVMContext* %__ctaContext, i64 4, i32 0, i32 0
  %threadId.x.t3 = load i32* %3, align 4
  %insert.threadId.x.t3.vec = insertelement <8 x i32> %insert.threadId.x.t2.vec, i32 %threadId.x.t3, i32 3
  %5 = getelementptr %LLVMContext* %__ctaContext, i64 5, i32 0, i32 0
  %threadId.x.t4 = load i32* %4, align 4
  %insert.threadId.x.t4.vec = insertelement <8 x i32> %insert.threadId.x.t3.vec, i32 %threadId.x.t4, i32 4
  %6 = getelementptr %LLVMContext* %__ctaContext, i64 6, i32 0, i32 0
  %threadId.x.t5 = load i32* %5, align 4
  %insert.threadId.x.t5.vec = insertelement <8 x i32> %insert.threadId.x.t4.vec, i32 %threadId.x.t5, i32 5
  %threadId.x.t6 = load i32* %6, align 4
  %insert.threadId.x.t6.vec = insertelement <8 x i32> %insert.threadId.x.t5.vec, i32 %threadId.x.t6, i32 6
  %7 = getelementptr %LLVMContext* %__ctaContext, i64 7, i32 0, i32 0
  %argumentPtrPtr.t0 = getelementptr %LLVMContext* %__ctaContext, i64 0, i32 8
  %threadId.x.t7 = load i32* %7, align 4
  %argumentPtr.t0 = load i8** %argumentPtrPtr.t0, align 8
  %insert.threadId.x.t7.vec = insertelement <8 x i32> %insert.threadId.x.t6.vec, i32 %threadId.x.t7, i32 7
  %rt2 = bitcast i8* %argumentPtr.t0 to i64*
  %r0 = load i64* %rt2, align 8
  %r3.vec = sitofp <8 x i32> %insert.threadId.x.t7.vec to <8 x float>
  %r4.vec = fadd <8 x float> %r3.vec, %r3.vec
  %r5.vec = fadd <8 x float> %r4.vec, <float 1.000000e+00, float 1.000000e+00, float 1.000000e+00, float 1.000000e+00, float 1.000000e+00, float 1.000000e+00, float 1.000000e+00, float 1.000000e+00>
  %rt5 = sext i32 %threadId.x.t0 to i64
  %r6 = shl nsw i64 %rt5, 2
  %r7 = add i64 %r0, %r6
  %vec.rt6 = inttoptr i64 %r7 to <8 x float>*
  store <8 x float> %r5.vec, <8 x float>* %vec.rt6, align 32
  %rt10 = ptrtoint i8* %localPtr.t0 to i64
  %rt10.t1 = ptrtoint i8* %localPtr.t1 to i64
  %rt10.t2 = ptrtoint i8* %localPtr.t2 to i64
  %rt10.t3 = ptrtoint i8* %localPtr.t3 to i64
  %rt10.t4 = ptrtoint i8* %localPtr.t4 to i64
  %rt10.t5 = ptrtoint i8* %localPtr.t5 to i64
  %rt10.t6 = ptrtoint i8* %localPtr.t6 to i64
  %rt10.t7 = ptrtoint i8* %localPtr.t7 to i64
  %rt11 = add i64 %rt10, 4
  %rt11.t1 = add i64 %rt10.t1, 4
  %rt11.t2 = add i64 %rt10.t2, 4
  %rt11.t3 = add i64 %rt10.t3, 4
  %rt11.t4 = add i64 %rt10.t4, 4
  %rt11.t5 = add i64 %rt10.t5, 4
  %rt11.t6 = add i64 %rt10.t6, 4
  %rt11.t7 = add i64 %rt10.t7, 4
  %rt12 = inttoptr i64 %rt11 to i32*
  %rt12.t1 = inttoptr i64 %rt11.t1 to i32*
  %rt12.t2 = inttoptr i64 %rt11.t2 to i32*
  %rt12.t3 = inttoptr i64 %rt11.t3 to i32*
  %rt12.t4 = inttoptr i64 %rt11.t4 to i32*
  %rt12.t5 = inttoptr i64 %rt11.t5 to i32*
  %rt12.t6 = inttoptr i64 %rt11.t6 to i32*
  %rt12.t7 = inttoptr i64 %rt11.t7 to i32*
  store i32 6, i32* %rt12, align 4
  store i32 6, i32* %rt12.t1, align 4
  store i32 6, i32* %rt12.t2, align 4
  store i32 6, i32* %rt12.t3, align 4
  store i32 6, i32* %rt12.t4, align 4
  store i32 6, i32* %rt12.t5, align 4
  store i32 6, i32* %rt12.t6, align 4
  store i32 6, i32* %rt12.t7, align 4
  ret void
}
