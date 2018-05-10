# Definition for singly-linked list with a random pointer.
# class RandomListNode(object):
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """
        if not head: return None
        current = RandomListNode(head.label)
        result = current
        lookup = {}
        while head:
            if head.next:
                if head.next in lookup:
                    current.next = lookup[head.next]
                else:
                    current.next = RandomListNode(head.next.label)
                    lookup[head.next] = current.next
            if head.random:
                if head.random in lookup:
                    current.random = lookup[head.random]
                else:
                    current.random = RandomListNode(head.random.label)
                    lookup[head.random] = current.random
            head = head.next
            current = current.next
        return result
