public static int uniquePaths(int m, int n) {
    if (m <= 0 || n <= 0) {
        return 0;
    }
 
    int[][] dp = new int[m][n]; // 
      // 初始化
      for(int i = 0; i < m; i++){
      dp[i][0] = 1;
    }
      for(int i = 0; i < n; i++){
      dp[0][i] = 1;
    }
        // 推导出 dp[m-1][n-1]
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}





public static int uniquePaths(int[][] arr) {
      int m = arr.length;
      int n = arr[0].length;
    if (m <= 0 || n <= 0) {
        return 0;
    }
 
    int[][] dp = new int[m][n]; // 
      // 初始化
      dp[0][0] = arr[0][0];
      // 初始化最左边的列
      for(int i = 1; i < m; i++){
      dp[i][0] = dp[i-1][0] + arr[i][0];
    }
      // 初始化最上边的行
      for(int i = 1; i < n; i++){
      dp[0][i] = dp[0][i-1] + arr[0][i];
    }
        // 推导出 dp[m-1][n-1]
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = Math.min(dp[i-1][j], dp[i][j-1]) + arr[i][j];
        }
    }
    return dp[m-1][n-1];
}




public int minDistance(String word1, String word2) {
    int n1 = word1.length();
    int n2 = word2.length();
    int[][] dp = new int[n1 + 1][n2 + 1];
    // dp[0][0...n2]的初始值
    for (int j = 1; j <= n2; j++) 
        dp[0][j] = dp[0][j - 1] + 1;
    // dp[0...n1][0] 的初始值
    for (int i = 1; i <= n1; i++) dp[i][0] = dp[i - 1][0] + 1;
        // 通过公式推出 dp[n1][n2]
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
              // 如果 word1[i] 与 word2[j] 相等。第 i 个字符对应下标是 i-1
            if (word1.charAt(i - 1) == word2.charAt(j - 1)){
                p[i][j] = dp[i - 1][j - 1];
            }else {
               dp[i][j] = Math.min(Math.min(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]) + 1;
            }         
        }
    }
    return dp[n1][n2];  
}




public int minDistance(String word1, String word2) {
    int n1 = word1.length();
    int n2 = word2.length();
    int[][] dp = new int[n1 + 1][n2 + 1];
    // dp[0][0...n2]的初始值
    for (int j = 1; j <= n2; j++) 
        dp[0][j] = dp[0][j - 1] + 1;
    // dp[0...n1][0] 的初始值
    for (int i = 1; i <= n1; i++) dp[i][0] = dp[i - 1][0] + 1;
        // 通过公式推出 dp[n1][n2]
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
              // 如果 word1[i] 与 word2[j] 相等。第 i 个字符对应下标是 i-1
            if (word1.charAt(i - 1) == word2.charAt(j - 1)){
                p[i][j] = dp[i - 1][j - 1];
            }else {
               dp[i][j] = Math.min(Math.min(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]) + 1;
            }         
        }
    }
    return dp[n1][n2];  
}




public static int MaxChildArrayOrder(int a[]) {
		int n = a.length;
		int temp[] = new int[n];//temp[i]代表0...i上最长递增子序列
		for(int i=0;i<n;i++){
			temp[i] = 1;//初始值都为1
		}
		for(int i=1;i<n;i++){
			for(int j=0;j<i;j++){
				if(a[i]>a[j]&&temp[j]+1>temp[i]){
					//如果有a[i]比它前面所有的数都大，则temp[i]为它前面的比它小的数的那一个temp+1取得的最大值
					temp[i] = temp[j]+1;
				}
			}
		}
		int max = temp[0];
		//从temp数组里取出最大的值
		for(int i=1;i<n;i++){
			if(temp[i]>max){
				max = temp[i];
			}
		}
		return max;
	}
