
def twoSum(nums: list[int], target: int) -> list[int]:
    result = []
    number_index = {}
    for i, number in enumerate(nums):
        complement = target - number
        if complement in number_index:
            result.append(number_index[complement])
            result.append(i)
            return result
        number_index[number] = i
    return result


def main():
    nums = [2, 3, 4, 5, 6]
    target = 11
    result = twoSum(nums, target)
    print("Result:", result)

if __name__ == "__main__":
    main()

