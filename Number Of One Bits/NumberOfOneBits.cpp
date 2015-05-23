 /*************************************************************************
    > File Name: NumberOfOneBits.cpp
    > Create by Vindo Chen on 15-05-17
 ************************************************************************/

class Solution {
public:
	int hammingWeight(uint32_t n) {
	if(n == 0) return 0;
	int result = 1;
	while(n != 1)
	{
		if(n%2 == 1) result++;
		n = n/2;
	}
	return result;
}
};
