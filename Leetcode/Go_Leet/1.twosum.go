package Go_Leet

func twoSum(nums []int, target int) []int {
    var mp= make(map[int]int)
    for i:=0; i<len(nums); i++{
        mp[nums[i]] = i
        
    }
    for i:=0; i<len(nums); i++ {
        ind, found := mp[target - nums[i]]
        if found {
            if ind != i{
                return []int{i,ind}
            }
        }
    }
    return []int{-1,-1}
}