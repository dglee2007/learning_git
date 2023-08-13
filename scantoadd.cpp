#include <iostream>

int main(void)
{
    int val1;
    std::cout << "첫번째 정수 입력 : ";
    std::cin >> val1;  // std::cin은 C언어에서의 스트림 stdin에 해당

    int val2;  // C++에서는 지역변수를 아무 곳에서나 선언 가능
    std::cout << "두번째 정수 입력 : ";
    std::cin >> val2;

    int result = val1 + val2;
    std::cout << "덧셈 결과 : " << result << std::endl;

    system("pause");  // VC++ 에서만 필요
    return 0;
}
