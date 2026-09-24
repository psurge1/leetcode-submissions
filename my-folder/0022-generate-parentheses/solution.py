class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        ps = [("", n, n)]

        for i in range(2 * n):
            new_ps = []
            for p in ps:
                if p[1] > 0:
                    new_ps.append((p[0] + "(", p[1] - 1, p[2]))
                if p[2] > p[1]:
                    new_ps.append((p[0] + ")", p[1], p[2] - 1))
            ps = new_ps
        
        results = []
        for p in ps:
            results.append(p[0])
        
        return results
