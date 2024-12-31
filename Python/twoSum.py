
def twoSum(nums: list[int], target: int) -> list[int]:
    result = []
    number_index = {}
    for i, number in enumerate(nums):
        complement = target - number
        if complement in number_index:
            return [number_index[complement], i]
        number_index[number] = i
    return result


def main():
    nums = [2, 3, 4, 5, 6, 7]
    target = 9
    result = twoSum(nums, target)
    print("Result:", result)

if __name__ == "__main__":
    main()

