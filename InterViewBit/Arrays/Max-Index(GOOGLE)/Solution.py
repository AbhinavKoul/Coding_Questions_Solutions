class Solution:
    # @param A : tuple of integers
    # @return an integer
    def maximumGap(self, arr):
        '''
        Time : O(N)
        Space: O(2N)
        '''
        Lmin = []
        Rmax = []

        #make 2 arrays
        mm = int(1e9)
        for i in arr:
            mm = min(i, mm)
            Lmin.append(mm)

        mx = -int(1e9)
        for i in reversed(arr):
            mx = max(mx, i)
            Rmax.append(mx)
        Rmax.reverse()

        #use mergesort kinda version

        i=0
        j=0
        ans = 0
        n = len(arr)
        while(1):
            while(j<n and Rmax[j]>=Lmin[i]):
                ans = max(ans, j-i)
                j += 1
            if j >=n:
                break

            while(i<=j and min_arr[i]>mx_arr[j]):
                i += 1
        return ans