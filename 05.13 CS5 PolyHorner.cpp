double poly(double a[], double x, long degree)
{
    double result;
    double x_power;
    
    result = a[0];
    x_power = x;
    for (long i = 1; i <= degree; i++) {
        result += a[i] * x_power;
        x_power *= x;
    }
    return result;
}
double poly_horner(double a[], double x, long degree)
{
    double result;
    
    result = a[degree];
    for (long i = degree-1; i >= 0; i--)
        result = a[i] + x*result;
    return result;
}

/*
p.551 해설
Poly Ver 2.5의 경우, 성능제한 계산은 반복되는 수식 
x_power = x*x_power이라는 것을 알 수 있다. 
이 수식으로 인해 부동소수점 곱셈(5클럭 사이클)은 이전 반복실행에 
대한 계산이 완료될 때까지 시작할 수 없게 된다. 
result의 갱신을 위해서 부동소수점 덧셈(3클럭 사이클)이 연속되는 
반복실행들 사이에 이루어져야 한다.

p.552 해설
Poly Horner에서 성능을 제한하는 계산은 수식 
result = a[i] + x*result의 반복적인 계산부분이라는 것을 알 수 있다. 
이전 반복실행의 결과인 result 값으로 시작해서 먼저 이 값에 x를 
곱하고(5클럭 사이클), 그러고 나서 이번 반복실행에 대한 값을 갖기 
전에 a[i]에 그 결과를 더한다(3클럭 사이클). 그래서 매 반복실행은 
최소 지연시간 8사이클이 소요된다.

즉, Poly Ver 2.5는 매 반복실행마다 한 번이 아니라 두 번의 곱셈이 
필요하지만, 반복실행마다 핵심 경로를 따라서 단 한 번의 곱셈만이 
일어난다.

따라서 Horner의 방법이 오히려 느리다!
*/
