#include <bits/stdc++.h>
//"https://www.acmicpc.net/problem/1874"

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    /* Q)
    1부터 n까지의 수를 스택에 넣었다가 뽑아 늘어놓음으로써, 하나의 수열을 만들 수 있다. 이때, 스택에 push하는 순서는 반드시 오름차순을 지키도록 한다고 하자. 임의의 수열이 주어졌을 때 스택을 이용해 그 수열을 만들 수 있는지 없는지, 있다면 어떤 순서로 push와 pop 연산을 수행해야 하는지를 알아낼 수 있다. 이를 계산하는 프로그램을 작성하라.

    1. 입력받은 순서대로 push/pop 연산을 통하여 동일한 결과를 뱉을수 있는지를 물어보는 문제

    2.'수열은 무적권 1에서부터 시작한다!'

    3.숫자를 스택으로 입력한 순서 상관없이 숫자의 크기에 따라 오름차순을 팝 푸시를 하였을 때에 입력한 순서의 수열을 그대로 내뱉을수 있는지 에 대한 알고리즘

    4. 그럼 여기서 조건이 맨 위에 있는 숫자가 현재 입력받은 t와 다르면 안된다.

    5.이해를 잘못한게 그럼 일단 1 ~ n 이니까 그냥 1부터 입력받은 숫자까지 추적하여 스택을 만들 cnt 변수 생성 . 왜냐? 무조건 1부터 시작에 중복되는 수가 없는 수열이 들어온다는 조건이 있었기에

    6.그러면 일단 항상 입력받은 수가 맨 위에 있어야 한다?

    7. 1 부터 n까지 수를 순서대로 넣는다는 뜻이고

    8. 만약 4 를 넣는다 하면 1에서 부터 4까지 순서대로 넣는다. 1 , 2 , 3 , 4 순으로 넣고 입력한 숫자가 맨 위에 있어야지 입력한 순서대로 숫자가 출력이 가능하고 오름차순으로 넣어야 하기에

    9. while 문에 조건으로 cnt 가 입력한 숫자를 담을 변수 t 보다 같거나 작을떄 까지라고 만들어놨다 그래야지 오름차순으로 숫자가 들어가기에

    10. 그렇기 때문에 만약 맨 위에 있는 수가 입력한 수가 아니면 스택에 오름차순으로 담아 push pop 을 통하여 입력한 순서대로의 수열을 구할수 가 없다는 결론이 나온다.

    11. 성립이 안되는 예) 5 뒤에 1이 들어온다면 처음 cnt 가 5까지 올라간 다음 5가 pop 되고 그 뒤에 남은 숫자는 4 하지만 그 뒤로 입력되는 수가 1이기에 스택의 top 과 일치하지 않아 NO 가 된다.
    */
    int n;
    cin >> n;
    int cnt = 1;
    stack<int> s;
    string ans;
    while (n--) {
        int t;
        cin >> t;
        while (cnt <= t) {
            //++ 연산자 , 먼저 현재의 값을 사용한 다음 1을 더함 
            s.push(cnt++);
            ans += "+\n";
        }
        if (s.top() != t) {
            ans = "NO\n";
            break;
        }
        s.pop();
        ans += "-\n";
    }
    cout << ans;
}