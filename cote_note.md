
1. 벡터 내부 값 합치기
```c++
#include <numeric>

accumulate(v.begin(), v.end(), 0); // 합 반환, (시작 위치, 끝 위치, 합 초기값)

```

2. 벡터 원소 찾기
```c++
if (find(v.begin(), v.end(), 6) != v.end()){} // (시작, 끝, 찾을 값)
```

