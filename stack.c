// c 에서 원래는 class 만들어서 쓰고싶었지만
// 억지로 만들어서 쓸수는 있지만 그냥 뭔가 보기안좋아서.. 기각
// 주석은 잘못됀 부분이 있을가능성이 높음

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *stack; // stack->stack 
    int rsp; // stack->rsp (stack 현제위치) 포인터를 안쓴이유 --> stack 에서 값을 찾아야함 --> ptr 쓸 이유 X
} Stack;

int push(Stack* stack, int value) {
    stack->stack[stack->rsp] = value;
    stack->rsp = stack->rsp + 1;
}

int pop(Stack* stack) {
    // 파라미터로 stack 의 포인터위치 받음

    if (stack->rsp == 0) {
        return 0;
    }

    stack->rsp = stack->rsp - 1;
    int value = stack->stack[stack->rsp];
    stack->stack[stack->rsp] = 0;

    return value;
}

int main() {
    Stack *stack;
    stack->rsp = 0;
    stack->stack = malloc(5);

    push(stack, 5);
    push(stack, 4);

    printf("%d\n", stack->stack[1]); // 4
    
    printf("%d\n", pop(stack)); // 4

    printf("%d\n", stack->stack[0]); // 5
}
