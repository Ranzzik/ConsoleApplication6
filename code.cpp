#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSumDivThree(vector<int>& nums) {
    // Инициализируем dp[0] = 0, а остальные как -бесконечность (минимальное значение)
    int dp[3] = {0, INT_MIN, INT_MIN};
    
    for (int num : nums) {
        int new_dp[3];
        // Копируем текущие значения dp в new_dp
        for (int i = 0; i < 3; ++i) {
            new_dp[i] = dp[i];
        }
        
        // Обновляем new_dp для каждого возможного остатка
        for (int i = 0; i < 3; ++i) {
            int remainder = (i + num) % 3;
            // Если dp[i] + num больше текущего значения new_dp[remainder], обновляем
            if (dp[i] + num > new_dp[remainder]) {
                new_dp[remainder] = dp[i] + num;
            }
        }
        
        // Обновляем основные значения dp
        for (int i = 0; i < 3; ++i) {
            dp[i] = new_dp[i];
        }
    }
    
    // Возвращаем максимальную сумму с остатком 0
    return dp[0];
}

int main() {
    vector<int> nums;
    int n, num;
    
    cout << "Введите количество элементов в массиве: ";
    cin >> n;
    
    cout << "Введите элементы массива через пробел: ";
    for (int i = 0; i < n; ++i) {
        cin >> num;
        nums.push_back(num);
    }
    
    int result = maxSumDivThree(nums);
    cout << "Максимальная сумма, делящаяся на 3: " << result << endl;
    
    return 0;
}