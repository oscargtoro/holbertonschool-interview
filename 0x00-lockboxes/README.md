# 0x00-lockboxes

Determines if **n** boxes can be opened. Each box is numbered sequentially from 0 to n - 1 and each box may contain keys to the other boxes.

- Receives a list of lists
- A key with the same number as a box opens that box
- All keys must be positive integers

```
>>> canUnlockAll = __import__('0-lockboxes').canUnlockAll
>>>
>>> boxes = [[1], [2], [3], [4], []]
>>> print(canUnlockAll(boxes))
True
>>>
>>> boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
>>> print(canUnlockAll(boxes))
True
>>>
>>> boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
>>> print(canUnlockAll(boxes))
False
>>>
```
