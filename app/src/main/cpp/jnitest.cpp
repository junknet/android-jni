#include <jni.h>
#include <string>


static int __attribute__((naked, pure)) MyAsmTest(int a, int b) {
    asm(".thumb");
    asm(".syntax unified");
    asm("sub r0,r0,r1");
    asm("add r0,r0,#1");
    asm("bx r0");
    asm("bx lr");
}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_jnitest_MainActivity_printStingFromNdk(JNIEnv *env, jobject thiz) {


    char strBuf[128];
    sprintf(strBuf, "Hello from C! ASMTest :%d", MyAsmTest(2, 2));

    return env->NewStringUTF(strBuf);

}