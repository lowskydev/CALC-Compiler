#include <stdlib.h>
#include "closure_runtime.h"

closure* create_closure(void* func_ptr, void* env) {
    closure* c = (closure*)malloc(sizeof(closure));
    c->func_ptr = func_ptr;
    c->env = env;
    return c;
}

int32_t apply_closure_i32_i32(closure* c, int32_t arg) {
    int32_t (*f)(void*, int32_t) = (int32_t (*)(void*, int32_t))c->func_ptr;
    return f(c->env, arg);
}

int32_t apply_closure_i32_i1(closure* c, int32_t arg) {
    int32_t (*f)(void*, int32_t) = (int32_t (*)(void*, int32_t))c->func_ptr;
    return f(c->env, arg);
}

int32_t apply_closure_i1_i32(closure* c, int32_t arg) {
    int32_t (*f)(void*, int32_t) = (int32_t (*)(void*, int32_t))c->func_ptr;
    return f(c->env, arg);
}

int32_t apply_closure_i1_i1(closure* c, int32_t arg) {
    int32_t (*f)(void*, int32_t) = (int32_t (*)(void*, int32_t))c->func_ptr;
    return f(c->env, arg);
}

closure* apply_closure_closure_closure(closure* c, closure* arg) {
    closure* (*f)(void*, closure*) = (closure* (*)(void*, closure*))c->func_ptr;
    return f(c->env, arg);
}

void free_closure(closure* c) {
    free(c);
}