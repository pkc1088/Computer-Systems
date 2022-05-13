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
p.551 �ؼ�
Poly Ver 2.5�� ���, �������� ����� �ݺ��Ǵ� ���� 
x_power = x*x_power�̶�� ���� �� �� �ִ�. 
�� �������� ���� �ε��Ҽ��� ����(5Ŭ�� ����Ŭ)�� ���� �ݺ����࿡ 
���� ����� �Ϸ�� ������ ������ �� ���� �ȴ�. 
result�� ������ ���ؼ� �ε��Ҽ��� ����(3Ŭ�� ����Ŭ)�� ���ӵǴ� 
�ݺ������ ���̿� �̷������ �Ѵ�.

p.552 �ؼ�
Poly Horner���� ������ �����ϴ� ����� ���� 
result = a[i] + x*result�� �ݺ����� ���κ��̶�� ���� �� �� �ִ�. 
���� �ݺ������� ����� result ������ �����ؼ� ���� �� ���� x�� 
���ϰ�(5Ŭ�� ����Ŭ), �׷��� ���� �̹� �ݺ����࿡ ���� ���� ���� 
���� a[i]�� �� ����� ���Ѵ�(3Ŭ�� ����Ŭ). �׷��� �� �ݺ������� 
�ּ� �����ð� 8����Ŭ�� �ҿ�ȴ�.

��, Poly Ver 2.5�� �� �ݺ����ึ�� �� ���� �ƴ϶� �� ���� ������ 
�ʿ�������, �ݺ����ึ�� �ٽ� ��θ� ���� �� �� ���� �������� 
�Ͼ��.

���� Horner�� ����� ������ ������!
*/
