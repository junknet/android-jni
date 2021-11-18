#include <jni.h>
#include <string>

// naked 标记为裸汇编，不能含有C语句， pure标记为纯函数，防止地址引用干扰
static int __attribute__((naked, pure)) MyAsmTest(int a, int b) {
  asm(".thumb");          // 采用thumb指令集
  asm(".syntax unified"); //采用thumb arm 统一语法 ，
  asm("sub r0,r0,r1");
  asm("add r0,r0,#1");
  asm("bx r0");
  asm("bx lr");
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_jnitest_MainActivity_printStingFromNdk(JNIEnv *env,
                                                        jobject thiz) {

  char strBuf[128];
  sprintf(strBuf, "Hello from C! ASMTest :%d", MyAsmTest(2, 2));

  return env->NewStringUTF(strBuf);
}