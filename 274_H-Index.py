class Solution:
    def hIndex(self, citations: List[int]) -> int:
        result  = len(citations)
        citations.sort()
        for each in citations:
            if each<result:
                result-=1
            else:
                break
        return result
