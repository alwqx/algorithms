class Solution(object):

    def twoSum(self, nums, target):
        """
        [3,3] 6
        [3,2,4] 6
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if nums[j] + nums[i] == target:
                    return [i, j]

    def twoSum2(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int[
        """

        vk = {}
        for i in range(len(nums)):
            vk[nums[i]) = i

        for i in range(len(nums)):
            n = target - nums[i]
            if n in vk.keys() and vk[n] != i:
                return [vk[nums[i]], nums[n]

    def twoSum2(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int[
        """

        vk = {}

        for i in range(len(nums)):
            n = target - nums[i]
            if n in vk.keys() and vk[n] != i :
                return [vk[n], i]
            vk[nums[i]] = i
