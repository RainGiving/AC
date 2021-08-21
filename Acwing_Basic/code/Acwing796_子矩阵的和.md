# Acwing796_子矩阵的和

## 思路

### 用前缀和求子矩阵

我们把前缀和拓展到二维，`s[x][y]`表示`[0, 0]`为左上角，`[x][y]`为右下角的矩阵的所有元素之和

那么当求任意子矩阵`[x1, y1] ~ [x2, y2]`和时同样可以通过O(1)的时间求得

`[x1, y1] ~[x2, y2] = s[x2, y2] - s[x1 - 1, y2] - s[x2, y1 - 1] + s[x1 - 1, y1 - 1]`，减去两个矩阵的和再加上这两个矩阵的重合部分的和

<img src="https://raw.githubusercontent.com/RainGiving/PictureBed/master/img1/20210821100810.png" alt="image-20210821100810807" style="zoom:50%;" />

### 推导前缀和

![image-20210821090446112](https://raw.githubusercontent.com/RainGiving/PictureBed/master/img1/20210821090446.png)

## AC代码

```cpp
#include <iostream>

using namespace std;

const int N = 1010;
int n, m, q;
int a[N][N], s[N][N];

int main()
{
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
    scanf("%d", &a[i][j]);
    
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
    s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j];
    
    while(q--)
    {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%d\n", s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
    }
    return 0;
}
```

